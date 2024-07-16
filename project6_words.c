// Anisha Hossain Megha (U43189731)
// Task - program checks each word stored in a file, if it is some string written twice in a row.
// Program will first ask the user to enter the file name, open and read the file, then write the words that are some strings written twice in a row to the output file. 

#include <stdio.h>
#include <string.h>

// function to check if word in file is a string written twice
int is_square(char *word){
    int number = strlen(word); // how many letters in word
    int middle = number/2;
    int j = middle;
    int true = 1; // variable to store if true or false that word is string written twice
    if(number%2 == 0){
        for(int i = 0; i < middle; i++){ // loop to compare
            if (word[i] == word[j]){
                j++;
            }
            else{
                true = 0;
                break;
            }
        }
    }
    
    else if (number%2 == 1){
        for(int i = 0; i <= middle; i++){ // loop to compare
            if (word[i] == word[j]){
                j++;
            }
            else{
                true = 0;
                break;
            }
        }
    }
    return true; 
}

int main(){

printf("Enter file name: ");
char filename[101];
scanf("%s", filename); // getting file name from user

FILE *fp = fopen(filename, "r"); // opening input file for reading
char input[101]; // buffer array to store input file words
int n = 0;
char input_words[1001][101]; // buffer array to store all input file words

while((fscanf(fp, "%s", input)) != EOF){ // storing words from file into buffer array
    strcpy(input_words[n], input);
    n++;
}

char output[1001][101]; // array for storing strings written twice
int j = 0;
int square;
for(int i = 0; i < n; i++){
    square = is_square(input_words[i]); // call to fucntion for each word
    if (square == 1){
        strcpy(output[j], input_words[i]); // storing output words
        j++;
    }
}

FILE *op; 
op = fopen("output.txt", "w"); // creating output file to erite into words which are strings written twice
for(int k = 0; k < j; k++){
    fprintf(op, "%s\n", output[k]); // storing from buffer array to output file
}


fclose(fp); // closing input file
fclose(op); // closing output file
    return 0;
}