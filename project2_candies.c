// Anisha Hossain Megha (U43189731)
// This program produces a candy vending machine that accepts user input of quarters, dimes, and nickels (0 to stop). 
// After input, prompt the user to select Hershey’s Kisses (15 cents), Reese’s Peanut Butter Cups (25 cents), or Snickers (50 cents). 
// If the total amount is sufficient, provides change; if not, returns the money.

#include <stdio.h>

int main(){

int coins = 0; // to store total coins inserted
int user_coins; // user input of coins
int user_choice; // to store user choice of cndy selection
int change;

int nickel = 5;
int dime = 10;
int quarter = 25;

int kisses = 15; // price of Hershey’s kisses 
int cups = 25;  // price of Reese’s Peanut Butter Cups
int snickers = 50; // price of Snickers

do{
    printf("Insert coins: ");
    scanf("%d", &user_coins);
    if(user_coins == nickel || user_coins == dime || user_coins == quarter || user_coins == 0){
        coins += user_coins;
    }
    else{
        printf("Invalid");
        return 1;
    }
    
    }while(user_coins != 0); // while loop for storing coins inserted by user


printf("1 - Hershey's kisses (15 cents), 2 - Reese's Peanut Butter Cups  (25 cents), 3 - Snickers (50 cents)\n");
printf("Enter your choice:"); 
scanf("%d", &user_choice); // user choosing the candy

// Processing and validating the choice
switch (user_choice){
    case 1:
    if(coins >= kisses){
        change = coins - kisses;
        printf("Your change is %d cents", change);
    }
    else{
        printf("Insufficient amount, %d cents returned", coins);
    }
    break;

    case 2:
    if(coins >= cups){
        change = coins - cups;
        printf("Your change is %d cents", change);
    }
    else{
        printf("Insufficient amount, %d cents returned", coins);
    }
    break;

    case 3:
    if(coins >= snickers){
        change = coins - snickers;
        printf("Your change is %d cents", change);
    }
    else{
        printf("Insufficient amount, %d cents returned", coins);
    }
    break;

    default:
    printf("Invalid selection, %d cents returned\n", coins);
            break;
}


return 0;
}