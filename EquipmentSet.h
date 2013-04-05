#ifndef EQUIPMENTSET_H
#define EQUIPMENTSET_H

#include <iostream>
#include <map>
#include "SetManager.h"

using namespace std;
class EquipmentSet : public Set
{
    public:
        EquipmentSet(string setName = "");
        virtual ~EquipmentSet();
        /*
        virtual void addToSet(const string & key, const string &  value);
        virtual void removeFromSet(const string & key, const string & value);
        virtual map<string, string> & getEquipmentMap(void);
        virtual string & getSetName(void);
        virtual void setName(const string & newName);
        */
    protected:
    private:
    /*
        string mSetName;
        map<string, string> mEquipmentMap;
        map<string, string>::iterator mItr;
    */
};

#endif // EQUIPMENTSET_H
