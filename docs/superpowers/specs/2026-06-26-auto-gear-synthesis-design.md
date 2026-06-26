# Auto Gear Synthesis Design

Date: 2026-06-26

## Scope

Add a first version of automatic equipment synthesis to the TaskBarHero plugin.

This version only automates Cube synthesis for equipment (`EItemSynthesisType.Gear`). It does not synthesize accessories or materials, and it does not change the chest reward path.

## User-Facing Behavior

- Add a plugin panel option to enable or disable automatic equipment synthesis.
- Add a grade selector with values `6`, `7`, `8`, and `9`.
- Add or reuse a storage toggle so synthesis can include warehouse/stash items.
- When enabled, the plugin periodically attempts one synthesis cycle:
  - select the Cube synthesis recipe for `SYNTHESIS + Gear + selected grade`;
  - enable or apply the include-storage setting when configured;
  - run the game's own auto-fill logic;
  - trigger the game's normal synthesis action.
- If the Cube UI/state is not initialized, or if the selected recipe cannot currently be filled, the plugin waits and retries later.

## Game Chain

The implementation should reuse the game's existing Cube logic instead of constructing item lists manually.

Relevant 1.00.21 addresses:

- `Cube.inh(bool)` at `0x1808A3050`: writes `CommonSaveData.useStorage`.
- `Cube.img(EItemSynthesisType)` at `0x18089F690`: sets synthesis item type.
- `Cube.ipa(ERecipeType, EItemSynthesisType, EGradeType, int)` at `0x1808AA8D0`: selects the current synthesis recipe.
- `UI_Cube.kzn()` at `0x180A22150`: invokes the game's auto-fill path for the current recipe.
- `Cube.inp()` / current recipe trigger at `0x1808A3F00`: dispatches the current recipe logic. For recipe type `SYNTHESIS`, the state machine calls `TrySynthesisAsyncBackend`.

Recommended call sequence:

1. Cache the active `UI_Cube` instance from `UI_Cube.OnEnable` or initialization, and clear it on disable/destroy.
2. On the game thread, when auto synthesis is enabled and cooldown allows:
   - call `Cube.inh(includeStorage)`;
   - call `Cube.img(Gear)`;
   - call `Cube.ipa(SYNTHESIS, Gear, selectedGrade, 0)`;
   - call `UI_Cube.kzn(cachedUiCube)`;
   - after a short delay, call `Cube.inp()`.
3. Mark the synthesis attempt as in-flight and wait for a conservative cooldown before the next attempt.

## State And Safety

- Run all game calls from the existing game-thread tick path in `winhttp_proxy.c`.
- Do not call the Cube chain when the cached `UI_Cube` pointer is null.
- Do not run repeated triggers while a previous synthesis attempt is still inside the cooldown window.
- Use a conservative default interval, for example 2-3 seconds, to avoid hammering async inventory and exchange flows.
- If a call fails validation or has no fillable recipe, back off without changing unrelated Cube state.
- Persist the new options in the plugin config, matching the existing settings persistence style.

## Explicit Non-Goals

- Do not force or override crafted/result item IDs.
- Do not modify chest reward selection.
- Do not bypass local inventory-full checks.
- Do not patch Steam/server inventory exchange results.
- Do not implement auto open-box-to-stash in this first version.

## Inventory And Stash Findings

The chest and inventory paths have both local and backend pieces:

- StageBox has local box-count, request-rate, and inventory-full UI/guard logic.
- Actual item creation still goes through the Steam/server inventory exchange/update path.
- The `SteamInventoryFullUpdate_t` callback is a full inventory update event, not a direct "bag full" bypass point.
- Moving items to stash uses a separate `MoveRequest` flow with slot types such as `INVENTORY`, `STASH`, and `CUBEINVENTORY`.

Because of that, bypassing the local full-inventory UI is not a reliable or safe fix. The first version should reduce bag pressure by consuming equipment through normal synthesis, especially with `useStorage` enabled.

## Future Work

If bag pressure remains a problem after automatic synthesis:

- add a second phase that observes newly opened inventory equipment;
- find an empty stash slot through the existing `uz.Stash` cache;
- move equipment from inventory to stash with the game's normal `MoveRequest(INVENTORY -> STASH)` flow;
- keep the same validation/cooldown approach and do not force backend state.

## Verification Plan

- Build the plugin DLL.
- Inject into game version `1.00.21`.
- Verify the panel persists the auto-synthesis, grade, and include-storage settings.
- With enough equipment available, enable auto synthesis and confirm only Gear synthesis is triggered.
- Confirm accessories and materials are not selected as synthesis targets.
- Confirm disabling auto synthesis stops new attempts.
- Confirm no crash when the Cube UI has not been opened or is unavailable.
- Confirm no chest reward or forced item-id logic is changed.
