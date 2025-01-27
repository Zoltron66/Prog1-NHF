/* Pac-Man CMD "initialize.c"
    
    Project name:   "Pac-Man CMD"

    Date modified:  "01/04/2024"

*/

// Libraries included:
#include "initialize.h"
#include "typedefinitions.h"
#include "cleanup.h"


/*....................................................................................................*/
/* Global functions: */
/*-------------------*/

// Get program root directory path:
char* _getProgramRootDirectoryPath(char* argv)
{
    // "Path\\To\\File\\Root\\Directory\\Pac-Man CMD\\bin\\Pac-Man CMD.exe" 
    // "                                              <-------------------"

    // Calculating output length:
    int outputLen = strlen(argv) - 18;

    // Declaring output string and allocating memory:
    char* outputString = (char*) malloc(outputLen);

    // Filling output string:
    for (int i = 0; i < outputLen - 1; i++)
    {
        outputString[i] = argv[i];
        outputString[i + 1] = '\0';
    }

    // Returning output string:
    return outputString;
}

// Create path to file:
char* _createPathToFile(char* programRootDirectoryPath, char* filePathFromRoot)
{
    // Ex.:
    // "Pac-Man CMD\\--------------------"
    // "------------>config\\settings.txt"
    
    // Calculating output length:
    int outputLen = strlen(programRootDirectoryPath) + strlen(filePathFromRoot) + 1;

    // Declaring output string and allocating memory:
    char* outputString = (char*) malloc(outputLen);

    // Copying program root deirectoy path to output string:
    strcpy(outputString, programRootDirectoryPath);

    // Adding file path to output string:
    strcat(outputString, filePathFromRoot);

    // Returning output string:
    return outputString;
}


/*....................................................................................................*/
/* Program Settings functions: */
/*-----------------------------*/

// Get control layout:
NO_ERROR_CODE getControlLayout(char* settingsFilePath, char* controlLayout, char* controlLayoutBuffer)
{
    // Trying to open settings file:
    FILE* inputFile = fopen(settingsFilePath, "r");

    // If opening fail:
    if (inputFile == NULL)
    {
        // Freeing the local allocated memory:
        free(settingsFilePath);

        // Creating an imposible setting:
        controlLayout[0] = 'x';
        controlLayoutBuffer[0] = 'Y';
        
        // Returning:
        return;
    }

    // Creating a reader line:
    char line[LINE_LENGTH];

    // Creating a support counter for searching:
    int contCounter = 48;

    // Reading out the data:
    while (fgets(line, LINE_LENGTH, inputFile) != NULL)
    {
        // Search for specific characters:
        if (line[0] == contCounter && line[1] == 58)
        
        // Once found:
        {
            // Transforming char to integer: 
            int x = contCounter - 48;

            // Setting the buttons:
            controlLayout[x] = controlLayoutBuffer[x] = line[3];

            // Incrementing the support counter:
            contCounter++;
        }
    }

    // Freeing the local allocated memory:
    free(settingsFilePath);

    // Closeing input file:
    fclose(inputFile);
}

// Load settings:
settings loadSettings(char* argv)
{
    // Declaring settings:
    settings outputSettings;
    
    // Setting 'settings under change' to false:
    outputSettings.underChange = false;

    // Getting program root directory:
    outputSettings.programRootDirectoryPath = _getProgramRootDirectoryPath(argv);

    // Getting settings file path:
    getControlLayout(_createPathToFile(outputSettings.programRootDirectoryPath, "config\\settings.txt"), outputSettings.controlLayout, outputSettings.controlLayoutBuffer);
    
    // Returning output settings:
    return outputSettings;
}

// Program settings load success checker:
ERROR_CODE settingsLoadSuccesChecker(_settings pSettings)
{
    // Checkig that the settings are 'corrupt':
    if (pSettings->controlLayout[0] == 'x' && pSettings->controlLayoutBuffer[0] == 'Y')
    
    // If the settings are corrupt:
    // Returning the error code:
    return 101;

    // Else:
    // Returning the success status:
    return SUCCESS;
}


