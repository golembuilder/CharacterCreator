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
    
    mUnit->getAppearanceSetManager().printAllSets();
	mUnit->getEquipmentSetManager().printAllSets();
	mUnit->getTitleSetManager().printAllSets();

	cout << "-------------------" << endl;
	mUnit->printUnitInfo();
	
	
	

	//Clean Up Object Creation
	cout << "Deleting Objects" << endl << endl;
    delete(mUnit);
    mUnit = 0;
	
	cin.get();

    return 0;
}
