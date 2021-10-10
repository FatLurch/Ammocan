//This function evaluates if there are any turret weapons on a vehicle that require turret ammo to be converted into ammocans. 
//The blasklist is used to skip items that should not be evaluated by Ammocan (e.g. SmokeShells, laser batteries, etc.)

params["_vehicle", "_blacklist"];

_return = false;

{
	_turretIndex = _x;	
	
	{
		_weapon = _x;
	
		if(!(toLower(_weapon) in _blacklist)) then 
		{	
			_count = [_vehicle, _turretIndex, _weapon] call fatLurch_fnc_turretWeaponMagazineCount;
			
			If(_count >1) then {_return = true;};	
		};			
	
	} forEach (_vehicle weaponsTurret _turretIndex);

}forEach (allTurrets _vehicle);

_return