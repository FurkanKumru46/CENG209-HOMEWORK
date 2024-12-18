#include "game.h"

// Global variables for the game
Player *player;
Room *rooms;
Room *currentRoom;
Item items[10];
Creature creatures[10];
char saveFileName[100];
int flamethrowerKey = 0;
int treasureKey = 0;

// Main function: Entry point of the game
int main() {
    int choice;
    printf("\nWelcome to the Dungeon Adventure Game!\n");
    printf("1. Load a saved game\n");
    printf("2. Start a new game\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter the save file name: ");
        scanf("%s", saveFileName);

      
        // Check if the save file exists
        FILE *file = fopen(saveFileName, "rb");
        if (file) {
            fclose(file);
            loadGame();
        } else {
            printf("No save file found. Starting a new game.\n");
            initializeGame();
        }
    } else if (choice == 2) {
        printf("Enter the save file name for this game: ");
        scanf("%s", saveFileName);
        initializeGame();
    } else {
        printf("Invalid choice. Exiting the game.\n");
        return 0;
    }

    printf("There is a treasure in one of the rooms, you must take that treasure and get out of the dungeon before you die.\n\n");

    while (1) {
        menu();
    }
    return 0;
}
// Displays the game menu and handles user input
void menu() {
    char input[10]; 
    int command;

    while (1) {
        printf("\n---------------- M E N U ----------------\n");
        printf("1. Move\n");
        printf("2. Show My State\n");
        printf("3. Inventory\n");
        printf("4. Look\n");
        printf("5. Attack\n");
        printf("6. Pick Up\n");
        printf("7. Save Game\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%s", input); 

        
        if (sscanf(input, "%d", &command) == 1) {
            parseCommand(command); 
        } else {
            printf("Invalid choice. Try again.\n"); 
        }
    }
}

// Parses the user's menu command and executes the corresponding function
void parseCommand(int command) {
    switch (command) {
        case 1:
            move();
            break;
        case 2:
            state();
            break;
        case 3:
            inventory();
            break;
        case 4:
            look();
            break;
        case 5:
            attack(player, currentRoom);
            break;
        case 6:
            if (currentRoom->creatureDefeated == 1) {
                pickup(currentRoom->items);
            } else {
                printf("You cannot pick up the item without defeating the creature in this room!\n");
            }
            break;
        case 7:
            saveGame();
            break;
        case 8:
            printf("Exiting the game...\n");
            freeMemory();
            exit(0);
            break;
        default:
            printf("Invalid choice. Try again.\n");
    }
}
// Initializes the game state and loads initial data
void initializeGame() {
    // Allocate memory for the player
    player = (Player *)malloc(sizeof(Player));
    if (!player) {
        printf("Memory allocation failed for player.\n");
        exit(1);
    }
    player->strength = DEFAULT_STRENGTH;
    player->health = DEFAULT_HEALTH;
    player->inventory_count = 0;

    // Allocate memory for the rooms
    rooms = (Room *)malloc(9 * sizeof(Room));

    // Load initial data for rooms, items, and creature
    loadRooms(rooms);
    loadItems(items);
    loadCreatures(creatures);

    // Initialize specific room states
    rooms[0].items = items[0];
    rooms[0].creatureDefeated = 1;
    rooms[1].items = items[1];
    rooms[1].creatures = creatures[3]; 
    rooms[2].items = items[2];
    rooms[2].creatures = creatures[4]; 
    rooms[3].items = items[3];
    rooms[3].creatures = creatures[5]; 
    rooms[4].items = items[4];
    rooms[4].creatures = creatures[6]; 
    rooms[5].items = items[6];      
    rooms[5].creatureDefeated = 1;         
    rooms[6].creatures = creatures[0]; 
    rooms[7].items = items[5];  
    rooms[7].creatureDefeated = 1;  
    rooms[8].creatures = creatures[1]; 

    // Set the initial room to room 0
    currentRoom = &rooms[0]; 
}

