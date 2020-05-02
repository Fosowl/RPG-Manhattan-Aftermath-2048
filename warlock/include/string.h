/*
** EPITECH PROJECT, 2020
** string.h
** File description:
** string function include for warlock
*/

#ifndef STRING_H_
#define STRING_H_

// initialize.c

/*
\fn char *clean_alloc(int size)
\brief allocate string and fill it with '\0'
\param size : the number of char the string can contain.
\return the allocated string.
*/

char *clean_alloc(int size);

/*
\fn char *fill(char *with)
\brief allocate string and fill string with another
\param with : the string to fill with.
\return this : new string filled and allocated.
*/

char *fill(char *with);

/*
\fn void fill_double(char **dest, char **temp, int nb)
\brief allocate and copy an array of string into another.
\param dest : the 2d array to fill with.
\return (char **) the allocated and filled array of string.
*/

char **fill_double(char **temp);

/*
\fn char *load_files(char *path)
\brief load file into buffer
\param path the file path to open\return
\return buffer of file content
*/

char *load_file(char *path);

// initialize_more.c

/*
\fn char **clean_double_alloc(int y, int x)
\brief allocate array of string in desirated size.
\param y : the number of string
\param x : the lenght of each string
\return a new array of string(char **).
*/

char **clean_double_alloc(int y, int x);

// copy.c

/*
\fn int copy_double(char **copy, char **array)
\brief copy an array of string into another.
\param copy : the copied array string.
\param array : the array of string to copy.
\return 0.
*/

int copy_double(char **copy, char **array);

/*
\fn int my_strcpy(char *dest, char *src)
\brief copy a string into another.
\param dest : the copied string
\param src : the string to copy
\return 0.
*/

int my_strcpy(char *dest, char *src);

// array.c

/*
\fn int locate_array_element(char **p, char *keyword)
\brief determine the position of a string in an array
of string according to a corresponding keyword.
\param p : array of string to search in.
\param keyboard : keyword to find in the array.
\return the index in the array of string.
*/

int locate_array_element(char **p, char *keyword);

/*
\fn char **array_add_element(char **array, char *element)
\brief add a string to an array of string.
\param array : array to add an element to.
\param element : string to add to array.
\return the new array with the added element.
*/

char **array_add_element(char **array, char *element);

/*
\fn char **array_pop_element(char **array, int this);
\brief pop a string from an array of string.
\param array : array to pop an element from.
\param this : index of the string to pop.
\return the new array with the string removed.
*/

char **array_pop_element(char **array, int this);

#endif /* !STRING_H_ */
