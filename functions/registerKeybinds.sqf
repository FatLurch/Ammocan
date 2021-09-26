#include "\a3\ui_f\hpp\defineDIKCodes.inc"

["Ammocan","reload_key", "Reload Turret", {[player] call fatLurch_fnc_reload}, "", [DIK_R, [false, false, false]]] call CBA_fnc_addKeybind;
//["Ammocan","ammo_key", "Select Turret Ammo", {[player] call fatLurch_fnc_selectAmmo}, "", [DIK_R, [true, false, false]]] call CBA_fnc_addKeybind;