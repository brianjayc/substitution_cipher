#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int check_key(string key)
{
    if (strlen(key) < 26 || strlen(key) > 26) // check if key contains 26 characters return error if not
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < strlen(key); i++) // iterate over each character of key then
    {
        if (!isalpha(key[i]))     // check if current character is a non alphabet character. return error if it is
        {
            printf("Key must only contain alphabet characters.\n");
            return 1;
        }

        for (int j = i + 1; j < strlen(key); j++) // iterate over the suceeding characters and check if its a duplicate of the current character. return error if it is.
        {
            if (key[i] == key[j])
            {
                printf("Key must not contain duplicates.\n");
                return 1;
            }
        }
    }

    return 0;
}

string encipher_text(string plain_text, string key)
{
    int ch = 0;  // initialize helper variable to store ascii equivalent of char

    for (int i = 0; i < strlen(plain_text); i++)  //iterate over plain text and subsitute the equivalent cipher character
    {
        if (isupper(plain_text[i]))   // if current char is upper case then
        {
            ch = plain_text[i]; //get ascii equivalent of char
            plain_text[i] = toupper(key[ch - 65]); //get equivalent cipher character by subtracting 65 to the ascii equivalent of current character to get key index, then convert to upper case
        }
        else if (islower(plain_text[i])) // if current char is lower case then
        {
            ch = plain_text[i]; //get ascii equivalent of char
            plain_text[i] = tolower(key[ch - 97]); //get equivalent cipher character by subtracting 97 to the ascii equivalent of current character to get key index, then convert to lower case
        }
    }

    return plain_text; // return plain text converted to cipher text
}

int main(int argc, string argv[])
{
    if (argc != 2) // quit if there is more than one command line argument or none
    {
        printf("Invalid command usage. Usage: substitution key\n");
        return 1;
    }

    string key = argv[1]; // get key from command line argument

    if (check_key(key)) // check key if valid return 1 if not
    {
        return 1;
    }

    string plain_text = get_string("plaintext: "); // get plain text from user

    string cipher_text = encipher_text(plain_text, key); // encipher plain text.

    printf("ciphertext: %s\n", cipher_text); // print cipher text.

    return 0;
}
