#ifndef TYPES
#define TYPES

enum Tile{
    DARK_BLUE,
    YELLOW,
    RED,
    BLACK,
    LIGHT_BLUE,
    FIRST_PLAYER,
    NO_TILE,
};

#define ROW 5
#define COLUMN 5
#define DEFAULT_FACTORIES 6
#define TILES_IN_FACTORY 4
#define TILE_TYPES 5
#define EACH_COLOR_TILES 20
#define FLOOR_SIZE 7
#define MINUS_ONE 0
#define MINUS_TWO 2
#define MINUS_THREE 5

#define COMMAND_LENGTH 4
#define COMMAND_TURN_LENGTH 10
#define COMMAND_TEST_LENGTH 3
#define FACTORY_INDEX 5
#define TILE_INDEX 7
#define PATTERN_INDEX 9

#define DEFAULT_ROUND 5
#define DEFAULT_PLAYERS 2

#define R 'R'
#define Y 'Y'
#define B 'B'
#define L 'L'
#define U 'U'
#define F 'F'
#define N '.'

#define COMMAND_TURN "turn"
#define COMMAND_SAVE "save"
#define COMMAND_TEST "-t"
#define COMMAND_ENHANCED "-e"
#define COMMAND_AI "--ai"
#define COMMAND_SEED "-s"
#define DEFAULT_TILE_BAG "BYYBBBLLBRLLYURUBRRBBYYRYULLLRBYLUYRBLUBUBRBULUYBBLRRUYBLYBLLLURURUUYRLRRUYUULYUBRBYURYYYYYRUULLRRLB"


char convertToChar(Tile tile);
Tile convertToEnum(char tile);

#endif // TYPES