#include "AppearanceSetManager.h"

AppearanceSetManager::AppearanceSetManager()
{
    //ctor
    createDefaultSet();
    mSetList.push_back(mDefaultSet);
    cout << "Appearance Set Manager Created" << endl;
}

AppearanceSetManager::~AppearanceSetManager()
{
    //dtor
    cout << "Appearance Set Manager Destroyed" << endl;
}

void AppearanceSetManager::createDefaultSet(void)
{   //Eventually I'll want to have these values set by a datafile or a database.  For now, it's all static.
    //I might have a simpler set up where you can just put in pairs of items with groupings (Hands, Shoulders, etc.)
    //I also might just shrink some of these things down a lot.
    mDefaultSet.setName("default");

    //Create the map.
    mDefaultSet.addToSet("hair", "hair01.mesh");
    mDefaultSet.addToSet("hairColor", "brown");
    mDefaultSet.addToSet("face", "face01.mesh");
    mDefaultSet.addToSet("lEye", "lEye01.mesh");
    mDefaultSet.addToSet("rEye", "rEye01.mesh");
    mDefaultSet.addToSet("lEyeColor", "blue");
    mDefaultSet.addToSet("rEyeColor", "yellow");
}
/*
void AppearanceSetManager::addSet(AppearanceSet newSet)
{
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
        mapItr = mItr->getAppearanceMap().begin();
        if(mItr->getSetName() == setName)
        {
            for (mapItr; mapItr != mItr->getAppearanceMap().end(); mapItr++)
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
        mapItr = mItr->getAppearanceMap().begin();
        cout << "Set Name:" << mItr->getSetName() << endl;
            for (mapItr; mapItr != mItr->getAppearanceMap().end(); mapItr++)
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
*/
