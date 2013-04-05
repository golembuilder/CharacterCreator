#ifndef APPEARANCESETMANAGER_H
#define APPEARANCESETMANAGER_H

#include <vector>
#include "AppearanceSet.h"

using namespace std;

class AppearanceSetManager
{
    public:
        AppearanceSetManager();
        virtual ~AppearanceSetManager();

        virtual void addAppearanceSet(AppearanceSet newSet);
        virtual AppearanceSet createDefaultSet(void);
        virtual void printSet(const string & setName);
        virtual void printAllSets(void);
        virtual void printSetList(void);
        //Setters


        //Getters
        virtual AppearanceSet & getCurrentSet(void);
        virtual AppearanceSet & getDefaultSet(void);
        virtual AppearanceSet & getSet(const string & setName);
        virtual const vector<AppearanceSet> * getSetList(void);

    protected:
    private:
        vector<AppearanceSet> mAppearanceSetList;
        vector<AppearanceSet>::iterator mItr;
        AppearanceSet mDefaultAppearanceSet;

};

#endif // APPEARANCESETMANAGER_H
