#ifndef I_SETMANAGER_H
#define I_SETMANAGER_H

#include <string>
#include <vector>


using namespace std;

class I_SetManager
{
public:
	
	/*
	virtual void addSet(Set newSet) = 0;
    virtual void setCurrent(Set & set) = 0;
    virtual void swap(Set & newSet, Set & oldSet) = 0;
    virtual Set & getCurrentSet(void) = 0;
    virtual Set & getDefaultSet(void) = 0;
    virtual Set & getSet(const string & setName) = 0;
    virtual const vector<Set> * getSetList(void) = 0;
	virtual void addToSet(const string & setName, const string & key, const string & value) = 0;
	*/

	I_SetManager(void);
	virtual ~I_SetManager(void);
	
    //virtual void createDefaultSet(void) = 0;
	virtual void setDefault(const string & setName) = 0;
    virtual void printSet(const string & setName) = 0;
    virtual void printAllSets(void) = 0;
    virtual void printSetList(void) = 0;
    virtual void setCurrent(const string & setName) = 0;

protected:
	
	
};

#endif //End I_SETMANAGER_H