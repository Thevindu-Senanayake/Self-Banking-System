#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <unistd.h>
#include <dos.h>
#include <stdbool.h>

int userResponse;
int menuIndentifier;
int first = 1000;
int accountNumber;
bool isAnyKeyPressed = false;

void navigate (int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void clearScreen ()
{
	system("@cls||clear");
}

int generateAccNo ()
{
	accountNumber = ++first;
	return (accountNumber);
}

void loadingAnimation()
{
	for (int i = 0; i < 70; i++) {
		for (int j = 0; j < 1200000; j++) {
			j++;
			j--;
		}
		printf("*");
	}
}

struct credetials
{
	char firstName[25];
	char lastName[25];
	char userName[30];
	int phoneNumber[10];
	char address[50];
	int nic[12];
	char password[20];

};

struct loginCredentials
{
	char userName[30];
	char password[20];
};

int mainMenu ()
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

struct credetials createAccCredentials;

void validateLogin (userName, password)
{
	printf("%d createAccCredentials.userName\n", createAccCredentials.userName);
	printf("%d userName\n", userName);
	printf("%d createAccCredentials.password\n", createAccCredentials.password);
	printf("%d password\n", password);
	if (createAccCredentials.userName == userName && createAccCredentials.password == password)
	{
		printf("Login successful\n");
	}
	else
	{
		printf("wrong arguments\n");
	}
}

void logIn ()
{
	 struct loginCredentials userInput;

	 clearScreen ();
	 navigate(50, 1);
	 printf("Login To Account\n");
	 navigate(49, 2);
	 printf("------------------");
	 navigate(20, 4);
	 printf("Enter your Username: ");
	 scanf("%s", &userInput.userName);
	 navigate(20, 5);
	 printf("Enter your Password: ");
	 scanf("%s", &userInput.password);

	 validateLogin (userInput.userName, userInput.password);
}

void createAccount ()
{
	 menuIndentifier = 2;
	 clearScreen();
	 navigate(50 , 1);
    printf("REQUEST TO CREATE AN ACCOUNT\n");
	 navigate(48 , 2);
    printf("--------------------------------");
	 navigate(20, 4);
	 printf("Enter Your First Name: ");
	 scanf("%s", &createAccCredentials.firstName);
	 navigate(20, 5);
	 printf("Enter Your Last Name: ");
	 scanf("%s", &createAccCredentials.lastName);
	 navigate(20, 6);
	 printf("Enter Your User Name: ");
	 scanf("%s", &createAccCredentials.userName);
	 navigate(20, 7);
	 printf("Enter Your Phone Number: ");
	 scanf("%d", &createAccCredentials.phoneNumber);
	 navigate(20, 8);
	 printf("Enter Your Address: ");
	 scanf("%s", &createAccCredentials.address);
	 navigate(20, 9);
	 printf("Enter Your NIC Number: ");
	 scanf("%d", &createAccCredentials.nic);
	 navigate(20, 10);
	 printf("Enter Your Password: ");
	 scanf("%S", &createAccCredentials.password);

	 clearScreen ();
	 navigate(50, 1);
	 printf("Your Account Has Been Created Successfully\n");
	 navigate(49, 2);
	 printf("............................................");
	 navigate(20, 3);
	 generateAccNo ();
	 printf("Your Account Number is: %d", accountNumber);
	 navigate(20, 5);
	 printf("Press Any Key to Login");
	 getch();
	 logIn();
}

int findAccount ()
{
	printf("api thama hodatama kare");
}

void Response ()
{
	if (menuIndentifier == 1)
	{
		switch (userResponse) {

			case 1:
				createAccount ();
				break;

			case 2:
				findAccount ();
				break;

			case 3:
				exit(0);
		}
	}
}

int main ()
{
	mainMenu();
	Response();
}