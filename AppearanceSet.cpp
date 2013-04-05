#include "AppearanceSet.h"

AppearanceSet::AppearanceSet(string setName) : Set(setName)
{
    //ctor
    cout << "Appearance Set created" << endl;
}

AppearanceSet::~AppearanceSet()
{
    //dtor
    cout << "Appearance Set destroyed" << endl;
}

/*
void AppearanceSet::addToSet(const string & key, const string & value)
{

    if (mAppearanceMap.count(key) > 0)      //Checking to see if the key exists
    {
        mAppearanceMap[key] = value;
    }
    else
    {
        mAppearanceMap.insert(make_pair(key, value));
    }

}

void AppearanceSet::removeFromSet(const string & key, const string & svalue)
{
    if (mSetMap.count(key) > 0)
        mSetMap.find(key)->second = "";
    //else  launch an exception of some kind, or error message... value not there.
}

string & AppearanceSet::getSetName(void)
{
    return mSetName;
}

void AppearanceSet::setName(const string & newName)
{
    mSetName = newName;
}

map<string, string> & AppearanceSet::getSetMap(void)
{
    return mSetMap;
}

*/


