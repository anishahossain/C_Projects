// Anisha Hossain Megha (U43189731)
// Task - program reads in the data (a list of supplies in random order) from input file and writes the search result to the output file. 
// The user will enter the name of the supply for searching. The result output file will include all supplies with name that exactly matches the name being searched.  


#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct supplies{
    char name[100];
    char color[100];
    int quantity;
};

// STUDY AND WRITE READLINE
int read_line(char* array, int n){
    int ch, i = 0;
    char *str = array;
    while(isspace(ch = getchar())); // skipping initial whitespace
    *(str++) = ch;
    i++;
    
    while((ch = getchar()) != '\n' && i < n){
        *str = ch;
        str++;
        i++;}
    *str = '\0'; //adding null at end
    return i; // returning number of characters in str
}

int search(struct supplies list[], int n, struct supplies result[], char *search_name) // function to search for item
{
    struct supplies *pL = list;
    struct supplies *pR = result;
    int matches = 0;
    while(pL < list + n) // looking through supply list and storing matches to result
    {
        if(strcmp(search_name, pL->name) == 0){
            strcpy(pR->name, pL->name);
            strcpy(pR->color, pL->color);
            pR->quantity = pL->quantity;
            pL++;
            pR++;
            matches++;
        }
        else{
            pL++;
        }
    }
    return matches; // reurning number of matches
}

int main(){

    printf("Enter supply: ");
    char search_name[100]; // name of supply searched for
    int size = read_line(search_name, 100); // number of characters in supply name

    FILE *fp;
    fp = fopen("supply.csv", "r");
    if(fp == NULL){
        printf("File does not exist");
    }

    struct supplies list[200]; // struct buffer array to store all the items from file
    int n = 0; // number of supply items 

    while(!feof(fp)){
        fscanf(fp, "%[^,], %[^,], %d\n", list[n].name, list[n].color, &list[n].quantity); // storing from file to buffer array
        n++;}
    
    struct supplies result[n]; // to hold the items in supply list that matches with search name
    struct supplies *pResult;
    int matches = search(list, n, result, search_name);

    pResult = result;
    

    fclose(fp);

    FILE *fp2 = fopen("result.csv", "w"); //output file
    while(pResult < result + matches)// putting the mtches in output file
    {
        fprintf(fp2, "%s, %s, %d\n", pResult->name, pResult->color, pResult->quantity);
        pResult++;
    }

    fclose(fp2);

    return 0;

}
