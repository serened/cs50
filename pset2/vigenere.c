#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//goal: encrypt a string using vigenere cipher
//rule: string will be key, must be alphabetical
//rule: case must be preserved
//equation: Ci = (Pi + kj) % 26 (p is plain text message, i is index position, k is key, c is character)
//first: get the key
//then: convert the key
//then: get a string from user to encipher
//last: print enciphered string back

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Wrong! Try again\n");
        return 1;
    }
    
    char* k = argv[1];
    int size = strlen(k);
    int key_cipher[size];
    
    // testing arg[1] to make sure key is alphabetical
    for (int j = 0; j < size; j++)
    {
        if (!isalpha(k[j]))
        {
            printf("You can only use letters.\n");
            return 1;
        }
        else
        {
            key_cipher[j] = (tolower(k[j]) - 'a');            
        }
    }

    string p = GetString();
    
    if (p != NULL)
    {
        for (int i = 0, j= 0, n = strlen(p); i < n; i++)
        {
            char enciphered;
            if (isupper(p[i])) 
            {
                enciphered = (p[i] - 'A' + key_cipher[j]) % 26 + 'A';
                j++;
            }
            else if (islower(p[i])) 
            {
                enciphered = (p[i] - 'a' + key_cipher[j]) % 26 + 'a';
                j++;
            }
            else
            {
                enciphered = p[i];
            }
            j = j % size;
            printf("%c", enciphered);
        }
        printf("\n");
    }
    return 0;
}
