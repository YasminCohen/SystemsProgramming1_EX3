#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LEN 50 
/*Declaration of the functions*/
int shift_element(int* arr, int i);
int insertion_sort(int* arr, int len);

int main() {
    int size = 0;
    int capacity = 10;
    int *numbers = malloc(capacity * sizeof(int));
    if (numbers == NULL) {
        fprintf(stderr, "Error: out of memory\n");
        exit(1);
    }

    while (scanf("%d", &numbers[size]) == 1 && ++size < LEN) { // scan 50 numbers to the array
        if (size == capacity) {
            capacity *= 2;
            numbers = realloc(numbers, capacity * sizeof(int));

            if (numbers == NULL) {
                fprintf(stderr, "Error: out of memory\n");
                exit(1);
            }
        }
    }

    insertion_sort(numbers,size);
    for(int j=0; j<size-1;j++)
    {
        printf("%d,",*(numbers+j));
    }
    printf("%d\n",*(numbers+size-1));
    free(numbers);
    return 0;
}
/*
shift_element function:
this function gets pointer to array of integers, and integer number i.
the function move the next i organs one step to the right
-for loop, arr[j] equal to arr[j-1](move one step right)
-arr[0] equal to n 
*/  
int shift_element(int *arr, int i) { 
    int n = *(arr + i);
    for (int j = i; j > 0; j--) {
        *(arr + j) = *(arr + j - 1);
    }
    *arr = n;
    return 0;
}

/*
Insertion_sort function:
-two for loop:
-the first for loop run from i=1 -> array size
-the second for loop run from j=i-1 -> 0
-new pointer: *ptr=arr+j 
-check if ptr>*(arr+i) : 
(count ++) && (ptr --) ...if j=0 -> move from ptr+1 size of count numbers(use shife_element function) , break
-else, move from ptr+1 size of count numbers(use shife_element function) , break 
*/ 
int insertion_sort(int* arr, int len){
    int count = 0;
    for(int i=1; i<len; i++){
        for(int j=i-1; j>=0; j--)
        {
            int *ptr=arr+j;
            if(*ptr>*(arr+i)){
                count++;
                ptr --;
                if(j==0){
                    shift_element((ptr+1),count);
                    count = 0;
                    break;
                }
            }
            else{
                shift_element((ptr+1),count);
                count = 0;
                break;
            }
        }
    }
    return 0;
}
