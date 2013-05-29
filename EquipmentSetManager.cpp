#include "EquipmentSetManager.h"


EquipmentSetManager::EquipmentSetManager() : SetMapManager()
{
    //ctor
	getSetList()[0] = *createDefaultSet();	//create a default equipment set and adds it to the list
	
	setAsDefault(getSetList()[0].getSetName());		
	setAsCurrent(getSetList()[0].getSetName());

    cout << "Equipment Set Manager Created" << endl;

}

EquipmentSetManager::~EquipmentSetManager()
{
    //dtor
    cout << "Equipment Set Manager Destroyed" << endl;
}

SetMap * EquipmentSetManager::createDefaultSet(void)
{
	SetMap * defaultSet = new EquipmentSet();

    defaultSet->changeName("default");

    //Create the map.
    defaultSet->addToSet("head", "helmet01.mesh");
    defaultSet->addToSet("face", "mask01.mesh");
    defaultSet->addToSet("neck", "collar01.mesh");
    defaultSet->addToSet("neck", "collar01.mesh");
    defaultSet->addToSet("lShoulder", "lPauldron01.mesh");
    defaultSet->addToSet("rShoulder", "rPauldron01.mesh");
    defaultSet->addToSet("lBicep", "lRerebrace01.mesh");
    defaultSet->addToSet("rBicep", "rRearebrace01.mesh");
    defaultSet->addToSet("lForearm", "lBracer01.mesh");
    defaultSet->addToSet("rForearm", "rBracer01.mesh");
    defaultSet->addToSet("lHand", "lGauntlet01.mesh");
    defaultSet->addToSet("rHand", "rGauntlet01.mesh");
    defaultSet->addToSet("lPinkie", "ring01.mesh");
    defaultSet->addToSet("rPinkie", "ring01.mesh");
    defaultSet->addToSet("lRing", "ring02.mesh");
    defaultSet->addToSet("rRing", "ring02.mesh");
    defaultSet->addToSet("lMiddle", "ring03.mesh");
    defaultSet->addToSet("rMiddle", "ring03.mesh");
    defaultSet->addToSet("lPointer", "ring04.mesh");
    defaultSet->addToSet("rPointer", "ring04.mesh");
    defaultSet->addToSet("chest", "chestPlate01.mesh");
    defaultSet->addToSet("waist", "belt01.mesh");
    defaultSet->addToSet("lThigh", "lCuisse01.mesh");
    defaultSet->addToSet("rThigh", "rCuisee01.mesh");
    defaultSet->addToSet("lShin", "lGreave01.mesh");
    defaultSet->addToSet("rShin", "rGreave01.mesh");
    defaultSet->addToSet("lFoot", "lBoot01.mesh");
    defaultSet->addToSet("rFoot", "rBoot01.mesh");

	return defaultSet;
}
