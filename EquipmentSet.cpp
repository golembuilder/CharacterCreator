#include "EquipmentSet.h"

EquipmentSet::EquipmentSet(string setName) : Set(setName)
{
    //ctor
    cout << "Equipment Set created" << endl;
}

EquipmentSet::~EquipmentSet()
{
    //dtor
    cout << "Equipment Set destroyed" << endl;
}

/*
void EquipmentSet::addToSet(const string & key, const string & value)
{

    if (mEquipmentMap.count(key) > 0)      //Checking to see if the key exists
    {
       mEquipmentMap[key] = value;
    }
    else
    {
       mEquipmentMap.insert(make_pair(key, value));
    }

}

void EquipmentSet::removeFromSet(const string & key, const string & svalue)
{
    if (mEquipmentMap.count(key) > 0)
        mEquipmentMap.find(key)->second = "";
    //else  launch an exception of some kind, or error message... value not there.
}

string & EquipmentSet::getSetName(void)
{
    return mSetName;
}

void EquipmentSet::setName(const string & newName)
{
    mSetName = newName;
}

map<string, string> & EquipmentSet::getEquipmentMap(void)
{
    return mEquipmentMap;
}
*/
