#ifndef TITLESET_H
#define TITLESET_H

#include <string>
#include <iostream>
#include <vector>
#include "I_Set.h"

using namespace std;

class TitleSet : public I_Set
{
public:
	TitleSet(string setName = "");
	TitleSet(const TitleSet & cSource);
	TitleSet & operator= (const TitleSet & cSource);
	virtual ~TitleSet(void);

	//TitleSet functions
    virtual void addToSet(const string &  value);
    virtual void removeFromSet(const string & value);
	virtual vector<string> & getSet(void);
	
	//overloaded functions from I_SET
	virtual string & getSetName(void);
    virtual void setName(const string & newName);
        
    protected:
    private:
		string mSetName;
		vector<string> mSet;
        vector<string>::iterator mItr;
};

#endif //End TITLESET_H

