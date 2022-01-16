#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <unistd.h>

int userResponse;
int menuIndentifier;

void navigate(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void clearScreen()
{
	system("@cls||clear");
}

struct credetials
{
	char firstName[25];
	char lastName[25];
	char phoneNumber[10];
	char adress[50];
	char nic[12];

};

int mainMenu()
{
	 menuIndentifier = 1;
	 navigate(50 , 1);
    printf("WELCOME TO BANK ABC\n");
	 navigate(48 , 2);
    printf("-----------------------");
	 navigate(20, 4);
	 printf("1. Request to create an account");
	 navigate(20, 5);
	 printf("2. Search Account");
	 navigate(20, 6);
	 printf("3. Exit\n");
	 navigate(0, 8);
	 printf("Enter Your Choice: ");
	 scanf("%d", &userResponse);

	 return (userResponse);
}

int createAccount()
{
	 menuIndentifier = 2;
	 clearScreen();
	 navigate(50 , 1);
    printf("REQUEST TO CREATE AN ACCOUNT\n");
	 navigate(48 , 2);
    printf("--------------------------------");
	 navigate(20, 4);
	 printf("Enter Your First Name: ");
	 scanf("");
}

void Response()
{
	if (userResponse == 1 && menuIndentifier == 1)
	{
		createAccount();
	}
}

int main ()
{
	mainMenu();
	Response();
}