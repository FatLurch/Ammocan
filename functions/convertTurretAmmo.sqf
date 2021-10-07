//This function attempts to convert all "vanilla" ammo in a turret to physical ammo cans in the vehicle inventory

params["_vehicle"];

_blacklist=["uk3cb_baf_safe", "smokelauncher"];	//A list of weapons that should be skipped. All entries should be lower case

sleep 1;	

_firstHit = true;

_turretWeapons = [];
turretAmmo = [];

//Build an array of how many rounds are loaded in the gun, per each turret weapon
{
	_turretIndex = _x;
	{
		
		turretAmmo pushback ([_vehicle, _turretIndex] call fatLurch_fnc_getTurretAmmo); //TODO - This part is being tested

	}forEach (_vehicle weaponsTurret _turretIndex);
	
}forEach allTurrets [_vehicle, false];

diag_log format["##### convertTurretAmmo - _turretAmmo:  %1", turretAmmo];

_count = (count(magazinesAllTurrets _vehicle) -1);
{

	_magazine = _x select 0;
	_turretIndex = _x select 1;
	_ammo = _x select 2;
	_foundType = [_magazine] call fatLurch_fnc_findAmmocanType;
	
	if(_foundType != "" && _ammo > 0) then
	{		
		
		If(_vehicle canAdd _foundType) then
		{
			//diag_log format["### Ammocan Debug - convertTurretAmmo.sqf - Converting ammo in vehicle %1, foundType: %2,  _magazine: %3, _forEachIndex: ", _vehicle, _foundType, _magazine, _forEachIndex];
			if(_forEachIndex < _count) then
			{
				_vehicle addMagazineCargoGlobal [_foundType, 1];
			};
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
_loop = 0;
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
			//_vehicle setMagazineTurretAmmo [_magType, _max, _turretIndex];
			[_vehicle, [_mag, turretAmmo select _loop, _turretIndex]] remoteExec ["setMagazineTurretAmmo", _vehicle];	//TODO - This should be ready now
			diag_log format["### - convertTurretAmmo - _vehicle: %1 - _turretIndex %2 - _weapon: %3 - ammo: %4", _vehicle, _turretindex, _weapon, turretAmmo select _loop];
			_loop = _loop +1;
		};
	}forEach (_vehicle weaponsTurret _turretIndex);
	
}forEach allTurrets [_vehicle, false];