/*....................................................................................................*/
/* Program Windows functions: */
/*----------------------------*/

// Get logo:
NO_ERROR_CODE getLogo(char* logoFilePath, int logo[LOGO_HEIGHT][LOGO_WIDTH])
{
    // Trying to open logo file:
    FILE* inputFile = fopen(logoFilePath, "r");

    // If opening fail:
    if (inputFile == NULL)
    {
        // Freeing the local allocated memory:
        free(logoFilePath);

        // Creating an imposible setting:
        logo[0][0] = -1;
        
        // Returning:
        return;
    }

    // Creating a reader line:
    char line[LINE_LENGTH];

    // Navigating on 'Y' axis:
    for (int y = 0; y < LOGO_HEIGHT; y++)
    {
        // Reading out the data:
        fgets(line, LINE_LENGTH, inputFile);

        // Navigating on 'X' axis:
        for (int x = 0; x < LOGO_WIDTH; x++)
        {
            switch (line[x])
            {
            // █
            case 49:
                logo[y][x] = 219;
                break;
            
            // ▄
            case 50:
                logo[y][x] = 220;
                break;

            // ▀
            case 51:
                logo[y][x] = 223;
                break;

            // ■
            case 52:
                logo[y][x] = 254;
                break;

            // ·
            case 53:
                logo[y][x] = 250;
                break;

            // ' '
            default:
                logo[y][x] = 32;
            }
        }
    }

    // Closeing input file:
    fclose(inputFile);

    // Freeing the allocated memory:
    free(logoFilePath);
}

// Load windows:
windows loadWindows(char* programRootDirectoryPath)
{
    // Declaring windows:
    windows outputWindows;

    // Setting window and menu function number to 1:
    outputWindows.windowNumber = outputWindows.menuFunctionNumber = 1;

    // Setting an unacceptable window size:
    outputWindows.windowSizes.previousWindowSize.X = -1;

    // Getting logo file path:
    getLogo(_createPathToFile(programRootDirectoryPath, "assets\\logo\\logo.txt"), outputWindows.logo);

    // Returning output settings:
    return outputWindows;
}

// Program windows load success checker:
ERROR_CODE windowsLoadSuccesChecker(_windows pWindows)
{
    // Checkig that the windows are 'corrupt':
    if (pWindows->logo[0][0] == -1)
    
    // If the windows are corrupt:
    // Returning the error code:
    return 102;
        
    // Else:
    // Returning the success status:
    return SUCCESS;
}


/*....................................................................................................*/
/* Game session functions: */
/*-------------------------*/

// Set timer datas:
NO_ERROR_CODE setTimerDatas(_session_timers globalTimerDatas)
{
    // Setting performance frequency:
    QueryPerformanceFrequency(&globalTimerDatas->frequency);
}

// Set default location:
POSITION setDefaultLocation(int X, int Y)
{
    // Declaring output position:
    POSITION outputPosition;

    // Setting axis 'X':
    outputPosition.X = X;

    // Setting axis 'Y':
    outputPosition.Y = Y;

    // Returning output position:
    return outputPosition;
}

// Set player datas:
NO_ERROR_CODE setPlayerDatas(_player_datas playerDatas)
{
    // Setting player body:
    playerDatas->body = PLAYER_BODY;

    // Setting player color:
    playerDatas->color = YELLOW_F;

    // Setting player default direction:
    playerDatas->direction = playerDatas->nextDirection = 'L';

    // Setting player deafult location:
    playerDatas->position = setDefaultLocation(28, 23);

    // Setting player default lives:
    playerDatas->lives = 3;

    // Initialize player movement timer:
    QueryPerformanceCounter(&playerDatas->movementTimer);
}

