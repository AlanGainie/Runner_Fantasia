#include "../include/my.h"

int settexts(scene_t *scenes, sfRenderWindow *window)
{
    (void)scenes;
    (void)window;
    // scenes[CONSOLE].texts[ICON_MENU] = createText(
    //     window,
    //     "assets/pictures/icon.png",
    //     (sfVector2u){16, 16});
    return 0;
}

/**
 * @date ✅ 16 september 2025 at 00:00
 * @author Alan Gainié
 * -----------------------------------
 * @brief This function set data of all icon in game
 * @param scenes is a structure to contain all elements you forgot all scenes of game
 * @return int (a status of function)
 */
int seticons(scene_t *scenes, sfRenderWindow *window)
{
    scenes[CHARGING].icons[ICON_MENU].icon = createIcon(
        window,
        "assets/pictures/icon.png",
        (sfVector2u){16, 16});
    scenes[STARTING_MENUE].icons[ICON_MENU].icon = createIcon(
        window,
        "assets/pictures/icon.png",
        (sfVector2u){16, 16});
    return 0;
}

/**
 * @date ✅ 16 september 2025 at 00:00
 * @author Alan Gainié
 * -----------------------------------
 * @brief This function set a data for all sprites in game
 * @param scenes is a structure to contain all elements you forgot all scenes of game
 * @return int (a status of function)
 */
int setparralaxe(scene_t *scenes)
{
    scenes[CHARGING].background = createSprite(
        (sfVector2f){0, 0},
        "assets/pictures/background.jpg",
        (sfVector2f){3, 4},
        (sfIntRect){5, 5, 655, 260});
    scenes[STARTING_MENUE].background = createSprite(
        (sfVector2f){0, 0},
        "assets/pictures/background.jpg",
        (sfVector2f){3, 4},
        (sfIntRect){5, 270, 655, 260});
    // scenes[OPTION_MENUE].background = createSprite(
    //     (sfVector2f){0, 0},
    //     "assets/pictures/background.jpg",
    //     (sfVector2f){3, 4},
    //     (sfIntRect){5, 540, 655, 260});
    return 0;
}

/**
 * @date ✅ 16 september 2025 at 00:00
 * @author Alan Gainié
 * -----------------------------------
 * @brief This function set a data for all sprites in game
 * @param scenes is a structure to contain all elements you forgot all scenes of game
 * @return int (a status of function)
 */
int setsprites(scene_t *scenes)
{
    setparralaxe(scenes);
    scenes[CHARGING].sprites[SPRITE_BAT] = createSprite(
        (sfVector2f){50, 50},
        "assets/pictures/PNJ.png",
        (sfVector2f){2, 2},
        (sfIntRect){0, 0, 40, 40});
    scenes[STARTING_MENUE].sprites[SPRITE_BAT] = createSprite(
        (sfVector2f){50, 50},
        "assets/pictures/PNJ.png",
        (sfVector2f){2, 2},
        (sfIntRect){100, 100, 40, 40});
    return 0;
}

/**
 * @date ✅ 16 september 2025 at 00:00
 * @author Alan Gainié
 * -----------------------------------
 * @brief Set the ting scenes object
 * @param scenes is a structure to contain all elements you forgot all scenes of game
 * @param window is a render of windows
 * @return int (a status of function)
 */
int setting_scenes(scene_t *scenes, sfRenderWindow *window)
{
    settexts(scenes, window);
    seticons(scenes, window);
    setsprites(scenes);
    return 0;
}

/**
 * @date ✅ 16 september 2025 at 00:00
 * @author Alan Gainié
 * -----------------------------------
 * @brief This function set all the elements in game
 * @param structWindow is a global struct of window
 * @attention curent_scene is intern param used for save progression in game
 * @result This function have : structWindow parameter with a pointer of function return
 * @return int (a status of function)
 */
int setting(window_t *structWindow)
{
    int status = 0;

    structWindow->curent_scene = CHARGING;
    structWindow->curent_scene = pre_setting_scenes(structWindow->curent_scene, structWindow->scenes, structWindow->window);
    if (structWindow->curent_scene == ERRORSCENE)
        return status;
    if (structWindow->curent_scene != ERRORSCENE && structWindow->curent_scene != CHARGING)
        status = 84;
    status = setting_scenes(structWindow->scenes, structWindow->window);
    return status;
}