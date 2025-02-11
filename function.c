// noi trien khai cac ham
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"datatype.h"
//bang danh sach
void listUser(struct User *user,int *uses) {
	printf("%50s","*** List User ***\n");
    printf("|============|=======================|================================|==============|==========|\n");
	for(int i=0;i<*uses;i++){
    	printf("|%-12s|%-23s|%-32s|%-14s|%-10s|\n","UserId","Name","Email","Phone","Status");
    	printf("|%-12s|%-23s|%-32s|%-14s|%-10s|\n", "1", "2", "3", "4", "5");
    	printf("|============|=======================|================================|==============|==========|\n");
    }
};
void showSytemtMenu(struct User *user, int*uses){
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
            AddUser(user,uses);
            listUser(user,uses);
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
void AddUser(struct User*user,int *uses) {
    printf("*** Add a new user ***\n");
    printf("Enter the ID: ");
    fgets(user[*uses].userId,sizeof(user[*uses].userId), stdin);
    getchar();
    fflush(stdin);
    printf("Enter the Name: ");
    fgets(user[*uses].name, sizeof(user[*uses].name), stdin);
    user[*uses].name[strcspn(user[*uses].name, "\n")] = 0;
    printf("Enter the email: ");
    fgets(user[*uses].email, sizeof(user[*uses].email), stdin);
    user[*uses].email[strcspn(user[*uses].email, "\n")] = 0;
    printf("Enter the Phone number: ");
    fgets(user[*uses].phone, sizeof(user[*uses].phone), stdin);
    user[*uses].phone[strcspn(user[*uses].phone, "\n")] = 0;
    fflush(stdin);
    printf("Enter the gender: ");
    scanf("%d", &user[*uses].gender);
    printf("Enter the Date of Birth: \n");
    printf("   Enter the Day: ");
    scanf("%d", &user[*uses].dateOfBirth.day);
    printf("   Enter the Month: ");
    scanf("%d", &user[*uses].dateOfBirth.month);
    printf("   Enter the Year: ");
    scanf("%d", &user[*uses].dateOfBirth.year);
    printf("\nAdded successfully\n");
      
    printf("\n User added successfully!\n");
    (*uses)++;


}


