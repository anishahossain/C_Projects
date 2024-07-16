// Anisha Hossain Megha (U43189731)
// Task -  project8_volunteer.c modified so that a volunteer can be deleteded from the list.
// program - Prompts the user to enter an operation code, then calls a function to perform the requested action of 
// adding volunteer data at last, printing all the volunteer data or searching for volunteers in a grade level or deleting a volunteer from the list


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define EMAIL_LEN 100
#define NAME_LEN 30

struct volunteer{
	char first[NAME_LEN+1];
	char last[NAME_LEN+1];
	char email[EMAIL_LEN+1];
	int grade_level;
	struct volunteer *next;
};


struct volunteer *add_to_list(struct volunteer *list);
struct volunteer *delete_from_list(struct volunteer *list);
void search_list(struct volunteer *list);
void print_list(struct volunteer *list);
void clear_list(struct volunteer *list);
int read_line(char str[], int n);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
  char code;

  struct volunteer *volunteer_list = NULL;  
  printf("Operation Code: a for adding to the list, s for searching"
	  ", d for deleting from the list, p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': volunteer_list = add_to_list(volunteer_list);
                break;
      case 's': search_list(volunteer_list);
                break;
      case 'p': print_list(volunteer_list);
                break;
      case 'd': volunteer_list = delete_from_list(volunteer_list);
                break;
      case 'q': clear_list(volunteer_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}

// function to add the volunteer to the end of the linked list.
struct volunteer *add_to_list(struct volunteer *list){ 
  // getting data from user
  char last_name[NAME_LEN+1]; // array storing first name
  char first_name[NAME_LEN+1]; // array storing last name
  char email[EMAIL_LEN+1]; // array storing email
  int gradelvl; // variable storing grade level

  printf("Enter last name: ");
  read_line(last_name, NAME_LEN+1);
  printf("Enter first name: ");
  read_line(first_name, NAME_LEN+1);
  printf("Enter email address: ");
  read_line(email, EMAIL_LEN+1);
  printf("Enter grade level: ");
  scanf("%d", &gradelvl);

  struct volunteer *check; // checking if volunteer already exists using a temporary pointer
  for(check = list; check != NULL; check = check->next){
    if((strcmp(check->last,last_name) == 0) && (strcmp(check->email,email) == 0)){
    printf("volunteer already exists.\n");
    return list;
    }
  }

  struct volunteer* new = malloc(sizeof(struct volunteer)); // allocating size for new volunteer data
  // adding volunteer data to linked list
  strcpy(new->last, last_name);
  strcpy(new->first, first_name);
  strcpy(new->email, email);
  new->grade_level = gradelvl;
  
  if(list == NULL){
    return new;
  } 
  struct volunteer *p = list;
  while(p->next != NULL){
    p = p->next;
  }
  new->next = NULL;
  p->next = new; // adding it to end
  return list; // returning updated list
}

// function to find volunteers by grade level
void search_list(struct volunteer *list){
  int grade;
  int is_there = 0;
  printf("Enter grade level: ");
  scanf("%d", &grade); // getting grade level from user

  // Loop to check if grade level is there in the list
    struct volunteer *q = list;
    while (q != NULL) {
        if (q->grade_level == grade) {
            is_there = 1;
            printf("%-12s%-12s%-30s\n", q->last, q->first, q->email);
        }
        q = q->next;
    }

    // Printing the appropriate message if grade level exists or not
    if (is_there == 0) {
        printf("not found\n");
    }
  
}

// function to print the last name, first name, email, and grade level of all the volunteers
void print_list(struct volunteer *list){
  struct volunteer *p = list;
  while(p != NULL){
    printf("%-12s%-12s%-30s%5d\n", p->last, p->first, p->email, p->grade_level);
    p = p->next;
  }

}

// function to deallocate all the memory allocated for the linked list
void clear_list(struct volunteer *list)
{
  struct volunteer *p = list;
  while(p != NULL){
    struct volunteer *temp = p;
    p = p->next;
    free(temp);
  }

}

//function to delete from the list
struct volunteer *delete_from_list(struct volunteer *list){
  // getting data from user
  char last_name[NAME_LEN+1]; // array storing first name
  char first_name[NAME_LEN+1]; // array storing last name
  char email[EMAIL_LEN+1]; // array storing email
  int gradelvl; // variable storing grade level

  printf("Enter last name: ");
  read_line(last_name, NAME_LEN+1);
  printf("Enter first name: ");
  read_line(first_name, NAME_LEN+1);
  printf("Enter email address: ");
  read_line(email, EMAIL_LEN+1);
  printf("Enter grade level: ");
  scanf("%d", &gradelvl);

  struct volunteer *previous = NULL;
  struct volunteer *current = list;

  //traversing through list to find node location of volunteer being deleted
  while (current != NULL)
  {
    if (strcmp(current->last, last_name) == 0 &&
        strcmp(current->first, first_name) == 0 &&
        strcmp(current->email, email) == 0 &&
        current->grade_level == gradelvl)
    {
      break;
    }
    previous = current;
    current = current->next;
  }

  //if volunteer dose not exist
  if(current == NULL){
    printf("volunteer does not exist");
    return list;
  }

  // if volunteer being deleted is at beginning
  else if(previous == NULL){
    list = list->next;
    free(current);
    return list;
  }

  else{
  previous->next = current->next;
    }
  free(current);
  return list;
  // returning updated list 
}

// function to read in string
int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  str[i++] = ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;
    
   }
   str[i] = '\0';
   return i;
}
