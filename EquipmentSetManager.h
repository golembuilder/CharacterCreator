#ifndef EQUIPMENTSETMANAGER_H
#define EQUIPMENTSETMANAGER_H


#include <vector>
#include <iostream>
#include "SetManager.h"
#include "EquipmentSet.h"

using namespace std;

class EquipmentSetManager : public SetManager
{
    public:
        EquipmentSetManager();
        virtual ~EquipmentSetManager();

        virtual void createDefaultSet();
        /*
        virtual void printSet(const string & setName);
        virtual void printAllSets(void);
        virtual void printSetList(void);
        virtual void setCurrent(const string & setName);
        */

    protected:
    private:
        /*
        vector<EquipmentSet> mSetList;
        vector<EquipmentSet>::iterator mItr;
        EquipmentSet mDefaultSet;
        */
};

#endif // EQUIPMENTSETMANAGER_H
