#include "../include/my.h"

/**
 * @date ✅ 16 september 2025 at 00:00
 * @author Alan Gainié
 * -----------------------------------
 * @brief This function draw all element have been used for parralaxe background element
 * @param structWindow is a global struct of window
 * @param scene is a structure to contain all element you forgot in curent_scene
 * @return int (a status of function)
 */
int drawparralaxe(window_t structWindow, scene_t scene)
{
    sfSprite_setPosition(scene.background.constructsprite, (sfVector2f){0, 0});
    sfRenderWindow_drawSprite(structWindow.window, scene.background.constructsprite, NULL);

    sfSprite_setPosition(scene.background.constructsprite, (sfVector2f){2220, 0});
    sfRenderWindow_drawSprite(structWindow.window, scene.background.constructsprite, NULL);
    return 0;
}

/**
 * @date ✅ 16 september 2025 at 00:00
 * @author Alan Gainié
 * -----------------------------------
 * @brief This function draw all element in window
 * @param structWindow is a global struct of window
 * @param scene is a structure to contain all element you forgot in curent_scene
 * @return int (a status of function)
 */
int draw(window_t structWindow, scene_t scene)
{
    drawparralaxe(structWindow, scene);
    sfRenderWindow_drawSprite(structWindow.window, scene.sprites[SPRITE_BAT].constructsprite, NULL);
    return 0;
}