// Handles player movement between rooms
void move(){
    if (currentRoom->creatureDefeated == 0) {
        printf("You must defeat the creature in this room before moving to another room!\n");
        return;
    }
    int direction;
    printf("\nChoose one of the directions you can move ? \n");
    if (currentRoom->roomNumber == 0)
    {
        printf("1. \n");
        printf("2. \n");
        printf("3. Right\n");
        printf("4. \n");
        scanf("%d", &direction);
        switch (direction)
        {
        case 3:
            currentRoom = &rooms[1];
            printf("Moving towards room number 2\n");
            break;
        
        default:
            printf("You chose a direction in which you cannot move.\n");
            printf("Please, choose again.\n");
            break;
        }
    }else if (currentRoom->roomNumber == 1)
    {
        printf("1. Up\n");
        printf("2. Down\n");
        printf("3. Right\n");
        printf("4. Left\n");
        scanf("%d", &direction);
        switch (direction)
        {
        case 1:
            currentRoom = &rooms[4];
            printf("Moving towards room number 5\n");
            break;    
        case 2:
            currentRoom = &rooms[3];
            printf("Moving towards room number 4\n");
            break;    
        case 3:
            currentRoom = &rooms[2];
            printf("Moving towards room number 3\n");
            break;    
        case 4:
            currentRoom = &rooms[0];
            printf("Go back to room number 1\n");
            break;
        
        default:
            printf("You chose a direction in which you cannot move.\n");
            printf("Please, choose again.\n");
            break;
        }
    }else if (currentRoom->roomNumber == 2)
    {
        printf("1. \n");
        printf("2. \n");
        printf("3. \n");
        printf("4. Left\n");
        scanf("%d", &direction);
        switch (direction)
        {
        case 4:
            currentRoom = &rooms[1];
            printf("Go back to room number 2\n");
            break;
        
        default:
            printf("You chose a direction in which you cannot move.\n");
            printf("Please, choose again.\n");
            break;
        }

    }else if (currentRoom->roomNumber == 3)
    {
        printf("1. Up\n");
        printf("2. \n");
        printf("3. \n");
        printf("4. \n");
        scanf("%d", &direction);
        switch (direction)
        {
        case 1:
            currentRoom = &rooms[1];
            printf("Go back to room number 2\n");
            break;
        default:
            printf("You chose a direction in which you cannot move.\n");
            printf("Please, choose again.\n");
            break;
        }
    }else if (currentRoom->roomNumber == 4)
    {
        printf("1. \n");
        printf("2. Down\n");
        printf("3. Right\n");
        printf("4. \n");
        scanf("%d", &direction);
        switch (direction)
        {
        case 2:
            currentRoom = &rooms[1];
            printf("Go back to room number 2\n");
            break;
        case 3:
            currentRoom = &rooms[5];
            printf("Moving towards room number 6\n");
            break;
        default:
            printf("You chose a direction in which you cannot move.\n");
            printf("Please, choose again.\n");
            break;
        }
    }else if (currentRoom->roomNumber == 5)
    {
        printf("1. Up\n");
        printf("2. Down\n");
        printf("3. Right\n");
        printf("4. Left\n");
        scanf("%d", &direction);
        switch (direction)
        {
        case 1:
            currentRoom = &rooms[7];
            printf("Moving towards room number 8\n");
            break;
        case 2:
            currentRoom = &rooms[6];
            printf("You fell into lava and died\n");
            exit(1);
            break;
        case 3:
            if (flamethrowerKey == 1)
            {
                currentRoom = &rooms[8];
                printf("BOSS FIGHT!!!");
            }else
                printf("You need to find the flamethrower to unlock this room.");
            break;
        case 4:
            currentRoom = &rooms[4];
            printf("Go back to room number 5\n");
            break;           
        default:
            printf("You chose a direction in which you cannot move.\n");
            printf("Please, choose again.\n");
            break;
        }
    }else if (currentRoom->roomNumber == 7)
    {
        printf("1. \n");
        printf("2. Down\n");
        printf("3. \n");
        printf("4. \n");
        scanf("%d", &direction);
        switch (direction)
        {
        case 2:
            currentRoom = &rooms[5];
            printf("Go back to room number 6\n");
            break; 
        default:
            break;
        }
    }
    else if (currentRoom->roomNumber == 8)
    {
        printf("1. \n");
        printf("2. \n");
        printf("3. Exit\n");
        printf("4. Left\n");
        scanf("%d", &direction);
        switch (direction)
        {
        case 3:
            if (treasureKey == 1)
            {
                printf("Congratulations, you're out of Dungeon!");
                exit(1);
            }else
                printf("You have to find the treasure to get out.");
            break;
        case 4:
            currentRoom = &rooms[5];
            printf("Go back to room number 6\n");
            break;     
        default:
            break;
        }
    }
    
}
// This function allows the player to observe the current room and its contents.
void look() {
    // Check if the currentRoom pointer is valid.
    if (!currentRoom) {
        printf("Error: currentRoom is NULL!\n");
        return;
    }
    
    printf("\n");
    printf("%s \n", currentRoom->description);

    // Check if there are any creatures in the room that are not defeated.
    if (currentRoom->creatureDefeated == 0) {
        printf("\nCreature: %s\nHealth: %d\nStrength: %d\n",
               currentRoom->creatures.name, currentRoom->creatures.health, currentRoom->creatures.strength);
    } else {
        printf("\nNo creatures in this room.\n");
    }
    // Check if there are any items in the room.
    if (strlen(currentRoom->items.name) > 0) {
        printf("\nItem: %s (Health: %d, Strength: %d)\n",
               currentRoom->items.name, currentRoom->items.health, currentRoom->items.strength);
    } else {
        printf("\nNo items in this room.\n");
    }
}


