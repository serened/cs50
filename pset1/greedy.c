#include <stdio.h>
#include <cs50.h>
#include <math.h>

//goal: use as few coins as possible in giving change, start with largest coins
//first: get user input for an amount of change and convert to cents
//next: always use largest coin possible
//next: keep track of coins used
//last: print number of coins

int main(void)  
{    
    float change;
    printf("How much change is owed?\n");
    change = GetFloat();  
    
    if (change<.01)
    { 
      printf("Try again. Change needs to be at least one penny.\n");
      change = GetFloat();
    }
    
    int change_converter = round(change*100);
    
    //debugging
    printf("%d total amount coming back in change\n",change_converter);
    
    int coin_count = 0;
    
    //quarter count
    while (change_converter >= 25)
    {
        change_converter -= 25;
        coin_count ++;
    }
    
    //dime count
    while (change_converter >= 10)
    {
        change_converter -= 10;
        coin_count ++;
    }
    
    //nickel count
    while (change_converter >= 5)
    {
        change_converter -= 5;
        coin_count ++;
    }
    
    //penny count
    while (change_converter >= 1)
    {
        change_converter -= 1;
        coin_count ++;
    }
    
    printf("%d\n",coin_count);
    
    return 0;   
 }
    
