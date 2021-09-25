//This function returns the classname of an ammocan that is compatible with the specific ammo type. If no corresponding type is found, returns ""

params ["_ammoType"];

_ammocans = getArray (configFile >> "cfgWeapons" >> "ammocan_fake_gun" >> "magazines");	//This pulls the list of magazines defined in config.cpp. This prevents having to replicate the array in 2 places. Use this instead of BIS_fnc_compatibleMagazines due tyo case sensitivity issue

_return = "";

{

	_magArray = getArray (configFile >> "CfgMagazines" >> _x >> "magazines");	//Get an array of which ammo types the ammocan can supply
	
	//if(_ammoType in _magArray) exitWith {_return = _x};	//case sensitivity causing issues
		
	if(_magArray findIf { _x == _ammoType; } != -1) exitWith {_return = _x};	
		
}forEach _ammocans;

_return


