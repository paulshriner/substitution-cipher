#ifndef Cipher_h
#define Cipher_h



/**
    @brief Generates a random cipher.

    Used by: main

    @param cipher "The cipher to fill.
    @param start - The character to start.
    @param end - The character the cipher will end on (inclusive)

    @attention Cipher is at least end-start in length.
    @attention Mutates: Fills cipher randomly with characters between start and end
*/
void GenerateCipher(char * cipher, char start, char end);


/**
    @brief Prints the cipher.

    Used by: main
    Uses colors.

    @param cipher The cipher to print.
    @param start The character started on cipher
    @param length The length of the cipher
*/
void PrintCipher(char * cipher, char start, char length);



/**
    @brief Encrypts the given string

    Anything out of bounds of the cipher will not be encrypted and will be preserved.
    Used by main.
    
    @attention mutatates: encypts the string in place, destroying the original characters
    @param string string to be encrypted, will be changed by the function
    @param length length of the string to encript
    @param cipher cipher to use for encrypting the string
    @param start the first character the cipher uses
    @param end the last character the ciper uses
*/
void EncryptString(char* string, int length, char* cipher, char start, char end);



#endif