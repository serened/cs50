#include <stdio.h>
#include <cs50.h>

int main(void)  
{    
    int height;  
    do
    {  
        printf("Height: ");
        height = GetInt();
    } while (height<1 || height>23);

    //row[0] = 7 spaces, 2 hashes
    //row[1] = 6 spaces, 3 hashes
    //row[2] = 5 spaces, 4 hashes
    //any row, n+2 hashes
    //any row, remaining_height-1

    for (int i = 0; i < height; i++)
    {
        printf("%.*s", height-i, "                           ");
        printf("%.*s", i+2, "###########################");
        printf("\n");
    }
    
    return 0;   
}
