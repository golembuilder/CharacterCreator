#ifndef EQUIPMENTSET_H
#define EQUIPMENTSET_H

#include <iostream>
#include <map>
#include "SetMap.h"

using namespace std;
class EquipmentSet : public SetMap
{
    public:
        EquipmentSet(string setName = "");
        virtual ~EquipmentSet();
		EquipmentSet(const EquipmentSet & cSource);
		EquipmentSet & operator=(const EquipmentSet & cSource);
        
    protected:
    private:
   
};

#endif // EQUIPMENTSET_H
