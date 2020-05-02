/*
** EPITECH PROJECT, 2020
** warlock-C-libraries
** File description:
** arg_parser include for warlock-lib
*/

#ifndef ARG_PARSER_H_
#define ARG_PARSER_H_

typedef struct arg_t {
    char *option;
    char **content;
    char *stick_content;
    int value;
} arg_t;

typedef struct adapter_t {
    int ac;
    int i;
    char **argv;
} adapter_t;

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

arg_t **argument_parser(int ac, char **argv);

#endif /* !ARG_PARSER_H_ */