#include<stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct date{
	int month,day,year;
};
struct Transaction{
    char transferId[10];
    char receivingId[10];
    double amount;
    char type[10];  // deposit / transfer / withdraw
    char message[50];
};
struct AccountInfo{
    char userId[20];
    float balance;
    bool status;
    char username[10];
    char password[10];
    struct Transaction transactionHistory[];
};
struct User {
    char userId[10];
    char name[20];
    bool gender;
    char phone[10];
    char email[20];
    struct date dateOfBirth;
};