// Set enemy default direction:
char setEnemyDefaultDirection(int enemyNumber)
{
    // Declaring output direction:
    char outputDirection;

    // Choosing direction by enemy number:
    switch (enemyNumber)
    {
    // Right:
    case 0:
        outputDirection = 'R';
        break;

    // Down:
    case 2:
        outputDirection = 'D';
        break;

    // Up:
    default:
        outputDirection = 'U';
    }

    // Returning output direction:
    return outputDirection;
}

// Set enemy default color:
COLOR setEnemyDefaultColor(int enemyNumber)
{
    // Declaring output color:
    COLOR outputColor;

    // Choosing color by enemy number:
    switch (enemyNumber)
    {
    // Red:
    case 0:
        outputColor = LIGHT_RED_F;
        break;
    
    // Green:
    case 1:
        outputColor = LIGHT_GREEN_F;
        break;
    
    // Sea blue:
    case 2:
        outputColor = LIGHT_SEA_BLUE_F;
        break;
    
    // Purple:
    case 3:
        outputColor = LIGHT_PURPLE_F;
    }

    // Returning output color:
    return outputColor;
}

// Set enemy default location:
POSITION setEnemyDefaultPosition(int enemyNumber)
{
    // Declaring output position:
    POSITION outputPosition;

    // Choosing position by enemy number:
    switch (enemyNumber)
    {
    // X:29 Y:12:
    case 0:
        outputPosition = setDefaultLocation(29, 12);
        break;
    
    // X:25 Y:15:
    case 1:
        outputPosition = setDefaultLocation(25, 15);
        break;
    
    // X:28 Y:15:
    case 2:
        outputPosition = setDefaultLocation(28, 15);
        break;
    
    // X:31 Y:15:
    case 3:
        outputPosition = setDefaultLocation(31, 15);
    }

    // Returning output position:
    return outputPosition;
}

// Create default enemy characteristic:
enemy_characteristic createDefaultEnemyCharacteristic(int enemyNumber)
{
    // Creating output enemy characteristic:
    enemy_characteristic outputEnemyCharacteristic;

    // Setting enemy ID:
    outputEnemyCharacteristic.enemyID = enemyNumber;

    // Setting enemy body:
    outputEnemyCharacteristic.body = ENEMY_BODY;

    // Setting enemy default direction:
    outputEnemyCharacteristic.direction = outputEnemyCharacteristic.nextDirection = setEnemyDefaultDirection(enemyNumber);

    // Setting enemy default color:
    outputEnemyCharacteristic.color = setEnemyDefaultColor(enemyNumber);

    // Setting enemy default position:
    outputEnemyCharacteristic.position = setEnemyDefaultPosition(enemyNumber);

    // Setting enemy movement timer:
    QueryPerformanceCounter(&outputEnemyCharacteristic.movementTimer);

    // Returning output enemy characteristic:
    return outputEnemyCharacteristic;
}

// Create enemy list:
_enemy_list_item createEnemyList(void)
{
    // Creating the head of the list :
    _enemy_list_item enemyListHead = (_enemy_list_item)malloc(sizeof(enemy_list_item));

    // Setting a helper pointer:
    _enemy_list_item thirdHand = enemyListHead;

    // Creating default enemy characteristic:
    thirdHand->characteristic = createDefaultEnemyCharacteristic(0);

    // Creating the list:
    for (int i = 1; i < 4; i++)
    {
        // Creating the next list item:
        thirdHand->next = (_enemy_list_item)malloc(sizeof(enemy_list_item));

        // Switching to the next item in the list:
        thirdHand = thirdHand->next;

        // Creating default enemy characteristic:
        thirdHand->characteristic = createDefaultEnemyCharacteristic(i);
    }

    // Closeing the list with NULL pointer:
    thirdHand->next = NULL;

    // Returning enemy list head:
    return enemyListHead;
}

