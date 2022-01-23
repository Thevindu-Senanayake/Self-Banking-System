#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include <time.h>

int i,j;
int mainExit;
void menu();
void createAccount();
void updateAccount();
void transact();
void deleteAccount();
void checkAccount();
void close();
void menu();
void generateAccNo ();

struct date
{
	int month,day,year;
};

struct
{
	char name[60];
	int accNo,age;
	char address[60];
	char NIC[9];
	double phone;
	char acc_type[10];
	float amt;
	struct date dob;
	struct date deposit;
	struct date withdraw;
}add,update,check,rem,transaction;

float interest(float t,float amount,int rate)
{
   float SI;
   SI = (rate*t*amount)/100.0;
   return (SI);
}

void delay(int j)
{
	int i,k;
   for(i = 0; i< j; i++)
   k = i;
}

void generateAccNo ()
{
	srand (time(NULL));
	add.accNo = rand();
}

void loadingAnimation()
{
	for (i = 0; i < 70; i++) {
	for (j = 0; j < 25000000; j++) {
		i++;
		i--;
	}
	printf("*");
	}
}

void navigate(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;

	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void createAccount()
{
   int choice;
   FILE *ptr;

   ptr=fopen("record.dat","a+");
   account_no:
   system("cls");
	navigate(50, 1);
   printf("Create New Account");
	navigate(48, 2);
	printf("----------------------");
	navigate(20, 4);
   printf("1.Enter today's date(mm/dd/yyyy): ");
   scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
   generateAccNo ();
	navigate(20, 5);
   printf("2.Enter your name: ");
   scanf("%s",add.name);
	navigate(20, 6);
   printf("3.Enter your date of birth(mm/dd/yyyy): ");
   scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
	navigate(20, 7);
   printf("4.Enter your age: ");
   scanf("%d",&add.age);
	navigate(20, 8);
   printf("5.Enter your address: ");
   scanf("%s",add.address);
	navigate(20, 9);
   printf("6.Enter your NIC number: ");
   scanf("%s",add.NIC);
	navigate(20, 10);
   printf("7.Enter your phone number: ");
   scanf("%lf",&add.phone);
	navigate(20, 11);
   printf("8.Enter the amount to deposit: RS.");
   scanf("%f",&add.amt);
	navigate(20, 12);
   printf("9.Type of account:" );
	navigate(25, 13);
	printf("#Saving");
	navigate(25, 14);
	printf("#Current");
	navigate(25, 15);
	printf("#Fixed1(for 1 year)");
	navigate(25, 16);
	printf("#Fixed2(for 2 years)");
	navigate(25, 17);
	printf("#Fixed3(for 3 years)");
	navigate(20, 19);
	printf("Enter your choice: ");
   scanf("%s",add.acc_type);

   fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accNo,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.NIC,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);


   fclose(ptr);
	navigate(40, 21);
	loadingAnimation();
	navigate(30, 22);
   printf("Account created successfully!");
	navigate(40, 23);
	printf("Your Account Number is %d Please Remember Your Account Number", add.accNo);
   addExit:
	navigate(20, 25);
   printf("1.Main menu");
	navigate(20, 26);
	printf("0.Exit");
	navigate(15, 28);
	printf("Enter your choice: ");
   scanf("%d",&mainExit);
   system("cls");
   if (mainExit==1)
	{
		menu();
	}
   else if(mainExit==0)
	{
		close();
	}
   else
   {
		navigate(50, 14);
      printf("Invalid Option !");
      goto addExit;
   }
}

void updateAccount()
{
   int choice,test=0;
	FILE *old,*newrec;
   old=fopen("record.dat","r");
   newrec=fopen("new.dat","w");

	navigate(50, 1);
	printf("Update account information");
	navigate(48, 2);
	printf("------------------------------");
	navigate(20, 4);
   printf("Enter your Account No: ");
   scanf("%d",&update.accNo);
   while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.accNo,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.NIC,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
      if (add.accNo == update.accNo)
      {
			test=1;
			navigate(40, 6);
			printf("Which information do you want to change");
			navigate(20, 8);
			printf("1.Address");
			navigate(20, 9);
			printf("2.Phone");
			navigate(15, 11);
         printf("Enter your choice: ");
         scanf("%d",&choice);
         system("cls");
         if(choice == 1)
         {
				navigate(50, 1);
				printf("Update Address");
				navigate(48, 2);
				printf("------------------");
				navigate(20, 4);
				printf("Enter the new address: ");
            scanf("%s",update.address);
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accNo,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,update.address,add.NIC,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
				navigate(50, 6);
            printf("Changes saved!");

         }
         else if(choice==2)
         {
				navigate(50, 1);
				printf("Update Phone Number");
				navigate(48, 2);
				printf("------------------");
				navigate(20, 4);
            printf("Enter the new phone number: ");
            scanf("%lf",&update.phone);
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accNo,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.NIC,update.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
            navigate(50, 6);
				printf("Changes saved!");
         }
      }
      else
		{
			printf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accNo,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.NIC,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
		}
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");

	if(test!=1)
   {
		system("cls");
		navigate(30, 1);
      printf("Account not found with Account No: %d", update.accNo);
      editExit:
      navigate(20, 3);
   	printf("1.Try again");
		navigate(20, 4);
		printf("2.Main menu");
		navigate(20, 4);
		printf("0.Exit");
		navigate(15, 5);
		printf("Enter your choice: ");
      scanf("%d",&mainExit);
      system("cls");
      if (mainExit==2)
         menu();
      else if (mainExit==0)
         close();
      else if(mainExit==1)
         updateAccount();
      else
      {
			navigate(50, 1);
			printf("Invalid Option !");
         goto editExit;
		}
   }
   else
   {
		navigate(20, 7);
   	printf("1.Main menu");
		navigate(20, 8);
		printf("0.Exit");
		navigate(15, 10);
		printf("Enter your choice: ");
      scanf("%d",&mainExit);
      system("cls");
      if (mainExit==1)
      	menu();
      else
      	close();
   }
}

