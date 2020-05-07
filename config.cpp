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
			
			//[_vehicle]call fatLurch_fnc_removeEmptyMagsTurret;
			class removeEmptyMagsTurret {file = "Ammocan\functions\removeEmptyMagsTurret.sqf";};
			
			//[_ammoType]call fatLurch_fnc_findAmmocanType;
			class findAmmocanType {file = "Ammocan\functions\findAmmocanType.sqf";};
			
			//[_vehicle]call fatLurch_fnc_convertTurretAmmo;
			class convertTurretAmmo {file = "Ammocan\functions\convertTurretAmmo.sqf";};
			
			//[_vehicle, _turretPath]call fatLurch_fnc_getTurretAmmo;
			class getTurretAmmo {file = "Ammocan\functions\getTurretAmmo.sqf";};
			
			//[_vehicle, _turretPath]call fatLurch_fnc_nonEmptyMagsTurret;
			class nonEmptyMagsTurret {file = "Ammocan\functions\nonEmptyMagsTurret.sqf";};
			
			//[_vehicle, _turretPath]call fatLurch_fnc_getTurretWeapons;
			class getTurretWeapons {file = "Ammocan\functions\getTurretWeapons.sqf";};
			
			//[_vehicle, _turretPath, _weapon]call fatLurch_fnc_getWeaponAmmo;
			class getWeaponAmmo {file = "Ammocan\functions\getWeaponAmmo.sqf";};
			
			//[_array]call fatLurch_fnc_toLowerArray;
			class toLowerArray {file = "Ammocan\functions\toLowerArray.sqf";};
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


//##############################################################################################
// ###### IMPORTANT! In order for an ammocan type to show up in rifle magazines it must be listed in the array below
//##############################################################################################
class cfgWeapons
{
	class Rifle_Base_F;
	class ammocan_fake_gun:Rifle_Base_F
	{
		magazines[] = 
		{
			"Ammocan_200Rnd_127x99_mag",
			"Ammocan_200Rnd_127x99_mag_Tracer_Red",
			"Ammocan_200Rnd_127x99_mag_Tracer_Yellow",
			"Ammocan_200Rnd_127x99_mag_Tracer_Green",
			"Ammocan_200Rnd_127x99_mag_SLAP",
			"Ammocan_200Rnd_127x99_mag_SLAP_Tracer_Red",
			"Ammocan_100Rnd_127x99_mag",
			"Ammocan_100Rnd_127x99_mag_Tracer_Red",
			"Ammocan_100Rnd_127x99_mag_Tracer_Yellow",
			"Ammocan_100Rnd_127x99_mag_Tracer_Green",
			"Ammocan_100Rnd_127x99_mag_SLAP",
			"Ammocan_100Rnd_127x99_mag_SLAP_Tracer_Red",
			"Ammocan_130Rnd_338_mag",
			"Ammocan_RHS_48Rnd_40mm_MK19_M430A1",
			"Ammocan_RHS_48Rnd_40mm_MK19_M1001",
			"Ammocan_96Rnd_40mm_G_belt",
			"Ammocan_RHS_48Rnd_40mm_MK19_M1001",
			"Ammocan_rhs_mag_762x51_M240_200_M80",
			"Ammocan_rhs_mag_762x51_M240_200",
			"Ammocan_rhs_mag_400rnd_127x99_mag",
			"Ammocan_400Rnd_127x99_mag_Tracer_Red", 
			"Ammocan_400Rnd_127x99_mag_SLAP",
			"Ammocan_400Rnd_127x99_mag_SLAP_Tracer_Red"
		};
	};
};

class CfgModels
{
	class Land_FireExtinguisher_F;
	class Test_thing:Land_FireExtinguisher_F
	{
		//sectionsInherit = "Car"; // Inherit all sections from class Car.
		// Add new section.
		sections[] = {"Marking"};
	};
};

class cfgVehicles
{	
	class Land_FireExtinguisher_F;
	class Test_thing:Land_FireExtinguisher_F
	{
 		ammocan = "true";
 		ammo = "";
 		author = "Fat_Lurch";
 		displayName = "M2A1 Ammocan";
 		picture = "Ammocan\data\ammocan.paa";
 		model = "Ammocan\M2A1.p3d";
 		hiddenSelections[] = {};								// List of model selections which can be changed with hiddenSelectionTextures[]
		hiddenSelectionsTextures[] = {"Ammocan\data\Marking_100x_M2.paa"};	// The textures for the selections defined above.
	};
};

