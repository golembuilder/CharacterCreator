#include "Set.h"


Set::Set(string setName) : mSetName(setName)
{
    //ctor
    cout << "Set Created" << endl;
}

Set::Set(const Set & cSource)
{
    cout << "Copy Constructor Called" << endl;
    mSetName = cSource.mSetName;
    mSetMap = cSource.mSetMap;
}

Set::~Set()
{
    //dtor
    cout << "Set Destroyed" << endl;
}

Set & Set::operator= (const Set & cSource)
{

    if (this == &cSource)
        return *this;

    cout << "Set's Assignment Operator called" << endl;
    mSetName = cSource.mSetName;
    mSetMap = cSource.mSetMap;

    return *this;
}

void Set::addToSet(const string & key, const string & value)
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

void Set::removeFromSet(const string & key)
{
    if (mSetMap.count(key) > 0)
        mSetMap.erase(key);
    else
        throw key;
}

string & Set::getSetName(void)
{
    return mSetName;
}

void Set::setName(const string & newName)
{
    mSetName = newName;
}

map<string, string> & Set::getSetMap(void)
{
    return mSetMap;
}
