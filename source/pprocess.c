/* Pac-Man CMD "pprocess.c"
    
    Project name:   "Pac-Man CMD"

    Date modified:  "01/04/2024"

*/

// Libraries included:
#include "pprocess.h"
#include "display.h"
#include "typedefinitions.h"


/*....................................................................................................*/
/* Main process function: */
/*------------------------*/

// Proccessing:
void process(_program_data programData)
{
    // Starting 'endless' program loop:
    while (true)
    {
        // Setting current window size:
        programData->windows.windowSizes.currentWindowSize = queryWindowSize(&programData->windows.windowSizes.consoleHandle);

        switch (checkWindow(&programData->windows.windowSizes))
        {

        // Nothing to do with the window, content fits: (run the program)
        case ntodwtwf:

            // Running game controller:


            // Running player controller:


            // Running basic "AI" controller:



            break;
        
        // Needs refresh, content will fit:
        case nreff:

            // Correcting the content to fit in the window:


            break;

        // Needs refresh, content will not fit:
        case nrefnf:

            // Clearing screen:
            system("cls");

            // Printing 'Unsupported window size' at the middle of the screen:
            printAtTheMiddleOfTheScreen(&programData->windows, "UNSUPPORTED WINDOW SIZE");

            // Printing corner arrows:
            printCornerArrows(&programData->windows);

        // Nothing to do, content not fits...
        // case ntodnf:...
        }
    }
}
