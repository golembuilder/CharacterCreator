#ifndef TITLESETMANAGER_H
#define TITLESETMANAGER_H

#include "SetManager.h"

class TitleSetManager : public virtual SetManager
{
public:
	TitleSetManager(void);
	virtual ~TitleSetManager(void);

	void createDefaultSet(void);

};

#endif //End TITLESETMANAGER_H