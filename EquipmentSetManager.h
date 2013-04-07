#ifndef EQUIPMENTSETMANAGER_H
#define EQUIPMENTSETMANAGER_H


#include <vector>
#include <iostream>
#include "I_SetManager.h"
#include "EquipmentSet.h"

using namespace std;

class EquipmentSetManager : public I_SetManager
{
    public:
        EquipmentSetManager();
        virtual ~EquipmentSetManager();

       	//TitleSetManager functions
		virtual void addSet(EquipmentSet & newSet);
		virtual void setCurrent(EquipmentSet & set);
		virtual void swap(EquipmentSet & newSet, EquipmentSet & oldSet);
		virtual EquipmentSet & getCurrentSet(void);
		virtual EquipmentSet & getDefaultSet(void);
		virtual EquipmentSet & getSet(const string & setName);
		virtual const vector<EquipmentSet> * getSetList(void);
		virtual void addToSet(const string & setName, const string & key, const string & value);
		virtual void removeFromSet(const string & setName, const string & key);
	
		//Overloaded from I_SetManager
		virtual void createDefaultSet(void);
		virtual void printSet(const string & setName);
		virtual void printAllSets(void);
		virtual void printSetList(void);
		virtual void setCurrent(const string & setName);

    protected:
    private:
        vector<EquipmentSet> mSetList;
        vector<EquipmentSet>::iterator mItr;
        EquipmentSet mDefaultSet;
};

#endif // EQUIPMENTSETMANAGER_H
