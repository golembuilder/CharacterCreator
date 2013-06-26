#include "SetVectorManager.h"


SetVectorManager::SetVectorManager(void)
{
	mDefaultSet = mCurrentSet = NULL;

	mSetList.push_back(*createDefaultSet());
	mDefaultSet = mCurrentSet = &mSetList[0];

	cout << "SetVector Manager Created" << endl;
}


SetVectorManager::~SetVectorManager(void)
{
	mDefaultSet = mCurrentSet = NULL;
	cout << "SetVector Manager Destroyed" << endl;
}

SetVector * SetVectorManager::createDefaultSet(void)
{
	mDefaultSet = new SetVector();
	mDefaultSet->changeName("empty");

	return mDefaultSet;
}

void SetVectorManager::addSet(SetVector & newSet)
{
        if ( find(newSet.getSetName()) == true)
			cout << "Set: " << newSet.getSetName() << " already exists in the set list, set will not be added" << endl;
		else
		{
			mSetList.push_back(newSet);
			cout << "Added: "  << newSet.getSetName() << endl;      //testing
		}
}

SetVector * SetVectorManager::getCurrentSet(void)
{
    return mCurrentSet;
}

void SetVectorManager::setAsCurrent(const string & setName)
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

void SetVectorManager::setAsCurrent(SetVector & set)
{
		if ( find(set.getSetName()) == true )
		{
			mCurrentSet = &getSet(set.getSetName());
			cout << "Set: "  << set.getSetName() << " was found in the set list, it is now the current set" << endl;      //testing
		}
		else
		{
			//add the new set to the list, and set it as the current set.  
			mSetList.push_back(set);
			mCurrentSet = &getSet(set.getSetName());
			cout << "Set: "  << set.getSetName() << " is now the current set" << endl;      //testing
		}
}

void SetVectorManager::setAsDefault(const string & setName)
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

SetVector * SetVectorManager::getDefaultSet(void)
{
    return mDefaultSet;
}

SetVector & SetVectorManager::getSet(const string & setName)
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

vector<SetVector> & SetVectorManager::getSetList(void)
{
    return mSetList;
}

void SetVectorManager::printSet(const string & setName)
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

void SetVectorManager::printAllSets(void)
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

void SetVectorManager::printSetList(void)
{
    mItr = mSetList.begin();
    for (mItr; mItr != mSetList.end(); mItr++)
        cout << mItr->getSetName() << endl;
}

void SetVectorManager::swap(SetVector & newSet, SetVector & oldSet)
{
    SetVector temp = oldSet;
    oldSet = newSet;
    newSet = temp;
}

void SetVectorManager::addToSet(const string & setName, const string & value)
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

void SetVectorManager::removeFromSet(const string & setName, const string & value)
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

bool SetVectorManager::find(const string & setName)
{
	mItr = mSetList.begin();
	
	for (mItr; mItr != mSetList.end(); mItr++)
		if (mItr->getSetName() == setName)
			return true;

	return false;	//not found in the list
}