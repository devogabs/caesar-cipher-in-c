#include <stdio.h>


// This script will do one of two things: encrypt or decrypt a message using the Caesar cipher technique.
// The user will be prompted to choose between encryption and decryption, enter a message, and provide a shift value.
// The program will then output the encrypted or decrypted message accordingly.

void encrypt(char message[], int shift){
    for(int i = 0; message[i] != '\0'; i++){
        char letter = message[i];
        int offset;
        offset = letter + shift;
        if (offset > 126){
            offset = offset % 126;
            letter = letter + offset;
        }
        letter = offset;

        message[i] = letter;

    }
}


void decrypt(char message[], int shift){

    
    for(int i = 0; message[i] != '\0'; i++){
        char letter = message[i];
        int offset;
        offset = letter - shift;
        if (offset < 33){
            offset = 126 - (33 - offset);
         
        }
        letter = offset;

        message[i] = letter;
    }
}



int main(){

    char message[100];
    int shift, choice;
    printf("Choose an option:\n1. Encrypt\n2. Decrypt\n");
    scanf("%d", &choice);

    if(choice == 1){
        printf("Enter message to encrypt: ");
        scanf(" %[^\n]s", message); // read string with spaces
        printf("Enter shift value: ");
        scanf("%d", &shift);
        encrypt(message, shift);
        printf("Encrypted message: %s\n", message);

    } else if(choice == 2){
        printf("Enter message to decrypt: ");
        scanf(" %[^\n]s", message); // read string with spaces
        printf("Enter shift value: ");
        scanf("%d", &shift);
        decrypt(message, shift);
        printf("Decrypted message: %s\n", message);

    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}