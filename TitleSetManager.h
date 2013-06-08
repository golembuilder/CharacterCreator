#ifndef TITLESETMANAGER_H
#define TITLESETMANAGER_H

#include "SetVectorManager.h"
#include "TitleSet.h"

class TitleSetManager : public virtual SetVectorManager
{
	public:
		TitleSetManager(void);
		virtual ~TitleSetManager(void);

		//TitleSetManager Functions
		virtual SetVector * createDefaultSet(void);	
};

#endif //End TITLESETMANAGER_H