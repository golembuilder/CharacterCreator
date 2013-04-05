#include "TitleSetManager.h"


TitleSetManager::TitleSetManager(void)
{
	createDefaultSet();
	mSetList.push_back(mDefaultSet);
	cout << "Title Set Manager Created"
}


TitleSetManager::~TitleSetManager(void)
{
	cout << "Title Set Manager Destroyed" << endl;
}

void TitleSetManager::createDefaultSet(void)
{	
	mDefaultSet.addToSet("Adventurer", "Novice");
	mDefaultSet.addToSet("Crafter", "Novice");
	mDefaultSet.addToSet("Diplomat", "Novice");
}