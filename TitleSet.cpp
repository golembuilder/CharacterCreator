#include "TitleSet.h"


TitleSet::TitleSet(string setName) : SetVector(setName)
{
	cout << "Title Set created" << endl;
}


TitleSet::~TitleSet(void)
{
	cout << "Title Set destroyed" << endl;
}

TitleSet::TitleSet(const TitleSet & cSource) : SetVector(cSource)
{
    cout << "Title Set's Copy Constructor Called" << endl;
}


TitleSet & TitleSet::operator= (const TitleSet & cSource)
{
    if (this == &cSource)
        return *this;

    cout << "Title Set's Assignment Operator called" << endl;
	/*
    mSetName = cSource.mSetName;
    mSet = cSource.mSet;
	*/
    return *this;
}
