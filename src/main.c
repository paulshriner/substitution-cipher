/*
    Class: ECET 4640-002
    Assignment: Lab Assignment 3
    Authors: Christian Messmer, Karl Miller, Paul Shriner

    main.c: Entry point of the program.
*/

#include "FlexString.h"
#include "Cipher.h"
#include "colors.h"

#define CIPHER_START 32
#define CIPHER_END 126

/**
   Entry point of the program.

   Generates a randomized cipher, then prompts the user for a string to encrypt. Encrypts that string, then prints the encrpyted string. Finally, it prints the cipher.

   Calls GenerateCipher, FlexString, EncryptString, and PrintCipher.

   Uses macros from colors.h
*/
int main()
{

    printf("%s\nSubstitution Cipher\n", COLOR_YELLOW);
    printf("%sBy Karl, Christian, and Paul%s\n", COLOR_GRAY, COLOR_RESET);

    // reserve the cipher of the needed length
    char cipher[CIPHER_END - CIPHER_START + 1];

    // Generate the randomized cipher.
    GenerateCipher(cipher, CIPHER_START, CIPHER_END);

    // Get a flexible string from user input
    char *string;
    size_t capacity;
    printf("\nEnter a string: ");
    int n_chars = FlexString(&string, &capacity, stdin);

    printf("\nEncrypting: %s%s%s\n", COLOR_RED, string, COLOR_RESET);

    // Encrypt the string
    EncryptString(string, n_chars, cipher, CIPHER_START, CIPHER_END);

    // Print the result
    printf("    Result: %s%s%s%s\n", COLOR_BLUE, COLOR_BOLD, string, COLOR_RESET);

    // Print the cipher.
    PrintCipher(cipher, CIPHER_START, CIPHER_END - CIPHER_START + 1);

    printf("\n");

    return 0;
}
