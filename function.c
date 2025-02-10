#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"datatype.h"
//bang danh sach
void listUser() {
    printf("%50s","*** List User ***\n");
    printf("|============|=======================|================================|==============|==========|\n");
    printf("|%-12s|%-23s|%-32s|%-14s|%-10s|\n","UserId","Name","Email","Phone","Status");
    printf("|============|=======================|================================|==============|==========|\n");
};
void addStudent(){
    int choice;

    printf("***Bank Management System Using C***\n\n");
    printf("\tCHOOSE YOUR ROLE\t\n");
    printf("================================\n");
    printf("[1] Admin.\n");
    printf("[2] User.\n");
    printf("[0] Exit the Program.\n");
    printf("================================\n");
    printf("Enter The Choice: ");
    scanf("%d", &choice);


    // Xu ly lua chon
    switch (choice) {
        case 1:
            printf("\nYou selected Admin.\n");
            menuAdmin();
            break;
        case 2:
            printf("\nYou selected User.\n");
            AddUser();
            listUser();
            break;
        case 0:
            printf("\nExiting the program...\n");
        default:
            printf("\nInvalid choice! Please try again.\n");
    }

}

void menuAdmin() {
    printf("***Bank Management System Using C***\n\n");
    printf("            MENU\n");
    printf("====================================\n");
    printf("[1] Add a new user\n");
    printf("[2] Show all user\n");
    printf("[3] Show detail an user\n");
    printf("[4] Lock (unlock) an user\n");
    printf("[5] User guideline\n");
    printf("[6] About us\n");
    printf("[0] Exit\n");
    printf("======================================\n");
}

// nhap lua chon
void runMainMenu() {
    while(1) {
        int choice;
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                menuAdmin();
                break;
            case 2:
                printf("User\n");
            break;
            case 0:
            
            default:
                printf("Invalid Choice\n");
        }
    }
}
// nhap nguoi dung moi
void AddUser() {
    struct User user;
    printf("*** Add a new user ***\n");
    printf("Enter the ID: ");
    fgets(user.userId, sizeof(user.userId), stdin);
    fflush(stdin);
    printf("Enter the Name: ");
    fgets(user.name, sizeof(user.name), stdin);
    fflush(stdin);
    printf("Enter the email: ");
    fgets(user.email, sizeof(user.email), stdin);
    fflush(stdin);
    printf("Enter the Phone number: ");
    fgets(user.phone, sizeof(user.phone), stdin);
    fflush(stdin);
    printf("Enter the gender: ");
    scanf("%d", &user.gender);
    printf("Enter the Date of Birth: \n");
    printf("   Enter the Day: ");
    scanf("%d", &user.dateOfBirth.day);
    printf("   Enter the Month: ");
    scanf("%d", &user.dateOfBirth.month);
    printf("   Enter the Year: ");
    scanf("%d", &user.dateOfBirth.year);
    printf("\nAdded successfully\n");
}



