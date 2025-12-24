#include "../include/my.h"

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

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

/**
 * @brief
 *
 * @param content_to_justified
 * @param global_content
 * @return char*
 */
char *justified_content(char *content_to_justified, char *global_content)
{
    char *content_justified = malloc(sizeof(char) * (strlen(global_content + 1) + 1));
    (void)content_justified;
    (void)content_to_justified;

    return 0;
}

/**
 * @brief
 *
 * @param content
 * @param input_status
 * @return char*
 */
char *endlog(char *content, char *input_status)
{
    char *content_end = malloc(sizeof(char) * (strlen(content + 1) + 1));
    char *input_status_end = malloc(sizeof(char) * (strlen(input_status + 1) + 1));

    content_end[strlen(content) + 1] = '\0';
    for (int counter = 0; content[counter] != '\0'; counter++)
        content_end[counter] = '-';
    printf("| %s |", content_end);
    input_status_end[strlen(input_status) + 1] = '\0';
    for (int counter = 0; input_status[counter] != '\0'; counter++)
        input_status_end[counter] = '-';
    printf(" %s |\n", input_status_end);
    return 0;
}

// TODO: Set le type de sortie, standard, erreur etc.. Et mettre en place le path local du log
/**
 * @brief
 *
 * @param content
 * @param status
 * @param located
 * @return int
 */
int log_message(char *content, int status, void *located)
{
    static int start_status = 0;

    (void)located;
    if (start_status == 0)
    {
        endlog(content, "0: standard input[PROGRAM SUCESS: PASS]");
        start_status++;
    }
    if (content)
    {
        printf("| ");
        switch (status)
        {
        case -1:
            printf(RED STR " | " RED INT ": " ERROR_ERN_LABEL, content, status);
            break;
        case 0:
            printf(GREEN STR " | " GREY INT ": " STANDARD_INP_LABEL, content, status);
            break;
        case 1:
            printf(BLUE STR " | " BLUE INT ": " STANDARD_OUT_LABEL, content, status);
            break;
        case 2:
            printf(YELLOW STR " | " YELLOW INT ": " ERROR_OUT_LABEL, content, status);
            break;
        default:
            printf(content);
            break;
        }
        printf(" |\n");
    }
    else
    {
        return 84;
    }
    return 0;
}

void segfaultlog(int sig)
{
    (void)sig;
    log_message("💥 Segfault détecté (signal sig)", -1, NULL);
    endlog("💥 Segfault détecté (signal sig)", "0: standard input[PROGRAM SUCESS: PASS]");
    exit(84);
}