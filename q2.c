#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
struct student
{
    char name[50];
    char roll[10];
    char email[10];

} s;

void myinfo(FILE *fp)
{

    printf("Enter my information:\n");
    printf("Enter name: ");
   scanf("%s",s.name);
    printf("Enter roll number: ");
   scanf("%s",s.roll);
    printf("Enter email: ");
    scanf("%s",s.email);
    printf("Displaying Information:\n");
    printf("Name: ");
    printf("%s", s.name);
    printf("\nRoll number: %s\n", s.roll);
    printf("Email: %s\n", s.email);

    
    fp = fopen("studentsdata.txt", "r+");
    fputs(s.name, fp);
    fputc('\n', fp);

    fputs(s.roll, fp);
    fputc('\n', fp);
    fputs(s.email, fp);
    fclose(fp);
    printf("Data Inserted Successfully\n");
}

void friendsinfo(FILE *fp)
{

    printf("Enter information:\n");
    printf("Enter name: ");
    scanf("%s",s.name);
    printf("Enter roll number: ");
    scanf("%s",s.roll);
    printf("Enter email: ");
    scanf("%s",s.email);
    printf("Displaying Information:\n");
    printf("Name: ");
    printf("%s", s.name);
    printf("\nRoll number: %s\n", s.roll);
    printf("Email: %s\n", s.email);

    
    fp = fopen("studentsdata.txt", "a");
    fputs(s.name, fp);
    fputs("\n", fp);
    fputs(s.roll, fp);
    fputs("\n", fp);
    fputs(s.email, fp);
    fclose(fp);
    printf("Data Inserted Successfully\n");
}

void readdata(FILE *fp,int r)
{
    
    char data[100];
   
    fp = fopen("studentsdata.txt", "r");
    int count = 0;
      char a=fgetc(fp);
    while (1)
    {

        if (count == r)
        {
          
            if(a=='0')
            {
                printf("No record found \n");
                break;
            }
            else
            {
                fclose(fp);
                fp = fopen("studentsdata.txt", "r");
                fgets(data, 100, fp);
                printf("Name: %s", data);
                fgets(data, 100, fp);
                printf("Rollno: %s", data);
                fgets(data, 100, fp);

                printf("Email: %s\n\n", data);
                break;
                
            }
            
        }
        else if(count==0&&a!='0')
        {
            
            fgets(data,100, fp);
            fgets(data,100, fp);
            fgets(data,100,fp);
            count=-1;
        }
        if(a=='0')
        {
            a=fgetc(fp);
        }

        fgets(data, 100, fp);
        printf("Name: %s\n", data);
         fgets(data,100, fp);
         printf("Rollno: %s\n", data);
         fgets(data,100,fp);
         printf("Email: %s\n\n", data);

     


        if(feof(fp))
        {
            break;
        }
    
    }
    fclose(fp);
}

void deletedata(FILE *fp,int val)
{

char data[100];
   
    fp = fopen("studentsdata.txt", "r");
     FILE *newfile;
    newfile = fopen("file.txt", "a");
   int count=0;
    while (1)
    {

        if (val == 0)
        {
            fputc('0',newfile);
            fputc('\n',newfile);
            fgets(data,100, fp);
            fgets(data,100, fp);
            fgets(data,100, fp);
           
           
            val=3;
        }
        else if (val == 1 || val == 2)
        {
            if (count != val)
            {
                fgets(data, 100, fp);
                fputs(data, newfile);
                fgets(data, 100, fp);
                fputs(data, newfile);
                fgets(data, 100, fp);
                fputs(data, newfile);
                count++;
            }
            else
            {
                fgets(data,100, fp);
                fgets(data,100, fp);
                fgets(data,100, fp);
                val=3;
            }
            
        }
        if (val == 3)
        {
            fgets(data, 100, fp);
            fputs(data, newfile);
            fgets(data, 100, fp);
            fputs(data, newfile);
            fgets(data, 100, fp);
            fputs(data, newfile);
        }

        if(feof(fp))
        {
            break;
        }
    
    }
    
    fclose(fp);
    remove("studentsdata.txt");
    fclose(newfile);
    rename("file.txt","studentsdata.txt");
}

int main()
{

    int input = -2;
    FILE *fp;

    while (input != 3)
    {
        printf("0:Add Students\n");
        printf("1:Read Students DATA\n");
        printf("2:Delete Students DATA\n");
        printf("3:Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &input);

        if (input == 0)
        {
            int inp = -1;

            printf("0:Add Your Data\n");
            printf("1:Add your friends Data\n");
            scanf("%d", &inp);
            if (inp == 0)
            {
                myinfo(fp);
            }
            else if (inp == 1)
            {
                friendsinfo(fp);
            }
            else
            {
                printf("Invalid INput\n");
            }
        }
        else if (input == 1)
        {
            int inp = -2;
            printf("0:Show your data\n");
            printf("1:Show your friends Data\n");
            scanf("%d", &inp);
            if (inp == 0)
            {
                readdata(fp,0);
            }
            else if (inp == 1)
            {
                readdata(fp,1);
            }
            else
            {
                printf("Invalid INput\n");
            }
        }

        else if (input == 2)
        {
            int inp = -2;
            printf("0:delete your data\n");
            printf("1 or 2:delete your friends Data\n");
            scanf("%d", &inp);
            if (inp == 0)
            {
              deletedata(fp,0);
            }
            else if (inp == 1||inp==2)
            {
                deletedata(fp,inp);
            }
            else
            {
                printf("Invalid INput\n");
            }
        }
        else if (input == 3)
        {
            printf("Terminating....\n");
        }
        else
        {
            printf("invalid input\n");
        }
    }
    return 0;
}