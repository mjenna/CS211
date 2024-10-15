# CS211
Computer Architecture, Rutgers NB, Fall 2024 

Inside the first folder:
strlib.c, creating a string library with the following functions:
•str_len() will return the length of the string passed in.
•str_cpy() will copy a source string to it’s destination string.
• strcmp(), similar to strcmp() in string.h
– Here, we’ll compare two strings: a and b.
∗ If a < b, return -1
∗ If a > b, return 1
∗ If a == b, return 0
• strdup(),we pass in a string, S. strdup will malloc a new character
array and copy S to it. The new array will then be returned

Inside the second folder:
Implement mergesort, sorting an array of strings. Use the strlib created in first part
