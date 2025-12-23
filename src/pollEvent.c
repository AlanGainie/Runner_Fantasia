#include "../include/my.h"

// TODO: Mettre à jour tous les doxygène
/**
 * @date ✅ 16 september 2025 at 00:00
 * @author Alan Gainié
 * -----------------------------------
 * @brief This function set all effect used when the keyboard is used
 * @param event is a CSFML tool for capte all interaction in game
 * @param structWindow is a global struct of window
 * @return int (a status of function)
 */
int initEventKeyPressed(sfEvent event, window_t *structWindow)
{
    if (event.type == sfEvtKeyPressed)
    {
        keyEventRight(event, &structWindow->scenes[CHARGING], sfKeyD);
        keyEventLeft(event, &structWindow->scenes[CHARGING], sfKeyA);
        keyEventTop(event, &structWindow->scenes[CHARGING], sfKeyZ);
        keyEventDown(event, &structWindow->scenes[CHARGING], sfKeyS);
        keyEventScenes(event, structWindow, sfKeyP);
    }

    return 0;
}

/**
 * @date ✅ 16 september 2025 at 00:00
 * @author Alan Gainié
 * -----------------------------------
 * @brief This function contain all event to use in game
 * @param structWindow is a global struct of window
 * @result This function have : structWindow parameter with a pointer of function return
 * @return int (a status of function)
 */
int pollEvent(window_t *structWindow)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(structWindow->window, &event))
    {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(structWindow->window);
        initEventKeyPressed(event, structWindow);
    }
    return 0;
}