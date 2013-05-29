#include "AppearanceSet.h"

AppearanceSet::AppearanceSet(string setName) : SetMap(setName)
{
    //ctor
    cout << "Appearance Set Created" << endl;
}

AppearanceSet::AppearanceSet(const AppearanceSet & cSource) : SetMap(cSource)
{
    cout << "Appearance Set's Copy Constructor Called" << endl;
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
	/*
    mSetName = cSource.getSetName();
    mSetMap = cSource.getSetMap();
	*/
    return *this;
	
}
