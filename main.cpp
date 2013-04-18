#include <iostream>
#include <string>
#include "Unit.h"
#include "PlayerCharacter.h"

using namespace std;

int main()
{
    Unit * mUnit = new PlayerCharacter("blah", "bleh");
    cout << "------------------" << endl;

    cout << mUnit->getName() << " " << mUnit->getUnitType() << endl;
    mUnit->setName("Knight");
    mUnit->setUnitType("WubWub");
    cout << mUnit->getName() << " " << mUnit->getUnitType() << endl;
    cout << "------------------" << endl;
	/*
    cout << "Creating a custom Appearance Set" << endl;
    
	AppearanceSet * mSet = new AppearanceSet();
    mSet->setName("set2");
    mSet->addToSet("face", "scar01.mesh");
	
    mUnit->getAppearanceSetManager().addSet(*mSet);
	
    cout << "-------------------" << endl;

    mUnit->getAppearanceSetManager().printAllSets();
    mUnit->getAppearanceSetManager().setCurrent("set2");
	cout << "Destroying: " << mSet->getSetName() << endl;
	
	delete(mSet);
    mSet = 0;
	*/
    cout << "-------------------" << endl << endl;
    //print off sets - should be set2 then default;

    
    mUnit->getAppearanceSetManager().printAllSets();
	mUnit->printUnitInfo();
	
	
	

	//Clean Up Object Creation
	cout << "Deleting Objects" << endl << endl;
    delete(mUnit);
    mUnit = 0;
	
	cin.get();

    return 0;
}
