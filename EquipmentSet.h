#ifndef EQUIPMENTSET_H
#define EQUIPMENTSET_H

#include <iostream>
#include <map>
#include "I_Set.h"

using namespace std;
class EquipmentSet : public I_Set
{
    public:
        EquipmentSet(string setName = "");
        virtual ~EquipmentSet();
		EquipmentSet(const EquipmentSet & cSource);
		EquipmentSet & operator=(const EquipmentSet & cSource);
      
        virtual void addToSet(const string & key, const string &  value);
        virtual void removeFromSet(const string & key);
        virtual map<string, string> & getSetMap(void);
        virtual string & getSetName(void);
        virtual void setName(const string & newName);
        
    protected:
    private:
        string mSetName;
        map<string, string> mSetMap;
        map<string, string>::iterator mItr;
   
};

#endif // EQUIPMENTSET_H