void transact()
{
	int choice,test=0;
   FILE *old,*newrec;
   old=fopen("record.dat","r");
   newrec=fopen("new.dat","w");

	navigate(50, 1);
   printf("Transactions");
	navigate(48, 2);
	printf("----------------");
	navigate(20, 4);
   printf("Enter your Account No: ");
   scanf("%d",&transaction.accNo);
   while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.accNo,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.NIC,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
      if(add.accNo == transaction.accNo)
      {
			test=1;
         if(strcmpi(add.acc_type,"fixed1")==0||strcmpi(add.acc_type,"fixed2")==0||strcmpi(add.acc_type,"fixed3")==0)
         {
				navigate(40, 6);
            printf("YOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS !");
            delay(1000000000);
            system("cls");
            menu();
         }
			navigate(20, 6);
         printf("Do you want to: ");
			navigate(25, 7);
			printf("1.Deposit");
			navigate(25, 8);
			printf("2.Withdraw");
			navigate(20, 10);
			printf("Enter your choice: ");
         scanf("%d",&choice);
         if (choice==1)
         {
				navigate(20, 12);
         	printf("Enter the amount you want to deposit: RS.");
            scanf("%f",&transaction.amt);
            add.amt+=transaction.amt;
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accNo,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.NIC,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
            navigate(50, 14);
				printf("Deposited successfully!");
         }
         else
         {
				navigate(20, 12);
            printf("Enter the amount you want to withdraw: RS.");
            scanf("%f",&transaction.amt);
            add.amt-=transaction.amt;
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accNo,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.NIC,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
				navigate(50, 14);
            printf("Withdrawn successfully!");
         }

      }
      else
      {
      	fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accNo,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.NIC,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
      }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test!=1)
   {
		system("cls");
		navigate(30, 1);
      printf("Account not found with this Account No: %d!", transaction.accNo);
      transact_invalid:
      navigate(20, 3);
   	printf("1.Try again");
		navigate(20, 4);
		printf("2.Main menu");
		navigate(20, 4);
		printf("0.Exit");
		navigate(15, 5);
		printf("Enter your choice: ");
      scanf("%d",&mainExit);
      system("cls");
      if (mainExit==1)
      	transact();
    	else if (mainExit==2)
      	menu();
    	else if (mainExit==0)
      	close();
    	else
    	{
      	navigate(50, 1);
			printf("Invalid!");
      	goto transact_invalid;
    	}
   }
   else
   {
      navigate(20, 17);
   	printf("1.Main menu");
		navigate(20, 18);
		printf("0.Exit");
		navigate(15, 20);
		printf("Enter your choice: ");
      scanf("%d",&mainExit);
      system("cls");
      if (mainExit==1)
      	menu();
      else
      	close();
   }
}

void deleteAccount()
{
   FILE *old,*newrec;
   int test=0;
   old=fopen("record.dat","r");
   newrec=fopen("new.dat","w");
   navigate(50, 1);
   printf("Delete account");
	navigate(48, 2);
	printf("------------------");
	navigate(20, 4);
   printf("Enter your Account No: ");
   scanf("%d",&rem.accNo);
   while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.accNo,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.NIC,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
      if(add.accNo!=rem.accNo)
      {
			fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accNo,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.NIC,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
		}
      else
      {
			test++;
			navigate(40, 6);
         printf("Account deleted successfully!");
      }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test==0)
   {
		system("cls");
		navigate(30, 1);
      printf("Account not found with this Account No: %d!", rem.accNo);
      erase_invalid:
      navigate(20, 3);
   	printf("1.Try again");
		navigate(20, 4);
		printf("2.Main menu");
		navigate(20, 4);
		printf("0.Exit");
		navigate(15, 5);
		printf("Enter your choice: ");
      scanf("%d",&mainExit);
      if (mainExit==2)
		{
         menu();
		}
      else if (mainExit==0)
		{
         close();
		}
      else if(mainExit==1)
		{
         deleteAccount();
		}
      else
      {
			navigate(50, 1);
			printf("Invalid!");
         goto erase_invalid;
		}
   }
   else
   {
		navigate(20, 9);
   	printf("1.Main menu");
		navigate(20, 10);
		printf("0.Exit");
		navigate(15, 12);
		printf("Enter your choice: ");
      scanf("%d",&mainExit);
      system("cls");
      if (mainExit==1)
		{
         menu();
		}
      else
		{
         close();
		}
   }
}

