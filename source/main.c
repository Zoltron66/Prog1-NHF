/* Pac-Man CMD "main.c"
    
    Project name:   "Pac-Man CMD"
    
    Version:        "v1.1.062-alpha+01062024"

    Build type:     "alpha"
    
    Date modified:  "01/06/2024"

*/ 

// Libraries included:
#include "initialize.h"
#include "pprocess.h"
#include "cleanup.h"


/*..................................................*/
/* Program main function: */
int main(int argc, char* argv[])
{
    // Declaring program data:
    program_data programData;

    // Initializing:
    ERROR_CODE ERC = initialize(&programData, argv[0]);

    // If something goes wrong during initialization:
    if (ERC != SUCCESS)
    {
        // Displaing file missing error dialog by error code:
        displayFileMissingErrorDialog(ERC);

        // Retuning with the error code:
        return ERC;
    }
    
    // Processing:
    process(&programData);

    // Cleaning up:
    cleanup(&programData);

    // #debug mode:
    #ifdef __DEBUG
    // Pauseing program before end:
    system("pause");
    #endif

    return 0;
}
/* Program end... */
/*..................................................*/