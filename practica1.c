//Compiladores 5CM2
//Ramirez Ruiz Alan Edwin
//Romero Barrientos Jonathan Ruben
//Sandoval Mandujano Samuel
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
// Estructura para tokens
typedef struct {
    TokenType tipo;
    char lexema[100];
    char literal[100];
} Token;

// Función para verificar si una cadena es una palabra reservada
TokenType tipoPalabraReservada(char *cadena) {
    if (strcmp(cadena, "and") == 0) return AND;
    if (strcmp(cadena, "else") == 0) return ELSE;
    if (strcmp(cadena, "false") == 0) return FALSE_TOKEN;
    if (strcmp(cadena, "for") == 0) return FOR;
    if (strcmp(cadena, "fun") == 0) return FUN;
    if (strcmp(cadena, "if") == 0) return IF;
    if (strcmp(cadena, "null") == 0) return NULL_TOKEN;
    if (strcmp(cadena, "or") == 0) return OR;
    if (strcmp(cadena, "print") == 0) return PRINT;
    if (strcmp(cadena, "return") == 0) return RETURN;
    if (strcmp(cadena, "true") == 0) return TRUE_TOKEN;
    if (strcmp(cadena, "var") == 0) return VAR;
    if (strcmp(cadena, "while") == 0) return WHILE;
    return IDENTIFICADOR;
}

// Función para manejar errores de declaración de tipo de variable
void errorDeclaracionSinTipo(Token t) {
    printf("Error: Falta tipo en la declaración de variable '%s'\n", t.lexema);
}

// Función para manejar errores de uso de variables no declaradas
void errorVariableNoDeclarada(Token t) {
    printf("Error: Uso de variable no declarada '%s'\n", t.lexema);
}

// Función para manejar errores de división por cero
void errorDivisionPorCero() {
    printf("Error: División por cero\n");
}

// Función para manejar errores de uso incorrecto de comillas en cadenas
void errorCadenaSinCerrar(Token t) {
    printf("Error: Cadena no cerrada en '%s'\n", t.lexema);
}

