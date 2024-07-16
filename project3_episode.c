// Anisha Hossain Megha (U43189731)
// This program prints the episode that Yuka hasn’t watched. 
// The program reads in the number of episodes n in the season, and episodes that she has watched.

#include <stdio.h>
int main(){

    int num_episode = 0; // total number of episodes
    int not_missing;
    int missing_episode;

    printf("Enter number of episodes: ");
    scanf("%d", &num_episode);

    int episodes_watched[num_episode - 1]; // to store the number of epsodes she has watched

    printf("Enter episodes watched: ");

    // to store each episode number entered into the array
    for(int i = 0; i < (num_episode - 1); i++) 
    {
        scanf("%d", &episodes_watched[i]);
    } 

    // to find missing episode number
    for(int j = 1; j <= num_episode; j++)
    {   
        not_missing = 0;
        for(int i = 0; i < num_episode; i++)
        {
        if(episodes_watched[i] == (j))
        {
            not_missing = 1;
            break; 
            // if number is present loop breaks and not_missing = 0 again
        }
        }
        if (!not_missing) // !not_missing means not_missing is false (value 0)
        {
            missing_episode = j;
            break;
        }
    }
    printf("Missing episode: %d", missing_episode);
    
    return 0;
}