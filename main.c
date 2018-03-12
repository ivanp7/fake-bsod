#include "io.h"
#include "bsod.h"

int main(int argc, char *argv[])
{
  InitializeScreen();

  const char *title = (argc > 1)? argv[1]: "Windows";
  int result = DrawBSoD(title);

  ReleaseScreen();

  return result;
}
