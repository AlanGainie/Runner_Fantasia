#include "../include/my.h"

// TODO: Use or supp sizeicon

/**
 * @brief Create a Icon object
 * @param window Is a parameter of window (sfRenderWindow)
 * @param img Is a path of picture you want sprite contain
 * @param sizeimg Is a size of the icon
 * @return sfImage * Is a CSFML struct for use a picture, icon or other method
 * @attention This function no return a status so you sheck this outside
 * of this function
 */
sfImage *createIcon(sfRenderWindow *window, char *img, sfVector2u sizeimg)
{
    sfImage *icon = sfImage_createFromFile(img);
    const sfUint8 *pixels = sfImage_getPixelsPtr(icon);
    // sfVector2u sizeicon = sfImage_getSize(icon);

    sfRenderWindow_setIcon(window, sizeimg.x, sizeimg.y, pixels);
    return icon;
}