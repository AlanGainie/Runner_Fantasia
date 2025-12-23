#include "../include/my.h"

// TODO: Rajouter un retour d'erreur en plus du message de log
/**
 * @brief Create a Sprite object
 * @param setPossition Is a placement of sprite went is call for the first time
 * @param img Is a path of picture you want sprite contain
 * @param setScale Is a multiplicated of the size set to sprite
 * @param setRect Is a delemited border of sprite
 * @return sfSprite * Is a CSFML struct for sprite
 * @attention This function no return a status so you sheck this outside
 * of this function
 */
sprite_t
createSprite(sfVector2f setPossition, char *img, sfVector2f setScale, sfIntRect setRect)
{
    sprite_t structsprite = {0};

    if (!structsprite.constructsprite)
        structsprite.constructsprite = sfSprite_create();
    if (img && !structsprite.constructspritetexture)
    {
        structsprite.constructspritetexture = sfTexture_createFromFile(img, NULL);
        sfSprite_setTexture(structsprite.constructsprite, structsprite.constructspritetexture, sfTrue);
        sfSprite_setTextureRect(structsprite.constructsprite, setRect);
        if (setScale.x != 0 || setScale.y != 0)
            sfSprite_setScale(structsprite.constructsprite, setScale);
        log_message("Texture correctement saissi", 0, NULL);
    }
    else
    {
        log_message("Pas de texture saissi erreur", -1, NULL);
    }

    if (!structsprite.clock)
    {
        structsprite.clock = sfClock_create();
        structsprite.time = sfClock_getElapsedTime(structsprite.clock);
        structsprite.seconds = structsprite.time.microseconds / MILLION;
    }
    if (setPossition.x != 0 || setPossition.y != 0)
    {
        structsprite.spritePossition = setPossition;
        sfSprite_setPosition(structsprite.constructsprite, structsprite.spritePossition);
    }
    return structsprite;
}