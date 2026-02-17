#include <stdio.h>
#include <stdlib.h>

void savePassword() {
    FILE *fp = fopen("passwords.txt", "a");

    char website[50], username[50], password[50];

    printf("\nEnter Website Name: ");
    scanf("%s", website);

    printf("Enter Username: ");
    scanf("%s", username);

    printf("Enter Password: ");
    scanf("%s", password);

    fprintf(fp, "\nWebsite: %s | Username: %s | Password: %s", website, username, password);

    fclose(fp);

    printf("\nPassword Saved Successfully!\n");
}

void viewPasswords() {
    FILE *fp = fopen("passwords.txt", "r");
    char ch;

    if(fp == NULL) {
        printf("\nNo Records Found!\n");
        return;
    }

    printf("\n--- Saved Passwords ---\n");

    while((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }

    fclose(fp);
}

int main() {
    int choice;

    while(1) {
        printf("\n\n===== PASSWORD MANAGER =====");
        printf("\n1. Save Password");
        printf("\n2. View Passwords");
        printf("\n3. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: savePassword(); break;
            case 2: viewPasswords(); break;
            case 3: exit(0);
            default: printf("Invalid Choice!");
        }
    }
}
