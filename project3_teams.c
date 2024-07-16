// Anisha Hossain Megha (U43189731)
// This program assigns students to different teams based on their accumulated points.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to ssign teams
void assign(int points[], int team_assignments[], int n) 
{
    for(int i = 0; i < n; i++)
    {
        int begginer_range = abs(points[i] - 25);
        int honor_range = abs(points[i] - 70);
        int exc_range = abs(points[i] - 125);

    // beginner = 1, honor = 2, excellence = 3
        if((begginer_range < honor_range) && (begginer_range < exc_range))
        {
            team_assignments[i] = 1;
        }
        else if((honor_range < begginer_range) && (honor_range < exc_range))
        {
            team_assignments[i] = 2;
        }
        else if((exc_range < begginer_range) && (exc_range < honor_range))
        {
            team_assignments[i] = 3;
        }
    }
        
}

// main function
int main(){

    int n; // number of students

    printf("Enter number of students: ");
    scanf("%d", &n);

    int points[n]; // points of each student
    int team_assignments[n]; // student assignment

    // storing number of points for each student
    printf("Enter points for each student: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &points[i]);
    }
    
    assign(points, team_assignments, n); // call to function

    // printing student number based on assignment
    printf("Beginner team: student");
    for(int i = 0; i < n; i++)
    {
        if(team_assignments[i] == 1)
        {
           printf(" %d", i+1);
        }
    }

    printf("\nHonor team: student");
    for(int i = 0; i < n; i++)
    {
        if(team_assignments[i] == 2)
        {
           printf(" %d", i+1);
        }
    }

    printf("\nExcellence team: student");
    for(int i = 0; i < n; i++)
    {
        if(team_assignments[i] == 3)
        {
           printf(" %d", i+1);
        }
    }

return 0;
}