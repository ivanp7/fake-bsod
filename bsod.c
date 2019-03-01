#include "bsod.h"

#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "io.h"

void GenerateRandomString(const char *baseString, char *destString, size_t len)
{
    size_t baseLength = strlen(baseString);
    if (baseLength == 0)
        len = 0;

    for(int i = 0; i < len; i++)
        destString[i] = baseString[rand() % baseLength];
}

int DrawBSoD(const char *title)
{
    const size_t textWidth = 66;
    const size_t textHeight = 10;

    size_t screenSizeX = GetScreenSizeX(),
        screenSizeY = GetScreenSizeY();

    if ((screenSizeX < textWidth) || (screenSizeY < textHeight))
        return 1;

    size_t titleLength = strlen(title);
    if (titleLength > screenSizeX - 4)
        titleLength = screenSizeX - 4;
    
    {
        char *cutTitle = (char*)malloc(titleLength + 1);
        cutTitle[titleLength] = '\0';
        strncpy(cutTitle, title, titleLength + 1);
        title = cutTitle;
    }

    size_t titleShift = (screenSizeX - titleLength - 2) / 2;

    char errorNumber1[3]; errorNumber1[2] = '\0';
    char errorNumber2[5]; errorNumber2[4] = '\0';
    char errorNumber3[9]; errorNumber3[8] = '\0';
    char errorNumber4[3]; errorNumber4[2] = '\0';
    char errorNumber5[9]; errorNumber5[8] = '\0';

    const char *A = "0123456789ABCDEF";

    srand(time(NULL));
    GenerateRandomString(A, errorNumber1, 2);
    errorNumber2[0] = errorNumber2[1] = '0';
    GenerateRandomString(A, errorNumber2 + 2, 2);
    GenerateRandomString(A, errorNumber3, 8);
    errorNumber4[0] = '0';
    GenerateRandomString(A, errorNumber4 + 1, 1);
    GenerateRandomString(A, errorNumber5, 8);

    char reason1[67]; reason1[0] = reason1[66] = '\0';
    char reason2[54]; reason2[0] = reason2[53] = '\0';

    strcat(reason1, "A fatal exception ");
    strcat(reason1, errorNumber1);
    strcat(reason1, " has occured at ");
    strcat(reason1, errorNumber2);
    strcat(reason1, ":");
    strcat(reason1, errorNumber3);
    strcat(reason1, " in VXD VMM(");
    strcat(reason1, errorNumber4);
    strcat(reason1, ") +");

    strcat(reason2, errorNumber5);
    strcat(reason2, ". The current application will be terminated.");

    size_t reasonShift = (screenSizeX - 66) / 2;

    //******************************************//

    const char *message1 = "* Press any key to terminate current application.";
    const char *message2 = "* Press CTRL+ALT+DEL again to restart your computer. You will";
    const char *message3 = "  lose any unsaved information in all applications.";

    //******************************************//

    const char *prompt = "Press any key to continue";
    size_t promptLength = strlen(prompt);
    size_t promptShift = (screenSizeX - promptLength) / 2;

    //******************************************//

    InitColorPair(1, COLOR_WHITE, COLOR_BLUE);
    InitColorPair(2, COLOR_BLUE, COLOR_WHITE);
    SetClearColorPair(1);
    ClearScreen();

    size_t posX, posY;

    posX = titleShift;
    posY = (screenSizeY - textHeight) / 2;

    SetWriteColorPair(2);
    MoveCursorTo(posX, posY);
    WriteString(" ");
    MoveCursorTo(posX + 1, posY);
    WriteString(title);
    MoveCursorTo(posX + 1 + titleLength, posY);
    WriteString(" ");

    posX = reasonShift;
    posY += 2;
    MoveCursorTo(posX, posY);
    SetWriteColorPair(1);
    WriteString(reason1);

    posY++;
    MoveCursorTo(posX, posY);
    WriteString(reason2);

    posY += 2;
    MoveCursorTo(posX, posY);
    WriteString(message1);

    posY++;
    MoveCursorTo(posX, posY);
    WriteString(message2);

    posY++;
    MoveCursorTo(posX, posY);
    WriteString(message3);

    posY += 2;
    posX = promptShift;
    MoveCursorTo(posX, posY);
    WriteString(prompt);

    posX += promptLength + 1;
    MoveCursorTo(posX, posY);

    RefreshScreen();
    WaitForKey();

    free((void*)title);

    return 0;
}

