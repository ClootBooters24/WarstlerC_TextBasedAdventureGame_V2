#include <cstdlib>
#include <iostream>
using namespace std;

class Room
{
private:
	string Name;
	string Description;
	int maxGold;
	string Food;
	string Items;
	string Creature;


public:
	Room();
	~Room();

	void setName(const string name);
	void setDescription(const string description);
	void setGold(const int gold);
	void setFood(const string food);
	void setItems(const string item);
	void setCreature(const string creature);

	//Add getters for each
	string getName() const;
	string getDescription() const;
	int getGold() const;
	string getFood() const;
	string getItems() const;
	string getCreature() const;
	
	int findTreasure();
	int eatFood();
	int fightBattle();
	string findItem();

	void Print();
};