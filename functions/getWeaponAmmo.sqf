//return the ammo count for a weapon given vehicle, turretPath and weapon name

params["_vehicle", "_turretPath", "_weapon"];

_compatibleMags = [_weapon] call bis_fnc_compatibleMagazines;

_ammo = 0;

{

//if the turretPath matches AND if the magazine is compatible with the weapon specified

	_currentMag = toLower(_x select 0);

	if((_x select 1 isEqualTo _turretPath) && (_currentMag in _compatibleMags)) then 
	{
		_ammo = _ammo + (_x select 2);
	};

}forEach magazinesAllTurrets _vehicle;

_ammo
