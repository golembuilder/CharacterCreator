#ifndef APPEARANCESETMANAGER_H
#define APPEARANCESETMANAGER_H

#include <vector>
#include <iostream>
#include "I_SetManager.h"
#include "AppearanceSet.h"

using namespace std;

class AppearanceSetManager: virtual public I_SetManager
{
    public:
        AppearanceSetManager();
        virtual ~AppearanceSetManager();

		//AppearanceSetManager functions
      	virtual void addSet(AppearanceSet & newSet);
		virtual void setCurrent(AppearanceSet & set);
		virtual void swap(AppearanceSet & newSet, AppearanceSet & oldSet);
		virtual AppearanceSet & getCurrentSet(void);
		virtual AppearanceSet & getDefaultSet(void);
		virtual AppearanceSet & getSet(const string & setName);
		virtual const vector<AppearanceSet> * getSetList(void);
		virtual void addToSet(const string & setName, const string & key, const string & value);
		virtual AppearanceSet & createDefaultSet(void);
		
		//Overloaded I_SetManager functions
		virtual void setDefault(const string & setName);
		virtual void printSet(const string & setName);
		virtual void printAllSets(void);
		virtual void printSetList(void);
		virtual void setCurrent(const string & setName);

    protected:
    private:
        vector<AppearanceSet> mSetList;
        vector<AppearanceSet>::iterator mItr;
        //AppearanceSet mDefaultSet;
      
};

#endif // APPEARANCESETMANAGER_H
