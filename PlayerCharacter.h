#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H

#include "Unit.h"
#include <iostream>

using namespace std;


class PlayerCharacter : public Unit
{
    public:
        /** Default constructor */
        PlayerCharacter(string name = "", string unitType = "");
        /** Default destructor */
        virtual ~PlayerCharacter();


    protected:



    private:
    //TitleSetManager mTitleSetMgr;

};

#endif // PLAYERCHARACTER_H
