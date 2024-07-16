// Anisha Hossain Megha (U43189731)
// This program calculates the total cost of event packages, considering the package selection, 
// number of guests, and event duration. 

#include <stdio.h>

int main(){

    int first_hour[] = {150, 180, 200}; // first hour cost for the events
    int hourly[] = {100, 120, 150}; // hourly cost for the events
    int max_chrge[] = {595, 850, 1050}; // maximum charge for each package
    int per_person[] = {25, 22, 20}; // cost per person for food  for each package 

    int selection; // to store user selection 
    int hours; // to store user hours
    int guests; // to store number of guests
    int hourly_charge; // hourly charge per package 
    int total_people; // total charge for number of guests
    int total; // total charge

    printf("Please select from three packages: 1, 2, and 3\n");
    printf("Enter package selection:");
    scanf("%d", &selection);

// validation of selection 
    if(selection <= 0 || selection >= 4){
        printf("Invalid selection.\n");
        return 1;
    }
    else{
        printf("Enter hours:");
        scanf("%d", &hours);
    }

// validation for hours
    if (hours < 1 || hours > 4){
        printf("Invalid hours.");
        return 1;
    }
    else{
        printf("Enter the number of guests: ");
        scanf("%d", &guests);
    }


// calculation for each package
    switch (selection){
        case 1:
        // validation for input of number of guests for package 1
            if(guests < 5 || guests > 20){
                printf("Invalid number of guests.");
                return 1;}
            else{
                // calculation for package 1
                hourly_charge = first_hour[0] + ((hours - 1) * hourly[0]);
                total_people = guests * per_person[0];
                total = hourly_charge + total_people;
                    if(total > max_chrge[0])
                    {
                        total = max_chrge[0];
                    }
                }
            break;

        case 2:
        // validation for input of number of guests for package 2
            if(guests < 8 || guests > 30){
                printf("Invalid number of guests.");
                return 1;}
            
            else{
                // calculation for package 2
                hourly_charge = first_hour[1] + ((hours - 1) * hourly[1]);
                total_people = guests * per_person[1];
                total = hourly_charge + total_people;
                    if(total > max_chrge[1])
                    {
                        total = max_chrge[1];
                    }
                }
            break;

        case 3:
        // validation for input of number of guests for package 3
            if(guests < 10 || guests > 40){
                printf("Invalid number of guests.");
                return 1;}

            else{
                // calculation for package 3
                hourly_charge = first_hour[2] + ((hours - 1) * hourly[2]);
                total_people = guests * per_person[2];
                total = hourly_charge + total_people;
                    if(total > max_chrge[2])
                    {
                        total = max_chrge[2];
                    }
                }
            break;         
                                        
                }

        printf("Charge($): %d\n", total); // printing total amount
        
    return 0;
}