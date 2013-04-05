#include "AppearanceSetManager.h"

AppearanceSetManager::AppearanceSetManager()
{
    //ctor
    mDefaultAppearanceSet = createDefaultSet();
    mDefaultAppearanceSet.setCurrent(true);
    mAppearanceSetList.push_back(mDefaultAppearanceSet);
}

AppearanceSetManager::~AppearanceSetManager()
{
    //dtor
}

void AppearanceSetManager::addAppearanceSet(AppearanceSet newSet)
{
    mAppearanceSetList.push_back(newSet);
    cout << "Added: "  << newSet.getSetName() << endl;
}

AppearanceSet AppearanceSetManager::createDefaultSet(void)
{   //Eventually I'll want to have these values set by a datafile or a database.  For now, it's all static.
    //I might have a simpler set up where you can just put in pairs of items with groupings (Hands, Shoulders, etc.)
    //I also might just shrink some of these things down a lot.
    mDefaultAppearanceSet.setName("default");
    mDefaultAppearanceSet.setCurrent(false);
    //Create the map.
    mDefaultAppearanceSet.addToSet("head", "helmet01.mesh");
    mDefaultAppearanceSet.addToSet("face", "mask01.mesh");
    mDefaultAppearanceSet.addToSet("neck", "collar01.mesh");
    mDefaultAppearanceSet.addToSet("neck", "collar01.mesh");
    mDefaultAppearanceSet.addToSet("lShoulder", "lPauldron01.mesh");
    mDefaultAppearanceSet.addToSet("rShoulder", "rPauldron01.mesh");
    mDefaultAppearanceSet.addToSet("lBicep", "lRerebrace01.mesh");
    mDefaultAppearanceSet.addToSet("rBicep", "rRearebrace01.mesh");
    mDefaultAppearanceSet.addToSet("lForearm", "lBracer01.mesh");
    mDefaultAppearanceSet.addToSet("rForearm", "rBracer01.mesh");
    mDefaultAppearanceSet.addToSet("lHand", "lGauntlet01.mesh");
    mDefaultAppearanceSet.addToSet("rHand", "rGauntlet01.mesh");
    mDefaultAppearanceSet.addToSet("lPinkie", "ring01.mesh");
    mDefaultAppearanceSet.addToSet("rPinkie", "ring01.mesh");
    mDefaultAppearanceSet.addToSet("lRing", "ring02.mesh");
    mDefaultAppearanceSet.addToSet("rRing", "ring02.mesh");
    mDefaultAppearanceSet.addToSet("lMiddle", "ring03.mesh");
    mDefaultAppearanceSet.addToSet("rMiddle", "ring03.mesh");
    mDefaultAppearanceSet.addToSet("lPointer", "ring04.mesh");
    mDefaultAppearanceSet.addToSet("rPointer", "ring04.mesh");
    mDefaultAppearanceSet.addToSet("chest", "chestPlate01.mesh");
    mDefaultAppearanceSet.addToSet("waist", "belt01.mesh");
    mDefaultAppearanceSet.addToSet("lThigh", "lCuisse01.mesh");
    mDefaultAppearanceSet.addToSet("rThigh", "rCuisee01.mesh");
    mDefaultAppearanceSet.addToSet("lShin", "lGreave01.mesh");
    mDefaultAppearanceSet.addToSet("rShin", "rGreave01.mesh");
    mDefaultAppearanceSet.addToSet("lFoot", "lBoot01.mesh");
    mDefaultAppearanceSet.addToSet("rFoot", "rBoot01.mesh");

    return mDefaultAppearanceSet;
}

AppearanceSet & AppearanceSetManager::getCurrentSet(void)
{
    mItr = mAppearanceSetList.begin();
    for (mItr; mItr != mAppearanceSetList.end(); mItr++)
        if (mItr->getCurrent())
            return *mItr;
}

AppearanceSet & AppearanceSetManager::getDefaultSet(void)
{
    return mDefaultAppearanceSet;
}

AppearanceSet & AppearanceSetManager::getSet(const string & setName)
{
    mItr = mAppearanceSetList.begin();
    for (mItr; mItr != mAppearanceSetList.end(); mItr++)
    {
        if (mItr->getSetName() == setName)
        {
            return  *mItr;
        }
    }
}

const vector<AppearanceSet> * AppearanceSetManager::getSetList(void)
{
    return &mAppearanceSetList;
}

void AppearanceSetManager::printSet(const string & setName)
{
    mItr = mAppearanceSetList.begin();
    map<string, string>::iterator mapItr;


    for (mItr; mItr != mAppearanceSetList.end(); mItr++)
    {
        mapItr = mItr->getAppearanceMap().begin();
        if(mItr->getSetName() == setName)
        {
            for (mapItr; mapItr != mItr->getAppearanceMap().end(); mapItr++)
                cout << mapItr->first << ": " << mapItr->second << endl;
        }
    }
}

void AppearanceSetManager::printAllSets(void)
{
    mItr = mAppearanceSetList.begin();
    map<string, string>::iterator mapItr;


    for (mItr; mItr != mAppearanceSetList.end(); mItr++)
    {
        mapItr = mItr->getAppearanceMap().begin();
        cout << "Set Name:" << mItr->getSetName() << endl;
            for (mapItr; mapItr != mItr->getAppearanceMap().end(); mapItr++)
                cout << mapItr->first << ": " << mapItr->second << endl;
    }
}

void AppearanceSetManager::printSetList(void)
{
    mItr = mAppearanceSetList.begin();
    for (mItr; mItr != mAppearanceSetList.end(); mItr++)
        cout << mItr->getSetName() << endl;
}
