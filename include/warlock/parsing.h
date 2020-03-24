/*
** EPITECH PROJECT, 2020
** parsing.h
** File description:
** parsing function include for warlock lib
*/

#ifndef PARSING_H_
#define PARSING_H_

// letter.c

char *empty_string(char *str);
char *insert(char *str, char pushed);
char *capitalize(char *str);

// parsing.c

/*
\fn char **divide_array(char *str, char **result, char separation)
\brief function to divide a string into a 2d array.
\param str : the simple string.
\separation : the charater to divide the array with.
\return result (char**) the array of word.
*/

char **divide_array(char *str, char separation);

/*
\fn void remove_char(char *str, char remove, int rest)
\brief remove char occurence from string.
\param str : the string to remove character occurence from.
\param remove : the character to remove in the string.
\param rest : number of character to leave starting from the right.
\return nothing.
*/

void remove_char(char *str, char remove, int rest);

/*
\fn char *fusion(char *str, char *sticked, int place)
\brief fusion 2 string.
\param str : the first string.
\param sticked : the string that will be sticked to the first one.
\place : the index of sticked in str.
\return 0.
*/

char *fusion(char *str, char *sticked, int place);

/*
\fn char *my_revstr(char *str)
\brief reverse a string.
\param str : the string to reverse.
\return (char *) the reversed string.
*/

char *my_revstr(char *str);

// replace.c

/*
\fn char *replace(char *str, char *this, char *with)
\brief replace string occurence in a string ith another string.
\param str : the string to modify.
\param this : the string to replace inside of str.
\param with : the string that will replace this.
\return (char *) the modified string.
*/

char *replace(char *str, char *this, char *with);

// light_python.c

/*
\fn char *append(char *origin, char *added)
\brief insert string in front of another with clean memory usage.
\param origin : (char *) first string to increase.
\param added : (char *) string to add at end of first string.
\return (char *) new string that result in the 2 string combinated.
*/

char *append(char *origin, char *added);

/*
\fn char *pop(char *origin, char character);
\brief pop character occurence in string
\param origin : (char *) string to modify.
\param character : (char) character to pop.
\return (char *) new string with character occurence removed.
*/

char *pop(char *origin, char character);

// cut.c

/*
\fn char *cut_tail(char *buffer, char character)
\brief cut string tail from delimated character.
\param buffer : string to cut.
\param character : character to delimitate the cut.
\return (char *) the new string cutted.
*/

char *cut_tail(char *buffer, char character);

/*
\fn char *keep_until(char *buffer, char character)
\brief cut string
\param buffer : string to cut.
\param character : character to delimitate the cut.
\return (char *) the new string cutted.
*/

char *keep_until(char *buffer, char character);

#endif /* !PARSING_H_ */
