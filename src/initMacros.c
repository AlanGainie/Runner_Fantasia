#include "../include/my.h"

char *searchTitleEnumMacros(char *listname, int index, char *listtype)
{
    int counter = 0;

    if (!listtype || strcmp(listtype, "enum") == 1)
    {
        for (; (counter < MACROS_COUNT) | (strcmp(listname, macros[counter].name) == 0); counter++)
            ;
        return macros[counter].enummacro[index].name;
    }
    return "error";
}
