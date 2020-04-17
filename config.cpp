class CfgPatches
 {
 	class Fat_Lurch_Ammocan
 	{
 		units[] = {};	
 		weapons[] = {};
 		requiredVersion = 0.1;
 		requiredAddons[] = {"A3_Weapons_F_Mark"};	
		version="0.1";
		author="Fat_Lurch";
 	};
 };
 
  //required for Zeus to see the item?
class CfgAddons 
{
	class PreloadAddons 
	{
		class Fat_Lurch_Ammocan
		{
			list[] = 
			{
				"Fat_Lurch_Ammocan"
			};
		};
	};
};

class CfgFunctions
{
	class fatLurch
	{
		class ammocan
		{
			//[_unit, _weapon]call fatLurch_fnc_getTurretIndex;
			class getTurretIndex {file = "Ammocan\functions\getTurretIndex.sqf";};
			
			//[_container, _magazine]call fatLurch_fnc_removeMagazine;
			class removeMagazine {file = "Ammocan\functions\removeMagazine.sqf";};
			
			//[_vehicle]call fatLurch_fnc_initAmmocan;
			class initAmmocan {file = "Ammocan\functions\initAmmocan.sqf";};
		};
	};
};




class Extended_Init_EventHandlers 
{
	class air
	{
        	class Fat_Lurch_ammocan_air {init = "(_this select 0) call fatLurch_fnc_initAmmocan;";};
   	};
   	
   	class car
	{
        	class Fat_Lurch_ammocan_car {init = "(_this select 0) call fatLurch_fnc_initAmmocan;";};
   	};
   	
   	class tank
	{
        	class Fat_Lurch_ammocan_tank {init = "(_this select 0) call fatLurch_fnc_initAmmocan;";};
   	};
     	class ship
	{
        	class Fat_Lurch_ammocan_ship {init = "(_this select 0) call fatLurch_fnc_initAmmocan;";};
   	};
};


// ###### IMPORTANT! In order for an ammocan type to show up in rifle magazines it must be lsited in the array below. Luckily the rifle can't fire any of these rounds
class cfgWeapons
{
	class Rifle_Base_F;
	class arifle_Mk20_F:Rifle_Base_F
	{
		magazines[] += {"Ammocan_200Rnd_127x99_mag", "Ammocan_200Rnd_127x99_mag_Tracer_Red","Ammocan_200Rnd_127x99_mag_Tracer_Yellow", "Ammocan_200Rnd_127x99_mag_Tracer_Green",  "Ammocan_200Rnd_127x99_mag_SLAP", "Ammocan_200Rnd_127x99_mag_SLAP_Tracer_Red", "Ammocan_130Rnd_338_mag:ammocan_base"};
	};
};



//model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
//hiddenSelectionsTextures[] = {};

class CfgMagazines
 {
 	// Base Config Setup #############################################################################################
 	class 30Rnd_556x45_Stanag;
 	class ammocan_base:30Rnd_556x45_Stanag
 	{
 		ammocan = "true";
 		ammo = "";
 		author = "Fat_Lurch";
 		picture = "\Ammocan\data\ammocan.paa";
 		model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
 	};
 	
 	// 200x 12.7x99 NATO aka .50 BMG =====================================================================================================
 	
 	class Ammocan_200Rnd_127x99_mag:ammocan_base
 	{
 		//Vanilla
 		//RHS
		displayName = " Ammocan - 200x 12.7x99 M2 Ball";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm<br>200 Rounds";
		magazines[] = {"200Rnd_127x99_mag", "rhs_mag_200rnd_127x99_mag"};
	};
 	
 	class Ammocan_200Rnd_127x99_mag_Tracer_Red:ammocan_base
 	{
 		//Vanilla
 		//RHS
		displayName = " Ammocan - 200x 12.7x99 M2 Red Tracer";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm Red Tracer<br>200 Rounds";
		magazines[] = {"200Rnd_127x99_mag_Tracer_Red", "rhs_mag_200rnd_127x99_mag_Tracer_Red"};
	};
	
	 class Ammocan_200Rnd_127x99_mag_Tracer_Yellow:ammocan_base
 	{
 		//Vanilla
		displayName = " Ammocan - 200x 12.7x99 M2 Yellow Tracer";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm Yellow Tracer<br>200 Rounds";
		magazines[] = {"200Rnd_127x99_mag_Tracer_Yellow"};
	};
		
	class Ammocan_200Rnd_127x99_mag_Tracer_Green:ammocan_base
 	{
 		//Vanilla
		displayName = " Ammocan - 200x 12.7x99 M2 Green Tracer";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm Green Tracer<br>200 Rounds";
		magazines[] = {"200Rnd_127x99_mag_Tracer_Green"};
	};
	
	class Ammocan_200Rnd_127x99_mag_SLAP:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - 200x 12.7x99 M903 SLAP";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm M903 SLAP<br>200 Rounds";
		magazines[] = {"rhs_mag_200rnd_127x99_SLAP_mag"};
	};

	class Ammocan_200Rnd_127x99_mag_SLAP_Tracer_Red:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - 200x 12.7x99 M903 SLAP Red Tracer";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm M903 SLAP Red Tracer<br>200 Rounds";
		magazines[] = {"rhs_mag_200rnd_127x99_SLAP_mag_Tracer_Red"};
	};
	
	
	// 130x .338 Magnum =====================================================================================================
	
	class Ammocan_130Rnd_338_mag:ammocan_base
 	{
		displayName = " Ammocan - 130x .338 Magnum";
		descriptionShort = "Ammocan<br>Caliber: .338 Magnum<br>130 Rounds";
		magazines[] = {"130Rnd_338_Mag"};
	};
 };



