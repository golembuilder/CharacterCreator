#include "TitleSetManager.h"


TitleSetManager::TitleSetManager(void)
{
	mDefaultSet = mCurrentSet = NULL;

	mSetList.push_back(*createDefaultSet());
	mDefaultSet = mCurrentSet = &mSetList[0];

	cout << "Title Set Manager Created" << endl;
}


TitleSetManager::~TitleSetManager(void)
{
	cout << "Title Set Manager Destroyed" << endl;
}

TitleSet * TitleSetManager::createDefaultSet(void)
{	
	mDefaultSet = new TitleSet();

	mDefaultSet->setName("default");
	mDefaultSet->addToSet("Commoner");

	return mDefaultSet;	
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

TitleSet * TitleSetManager::getCurrentSet(void)
{
    return mCurrentSet;
}

void TitleSetManager::setAsCurrent(const string & setName)
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

void TitleSetManager::setAsCurrent(TitleSet & set)
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

void TitleSetManager::setAsDefault(const string & setName)
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

TitleSet * TitleSetManager::getDefaultSet(void)
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

vector<TitleSet> & TitleSetManager::getSetList(void)
{
    return mSetList;
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

