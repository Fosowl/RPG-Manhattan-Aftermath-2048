/*
** EPITECH PROJECT, 2020
** gather.h
** File description:
** gathering function include for warlock lib
*/

#ifndef GATHER_H_
#define GATHER_H_

// get.c

/*
\fn int char_in(char c, char *str)
\brief check if a character is inside a string.
\param c : the character to check.
\param str : the string witch you check the character in.
\return -1 if not found else return the index.
*/

int char_in(char c, char *str);

/*
\fn int compare(char *str, char *try)
\brief compare 2 string
\param str : the first string.
\param try : the string to compare with.
\return 1 if the string are identical else return 0.
*/

int compare(char *str, char *try);
/*
\fn int my_strlen(char *str)
\brief measure string lenght
\param str : the string to measure the lenght.
\return the len of the string in a int.
*/

int my_strlen(char *str);

/*
\fn int search(char *this, char *in)
\brief search string inside another
\param this : the string that you are looking for.
\return the index if found else return -1
*/

int search(char *this, char *in);

/*
\fn int read_input(char *str)
\brief read user input.
\param str : the string that store user input.
\return 0
*/

int read_input(char *str);

// letter_info.c

/*
\fn int compare_letter(char l1, char l2)
\brief compare 2 letter and ignore case.
\param l1 : (char) first character.
\param l2 : (char) second character.
\return 1 if char are same letter and 0 if not the case.
*/

int compare_letter(char l1, char l2);

/*
\fn int is_number(char *c)
\brief check if character is a number.
\param c : (char) character to check.
\return 1 if character is a number.
*/

int is_number(char *c);

// gather.h

/*
\fn int count_digit(float *number)
\brief count number of digit in a number
\param number : (float *) number to count digit.
\return number of digit in number.
*/

int count_digit(float *number);

/*
\fn int array_lenght(char **array)
\brief measure lenght of and array of string
\param array(char **) array to measure the lenght.
\return number of element of the array of string.
*/

int array_lenght(char **array);

// get_next_line.c

/*
\fn char *get_next_line(int fd)
\brief get next line of file or input at each call.
\param fd : the file descriptor 0 for stantard input.
\return NULL if an error occured else return the line read.
*/

char *get_next_line(int fd);

// buffer_info.c

/*
\fn int count_word(char *buffer)
\brief count number of word in a string.
\param buffer : the string in witch you want ot count the number of word.
\return the number of word in the string.
*/

int count_word(char *buffer);

/*
\fn int longest_word(char *buffer)
\brief return size of longest word in the string
\param buffer : the string in witch you cant to lenght of the longest word.
\return the lenght of the longest word in the string.
*/

int longest_word(char *buffer);

#endif /* !GATHER_H_ */
