#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<time.h>
typedef struct tm tm;
void storeStudentQuery();
void storeFacultyQuery();
void checktime();
void admincheck();
int main() 
{ 
printf("\t\t\tWELCOME TO QUERY MANAGEMENT SYSTEM\t\n");
 while(1){
	int option;
  printf("\nEnter your Post: \n1.Faculty \t2.Student \t3.Admin \t4.Exit\n");
  scanf("%d",&option);
  switch(option){
  	case 1:
  		printf("You have Selected:\t\tFaculty Queries \n ");
  		storeFacultyQuery();
  		break;
  	case 2:
  		printf("You have Selected:\t\tStudent Queries\n");
                storeStudentQuery();
  		break;
        case 3:
  		printf("You have Selected:\t\tAdmin");
                checktime();
  		
		break;
  	case 4:
  		printf("\nProgram terminated ");
  		exit(0);
		break;
  	default:
  		printf("\nPlease Enter The correct options");
  		break;
  }
}
}


void storeStudentQuery()
{DIR *dr=mkdir("Queries",0777);
	DIR *dr1=mkdir("Queries/Student",0777); //Directory for storing queries
	int n,fd,n1;
	char buff[]="\n";
	char name[20];
	char q[]="Query BY=> ";
	write(1,q,11);
	read(0,name,20);
	strcat(q,name);
	n1=strlen(q);
	fd=open("Queries/Student/queries.txt",O_CREAT|O_TRUNC|O_RDWR,0777);
	write(fd,q,n1);
	close(fd);
	printf("Enter your queries here \n");
	n=read(0,buff,200);
	fd=open("Queries/Student/queries.txt",O_WRONLY|O_APPEND);
	write(fd,buff,n);
	close(fd);
}
void storeFacultyQuery()
{       DIR *dr=mkdir("Queries",0777);
	DIR *dr1=mkdir("Queries/Faculty",0777); //Directory for storing queries
	int n,fd,n1;
	char buff[]="\n";
	char name[20];
	char q[]="Query BY=> ";
	write(1,q,11);
	read(0,name,20);
	strcat(q,name);
	n1=strlen(q);
	fd=open("Queries/Faculty/queries.txt",O_CREAT|O_TRUNC|O_RDWR,0777);
	write(fd,q,n1);
	close(fd);
	printf("Enter your queries here \n");
	n=read(0,buff,200);
	fd=open("Queries/Faculty/queries.txt",O_WRONLY|O_APPEND);
	write(fd,buff,n);
	close(fd);
}
void admincheck()
{
printf("Enter your Password here=>");
char pass[20];
read(0,pass,20);
if(strcmp(pass,"Admin123")==0)
{
	printf("\nAdmin verified\n");
}
else
{
printf("\nAdmin not verified \n");

}
}
void checktime()
{
time_t currentTime;
time(&currentTime);
tm *myTime = localtime(&currentTime);
if((myTime->tm_hour >10) && (myTime->tm_hour <18))
{
admincheck();
}
else
{
printf("/nACCESS DENIED \n[The Time is %d:%d ]\nNOTE: Admin are allowed to login in between 10am to 12am only",myTime->tm_hour,myTime->tm_min);
}
}
