/*Until I get this stuff into a VC system, project info will go here.

Character Creator
Corbett Gildersleve
Project Time: 6 hours
*/

#include <iostream>
#include <string>
#include "Unit.h"
#include "PlayerCharacter.h"
#include "AppearanceSet.h"

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

    cout << "Creating a custom Appearance Set" << endl;
    AppearanceSet * mSet = new AppearanceSet();
    mSet->setName("set2");
    mSet->addToSet("face", "scar01.mesh");
    mUnit->getAppearanceSetManager().addSet(*mSet);
    cout << "-------------------" << endl;

    mUnit->getAppearanceSetManager().printAllSets();
    mUnit->getAppearanceSetManager().setCurrent(*mSet);

    cout << "-------------------" << endl << endl;
    //print off sets - should be set2 then default;

    mUnit->getAppearanceSetManager().printAllSets();
    mUnit->getAppearanceSetManager().setCurrent("default");
    mUnit->getAppearanceSetManager().printAllSets();
	
	cout << "-------------------" << endl << endl;
    cout << "printing off character info" << endl;
	mUnit->printUnitInfo();
	
	//Clean Up Object Creation
    delete(mSet);
    mSet = 0;
    delete(mUnit);
    mUnit = 0;
	
	cin.get();

    return 0;
}