void checkAccount()
{
   FILE *ptr;
   int test=0,rate;
   int choice;
   float time;
   float intrst;
   ptr=fopen("record.dat","r");
	navigate(50, 1);
   printf("Check account details");
	navigate(48, 2);
	printf("-------------------------");
	navigate(20, 10);
	printf("Enter the account number: ");
   scanf("%d",&check.accNo);

   while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.accNo,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.NIC,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
      if(add.accNo==check.accNo)
      {
			system("cls");
         test=1;
			navigate(50, 1);
   		printf("Account Details");
			navigate(48, 2);
			printf("-------------------");
			navigate(20, 5);
			printf("Account NO: %d", add.accNo);
			navigate(20, 6);
			printf("Name: %s", add.name);
			navigate(20, 7);
			printf("Date Of Birth: %d/%d/%d", add.dob.month,add.dob.day,add.dob.year);
			navigate(20, 8);
			printf("Age: %d", add.age);
			navigate(20, 9);
			printf("Address: %s", add.address);
			navigate(20, 10);
			printf("NIC No: %s", add.NIC);
			navigate(20, 11);
			printf("Phone number: %.0lf", add.phone);
			navigate(20, 12);
			printf("Type Of Account: %s", add.acc_type);
			navigate(20, 13);
			printf("Amount deposited: RS.%.2f", add.amt);
			navigate(20, 12);
			printf("Date Of Deposit:%d/%d/%d", add.deposit.month,add.deposit.day,add.deposit.year);
         if(strcmpi(add.acc_type,"fixed1")==0)
         {
            time=1.0;
            rate=9;
            intrst=interest(time,add.amt,rate);
				navigate(20, 15);
            printf("You will get $%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
         }
         else if(strcmpi(add.acc_type,"fixed2")==0)
         {
            time=2.0;
            rate=11;
            intrst=interest(time,add.amt,rate);
				navigate(20, 15);
            printf("You will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);
         }
         else if(strcmpi(add.acc_type,"fixed3")==0)
         {
            time=3.0;
            rate=13;
            intrst=interest(time,add.amt,rate);
				navigate(20, 15);
            printf("You will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);
         }
         else if(strcmpi(add.acc_type,"saving")==0)
         {
            time=(1.0/12.0);
            rate=8;
            intrst=interest(time,add.amt,rate);
				navigate(20, 15);
            printf("You will get $.%.2f as interest on %d of every month",intrst,add.deposit.day);
         }
         else if(strcmpi(add.acc_type,"current")==0)
         {
				navigate(20, 15);
         	printf("You will get no interest");
         }

      }
   }
   fclose(ptr);
   if(test!=1)
   {
		system("cls");
      printf("Account not found with Account No: %d", check.accNo);
      see_invalid:
      navigate(20, 3);
   	printf("1.Try again");
		navigate(20, 4);
		printf("2.Main menu");
		navigate(20, 4);
		printf("0.Exit");
		navigate(15, 5);
		printf("Enter your choice: ");
      scanf("%d",&mainExit);
      system("cls");
      if (mainExit==2)
         menu();
      else if (mainExit==0)
         close();
      else if(mainExit==1)
         checkAccount();
      else
      {
         system("cls");
         navigate(50, 1);
			printf("Invalid Option !");
         goto see_invalid;
		}
   }
   else
   {
		navigate(30, 17);
   	printf("1.Main menu");
		navigate(30, 18);
		printf("0.Exit");
		navigate(25, 20);
		printf("Enter your choice: ");
      scanf("%d",&mainExit);
   	if (mainExit==1)
   	{
      	system("cls");
      	menu();
   	}
   	else
   	{
   		system("cls");
   		close();
   	}
	}
}

void close()
{
	exit(0);
}

void menu()
{
	int choice;
   system("cls");
	navigate(50, 1);
   printf("ABC BANK MANAGEMENT SYSTEM");
	navigate(48, 2);
	printf("------------------------------");
	navigate(50, 4);
   printf("WELCOME TO THE MAIN MENU");
	navigate(20, 6);
   printf("1.Create New Account");
	navigate(20, 7);
	printf("2.Update account information");
	navigate(20, 8);
	printf("3.Transactions");
	navigate(20, 9);
	printf("4.Check account details");
	navigate(20, 10);
	printf("5.Delete account");
	navigate(20, 11);
	printf("6.Exit");
	navigate(15, 13);
	printf("Enter your choice: ");
   scanf("%d",&choice);

   system("cls");
   switch(choice)
   {
      case 1:
			createAccount();
      	break;
      case 2:
			updateAccount();
      	break;
      case 3:
			transact();
      	break;
      case 4:
			checkAccount();
      	break;
      case 5:
			deleteAccount();
      	break;
      case 6:
			close();
      	break;
		default :
			menu();
			break;
   }
}

int main()
{
	menu();
	return 0;
}
