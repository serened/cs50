#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//goal: encrypt a string using ceasar cipher
//rule: non-negative integer will determine key
//rule: case must be preserved
//equation: Ci = (Pi + k) % 26 (p is plain text message, i is index position, k is key, c is character)
//first: user passes command-line argument for key
//then: get a string from user to encipher
//last: print enciphered string back

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Wrong!\n");
        return 1;
    }
    else
    {   
        int k = atoi(argv[1]);
        string p = GetString();
        
        if (p != NULL)
        {
            for (int i = 0, n = strlen(p); i < n; i++)
            {
                char enciphered[i];
                if (isupper(p[i])) 
                    enciphered[i] = (p[i] - 'A' + k) % 26 + 'A';
                else if (islower(p[i])) 
                    enciphered[i] = (p[i] - 'a' + k) % 26 + 'a';
                else
                    enciphered[i] = p[i];
                printf("%c", enciphered[i]);
            }
            printf("\n");
        }
    }
}
 
