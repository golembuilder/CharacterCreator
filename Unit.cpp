#include "Unit.h"


using namespace std;

Unit::Unit(string name, string unitType) : mName(name), mUnitType(unitType) //Default and User constructor
{
    cout << "Unit Created" << endl;
}

Unit::~Unit(void)
{
    cout << "Unit Destroyed" << endl;
}

const string Unit::getName(void)
{
    return mName;
}

const string Unit::getUnitType(void)
{
    return mUnitType;
}

void Unit::setName(const string & name)
{
    mName = name;
}

void Unit::setUnitType(const string & unitType)
{
    mUnitType = unitType;
}

AppearanceSetManager & Unit::getAppearanceSetManager(void)
{
    return mAppearanceSetMgr;
}
