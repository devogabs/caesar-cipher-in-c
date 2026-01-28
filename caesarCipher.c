#include <stdio.h>


// This script will do one of too things: encrypt or decrypt a message using the Caesar cipher technique.
// The user will be prompted to choose between encryption and decryption, enter a message, and provide a shift value.
// The program will then output the encrypted or decrypted message accordingly.

void encrypt(char message[], int shift){
    for(int i = 0; message[i] != '\0'; i++){
        char letter = message[i];
        // Encrypt uppercase letters
        if(letter >= 'A' && letter <= 'Z'){
            letter = letter + shift;
            if(letter > 'Z'){
                letter = letter - 'Z' + 'A' - 1; // does that even make sense?
            
            }
            message[i] = letter;
        
        // Encrypt lowercase letters
        } else if(letter >= 'a' && letter <= 'z'){
            letter = letter + shift;
            if(letter > 'z'){
                letter = letter - 'z' + 'a' - 1;

            }
            message[i] = letter;

        }
    }
}


void decrypt(char message[], int shift){

    for(int i=0; message[i] != '\0'; i++){
        char letter = message[i];    
        // Decrypt uppercase letters
        if (letter >= 'A' && letter <= 'Z'){
            letter = letter - shift;
            if(letter < 'A'){
                letter = letter + 'Z' - 'A' + 1;
            }
            message[i] = letter;
        }
        // Decrypt lowercase letters
        if (letter >= 'a' && letter <= 'z'){
            letter = letter - shift;
            if(letter < 'a'){
                letter = letter + 'z' - 'a' + 1;
            }
            message[i] = letter;
        }
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