#include "PlayerCharacter.h"
#include <iostream>

using namespace std;

PlayerCharacter::PlayerCharacter(string name, string unitType) : Unit(name, unitType)
{
    //ctor
    cout << "This is a PC" << endl;

}

PlayerCharacter::~PlayerCharacter()
{
    //dtor
    cout << "PC DYING!" << endl;
}

