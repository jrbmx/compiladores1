//Ramirez Ruiz Alan Edwin
//Romero Barrientos Jonathan Ruben
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Enumeración para tipos de token
typedef enum {
    AND, ELSE, FALSE_TOKEN, FOR, FUN, IF, NULL_TOKEN, OR, PRINT, RETURN, TRUE_TOKEN, VAR, WHILE,
    IDENTIFICADOR, NUMERO_ENTERO, NUMERO_DECIMAL, CADENA, SIMBOLO, ERROR_FALTA_PUNTO_Y_COMA,
    ERROR_VARIABLE_DECLARADA, ERROR_PARENTESIS_NO_CERRADO, ERROR_LLAVE_NO_CERRADA,
    ERROR_DECLARACION_SIN_TIPO, ERROR_VARIABLE_NO_DECLARADA,
    ERROR_DIVISION_POR_CERO, ERROR_CADENA_SIN_CERRAR, ERROR_CARACTER_NO_VALIDO
} TokenType;

//prueba para github
