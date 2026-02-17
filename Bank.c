#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
    int acc_no;
    char name[50];
    float balance;
};

struct account acc[100];
int count = 0;

void createAccount() {
    printf("\nEnter Account Number: ");
    scanf("%d", &acc[count].acc_no);

    printf("Enter Name: ");
    scanf(" %[^\n]", acc[count].name);

    printf("Enter Initial Balance: ");
    scanf("%f", &acc[count].balance);

    count++;
    printf("\n✅ Account Created Successfully!\n");
}

void deposit() {
    int num;
    float amount;
    printf("\nEnter Account Number: ");
    scanf("%d", &num);

    for(int i=0; i<count; i++) {
        if(acc[i].acc_no == num) {
            printf("Enter Amount to Deposit: ");
            scanf("%f", &amount);
            acc[i].balance += amount;
            printf("✅ Deposit Successful!\n");
            return;
        }
    }
    printf("❌ Account Not Found!\n");
}

void withdraw() {
    int num;
    float amount;
    printf("\nEnter Account Number: ");
    scanf("%d", &num);

    for(int i=0; i<count; i++) {
        if(acc[i].acc_no == num) {
            printf("Enter Amount to Withdraw: ");
            scanf("%f", &amount);

            if(amount <= acc[i].balance) {
                acc[i].balance -= amount;
                printf("✅ Withdrawal Successful!\n");
            } else {
                printf("❌ Insufficient Balance!\n");
            }
            return;
        }
    }
    printf("❌ Account Not Found!\n");
}

void checkBalance() {
    int num;
    printf("\nEnter Account Number: ");
    scanf("%d", &num);

    for(int i=0; i<count; i++) {
        if(acc[i].acc_no == num) {
            printf("\nName: %s", acc[i].name);
            printf("\nBalance: %.2f\n", acc[i].balance);
            return;
        }
    }
    printf("❌ Account Not Found!\n");
}

void displayAll() {
    printf("\n--- All Accounts ---\n");
    for(int i=0; i<count; i++) {
        printf("\nAccount No: %d", acc[i].acc_no);
        printf("\nName: %s", acc[i].name);
        printf("\nBalance: %.2f\n", acc[i].balance);
    }
}

int main() {
    int choice;

    while(1) {
        printf("\n\n===== BANK MANAGEMENT SYSTEM =====");
        printf("\n1. Create Account");
        printf("\n2. Deposit Money");
        printf("\n3. Withdraw Money");
        printf("\n4. Check Balance");
        printf("\n5. Display All Accounts");
        printf("\n6. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: checkBalance(); break;
            case 5: displayAll(); break;
            case 6: exit(0);
            default: printf("Invalid Choice!");
        }
    }
}