// This function allows the player to attack creatures in the room.
void attack(Player *player, Room *room){
    printf("\n");
    // If the creature in the room is already defeated, notify the player.
    if (room->creatureDefeated == 1) {
        printf("No creatures to attack in this room.\n");
        return;
    }
    char ch;
     do {
        printf("Press (a) to attack, Press (r) to return: ");
        scanf(" %c", &ch);
        if (ch == 'a') {
            room->creatures.health -= player->strength;
            player->health -= room->creatures.strength;
            printf("You attacked!\n");

            if (room->creatures.health > 0 && player->health > 0)
            {
                printf("Your health: %d, Enemy health: %d\n", player->health, room->creatures.health);
            }

            if (room->creatures.health <= 0) {
                printf("You defeated the %s!\n", room->creatures.name);
                room->creatureDefeated = 1;
            }

            if (player->health <= 0) {
                printf("You have been defeated. Game Over!\n");
                freeMemory();
                exit(0);
            }
        } else if (ch == 'r') {
            printf("Returning to the previous room...\n");
            return;
        } else {
            printf("Invalid choice!\n");
        }
    } while (room->creatures.health > 0);
    if (room->roomNumber == 8)
    {   
        printf("WIN WIN WIN !!!\n");
        printf("You managed to kill Boss Pegasus, let's get out of here.");
    }
}

// This function handles picking up items in the room.
void pickup(Item item){
    // Check if there is any item in the room.
    if (strlen(item.name) == 0) {
        printf("There is no item to pick up in this room!\n");
        return;
    }
    // Ensure the player's inventory is not full.
    if (player->inventory_count >= MAX_INVENTORY_SIZE)
    {
        printf("Inventory is FULL!!!");
        return;   
    }
    // Add the item to the player's inventory.
    strncpy(player->inventory[player->inventory_count].name, item.name, MAX_ITEM_NAME);
    player->inventory_count++;
    player->strength += item.strength;
    player->health += item.health;
    // Clear the item from the room.
    memset(&currentRoom->items, 0, sizeof(Item));
    printf("%s added to inventory", item.name);
    // Check for special items.
    if (strcmp(item.name, "Flamethrower") == 0)
    {
        printf("You found the flamethrower !!");
        flamethrowerKey = 1;
    }
    if (strcmp(item.name, "Treasure") == 0)
    {
        printf("\nYou found the treasure !!!\n");
        treasureKey = 1;
    }
}

