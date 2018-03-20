#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<string.h>

main()
{
char ans;
write(1,"WELCOME TO QUERY MANAGEMENT SYSTEM",35);
int time=30; //30 seconds
start:
printf("\nAre you Admin? ['y' for yes/'n' for no]");
read(0,ans,1);
if(ans=='y')
{char pass[20];
ps:
write(1,"Enter Password here=>",22);
read(0,pass,20);
if(strcmp(pass,"Admin123")==0)
{
printf("The List Of Queries");
}
else
{
printf("WRONG PASSWORD !!!");
goto ps;
}
}
else if(ans=='n')
{
struct dirent *de;
DIR *dr=mkdir("Queries",0777); //Directory for storing queries
int n,fd,n1;
char buff[]="\n";
char name[20];
char q[]="Query BY=> ";
write(1,q,11);
read(0,name,20);
strcat(q,name);
n1=strlen(q);
fd=open("Queries/query1.txt",O_CREAT|O_TRUNC|O_RDWR,0777);
write(fd,q,n1);
close(fd);
printf("Enter your queries here \n");
n=read(0,buff,200);  
fd=open("Queries/query1.txt",O_WRONLY|O_APPEND);
write(fd,buff,n);
close(fd);
}
else
{
printf("please give response in 'y' or 'n' \n");
goto start;
}
}
