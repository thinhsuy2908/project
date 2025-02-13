#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatype.h"


void AddUser(struct User* user,int* uses) {
	system("cls"); 
	struct User newUser;
	int check=0;
	while(!check){
		check=1;
		printf("*** Add a new user ***\n");
	    printf("Enter the ID: ");
	    scanf("%s", newUser.userId);
	    while(getchar()!='\n');
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
	    
	    if(strlen(newUser.email)==0){
	    	printf("Email name empty\n");
	    	check=0;
	    	continue;
		}
	    printf("Enter the Phone number: ");
	    gets(newUser.phone);
	    printf("Enter the gender (1 for male, 0 for female): ");
	    scanf("%d", &newUser.gender);
	    getchar();
	    printf("Enter the Date of Birth (DD\\MM\\YY): \n");
	    scanf("%d%d%d", &newUser.dateOfBirth.day, &newUser.dateOfBirth.month, &newUser.dateOfBirth.year);	    
	} 	
	user[*uses]=newUser;
	printf("\nAdded successfully\n");
      
    printf("\n User added successfully!\n");
    (*uses)++;
}
void login() {
	system("cls");
	char email[50];  // Khai báo biến email
    char password[50];  // Khai báo biến password
    printf("\n***Bank Management System Using C***\n");
    printf("\n\tLOGIN\n");
    printf("====================================\n");
    printf("Email: ");
    fgets(email, sizeof(email), stdin);
    getchar();
    email[strcspn(email, "\n")] = '\0';  // Xóa ký tự xuống dòng nếu có

    printf("Password: ");
    
    // Đọc mật khẩu và hiển thị dưới dạng dấu '*'
    int i = 0;
    char ch;
    while ((ch = getchar()) != '\n' && i < sizeof(password) - 1) {
        if (ch == '\b' && i > 0) { // Xử lý backspace
            printf("\b \b");
            i--;
        } else {
            password[i++] = ch;
            printf("*");
        }
    }
    password[i] = '\0';  // Kết thúc chuỗi

    printf("\n====================================\n");
    printf("Login successful (dummy check)\n");
}

void goBack(struct User *user, int* uses){
	char choice;
	printf("Go back(b) or Exit(0) ? ");
	scanf("%s",&choice);
	if(choice=='b'){
		menuAdmin(user, uses);
	}
	else if(choice==0){
		printf("\nExiting the program...\n");
		return;
	}
}

void findIdUser(struct User* user, int uses) {
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
            printf("|============|=======================|================================|==============|==========|\n");
    		printf("|%-12s|%-23s|%-32s|%-14s|%-10s|\n", "UserId", "Name", "Email", "Phone", "Gender");
    			for(int i = 0; i < uses; i++) {
        			printf("|============|=======================|================================|==============|==========|\n");
        			printf("|%-12s|%-23s|%-32s|%-14s|%-10s|\n", user[i].userId, user[i].name, user[i].email, user[i].phone, user[i].gender ? "male" : "female");
    }
    printf("|============|=======================|================================|==============|==========|\n");
    break;
}
        }
    if(flag) {
        printf("ID not found!!\n");
    }
}

void findNameUser (struct User* user, int uses){
    char name[20];
    int flag = 1;
    printf("Enter name to find: ");
    getchar();
    fgets(name, 20, stdin);
    name[strcspn(name, "\n")] = '\0';

    for(int i = 0; i < uses; i++) {
        if(strcmp(name, user[i].name) == 0) {
            flag = 0;
            printf("Name found:\n");
            printf("%50s", "*** List User ***\n");
    		printf("|============|=======================|================================|==============|==========|\n");
    		printf("|%-12s|%-23s|%-32s|%-14s|%-10s|\n", "UserId", "Name", "Email", "Phone", "Gender");
    			for(int i = 0; i < uses; i++) {
        			printf("|============|=======================|================================|==============|==========|\n");
        			printf("|%-12s|%-23s|%-32s|%-14s|%-10s|\n", user[i].userId, user[i].name, user[i].email, user[i].phone, user[i].gender ? "male" : "female");
    }
    printf("|============|=======================|================================|==============|==========|\n");
    break;
}
        }
    if(flag) {
        printf("Name not found!!\n");
    }
}

void listUser(struct User *user, int uses) {
	system("cls");
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
	system("cls");
    int choice;
    printf("%d", choice);
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
        printf("[7] return menu\n");
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
            case 3: {
				char choiceSmall;
				getchar();
				printf("[a].find by name user\n");
				printf("[b].find by Id user\n");
				printf("[c].return to menu\n");
				printf("Please choose a search method :");
				scanf("%s",&choiceSmall);
            	switch(choiceSmall){
            		case'a':
                		findNameUser(user, *uses);
                		goBack(user, uses);
                		break;
                	case'b':
                		findIdUser(user, *uses);
                		goBack(user,uses);
                		break;
                	case'c':
						goBack(user,uses);
						break;
                	default:
						printf("no value is escaping /n");           
                		break;
			}
            	
            	}
            case 7:
                goBack(user, uses);
                break;    
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 0);
}
 
void showSystemMenu(struct User *user, int* uses) {
	system("cls");
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
            goBack(user, uses);
            break;
        case 2:
            printf("\nYou selected User.\n");
            login(user, uses);
            goBack(user, uses);
            break;
        case 0:
            printf("\nExiting the program...\n");
            break;
        default:
            printf("\nInvalid choice! Please try again.\n");
    }
}

