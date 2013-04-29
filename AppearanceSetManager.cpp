#include "AppearanceSetManager.h"

AppearanceSetManager::AppearanceSetManager()
{
    //ctor
	mDefaultSet = mCurrentSet = NULL;	//initilizing both pointers to null

	
    mSetList.push_back(*createDefaultSet());
	mDefaultSet = mCurrentSet = &mSetList[0];	//setting the pointers to the first set in the list

    cout << "Appearance Set Manager Created" << endl;
}

AppearanceSetManager::~AppearanceSetManager()
{
    //dtor
    cout << "Appearance Set Manager Destroyed" << endl;
}

AppearanceSet * AppearanceSetManager::createDefaultSet(void)
{   //Eventually I'll want to have these values set by a datafile or a database.  For now, it's all static.
    //I might have a simpler set up where you can just put in pairs of items with groupings (Hands, Shoulders, etc.)
    //I also might just shrink some of these things down a lot.

	mDefaultSet = new AppearanceSet();
    mDefaultSet->setName("default");

    //Create the map.
    mDefaultSet->addToSet("hair", "hair01.mesh");
    mDefaultSet->addToSet("hairColor", "brown");
    mDefaultSet->addToSet("face", "face01.mesh");
    mDefaultSet->addToSet("lEye", "lEye01.mesh");
    mDefaultSet->addToSet("rEye", "rEye01.mesh");
    mDefaultSet->addToSet("lEyeColor", "blue");
    mDefaultSet->addToSet("rEyeColor", "yellow");

	return mDefaultSet;
}

void AppearanceSetManager::addSet(AppearanceSet & newSet)
{   cout << "Test: Add" << endl;
    try     //check to see if newSet is not contained in the set.
    {
        getSet( newSet.getSetName() );      //not sure I like this, but it works or now.
        cout << "Set: " << newSet.getSetName() << " already exists, set will not be added" << endl;
    }
    catch (bool flag)
    {	
        mSetList.push_back(newSet);
        cout << "Added: "  << newSet.getSetName() << endl;      //testing
    }
}

AppearanceSet * AppearanceSetManager::getCurrentSet(void)
{
    return mCurrentSet;
}

void AppearanceSetManager::setAsCurrent(const string & setName)
{
    try
    {
        mCurrentSet = &getSet(setName);
        cout << "Set Name: "  << setName << " was found in the set list, it is now the current set" << endl;      //testing
    }
    catch (bool flag)
    {
        cout << "Set: "  << setName << " was not found in the set list!" << endl;      //testing
    }
}

void AppearanceSetManager::setAsCurrent(AppearanceSet & set)
{
   
    try   //check to see if newSet is not contained in the set.
    {

        mCurrentSet = &getSet(set.getSetName());
        cout << "Set: "  << set.getSetName() << " was found in the set list, it is now the current set" << endl;      //testing
    }
    catch (bool flag)
    {
        mSetList.push_back(set);
		mCurrentSet = &getSet(set.getSetName());
        cout << "Set: "  << set.getSetName() << "has been added to the set list, and is now the current set" << endl;      //testing
    }
}

AppearanceSet * AppearanceSetManager::getDefaultSet(void)
{
	return mDefaultSet;
}

AppearanceSet & AppearanceSetManager::getSet(const string & setName)
{
    mItr = mSetList.begin();
    for (mItr; mItr != mSetList.end(); mItr++)
    {
        if (mItr->getSetName() == setName)
        {
            return  *mItr;
        }
    }
    throw false;        //set not found in the list
}

vector<AppearanceSet> & AppearanceSetManager::getSetList(void)
{
    return mSetList;
}

void AppearanceSetManager::printSet(const string & setName)
{
    mItr = mSetList.begin();
    map<string, string>::iterator mapItr;


    for (mItr; mItr != mSetList.end(); mItr++)
    {
        mapItr = mItr->getSetMap().begin();
        if(mItr->getSetName() == setName)
        {
            for (mapItr; mapItr != mItr->getSetMap().end(); mapItr++)
                cout << mapItr->first << ": " << mapItr->second << endl;
        }
    }
}

void AppearanceSetManager::printAllSets(void)
{
    mItr = mSetList.begin();
    map<string, string>::iterator mapItr;


    for (mItr; mItr != mSetList.end(); mItr++)
    {
        mapItr = mItr->getSetMap().begin();
        cout << "Set Name:" << mItr->getSetName() << endl;
            for (mapItr; mapItr != mItr->getSetMap().end(); mapItr++)
            {
                cout << mapItr->first << ": " << mapItr->second << endl;
            }
        cout << endl;
    }
}

void AppearanceSetManager::printSetList(void)
{
    mItr = mSetList.begin();
    for (mItr; mItr != mSetList.end(); mItr++)
        cout << mItr->getSetName() << endl;
}

void AppearanceSetManager::swap(AppearanceSet & newSet, AppearanceSet & oldSet)
{
    AppearanceSet temp = oldSet;
    oldSet = newSet;
    newSet = temp;
}

void AppearanceSetManager::addToSet(const string & setName, const  string & key, const string & value)
{
	getSet(setName).addToSet(key, value);
}

void AppearanceSetManager::removeFromSet(const string & setName, const string & key)
{
	try
	{
		getSet(setName).removeFromSet(key);
	}
	catch (bool)
	{
		cout << setName << " was not found in the set." << endl;
	}
}

void AppearanceSetManager::setAsDefault(const string & setName)
{
	if (mDefaultSet->getSetName() != setName)
	{
		try
		{
			mDefaultSet = &getSet(setName);
			cout << setName << " is now the default set" << endl;
		}
		catch (bool flag)
		{
			cout << "Set: "  << setName << " is not in the list" << endl;      //testing
		}
	}	
	else
		cout << setName << " is already the default set." << endl;
}
