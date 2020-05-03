/*
** EPITECH PROJECT, 2019
** parsing.c
** File description:
** usefull3 function
*/

#include "warlock.h"

char **divide_array(char *str, char separation)
{
    int o = 0;
    int result_x = 0;
    int str_x = 0;
    char **result = clean_double_alloc(count_word(str, separation) + 1
    , longest_word(str, separation) + 1);

    for (; str[str_x] == separation || str[str_x] == '\t'; str_x++);
    for ( ; str[str_x] != '\0'; str_x++, result_x += 1) {
        if (str[str_x] == separation || str[str_x] == '\t') {
            for (; str[str_x] == separation || str[str_x] == '\t'; str_x++);
            str_x -= 1;
            result[o][result_x] = '\0';
            o += 1;
            result_x = -1;
        }
        else
            result[o][result_x] = str[str_x];
    }
    result[o + 1] = NULL;
    return (result);
}

void remove_char(char *str, char remove, int rest)
{
    char *cpy;
    int k = 0;

    DEBUG_MODE == 1 ? debug_log("remove_char()", str) : 0;
    cpy = malloc(my_strlen(str) * sizeof(char) + 1);
    if (!cpy)
        return;
    cpy = fill(str);
    for (int i = 0, d = 0; cpy[i] != '\0'; i++) {
        if (cpy[i] == remove && cpy[i + 1] != remove)
            d = 0;
        if (cpy[i] == remove)
            d++;
        if (cpy[i] != remove || d <= rest) {
            str[k] = cpy[i];
            k++;
        }
    }
    free(cpy);
    str[k] = '\0';
}

char *fusion(char *str, char *sticked, int place)
{
    char *end_copy = NULL;
    char *tmp = NULL;

    DEBUG_MODE == 1 ? debug_log("fusion() first arg", str) : 0;
    DEBUG_MODE == 1 ? debug_log("fusion() second arg", sticked) : 0;
    end_copy = malloc(sizeof(char) * (sizeof(str) - place + 1));
    tmp = malloc(sizeof(char) * (sizeof(str) + sizeof(sticked) + 1));
    if (!tmp || !end_copy)
        return (NULL);
    if (my_strlen(str) < place)
        for (int index = place, k = 0; str[index] != '\0'; index++, k++)
            end_copy[k] = str[index];
    else
        end_copy[0] = '\0';
    for (int index = 0; index < place && str[index] != '\0'; index++)
        tmp[index] = str[index];
    fusion_2(end_copy, tmp, sticked, place);
    free(end_copy);
    return (tmp);
}

void fusion_2(char *end_copy, char *str, char *sticked, int place)
{
    for (int index = 0; sticked[index] != '\0'; index++, place++)
        str[place] = sticked[index];
    for (int index = 0; end_copy[index] != '\0'; index++, place++)
        str[place] = end_copy[index];
    str[place] = '\0';
}

char *my_revstr(char *str)
{
    int l = my_strlen(str) - 1;
    char t;

    for (int i = 0, r = 0, lenght = l; i < lenght / 2 + lenght % 2
    ; i++, r++, l--) {
        t = str[r];
        str[r] = str[l];
        str[l] = t;
        if (l <= r)
            break;
    }
    return (str);
}