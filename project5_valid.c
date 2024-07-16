// Anisha Hossain Megha (U43189731)
// Task 2 - this program prompts the user to enter input and determines if the input is a valid or invalid. 
// input characters are command line arguments.

#include <stdio.h>
#include <ctype.h>

int main(int argc, char **argv){

    int validity = 1; // assigning validity
    int i = 1;

    if(argc > 2) // validation happens if there are more than 2 arguments
        {// validating the input using nested loop
        while(argv[i] != NULL){
            int j = 0;
            while(argv[i][j] != '\0'){
                if (islower(argv[i][j]) || isdigit(argv[i][j]) || argv[i][j] == ' ' || argv[i][j] == '!' || argv[i][j] == '?' || argv[i][j] == '.'){
                }
                else if(isupper(argv[i][j])){
                    validity = 0;
                }
                else{
                    validity = 0;
                }
                j++;
                }
            i++;
        }
        // showcasing whether it is valid or not
        if(validity == 0){
            printf("invalid");
        }
        else{
            printf("valid");
        }
            }

    else if (argc <= 2) // showcasing message if number of arguments 2 or less
    {
        printf("invalid number of arguments");
    }

    return 0;
}