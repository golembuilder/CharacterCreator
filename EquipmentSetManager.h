#ifndef EQUIPMENTSETMANAGER_H
#define EQUIPMENTSETMANAGER_H


#include <vector>
#include <iostream>
#include "SetMapManager.h"
#include "EquipmentSet.h"

using namespace std;

class EquipmentSetManager : public SetMapManager
{
    public:
        EquipmentSetManager();
        virtual ~EquipmentSetManager();

       	//TitleSetManager functions
		virtual SetMap * createDefaultSet(void);
	
		

    protected:
    private:
};

#endif // EQUIPMENTSETMANAGER_H
