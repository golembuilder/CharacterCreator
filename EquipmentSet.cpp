#include "EquipmentSet.h"

EquipmentSet::EquipmentSet(string setName) : SetMap(setName)
{
    //ctor
    cout << "Equipment Set created" << endl;
}

EquipmentSet::~EquipmentSet()
{
    //dtor
    cout << "Equipment Set destroyed" << endl;
}

EquipmentSet::EquipmentSet(const EquipmentSet & cSource) : SetMap(cSource)
{
	cout << "EquipmentSet copy constructor called" << endl;
}

EquipmentSet & EquipmentSet::operator= (const EquipmentSet & cSource)
{
	if (this == &cSource)
		return *this;

	cout << "EquipmentSet copy constructor called" << endl;
	/*
	mSetName = cSource.mSetName;
	mSetMap = cSource.mSetMap;

	return *this;
	*/
}

