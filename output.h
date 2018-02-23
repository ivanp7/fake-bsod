#ifndef OUTPUT_H
#define OUTPUT_H

// Platform-dependent functions

#include <ncurses.h>

void InitializeScreen()
{
  initscr();
  start_color();
}

void ClearScreen()
{
  clear();
}

void RefreshScreen()
{
  refresh();
}

void ReleaseScreen()
{
  endwin();
}

void HideCursor()
{
  curs_set(0);
}

void ShowCursor()
{
  curs_set(1);
}

void InitColorPair(int pairNo, int foregroundColor, int backgroundColor)
{
  init_pair(pairNo, foregroundColor, backgroundColor);
}

void SetWriteColorPair(int pairNo)
{
  attrset(COLOR_PAIR(pairNo));
}

void SetClearColorPair(int pairNo)
{
  bkgdset(COLOR_PAIR(pairNo));
}

int GetScreenSizeX()
{
  return getmaxx(stdscr);
}

int GetScreenSizeY()
{
  return getmaxy(stdscr);
}

void MoveCursorTo(int x, int y)
{
  move(y, x);
}

void WriteString(const char* str)
{
  printw(str);
}

#endif

