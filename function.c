#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/function.h"
#include "../include/datatype.h"

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

	    printf("Enter the email: ");
	    fgets(newUser.email, sizeof(newUser.email), stdin);
	    newUser.email[strcspn(newUser.email, "\n")] = 0;


	    printf("Enter the Phone number: ");
	    gets(newUser.phone);
	    printf("Enter the gender (1 for male, 0 for female): ");
	    scanf("%d", &newUser.gender);
	    getchar();
	    printf("Enter the Date of Birth (DD\\MM\\YY): \n");
	    scanf("%d%d%d", &newUser.dateOfBirth.day, &newUser.dateOfBirth.month, &newUser.dateOfBirth.year);
		newUser.Status=1;
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
		 for(int i=0;i<*uses;++i){
			if(strcmp(newUser.phone, user[i].phone)==0){
				printf("Phone number exist\n");
				check=0;
				break;
			}
		}
		 if(strlen(newUser.email)==0){
	    	printf("Email name empty\n");
	    	check=0;
	    	continue;
		}
		for(int i=0;i<*uses;++i){
			if(strcmp(newUser.email, user[i].email)==0){
				printf("email exist\n");
				check=0;
				break;
			}
		}

	}
	user[*uses]=newUser;
	printf("\nAdded successfully\n");

    printf("\n User added successfully!\n");
    (*uses)++;
	fileWrite(user,*uses);
}
void login(char *email, char *password,int admin) {
	system("cls");
    printf("\n***Bank Management System Using C***\n");
    printf("\n\tLOGIN\n");
    printf("====================================\n");
    printf("Email: ");
	fflush(stdin);
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';  // Xóa ký tự xuống dòng nếu có
	fflush(stdin);
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
	if (admin==0) {
		printf("\n====================================\n");
		printf("Login successful (dummy check)\n");
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
    		printf("|%-12s|%-23s|%-32s|%-14s|%-10s||%-10s|\n", "UserId", "Name", "Email", "Phone", "Gender","Status");
    			for(int i = 0; i < uses; i++) {
        			printf("|============|=======================|================================|==============|==========|\n");
        			printf("|%-12s|%-23s|%-32s|%-14s|%-10s||%-10s|\n", user[i].userId, user[i].name, user[i].email, user[i].phone, user[i].gender ? "male" : "female",user[i].Status ? "open":"close" );
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
    printf("|%-12s|%-23s|%-32s|%-14s|%-10s|\n", "UserId", "Name", "Email", "Phone", "Status");
    for(int i = 0; i < uses; i++) {
        printf("|============|=======================|================================|==============|==========|\n");
        printf("|%-12s|%-23s|%-32s|%-14s|%-10s|\n", user[i].userId, user[i].name, user[i].email, user[i].phone, user[i].Status ?"open ":"close");
    }
    printf("|============|=======================|================================|==============|==========|\n");
}

void goBack(struct User *user, int* uses){
	char choice;
	printf("Go back(b) or Exit(0) ? ");
	scanf("%s",&choice);
	if(choice=='b'){
		return ;
	}
	else if(choice==0){
		printf("\nExiting the program...\n");
		return;
	}
}

void idLock(struct User *user, int* uses){
	system("cls");
	char id[20];
	char status;
	char choice;
    int flag = 1;
    printf("Enter id to check: ");
    getchar();
    fgets(id, 20, stdin);
    id[strcspn(id, "\n")] = '\0';

    for(int i = 0; i < *uses; i++) {
        if(strcmp(id, user[i].userId) == 0) {
            flag = 0;
            printf("ID found:\n");
            if(status == 0){
            	printf("Your account is locked");
            	printf("Do you want to change the status to closed?");
            	scanf("%s",&choice);
            	switch(choice){
            		printf("[n].No");
					printf("[y].Yes");
            		case 'n':
            			
            		case 'y':
            			printf("[y].Yes");
            			strcpy("open",user[i].Status);
            			printf("open successfully");
            			fileWrite(user,*uses);
				}
			}
			else if(status == 1){
				printf("Your account is open");
				printf("Do you want to change the status to open?");
				switch(choice){
					printf("[n].No");
					printf("[y].Yes");
            		case 'n':
            			
            		case 'y':
            			
            			strcpy("close",user[i].Status);
						printf("closed successfully");
						fileWrite(user,*uses);	
			}
    break;
			}
    if(flag) {
        printf("ID not found!!\n");
    }
}
}
}
void arrange(struct User *user, int* uses){
	int Choice;
	system("cls");
printf("+------------x SORT MENU x-------------+\n");		
printf( "[1] Sort user by name Descending.\n");		
printf( "[2] Sort user by name Ascending. \n");
printf("+--------------------------------------+");
printf("\n Enter your choice: ");
scanf("%d", &Choice);
	if(Choice == 1){
		for(int i = 0; i < (*uses) - 1; i++){
			for(int j = 0; j < (*uses) - i - 1; j++){
				if(strcmp(user[j].name, user[j + 1].name) < 0){
						struct User temp = user[j];
						user[j] = user[j + 1];
						user[j + 1] = temp;
}
	}	
		}
									
printf("\n\t User after Descending arrangement: ");
listUser(user, *uses);
goBack(user, uses);
}
else if(Choice == 2){
	for(int a = 0; a < (*uses) - 1; a++){
		for(int b = 0; b < (*uses) - a - 1; b++){
			if(strcmp(user[b].name, user[b + 1].name) > 0){
				struct User temp = user[b];
				user[b] = user[b + 1];
				user[b + 1] = temp;
			}
		}	
	}
}
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
			case 5:
				arrange(user, uses);
			break;
			case 4:
				idLock(user, *uses);
			break;
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
	fileRead(user, uses);
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
		case 1: {
			char a[20];
			char b[20];
			printf("\nYou selected Admin.\n");
			login(a,b,1);
			if (loginAdmin(a,b)) {
				menuAdmin(user,uses);
			}
			goBack(user, uses);
		}
		break;
		case 2: {
			char a[20];
			char b[20];
			printf("\nYou selected User.\n");
			login(a,b,0);
			menuAdmin(user,uses);
			goBack(user, uses);
			break;
		}
		case 0:
			printf("\nExiting the program...\n");
		break;
		default:
			printf("\nInvalid choice! Please try again.\n");
	}
}

void fileRead(struct User *user, int* uses){
	FILE *file=fopen("user.bin","rb");
	if(file==NULL){
		printf("you cannot read file");
	}
	printf("----%d---", *uses);

	*uses=fread(user,sizeof(struct User),100,file);
	fclose(file);
}
void fileWrite(struct User *user, int uses){
	FILE *file=fopen("user.bin","wb");
	if(file==NULL){
		printf("you cannot write file");
	}
	printf("----%d----", uses);
	fwrite(user,sizeof(struct User),uses,file);
	fclose(file);
}
int loginAdmin(char *ad,char *password) {
	char a[20];
	char b[20];
	FILE *admin=fopen("../data/admin.txt","r");
	fscanf(admin,"%s%s",a,b);
	a[strcspn(a,"\n")]='\0';
	b[strcspn(b,"\n")]='\0';
	if (strcmp(a,ad)==0&&strcmp(b,password)==0) {
		printf("Log in successfully");
		return 1;
	}
	else {
		printf("Login failed, please check your username or password again");
		return 0;
	}
}