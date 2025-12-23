#include "../include/my.h"

int pre_seticons(scene_t *scene, sfRenderWindow *window)
{
    scene->icons[ICON_MENU].icon = createIcon(
        window,
        "assets/pictures/icon.png",
        (sfVector2u){16, 16});
    return 0;
}

int pre_setsprites(scene_t *scene)
{
    scene->sprites[SPRITE_BAT] = createSprite(
        (sfVector2f){50, 50},
        "assets/pictures/PNJ.png",
        (sfVector2f){2, 2},
        (sfIntRect){0, 0, 40, 40});
    scene->background = createSprite(
        (sfVector2f){0, 0},
        "assets/pictures/background.jpg",
        (sfVector2f){3, 4},
        (sfIntRect){5, 5, 655, 260});
    return 0;
}

int pre_set_error_scene(scene_t *scene, sfRenderWindow *window)
{
    sfSleep(sfMilliseconds(0.1 * MILLIER));
    scene->icons[ICON_MENU].icon = createIcon(
        window,
        "assets/pictures/erroricon.png",
        (sfVector2u){16, 16});
    scene->background = createSprite(
        (sfVector2f){0, 0},
        "assets/pictures/errorbackground.jpg",
        (sfVector2f){3, 4},
        (sfIntRect){5, 5, 655, 260});
    return 0;
}

// createMacros(scene_id_t, enum)
// renvoie la scene en cour mais set toutes les scenes remonter en pointeur
int pre_setting_scenes(int current_scene, scene_t *scenes, sfRenderWindow *window)
{
    int status = 0;
    (void)current_scene;

    pre_set_error_scene(&scenes[ERRORSCENE], window);
    for (int counter = 0; counter < NBRSETTINGSCENE; counter++)
    {
        sfSleep(sfMilliseconds(0.1 * MILLIER));
        scenes[counter].title = searchTitleEnumMacros("scenes", counter, "enum");
        status += pre_seticons(&scenes[counter], window);
        status += pre_setsprites(&scenes[counter]);
        log_message("Scene correctement saissi", 0, NULL);
    }
    if (status == 84 || status == 168)
    {
        log_message("Scene incorrectement saissi", -1, NULL);
        return ERRORSCENE;
    }
    return CHARGING;
}