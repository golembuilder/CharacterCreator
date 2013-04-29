#ifndef I_SETMANAGER_H
#define I_SETMANAGER_H

#include <string>
#include <vector>


using namespace std;

class I_SetManager
{
public:
	I_SetManager(void);
	virtual ~I_SetManager(void);
	
    //virtual void createDefaultSet(void) = 0;
	virtual void setAsDefault(const string & setName) = 0;
    virtual void printSet(const string & setName) = 0;
    virtual void printAllSets(void) = 0;
    virtual void printSetList(void) = 0;
    virtual void setAsCurrent(const string & setName) = 0;

protected:
	
	
};

#endif //End I_SETMANAGER_H