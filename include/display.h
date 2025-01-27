/* Pac-Man CMD "display.h"
    
    Project name:   "Pac-Man CMD"

    Date modified:  "01/04/2024"

*/

#ifndef DISPLAY_H
#define DISPLAY_H


// Libraries included:
#include "typedefinitions.h"


/*....................................................................................................*/
/* Main functions: */
/*-----------------*/

// Query window size:
SIZE__ queryWindowSize(_HANDLE consoleHandle);

// Checking window:
window_modes checkWindow(_window_size inputWindowSizes);

// Print at the middle of the screen:
void printAtTheMiddleOfTheScreen(_windows inputWindows, char* message);

// Print corner arrows:
void printCornerArrows(_windows inputWindows);



#endif