// Set enemy datas:
NO_ERROR_CODE setEnemyDatas(_enemy_datas enemyDatas)
{
    // Setting enemy eateable to false:
    enemyDatas->enemyEatable = false;

    // Setting enemy default behavior to neutral:
    enemyDatas->enemyBehavior = neutral;

    // Creating enemy list:
    enemyDatas->enemyListHead = createEnemyList();
}

// Get high score:
NO_ERROR_CODE getHighScore(char* highScoreFilePath, long long unsigned* highScore)
{
    // Trying to open settings file:
    FILE* inputFile = fopen(highScoreFilePath, "r");

    // If opening fail:
    if (inputFile == NULL)
    {
        // Freeing the local allocated memory:
        free(highScoreFilePath);

        // Creating an imposible setting:
        *highScore = 1;
        
        // Returning:
        return;
    }

    // Creating a reader line:
    char line[LINE_LENGTH];

    // Reading out the data:
    fgets(line, LINE_LENGTH, inputFile);
    
    // Setting high score:
    *highScore = atoll(line);

    // Closeing input file:
    fclose(inputFile);

    // Freeing the local allocated memory:
    free(highScoreFilePath);

    // Returning:
    return;
}

// Get visible layer:
NO_ERROR_CODE getVisibleLayer(MAP map[GAME_MAP_LAYER_NUMBER][GAME_MAP_HEIGHT][GAME_MAP_WIDTH], char* line, mode modeSwitch, int Y, int X)
{
    // Decoding file to extended ASCII:
    switch (line[X])
    {
    // ╔:
    case 'a':
        map[modeSwitch][Y][X] = 201;
        break;

    // ═:
    case 'b':
        map[modeSwitch][Y][X] = 205;
        break;

    // ╗:
    case 'c':
        map[modeSwitch][Y][X] = 187;
        break;

    // ╚:
    case 'd':
        map[modeSwitch][Y][X] = 200;
        break;

    // ╝:
    case 'e':
        map[modeSwitch][Y][X] = 188;
        break;

    // ║:
    case 'f':
        map[modeSwitch][Y][X] = 186;
        break;

    // ╤:
    case 'g':
        map[modeSwitch][Y][X] = 209;
        break;

    // ╢:
    case 'h':
        map[modeSwitch][Y][X] = 182;
        break;

    // ╟:
    case 'i':
        map[modeSwitch][Y][X] = 199;
        break;

    // ┌:
    case '1':
        map[modeSwitch][Y][X] = 218;
        break;

    // ─:
    case '2':
        map[modeSwitch][Y][X] = 196;
        break;

    // ┐:
    case '3':
        map[modeSwitch][Y][X] = 191;
        break;

    // ┘:
    case '4':
        map[modeSwitch][Y][X] = 217;
        break;

    // └:
    case '5':
        map[modeSwitch][Y][X] = 192;
        break;

    // │:
    case '6':
        map[modeSwitch][Y][X] = 179;
        break;

    // ■:
    case '_':
        map[modeSwitch][Y][X] = 254;
        break;
    
    // ' '
    case 32:
        map[modeSwitch][Y][X] = 32;
    }
}

// Get collectibles layer:
NO_ERROR_CODE getCollectiblesLayer(MAP map[GAME_MAP_LAYER_NUMBER][GAME_MAP_HEIGHT][GAME_MAP_WIDTH], char* line, mode modeSwitch, int Y, int X)
{
    // Dedcoding file to simple numbers:
    switch (line[X])
    {
    // 1:
    case 'X':
        map[modeSwitch][Y][X] = 1;
        break;

    // 2:
    case 'B':
        map[modeSwitch][Y][X] = 2;
        break;

    // 0:
    case 32:
        map[modeSwitch][Y][X] = 0;
    }
}

