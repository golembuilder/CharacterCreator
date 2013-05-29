#ifndef SETMAP_H
#define SETMAP_H

#include <iostream>
#include <map>
#include <string>
#include "I_Set.h"

using namespace std;

class SetMap : I_Set
{
    public:
       	SetMap(string setName = "");   //default and class constructor
		virtual ~SetMap();
        SetMap(const SetMap & cSource);   //copy constructor
		SetMap & operator= (const SetMap & cSource); //Assignment operator overload
    
		virtual void addToSet(const string & key, const string &  value);
        virtual void removeFromSet(const string & key);
        virtual map<string, string> & getSetMap(void);
        virtual string & getSetName(void);
        virtual void changeName(const string & newName);
		virtual void changeMap(const map<string, string> & newMap);
        
    protected:
	

		
    private:
		string mSetName;
        map<string, string> mSetMap;
        map<string, string>::iterator mItr;

        
};

#endif // SETMAP_H
