#include "EquipmentSet.h"

EquipmentSet::EquipmentSet(string setName) : mSetName(setName)
{
    //ctor
    cout << "Equipment Set created" << endl;
}

EquipmentSet::~EquipmentSet()
{
    //dtor
    cout << "Equipment Set destroyed" << endl;
}

EquipmentSet::EquipmentSet(const EquipmentSet & cSource)
{
	cout << "EquipmentSet copy constructor called" << endl;
	mSetName = cSource.mSetName;
	mSetMap = cSource.mSetMap;
}

EquipmentSet & EquipmentSet::operator=(const EquipmentSet & cSource)
{
	if (this == &cSource)
		return *this;

	cout << "EquipmentSet copy constructor called" << endl;
	mSetName = cSource.mSetName;
	mSetMap = cSource.mSetMap;
}

void EquipmentSet::addToSet(const string & key, const string & value)
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

void EquipmentSet::removeFromSet(const string & key)
{
    if (mSetMap.count(key) > 0)
        mSetMap.erase(key);
	else
		throw key;
}

string & EquipmentSet::getSetName(void)
{
    return mSetName;
}

void EquipmentSet::setName(const string & newName)
{
    mSetName = newName;
}

map<string, string> & EquipmentSet::getSetMap(void)
{
    return mSetMap;
}

