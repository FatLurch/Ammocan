params ["_vehicle"];

sleep 1;

//diag_log format["### - convertInventoryMagazines called for vehicle: %1", _vehicle];

_magazines = magazinesAmmoCargo _vehicle;

{
	//systemChat format["Mag: %1", _x];
	
	_ammocan = [_x select 0] call fatLurch_fnc_findAmmocanType;
	
	if((_ammocan) != "") then
	{
		_roundCount = _x select 1;		
		_vehicle addMagazineAmmoCargo [_ammocan, 1, _roundCount];
		//diag_log format ["### convertInventoryMagazines - Adding ammocan: %1 with _roundcount: %2", _ammocan, _roundCount];
		
		[_vehicle, _x select 0, 1, _roundCount] call CBA_fnc_removeMagazineCargo;
	};
	
}forEach _magazines;