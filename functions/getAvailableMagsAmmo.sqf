//Returns the magazines and how much ammo they have available to the vehicle
//This has to be handled differently for a static turret as opposed to other vehicles since it doesn't have an inventory/container

params["_vehicle"];

_output = [];

if((_vehicle isKindOf "Air") || (_vehicle isKindOf "Car") || (_vehicle isKindOf "Tank") || (_vehicle isKindOf "Ship")) then {_output = magazinesAmmoCargo _vehicle};

//if(_vehicle isKindOf "staticWeapon")) exitWith {//search for mags nearby};	

_output