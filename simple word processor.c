#include <stdio.h>
#include <stdlib.h>
int main()
{
    char mystr[250];

    printf("Enter  : ");
    gets(mystr);
    printf("%s\n",mystr);
    printf("Number of caracters : %d\n", strlen(mystr));

    int wordCount = 0;

    for(int i = 0; i < strlen(mystr)-1; i++) {
    if(mystr[i] == ' ' && isalpha(mystr[i+1]) && (i > 0)) {
            wordCount++;
        }
    }
    wordCount++;
    printf("Number of words : %d\n", wordCount);
    for (int i = 0; i < 80; i++) {
        mystr[0]=toupper(mystr[0]);
        if(mystr[i]==' '){
            mystr[i+1] = toupper(mystr[i+1]);
    }
    }
    printf("Reversed : %s\n", mystr);

    int len = strlen(mystr);
    int e = len-1;
    int s;
    printf("Capitalized : ");
    for(int a = len - 1; a >= 0; a--)
	{
		if(mystr[a] == ' ' || a == 0)
		{
			if(a == 0)
			{
				s = 0;
			}
			else
			{
				s = a + 1;
			}
			for(int j = s; j <= e; j++)
			{
				printf("%c", mystr[j]);
			}
			e = a - 1;
			printf(" ");
		}
	}
    return 0;
}
