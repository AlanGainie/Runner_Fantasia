#include "../include/my.h"

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

/**
 * @brief Prépare une chaîne justifiée pour l’affichage des logs.
 *
 * Fonction utilitaire destinée à formater un contenu en fonction
 * d’un texte de référence (implémentation en cours).
 *
 * @param content_to_justified Texte à justifier.
 * @param global_content Texte de référence pour la justification.
 * @return Chaîne allouée dynamiquement ou NULL.
 */
char *justified_content(char *content_to_justified, char *global_content)
{
    char *content_justified = malloc(sizeof(char) * (strlen(global_content + 1) + 1));
    (void)content_justified;
    (void)content_to_justified;

    return 0;
}

/**
 * @brief Affiche une ligne de séparation pour les logs.
 *
 * Génère et affiche deux lignes de tirets correspondant à la
 * longueur des colonnes du message de log.
 *
 * @param content Texte principal du log.
 * @param input_status Texte représentant l’état du log.
 */
void endlog(const char *content, const char *input_status)
{
    size_t len1 = strlen(content);
    size_t len2 = strlen(input_status);

    char *content_end = malloc(len1 + 1);
    char *input_status_end = malloc(len2 + 1);

    if (!content_end || !input_status_end)
        return;

    memset(content_end, '-', len1);
    content_end[len1] = '\0';

    memset(input_status_end, '-', len2);
    input_status_end[len2] = '\0';

    printf("| %s | %s |\n", content_end, input_status_end);

    free(content_end);
    free(input_status_end);
}

/**
 * @brief Affiche un message de log avec un niveau de gravité.
 *
 * Formate et affiche un message selon son type (succès,
 * information, avertissement ou erreur critique).
 *
 * @param content Message à afficher.
 * @param status Niveau du log (-1 à 2).
 * @param located Contexte réservé pour usage futur.
 * @return 0 en cas de succès, 84 si le contenu est invalide.
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

/**
 * @brief Gère les erreurs de segmentation (SIGSEGV).
 *
 * Affiche un message d’erreur critique puis termine
 * le programme proprement.
 *
 * @param sig Signal reçu.
 */
void segfaultlog(int sig)
{
    (void)sig;
    log_message("💥 Segfault détecté (signal sig)", -1, NULL);
    endlog("💥 Segfault détecté (signal sig)", "0: standard input[PROGRAM SUCESS: PASS]");
    exit(84);
}
