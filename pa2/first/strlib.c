#include "./strlib.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * tolowercase
 * Converts an uppercase character to its lowercase equivalent.
 * 
 * @param a The character to convert.
 * @return The lowercase version of the character if it is uppercase; 
 * Otherwise, returns the character unchanged.
 * 
 * Example: tolowercase('A') returns 'a', while tolowercase('1') returns '1'.
 */
static char tolowercase(char a)
{
    if (a >= 'A' && a <= 'Z')
    {
        char lowercase = a | 0x20; // Toggle the 6th bit to convert to lowercase
        return lowercase;
    }
    return a;
}

/**
 * strcmp
 * Compares two strings lexicographically.
 *
 * @param a One string to compare.
 * @param b The other string to compare.
 * @return 1 if a > b, -1 if a < b, or 0 if a == b.
 * 
 * The comparison is based on the ASCII values of the characters.
 * The function processes each character until a difference is found
 * or the end of either string is reached.
 */
int strcmp(const char *a, const char *b){
    int counter = 0;
    while (a[counter] != '\0' && b[counter] != '\0'){
        // compare w tolowercase
        char lower_a = tolowercase(a[counter]);
        char lower_b = tolowercase(b[counter]);
        
        if(lower_a < lower_b){
            return -1;
        }else if(lower_a > lower_b){
            return 1;
        }
        counter++;
    }

    if(a[counter] == '\0' && b[counter] == '\0'){
        return 0;
    }else if(a[counter] == '\0'){
        return -1;
    }else{
        return 1; 
    }
}

/**
 * str_len
 * Calculates the length of a string.
 *
 * @param string The string whose length is to be determined.
 * @return The length of the string, excluding the null terminator.
 *
 * The function iterates through the string until it encounters the null terminator.
 */
int str_len(const char *string){
    int counter = 0;

    while(string[counter] != '\0'){
        counter++;
    }
    return counter;
}

/**
 * str_cpy
 * Copies a source string to a destination string.
 *
 * @param dest The destination string to which the source string will be copied.
 * @param src The source string to be copied.
 *
 * The function copies each character from the source string to the destination
 * string and appends a null terminator at the end.
 */
void str_cpy(char *dest, const char *src){
    int counter =0;
    while(src[counter] != '\0'){
        dest[counter] = src[counter];
        counter++;
    }
    dest[counter] = '\0'; //terminates so it ends
}

/**
 * strdup
 * Duplicates a string by allocating memory and copying its content.
 *
 * @param input The string to be duplicated.
 * @return A pointer to the newly allocated duplicate string.
 *
 * The function first calculates the length of the input string, then allocates
 * memory for the new string (including space for the null terminator),
 * and finally copies the input string into the allocated memory.
 */
char *strdup(const char *input){
    int length = 0;
    while(input[length] != '\0'){
        length++;
    }
    char *newS = (char*)malloc((length + 1) * sizeof(char)); //malloc function
    if(newS == NULL){
        return NULL; //returns nul lif malloc fails
    }

    for(int i = 0; i < length; i++){ //string into the new array
        newS[i] = input[i];
    }

    newS[length] = '\0'; //represents emptiness - > null terminate the new string
    return newS;
}
