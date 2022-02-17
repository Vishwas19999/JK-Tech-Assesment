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
    fp=fopen("task.txt","w");
    if(fp==NULL)
    {
      printf("\nError opening the file\n");
      exit(1);
    }
    struct employee emp1={"Vishu",01,22};
    struct employee emp2={"Mahi",02,23};
    struct employee emp3={"SRK",03,24};
    fwrite(&emp1,sizeof(struct employee),1,fp);
    fwrite(&emp2,sizeof(struct employee),1,fp);
    fwrite(&emp3,sizeof(struct employee),1,fp);

     if(fwrite != 0)
      printf("Contents to file written successfully\n");
   else
      printf("Error writing file !\n");
      fclose(fp);
}
void read()
{
    struct employee emp;
    FILE *fp1;
   fp1= fopen ("task.txt", "r");
   if (fp1 == NULL)
   {
      printf("\nError to open the file\n");
      exit (1);
   }
   while((fread(&emp, sizeof(struct employee), 1, fp1)))
      printf ("name = %s id= %d age=%d\n", emp.name,emp.id,emp.age);
   fclose (fp1);
}
int main()
{
   write();
   read();
}
