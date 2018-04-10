#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
void storeStudentQuery();
int main() 
{ 
printf("\t\t\tWELCOME TO QUERY MANAGEMENT SYSTEM\t\n");
 while(1){
	int option;
  printf("\nEnter your Post: \n1.Faculty \t2.Student \t3.Admin \t4.Exit\n");
  scanf("%d",&option);
  switch(option){
  	case 1:
  		printf("You have Selected:\n\t\tFaculty Queries \n ");
  		
  		break;
  	case 2:
  		printf("You have Selected:\n\t\tStudent Queries\n");
                storeStudentQuery();
  		break;
        case 3:
  		printf("\n\t\tAdmin");
  		
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
{
	DIR *dr=mkdir("Queries",0777); //Directory for storing queries
	int n,fd,n1;
	char buff[]="\n";
	char name[20];
	char q[]="Query BY=> ";
	write(1,q,11);
	read(0,name,20);
	strcat(q,name);
	n1=strlen(q);
	fd=open("Queries/Studentsqueries.txt",O_CREAT|O_TRUNC|O_RDWR,0777);
	write(fd,q,n1);
	close(fd);
	printf("Enter your queries here \n");
	n=read(0,buff,200);
	fd=open("Queries/Studentsqueries.txt",O_WRONLY|O_APPEND);
	write(fd,buff,n);
	close(fd);
}
