// Anisha Hossain Megha (U43189731)
// Task 1 - program to decrypt a message that is encrypted. 
// In the encrypted message the first character is written once, second character twice, third character three times, .., and mth character m times.
// program decrypts message so that each character is written once.

#include <stdio.h>

void decrypt(char *input, char *output){

    char *p = input; // pointer to (first char of) array input
    char *o = output; // pointer to output
    int j = 0;
    int i = 2;

    *o = *p; // setting first char of output to first char of input

    // loop for decryption and adding decrypted characters to output
    while(*(p + j + i) != '\0'){ 
        *(o + 1) = *(p + j + i);
        o++;
        j = j + i;
        i++;
    }
    *(o + 1) = '\0'; // adding null character at end

}

int main(){
    char input[1000]; // array for inout by user
    printf("Enter message: "); 
    scanf("%s", input); // storing input to array
    char output[1000]; // array for storing decrypted message
    decrypt(input, output); // call to function
    printf("Output: %s", output);


    return  0;
}