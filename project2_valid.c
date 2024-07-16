// Anisha Hossain Megha (U43189731)
// this program prompts the user to enter input and determines if the input is a valid or invalid.

#include <stdio.h>
#include <ctype.h>

int main(){

    char user_input; // stores input by user
    int validity = 1; // assigning validity

    printf("Enter input:");

    // validating the input
    while((user_input = getchar()) != '\n'){
        if (islower(user_input) || isdigit(user_input) || user_input == ' ' || user_input == '!' || user_input == '?' || user_input == '.'){
        }
        else if(isupper(user_input)){
            validity = 0;
        }
        else{
            validity = 0;
        }
    }

    // showcasing whether it is valid or not
    if(validity == 0){
        printf("invalid");
    }
    else{
        printf("valid");
    }


    return 0;
}