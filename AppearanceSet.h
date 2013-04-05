#ifndef APPEARANCESET_H
#define APPEARANCESET_H

#include <iostream>
#include <map>
#include "Set.h"

using namespace std;

class AppearanceSet : virtual public Set
{
    public:
        AppearanceSet(string setName = "");
        virtual ~AppearanceSet();
        /*
        virtual void addToSet(const string & key, const string &  value);
        virtual void removeFromSet(const string & key);
        virtual map<string, string> & getSetMap(void);
        virtual string & getSetName(void);
        virtual void setName(const string & newName);
        */
    protected:
    private:

};

#endif // APPEARANCESET_H
