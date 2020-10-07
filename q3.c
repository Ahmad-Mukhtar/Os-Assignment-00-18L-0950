#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>



void revereseArray(char arr[], int start, int end)
{
    char temp;
   
    while (start < end)
    {
        temp = arr[start];   
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }   

 
 
}     




int main(int argc, char *argv[])
{

    FILE *fp;
    FILE  *inv;
    int display;
    char arr[] = "q1_b.txt";
    if (argc == 2)
    {
        if (*argv[1] > 'c')
        {

            printf("Argument not valid on command line using default file\n");
        }

        else
        {
            
        arr[3] = *argv[1];
        }
        
    }
    else
    {
        printf("Argument not valid on command line using default file\n");
    }

    fp = fopen(arr, "r");
    inv=fopen("invertedfile.txt","a");

    char ar[100];
    int j=0;
    while (1)
    {
        fgets(ar,100,fp);
       
       for(int i=0;ar[i]!='\0';i++)
       {
           if (ar[i] == 'a' || ar[i] == 'e' || ar[i] == 'i' || ar[i] == 'o' || ar[i] == 'u')
           {
               while (ar[i] != ' '&&ar[i]!='\0')
               {
                   i++;
                  
               }
               revereseArray(ar, j, i - 1);
           }
           if (ar[i] == ' ')
           {
               j = i + 1;
           }

          
     

        }

       printf("the array is %s\n",ar);
     
        fputs(ar,inv);
        fputc('\n',inv);
        // end of file indicator
        if (feof(fp))
            break;

       
    }
    
    fclose(fp);
    fclose(inv);
    return 0;
}