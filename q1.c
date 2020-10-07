#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

    FILE *fp;
    int display;
    char arr[] = "q1_a.txt";
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
int count=0;
    while (1)
    {
        int display = fgetc(fp);
        if(display>='0'&&display<='9')
        {
            count++;
        }
        // end of file indicator
        if (feof(fp))
            break;

       
    }
    printf("The count is %d\n",count);

    return 0;
}