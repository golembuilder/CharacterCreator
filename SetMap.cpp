#include "SetMap.h"

SetMap::SetMap(string setName) : mSetName(setName)
{
    //ctor
    cout << "SetMap Created" << endl;
}

SetMap::SetMap(const SetMap & cSource)
{
    cout << "SetMap's Copy Constructor Called" << endl;
    mSetName = cSource.mSetName;
    mSetMap = cSource.mSetMap;
}

SetMap::~SetMap()
{
    //dtor
    cout << "SetMap Destroyed" << endl;
}

SetMap & SetMap::operator= (const SetMap & cSource)
{

    if (this == &cSource)
        return *this;

    cout << "SetMap's Assignment Operator called" << endl;
    mSetName = cSource.mSetName;
    mSetMap = cSource.mSetMap;

    return *this;
}

void SetMap::addToSet(const string & key, const string & value)
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

void SetMap::removeFromSet(const string & key)
{
    if (mSetMap.count(key) > 0)
        mSetMap.erase(key);
    else
        throw key;
}

string & SetMap::getSetName(void)
{
    return mSetName;
}

void SetMap::changeName(const string & newName)
{
    mSetName = newName;
}

map<string, string> & SetMap::getSetMap(void)
{
    return mSetMap;
}

void SetMap::changeMap(const map<string, string> & newMap)
{
	mSetMap = newMap;
}

