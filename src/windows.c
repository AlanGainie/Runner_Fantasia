#include "../include/my.h"
#include "signal.h"

// TODO: Set les framerate dans les settings du renderwindow
// TODO: Réfléchir entre le RenderWindow et le Window pour ne pas avoir la fenêtre system
/**
 * @date ✅ 16 september 2025 at 00:00
 * @author Alan Gainié
 * -----------------------------------
 * @brief This function open the graphic windows and execute content of game
 * while render window is open.
 * @param starting_mode Defined size (x and y) of the window and bitsPerPixel (RGBA (32) or RGB (24)) for the first time of this program
 * @param scenes Defined scenes you can use in game or in extra game for animate windows and delete data unused currently
 * @return int (a status of function)
 */
int window(void)
{
    window_t structWindow;
    structWindow.starting_mode = (sfVideoMode){1920, 1080, 32};
    structWindow.inittitle = "Fenetre CSFML";
    structWindow.window = sfRenderWindow_create(structWindow.starting_mode,
                                                structWindow.inittitle,
                                                sfResize | sfClose | sfTitlebar,
                                                NULL);
    sfRenderWindow_setFramerateLimit(structWindow.window, 60);

    setting(&structWindow);

    while (sfRenderWindow_isOpen(structWindow.window))
    {
        pollEvent(&structWindow);

        sfRenderWindow_clear(structWindow.window, sfBlack); // Refresh les FPS
        draw(structWindow, structWindow.scenes[structWindow.curent_scene]);
        sfRenderWindow_display(structWindow.window);
        if (signal(SIGSEGV, segfaultlog) == SIG_ERR)
            destroyall(structWindow);
    }
    // endlog();
    destroyall(structWindow);
    return 0;
}
