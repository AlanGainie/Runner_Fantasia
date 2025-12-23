#include "../include/my.h"

#define BLUE(content) "\034[31m content \033[0m"
#define GREEN(content) "\032[31m content \033[0m"
#define YELLOW(content) "\031[31m content \033[0m"
// #define ORANGE(content) "\033[31m content \033[0m"
#define RED(content) "\033[31m content \033[0m"
#define GREY(content) "\030[31m content \033[0m"

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

char *justified_content(char *content_to_justified, char *global_content)
{
    char *content_justified = malloc(sizeof(char) * (strlen(global_content + 1) + 1));
    (void)content_justified;

    return 0;
}

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
            printf("\033[31m%s\033[0m", content);
            printf(" | \033[31m%d\033[0m:\033[30m error errno[PROGRAM FAIL: CRITICAL]\033[0m", status);
            break;
        case 0:
            printf("\033[32m%s\033[0m", content);
            printf(" | \033[32m%d\033[0m:\033[30m standard input[PROGRAM SUCESS: PASS]\033[0m", status);
            break;
        case 1:
            printf("\033[34m%s\033[0m", content);
            printf(" | \033[34m%d\033[0m:\033[30m standard output consol[PROGRAM SUCESS: PASS]\033[0m", status);
            break;
        case 2:
            printf("\033[33m%s\033[0m", content);
            printf(" | \033[33m%d\033[0m:\033[30m error output[PROGRAM FAIL: WARNING]\033[0m", status);
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
    log_message("💥 Segfault détecté (signal sig)", -1, NULL);
    endlog("💥 Segfault détecté (signal sig)", "0: standard input[PROGRAM SUCESS: PASS]");
    exit(84);
}