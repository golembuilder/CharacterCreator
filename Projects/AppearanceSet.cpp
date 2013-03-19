#include "AppearanceSet.h"

AppearanceSet::AppearanceSet()
{
    //ctor
}

AppearanceSet::~AppearanceSet()
{
    //dtor
}


void AppearanceSet::addToSet(const string & key, const string & value)
{

    if (mAppearanceMap.count(key) > 0)      //Checking to see if the key exists
        mAppearanceMap[key] = value;
    else
        mAppearanceMap.insert(make_pair(key, value));
}

void AppearanceSet::removeFromSet(const string & key, const string & svalue)
{
    //if(mAppearanceMap.find(key))
        mAppearanceMap.find(key)->second = "";
    //else  launch an exception of some kind, or error message... value no there.
}

string & AppearanceSet::getSetName(void)
{
    return mSetName;
}

void AppearanceSet::setName(const string & newName)
{
    mSetName = newName;
}

map<string, string> & AppearanceSet::getAppearanceMap(void)
{
    return mAppearanceMap;
}

void AppearanceSet::setCurrent(bool flag)
{
    isCurrent = flag;
}

bool AppearanceSet::getCurrent(void)
{
    return isCurrent;
}


