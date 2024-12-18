#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_HEALTH 100
#define DEFAULT_STRENGTH 10
#define MAX_ITEM_NAME 50
#define MAX_INVENTORY_SIZE 10

typedef struct {
    char name[MAX_ITEM_NAME];
    int health;
    int strength;
} Item;

typedef struct {
    char *name;
    int health;
    int strength;
} Creature;

typedef struct {
    int health;
    int strength;
    Item inventory[MAX_INVENTORY_SIZE];
    int inventory_count;
} Player;

typedef struct {
    char description[100];
    Creature creatures;
    Item items;
    int roomNumber;
    int creatureDefeated;
} Room;

// Global Variables
extern Player *player;
extern Room *rooms;
extern Room *currentRoom;
extern Item items[10];
extern Creature creatures[10];
extern char saveFileName[100];
extern int flamethrowerKey;
extern int treasureKey;

// Function Prototypes
void initializeGame();
void move();
void look();
void attack(Player *player, Room *room);
void pickup(Item item);
void inventory();
void parseCommand(int command);
void menu();
void state();
void saveGame();
void loadGame();
void loadCreatures(Creature *creatures);
void loadItems(Item *items);
void loadRooms(Room *rooms);
void freeMemory();

#endif
