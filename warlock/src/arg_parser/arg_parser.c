/*
** EPITECH PROJECT, 2020
** warlock-C-libraries
** File description:
** arg_parser
*/

#include "warlock/arg_parser.h"
#include "warlock/string.h"
#include "warlock/gather.h"
#include "warlock/parsing.h"
#include <stdlib.h>

static void load_parser_content(adapter_t *a, int *current, arg_t **list)
{
    int k = 0;

    list[*current]->option = fill(a->argv[a->i]);
    list[*current]->content = malloc(sizeof(char *) * 10);
    for (k = 0, a->i++; a->i < a->ac && a->argv[a->i][0] != '-'; a->i++) {
        list[*current]->content[k] = fill(a->argv[a->i]);
        k++;
    }
    a->i--;
    list[*current]->content[k] = NULL;
    *current += 1;
}

static int load_parser_stick_content(adapter_t *a, int *current, arg_t **list)
{
    if (search("=", a->argv[a->i]) == -1) {
        list[*current]->option = fill(a->argv[a->i]);
        return (0);
    }
    list[*current]->content = malloc(sizeof(char *) * 2);
    list[*current]->stick_content = cut_tail(a->argv[a->i], '=');
    list[*current]->content[0] = list[*current]->stick_content;
    list[*current]->content[1] = NULL;
    list[*current]->option = keep_until(a->argv[a->i], '=');
    *current += 1;
    return (0);
}

/*
\fn arg_t **argument_parser(int ac, char **argv)
\brief function use to parse argument pass to "main" function.
       for exemple you can use ./a.out --option_name=value -debug
       or, ./a.out -d -p value1 value2 --other_option=value -R
\param ac : the "ac" from <<int main(int ac, char **argv)>>
\param argv : the "argv" from <<int main(int ac, char **argv)>>
\return list(arg_t **) : a list of structure containing the option and their value.
                        arg_t content is as follow :
                        char *option --> the option name for exemple "-debug"
                        char **content --> the value list of each option for
                        exemple "--debug full"
                        char *stick_content --> exemple : in --debug=full
                        stick_content will be equal to "full" and option 
                        to --debug
*/

arg_t **argument_parser(int ac, char **argv)
{
    arg_t **list = malloc(sizeof(arg_t *) * ac);
    adapter_t *a = malloc(sizeof(adapter_t));
    int current = 0;

    a->ac = ac;
    a->argv = argv;
    for (int i = 0; i < ac; i++)
        list[i] = malloc(sizeof(arg_t));
    for (a->i = 1; a->i < ac; a->i++) {
        if (argv[a->i][0] == '-' && argv[a->i][1] == '-') {
            load_parser_stick_content(a, &current, list);
        } else if (argv[a->i][0] == '-') {
            load_parser_content(a, &current, list);
        }
    }
    list[current] = NULL;
    return (list);
}

