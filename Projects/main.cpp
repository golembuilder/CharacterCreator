/*Until I get this stuff into a VC system, project info will go here.

Character Creator
Corbett Gildersleve
Project Time: 6 hours
*/

#include <iostream>
#include "Unit.h"
#include "PlayerCharacter.h"
#include "AppearanceSet.h"

using namespace std;

int main()
{

    Unit * mUnit = new PlayerCharacter("blah", "bleh");
    cout << mUnit->getName() << " " << mUnit->getUnitType() << endl;
    mUnit->setName("Knight");
    mUnit->setUnitType("WubWub");
    cout << mUnit->getName() << " " << mUnit->getUnitType() << endl;
    cout << "------------------" << endl << endl;

    //test AppearanceSet Creation.
    mUnit->getAppearanceSetManager().printSet("default");

    cout << "------------------" << endl;
    //cout << mUnit->getAppearanceSetManager().getSet("blah").getSetName() << endl;
    //mUnit->getAppearanceSetManager().getSet("blah").printSet();

    AppearanceSet * mSet = new AppearanceSet();
    mSet->setName("set2");
    mSet->setCurrent(false);
    mSet->addToSet("face", "scar01.mesh");

    mUnit->getAppearanceSetManager().addAppearanceSet(*mSet);
    mUnit->getAppearanceSetManager().printSet("set2");
   // mUnit->getAppearanceSetManager().printAllSets();

    delete(mUnit);
    mUnit = 0;


    return 0;
}
