#include "TitleSet.h"


TitleSet::TitleSet(string setName) : mSetName(setName)
{
	cout << "Title Set created" << endl;
}


TitleSet::~TitleSet(void)
{
	cout << "Title Set destroyed" << endl;
}

TitleSet::TitleSet(const TitleSet & cSource)
{
    cout << "Title Set's Copy Constructor Called" << endl;
    mSetName = cSource.mSetName;
    mSet = cSource.mSet;
}


TitleSet & TitleSet::operator= (const TitleSet & cSource)
{
    if (this == &cSource)
        return *this;

    cout << "Title Set's Assignment Operator called" << endl;
    mSetName = cSource.mSetName;
    mSet = cSource.mSet;

    return *this;
}

void TitleSet::addToSet(const string & value)
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

void TitleSet::removeFromSet(const string & value)
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

string & TitleSet::getSetName(void)
{
    return mSetName;
}

void TitleSet::changeName(const string & newName)
{
    mSetName = newName;
}

vector<string> & TitleSet::getSet(void)
{
    return mSet;
}
