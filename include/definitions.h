/* Pac-Man CMD "definitions.h"
    
    Project name:   "Pac-Man CMD"

    Date modified:  "12/25/2023"

*/

#ifndef DEFINITIONS_H
#define DEFINITIONS_H


// Debug mode:
#define __DEBUG // Uncomment it if needed


/*....................................................................................................*/
/* Foreground color definitions: */
/*-------------------------------*/

// Black:
#define BLACK_F 0x0000
// Gray:
#define GRAY_F 0x0008
// Light Gray:
#define LIGHT_GRAY_F 0x0007
// White:
#define WHITE_F 0x000F

// Red:
#define RED_F 0x0004
// Light Red:
#define LIGHT_RED_F 0x000C

// Green:
#define GREEN_F 0x0002
// Light Green:
#define LIGHT_GREEN_F 0x000A

// Blue:
#define BLUE_F 0x0001
// Light Blue:
#define LIGHT_BLUE_F 0x0009

// Sea Blue:
#define SEA_BLUE_F 0x0003
// Light Sea Blue:
#define LIGHT_SEA_BLUE_F 0x000B

// Purple:
#define PURPLE_F 0x0005
// Light Purple:
#define LIGHT_PURPLE_F 0x000D

// Yellow:
#define YELLOW_F 0x0006
// Light Yellow:
#define LIGHT_YELLOW_F 0x000E


/*....................................................................................................*/
/* Background color definitions: */
/*-------------------------------*/

// Black:
#define BLACK_B 0x0000
// Gray:
#define GRAY_B 0x0080
// Light Gray:
#define LIGHT_GRAY_B 0x0070
// White:
#define WHITE_B 0x00F0

// Red:
#define RED_B 0x0040
// Light Red:
#define LIGHT_RED_B 0x00C0

// Green:
#define GREEN_B 0x0020
// Light Green:
#define LIGHT_GREEN_B 0x00A0

// Blue:
#define BLUE_B 0x0010
// Light Blue:
#define LIGHT_BLUE_B 0x0090

// Sea Blue:
#define SEA_BLUE_B 0x0030
// Light Sea Blue:
#define LIGHT_SEA_BLUE_B 0x00B0

// Purple:
#define PURPLE_B 0x0050
// Light Purple:
#define LIGHT_PURPLE_B 0x00D0

// Yellow:
#define YELLOW_B 0x0060
// Light Yellow:
#define LIGHT_YELLOW_B 0x00E0


/*....................................................................................................*/
/* Frequently used numbers: */
/*--------------------------*/

// Game map defaults:
#define GAME_MAP_LAYER_NUMBER 3
#define GAME_MAP_HEIGHT 31
#define GAME_MAP_WIDTH 55

// File reading defaults:
#define LINE_LENGTH 100

// Logo dimension defaults:
#define LOGO_HEIGHT 10
#define LOGO_WIDTH 48

// ERROR_CODE flag statuses:
#define SUCCESS 0
#define FAILURE 1

// Bodies:
#define PLAYER_BODY 254
#define ENEMY_BODY 239

// Program window sizes:
#define PROGRAM_WINDOW_HEIGHT 33
#define PROGRAM_WINDOW_WIDTH 55


#endif