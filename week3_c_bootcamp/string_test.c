#include <stdio.h>

int str_len (char* word)
{
    int cnt=-1;
    char var = 'o';
    while (var!='\0')
    {
        cnt++;
        var=word[cnt];
        
    }
    return cnt;
}
int main()
{
    char word[1000];
    printf("Please type a word:\n");
    scanf("%s", word); //pointer is already an adress, so dont need &
    int len = str_len(word);
    printf("The length %d \n",len);
    return 0;
}