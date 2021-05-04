#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

float CriaAleatorio();

void Clean();

int VerificaEntre(const char* x, int bottom, int up);

int VerificaNum(const char *x);
#endif //UTILIDADES_H
