#include "AppearanceSet.h"

AppearanceSet::AppearanceSet(string setName) : mSetName(setName)
{
    //ctor
    cout << "Appearance Set Created" << endl;
}

AppearanceSet::AppearanceSet(const AppearanceSet & cSource)
{
    cout << "Appearance Set's Copy Constructor Called" << endl;
    mSetName = cSource.mSetName;
    mSetMap = cSource.mSetMap;
}

AppearanceSet::~AppearanceSet()
{
    //dtor
    cout << "Appearance Set Destroyed" << endl;
}

AppearanceSet & AppearanceSet::operator= (const AppearanceSet & cSource)
{

    if (this == &cSource)
        return *this;

    cout << "Appearance Set's Assignment Operator called" << endl;
    mSetName = cSource.mSetName;
    mSetMap = cSource.mSetMap;

    return *this;
}

void AppearanceSet::addToSet(const string & key, const string & value)
{

    if (mSetMap.count(key) > 0)      //Checking to see if the key exists
    {
        mSetMap[key] = value;
    }
    else
    {
        mSetMap.insert(make_pair(key, value));
    }
}

void AppearanceSet::removeFromSet(const string & key)
{
    if (mSetMap.count(key) > 0)
        mSetMap.erase(key);
    else
        throw key;
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