// Función para manejar errores de caracteres no válidos
void errorCaracterNoValido(Token t) {
    printf("Error: Caracter no válido en '%s'\n", t.lexema);
}
// Función principal para analizar el código fuente y generar tokens
void analizarCodigo(char *codigo) {
    // Inicializar variables para seguimiento de errores
    bool faltaPuntoYComa = false;
    bool declaraciones[100]; // Usamos un arreglo booleano para llevar un registro de declaraciones
    int parentesisAbiertos = 0;
    int llavesAbiertas = 0;
    
    for (int i = 0; i < 100; i++) {
        declaraciones[i] = false;
    }
    
    char *token = codigo;
    
    while (*token != '\0') {
        Token t;
        char lexema[100];
        char literal[100];
        int i = 0;
        
        // Ignorar espacios en blanco
while (*token != '\0' && isspace(*token)) {
    token++;
}

// Identificar comentarios de una sola línea
if (*token == '/' && *(token + 1) == '/') {
    // Saltar hasta el final de la línea
    while (*token != '\0' && *token != '\n') {
        token++;
    }
    continue;
}

// Identificar comentarios multilineales
if (*token == '/' && *(token + 1) == '*') {
    // Saltar los caracteres '/*'
    token += 2;
    // Buscar el cierre de comentario '*/'
    while (*token != '\0' && !(*token == '*' && *(token + 1) == '/')) {
        token++;
    }
    if (*token == '\0') {
        // Error: Comentario multilineal sin cerrar
        printf("Error: Comentario multilineal sin cerrar.\n");
        break;
    }
    // Saltar los caracteres '*/'
    token += 2;
    continue;
}
// Identificar tokens
        if (isalpha(*token) || *token == '_') {
            // Identificador o palabra reservada
            while (*token != '\0' && (isalnum(*token) || *token == '_')) {
                lexema[i++] = *token;
                token++;
            }
            lexema[i] = '\0';
            
            TokenType tipoToken = tipoPalabraReservada(lexema);
            if (tipoToken != IDENTIFICADOR) {
                t.tipo = tipoToken;
                strcpy(t.lexema, lexema);
            } else {
                t.tipo = IDENTIFICADOR;
                strcpy(t.lexema, lexema);
            }
        } else if (isdigit(*token) || (*token == '-' && isdigit(*(token + 1)))) {
            // Número entero o decimal
            bool decimal = false;
            bool exponente = false;
            while (*token != '\0' && (isdigit(*token) || *token == '.' || *token == 'e' || *token == 'E' || (*token == '-' && exponente))) {
                if (*token == '.') {
                    decimal = true;
                }
                if (*token == 'e' || *token == 'E') {
                    exponente = true;
                }
                lexema[i++] = *token;
                token++;
            }
            lexema[i] = '\0';
            
            if (decimal || exponente) {
                t.tipo = NUMERO_DECIMAL;
                strcpy(t.lexema, lexema);
            } else {
                t.tipo = NUMERO_ENTERO;
                strcpy(t.lexema, lexema);
            }
        } else if (*token == '"' || *token == '\'') {
            // Cadena
            char delim = *token;
            token++; // Saltar el delimitador inicial
            while (*token != '\0' && *token != delim) {
                if (*token == '\\') {
                    // Escapar caracteres
                    token++;
                }
                lexema[i++] = *token;
                token++;
            }
            if (*token == delim) {
                token++; // Saltar el delimitador final
                lexema[i] = '\0';
                t.tipo = CADENA;
                strcpy(t.lexema, lexema);
            } else {
                // Cadena sin cerrar
                t.tipo = ERROR_CADENA_SIN_CERRAR;
                strcpy(t.lexema, lexema);
            }
        } else {
            // Símbolo
            lexema[i++] = *token;
            token++;
            lexema[i] = '\0';
            t.tipo = SIMBOLO;
            strcpy(t.lexema, lexema);
            
            // Verificar paréntesis y llaves
            if (lexema[0] == '(') {
                parentesisAbiertos++;
            } else if (lexema[0] == ')') {
                parentesisAbiertos--;
                if (parentesisAbiertos < 0) {
                    t.tipo = ERROR_PARENTESIS_NO_CERRADO;
                }
            } else if (lexema[0] == '{') {
                llavesAbiertas++;
            } else if (lexema[0] == '}') {
                llavesAbiertas--;
                if (llavesAbiertas < 0) {
                    t.tipo = ERROR_LLAVE_NO_CERRADA;
                }
            }
        }
// Imprimir token y manejar errores
        //printf("<%s \"%s\" %s>\n", nombreTipoToken(t.tipo), t.lexema, t.literal);
        printf("<%s \"%s\" %s>\n", nombreTipoToken(t.tipo), t.lexema, (t.tipo == NUMERO_ENTERO || t.tipo == NUMERO_DECIMAL) ? t.lexema : "NULL");

        // Llamar a funciones de manejo de errores específicos
        if (t.tipo == ERROR_FALTA_PUNTO_Y_COMA) {
            printf("Error: Falta punto y coma al final de una declaración.\n");
        }
        
        if (t.tipo == ERROR_VARIABLE_DECLARADA) {
            printf("Error: Variable '%s' ya declarada.\n", t.lexema);
        }
        
        if (t.tipo == ERROR_VARIABLE_NO_DECLARADA) {
            printf("Error: Uso de variable no declarada '%s'.\n", t.lexema);
        }
        
        if (t.tipo == ERROR_DIVISION_POR_CERO) {
            printf("Error: División por cero.\n");
        }
        
        if (t.tipo == ERROR_CADENA_SIN_CERRAR) {
            printf("Error: Cadena no cerrada en '%s'.\n", t.lexema);
        }
        
        if (t.tipo == ERROR_CARACTER_NO_VALIDO) {
            printf("Error: Caracter no válido en '%s'.\n", t.lexema);
        }
    }
    
    // Verificar errores
    if (faltaPuntoYComa) {
        printf("Error: Falta punto y coma al final de una declaración.\n");
    }
    
    if (parentesisAbiertos > 0) {
        printf("Error: Falta cerrar %d paréntesis.\n", parentesisAbiertos);
    } else if (parentesisAbiertos < 0) {
        printf("Error: Paréntesis no cerrado.\n");
    }
    
    if (llavesAbiertas > 0) {
        printf("Error: Falta cerrar %d llaves.\n", llavesAbiertas);
    } else if (llavesAbiertas < 0) {
        printf("Error: Llave no cerrada.\n");
    }
}
