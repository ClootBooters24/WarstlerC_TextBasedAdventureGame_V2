#include "room.h"

Room::Room()
{
    Name = "none";
    Description = "none";
    maxGold = 0;
    Food = "none";
    Items = "none";
    Creature = "none";
}

Room::~Room()
{
}

//------------------------------------------------------------
// Purpose: Set Name value
//------------------------------------------------------------
void Room::setName(const string name)
{
    Name = name;
}

//------------------------------------------------------------
// Purpose: Set Description value
//------------------------------------------------------------
void Room::setDescription(const string descriptions)
{
    Description = descriptions;
}

//------------------------------------------------------------
// Purpose: Set Gold value
//------------------------------------------------------------
void Room::setGold(const int gold)
{
    maxGold = gold;
}

//------------------------------------------------------------
// Purpose: Set Food value
//------------------------------------------------------------
void Room::setFood(const string food)
{
    Food = food;
}

//------------------------------------------------------------
// Purpose: Set Items value
//------------------------------------------------------------
void Room::setItems(const string items)
{
    Items = items;
}

//------------------------------------------------------------
// Purpose: Set Creature value
//------------------------------------------------------------
void Room::setCreature(const string creature)
{
    Creature = creature;
}

//------------------------------------------------------------
// Purpose: Get Name value
//------------------------------------------------------------
string Room::getName() const
{
    return Name;
}

//------------------------------------------------------------
// Purpose: Get Description value
//------------------------------------------------------------
string Room::getDescription() const
{
    return Description;
}

//------------------------------------------------------------
// Purpose: Get Gold value
//------------------------------------------------------------
int Room::getGold() const
{
    return maxGold;
}

//------------------------------------------------------------
// Purpose: Get Food value
//------------------------------------------------------------
string Room::getFood() const
{
    return Food;
}

//------------------------------------------------------------
// Purpose: Get Items value
//------------------------------------------------------------
string Room::getItems() const
{
    return Items;
}

//------------------------------------------------------------
// Purpose: Get Creatures value
//------------------------------------------------------------
string Room::getCreature() const
{
    return Creature;
}

//------------------------------------------------------------
// Purpose: Print all Player data
//------------------------------------------------------------
void Room::Print()
{
    cout << "\nRoom Information" << endl;
    cout << "Name: " << Name << endl;
    cout << "Description: " << Description << endl;
    cout << "Max Gold: " << maxGold << endl;
    cout << "Food: " << Food << endl;
    cout << "Items: " << Items << endl;
    cout << "Creature: " << Creature << endl;
}

//------------------------------------------------------------
// Purpose: To simulate battle with a creature
// Input:   Creature number between [0..3]
// Output:  Amount of damage done to your health.
//------------------------------------------------------------
int Room::fightBattle()
{
    //Creature Information
    const int slimeDmg = 5;
    const int bugbearDmg = 15;
    const int mindflayerDmg = 25;

    int damage = 0;

    if (Creature == "slime")
    {
        damage = 1 + rand() % slimeDmg;
        cout << "\nYou trip over a slimy slime and do " 
            << damage << " damage to your health.\n";
    }
    else if (Creature == "bugbear")
    {
        damage = 1 + rand() % bugbearDmg;
        cout << "\nA hairy dwarf hits you with a club and does "
            << damage << " damage to your health.\n";
    }
    else if (Creature == "mindflayer")
    {
        damage = 1 + rand() % mindflayerDmg;
        cout << "\nAn angry mindflayer sucks your brain and does "
            << damage << " damage to your health.\n";
    }
    else
        cout << "\nIt is ghostly quiet here, you must be alone\n";

    return damage;
}

//------------------------------------------------------------
// Purpose: To eating food item to restore health.
// Input:   Food item number between [0..2]
// Output:  Health value after eating food.
//------------------------------------------------------------
int Room::eatFood()
{
    //Food Information
    const int appleHeal = 5;
    const int steakHeal = 20;
    const int potionHeal = 40;

    int healing = 0;

    if (Food == "apple")
    {
        healing = appleHeal;
        cout << "\nYou find a half eaten apple on the floor "
            << "which restores your health by " << appleHeal << endl;
    }
    else if (Food == "steak")
    {
        healing = steakHeal;
        cout << "\nYou find a warm and jucy steak on the table "
            << "which restores your health by " << steakHeal << endl;
    }
    else if (Food == "potion")
    {
        healing = potionHeal;
        cout << "\nYou find a red glowing potion on a shelf "
            << "which restores your health by " << potionHeal << endl;
    }
    else
        cout << "\nYour stomach is rumbling, but there is nothing to eat\n";

    return healing;
}

//------------------------------------------------------------
// Purpose: To calculate how much treasure is found
// Input:   Maximum amount of gold possible
// Output:  Actual amount of gold found
//------------------------------------------------------------
int Room::findTreasure()
{
    int gold = 1 + rand() % maxGold;
    if (gold < maxGold / 2)
        cout << "\nYou find " << gold << " gold pieces on the floor.\n";
    else
        cout << "\nYou find a huge mound of " << gold << " gold pieces!\n";

    return gold;
}

string Room::findItem()
{
    int number = rand() % 100;
    if (number < 75)
        return Items;
    else
        return "";
}