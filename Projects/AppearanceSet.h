#ifndef APPEARANCESET_H
#define APPEARANCESET_H

#include <iostream>
#include <map>

using namespace std;

class AppearanceSet
{
    public:
        AppearanceSet();
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
        bool isCurrent;
        string mSetName;
        map<string, string> mAppearanceMap;
        std::map<string, string>::iterator mItr;
};

#endif // APPEARANCESET_H
