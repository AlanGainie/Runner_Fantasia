#include "../include/my.h"

int keyEventRight(sfEvent event, scene_t *scene, sfKeyCode key)
{
    sfSprite *sprite = scene->sprites[SPRITE_BAT].constructsprite;

    if (event.key.code == key && scene->sprites[SPRITE_BAT].spritePossition.x <= 1865.0)
    {
        scene->sprites[SPRITE_BAT].spritePossition.x += 15.0;
        printf("+mouvXD =%f", scene->sprites[SPRITE_BAT].spritePossition.x);
        sfSprite_setPosition(sprite, scene->sprites[SPRITE_BAT].spritePossition);
    }
    return 0;
}

int keyEventLeft(sfEvent event, scene_t *scene, sfKeyCode key)
{
    sfSprite *sprite = scene->sprites[SPRITE_BAT].constructsprite;

    if (event.key.code == key)
    {
        if (scene->sprites[SPRITE_BAT].spritePossition.x >= -0.0)
        {
            scene->sprites[SPRITE_BAT].spritePossition.x -= 15.0;
            printf("+mouvXA =%f", scene->sprites[SPRITE_BAT].spritePossition.x);
            sfSprite_setPosition(sprite, scene->sprites[SPRITE_BAT].spritePossition);
        }
    }
    return 0;
}

int keyEventTop(sfEvent event, scene_t *scene, sfKeyCode key)
{
    sfSprite *sprite = scene->sprites[SPRITE_BAT].constructsprite;

    if (event.key.code == key)
        if (scene->sprites[SPRITE_BAT].spritePossition.y >= -0.0)
        {
            scene->sprites[SPRITE_BAT].spritePossition.y -= 15.0;
            printf("+mouvYZ =%f", scene->sprites[SPRITE_BAT].spritePossition.y);
            sfSprite_setPosition(sprite, scene->sprites[SPRITE_BAT].spritePossition);
        }
    return 0;
}

int keyEventDown(sfEvent event, scene_t *scene, sfKeyCode key)
{
    sfSprite *sprite = scene->sprites[SPRITE_BAT].constructsprite;

    if (event.key.code == key)
    {
        if (scene->sprites[SPRITE_BAT].spritePossition.y <= 1005.0)
        {
            scene->sprites[SPRITE_BAT].spritePossition.y += 15.0;
            printf("+mouvYS =%f", scene->sprites[SPRITE_BAT].spritePossition.y);
            sfSprite_setPosition(sprite, scene->sprites[SPRITE_BAT].spritePossition);
        }
    }
    return 0;
}

int keyEventScenes(sfEvent event, window_t *structWindow, sfKeyCode key)
{
    if (event.key.code == key && structWindow->curent_scene < NBRSETTINGSCENE)
    {
        structWindow->curent_scene += 1;
        char *newtitle = my_strcat(structWindow->inittitle, structWindow->scenes[structWindow->curent_scene].title);
        printf("+scenechanged =%d", structWindow->curent_scene);
        printf("title scene : %s\n", newtitle);
        sfRenderWindow_setTitle(structWindow->window, newtitle);
    }
    else if (event.key.code == key && structWindow->curent_scene == NBRSETTINGSCENE)
    {
        printf("+scene unchanged error detected\n");
        return 84;
    }
    return 0;
}