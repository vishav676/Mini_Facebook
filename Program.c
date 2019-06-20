#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#ifdef _WIN32
#include<conio.h>
#endif
#include<stdlib.h>
typedef struct // Structure to save the date of birth...
{
	int date;
	int month;
	int year;
}dob;

typedef struct detail
{
	char *name,*family,*nick,*gender,*inviter;
	int age;
	dob birth;// Structure...
}detail;

FILE *fp; //FILE reference;
int i=0;
void lines()//to print the lines to make the output clean
{
	int i;
	for(i=0;i<10;i++)
	{
		printf("\n");
	}
}
detail list_main(){//this function returns the data in file of users one by one.
	char str[1000];
	detail det;

	if(fp==NULL)
	fp=fopen("facebook.txt","r");

	fscanf(fp,"%s",str);//scan the first string into str
	det.name = (char*)malloc(sizeof(char)*strlen(str)+1);//dynamiclly det.name array is created of length str+1 ..+1 for terminating character
	strcpy(det.name,str);//copy the str to det.name

	fscanf(fp,"%s",str);
	det.family = (char*)malloc(sizeof(char)*strlen(str)+1);
	strcpy(det.family,str);

	fscanf(fp,"%s",str);
	det.nick = (char*)malloc(sizeof(char)*strlen(str)+1);
	strcpy(det.nick,str);

	fscanf(fp,"%d",&det.age);

	fscanf(fp,"%s",str);
	det.gender = (char*)malloc(sizeof(char)*strlen(str)+1);
	strcpy(det.gender,str);
	fscanf(fp,"%d",&det.birth.date);
	fscanf(fp,"%d",&det.birth.month);
	fscanf(fp,"%d",&det.birth.year);

	fscanf(fp,"%s",str);
	det.inviter = (char*)malloc(sizeof(char)*strlen(str)+1);
	strcpy(det.inviter,str);
    return det;//return data of user in structure.
}

int numberusers()
{
	FILE *fp;
	int n=0;
	char str[1000];
	fp = fopen("facebook.txt","r");//open files in read mode
	while(1)
	{
		if(fscanf(fp,"%s",str)!=EOF)//read the file until the end of file
		{
			++n;//count the number of users in the file
		}
		else
		break;

	}
	n=n/9;//structure contains 9 elements so n is divided by 9;
	fclose(fp);
	return n;
}
void display_menu()//display the menu to screen
{
    printf("\n-----------------------------------------");
    printf("\n\t\tList data on the basis of");
	printf("\n\t1. Name\n\t2. same birth year\n\t3. family name\n\t4. Inviter\n\t5. All List\n");
	printf("\n-----------------------------------------");
	printf("\nEnter your Choice ");
}
void menu() // Main Menu function
{
	lines();
	printf("-------------------------------\n");
	printf("\t\tMenu\n\t1. Add new\n\t2. Delete\n\t3. List\n\t4. Modify\n\t0.To exit\n");
	printf("-------------------------------");
}
void listchoice(int choice)
{//print the messsage on the console on the basis of the choice of the user...
	switch(choice)
	{
		case 1:
			printf("Enter the name you want to search: ");
			break;
		case 2:
			printf("\nEnter the birth year you want to search = ");
			break;
		case 3:
			printf("\nEnter the family name you want to search: ");
			break;
		case 4:
			printf("Enter the name of invitor: ");
			break;
	}
}
void leave()
{//printf the message while leaving the program
	printf("Made by Vishav Lakhtia\nNeptun Code :- MXYQFR\n");
	printf("Thanks for visiting!");
}
detail new_mem()
{
	detail det;
	char temp[1000];
	int c=0;
	printf("\n-------------------------------------");
	printf("\n\tEnter the new Data");
	printf("\nEnter the name : ");
	scanf("%s",temp);
	det.name = (char*)malloc(sizeof(char)*strlen(temp+1));
	strcpy(det.name,temp);
	printf("Enter the family name : ");
	scanf("%s",temp);
	det.family = (char*)malloc(sizeof(char)*strlen(temp)+1);
	strcpy(det.family,temp);
	printf("Enter the nickname : ");
	scanf("%s",temp);
	det.nick = (char*)malloc(sizeof(char)*strlen(temp)+1);
	strcpy(det.nick,temp);
	printf("Enter the age : ");
	scanf("%d",&det.age);
	printf("Enter the gender : ");
	scanf("%s",temp);
	det.gender = (char*)malloc(sizeof(char)*strlen(temp)+1);
	strcpy(det.gender,temp);
	do{
	    c=0;
        printf("Enter the date of birth(dd/mm/yyyy) : ");
        scanf("%d%d%d",&det.birth.date,&det.birth.month,&det.birth.year);
        if(det.birth.date<=0||det.birth.date>31)
        {
            printf("Invalid date");
            c=1;
        }
        if(det.birth.month<=0||det.birth.month>12)
        {
            printf("Invalid month");
            c=1;
        }
        if(det.birth.year>2018)
        {
            printf("Invalid year");
            c=1;
        }
        if(c==1)
            printf("\nEnter the correct date...\n");
    }while(c==1);
	printf("\nEnter the inviter : ");
	scanf("%s",temp);
	det.inviter = (char*)malloc(sizeof(char)*strlen(temp)+1);
	strcpy(det.inviter,temp);
	return det;// return the data of users in the form of structure...
}
bool login(char username[],char password[])//function to check login deatils...
{
	char pass[] = "password",use[] = "Cprog";
	if(strcmp(pass,password)==0&&strcmp(username,use)==0)
	{
		return true;//username and password matched
	}
	else
	{

		return false;//wrong username or password...
	}
}

