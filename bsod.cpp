#include <cstdlib>
#include <ctime>
#include <string>
using std::string;

#include "output.h"

int main(int argc, char *argv[])
{
  InitializeScreen();

  int screenSizeX = GetScreenSizeX(),
    screenSizeY = GetScreenSizeY();

  //******************************************//

  string errorCauser;

  if(argc == 1)
    errorCauser = "Windows";
  else
    errorCauser = argv[1];

  errorCauser = " " + errorCauser + " ";

  int errorCauserShift = (screenSizeX - errorCauser.length()) / 2;

  //******************************************//

  srand(time(NULL));
  char A[] = "0123456789ABCDEF";

  string errorRandomNumbers[5];

  for(int i = 0; i < 2; i++)
    errorRandomNumbers[0] += A[rand() % 16];

  for(int i = 0; i < 2; i++)
    errorRandomNumbers[1] += A[rand() % 16];
  errorRandomNumbers[1] = "00" + errorRandomNumbers[1];

  for(int i = 0; i < 8; i++)
    errorRandomNumbers[2] += A[rand() % 16];

  for(int i = 0; i < 1; i++)
    errorRandomNumbers[3] += A[rand() % 10];
  errorRandomNumbers[3] = "0" + errorRandomNumbers[3];

  for(int i = 0; i < 8; i++)
    errorRandomNumbers[4] += A[rand() % 16];

  string reason[2];
  reason[0] = "A fatal exception " + errorRandomNumbers[0] + " has occured at " +
    errorRandomNumbers[1] + ":" + errorRandomNumbers[2] + " in VXD VMM(" +
    errorRandomNumbers[3] + ") +";
  reason[1] = errorRandomNumbers[4] + ". The current application will be terminated.";

  int reasonShift = (screenSizeX - reason[0].length()) / 2;

  //******************************************//

  string message[3];
  message[0] = "* Press any key to terminate current application.";
  message[1] = "* Press CTRL+ALT+DEL again to restart your computer. You will";
  message[2] = "  lose any unsaved information in all applications.";

  //******************************************//

  string prompt = "Press any key to continue";

  int promptShift = (screenSizeX - prompt.length()) / 2;

  //******************************************//

  InitColorPair(1, COLOR_WHITE, COLOR_BLUE);
  InitColorPair(2, COLOR_BLUE, COLOR_WHITE);
  SetClearColorPair(1);
  ClearScreen();

  int posX, posY;

  posX = errorCauserShift;
  posY = (screenSizeY - 10) / 2;
  MoveCursorTo(posX, posY);

  SetWriteColorPair(2);
  WriteString(errorCauser.c_str());

  posX = reasonShift;
  posY += 2;
  MoveCursorTo(posX, posY);
  SetWriteColorPair(1);
  WriteString(reason[0].c_str());

  posY++;
  MoveCursorTo(posX, posY);
  WriteString(reason[1].c_str());

  posY += 2;
  MoveCursorTo(posX, posY);
  WriteString(message[0].c_str());

  posY++;
  MoveCursorTo(posX, posY);
  WriteString(message[1].c_str());

  posY++;
  MoveCursorTo(posX, posY);
  WriteString(message[2].c_str());

  posY += 2;
  posX = promptShift;
  MoveCursorTo(posX, posY);
  WriteString(prompt.c_str());

  posX += prompt.length() + 1;
  MoveCursorTo(posX, posY);

  RefreshScreen();
  getch();

  ReleaseScreen();

  return 0;
}
