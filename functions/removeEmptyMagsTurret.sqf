params["_vehicle"];

_emptyMag = false;

{
	_index = _x select 1;
	_type = _x select 0;
	if((_x select 2) == 0) then
	{
		_vehicle removeMagazineTurret [_type,_index];
	};
	
}forEach magazinesAllTurrets _vehicle;