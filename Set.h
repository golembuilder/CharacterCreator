#ifndef SET_H
#define SET_H

#include <iostream>
#include <map>
#include <string>
#include "I_Set.h"

using namespace std;

class Set : public virtual I_Set
{
    public:
		Set(string setName = "");   //default and class constructor
        virtual ~Set();
        Set(const Set & cSource);   //copy constructor
		Set & operator= (const Set & cSource); //Assignment operator overload

		virtual void addToSet(const string & key, const string &  value);
        virtual void removeFromSet(const string & key);
        virtual string & getSetName(void);
        virtual void setName(const string & newName);

    protected:

		

    private:
        
};

#endif // SET_H
