#ifndef APPEARANCESETMANAGER_H
#define APPEARANCESETMANAGER_H

#include "SetMapManager.h"
#include "AppearanceSet.h"

using namespace std;

class AppearanceSetManager: virtual public SetMapManager
{
    public:
        AppearanceSetManager();
        virtual ~AppearanceSetManager();

		//AppearanceSetManager functions
    	virtual SetMap * createDefaultSet(void); 
		


    protected:
    private:
};

#endif // APPEARANCESETMANAGER_H
