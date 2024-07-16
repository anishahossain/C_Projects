// Anisha Hossain Megha (U43189731)
// Task 1 - This program assigns students to different teams based on their accumulated points.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to assign teams
void assign(int *points, int *team_assignments, int n) 
{

    int i = 0;
    while(i < n)
    {
    // dividing the points to appropriate ranges
        int begginer_range = abs(*points - 25);
        int honor_range = abs(*points - 70);
        int exc_range = abs(*points - 125);

    // beginner = 1, honor = 2, excellence = 3
        if((begginer_range < honor_range) && (begginer_range < exc_range))
        {
            *team_assignments = 1;
        }
        else if((honor_range < begginer_range) && (honor_range < exc_range))
        {
            *team_assignments = 2;
        }
        else if((exc_range < begginer_range) && (exc_range < honor_range))
        {
            *team_assignments = 3;
        }
        i++;
        points++;
        team_assignments++;
    }
        
}

// main function
int main(){

    int n; // number of students

    printf("Enter number of students: ");
    scanf("%d", &n);

    int points[n]; // points of each student
    int team_assignments[n]; // student assignment
    int *pPoints = &points[0]; // pointer for array points
    int *pTeams = &team_assignments[0]; // pointer for array team_assignments

    // storing number of points for each student using while loop
    printf("Enter points for each student: ");
    int i = 0;
    while(i < n)
    {
        scanf("%d", pPoints + i);
        i++;
    }
    
    assign(pPoints, pTeams, n); // call to function

    // printing student number based on assignment using loops
    printf("Beginner team: student");
    for(int j = 0; j < n; j++)
    {
        if(*(pTeams + j) == 1)
        {
           printf(" %d", j+1);
        }
    }

    printf("\nHonor team: student");
    for(int j = 0; j < n; j++)
    {
        if(*(pTeams + j) == 2)
        {
           printf(" %d", j+1);
        }
    }

    printf("\nExcellence team: student");
    for(int j = 0; j < n; j++)
    {
        if(*(pTeams + j) == 3)
        {
           printf(" %d", j+1);
        }
    }

return 0;
}