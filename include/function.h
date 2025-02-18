#include "./datatype.h"
void AddUser(struct User* user, int* uses);
void findUser(struct User* user, int uses);
void findUserName (struct User* user, int uses);
void listUser(struct User *user, int uses);
void menuAdmin(struct User* user, int* uses);
void login(char *email, char *password, int admin);
void goBack(struct User *user, int* uses);
void idLock(struct User *user, int* uses);
void arrange(struct User *user, int* uses);
void showSystemMenu(struct User *user, int* uses);
void fileRead(struct User *user, int* uses);
void fileWrite(struct User *user, int uses);
int loginAdmin(char *ad,char *password);