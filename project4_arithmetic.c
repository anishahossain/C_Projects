// Anisha Hossain Megha (U43189731)
// Task 2 - program that determines if a sequence is an arithmetic sequence

#include <stdio.h>

// function to determine whether sequence is arithmetic or not
int is_arithmetic_sequence(int *sequence,  int n){
    int is_sequence = 1;
    int i = 0;
    while(i  < n  - 2){
        if((*(sequence + 1) - *sequence) != (*(sequence + 2) - *(sequence + 1))){
            is_sequence = 0;
        }
    i++;
    sequence++;
    }
    return is_sequence;
}

int main(){

    int n;
    printf("Enter length of the sequence: ");
    scanf("%d", &n);

    int sequence[n]; // array storing sequence
    int *p = &sequence[0]; // pointer for array sequence

    printf("Enter numbers of the sequence: ");
        // storing input numbers into array using while loop
        int i = 0;
        while(i < n)
        {
            scanf("%d", p + i);
            i++;
        }

    int is_true = is_arithmetic_sequence(p, n); // call to function

    // printing yes if it is an arithmetic sequence and no if it is not
    if(is_true){
        printf("yes");
    }
    else{
        printf("no");
    }

    return 0;
}