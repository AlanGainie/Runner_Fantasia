#include "../include/my.h"

text_t
createText(sfVector2f position, char *content)
{
    text_t structtext;
    structtext.text = sfText_create();
    structtext.font = sfFont_createFromFile("../ressources/cinzel.ttf");
    structtext.style = sfTextRegular;

    sfText_setColor(structtext.text, structtext.color);
    sfText_setFont(structtext.text, structtext.font);
    sfText_setPosition(structtext.text, position);
    sfText_setStyle(structtext.text, structtext.style);
    sfText_setString(structtext.text, content);
    sfText_setCharacterSize(structtext.text, 40);

    structtext.position = position;
    structtext.color = sfBlack;
    structtext.content = content;
    return structtext;
}
