#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int check(int argc , string key);
void encrypt(string key);

int main(int argc, string argv[])
{
    //check argc (must ahead of check())
    //if put argc check in check() , when no argument , argv[1] is not exist
    if(argc != 2){
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if(check(argc,argv[1]) < 0){
        printf("Key must contain 26 characters\n");
        return 1;
    }
    encrypt(argv[1]);
}

int check(int argc , string key){
    int len = strlen(key);
    //check length
    if(len != 26){
        return -1;
    }
    //check character
    int alphabetic[26] = {0}; //store the apperance times of each character
    for(int i = 0; i < len; i++){
        if((key[i] >= 'a' && key[i] <= 'z')){
            if(alphabetic[key[i] - 97] == 0){
                alphabetic[key[i] - 97]++;
            }
            else{
                return -2;
            }
        }
        else if((key[i] >= 'A' && key[i] <= 'Z')){
            if(alphabetic[key[i] - 65] == 0){
                alphabetic[key[i] - 65]++;
            }
            else{
                return -2;
            }
        }
        else{
            return -3;
        }
    }
    return 1;
    /*
    return 1 -- OK
    return -1 -- length != 26
    return -2 -- repeat character
    return -3 -- contain not alphabetic character
    no need to distinguish between different return values ,
    but this will help to better determine the cause of the error
    */
}

void encrypt(string key){
    string plaintext = get_string("plaintext:  ");
    int i = 0;
    while(plaintext[i] != '\0'){
        if(islower(plaintext[i])){
            plaintext[i] = tolower(key[plaintext[i] - 97]); // Modify directly on plaintext[i]
        }
        else if(isupper(plaintext[i])){
            plaintext[i] = toupper(key[plaintext[i] - 65]);
        }
        i++;
    }
    printf("ciphertext: %s\n", plaintext); // plaintext is now turned into ciphertext
}
