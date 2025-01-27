/* Pac-Man CMD "typedefinitions.h"
    
    Project name:   "Pac-Man CMD"
 
    Date modified:  "12/25/2023"

*/

#ifndef TYPEDEFINITIONS_H
#define TYPEDEFINITIONS_H


// Libraries included:
#include "included.h"
#include "definitions.h"


/*....................................................................................................*/
/* Type definitions: */
/*-------------------*/

// COORD alternatives: SIZE__, PRINT_START_POINT, _PRINT_START_POINT, POSITION, _POSITION
typedef COORD 
SIZE__,
PRINT_START_POSITION,
* _PRINT_START_POSITION,
POSITION,
* _POSITION;

// integer alternatives: MAP, _MAP
typedef int
MAP,
* _MAP,
ERROR_CODE;

// WORD alternatives: COLOR
typedef WORD
COLOR;

// void alternatives: NO_ERROR
typedef void
NO_ERROR_CODE;

// HANDLE alternatives:
typedef HANDLE
* _HANDLE;


/*....................................................................................................*/
/* Struct type definitions: */
/*--------------------------*/

/* Settings: */

// Settings:
typedef struct settings
{
    // Control layout: (W, A, S, D)
    char controlLayout[4], controlLayoutBuffer[4],

    // Program root directory path:
    * programRootDirectoryPath;

    // Control layout under change:
    bool underChange;

} settings,* _settings;


/* Windows: */

// Window sizes:
typedef struct window_size
{
    // Current window size:
    SIZE__ currentWindowSize,

    // Previous window size:
    previousWindowSize;

    // Console handle:
    HANDLE consoleHandle;

} window_size,* _window_size;


// Print start positions:
typedef struct print_start_positions
{
    // Window origo:
    PRINT_START_POSITION origo,

    // Menu components:
    menuBorder, menuLogo, menuIcons, menuMakerName, menuVersionNumber,

    // Game components:
    gameMap, gameOverMapStats, gameUnderMapStats, gameInformationBlock,

    // Settings menu components:
    settingsBorder, settingsIcons;

} print_start_positions,* _print_start_positions;


// Windows:
typedef struct windows
{
    // Window sizes:
    window_size windowSizes;

    // Print start positions:
    print_start_positions printStartPositions;

    // Logo:
    int logo[LOGO_HEIGHT][LOGO_WIDTH],

    // Opened window number:
    windowNumber,

    // Menu function number:
    menuFunctionNumber;

} windows,* _windows;


/* Game session: */

// Enemy characteristic:
typedef struct enemy_characteristic
{
    // Enemy ID:
    unsigned enemyID;

    // Enemy character body:
    int body;

    // Direction of movement:
    char direction,
    
    // Next direction of movement
    nextDirection;

    // Enenmy color:
    COLOR color;

    // Enemy position:
    POSITION position;

    // Enemy movement timer:
    LARGE_INTEGER movementTimer;

} enemy_characteristic,* _enemy_characteristic;


// Enemy list:
typedef struct enemy_list
{
    // Enemy characteristic:
    enemy_characteristic characteristic;

    // Next enemy:
    struct enemy_list* next;

} enemy_list_item,* _enemy_list_item;


// Enemy behavior:
typedef enum behavior
{
    // Escape behavior:
    escape,

    // Neutral behavior:
    neutral,

    // Aggressive behavior:
    aggressive

} enemy_behavior;


// Enemy datas:
typedef struct enemy_datas
{
    // Enemy list:
    _enemy_list_item enemyListHead;

    // Enemy eatable:
    bool enemyEatable;

    // Enemy behavior:
    enemy_behavior enemyBehavior;

} enemy_datas,* _enemy_datas;


// Player datas:
typedef struct player_datas
{
    // Player character body:
    int body;

    // Direction of movement:
    char direction,

    // Next direction of movement:
    nextDirection;

    // Player color:
    COLOR color;

    // Player position:
    POSITION position;

    // Player movement timer:
    LARGE_INTEGER movementTimer;

    // Player lives:
    unsigned lives;

} player_datas,* _player_datas;


// Game datas:
typedef struct game_datas
{
    // Map details:
    MAP map[GAME_MAP_LAYER_NUMBER][GAME_MAP_HEIGHT][GAME_MAP_WIDTH]; // 3 layer system: 1l Displayed map, 2l Collectibles map, 3l Graph map

    // Score:
    long long unsigned score,
    
    // High score:
    highScore;

} game_datas,* _game_datas;


// Session timers:
typedef struct session_times
{
    // Frequency:
    LARGE_INTEGER frequency,

    // Low frequency timer:
    lowFrequencyTimer,
    
    // Higher frequency timer:
    higherFrequencyTimer;

}session_timers,* _session_timers;


// Game session:
typedef struct game_session
{
    // Game session global timer datas:
    session_timers globalTimerDatas;

    // Player datas:
    player_datas playerDatas;

    // Enemy datas:
    enemy_datas enemyDatas;

    // Game datas:
    game_datas gameDatas;

} game_session,* _game_session;


/* Program data: */

// Program data:
typedef struct program_data
{
    // Program settings:
    settings settings;

    // Program windows:
    windows windows;

    // Game session:
    game_session gameSession;

} program_data,* _program_data;


/*....................................................................................................*/
/* Enum type definitions: */
/*------------------------*/

// Mode switch:
typedef enum mode
{
    // Visible layer:
    visible,

    // Collectibles layer:
    collectibles,

    // Graph layer:
    graph

} mode;

// Window modes:
typedef enum window_modes
{
    // Nothing to do with the window, content fits:
    ntodwtwf,

    // Nothing to do, content not fits:
    ntodnf,

    // Needs refresh, content will fit:
    nreff,

    // Needs refresh, content will not fit:
    nrefnf

} window_modes;



/*....................................................................................................*/
/* Function type definitions: */
/*----------------------------*/

// Get choosen layer:
typedef NO_ERROR_CODE (*_getChoosenLayer)(MAP map[GAME_MAP_LAYER_NUMBER][GAME_MAP_HEIGHT][GAME_MAP_WIDTH], char* line, mode modeSwitch, int Y, int X);


#endif