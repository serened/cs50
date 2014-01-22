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
    else
    {   
        char* k = argv[1];
        char* code;
        
        //testing arg[1] to make sure key is alphabetical
        for (int j = 0, n = strlen(k); j < n; j++)
        {
            if (!isalpha(k[j]))
            {
                printf("You can only use letters.\n");
                return 1;
            }
            else
                code = argv[1];             
        }
        
        //get the message to encipher 
        //printf("Ciphertext: ");
        string p = GetString();
        
        if (p != NULL)
        {
            //printf("Plaintext: ");
            for (int i = 0, j = 0, n = strlen(p); i < n; i++)
            {
                char enciphered[i];
                if (isupper(p[i])) 
                    enciphered[i] = (p[i] - 'A' + (code[j] - 'A')) % 26 + 'A';
		        else if (islower(p[i])) 
		            enciphered[i] = (p[i] - 'a' + (code[j] - 'a')) % 26 + 'a';
		        else
		            enciphered[i] = p[i];
		        printf("%c", enciphered[i]);
            }
            printf("\n");
        }
    }
}
