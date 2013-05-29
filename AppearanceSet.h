#ifndef APPEARANCESET_H
#define APPEARANCESET_H

#include <iostream>
#include <string>
#include <map>
#include "SetMap.h"

using namespace std;

class AppearanceSet : virtual public SetMap
{
	public:
        AppearanceSet(string setName = "");   //default and class constructor
		virtual ~AppearanceSet();
        AppearanceSet(const AppearanceSet & cSource);   //copy constructor
		AppearanceSet & operator= (const AppearanceSet & cSource); //Assignment operator overload
        
    protected:
    private:

};

#endif // APPEARANCESET_H
