/* Pac-Man CMD "initialize.h"
    
    Project name:   "Pac-Man CMD"
 
    Date modified:  "01/04/2024"

*/

#ifndef INITIALIZE_H
#define INITIALIZE_H


// Libraries included:
#include "typedefinitions.h"


/*....................................................................................................*/
/* Initialization functions: */
/*---------------------------*/

// Initialization:
ERROR_CODE initialize(_program_data programData, char* argv);

// Display file missing error dialog:
void displayFileMissingErrorDialog(ERROR_CODE inputErrorCode);


#endif