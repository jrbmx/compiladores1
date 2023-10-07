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
// Función para obtener el nombre literal del tipo de token
const char* nombreTipoToken(TokenType tipo) {
    switch (tipo) {
        case AND: return "AND";
        case ELSE: return "ELSE";
        case FALSE_TOKEN: return "FALSE";
        case FOR: return "FOR";
        case FUN: return "FUN";
        case IF: return "IF";
        case NULL_TOKEN: return "NULL";
        case OR: return "OR";
        case PRINT: return "PRINT";
        case RETURN: return "RETURN";
        case TRUE_TOKEN: return "TRUE";
        case VAR: return "VAR";
        case WHILE: return "WHILE";
        case IDENTIFICADOR: return "IDENTIFICADOR";
        case NUMERO_ENTERO: return "NUMERO_ENTERO";
        case NUMERO_DECIMAL: return "NUMERO_DECIMAL";
        case CADENA: return "CADENA";
        case SIMBOLO: return "SIMBOLO";
        case ERROR_FALTA_PUNTO_Y_COMA: return "ERROR_FALTA_PUNTO_Y_COMA";
        case ERROR_VARIABLE_DECLARADA: return "ERROR_VARIABLE_DECLARADA";
        case ERROR_PARENTESIS_NO_CERRADO: return "ERROR_PARENTESIS_NO_CERRADO";
        case ERROR_LLAVE_NO_CERRADA: return "ERROR_LLAVE_NO_CERRADA";
        case ERROR_DECLARACION_SIN_TIPO: return "ERROR_DECLARACION_SIN_TIPO";
        case ERROR_VARIABLE_NO_DECLARADA: return "ERROR_VARIABLE_NO_DECLARADA";
        case ERROR_DIVISION_POR_CERO: return "ERROR_DIVISION_POR_CERO";
        case ERROR_CADENA_SIN_CERRAR: return "ERROR_CADENA_SIN_CERRAR";
        case ERROR_CARACTER_NO_VALIDO: return "ERROR_CARACTER_NO_VALIDO";
        default: return "DESCONOCIDO";
    }
}
