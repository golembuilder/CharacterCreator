#ifndef SETMAPMANAGER_H
#define SETMAPMANAGER_H

#include <iostream>
#include "I_SetManager.h"
#include "SetMap.h"

#include <vector>

using namespace std;

class SetMapManager
{
    public:
        SetMapManager();
        virtual ~SetMapManager();

		//SetMapManager functions
      	virtual void addSet(SetMap & newSet);
		virtual void setAsCurrent(SetMap & set);
		virtual void swap(SetMap & newSet, SetMap & oldSet);
		virtual SetMap * getCurrentSet(void);
		virtual SetMap * getDefaultSet(void);
		virtual SetMap & getSet(const string & setName);
		virtual vector<SetMap> & getSetList(void);
		virtual void addToSet(const string & setName, const string & key, const string & value);
		virtual void removeFromSet(const string & setName, const string & key);
		
		virtual SetMap * createDefaultSet(void) = 0; //all derived classes need to create their own custom default set.
		
		//Overloaded I_SetManager functions
		virtual void setAsDefault(const string & setName);
		virtual void printSet(const string & setName);
		virtual void printAllSets(void);
		virtual void printSetList(void);
		virtual void setAsCurrent(const string & setName);

    protected:
		
    private:
		vector<SetMap> mSetList;
        vector<SetMap>::iterator mItr;
        SetMap * mDefaultSet;
		SetMap * mCurrentSet;
       

};

#endif // SETMAPMANAGER_H


