//user entering the data

#include<stdio.h>
#include<stdlib.h>
struct employee
{
   char name[20];
   int id;
   int age;
};
void write()
{
    FILE *fp;
    struct employee emp;
    fp=fopen("task1.txt","w");
    if(fp==NULL)
    {
      fprintf(stderr,"\nError opening the file\n");
      exit(1);
    }
    printf("enter employee details:\n");
    for(int i=0;i<3;i++)
    {
        printf("enter name:\n");
        scanf("%s",emp.name);
        printf("enter id:\n");
        scanf("%d",&emp.id);
        printf("enter age:\n");
        scanf("%d",&emp.age);
    }
      fclose(fp);
}
void read()
{
    struct employee emp;
   FILE *fp1;
   fp1= fopen ("task1.txt", "r");
   if (fp1 == NULL)
   {
      fprintf(stderr,"\nError to open the file\n");
      exit (1);
   }
   printf("employee details are:\n");
     for(int i=0;i<3;i++)
     {
         fscanf(fp1,"%s\n%d\n%d\n",1,emp.name,emp.id,emp.age);
         printf("name=%s\n",emp.name);
         printf("id=%d\n",emp.id);
         printf("age=%d\n",emp.age);
     }
   fclose (fp1);
}
int main()
{
   write();
   read();
}
