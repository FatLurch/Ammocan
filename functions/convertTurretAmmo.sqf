//This function attempts to convert all "vanilla" ammo in a turret to physical ammo cans in the vehicle inventory

params["_vehicle"];

sleep 1;	

_firstHit = true;

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
			[_vehicle, [_magazine,_turretIndex]] remoteExec ["removeMagazineTurret", _vehicle];
		}
		else
		{
			diag_log format["### Ammocan Debug - convertTurretAmmo.sqf - Unable to convert ammo in vehicle (canAdd = false) %1, foundType: %2,  _magazine: %3", _vehicle, _foundType, _magazine];
		};
	};

}forEach magazinesAllTurrets _vehicle;	
//At this point, the turret has no ammo 

{	
	//Load one magazine with the same kind of ammo into the turret as is in the turret config
	
	_preferredMag = getArray([_vehicle, _x] call BIS_fnc_turretConfig >> "magazines") select 0;	//get preferred mag type (this is the 1st magazine the vehicle would otherwise spawn with)
	[_vehicle, _x, _preferredMag] call fatLurch_fnc_loadAmmoFromInventory;		
	
}forEach allTurrets [_vehicle, false];