// Display the player's current inventory.
void inventory(){
    printf("\nInventory: \n");
    for (int i = 0; i < player->inventory_count; i++) {
        printf("%d. %s \n", i + 1, player->inventory[i].name);
    }
}

// Show the player's current state (health and strength).
void state(){
    printf("\nStrength: %d\n", player->strength);
    printf("Health: %d\n", player->health);
}

// Save the current game state to a file.
void saveGame() {
    FILE *file = fopen(saveFileName, "wb");
    if (!file) {
        printf("Failed to save the game.\n");
        return;
    }

    int currentRoomIndex = currentRoom - rooms; 
    fwrite(player, sizeof(Player), 1, file);
    fwrite(rooms, sizeof(Room), 9, file);
    fwrite(&currentRoomIndex, sizeof(int), 1, file); 
    fclose(file);
    printf("Game saved successfully.\n");
}

// Load a saved game state from a file.
void loadGame() {
    FILE *file = fopen(saveFileName, "rb");
    if (!file) {
        printf("Failed to load the game.\n");
        return;
    }

    // Allocate memory for the player and rooms during loading
    player = (Player *)malloc(sizeof(Player));
    if (!player) {
        printf("Memory allocation failed for player during loading.\n");
        fclose(file);
        return;
    }

    rooms = (Room *)malloc(9 * sizeof(Room));
    if (!rooms) {
        printf("Memory allocation failed for rooms during loading.\n");
        free(player);
        fclose(file);
        return;
    }

    int currentRoomIndex;
    fread(player, sizeof(Player), 1, file);
    fread(rooms, sizeof(Room), 9, file);
    fread(&currentRoomIndex, sizeof(int), 1, file); 
    fclose(file);

    currentRoom = &rooms[currentRoomIndex]; 
    printf("Game loaded successfully.\n");
}

// Load room data from a file and initialize the Room structures.
void loadRooms(Room *rooms) {
    FILE *file = fopen("rooms.txt", "r");
    if (!file) {
        printf("Failed to open rooms file.\n");
        exit(1);
    }

    int roomNumber;
    char description[100];
    // Read each line from the file, extracting room number and description.
    while (fscanf(file, "%d %[^\n]", &roomNumber, description) != EOF) {
        rooms[roomNumber].roomNumber = roomNumber;
        strncpy(rooms[roomNumber].description, description, sizeof(rooms[roomNumber].description));
        rooms[roomNumber].creatureDefeated = 0; 
    }
    fclose(file);
}

// Load item data from a file and initialize the Item structures.
void loadItems(Item *items) {
    FILE *file = fopen("items.txt", "r");
    if (!file) {
        printf("Failed to open items file.\n");
        exit(1);
    }

    char name[MAX_ITEM_NAME];
    int health, strength;
    int i = 0;
    // Read each line from the file, extracting item name, health, and strength.
    while (fscanf(file, "%s %d %d", name, &health, &strength) != EOF) {
        // Populate the Item structure for the current index.
        strncpy(items[i].name, name, MAX_ITEM_NAME);
        items[i].health = health;
        items[i].strength = strength;
        i++;
    }
    fclose(file);
}

// Load creature data from a file and initialize the Creature structures.
void loadCreatures(Creature *creatures) {
    FILE *file = fopen("creatures.txt", "r");
    if (!file) {
        printf("Failed to open creatures file.\n");
        exit(1);
    }

    char name[50];
    int health, strength;
    int i = 0;
    // Read each line from the file, extracting creature name, health, and strength.
    while (fscanf(file, "%s %d %d", name, &health, &strength) != EOF) {
        // Allocate memory for the creature's name and populate its attributes.
        creatures[i].name = strdup(name);
        creatures[i].health = health;
        creatures[i].strength = strength;
        i++;
    }
    fclose(file);
}

// Free dynamically allocated memory used by the player and rooms.
void freeMemory() {
    if (player) {
        free(player);
    }
    if (rooms) {
        free(rooms);
    }
}
