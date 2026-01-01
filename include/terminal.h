#ifndef TERMINAL_H
#define TERMINAL_H

////////////////////////////////////////////////////////////
// Terminal
//
// Add all tools used in terminal standards and other output
//
////////////////////////////////////////////////////////////

// Terminal COLORS
#define GREY "\033[30m"
#define YELLOW "\033[31m"
#define GREEN "\033[32m"
#define RED "\033[33m"
#define BLUE "\033[34m"
// #define ORANGE(content) "\033[31m content \033[0m"
#define RESET "\033[0m"

// Is a littel tools to color writting text in standard output
#define STR "%s" RESET
#define INT "%d" RESET

#define ERROR_ERN_LABEL "error errno[PROGRAM FAIL: CRITICAL]"
#define STANDARD_INP_LABEL "standard input[PROGRAM SUCESS: PASS]"
#define STANDARD_OUT_LABEL "standard output consol[PROGRAM SUCESS: PASS]"
#define ERROR_OUT_LABEL "error output[PROGRAM FAIL: WARNING]"

#endif