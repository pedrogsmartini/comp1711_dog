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
    int d = 1;
    while (cnt <= n)
    {
        if (h==24)
        {
            h = 0;
            d++;
        }
        int j = 0;
        while (j <= 3 & cnt <= n)
        {
            if (h<10)
            {
                if (j == 0)
                {
                    fprintf(file,"2023-09-0%d,0%d:00,%d\n",d,h,cnt*150);
                }
                else
                {
                    fprintf(file,"2023-09-0%d,0%d:%d,%d\n",d,h,j*15,cnt*150);
                }
            }
            else
            {
                if (j == 0)
                {
                    fprintf(file,"2023-09-0%d,%d:00,%d\n",d,h,cnt*150);
                }
                else
                {
                    fprintf(file,"2023-09-0%d,%d:%d,%d\n",d,h,j*15,cnt*150);
                }
            }

            cnt++;
            j++;
            printf("j = %d\n",j);
        }
        h++;

    }
    fclose(file);
    return 0;
}