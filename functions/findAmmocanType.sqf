params ["_ammoType"];

_ammocans = ["ammocan_fake_gun"] call BIS_fnc_compatibleMagazines;	//This pulls the list of magazines defined in config.cpp. This prevents having to replicate the array in 2 places

_return = "";

{
	//if the provided ammotype is contained in this type of can, return the classname of the can
	_magArray = getArray (configFile >> "CfgMagazines" >> _x >> "magazines");	//Get an array of which ammo types the ammocan can supply
	if(_ammoType in _magArray) exitWith {_return = _x};
	
}forEach _ammocans;

_return


