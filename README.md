# CENG209-HOMEWORK
# Dungeon Adventure Game

Dungeon Adventure Game is a text-based adventure game where players navigate through a dungeon, battle creatures, collect items, and aim to find the treasure to escape.

## Features
- **Interactive Gameplay**: Explore interconnected rooms, fight creatures, and collect items.
- **Combat Mechanics**: Engage in battles with creatures that guard certain rooms.
- **Inventory Management**: Pick up items to boost your health and strength.
- **Save and Load System**: Save your progress and resume the game later.
- **Dynamic Navigation**: Move between rooms by defeating creatures blocking your path.

## Getting Started

### Prerequisites
- A C compiler (e.g., GCC)
- Make utility
- Command-line terminal

### Installation
1. Clone the repository or extract the ZIP file.
   ```bash
   git clone <repository-url>
   cd Dungeon_Adventure_Game
   ```

2. Use the provided `Makefile` to compile the game:
   ```bash
   make
   ```

3. Run the game executable:
   ```bash
   ./game
   ```

### File Structure
- `game.c`: Main source file containing game logic.
- `game.h`: Header file with function and structure definitions.
- `rooms.txt`: Defines the rooms and their descriptions.
- `items.txt`: Specifies the items and their effects.
- `creatures.txt`: Contains details about creatures and their attributes.
- `Makefile`: Automates the build process.

### How to Play
1. Start the game and choose to load a saved game or begin a new one.
2. Navigate through rooms by entering directional commands.
3. Use `look` to inspect rooms for items and creatures.
4. Fight creatures using the `attack` command.
5. Collect items to enhance your attributes.
6. Find the treasure and escape the dungeon to win.

### Controls
- `north`, `south`, `east`, `west`: Move in the specified direction.
- `look`: Inspect the current room.
- `attack`: Engage in combat with a creature.
- `pickup`: Collect an item.
- `save`: Save your current progress.
- `exit`: Quit the game.

## Contribution
Contributions are welcome! If you have suggestions for improvements, feel free to open an issue or submit a pull request.

## License
This project is licensed under the MIT License. See `LICENSE` for details.

## Acknowledgments
- The developers of the Dungeon Adventure Game.
- Inspiration from classic text-based adventure games.

---

Enjoy your adventure!
