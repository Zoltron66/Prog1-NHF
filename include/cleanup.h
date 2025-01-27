/* Pac-Man CMD "cleanup.h"
    
    Project name:   "Pac-Man CMD"

    Date modified:  "01/04/2024"

*/

#ifndef CLEANUP_H
#define CLEANUP_H


// Libraries included:
#include "typedefinitions.h"


/*....................................................................................................*/
/* Freeing functions: */
/*--------------------*/

// Free settings:
void freeSettings(_settings inputSettings);

// Free game session:
void freeGameSession(_game_session inputGameSession);


/*....................................................................................................*/
/* Clean up functions: */
/*---------------------*/

// Cleanup:
void cleanup(_program_data inputProgramData);


#endif