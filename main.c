#include <stdio.h>
#include <stdlib.h>
#include "datatype.h"
#include "function.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int uses =0;
	struct User user[100];
	showSystemMenu(user,&uses);
	return 0;
}
