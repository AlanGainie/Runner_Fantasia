#include "../include/my.h"

/**
 * @brief This function free memories used in malloc
 * @return int (a status of function)
 */
int freeMemories()
{
    return 0;
}

int destroy_scene(scene_t scene)
{
    freeMemories();

    if (scene.background.constructsprite)
    {
        sfTexture_destroy(scene.background.constructspritetexture);
        sfSprite_destroy(scene.background.constructsprite);
    }
    if (scene.sprites[SPRITE_BAT].constructsprite)
    {
        sfTexture_destroy(scene.sprites[SPRITE_BAT].constructspritetexture);
        sfSprite_destroy(scene.sprites[SPRITE_BAT].constructsprite);
    }
    return 0;
}

/**
 * @brief This function destroy element when is call. Is obligatory when you
 * kill the game
 * @param structWindow is a global struct of window
 * @return int (a status of function)
 */
int destroy(window_t structWindow)
{
    freeMemories();

    destroy_scene(structWindow.scenes[CHARGING]);

    sfRenderWindow_destroy(structWindow.window);
    return 0;
}

/**
 * @brief This function destroy all elements permanent used in structWindow
 * @param structWindow Is a struct used in a body of game
 * @return int
 */
int destroywindows(window_t structWindow)
{
    destroy(structWindow);
    return 0;
}

/**
 * @brief This function destroy all elements permanent used in structWindow
 * @param structWindow Is a struct used in a body of game
 * @return int
 */
int destroyall(window_t structWindow)
{
    destroywindows(structWindow);
    printf("Nettoyage des ressources...\n");
    return 0;
}