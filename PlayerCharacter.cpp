#include "PlayerCharacter.h"

using namespace std;

PlayerCharacter::PlayerCharacter(string name, string unitType) : Unit(name, unitType)
{
    //ctor
    cout << "PC created" << endl;

}

PlayerCharacter::~PlayerCharacter()
{
    //dtor
    cout << "PC Destroyed" << endl;
}