// Get graph layer:
NO_ERROR_CODE getGraphLayer(MAP map[GAME_MAP_LAYER_NUMBER][GAME_MAP_HEIGHT][GAME_MAP_WIDTH], char* line, mode modeSwitch, int Y, int X)
{
    // Dedcoding file to simple numbers:
    switch (line[X])
    {
    // 1:
    case 'V':
        map[modeSwitch][Y][X] = 1;
        break;

    // 2:
    case 'x':
        map[modeSwitch][Y][X] = 2;
        break;

    // 0:
    case 32:
        map[modeSwitch][Y][X] = 0;
    }
}

// Fill row:
NO_ERROR_CODE fillRow(MAP map[GAME_MAP_LAYER_NUMBER][GAME_MAP_HEIGHT][GAME_MAP_WIDTH], char* line, mode modeSwitch, int Y)
{
    // Creating a variable function:
    _getChoosenLayer getChoosenLayer;
    
    switch (modeSwitch)
    {
        // Visible layer:
        case visible:

            // Getting visible layer:
            getChoosenLayer = getVisibleLayer;
            break;
        
        // Collectibles layer:
        case collectibles:

            // Getting collectibles layer:
            getChoosenLayer = getCollectiblesLayer;
            break;

        // Graph layer:
        case graph:

            // Getting graph layer:
            getChoosenLayer = getGraphLayer;
        }    

    // Navigation on 'X' axis:
    for (int X = 0; X < GAME_MAP_WIDTH; X++)
    {
        // Getting the choosen layer:
        getChoosenLayer(map, line, modeSwitch, Y, X);
    }
}

// Get map:
NO_ERROR_CODE getMap(char* mapFilePath, MAP map[GAME_MAP_LAYER_NUMBER][GAME_MAP_HEIGHT][GAME_MAP_WIDTH])
{
    // Trying to open settings file:
    FILE* inputFile = fopen(mapFilePath, "r");

    // If opening fail:
    if (inputFile == NULL)
    {
        // Freeing the local allocated memory:
        free(mapFilePath);

        // Creating an imposible setting:
        map[0][0][0] = -1;

        // Returning failure:
        return;
    }

    /* Navigation in the 3D array: */

    // Creating a reader line:
    char line[LINE_LENGTH];

    // Creating a mode switch:
    mode modeSwitch = visible;

    // Creating 'Y' axis:
    int Y = 0;
    
    // Reading out the data:
    while (fgets(line, LINE_LENGTH, inputFile) != NULL)
    {
        // Navigating on 'Z' axis with a mode switch:
        if (line[0] == ':' && line[1] == ':' && line[2] == ':') modeSwitch++, Y = 0;

        // Navigation on 'Y' axis:
        else if (line[0] != '/' && line[1] != '/')
        {
            // Filling each row:
            fillRow(map, line, modeSwitch, Y);
            
            // Incrementing 'Y':
            Y++;
        }
    }
    
    // Closeing input file:
    fclose(inputFile);

    // Freeing the local allocated memory:
    free(mapFilePath);

    // Returning success:
    return;
}

// Set game datas:
NO_ERROR_CODE setGameDatas(char* programRootDirectoryPath, _game_datas gameDatas)
{
    // Setting session score to 0:
    gameDatas->score = 0;

    // Getting global high score:
    getHighScore(_createPathToFile(programRootDirectoryPath, "config\\highscore.txt"), &gameDatas->highScore);

    // Getting map:
    getMap(_createPathToFile(programRootDirectoryPath, "assets\\map\\map.txt"), gameDatas->map);
}

// Load game session:
game_session loadGameSession(char* programRootDirectoryPath)
{
    // Declaring game session:
    game_session outputGameSession;

    // Setting timer datas:
    setTimerDatas(&outputGameSession.globalTimerDatas);

    // Setting player datas:
    setPlayerDatas(&outputGameSession.playerDatas);

    // Setting enemy datas:
    setEnemyDatas(&outputGameSession.enemyDatas);

    // Setting game datas:
    setGameDatas(programRootDirectoryPath, &outputGameSession.gameDatas);

    // Returning game session:
    return outputGameSession;
}

