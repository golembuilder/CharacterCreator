#ifndef TITLESET_H
#define TITLESET_H

#include <string>
#include <iostream>
#include <vector>
#include "SetVector.h"

using namespace std;

class TitleSet : public SetVector
{
public:
	TitleSet(string setName = "");
	TitleSet(const TitleSet & cSource);
	TitleSet & operator= (const TitleSet & cSource);
	virtual ~TitleSet(void);

	
        
    protected:
    private:
	
};

#endif //End TITLESET_H

