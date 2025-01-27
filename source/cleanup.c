/* Pac-Man CMD "cleanup.c"
    
    Project name:   "Pac-Man CMD"

    Date modified:  "01/04/2024"

*/

// Libraries included:
#include "cleanup.h"
#include "typedefinitions.h"


/*....................................................................................................*/
/* Freeing functions: */
/*--------------------*/

// Free settings:
void freeSettings(_settings inputSettings)
{
    // Freeing the allocated memory:
    free(inputSettings->programRootDirectoryPath);
}

// Free Game session:
void freeGameSession(_game_session inputGameSession)
{
    // Creating head and third hand:
    _enemy_list_item head, 
    
    // Initializing third hand:
    thirdHand = inputGameSession->enemyDatas.enemyListHead;
    
    // Setting head:
    head = thirdHand;
    
    while (head != NULL)
    {
        //Setting third hand:
        thirdHand = thirdHand->next;

        // Freeing the allocated memory:
        free(head);

        // Setting head:
        head = thirdHand;
    }
}


/*....................................................................................................*/
/* Clean up functions: */
/*---------------------*/

// Cleanup:
void cleanup(_program_data inputProgramData)
{
    // Freeing settings:
    freeSettings(&inputProgramData->settings);

    // Freeing game session:
    freeGameSession(&inputProgramData->gameSession);
}