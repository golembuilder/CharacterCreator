#include "EquipmentSetManager.h"


EquipmentSetManager::EquipmentSetManager()
{
    //ctor
    createDefaultSet();
    mSetList.push_back(mDefaultSet);
    cout << "Equipment Set Manager Created" << endl;

}

EquipmentSetManager::~EquipmentSetManager()
{
    //dtor
    cout << "Equipment Set Manager Destroyed" << endl;
}

void EquipmentSetManager::createDefaultSet(void)
{
    mDefaultSet.setName("default");

    //Create the map.
    mDefaultSet.addToSet("head", "helmet01.mesh");
    mDefaultSet.addToSet("face", "mask01.mesh");
    mDefaultSet.addToSet("neck", "collar01.mesh");
    mDefaultSet.addToSet("neck", "collar01.mesh");
    mDefaultSet.addToSet("lShoulder", "lPauldron01.mesh");
    mDefaultSet.addToSet("rShoulder", "rPauldron01.mesh");
    mDefaultSet.addToSet("lBicep", "lRerebrace01.mesh");
    mDefaultSet.addToSet("rBicep", "rRearebrace01.mesh");
    mDefaultSet.addToSet("lForearm", "lBracer01.mesh");
    mDefaultSet.addToSet("rForearm", "rBracer01.mesh");
    mDefaultSet.addToSet("lHand", "lGauntlet01.mesh");
    mDefaultSet.addToSet("rHand", "rGauntlet01.mesh");
    mDefaultSet.addToSet("lPinkie", "ring01.mesh");
    mDefaultSet.addToSet("rPinkie", "ring01.mesh");
    mDefaultSet.addToSet("lRing", "ring02.mesh");
    mDefaultSet.addToSet("rRing", "ring02.mesh");
    mDefaultSet.addToSet("lMiddle", "ring03.mesh");
    mDefaultSet.addToSet("rMiddle", "ring03.mesh");
    mDefaultSet.addToSet("lPointer", "ring04.mesh");
    mDefaultSet.addToSet("rPointer", "ring04.mesh");
    mDefaultSet.addToSet("chest", "chestPlate01.mesh");
    mDefaultSet.addToSet("waist", "belt01.mesh");
    mDefaultSet.addToSet("lThigh", "lCuisse01.mesh");
    mDefaultSet.addToSet("rThigh", "rCuisee01.mesh");
    mDefaultSet.addToSet("lShin", "lGreave01.mesh");
    mDefaultSet.addToSet("rShin", "rGreave01.mesh");
    mDefaultSet.addToSet("lFoot", "lBoot01.mesh");
    mDefaultSet.addToSet("rFoot", "rBoot01.mesh");
}
/*
void EquipmentSetManager::printSet(const string & setName)
{
    //blah
}

void EquipmentSetManager::printAllSets(void)
{
     //blah
}

void EquipmentSetManager::printSetList(void)
{
     //blah
}

void EquipmentSetManager::setCurrent(const string & setName)
{
     //blah
}
*/
