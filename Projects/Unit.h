#ifndef UNIT_H
#define UNIT_H

#include "AppearanceSetManager.h"
//#include "EquipmentSetManager.h"
//#include "SkillSetManager.h"
//#include "AbilitiesSetManager.h"
//#include "OgreSceneManager.h"

#include <iostream>


using namespace std;

class Unit
{
public:
    Unit(string name = "", string unitType = "");	//Default and User-generated constructor
	virtual ~Unit(void);

    virtual const string getName(void);
	virtual const string getUnitType(void);
	virtual AppearanceSetManager & getAppearanceSetManager(void);

	virtual void setName(const string & name);
	virtual void setUnitType(const string & unitType);



	string mName;
	string mUnitType;

protected:



private:

	AppearanceSetManager mAppearanceSetMgr;
	//EquipmentSetManager mEquipmentSetManager;
	//SkillSetManager mSkillSetMgr;
	//AbiliiesSetManager mAbiliiesSetMgr;

};

#endif //UNIT_H
