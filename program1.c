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
    struct employee emp[3];
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
        scanf("%s",&emp[i].name);
        printf("enter id:\n");
        scanf("%d",&emp[i].id);
        printf("enter age:\n");
        scanf("%d",&emp[i].age);
        fprintf(fp,"%s\n%d\n%d\n",emp[i].name,&emp[i].id,&emp[i].age);
    }
      fclose(fp);
}
void read()
{
    struct employee emp[3];
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
         printf("name=%s\n",emp[i].name);
         printf("id=%d\n",emp[i].id);
         printf("age=%d\n",emp[i].age);
         fscanf(fp1,"%s\n%d\n%d\n",&emp[i].name,&emp[i].id,&emp[i].age);
     }
   fclose (fp1);
}
int main()
{
   write();
   read();
}
