//This function attempts to convert all "vanilla" ammo in a turret to physical ammo cans in the vehicle inventory

params["_vehicle"];

_blacklist=["uk3cb_baf_safe", "smokelauncher"];	//A list of weapons that should be skipped. All entries should be lower case

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
			//diag_log format["### Ammocan Debug - convertTurretAmmo.sqf - Converting ammo in vehicle %1, foundType: %2,  _magazine: %3", _vehicle, _foundType, _magazine];
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


//This affront to the laws of physics and all known dieties configures the weapon in question with exactly ONE magazine in the gun, instantly
{
	_turretIndex = _x;
	{
		_weapon = _x;
		if(!(toLower(_weapon) in _blacklist)) then 
		{	
			_mag = getArray([_vehicle, _turretIndex] call BIS_fnc_turretConfig >> "magazines") select 0;
			[_vehicle, [_weapon,_turretIndex]] remoteExec ["removeWeaponTurret", _vehicle];
			[_vehicle, [_mag,_turretIndex]] remoteExec ["addMagazineTurret", _vehicle];
			[_vehicle, [_weapon,_turretIndex]] remoteExec ["addWeaponTurret", _vehicle];
		};
	}forEach (_vehicle weaponsTurret _turretIndex);
	
}forEach allTurrets [_vehicle, false];

