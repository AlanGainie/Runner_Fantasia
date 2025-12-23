////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2025-2027 Yaouen Ledanvic (yaouen@ledanvic.***)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
//
////////////////////////////////////////////////////////////

#include <stdarg.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef MY_H_
#define MY_H_
#include "macros.h"
#define MILLION 1000000.0f
#define MILLIER 1000.0f
#define NBRSETTINGSCENE SCENE_COUNT - 2 // Moins SCENE_COUNT et ERRORSCENE

////////////////////////////////////////////////////////////
// Structures
//
// ---
//
////////////////////////////////////////////////////////////

typedef struct text
{
    sfText *text;
    sfFont *font;
    int style;
    sfVector2f position;
    sfColor color;
    char *content;
} text_t;

typedef struct sprite
{
    sfVector2f spritePossition;
    sfSprite *constructsprite;
    sfTexture *constructspritetexture;
    sfClock *clock;
    sfTime time;
    sfInt64 seconds;
} sprite_t;

typedef struct icon
{
    sfImage *icon;
    sfVector2u sizeicon;
} icon_t;

typedef struct scene
{
    sfVideoMode new_mode;
    sprite_t background;
    sprite_t sprites[SPRITE_COUNT];
    icon_t icons[ICON_COUNT];
    text_t texts[TEXT_COUNT];
    char *title;
} scene_t;

typedef struct window
{
    sfVideoMode starting_mode;
    sfRenderWindow *window;
    scene_t scenes[SCENE_COUNT];
    int curent_scene;
    char *inittitle;
} window_t;

////////////////////////////////////////////////////////////
// Global library
////////////////////////////////////////////////////////////
char *my_strcat(char *dest, char const *src);

////////////////////////////////////////////////////////////
// CSFML library
////////////////////////////////////////////////////////////
// Elements and pre-setting
sprite_t createSprite(sfVector2f setPossition, char *img, sfVector2f setScale, sfIntRect setRect);
sfImage *createIcon(sfRenderWindow *window, char *img, sfVector2u sizeimg);
int pre_setting_scenes(int current_scene, scene_t *scenes, sfRenderWindow *window);

// Setting
int setting(window_t *structWindow);

// Body
int pollEvent(window_t *structWindow);
int draw(window_t structWindow, scene_t scene);
int destroy(window_t structWindow);

int log_message(char *content, int status, void *located);
void segfaultlog(int sig);

int destroyall(window_t structWindow);

// Key event
int keyEventRight(sfEvent event, scene_t *scene, sfKeyCode key);
int keyEventLeft(sfEvent event, scene_t *scene, sfKeyCode key);
int keyEventTop(sfEvent event, scene_t *scene, sfKeyCode key);
int keyEventDown(sfEvent event, scene_t *scene, sfKeyCode key);
int keyEventScenes(sfEvent event, window_t *structWindow, sfKeyCode key);

////////////////////////////////////////////////////////////
// Game
////////////////////////////////////////////////////////////
int window(void);
int main(void);

#endif