void add(detail det)
{
	//detail variable to store the infoormation
	fp = fopen("facebook.txt","a");//opening file in append mode this creates files if it doesn't exists.



		//this syntax write the data in the file facebook.txt
		fprintf(fp,"%s\t%s\t%s\t%d\t%s\t%d\t%d\t%d\t%s\n",det.name,det.family,det.nick,det.age,det.gender,det.birth.date,det.birth.month,det.birth.year,det.inviter);
	//continues until ch is equal to 1
	fclose(fp);
}
void list(detail det)
{
	int choice;
	int i=0,finder =0;
	int users;
	char name[50];
	int yr;
	users = numberusers();
	fp = fopen("facebook.txt","r");//opening file in the read mode
	display_menu();//calling display function declared in display.h module
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			listchoice(choice);//calling listchoice function declared in the display.h module
			scanf("%s",name);//ask name to list all users of same name;
			while(i<users)
			{
				det=list_main();
					if(strcmp(det.name,name)==0)//found username in the file
					{
						printf("%s\t\t%s\t\t%s\t\t%d\t\t%s\t\t%d-%d-%d\t\t%s\n",det.name,det.family,det.nick,det.age,det.gender,det.birth.date,det.birth.month,det.birth.year,det.inviter);
                        finder =1;
					}
				i++;

			}
			if(finder == 1)
                printf("\nAll users printed");
            else
                printf("\nNo data found");
			break;
		case 2:
			listchoice(choice);
			scanf("%d",&yr);//ask user to enter the year to list data of users with same birth year..

			while(i<users)
			{
				det=list_main();//list_main() function is called. which return the data in structure one by one

					if(det.birth.year==yr)
					{
						printf("%s\t\t%s\t\t%s\t\t%d\t\t%s\t\t%d-%d-%d\t\t%s\n",det.name,det.family,det.nick,det.age,det.gender,det.birth.date,det.birth.month,det.birth.year,det.inviter);
                        finder = 1;
					}

				i++;

			}
			if(finder == 1)
                printf("\nAll users printed");
            else
                printf("\nNo data found");
			break;
		case 3:
			listchoice(choice);
			scanf("%s",name);//asks user to enter the family name..
			i=0;
			while(i<users)
			{
				det=list_main();//list_main() function is called. which return the data in structure one by one

					if(strcmp(det.family,name)==0)//condition to find same family name in file as enter by the user..
					{
						printf("%s\t\t%s\t\t%s\t\t%d\t\t%s\t\t%d-%d-%d\t\t%s\n",det.name,det.family,det.nick,det.age,det.gender,det.birth.date,det.birth.month,det.birth.year,det.inviter);
                        finder = 1;
					}


				i++;

			}
			if(finder == 1)
                printf("\nAll users printed");
            else
                printf("\nNo data found");
			break;
		case 4:
			listchoice(choice);
			scanf("%s",name);//ask user to enter the name of inviter.
			i=0;
			while(i<users)
			{
				det=list_main();

					if(strcmp(det.inviter,name)==0)//condition to match the inviter name..
					{
						printf("%s\t\t%s\t\t%s\t\t%d\t\t%s\t\t%d-%d-%d\t\t%s\n",det.name,det.family,det.nick,det.age,det.gender,det.birth.date,det.birth.month,det.birth.year,det.inviter);
                        finder = 1;
					}

				i++;

			}
			if(finder == 1)
                printf("\nAll users printed");
            else
                printf("\nNo data found");
			break;
		case 5:
			listchoice(choice);
			 i=0;
			int num = numberusers();//stores the number of users in the file
			printf("Name\t\tFamily\t\tNickname\t\tAge\t\tGender\t\tDate Of Birth\t\tInviter\n");
			while(i<num)//loop runs till the number of users in the file..
			{
				det = list_main();//gets the data in the file one by one..
				printf("%s\t\t%s\t\t%s\t\t%d\t\t%s\t\t%d-%d-%d\t\t%s\n",det.name,det.family,det.nick,det.age,det.gender,det.birth.date,det.birth.month,det.birth.year,det.inviter);
				i++;
			}
	}
	fclose(fp);

}
void modify()
{//modify function
	char mod[50];
	detail det;
	int i=0,numbermem=0;
	numbermem = numberusers();
	detail *deat = (detail*)malloc(sizeof(detail) * numbermem);//creation of array with size of detail structure with size of number of users in file
	fp=fopen("facebook.txt","r");

	while(i<numbermem)//loop until the number of users in file
	{
			det = list_main();//det stores the structure return from the function list_main()
			deat[i]=det;//deat[i] array stores det in index
			i++;

	}
	fclose(fp);
	printf("Enter the name of the person: ");
	scanf("%s",mod);//recieves data from users...
	for(i=0;i<numbermem;i++)
	{
		if(strcmp(deat[i].name,mod)==0)//condition to find the name entered by user in the file
		{
			deat[i] = new_mem();//function called to ask user to enter new details ..then return that data in form of structure..
			fp = fopen("facebook.txt","w");//open in write mode because this overwrites the data in the file..
			for(i=0;i<numbermem;i++)
			{//this write the new array data to the file...
				fprintf(fp,"%s\t%s\t%s\t%d\t%s\t%d\t%d\t%d\t%s\n",deat[i].name,deat[i].family,deat[i].nick,deat[i].age,deat[i].gender,deat[i].birth.date,deat[i].birth.month,deat[i].birth.year,deat[i].inviter);
			}
			fclose(fp);
			break;
		}
	}
	printf("No data found.....");
	fclose(fp);

}
void del()
{
	char name[50];
	fp = fopen("facebook.txt","r");
	int numbermem,i=0,j,c=0;
	numbermem = numberusers();//stores number of users in file.....
	detail det;
	detail *deat = (detail*)malloc(sizeof(detail) * numbermem);//dynamicly make array of structure of size of number of users in file
	while(i<numbermem)
	{
			det = list_main();
			deat[i]=det;
			i++;

	}
	fclose(fp);
	printf("\tDelete the data...");
	printf("Enter the name : ");
	scanf("%s",name);
	for(i=0;i<numbermem;i++)
	{
		if(strcmp(deat[i].name,name)==0)//find the name in the array which user has entered...
		{
			for(j=i;j<numbermem;j++)//decrease size oof array
			deat[j]=deat[j+1];
			numbermem--;
			fp = fopen("facebook.txt","w");//open file in write mode because it deletes the previous data in file...
			for(i=0;i<numbermem;i++)
			{
				//store new data in the file...
				fprintf(fp,"%s\t%s\t%s\t%d\t%s\t%d\t%d\t%d\t%s\n",deat[i].name,deat[i].family,deat[i].nick,deat[i].age,deat[i].gender,deat[i].birth.date,deat[i].birth.month,deat[i].birth.year,deat[i].inviter);
			}
			fclose(fp);
			printf("Data Deleted successfully");
			c=1;
			break;
		}
	}
	if(c==0)
	printf("No data found......");

}
int main()
{
	int attempt,choice,d,i=0,chr;
	char  username[10],password[10],ch;
	detail det;
	//Ask user to enter login details....

	printf("\t\tWelcome To Facebook\n");
	i=0;
	printf("Enter the username: ");
	scanf("%s",username);
	printf("Enter the password:");
	while(d!=13) //d is not equal to 13.. as 13 is ASCII Code of enter...
	{
#ifdef _WIN32
		ch=getch();
#else
ch=getchar();
#endif
		password[i]=ch;
		d=(int)ch;
		if(d==13){
		break;
		}
#ifdef _WIN32
		ch='*';
		printf("%c",ch);
#endif // _WIN32
		i++;
	}
	password[i]='\0';
	attempt = login(username,password); //call function to check the whether the login deatils are correct or not....
	if(attempt){
		printf("\nAuthencation sucessful!!!!:-)\nPress Any Key ");
//
		do{
		menu();
		//print the menu on the screen
		printf("\nEnter the choice: ");
		scanf("%d",&choice);
		//switch case to call the function which user wants
		switch(choice)
		{
		case 1:
			lines();
			do
			{
			det = new_mem();//new_mem function is called declared in other module display.h and store the return detail variable
            add(det);
			printf("Do more (press 1 to add more)= ");
			scanf("%d",&chr);
			}while(chr==1);
			//this function add the new user details to the file
			break;
		case 2:
			lines();
			del();
			//this function delete the user information from the file

			break;
		case 3:
			lines();
			//here list is displayed to user based on his choice
			list(det);
			break;
		case 4:
			lines();
			//this function is called to modify the data of the user in a file
			modify();
			break;
		case 0:
			lines();
			//this function print greeting message to the screen then program terminates..
			leave();
			break;
		default:
			lines();
			//in case user enters the invalid choice like -1
			printf("Wrong value ");
//
			break;
		}
		}while(choice!=0);
	}else
	{
		printf("\nInvalid password or username...");
	}

	return 0;
}
