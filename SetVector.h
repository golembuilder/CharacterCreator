#ifndef SETVECTOR_H
#define SETVECTOR_H

#include "I_Set.h"
#include <iostream>
#include <vector>
#include <string>

class SetVector :
	public I_Set
{
public:
	SetVector(string setName = "");
	SetVector(const SetVector & cSource);
	SetVector & operator= (const SetVector & cSource);
	~SetVector(void);

	//SetVector functions
    virtual void addToSet(const string &  value);
    virtual void removeFromSet(const string & value);
	virtual vector<string> & getSet(void);
	
	//overloaded functions from I_SET
	virtual string & getSetName(void);
    virtual void changeName(const string & newName);
        
    protected:
    private:
		string mSetName;
		vector<string> mSet;
        vector<string>::iterator mItr;

};

#endif //End SETVECTOR_H