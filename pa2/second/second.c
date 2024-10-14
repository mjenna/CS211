#include "../first/strlib.h"
#include <stdio.h>
#include <stdlib.h>
int height; //a global variable which will help us determine the height.
/**
 * merge
 * We merge the two subarray to the main array, this is the 
 * sorting process
 * @param array, array we're merging to.
 * @param larray, the left subarray.
 * @param rarray, the right subarray.
 * @param a, length of array.
 * @param b, length of larray.
 * @param c, length of rarray.
 */
void merge(char** array, char** larray, char** rarray, int a, int b, int c){
    int i = 0, j = 0, k = 0; // i for larray, j for rarray, k for array

    while(i < b && j < c){ //the length is greater than 0
        if(strcmp(larray[i], rarray[j]) <=0){
            array[k++] = larray[i++]; //merging elements from larray to array

        }else{
            array[k++] = rarray[j++]; //rarray to array
        }
    }

    while(i<b){
        array[k++] = larray[i++];
    }

    while(j<c){
        array[k++] = rarray[j++];
    }


}


/**
 * mergesort
 * 
 * This is our mergesort algorithm, which uses the divide
 * and conquer approach. We break the array into two halves.
 * 
 * @param array, our array of strings we want to sort.
 * @param size, the size of our array
 * @param heighta, helps us determine the maximum depth of the tree.
 */
void mergesort(char** array, int size, int heighta){
    /*write code here*/
    if (size <2){
        return;
    } // <2 bc if its less than, its already sorted

    int newheight= heighta +1;

    int mid = size / 2; //midpoint of array then divide to two halfs

    char** larray = (char**)malloc(mid * sizeof(char*));
    char** rarray = (char**)malloc((size - mid) * sizeof(char*));

    for (int i = 0; i < mid; i++){
        larray[i] = array[i];
    }
    for (int i = mid; i < size; i++){
        rarray[i - mid] = array[i];
    }

    mergesort(larray, mid, heighta + 1); // Increase depth (heighta) for recursion
    mergesort(rarray, size - mid, heighta + 1);

    if(newheight>height){
        height = newheight;
    }

    merge(array, larray, rarray, size, mid, size - mid);

    if(heighta > height){
        height = heighta; //track the depth of the recursion
    }

    free(larray);
    free(rarray);
}

/**
 * This function will check if the array is sorted
 * @param array: The array of strings.
 * @param size: The size of the array.
 * @return 0 if array isn't sorted, 1 if sorted.
 */
char issorted(char** array, int size){
    for(int i = 1; i < size; i++){
        if(strcmp(array[i-1],array[i]) == 1){
            return 0;
        }
    }
    return 1;
}

int main(int argc, char** argv){
    /*write code here*/
    if (argc != 2){
        fprintf(stderr, "%s <filename>\n", argv[0]); //test case #6
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
        if (file == NULL){ //error opening certain file <- test case 7
        fprintf(stderr, "Error: Failed to open %s\n", argv[1]);
        return 1;
    }

    int size;
    if (fscanf(file, "%d\n", &size) != 1){
        fprintf(stderr, "Error: Cannot read size from input file.\n");
        fclose(file);
        return 1;
    }

    char** array = (char**)malloc(size * sizeof(char*)); //memory allocation
    if (array == NULL){
        perror("Error: allocating memory");
        fclose(file);
        return 1;
    }

    for (int i = 0; i < size; i++){
        char buffer[100];
        if (fgets(buffer, sizeof(buffer), file) != NULL){
            int lenth = str_len(buffer);
            if (buffer[lenth - 1] == '\n'){
                buffer[lenth - 1] = '\0';
            }
            array[i] = strdup(buffer);
        }else{
            perror("Error: reading string");
            fclose(file);
            return 1;
        }
    }

    fclose(file);

    mergesort(array, size, 0); //sorts array

    for (int i = 0; i < size; i++){ //print sorted array
        printf("%s\n", array[i]);
    }

    printf("height: %d\n", height);

    for (int i = 0; i < size; i++){
        free(array[i]);
    }
    free(array);

    return 0;
}