/*
This function is required because apparently there is no functioning command currently implemented (as of version 2.04) to simply remove a magazine from a container.

The work around is to delete *all* the magazines and add back all but 1


Courtesy of RegEdit
https://forums.bohemia.net/forums/topic/160783-how-to-remove-a-magazine-from-a-specific-container-uniform-vest-backpack/

*/

//[_container, _magazine]call fatLurch_fnc_removeMagazine;


params["_container", "_magazine"];
private ["_cargo","_index"];
_cargo = magazinesAmmoCargo _container;
_index = _cargo find _magazine;

diag_log format["### - _cargo: %1", _cargo];
diag_log format["### - _index: %1", _index];

if (not local _container) exitWith{};

if (_index != -1) then
{
	private ["_i"];
	_i = 0;
   	clearMagazineCargoGlobal _container;
  	{
  		diag_log format["### - _index: %1 - _i: %2 - _x # 0: %3 - _x # 1: %4", _index, _i, _x select 0, _x select 1];
		if (_index != _i) then 
			{
				_container addMagazineAmmoCargo [_x select 0,1, _x select 1];
			};
		_i = _i+1;
	} forEach _cargo;
};