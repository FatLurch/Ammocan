params ["_ammoType"];

_ammocans = ["Ammocan_200Rnd_127x99_mag","Ammocan_200Rnd_127x99_mag_Tracer_Red","Ammocan_200Rnd_127x99_mag_Tracer_Yellow","Ammocan_200Rnd_127x99_mag_Tracer_Green","Ammocan_200Rnd_127x99_mag_SLAP","Ammocan_200Rnd_127x99_mag_SLAP_Tracer_Red","Ammocan_100Rnd_127x99_mag","Ammocan_100Rnd_127x99_mag_Tracer_Red","Ammocan_100Rnd_127x99_mag_Tracer_Yellow","Ammocan_100Rnd_127x99_mag_Tracer_Green","Ammocan_100Rnd_127x99_mag_SLAP","Ammocan_100Rnd_127x99_mag_SLAP_Tracer_Red","Ammocan_130Rnd_338_mag"];

_return = "";

{
	//if the provided ammotype is contained in this type of can, return the classname of the can
	_magArray = getArray (configFile >> "CfgMagazines" >> _x >> "magazines");	//Get an array of which ammo types the ammocan can supply
	if(_ammoType in _magArray) exitWith {_return = _x};
	
}forEach _ammocans;

_return