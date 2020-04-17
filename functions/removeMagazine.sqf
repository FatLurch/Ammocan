/*

Courtesy of RegEdit
https://forums.bohemia.net/forums/topic/160783-how-to-remove-a-magazine-from-a-specific-container-uniform-vest-backpack/

removeMagazineFromContainer =
{
   private ["_container","_magazine","_cargo","_index"];
   _container = _this select 0;
   _magazine = _this select 1;
   _cargo = magazineCargo _container;
_index = _cargo find _magazine;
   if (_index != -1) then
   {
	private ["_i"];
	_i = 0;
       clearMagazineCargo _container;
       {
		if (_index != _i) then {_container addMagazineCargo [_x,1]};
		_i = _i+1;
	}
	forEach _cargo;
   };
};
For example:

[uniformContainer player,"16Rnd_9x21_Mag"] call removeMagazineFromContainer;

*/

//[_container, _magazine]call fatLurch_fnc_removeMagazine;

params["_container", "_magazine"];
private ["_cargo","_index"];
_container = _this select 0;
_magazine = _this select 1;
_cargo = magazineCargo _container;
_index = _cargo find _magazine;

if (_index != -1) then
{
	private ["_i"];
	_i = 0;
   	clearMagazineCargo _container;
  	{
		if (_index != _i) then {_container addMagazineCargo [_x,1]};
		_i = _i+1;
	} forEach _cargo;
};