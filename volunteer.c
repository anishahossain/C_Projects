// Anisha Hossain Megha (U43189731)
// source file for project 10

#include "volunteer.h"
#include "read_line.h"

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