class CfgMagazines
 {
 	// Base Config Setup #############################################################################################
 	class 30Rnd_556x45_Stanag;
 	class ammocan_base:30Rnd_556x45_Stanag
 	{
 		ammocan = "true";
 		ammo = "";
 		author = "Fat_Lurch";
 		picture = "Ammocan\data\ammocan.paa";
 		model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
 	};
 	
 	 // 400x 12.7x99 NATO aka .50 BMG =====================================================================================================
 	
 	class Ammocan_rhs_mag_400rnd_127x99_mag:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - 400x .50 Cal (12.7x99) M2 Ball";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm<br>400 Rounds";
		magazines[] = {"rhs_mag_400rnd_127x99_mag"};
	};
 	
 	class Ammocan_400Rnd_127x99_mag_Tracer_Red:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - 400x .50 Cal (12.7x99) M2 Red Tracer";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm Red Tracer<br>400 Rounds";
		magazines[] = {"rhs_mag_400rnd_127x99_mag_Tracer_Red"};
	};
	
	class Ammocan_400Rnd_127x99_mag_SLAP:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - 400x .50 Cal (12.7x99) M903 SLAP";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm M903 SLAP<br>400 Rounds";
		magazines[] = {"rhs_mag_400rnd_127x99_SLAP_mag"};
	};

	class Ammocan_400Rnd_127x99_mag_SLAP_Tracer_Red:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - 400x .50 Cal (12.7x99) M903 SLAP Red Tracer";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm M903 SLAP Red Tracer<br>400 Rounds";
		magazines[] = {"rhs_mag_400rnd_127x99_SLAP_mag_Tracer_Red"};
	};
 	
 	// 200x 12.7x99 NATO aka .50 BMG =====================================================================================================
 	
 	class Ammocan_200Rnd_127x99_mag:ammocan_base
 	{
 		//Vanilla
 		//RHS
		displayName = " Ammocan - 200x .50 Cal (12.7x99) M2 Ball";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm<br>200 Rounds";
		magazines[] = {"200Rnd_127x99_mag", "rhs_mag_200rnd_127x99_mag"};
	};
 	
 	class Ammocan_200Rnd_127x99_mag_Tracer_Red:ammocan_base
 	{
 		//Vanilla
 		//RHS
		displayName = " Ammocan - 200x .50 Cal (12.7x99) M2 Red Tracer";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm Red Tracer<br>200 Rounds";
		magazines[] = {"200Rnd_127x99_mag_Tracer_Red", "rhs_mag_200rnd_127x99_mag_Tracer_Red"};
	};
	
	 class Ammocan_200Rnd_127x99_mag_Tracer_Yellow:ammocan_base
 	{
 		//Vanilla
		displayName = " Ammocan - 200x .50 Cal (12.7x99) M2 Yellow Tracer";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm Yellow Tracer<br>200 Rounds";
		magazines[] = {"200Rnd_127x99_mag_Tracer_Yellow"};
	};
		
	class Ammocan_200Rnd_127x99_mag_Tracer_Green:ammocan_base
 	{
 		//Vanilla
		displayName = " Ammocan - 200x .50 Cal (12.7x99) M2 Green Tracer";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm Green Tracer<br>200 Rounds";
		magazines[] = {"200Rnd_127x99_mag_Tracer_Green"};
	};
	
	class Ammocan_200Rnd_127x99_mag_SLAP:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - 200x .50 Cal (12.7x99) M903 SLAP";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm M903 SLAP<br>200 Rounds";
		magazines[] = {"rhs_mag_200rnd_127x99_SLAP_mag"};
	};

	class Ammocan_200Rnd_127x99_mag_SLAP_Tracer_Red:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - 200x .50 Cal (12.7x99) M903 SLAP Red Tracer";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm M903 SLAP Red Tracer<br>200 Rounds";
		magazines[] = {"rhs_mag_200rnd_127x99_SLAP_mag_Tracer_Red"};
	};
	
 	// 100x 12.7x99 NATO aka .50 BMG =====================================================================================================
 	
 	class Ammocan_100Rnd_127x99_mag:ammocan_base
 	{
 		//Vanilla
 		//RHS
		displayName = " Ammocan - 100x .50 Cal (12.7x99) M2 Ball";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm<br>100 Rounds";
		magazines[] = {"100Rnd_127x99_mag", "rhs_mag_100rnd_127x99_mag"};
	};
 	
 	class Ammocan_100Rnd_127x99_mag_Tracer_Red:ammocan_base
 	{
 		//Vanilla
 		//RHS
		displayName = " Ammocan - 100x .50 Cal (12.7x99) M2 Red Tracer";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm Red Tracer<br>100 Rounds";
		magazines[] = {"100Rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red"};
	};
	
	 class Ammocan_100Rnd_127x99_mag_Tracer_Yellow:ammocan_base
 	{
 		//Vanilla
		displayName = " Ammocan - 100x .50 Cal (12.7x99) M2 Yellow Tracer";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm Yellow Tracer<br>100 Rounds";
		magazines[] = {"100Rnd_127x99_mag_Tracer_Yellow"};
	};
		
	class Ammocan_100Rnd_127x99_mag_Tracer_Green:ammocan_base
 	{
 		//Vanilla
		displayName = " Ammocan - 100x .50 Cal (12.7x99) M2 Green Tracer";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm Green Tracer<br>100 Rounds";
		magazines[] = {"100Rnd_127x99_mag_Tracer_Green"};
	};
	
	class Ammocan_100Rnd_127x99_mag_SLAP:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - 100x .50 Cal (12.7x99) M903 SLAP";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm M903 SLAP<br>100 Rounds";
		magazines[] = {"rhs_mag_100rnd_127x99_SLAP_mag"};
	};

	class Ammocan_100Rnd_127x99_mag_SLAP_Tracer_Red:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - 100x .50 Cal (12.7x99) M903 SLAP Red Tracer";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm M903 SLAP Red Tracer<br>100 Rounds";
		magazines[] = {"rhs_mag_100rnd_127x99_SLAP_mag_Tracer_Red"};
	};
	
	// 130x .338 Magnum =====================================================================================================
	
	class Ammocan_130Rnd_338_mag:ammocan_base
 	{
 		//Vanilla
		displayName = " Ammocan - 130x .338 Norma Magnum";
		descriptionShort = "Ammocan<br>Caliber: .338 Norma Magnum<br>130 Rounds";
		magazines[] = {"130Rnd_338_Mag"};
	};
	
	// 48x 40mm =====================================================================================================
	
	class Ammocan_RHS_48Rnd_40mm_MK19_M430A1:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - 48x 40mm M430A1 HEDP";
		descriptionShort = "Ammocan<br>Caliber: 40mm M430A1 HEDP<br>48 Rounds";
		magazines[] = {"RHS_48Rnd_40mm_MK19_M430A1"};
	};
	class Ammocan_RHS_48Rnd_40mm_MK19_M1001:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - 48x 40mm M1001 Canister";
		descriptionShort = "Ammocan<br>Caliber: 40mm M1001 Canister<br>48 Rounds";
		magazines[] = {"RHS_48Rnd_40mm_MK19_M1001"};
	};
	
	
	class Ammocan_96Rnd_40mm_G_belt:ammocan_base
 	{
 		//Vanilla
 		//RHS
		displayName = " Ammocan - 96x 40mm M430A1 HEDP";
		descriptionShort = "Ammocan<br>Caliber: 40mm M430A1 HEDP<br>96 Rounds";
		magazines[] = {"RHS_96Rnd_40mm_MK19_M430A1", "96Rnd_40mm_G_belt"};
	};
	class Ammocan_RHS_96Rnd_40mm_MK19_M1001:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - 96x 40mm M1001 Canister";
		descriptionShort = "Ammocan<br>Caliber: 40mm M1001 Canister<br>96 Rounds";
		magazines[] = {"RHS_96Rnd_40mm_MK19_M1001",};
	};
	
	// 200x 7.62x51 NATO =====================================================================================================

	class Ammocan_rhs_mag_762x51_M240_200:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - 200x 7.62x51mm M80A1 EPR";
		descriptionShort = "Ammocan<br>Caliber: 7.62x51mm M80A1 EPR<br>200 Rounds";
		magazines[] = {"rhs_mag_762x51_M240_200"};
	};
	
	class Ammocan_rhs_mag_762x51_M240_200_M80:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - 200x 7.62x51mm M80 Ball";
		descriptionShort = "Ammocan<br>Caliber: 7.62x51mm M80 Ball<br>200 Rounds";
		magazines[] = {"rhs_mag_762x51_M240_200_M80"};
	};
 };



