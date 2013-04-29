#include "EquipmentSetManager.h"


EquipmentSetManager::EquipmentSetManager()
{
    //ctor
	mDefaultSet = mCurrentSet = NULL;

    mSetList.push_back(*createDefaultSet());
	mDefaultSet = mCurrentSet = &mSetList[0];	//pointing both sets to the default set

    cout << "Equipment Set Manager Created" << endl;

}

EquipmentSetManager::~EquipmentSetManager()
{
    //dtor
    cout << "Equipment Set Manager Destroyed" << endl;
}

EquipmentSet * EquipmentSetManager::createDefaultSet(void)
{
	mDefaultSet = new EquipmentSet();

    mDefaultSet->setName("default");

    //Create the map.
    mDefaultSet->addToSet("head", "helmet01.mesh");
    mDefaultSet->addToSet("face", "mask01.mesh");
    mDefaultSet->addToSet("neck", "collar01.mesh");
    mDefaultSet->addToSet("neck", "collar01.mesh");
    mDefaultSet->addToSet("lShoulder", "lPauldron01.mesh");
    mDefaultSet->addToSet("rShoulder", "rPauldron01.mesh");
    mDefaultSet->addToSet("lBicep", "lRerebrace01.mesh");
    mDefaultSet->addToSet("rBicep", "rRearebrace01.mesh");
    mDefaultSet->addToSet("lForearm", "lBracer01.mesh");
    mDefaultSet->addToSet("rForearm", "rBracer01.mesh");
    mDefaultSet->addToSet("lHand", "lGauntlet01.mesh");
    mDefaultSet->addToSet("rHand", "rGauntlet01.mesh");
    mDefaultSet->addToSet("lPinkie", "ring01.mesh");
    mDefaultSet->addToSet("rPinkie", "ring01.mesh");
    mDefaultSet->addToSet("lRing", "ring02.mesh");
    mDefaultSet->addToSet("rRing", "ring02.mesh");
    mDefaultSet->addToSet("lMiddle", "ring03.mesh");
    mDefaultSet->addToSet("rMiddle", "ring03.mesh");
    mDefaultSet->addToSet("lPointer", "ring04.mesh");
    mDefaultSet->addToSet("rPointer", "ring04.mesh");
    mDefaultSet->addToSet("chest", "chestPlate01.mesh");
    mDefaultSet->addToSet("waist", "belt01.mesh");
    mDefaultSet->addToSet("lThigh", "lCuisse01.mesh");
    mDefaultSet->addToSet("rThigh", "rCuisee01.mesh");
    mDefaultSet->addToSet("lShin", "lGreave01.mesh");
    mDefaultSet->addToSet("rShin", "rGreave01.mesh");
    mDefaultSet->addToSet("lFoot", "lBoot01.mesh");
    mDefaultSet->addToSet("rFoot", "rBoot01.mesh");

	return mDefaultSet;
}

void EquipmentSetManager::addSet(EquipmentSet & newSet)
{
	mSetList.push_back(newSet);
}

EquipmentSet * EquipmentSetManager::getCurrentSet(void)
{
    return mCurrentSet;
}

void EquipmentSetManager::setAsCurrent(const string & setName)
{
    try
    {
		mCurrentSet = &getSet(setName);
        cout << "Set Name: "  << setName << " was found in the set list, it is now the current set" << endl;      //testing
    }
    catch (bool flag)
    {
        cout << "Set: "  << setName << " was not found!" << endl;      //testing
    }
}

void EquipmentSetManager::setAsCurrent(EquipmentSet & set)
{
    try     //check to see if newSet is not contained in the set.
    {
		mCurrentSet = &getSet(set.getSetName());
        cout << "Set: "  << set.getSetName() << " was found in the set list, it is now the current set" << endl;      //testing
    }
    catch (bool flag)
    {
        mSetList.push_back(set);
		mCurrentSet = &getSet(set.getSetName());
        cout << "Set: "  << set.getSetName() << " is now the current set" << endl;      //testing
    }
}

EquipmentSet * EquipmentSetManager::getDefaultSet(void)
{
    return mDefaultSet;
}

EquipmentSet & EquipmentSetManager::getSet(const string & setName)
{
    mItr = mSetList.begin();
    for (mItr; mItr != mSetList.end(); mItr++)
    {
        if (mItr->getSetName() == setName)
        {
            return  *mItr;
        }
    }
    throw false;        //set not found in the list
}

vector<EquipmentSet> & EquipmentSetManager::getSetList(void)
{
    return mSetList;
}

void EquipmentSetManager::printSet(const string & setName)
{
    mItr = mSetList.begin();
    map<string, string>::iterator mapItr;


    for (mItr; mItr != mSetList.end(); mItr++)
    {
        mapItr = mItr->getSetMap().begin();
        if(mItr->getSetName() == setName)
        {
            for (mapItr; mapItr != mItr->getSetMap().end(); mapItr++)
                cout << mapItr->first << ": " << mapItr->second << endl;
        }
    }
}

void EquipmentSetManager::printAllSets(void)
{
    mItr = mSetList.begin();
    map<string, string>::iterator mapItr;


    for (mItr; mItr != mSetList.end(); mItr++)
    {
        mapItr = mItr->getSetMap().begin();
        cout << "Set Name:" << mItr->getSetName() << endl;
            for (mapItr; mapItr != mItr->getSetMap().end(); mapItr++)
            {
                cout << mapItr->first << ": " << mapItr->second << endl;
            }
        cout << endl;
    }
}

void EquipmentSetManager::printSetList(void)
{
    mItr = mSetList.begin();
    for (mItr; mItr != mSetList.end(); mItr++)
        cout << mItr->getSetName() << endl;
}

void EquipmentSetManager::swap(EquipmentSet & newSet, EquipmentSet & oldSet)
{
	EquipmentSet temp = oldSet;
    oldSet = newSet;
    newSet = temp;
}

void EquipmentSetManager::addToSet(const string & setName, const  string & key, const string & value)
{
	try
	{
		getSet(setName).addToSet(key, value);
	}
	catch (bool)
	{
		cout << setName << " was not found in the set." << endl;
	}
}

void EquipmentSetManager::removeFromSet(const string & setName, const string & key)
{
	try
	{
		getSet(setName).removeFromSet(key);
	}
	catch (bool)
	{
		cout << setName << " was not found in the set." << endl;
	}
}

void EquipmentSetManager::setAsDefault(const string & setName)
{
	if (mDefaultSet->getSetName() != setName)
	{
		try
		{
			mDefaultSet = &getSet(setName);
			cout << setName << " is now the default set" << endl;
		}
		catch (bool flag)
		{
			cout << "Set: "  << setName << " is not in the list" << endl;      //testing
		}
	}	
	else
		cout << setName << " is already the default set." << endl;
}

