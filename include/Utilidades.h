#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * @brief Funcao para retornar um float aleatorio
 * @return Float aleatorio
 */
float CriaAleatorio();

/**
 * @brief Funcao para limpar o terminal
 */
void Clean();
/**
 * @brief Funcao para verificar se um char* esta entre dois int
 * @param char* x string que sera comparada
 * @param int bottom limite inferior
 * @param int up limite superior
 * @return retorna x convertido para int caso esteja entre bottom e up e 0 caso contrario
 */
int VerificaEntre(const char* x, int bottom, int up);
/**
 * @brief Funcao para verificar caso uma string seja um digito
 * @param char *x string que sera verificada
 * @return 0 caso a string nao seja composta apenas de digitos e 1 caso contrario
 */
int VerificaNum(const char *x);
#endif //UTILIDADES_H
