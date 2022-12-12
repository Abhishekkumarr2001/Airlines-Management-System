#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>

struct Airlines
{
	char passport[6];
	char name[15];
	char destination[15];
	int SeatNum;
	char email[15];
	struct Airlines *following;
}
*begin, *stream;
struct Airlines *dummy;

void details()
{
	printf("\n\t Enter your Passport Number :");
	gets(stream->passport);
	fflush(stdin);
	printf("\n\t Enter your  Name :");
	gets(stream->name);
	fflush(stdin);
	printf("\n\t Enter your Email :");
	gets(stream->email);
	fflush(stdin);
	printf("\n\t Enter the Destination : ");
	gets(stream->destination);
	fflush(stdin);
}

void details();
void reserve(int x)
{
	stream = begin;
	if (begin == NULL)
	{
		begin = stream = (struct Airlines *)malloc(sizeof(struct Airlines));
		details();
		stream->following = NULL;
		printf("\n\t Seat booking successful!");
		printf("\n\t Your Seat Number is : Seat A-%d", x);
		stream->SeatNum = x;
		return;
	}
	else if (x > 30)
	{
		printf("\n\t\t Seat are Full.");
		return;
	}
	else
	{
		while (stream->following)
			stream = stream->following;
		stream->following = (struct Airlines *)malloc(sizeof(struct Airlines));
		stream = stream->following;
		details();
		stream->following = NULL;
		printf("\n\t Seat Booking Succesfull!");
		printf("\n\t Your Seat Number is : Seat A-%d", x);
		stream->SeatNum = x;
		return;
	}
}

void savefile()
{
	FILE *fpointer = fopen("AirlinesRecords", "w");
	if (!fpointer)
	{
		printf("\n Error in Opening the File!");
		return;
		Sleep(1000);
	}
	stream = begin;
	while (stream)
	{
		fprintf(fpointer, "%-6s", stream->passport);
		fprintf(fpointer, "%-15s", stream->name);
		fprintf(fpointer, "%-15s", stream->email);
		fprintf(fpointer, "%-15s", stream->destination);
		fprintf(fpointer, "\n");
		stream = stream->following;
	}
	printf("\n\n\t Details have been saved to a file (AirlinesRecords)");
	fclose(fpointer);
}

void display()
{
	stream = begin;
	while (stream)
	{
		printf("\n\n Passport Number : %-6s", stream->passport);
		printf("\n         Name : %-15s", stream->name);
		printf("\n      Email Address: %-15s", stream->email);
		printf("\n      Seat Number: A-%d", stream->SeatNum);
		printf("\n     Destination:%-15s", stream->destination);
		printf("\n\n++*=====================================================*++");
		stream = stream->following;
	}
}

void cancel()
{
	stream = begin;
	system("cls");
	char passport[6];
	printf("\n\n Enter Passort Number to Delete Record?:");
	gets(passport);
	fflush(stdin);
	if (strcmp(begin->passport, passport) == 0)
	{
		dummy = begin;
		begin = begin->following;
		free(dummy);
		printf(" Your Booking has been Deleted");
		Sleep(800);
		return;
	}

	while (stream->following)
	{
		if (strcmp(stream->following->passport, passport) == 0)
		{
			dummy = stream->following;
			stream->following = stream->following->following;
			free(dummy);
			printf("has been Deleted. ");
			getch();
			Sleep(800);
			return;
		}
		stream = stream->following;
	}
	printf("Wrong Passport Number!! Please Try Again.");
}

void main()
{
	void reserve(int x), cancel(), display(), savefile();
	int choice;
	begin = stream = NULL; // Initialising pointers to NULL value
	int num = 1;
	do
	{

		printf("\n\n\t\t ********************************************************************");
		printf("\n\t\t                   Welcome to XYZ Airlines                             ");
		printf("\n\t\t   *******************************************************************");
		printf("\n\n\n\t\t Please Enter your Choice(1-4) :");
		printf("\n\n\t\t 1. Reservation");
		printf("\n\n\t\t 2. Cancel");
		printf("\n\n\t\t 3. Display Records");
		printf("\n\n\t\t 4. Exit");
		printf("\n\n\t\t Feel Free to Contact Us anytime.");
		printf("\n\n\t\t Please! Enter your choice :");
		scanf("%d", &choice);
		fflush(stdin);
		system("cls");

		switch (choice)
		{
		case 1:
			reserve(num);
			num++;
			break;
		case 2:
			cancel();
			break;
		case 3:
			display();
			break;
		case 4:
		{
			savefile();
			break;
		}
		default:
			printf("\n\n\t Invalid Choice! (Please Choose From 1-4");
		}
		getch();
	} while (choice != 4);
}
