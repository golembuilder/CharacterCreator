#ifndef APPEARANCESET_H
#define APPEARANCESET_H

#include <iostream>
#include <map>

using namespace std;

class AppearanceSet
{
    public:
        AppearanceSet(string setName = "", bool currentFlag = false);
        virtual ~AppearanceSet();

        virtual void addToSet(const string & key, const string &  value);
        virtual void removeFromSet(const string & key, const string & value);
        virtual map<string, string> & getAppearanceMap(void);
        virtual string & getSetName(void);
        virtual void setName(const string & newName);
        virtual void setCurrent(bool flag);
        virtual bool getCurrent(void);

    protected:
    private:
        string mSetName;
        bool isCurrent;
        map<string, string> mAppearanceMap;
        map<string, string>::iterator mItr;
};

#endif // APPEARANCESET_H
