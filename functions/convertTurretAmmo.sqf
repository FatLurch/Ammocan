//This function attempts to convert all "vanilla" ammo in a turret to physical ammo cans in the vehicle inventory

params["_vehicle"];

sleep 1;	

_turretWeapons = [];

{
	_magazine = _x select 0;
	_turretIndex = _x select 1;
	_ammo = _x select 2;
	_foundType =[_magazine] call fatLurch_fnc_findAmmocanType;
	
	if(_foundType != "" && _ammo > 0) then
	{			
		If(_vehicle canAdd _foundType) then
		{
			diag_log format["### Ammocan Debug - convertTurretAmmo.sqf - Converting ammo in vehicle %1, foundType: %2,  _magazine: %3", _vehicle, _foundType, _magazine];
			_vehicle addMagazineCargoGlobal [_foundType, 1];
			[_vehicle, [_magazine,_turretIndex]] remoteExec ["removeMagazinesTurret", _vehicle];	
		}
		else
		{
			diag_log format["### Ammocan Debug - convertTurretAmmo.sqf - Unable to convert ammo in vehicle (canAdd = false) %1, foundType: %2,  _magazine: %3", _vehicle, _foundType, _magazine];
		};
	};

}forEach magazinesAllTurrets _vehicle;	//At this point, the turret has no ammo



{	
	//Load one magazine with the same kind of ammo into the turret as is in the turret config
	
	_preferredMag = getArray([_vehicle, _x] call BIS_fnc_turretConfig >> "magazines") select 0;	//get preferred mag type (this is the 1st magazine the vehicle would otherwise spawn with)
	
	[_vehicle, [_preferredMag,_x]] remoteExec ["addMagazineTurret", _vehicle];		//load the preferred mag into the turret so that there's ammo when the scenario starts
	
	diag_log format["### Ammocan Debug - convertTurretAmmo.sqf - Loading ammo %1 into turret %2 in vehicle %3", _preferredMag, _x, _vehicle];
	
	[_vehicle, [_preferredMag] call fatLurch_fnc_findAmmocanType] call fatLurch_fnc_removeMagazine;	//consume an appropriate ammocan from the vehicle inventory
	
	diag_log format["### Ammocan Debug - convertTurretAmmo.sqf - Consuming ammocan %1 for turret %2 from vehicle %3", [_preferredMag] call fatLurch_fnc_findAmmocanType, _x, _vehicle];
	
}forEach allTurrets [_vehicle, false];

