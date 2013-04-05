#ifndef APPEARANCESETMANAGER_H
#define APPEARANCESETMANAGER_H

#include <vector>
#include <iostream>
#include "AppearanceSet.h"
#include "SetManager.h"
using namespace std;

class AppearanceSetManager: virtual public SetManager
{
    public:
        AppearanceSetManager();
        virtual ~AppearanceSetManager();

        virtual void createDefaultSet(void);
        /*
        virtual void addSet(AppearanceSet newSet);
        virtual void printSet(const string & setName);
        virtual void printAllSets(void);
        virtual void printSetList(void);
        virtual void swap(AppearanceSet & newSet, AppearanceSet & oldSet);

        //Setters
        virtual void setCurrent(const string & setName);
        virtual void setCurrent(AppearanceSet & set);


        //Getters
        virtual AppearanceSet & getCurrentSet(void);
        virtual AppearanceSet & getDefaultSet(void);
        virtual AppearanceSet & getSet(const string & setName);
        virtual const vector<AppearanceSet> * getSetList(void);
        */
    protected:
    private:
        /*
        vector<AppearanceSet> mSetList;
        vector<AppearanceSet>::iterator mItr;
        AppearanceSet mDefaultSet;
        */
};

#endif // APPEARANCESETMANAGER_H
