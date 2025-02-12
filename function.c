#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatype.h"
void AddUser(struct User* user,int* uses) {
struct User newUser;
int check=0;
	while(!check){
		check=1;
		printf("*** Add a new user ***\n");
	    printf("Enter the ID: ");
	    scanf("%s", newUser.userId);
	    getchar();
	    printf("Enter the Name: ");
	    fgets(newUser.name, sizeof(newUser.name), stdin);
	    newUser.name[strcspn(newUser.name, "\n")] = 0;
	    if(strlen(newUser.userId)==0 || strlen(newUser.name)==0){
	    	printf("ID or name empty\n");
	    	check=0;
	    	continue;
		}
		for(int i=0;i<*uses;++i){
			if(strcmp(newUser.userId, user[i].userId)==0){
				printf("ID exist\n");
				check=0;
				break;
			}
		}
		
		for(int i=0;i<*uses;++i){
			if(strcmp(newUser.name, user[i].name)==0){
				printf("Name exist\n");
				check=0;
				break;
			}
		}
	    printf("Enter the email: ");
	    fgets(newUser.email, sizeof(newUser.email), stdin);
	    newUser.email[strcspn(newUser.email, "\n")] = 0;
	    
	    if(strlen(newUser.email)==0 || strlen(newUser.name)==0){
	    	printf("Email name empty\n");
	    	check=0;
	    	continue;
		}
	    printf("Enter the Phone number: ");
	    gets(newUser.phone);
	    printf("Enter the gender (1 for male, 0 for female): ");
	    scanf("%d", &newUser.gender);
	    getchar();
	    printf("Enter the Date of Birth (DD\MM\YY): \n");
	    scanf("%d%d%d", &newUser.dateOfBirth.day, &newUser.dateOfBirth.month, &newUser.dateOfBirth.year);	    
	} 	
	user[*uses]=newUser;
	printf("\nAdded successfully\n");
      
    printf("\n User added successfully!\n");
    (*uses)++;
}
void findUser(struct User* user, int uses) {
    char id[20];
    int flag = 1;
    printf("Enter id to find: ");
    getchar();
    fgets(id, 20, stdin);
    id[strcspn(id, "\n")] = '\0';

    for(int i = 0; i < uses; i++) {
        if(strcmp(id, user[i].userId) == 0) {
            flag = 0;
            printf("ID found:\n");
            printf("ID: %s\n", user[i].userId);
            printf("Name: %s\n", user[i].name);
            printf("Email: %s\n", user[i].email);
            printf("Phone: %s\n", user[i].phone);
            printf("Gender: %s\n", user[i].gender ? "male" : "female");
            printf("Date of Birth: %d/%d/%d\n", user[i].dateOfBirth.day, user[i].dateOfBirth.month, user[i].dateOfBirth.year);
            break;
        }
    }
    if(flag) {
        printf("ID not found!!\n");
    }
}

void listUser(struct User *user, int uses) {
    printf("%50s", "*** List User ***\n");
    printf("|============|=======================|================================|==============|==========|\n");
    printf("|%-12s|%-23s|%-32s|%-14s|%-10s|\n", "UserId", "Name", "Email", "Phone", "Gender");
    for(int i = 0; i < uses; i++) {
        printf("|============|=======================|================================|==============|==========|\n");
        printf("|%-12s|%-23s|%-32s|%-14s|%-10s|\n", user[i].userId, user[i].name, user[i].email, user[i].phone, user[i].gender ? "male" : "female");
    }
    printf("|============|=======================|================================|==============|==========|\n");
}

void menuAdmin(struct User* user, int* uses) {
    int choice;
    do {
        printf("***Bank Management System Using C***\n\n");
        printf("            MENU\n");
        printf("====================================\n");
        printf("[1] Add a new user\n");
        printf("[2] Show all users\n");
        printf("[3] Show details of a user\n");
        printf("[4] Lock (unlock) a user\n");
        printf("[5] User guideline\n");
        printf("[6] About us\n");
        printf("[0] Exit\n");
        printf("======================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                AddUser(user, uses);
                break;
            case 2:
                listUser(user, *uses);
                break;
            case 3:
                findUser(user, *uses);
                break;
            case 0:
                printf("Exiting admin menu...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 0);
}

void showSystemMenu(struct User *user, int* uses) {
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

    switch (choice) {
        case 1:
            printf("\nYou selected Admin.\n");
            menuAdmin(user, uses);
            break;
        case 2:
            printf("\nYou selected User.\n");
            break;
        case 0:
            printf("\nExiting the program...\n");
            break;
        default:
            printf("\nInvalid choice! Please try again.\n");
    }
}
