#ifndef APPEARANCESET_H
#define APPEARANCESET_H

#include <iostream>
#include <string>
#include <map>
#include "I_Set.h"

using namespace std;

class AppearanceSet : virtual public I_Set
{
	public:
        AppearanceSet(string setName = "");   //default and class constructor
		virtual ~AppearanceSet();
        AppearanceSet(const AppearanceSet & cSource);   //copy constructor
		AppearanceSet & operator= (const AppearanceSet & cSource); //Assignment operator overload
    
		virtual void addToSet(const string & key, const string &  value);
        virtual void removeFromSet(const string & key);
        virtual map<string, string> & getSetMap(void);
        virtual string & getSetName(void);
        virtual void setName(const string & newName);
        
    protected:
    private:
		string mSetName;
        map<string, string> mSetMap;
        map<string, string>::iterator mItr;

};

#endif // APPEARANCESET_H
