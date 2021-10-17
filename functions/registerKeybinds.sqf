#include "\a3\ui_f\hpp\defineDIKCodes.inc"

["Ammocan","reload_key", "Reload Turret", {[player] call fatLurch_fnc_reload}, "", [DIK_R, [false, false, false]]] call CBA_fnc_addKeybind;
//["Ammocan","ammo_key", "Select Turret Ammo", {[player] call fatLurch_fnc_selectAmmo}, "", [DIK_R, [true, false, false]]] call CBA_fnc_addKeybind;


[
    "Fat_Lurch_Ammocan_Hint", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "CHECKBOX", // setting type. CHECKBOX, EDITBOX, SLIDER, LIST or COLOR
    "Show Reload Hint", // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    "Ammocan", // Pretty name of the category where the setting can be found. Can be stringtable entry.
    TRUE, // data for this setting: [min, max, default, number of shown trailing decimals]
    nil, // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
    {  
        //params ["_value"];
        //setViewDistance _value;
    } // function that will be executed once on mission start and every time the setting is changed.
] call CBA_Settings_fnc_init;


[
    "Fat_Lurch_Ammocan_Verbose", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "CHECKBOX", // setting type. CHECKBOX, EDITBOX, SLIDER, LIST or COLOR
    "Output verbose ammocan support info to diag log", // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    "Ammocan", // Pretty name of the category where the setting can be found. Can be stringtable entry.
    FALSE, // data for this setting: [min, max, default, number of shown trailing decimals]
    nil, // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
    {  
        //params ["_value"];
        //setViewDistance _value;
    } // function that will be executed once on mission start and every time the setting is changed.
] call CBA_Settings_fnc_init;