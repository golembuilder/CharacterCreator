#include "TitleSetManager.h"


TitleSetManager::TitleSetManager(void)
{
	createDefaultSet();
	mSetList.push_back(mDefaultSet);
	cout << "Title Set Manager Created" << endl;
}


TitleSetManager::~TitleSetManager(void)
{
	cout << "Title Set Manager Destroyed" << endl;
}

void TitleSetManager::createDefaultSet(void)
{	
	mDefaultSet.setName("default");
	mDefaultSet.addToSet("Commoner");
	
}

void TitleSetManager::addSet(TitleSet & newSet)
{
    try     //check to see if newSet is not contained in the set.
    {
        getSet( newSet.getSetName() );      //not sure I like this, but it works or now.
        cout << "Set: " << newSet.getSetName() << " already exists, set will not be added" << endl;
    }
    catch (bool flag)
    {
        mSetList.push_back(newSet);
        cout << "Added: "  << newSet.getSetName() << endl;      //testing
    }

}

TitleSet & TitleSetManager::getCurrentSet(void)
{
    return mSetList[0];
}

void TitleSetManager::setCurrent(const string & setName)
{
    try
    {
        swap(getSet(setName), mSetList[0]);
        cout << "Set Name: "  << setName << " was found in the set list, it is now the current set" << endl;      //testing
    }
    catch (bool flag)
    {
        cout << "Set: "  << setName << " was not found!" << endl;      //testing
    }
}

void TitleSetManager::setCurrent(TitleSet & set)
{
    //This is a little confusing:
    //check getSet(), if 'set' is not in the list, a bool flag of false is thrown in getSet() and caught here.
    try     //check to see if newSet is not contained in the set.
    {
        swap( getSet(set.getSetName()), mSetList[0] );
        cout << "Set: "  << set.getSetName() << " was found in the set list, it is now the current set" << endl;      //testing
    }
    catch (bool flag)
    {
        swap(set, mSetList[0]);
        cout << "Set: "  << set.getSetName() << " is now the current set" << endl;      //testing
    }
}

TitleSet & TitleSetManager::getDefaultSet(void)
{
    return mDefaultSet;
}

TitleSet & TitleSetManager::getSet(const string & setName)
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

const vector<TitleSet> * TitleSetManager::getSetList(void)
{
    return &mSetList;
}

void TitleSetManager::printSet(const string & setName)
{
    mItr = mSetList.begin();
    vector<string>::iterator vectItr;

    for (mItr; mItr != mSetList.end(); mItr++)
    {
        vectItr = mItr->getSet().begin();
        if(mItr->getSetName() == setName)
        {
            for (vectItr; vectItr != mItr->getSet().end(); vectItr++)
                cout << *vectItr << endl;
        }
    }
}

void TitleSetManager::printAllSets(void)
{
	mItr = mSetList.begin();
    vector<string>::iterator vectItr;


    for (mItr; mItr != mSetList.end(); mItr++)
    {
		vectItr = mItr->getSet().begin();
        cout << "Set Name:" << mItr->getSetName() << endl;
            for (vectItr; vectItr != mItr->getSet().end(); vectItr++)
            {
                cout << *vectItr << endl;
            }
        cout << endl;
    }
}

void TitleSetManager::printSetList(void)
{
    mItr = mSetList.begin();
    for (mItr; mItr != mSetList.end(); mItr++)
        cout << mItr->getSetName() << endl;
}

void TitleSetManager::swap(TitleSet & newSet, TitleSet & oldSet)
{
    TitleSet temp = oldSet;
    oldSet = newSet;
    newSet = temp;
}

void TitleSetManager::addToSet(const string & setName, const string & value)
{
	try
	{
		getSet(setName).addToSet(value);
	}
	catch (string)
	{
		cout << value << " already exists in the set and will not be added again." << endl;
	}
	catch (bool)
	{
		cout << setName << " was not found in the set. " << endl;
	}
}

void TitleSetManager::removeFromSet(const string & setName, const string & value)
{
	try
	{
		getSet(setName).removeFromSet(value);
	}
	catch (string)
	{
		cout << value << " doesn't exist in the set and cannot be deleted." << endl;
	}
	catch (bool)
	{
		cout << setName << " was not found in the set. " << endl;
	}
}