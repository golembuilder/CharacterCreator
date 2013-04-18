#include "AppearanceSetManager.h"

AppearanceSetManager::AppearanceSetManager()
{
    //ctor
    
	mSetList.push_back(createDefaultSet());
    cout << "Appearance Set Manager Created" << endl;
}

AppearanceSetManager::~AppearanceSetManager()
{
    //dtor
    cout << "Appearance Set Manager Destroyed" << endl;
}

AppearanceSet & AppearanceSetManager::createDefaultSet(void)
{   //Eventually I'll want to have these values set by a datafile or a database.  For now, it's all static.
    //I might have a simpler set up where you can just put in pairs of items with groupings (Hands, Shoulders, etc.)
    //I also might just shrink some of these things down a lot.
    AppearanceSet * defaultSet = new AppearanceSet();
	defaultSet->setName("default");

    //Create the map.
    defaultSet->addToSet("hair", "hair01.mesh");
    defaultSet->addToSet("hairColor", "brown");
    defaultSet->addToSet("face", "face01.mesh");
    defaultSet->addToSet("lEye", "lEye01.mesh");
    defaultSet->addToSet("rEye", "rEye01.mesh");
    defaultSet->addToSet("lEyeColor", "blue");
    defaultSet->addToSet("rEyeColor", "yellow");

	return *defaultSet;

	delete(defaultSet);
	defaultSet = 0;
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

AppearanceSet & AppearanceSetManager::getCurrentSet(void)
{
    return mSetList[0];
}

void AppearanceSetManager::setCurrent(const string & setName)
{
    try
    {
        swap(getSet(setName), mSetList[0]);
        cout << "Set Name: "  << setName << " was found in the set list, it is now the current set" << endl;      //testing
    }
    catch (bool flag)
    {
        cout << "Set: "  << setName << " was not found!" << endl;      //testing
    }
}

void AppearanceSetManager::setCurrent(AppearanceSet & set)
{
    //This is a little confusing:
    //check getSet(), if 'set' is not in the list, a bool flag of false is thrown in getSet() and caught here.
    try     //check to see if newSet is not contained in the set.
    {
        swap( getSet(set.getSetName()), mSetList[0] );
        cout << "Set: "  << set.getSetName() << " was found in the set list, it is now the current set" << endl;      //testing
    }
    catch (bool flag)
    {
        swap(set, mSetList[0]);
        cout << "Set: "  << set.getSetName() << " is now the current set" << endl;      //testing
    }
}

AppearanceSet & AppearanceSetManager::getDefaultSet(void)
{
	if (mSetList[0].getSetName() == "default")
		return mSetList[0];		//default set is the current set
	else
		return mSetList[1];		//some other set is the current set, so return the value in space 1
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

const vector<AppearanceSet> * AppearanceSetManager::getSetList(void)
{
    return &mSetList;
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

void AppearanceSetManager::setDefault(const string & setName)
{
	if (setName != "default")
	{
		try
		{
			swap(getSet(setName), mSetList[1]);
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
