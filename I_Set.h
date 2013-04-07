#ifndef I_SET_H
#define I_SET_H

#include <string>
#include <map>

using namespace std;

class I_Set
{
public:
	I_Set(void);
	virtual ~I_Set(void);

    virtual string & getSetName(void)= 0;
    virtual void setName(const string & newName)= 0;
};

#endif // End I_SET_H