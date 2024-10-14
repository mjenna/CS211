#include <stdio.h>
#include <stdlib.h>
#include "./strlib.h"

/**
 * @brief Main function to test string manipulation functions implemented in strlib.h.
 * 
 * This includes:
 * - Comparing strings using strcmp
 * - Calculating the length of a string with str_len
 * - Copying strings with str_cpy
 * - Duplicating strings using strdup
 *
 * @note To compile the program, use: make customtestclient
 * @note Run the executable to see the results of the tests.
 * 
 * The expected outcomes for the test cases are noted in the output.
 */

int main(int argc, char **argv){
    printf("Comparing 'CS211' and 'CS206': %d\n", strcmp("CS211", "CS206")); 
    /* make your own testcases!*/

//strlen
    const char *stringa = "hey man\n";
    const char *stringb = "CS211";
    printf("length is '%s': %d (Expected: 8)", stringa, str_len(stringa));
    printf("length is '%s': %d (Expected: 5)", stringb, str_len(stringb));

//copying
    char dest[50];
    str_cpy(dest, stringa);
    printf("original: '%s' (copied: '%s')", dest, stringa);

//duping
    char *duplicated_str = strdup(stringa);
    if (duplicated_str){
        printf("Duplicated string: '%s' (Expected: '%s')", duplicated_str, stringa);
        free(duplicated_str);
    }else{
        printf("Failed to duplicate string.\n");
    }

    return 0;
}
