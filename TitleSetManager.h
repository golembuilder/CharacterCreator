#ifndef TITLESETMANAGER_H
#define TITLESETMANAGER_H

#include "I_SetManager.h"
#include "TitleSet.h"

class TitleSetManager : public virtual I_SetManager
{
public:
	TitleSetManager(void);
	virtual ~TitleSetManager(void);

	//TitleSetManager functions
	virtual void addSet(TitleSet & newSet);
    virtual void setCurrent(TitleSet & set);
    virtual void swap(TitleSet & newSet, TitleSet & oldSet);
    virtual TitleSet & getCurrentSet(void);
    virtual TitleSet & getDefaultSet(void);
    virtual TitleSet & getSet(const string & setName);
    virtual const vector<TitleSet> * getSetList(void);
	virtual void addToSet(const string & setName, const string & value);
	virtual void removeFromSet(const string & setName, const string & value);
	
	//Overloaded from I_SetManager
    virtual void createDefaultSet(void);
    virtual void printSet(const string & setName);
    virtual void printAllSets(void);
    virtual void printSetList(void);
    virtual void setCurrent(const string & setName);

private:
	TitleSet mDefaultSet;
	vector<TitleSet> mSetList;
	vector<TitleSet>::iterator mItr;
	
};

#endif //End TITLESETMANAGER_H