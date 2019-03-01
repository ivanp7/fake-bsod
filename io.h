#pragma once

// Platform-dependent functions

#define COLOR_BLACK   0
#define COLOR_RED     1
#define COLOR_GREEN   2
#define COLOR_YELLOW  3
#define COLOR_BLUE    4
#define COLOR_MAGENTA 5
#define COLOR_CYAN    6
#define COLOR_WHITE   7

void InitializeScreen();
void ClearScreen();
void RefreshScreen();
void ReleaseScreen();
void HideCursor();
void ShowCursor();
void InitColorPair(int pairNo, int foregroundColor, int backgroundColor);
void SetWriteColorPair(int pairNo);
void SetClearColorPair(int pairNo);
int GetScreenSizeX();
int GetScreenSizeY();
void MoveCursorTo(int x, int y);
void WriteString(const char* str);
int WaitForKey();

