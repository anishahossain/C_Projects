// Anisha Hossain Megha (U43189731)
// Task - project 7 modified so that it uses quick sort fucntion to sort the school supplies
// program reads in the data (a list of supplies in random order) from input file and writes the search result to the output file. 
// The user will enter the name of the supply for searching. The result output file will include all supplies with name that exactly matches the name being searched.  


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct supplies{
    char name[100];
    char color[100];
    int quantity;
};

void read_line(char* array, int n){
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
}



int compare(const void *supply1, const void *supply2){
    const struct supplies *p = supply1;
    const struct supplies *q = supply2;

    // comparing by name 
    int comparison = strcmp(p->name, q->name);
    if (comparison != 0){
        return comparison;
    }

    // if names are same then compare by color
    return strcmp(p->color, q->color);
}

int main(){

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

    
    // sorting the supplies
    qsort(list, n, sizeof(struct supplies), compare);

    fclose(fp); // closing input file

    FILE *fp2 = fopen("result.csv", "w"); //output file

    int i = 0;
    while(i < n)// putting sorted list in output file
    {
        fprintf(fp2, "%s, %s, %d\n", list[i].name, list[i].color, list[i].quantity);
        i++;
    }

    fclose(fp2); // closing output file 

    return 0;

}
