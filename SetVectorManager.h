#ifndef SETVECTORMANAGER_H
#define SETVECTORMANAGER_H

#include "I_SetManager.h"
#include "SetVector.h"

class SetVectorManager : public I_SetManager
{

public:
	SetVectorManager(void);
	virtual ~SetVectorManager(void);

	
		//SetVectorManager functions
		virtual void addSet(SetVector & newSet);
		virtual void setAsCurrent(SetVector & set);
		virtual void swap(SetVector & newSet, SetVector & oldSet);
		virtual SetVector * getCurrentSet(void);
		virtual SetVector * getDefaultSet(void);
		virtual SetVector & getSet(const string & setName);
		virtual vector<SetVector> & getSetList(void);
		virtual void addToSet(const string & setName, const string & value);
		virtual void removeFromSet(const string & setName, const string & value);
		virtual SetVector * createDefaultSet() = 0;		//forces every child class to create their own custom default set creator.
	
		//Overloaded from I_SetManager
		virtual void setAsDefault(const string & setName);
		virtual void printSet(const string & setName);
		virtual void printAllSets(void);
		virtual void printSetList(void);
		virtual void setAsCurrent(const string & setName);

	private:
		vector<SetVector> mSetList;
		vector<SetVector>::iterator mItr;
		SetVector * mDefaultSet;
		SetVector * mCurrentSet;

};


#endif //End SETVECTORMANAGER_H
