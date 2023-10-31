#include<stdio.h>

int main()
{
    char filename[] = "timelines.md";
    FILE *file = fopen(filename,"w");
    if (filename == NULL)
    {
        perror("No such file!");
        return 1;
    }
    int n;
    printf("Choose number of lines:\n");
    scanf("%d",&n);
    int h = 7;
    int cnt = 1;
    while (cnt <= n)
    {
        int j = 1;

        while (j <= 4)
        {
            printf("%d\n",j);
            if (j=1)
            {
                fprintf(file,"2023-09-01,0%d:00,150\n",h);
                cnt++;
                j++;
            }
            else
            {
                fprintf(file,"2023-09-01,0%d:%d,150\n",h,j*15);
                cnt++;
                j++;
            }
            h++;

        }

    }
    fclose(file);
    return 0;
}