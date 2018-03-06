#ifndef BSOD_H
#define BSOD_H

#include "stddef.h"

void GenerateRandomString(const char *baseString, char *destString, size_t len);
int DrawBSoD(const char *title);

#endif

