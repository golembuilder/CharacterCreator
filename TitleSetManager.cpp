#include "TitleSetManager.h"


TitleSetManager::TitleSetManager(void)
{
	getSetList()[0] = *createDefaultSet();	//create a default appearance set and add it to the set list.
	
	setAsDefault(getSetList()[0].getSetName());
	setAsCurrent(getSetList()[0].getSetName());

	cout << "Title Set Manager Created" << endl;
}


TitleSetManager::~TitleSetManager(void)
{
	cout << "Title Set Manager Destroyed" << endl;
}

SetVector * TitleSetManager::createDefaultSet(void)
{	
	SetVector * defaultSet = new TitleSet();

	defaultSet->changeName("default");
	defaultSet->addToSet("Commoner");

	return defaultSet;	
}