// Game session load success checker:
ERROR_CODE gameSessionLoadSuccesChecker(_game_session pGameSession)
{
    // Checkig high score file present:
    if (pGameSession->gameDatas.highScore == 1)
    
    // If high score file absent:
    // Returning the error code:
    return 103;

    // Checking map file present:
    if (pGameSession->gameDatas.map[0][0][0] == -1)

    // If map file absent:
    // Returning the error code:
    return 104;

    // Else:
    // Returning the success status:
    return SUCCESS;
}


/*....................................................................................................*/
/* Console functions: */
/*--------------------*/

// Hide cursor:
void hideCursor(void)
{
    // Declaring console cursor info:
    CONSOLE_CURSOR_INFO cursorInfo;

    // Setting cursor to invisible:
    cursorInfo.bVisible = false;

    // Applying (setting) cursor settings:
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

// Console setup:
void consoleSetup(void)
{
    // Setting console title to "Pac-Man CMD by MZoltan":
    SetConsoleTitle("Pac-Man CMD by MZoltan");

    // #debug mode:
    #ifndef __DEBUG
    // Hideing cursor:
    hideCursor();
    #endif
}


/*....................................................................................................*/
/* Initialization functions: */
/*---------------------------*/

// Initialization:
ERROR_CODE initialize(_program_data programData, char* argv)
{
    /* Settings: */

    // Loading settings:
    programData->settings = loadSettings(argv);

    // Checking that the settings are loaded:
    ERROR_CODE ERC = settingsLoadSuccesChecker(&programData->settings);
    
    // If the settings failed to load:
    if (ERC != SUCCESS)
    {
        // Freeing the golbal allocated memory:
        freeSettings(&programData->settings);       // 1

        // Returning the error code:
        return ERC;
    }


    /* Windows: */

    // Loading windows:
    programData->windows= loadWindows(programData->settings.programRootDirectoryPath);

    // Checking that the windows are loaded:
    ERC = windowsLoadSuccesChecker(&programData->windows);

    // If the windows failed to load:
    if (ERC != SUCCESS)
    {
        // Freeing the golbal allocated memory:
        freeSettings(&programData->settings);       // 1
        // (No need to free anything in windows)    // 2

        // Returning the error code:
        return ERC;
    }


    /* Game session: */

    // Loading game session:
    programData->gameSession = loadGameSession(programData->settings.programRootDirectoryPath);

    // Checking that the game session is loaded:
    ERC = gameSessionLoadSuccesChecker(&programData->gameSession);

    // If the game session failed to load:
    if (ERC != SUCCESS)
    {
        // Freeing the golbal allocated memory:
        freeSettings(&programData->settings);       // 1
        // (No need to free anything in windows)    // 2
        freeGameSession(&programData->gameSession); // 3

        // Returning the error code:
        return ERC;
    }

    /* Console: */

    // Setting up the console:
    consoleSetup();


    // Returning SUCCES:
    return SUCCESS;
}

// Display file missing error dialog:
void displayFileMissingErrorDialog(ERROR_CODE inputErrorCode)
{
    // Choosing the right code:
    switch (inputErrorCode)
    {
    // Settings.txt:
    case 101:
        MessageBox(NULL, "\'Settings.txt\' is missing!", "ERROR 101", MB_OK | MB_ICONERROR);
        return;

    // logo.txt
    case 102:
        MessageBox(NULL, "\'logo.txt\' is missing!", "ERROR 102", MB_OK | MB_ICONERROR);
        return;

    // highscore.txt
    case 103:
        MessageBox(NULL, "\'highscore.txt\' is missing!", "ERROR 103", MB_OK | MB_ICONERROR);
        return;
    
    // map.txt
    case 104:
        MessageBox(NULL, "\'map.txt\' is missing!", "ERROR 104", MB_OK | MB_ICONERROR);
        return;
    }
}