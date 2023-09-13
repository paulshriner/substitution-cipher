/*
    Class: ECET 4640-002
    Assignment: Lab Assignment 3
    Authors: Christian Messmer, Karl Miller, Paul Shriner

    FlexString.h: Function prototypes for FlexString.c
*/

#ifndef FlexString_c
#define FlexString_c

/*
    FlexString is used to create a heap-allocated string that resizes as necessary for longer input strings.
*/

#include <stdio.h>  // for reading input
#include <stdlib.h> // for memory allocation

/**
    Fills a malloced string with input, reallocating if necessary.

    Called by FlexString

    @param string A char **; it points to the string that will be populated.
    @param capacity A pointer to the capacity desired of the string. If 0 or less, it will be set to 11.
    @param file A pointer to a file. Can be stdin if reading from the console.

    @attention Precondition: String has already been malloced.
    @attention Mutates: May reallocate and change value pointed to by string.
    @attention Mutates: May change value pointed to by capacity.
    @return The number of characters read (not including new line, and null-terminator)
*/
int FlexString_Read(char **string, size_t *capacity, FILE *file);

/**
    @brief Creates and fills a malloced string. Then calls FlexString_Read to read from input, resizing as necessary.

    Called by main.

    @param string A pointer to a char*, referencing the string that will be populated.
    @param capacity A pointer to the capacity desired of the string. If 0 or less, it will be set to 11.
    @param file A pointer to a file. Can be stdin if reading from the console.

    @attention Mutates: May reallocate and change value pointed to by string.
    @attention Mutates: May change value pointed to by capacity.
    @return The size of characters read, excluding the null-terminator and new-line (if present)
*/
int FlexString(char **string, size_t *capacity, FILE *file);

#endif
