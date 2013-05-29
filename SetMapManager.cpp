#include "SetMapManager.h"

SetMapManager::SetMapManager()
{
    //ctor
	mDefaultSet = mCurrentSet = NULL;	//initilizing both pointers to null
	
    mSetList.push_back(*createDefaultSet());	//create a default set and add it to the set list.
	
    cout <<  "SetMap Manager Created" << endl;
}

SetMapManager::~SetMapManager()
{
    //dtor
	mDefaultSet = mCurrentSet = NULL;
    cout << "SetMap Manager Destroyed" << endl;
}

SetMap * SetMapManager::createDefaultSet(void)
{   //Eventually I'll want to have these values set by a datafile or a database.  For now, it's all static.
    //I might have a simpler set up where you can just put in pairs of items with groupings (Hands, Shoulders, etc.)
    //I also might just shrink some of these things down a lot.

	mDefaultSet = new SetMap();
    mDefaultSet->changeName("empty");

    return mDefaultSet;
}

void SetMapManager::addSet(SetMap & newSet)
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

SetMap * SetMapManager::getCurrentSet(void)
{
    return mCurrentSet;
}

void SetMapManager::setAsCurrent(const string & setName)
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

void SetMapManager::setAsCurrent(SetMap & set)
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

SetMap * SetMapManager::getDefaultSet(void)
{
	return mDefaultSet;
}

SetMap & SetMapManager::getSet(const string & setName)
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

vector<SetMap> & SetMapManager::getSetList(void)
{
    return mSetList;
}

void SetMapManager::printSet(const string & setName)
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

void SetMapManager::printAllSets(void)
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

void SetMapManager::printSetList(void)
{
    mItr = mSetList.begin();
    for (mItr; mItr != mSetList.end(); mItr++)
        cout << mItr->getSetName() << endl;
}

void SetMapManager::swap(SetMap & newSet, SetMap & oldSet)
{
    SetMap temp = oldSet;
    oldSet = newSet;
    newSet = temp;
}

void SetMapManager::addToSet(const string & setName, const  string & key, const string & value)
{
	getSet(setName).addToSet(key, value);
}

void SetMapManager::removeFromSet(const string & setName, const string & key)
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

void SetMapManager::setAsDefault(const string & setName)
{
	if (mDefaultSet->getSetName() != setName)
	{
		try
		{
			mDefaultSet = &getSet(setName);
			cout << "Set Name: " << setName << " is now the default set" << endl;
		}
		catch (bool flag)
		{
			cout << "Set Name: "  << setName << " is not in the list" << endl;      //testing
		}
	}	
	else
		cout << "Set Name: " << setName << " is already the default set." << endl;
}
