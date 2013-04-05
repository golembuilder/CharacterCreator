#ifndef SET_H
#define SET_H

#include <iostream>
#include <map>
#include <string>


using namespace std;

class Set
{
    public:
        Set(string setName = "");   //default and class constructor
        Set(const Set & cSource);   //copy constructor
        virtual ~Set();
        Set & operator= (const Set & cSource); //Assignment operator overload

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

#endif // SET_H
