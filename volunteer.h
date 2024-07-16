// Anisha Hossain Megha (U43189731)
// header file for project 10 

#ifndef VOLUNTEER_H //protecting header file using an #ifndef-#endif pair
#define VOLUNTEER_H

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

#endif