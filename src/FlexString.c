/*
    Class: ECET 4640-002
    Assignment: Lab Assignment 3
    Authors: Christian Messmer, Karl Miller, Paul Shriner

    FlexString.c: Functions for reading in a string.
*/

#include "FlexString.h"

// See Cipher.h for header comments
int FlexString_Read(char **string, size_t *capacity, FILE *file)
{
    int i = 0;
    char ch = '?';
    do
    {
        ch = getc(file);
        if (i >= *capacity - 1)
        {
            *capacity *= 2;
            *string = realloc(*string, *capacity * sizeof(char));
        }
        (*string)[i] = ch;
        i++;
    } while (ch != '\n' && ch != '\0');
    (*string)[i - 1] = '\0';
    return i - 1;
}

// See Cipher.h for header comments
int FlexString(char **string, size_t *capacity, FILE *file)
{

    if (*capacity <= 0)
    {
        *capacity = 11;
    }
    *string = malloc(*capacity * sizeof(char));
    return FlexString_Read(string, capacity, file);
}
