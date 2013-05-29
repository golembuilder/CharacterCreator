#include "AppearanceSetManager.h"

AppearanceSetManager::AppearanceSetManager() : SetMapManager()
{
    //ctor

    getSetList()[0] = *createDefaultSet();	//create a default appearance set and add it to the set list.
	setAsDefault(getSetList()[0].getSetName());
	setAsCurrent(getSetList()[0].getSetName());

    cout << "Appearance Set Manager Created" << endl;
	cout << "______________________________" << endl;
}

AppearanceSetManager::~AppearanceSetManager()
{
    //dtor
    cout << "Appearance Set Manager Destroyed" << endl;
}

SetMap * AppearanceSetManager::createDefaultSet(void)
{   //Overloaded SetMapManager default set creator function

	SetMap * defaultSet = new AppearanceSet();
    defaultSet->changeName("default");

    //Create the map.
    defaultSet->addToSet("hair", "hair01.mesh");
    defaultSet->addToSet("hairColor", "brown");
    defaultSet->addToSet("face", "face01.mesh");
    defaultSet->addToSet("lEye", "lEye01.mesh");
    defaultSet->addToSet("rEye", "rEye01.mesh");
    defaultSet->addToSet("lEyeColor", "blue");
    defaultSet->addToSet("rEyeColor", "yellow");

	return defaultSet;
}

