#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float power(float x,float y);
float power_b(float x,float y);
void bas(char x[],int *s1,int *o1);
float my_atof(char *x);
void remove_spaces(char* s);
float *oparate(char *str);
int main()
{
    printf("By Muhammet Furkan ATALAY\n");
    printf("Calculator: ");
    char *a=malloc(250);
    gets(a);
    printf("%s = %.2lf",a,*oparate(a));
    return 0;
}
void remove_spaces(char* s) {
    const char* d = s;
    do {
        while (*d == ' ') {
            ++d;
        }
    } while (*s++ = *d++);
}
float power(float x,float y)            //Variables are respectively x is the number y is the power
{
    float r=1;
    for(int i=0;i<y;i++)
    {
        r=r*x;
    }
    return r;                     //Power of the x to the y
}
float power_b(float x,float y)            //Variables are respectively x is the number y is the power
{
    float r=1;
    for(int i=0;i<y;i++)
    {
        r=r/10;
    }
    return r;                     //Power of the x to the y
}
void bas(char x[],int *s1,int *o1)  //address of the digit number
{
    int s=0;
    int o=0;
    int i=0;
    while(x[i]!='\0')
    {
        if(x[i]=='.')
        {
            i++;
            while(x[i]!='\0')
            {
                o++;
                i++;
            }
            break;
        }
        s++;
        i++;
    }
    *s1=s;
    *o1=o;
}
float my_atof(char *x)
{
    int error=0;
    int i=0;
    while(x[i]!='\0')
    {
        if(48<=x[i]<=57 || x[i]==46)
        {
            i++;
        }
        else{
            error=1;
            break;
        }
    }
    int s1=0;
    int o1=0;
    bas( x,&s1,&o1);
    float num1=0;
    int p=s1;
    for(int j=0;j<s1;j++)
    {
        p--;
        float y=( x[j]-48)*power(10,p);
        num1=num1+y;
    }
    int b=s1+1;      //noktan sonraki index
    p=o1;
    for(int j=0;j<o1;j++)
    {

       float y=(x[b+j]-48)*power_b(10,j+1);
        num1=num1+y;
    }
    return num1;
}
float* oparate(char *str)
{
    remove_spaces(str);
    char *opindex=malloc(1);
    float *result=malloc(sizeof(float));
    *result=0;
    int i=0;
    while(str[i]!='\0')
    {
        if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/')
        {
            *opindex=str[i];
        }
        i++;
    }
    char *token=calloc(20,1);
    char *token1=calloc(20,1);
    i=0;
    while(str[i]!=*opindex)
    {
        token[i]=str[i];
        i++;
    }
    i++;
    int j=0;
    while(str[i]!='\0')
    {
        token1[j]=str[i];
        i++;
        j++;
    }
    if(*opindex=='+')
    {
        *result=my_atof(token) +my_atof(token1);
    }
    else if(*opindex=='-')
    {
        *result=my_atof(token) - my_atof(token1);
    }
    else if(*opindex=='*')
    {
        *result=my_atof(token)*my_atof(token1);
    }
    else if(*opindex=='/')
    {
        *result=my_atof(token)/my_atof(token1);
    }
    return result;
}

