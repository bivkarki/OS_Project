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
void adminservices();
void openStudentQuery();
void openFacultyQuery();
void writeResponseStudent();
void writeResponseFaculty();
void admfacActions();
void admstdActions();
void stdActions();
void facActions();
void ViewResponseFaculty();
void ViewResponseStudent();
void summary();
double calculateTimetaken(clock_t start, clock_t end);
clock_t start1,end1;
clock_t start2,end2;
clock_t start3,start4,end3,end4;
double stdTime,facTime,admstdTime,admfacTime;

int main() 
{ 

printf("\t\t\tWELCOME TO QUERY MANAGEMENT SYSTEM\t\n");
 while(1){
   
	int option;
  printf("\nEnter your Post: \n1.Faculty \t2.Student \t3.Admin \t4.Exit\n");
  scanf("%d",&option);
  switch(option){
  	case 1: 
                start1=clock();
  		printf("You have Selected:\t\tFaculty Queries \n ");
                facActions();
                end1=clock();
    printf("\n The time taken by Faculty is %f seconds",calculateTimetaken(start1,end1));
      stdTime+=calculateTimetaken(start1,end1);
  		break;
  	case 2:
                start2=clock();
  		printf("You have Selected:\t\tStudent Queries\n");
                stdActions();
                 end2=clock();
                 printf("\n The time taken by Student is %f seconds",calculateTimetaken(start2,end2));
           facTime+=calculateTimetaken(start2,end2);
  		break;
        case 3:

  		printf("You have Selected:\t\tAdmin");
                checktime();
  		
		break;
  	case 4:
                summary();
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
adminservices();
}
void checktime()
{
time_t currentTime;
time(&currentTime);
tm *myTime = localtime(&currentTime);
if((myTime->tm_hour >=10) && (myTime->tm_hour <12))
{
admincheck();
}
else
{
printf("\nACCESS DENIED \n[The Time is %d:%d ]\nNOTE: Admin are allowed to login in between 10am to 12am only",myTime->tm_hour,myTime->tm_min);
}
}
void adminservices()
{

	int option;
  printf("\n\nChoose the action: \n1.Manage Faculty Queries \t2.Manage Student Queries \t3.Logout\n");
  scanf("%d",&option);
  switch(option){
  	case 1:
               start3=clock();
  		printf("You have Selected:\t\tManage Faculty Queries\n ");
               admfacActions();
                end3=clock();
                 printf("\n The time taken by Admin to handle Faculty's Query is %f seconds",calculateTimetaken(start3,end3));
                admfacTime+=calculateTimetaken(start3,end3);
  		break;
  	case 2: start4=clock();
  		printf("You have Selected:\t\tManage Student Queries\n");
                admstdActions();
               end4=clock();
                 printf("\n The time taken by Admin to handle Student's Query is %f seconds",calculateTimetaken(start4,end4));
                admstdTime+=calculateTimetaken(start4,end4);
  		break;
              
       
  	case 3:
  		printf("\nAdmin Logged out.. \n\n");
		break;
  	default:
  		printf("\nPlease Enter The correct options and press CTRL+Z For program termination");
  		break;

}
}
void openFacultyQuery()
{
sleep(3);
int n,fd;
char ans;
char buff[500];
fd=open("Queries/Faculty/queries.txt",O_RDONLY,0777);
n=read(fd,buff,500);
write(1,buff,n);
close(fd);
}
void openStudentQuery()
{
char ans;
write(1,"\n Opening Student Query.... \n",30);
sleep(3);
int n,fd;
char buff[500];

fd=open("Queries/Student/queries.txt",O_RDONLY,0777);
n=read(fd,buff,500);
write(1,buff,n);
close(fd);

}
void writeResponseStudent()
{
int n,fd;
	
	char sol[200];
	char buff[]="Response=> ";
        write(1,buff,11);
	read(0,sol,200);
        strcat(buff,sol);
        n=strlen(buff);

	fd=open("Queries/Student/response.txt",O_CREAT|O_TRUNC|O_RDWR,0777);
	write(fd,buff,n);
	close(fd);

}
void writeResponseFaculty()
{
int n,fd;
	
	char sol[200];
	char buff[]="Response=> ";
        write(1,buff,11);
	read(0,sol,200);
        strcat(buff,sol);
        n=strlen(buff);

	fd=open("Queries/Faculty/response.txt",O_CREAT|O_TRUNC|O_RDWR,0777);
	write(fd,buff,n);
	close(fd);

}
void admstdActions()
{
int opt;
  printf("\nEnter Student Related Action: \n1.Read Query \t2.Give Response \t3.Exit\n");
  scanf("%d",&opt);
  switch(opt){
  	case 1:
  		printf("You have Selected:\t\tRead Query \n ");
  		openStudentQuery();
                admstdActions();
            
  		break;
  	case 2:
  		printf("You have Selected:\t\tGive Response\n");
                writeResponseStudent();
                admstdActions();
  		break;
  	case 3:
  		printf("\nExiting to the back menu ");
                adminservices();
		break;
  	default:
  		printf("\nPlease Enter The correct options");
  		break;
            }

}
void admfacActions()
{
int opt;
  printf("\nEnter Faculty Related Action: \n1.Read Query \t2.Give Response \t3.Exit\n");
  scanf("%d",&opt);
  switch(opt){
  	case 1:
  		printf("You have Selected:\t\tRead Query \n ");
sleep(1);
          printf("\n Opening Faculty Query....");
  		openFacultyQuery();
                admfacActions();
  		break;
  	case 2:
  		printf("You have Selected:\t\tGive Response\n");
                writeResponseFaculty();
                admfacActions();
  		break;
  	case 3:
  		printf("\nExiting to the back menu ");
                adminservices();
		break;
  	default:
  		printf("\nPlease Enter The correct options");
  		break;
            }

}
void stdActions()
{
int opt;
  printf("\nChoose any Action: \n1.Write Query \t2.View Response \t3.Exit\n");
  scanf("%d",&opt);
  switch(opt){
  	case 1:
  		printf("You have Selected:\t\tWrite Query \n ");
                storeStudentQuery();
                stdActions();
  		break;
  	case 2:
  		printf("You have Selected:\t\tView Response\n");
                ViewResponseStudent();
                stdActions();
  		break;
  	case 3:
  		printf("\nExiting to the back menu ");
		break;
  	default:
  		printf("\nPlease Enter The correct options");
  		break;
            }
}
void facActions()
{
int opt;
  printf("\nChoose any Action: \n1.Write Query \t2.View Response \t3.Exit\n");
  scanf("%d",&opt);
  switch(opt){
  	case 1:
  		printf("You have Selected:\t\tWrite Query \n ");
                storeFacultyQuery();
                facActions();
  		break;
  	case 2:
  		printf("You have Selected:\t\tView Response\n");
                ViewResponseFaculty();
                facActions();
  		break;
  	case 3:
  		printf("\nExiting to the back menu ");
		break;
  	default:
  		printf("\nPlease Enter The correct options");
  		break;
            }
}

void  ViewResponseStudent()
{
char ans;
write(1,"\n Viewing Response.... \n",25);
sleep(3);
int n,fd;
char buff[500];

fd=open("Queries/Student/response.txt",O_RDONLY,0777);
n=read(fd,buff,500);
write(1,buff,n);
close(fd);
}
void  ViewResponseFaculty()
{
char ans;
write(1,"\n Viewing Response.... \n",25);
sleep(3);
int n,fd;
char buff[200];
fd=open("Queries/Faculty/response.txt",O_RDONLY,0777);
n=read(fd,buff,200);
write(1,buff,n);
close(fd);
}
double  calculateTimetaken(clock_t start, clock_t end)
{
double cpu_time_used;
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
return cpu_time_used;
}
void summary()
{
printf("\nThe total Time taken By Student is %f seconds",stdTime);
printf("\nThe total Time taken By Faculty is %f seconds",facTime);
printf("\nThe total Time taken By Admin to handle student's query is %f seconds",admstdTime);
printf("\nThe total Time taken By Admin to handle faculty's query is %f seconds",admfacTime);
}
