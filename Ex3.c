#include "student.h"
#include<string.h>
#include<stdlib.h>
int main()
{
    while(0)
{
    printf("Student Manager\n\n");
    printf("Please select one of following options here:\n");
    printf("1. Student list.\n");
    printf("2. Add a student.\n");
    printf("3. Find student.\n");
    printf("4. Exit.\n");
    printf("Your choice is: ");
    int x;
    scanf("%d", &x);
    switch(x)
    {
        case 1:
        {
            viewlist();
            break;
        }
        case 2:
        {
            sv newstudent;
            addstudent(&newstudent);
            break;
        }
        case 3:
        {
            char findstudent[MAX];
            printf("Who are you looking for?\n");
            fflush(stdin);
            gets(findstudent);
            search(findstudent);
            break;
        }
        case 4:printf("Goodbye.");return 0;
    }
    printf("Press any key to continue...");
}
}

void addstudent(sv *newstudent)
{
    printf("Name: ");
    fflush(stdin);
    gets(newstudent->name);
    printf("ID: ");
    scanf("%d",&(newstudent->ID));
    printf("Score: ");
    scanf("%lf",&(newstudent->score));
    FILE *fptr;
    fptr=fopen("SV2021.dat","ab");
    fprintf(fptr,"%s\t",newstudent->name);
    fprintf(fptr,"%d\t",newstudent->ID);
    fprintf(fptr,"%.2lf\n",newstudent->score);
    fclose(fptr);
    printf("Done!\n");
}
void viewlist()
{
    FILE *fptr;
    fptr=fopen("SV2021.dat","rb");
    char info;
    while(info != EOF)
    {
        info=getc(fptr);
        printf("%c",info);
    }
    fclose(fptr);
}
void search(char name[MAX])
{
    FILE *fptr1,*fptr2;
    fptr1=fopen("SV2021.dat","rb");
    fptr2=fopen("output.txt","a");
    char info[100];
    int found=0;
    fprintf(fptr2,"Search result for %s:\n",name);

    while(fgets(info,100,fptr1)!=NULL)
    {
        if(strstr(info,name)!=NULL)
        {
            printf("%s",info);
            fprintf(fptr2,"%s",info);
            found=1;
            }
    }
    if(found==0)
    {
        printf("Sorry, not found!\n");
        fprintf(fptr2,"Sorry, not found!\n");
    }
    fclose(fptr1);
    fclose(fptr2);
}
