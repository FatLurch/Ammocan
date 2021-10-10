//This function attempts to convert all "vanilla" ammo in a turret to physical ammo cans in the vehicle inventory

params["_vehicle"];

_blacklist=["uk3cb_baf_safe", "smokelauncher"];	//A list of weapons that should be skipped. All entries should be lower case

if(!([_vehicle, _blacklist] call fatLurch_fnc_needTurretAmmoconversion)) exitWith {};	//Exit if no weapons on the vehicle need turret ammo converted. This skips a superfluous animation 

_firstHit = true;
_turretWeapons = [];
turretAmmo = []; 
_reloading = false;

//Build an array of how many rounds are loaded in the gun, per each turret weapon
{
	_turretIndex = _x;
	{
		_weapon = _x;
		
		if((weaponState [_vehicle, _turretIndex, _weapon] select 6) > 0) exitWith {_reloading = true};	//If the weapon is in the middle of a reloading animation, return true
		
		if(!(toLower(_weapon) in _blacklist)) then 
		{	
			turretAmmo pushback ([_vehicle, _turretIndex, _weapon] call fatLurch_fnc_getTurretAmmo);
		};

	}forEach (_vehicle weaponsTurret _turretIndex);
	
}forEach allTurrets [_vehicle, false];

if(_reloading) exitWith {};	//exit here so as not to interrupt a reloading animation. Any weapon on the vehicle will trip this

//This loop replaces magazines in the turret with ammocans in the vehicle inventory
{

	_magazine = _x select 0;
	_turretIndex = _x select 1;
	_ammo = _x select 2;
	_foundType = [_magazine] call fatLurch_fnc_findAmmocanType;
	
	if(_foundType != "" && _ammo > 0) then
	{		
		
		If(_vehicle canAdd _foundType) then
		{
			_vehicle addMagazineCargoGlobal [_foundType, 1];
			[_vehicle, [_magazine,_turretIndex]] remoteExec ["removeMagazineTurret", _vehicle];
		}
		else
		{
			diag_log format["### Ammocan Debug - convertTurretAmmo.sqf - Unable to convert ammo in vehicle (canAdd = false) %1, foundType: %2,  _magazine: %3", _vehicle, _foundType, _magazine];
		};
	};

}forEach magazinesAllTurrets _vehicle;
//At this point, the turret has *no* ammo 


//This affront to the laws of physics and all known dieties configures the weapon in question with exactly ONE magazine in the gun, instantly
_loop = 0;
{
	_turretIndex = _x;
	{
		_weapon = _x;
		
		if(!(toLower(_weapon) in _blacklist)) then 
		{	
			_originalWeapon = _vehicle currentWeaponTurret _turretIndex;
			_mag = getArray([_vehicle, _turretIndex] call BIS_fnc_turretConfig >> "magazines") select 0;	//TODO should match current ammo type if there's already ammo in the gun
			[_vehicle, [_weapon,_turretIndex]] remoteExec ["removeWeaponTurret", _vehicle];
			[_vehicle, [_mag,_turretIndex]] remoteExec ["addMagazineTurret", _vehicle];
			[_vehicle, [_weapon,_turretIndex]] remoteExec ["addWeaponTurret", _vehicle];
			[_vehicle, [_mag, (turretAmmo select _loop), _turretIndex]] remoteExec ["setMagazineTurretAmmo", _vehicle];	//Setup the weapon with the same amount of rounds it originally had as opposed to being topped off
			_loop = _loop +1;	//This is used as an array index to pick the right element out of the turretAmmo array defined up top
			[_vehicle, [_originalWeapon, _turretIndex]] remoteExec ["selectWeaponTurret", _vehicle];	//Restore the selected weapon to the one that was selected before loading
			
			//Consume an ammocan
			_ammoCanType = [_mag] call fatLurch_fnc_findAmmocanType;
			_ammoCount = [_vehicle, _turretIndex, _weapon] call fatLurch_fnc_getTurretAmmo;
			_test = [_vehicle, _ammoCanType, 1] call CBA_fnc_removeMagazineCargo;	
		};
		
	}forEach (_vehicle weaponsTurret _turretIndex);
	
}forEach allTurrets [_vehicle, false];

