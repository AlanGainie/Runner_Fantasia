#ifndef MACROS_H
#define MACROS_H

////////////////////////////////////////////////////////////
// Macros
//
// Add an enum for the scalability of sprites
//
////////////////////////////////////////////////////////////

typedef enum
{
    TEXTS,
    ICONS,
    SPRITES,
    SCENES,
    MACROS_COUNT
} macros_id_t;

typedef enum
{
    TEXT_CONSOLE,
    // TEXT_MENU,
    // TEXT_HERO,
    // TEXT_ENNEMI,
    TEXT_COUNT
} text_id_t;

typedef enum
{
    ICON_MENU,
    // ICON_HERO,
    // ICON_ENNEMI,
    ICON_COUNT
} icon_id_t;

typedef enum
{
    SPRITE_BAT,
    // SPRITE_HERO,
    // SPRITE_ENNEMI,
    SPRITE_COUNT
} sprite_id_t;

typedef enum
{
    CHARGING,
    STARTING_MENUE,
    OPTION_MENUE,
    PARAMETER_MENUE,
    INGAME,
    ENDGAME,
    CREDIT,
    ERRORSCENE,
    SCENE_COUNT
} scene_id_t;

typedef struct
{
    char *name; // Nom “symbolique” de la macro/enum
    int value;  // Sa valeur (pour enum) ou NULL pour #define
    char *type; // définis le type de macros que l'on dois prendre en considération facultatif par défaut enum
} macro_t;

typedef struct
{
    char *name;
    const macro_t *enummacro;
} macros_t;

static const macro_t scenes[] = {
    {"CHARGING", CHARGING, NULL},
    {"STARTING_MENUE", STARTING_MENUE, NULL},
    {"OPTION_MENUE", OPTION_MENUE, NULL},
    {"PARAMETER_MENUE", PARAMETER_MENUE, NULL},
    {"INGAME", INGAME, NULL},
    {"ENDGAME", ENDGAME, NULL},
    {"CREDIT", CREDIT, NULL},
    {"ERRORSCENE", ERRORSCENE, NULL},
    {NULL, SCENE_COUNT, NULL}};

static const macro_t texts[] = {
    {"CHARGING", TEXT_CONSOLE, NULL},
    {NULL, TEXT_COUNT, NULL}};

static const macro_t icons[] = {
    {"ICON_MENU", ICON_MENU, NULL},
    // {"ICON_HERO", ICON_COUNT, ICON_HERO},
    {NULL, ICON_COUNT, NULL}};

static const macro_t sprites[] = {
    {"SPRITE_BAT", SPRITE_BAT, NULL},
    // {"SPRITE_HERO", SPRITE_HERO, NULL},
    // {"SPRITE_ENNEMI", SPRITE_ENNEMI, NULL},
    {NULL, SPRITE_COUNT, NULL}};

static const macros_t macros[MACROS_COUNT] = {
    {"texts", texts},
    {"icons", icons},
    {"sprites", sprites},
    {"scenes", scenes}};

char *searchTitleEnumMacros(char *listname, int index, char *listtype);

#endif