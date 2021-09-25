/*
This function is required because apparently there is no functioning command currently implemented (as of version 2.04) to simply remove a magazine from a container.

The work around is to delete *all* the magazines and add back all but 1


Courtesy of RegEdit
https://forums.bohemia.net/forums/topic/160783-how-to-remove-a-magazine-from-a-specific-container-uniform-vest-backpack/

*/

//[_container, _magazine]call fatLurch_fnc_removeMagazine;


params["_container", "_magazine"];
private ["_cargo","_index"];
_cargo = magazineCargo _container;
_index = _cargo find _magazine;

if (not local _container) exitWith{};

if (_index != -1) then
{
	private ["_i"];
	_i = 0;
   	clearMagazineCargoGlobal _container;
  	{
		if (_index != _i) then 
			{
				_container addMagazineCargoGlobal [_x,1];
			};
		_i = _i+1;
	} forEach _cargo;
};