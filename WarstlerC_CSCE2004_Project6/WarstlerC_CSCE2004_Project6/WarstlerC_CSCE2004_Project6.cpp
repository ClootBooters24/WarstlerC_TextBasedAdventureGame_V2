// WarstlerC_CSCE2004_Project6.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "player.h"
#include "room.h"

int main()
{
	// Initialize game
	srand(time(NULL));

	// Create room1
	Room room1;
	room1.setName("Throne Room");
	room1.setDescription(
		"\n------------------------------------------------------------\n"
		"You have entered the throne room.In the middle\n"
		"of the room there is a giant wooden throne with\n"
		"intricate carvings. As you take a closer look at the\n"
		"carvings, you see that they show bugbears chasing humans.\n"
		"Hmmm, maybe this is not a great place to stop for a rest.\n"
		"------------------------------------------------------------\n");
	room1.setItems("Torch");

	//setGold sets MAX_GOLD
	room1.setGold(25);
	room1.setFood("potion");
	room1.setCreature("None");

	// Create room2
	Room room2;
	room2.setName("Sleeping Quarters");
	room2.setDescription(
		"\n------------------------------------------------------------\n"
		"You enter what seems to be a religious alter room. You see\n"
		"skulls littering the floor as you enter the room. The air is\n"
		"stale, as if nobody has been in here for a very long time.\n"
		"------------------------------------------------------------\n");
	room2.setItems("Ornate Staff");
	room2.setGold(15);
	room2.setFood("apple");
	room2.setCreature("mindflayer");

	// Create player
	Player player;
	player.setName("Grett");
	player.setGold(0);
	player.setHealth(MAX_HEALTH);
	player.setItems("");

	// Call Player methods
	player.Print();

	// Call Room methods
	room1.Print();
	
	// Call Player methods
	player.setHealth(player.getHealth() - room1.fightBattle());
	player.setGold(player.getGold() + room1.findTreasure());
	player.setHealth(player.getHealth() + room1.eatFood());
	player.addItem(room1.findItem());
	player.Print();

	// Call Room methods
	room2.Print();

	// Call Player methods
	player.setHealth(player.getHealth() - room2.fightBattle());
	player.setGold(player.getGold() + room2.findTreasure());
	player.setHealth(player.getHealth() + room2.eatFood());
	player.addItem(room2.findItem());
	player.Print();

	return 0;
}