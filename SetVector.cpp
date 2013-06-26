#include "SetVector.h"


SetVector::SetVector(string setName) : mSetName(setName)
{
	cout << "SetVector created" << endl;
}


SetVector::~SetVector(void)
{
	cout << "SetVector destroyed" << endl;
}

SetVector::SetVector(const SetVector & cSource)
{
    cout << "SetVector's Copy Constructor Called" << endl;
    mSetName = cSource.mSetName;
    mSet = cSource.mSet;
}


SetVector & SetVector::operator= (const SetVector & cSource)
{
    if (this == &cSource)
        return *this;

    cout << "SetVector's Assignment Operator called" << endl;
    mSetName = cSource.mSetName;
    mSet = cSource.mSet;

    return *this;
}

void SetVector::addToSet(const string & value)
{
	mItr = mSet.begin();
	bool exists = false;

	for (mItr; mItr != mSet.end(); mItr++)
	{
		if (*mItr == value)
		{
			exists = true;
			break;
		}
	}
	
	if (exists == true)
		throw value;
	else
		mSet.push_back(value);
}

void SetVector::removeFromSet(const string & value)
{
	mItr = mSet.begin();

	for (mItr; mItr != mSet.end(); mItr++)
	{
		if (*mItr == value)
		{
			mSet.erase(mItr);
			break;
		}
	}
	
	if (mItr == mSet.end())
		throw value;
}

string & SetVector::getSetName(void)
{
    return mSetName;
}

void SetVector::changeName(const string & newName)
{
    mSetName = newName;
}

vector<string> & SetVector::getSet(void)
{
    return mSet;
}

bool SetVector::find(const string & value)
{
	mItr = mSet.begin();
	for (mItr; mItr != mSet.end(); mItr++)
	{
		if (*mItr == value)
			return true;
	}
	
	return false;		//if value is not found in the list, return false
}