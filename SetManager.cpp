#include "SetManager.h"
#include <iostream>
#include <string>

using namespace std;

SetManager::SetManager()
{
    //ctor
    cout << "Set Manager Created" << endl;
}

SetManager::~SetManager()
{
    //dtor
    cout << "Set Manager Destroyed" << endl;
}
void SetManager::createDefaultSet(void)
{
    mDefaultSet.setName("default");

    //Create the map.
   try
   {
       mDefaultSet.addToSet("Blah", "Blue");
   }
   catch (string exception)
   {
       cout << exception <<  " not found!" << endl;
   }
}

void SetManager::addSet(Set newSet)
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

Set & SetManager::getSet(const string & setName)
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

Set & SetManager::getCurrentSet(void)
{
    return mSetList[0];
}

void SetManager::setCurrent(const string & setName)
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

void SetManager::setCurrent(Set & set)
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

Set & SetManager::getDefaultSet(void)
{
    return mDefaultSet;
}



const vector<Set> * SetManager::getSetList(void)
{
    return &mSetList;
}

void SetManager::printSet(const string & setName)
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

void SetManager::printAllSets(void)
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

void SetManager::printSetList(void)
{
    mItr = mSetList.begin();
    for (mItr; mItr != mSetList.end(); mItr++)
        cout << mItr->getSetName() << endl;
}

void SetManager::swap(Set & newSet, Set & oldSet)
{
    Set temp = oldSet;
    oldSet = newSet;
    newSet = temp;
}

void SetManager::addToSet(const string & setName, const string & key, const string & value)
{
    try
    {
        getSet(setName).addToSet(key, value);
    }
    catch (string exception)
    {
        cout << exception << " not found!" << endl;
    }
}
