#ifndef SETMANAGER_H
#define SETMANAGER_H

#include <iostream>
#include "Set.h"
#include <vector>

using namespace std;

class SetManager
{
    public:
        SetManager();
        virtual ~SetManager();

        virtual void addSet(Set newSet);
        virtual void createDefaultSet(void);
        virtual void printSet(const string & setName);
        virtual void printAllSets(void);
        virtual void printSetList(void);
        virtual void setCurrent(const string & setName);
        virtual void setCurrent(Set & set);
        virtual void swap(Set & newSet, Set & oldSet);
        virtual void addToSet(const string & setName, const string & key, const string & value);
        virtual Set & getCurrentSet(void);
        virtual Set & getDefaultSet(void);
        virtual Set & getSet(const string & setName);
        virtual const vector<Set> * getSetList(void);

    protected:
        vector<Set> mSetList;
        vector<Set>::iterator mItr;
        Set mDefaultSet;

    private:


};

#endif // SETMANAGER_H


