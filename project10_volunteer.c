// Anisha Hossain Megha (U43189731)
// Task - project9_volunteer.c modified so so the program is split into two source files and one header file.
// program - Prompts the user to enter an operation code, then calls a function to perform the requested action of 
// adding volunteer data at last, printing all the volunteer data or searching for volunteers in a grade level or deleting a volunteer from the list

// this file contains the main function

#include "volunteer.h" // header file for vounteer source code
#include "read_line.h" // header file for readline function

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