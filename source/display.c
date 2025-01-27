/* Pac-Man CMD "display.c"
    
    Project name:   "Pac-Man CMD"

    Date modified:  "01/04/2024"

*/

// Libraries included:
#include <display.h>
#include <typedefinitions.h>


/*....................................................................................................*/
/* Check window sizes support functions: */
/*---------------------------------------*/

// Check window size changed:
bool checkWindowSizeChanged(window_size inputWindowSizes)
{
    // Checking if the window size has changed:
    if (inputWindowSizes.currentWindowSize.X != inputWindowSizes.previousWindowSize.X || inputWindowSizes.currentWindowSize.Y != inputWindowSizes.previousWindowSize.Y)
    
    // Retruning true because the win size has changed:
    return true;

    // Returning false because the win size is still the same:
    return false;
}

// Check content fits:
bool checkContentFits(window_size inputWindowSizes)
{
    // Checking if the content fits on the window:
    if (inputWindowSizes.currentWindowSize.X < PROGRAM_WINDOW_WIDTH || inputWindowSizes.currentWindowSize.Y < PROGRAM_WINDOW_HEIGHT)

    // Returning false because it does not fit:
    return false;

    // Returning true because it fits:
    return true;
}


/*....................................................................................................*/
/* XXXXX functions: */
/*------------------*/

// Calculate origo:
PRINT_START_POSITION calculateOrigo(window_size windowSizes)
{
    // Declaring local origo variable:
    PRINT_START_POSITION origo;

    // Calculating origo position in 'X' axis:
    origo.X = windowSizes.currentWindowSize.X / 2;

    // Calculating origo position in 'Y' axis:
    origo.Y = windowSizes.currentWindowSize.Y / 2;

    // Returning origo:
    return origo;
}



/*....................................................................................................*/
/* Cursor functions: */
/*-------------------*/

// Set cursor position:
void setCursorPosition(POSITION set, int offset_x, int offset_y, HANDLE consoleHandle)
{
    set.X += offset_x;
    set.Y += offset_y;
    SetConsoleCursorPosition(consoleHandle, set);
}




/*....................................................................................................*/
/* Main functions: */
/*-----------------*/

// Query window size:
SIZE__ queryWindowSize(_HANDLE consoleHandle)
{
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    *consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(*consoleHandle, &consoleInfo);
    return consoleInfo.dwSize;
}

// Check window:
window_modes checkWindow(_window_size inputWindowSizes)
{   
    // Checking if the window size is changed or not:
    bool wSC = checkWindowSizeChanged(*inputWindowSizes);

    // Setting previous window size:
    inputWindowSizes->previousWindowSize = inputWindowSizes->currentWindowSize;
            
    // Switching to the right case:
    switch (wSC)
    {
    case true:

        // Checking if the content fits or not:
        switch (checkContentFits(*inputWindowSizes))
        {
        case true:
        
            // Returning 'Needs refresh, contents will fit':
            return nreff;
           
        default:

            // Returning 'Needs refresh, contents will not fit':
            return nrefnf;
        }
    
    default:

        // Checking if the content fits or not:
        switch (checkContentFits(*inputWindowSizes))
        {
        case true:
        
            // Returning 'Nothing to do, content fits':
            return ntodwtwf;
           
        default:

            // Returning 'Nothing to do, content not fits':
            return ntodnf;
        }
    }
}


/*.....................*/
/* ntodwtwf functions: */
/*---------------------*/



/*..................*/
/* nreff functions: */
/*------------------*/

// Correct the content to fit in the window:
void correctContentToFitInWindow(_program_data programData)
{
    switch (programData->windows.windowNumber)
    {
    
    // Menu:
    case 1:
        
        // Printing complete menu:
        //printCompleteMenu(programData);

        // Retuning:
        return;
    
    // Game:
    case 2:

        // Printing complete game:
        //printCompleteGame(programData);

        // Returning:
        return;
    
    // Settings:
    case 3:

        // Printing complete settings:
        //printCompleteSettings(programData);
    }
}

/*...................*/
/* nrefnf functions: */
/*-------------------*/

// Print corner arrows:
void printCornerArrows(_windows inputWindows)
{
    /* Initializeing corner positions: */

    // Initializing top left corner:
    POSITION topLeftCorner = {0, 0};

    // Initializing top right corner:
    POSITION topRightCorner = {inputWindows->windowSizes.currentWindowSize.X - 1, 0};

    // Initializing bottom left corner:
    POSITION bottomLeftCorner = {0, inputWindows->windowSizes.currentWindowSize.Y - 1};

    // Initializing bottom right corner:
    POSITION bottomRightCorner = {inputWindows->windowSizes.currentWindowSize.X - 1, inputWindows->windowSizes.currentWindowSize.Y - 1};


    /* Placeing charactes: */

    /* Top left corner: */
    // Setting cursor position:
    setCursorPosition(topLeftCorner, 0, 0, inputWindows->windowSizes.consoleHandle);

    // Putting character:
    putchar(201);

    /* Top right corner: */
    // Setting cursor position:
    setCursorPosition(topRightCorner, 0, 0, inputWindows->windowSizes.consoleHandle);

    // Putting character:
    putchar(187);

    /* Bottom left corner: */
    // Setting cursor position:
    setCursorPosition(bottomLeftCorner, 0, 0, inputWindows->windowSizes.consoleHandle);

    // Putting character:
    putchar(200);

    /* Bottom right corner: */
    // Setting cursor position:
    setCursorPosition(bottomRightCorner, 0, 0, inputWindows->windowSizes.consoleHandle);

    // Putting character:
    putchar(188);
}

// Print at the middle of the screen:
void printAtTheMiddleOfTheScreen(_windows inputWindows, char* message)
{
    // Calculating origo:
    inputWindows->printStartPositions.origo = calculateOrigo(inputWindows->windowSizes);

    // Calculateing the half of the message length:
    int messageLengthHalf = strlen(message) / 2;

    // Setting cursor position:
    setCursorPosition(inputWindows->printStartPositions.origo, -messageLengthHalf, 0, inputWindows->windowSizes.consoleHandle);

    // Printing message:
    printf("%s", message);
}



