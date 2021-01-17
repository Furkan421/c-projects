#include <stdio.h>
#include <stdlib.h>
unsigned long long int power(int x,int y);
int digit_count(int x);
unsigned long long int encode(int x);
int decode(int x);
int main(){
    printf("By Muhammet Furkan ATALAY\n");
    printf("Please follow the instructions below\n");
    printf("Enter 'e' either 'E' for encode or enter 'd' either 'D' for decode or enter 'q' either 'Q' for quit:\n");
    char x;                        //Declaring variable for the choice that is decided by users
    int y;                         //Declaring variable for number that is entered by users
    scanf("%c",&x);                //Inputting the variable 'x' from users
    int check=0;
    while (check<1){
        if(x=='e' || x=='E')           //If statement for encode
        {
            printf("Enter  at least five digits positive number to encode: \n");
            scanf("%d",&y);            //Inputting variable number from users
            if(check_encode(y)==1){            //Checking whether the entered number is positive and has a maximum of 5 digits
                printf("%llu",encode(y));
                check++;
            }
            else
            {
                printf("You need to enter max 5 digits positive integer number\nplease try again");
            }
        }
        else if(x=='d' || x=='D'){       //If statement for decoding
            printf("Enter at least five digits positive  number to decode: \n");
            scanf("%d",&y);              //Inputting variable number from users
            if(check_decode(y)==1)              //Checking whether the entered number is positive and has a maximum of 5 digits
            {
                if(encode(decode(y))==y){
                printf("%d",decode(y));   //decoding number with using decode() function
                check++;
    }
            else{
                printf("This number not suitable for decoding please try again");
    }
            }
            else
            {
                printf("You need to enter max 15 digits positive integer number\nplease try again");
            }
        }
        else if(x=='q' || x=='Q'){
        printf("Good By");
        check++;
    }
        else{
            printf("Wrong input please try again\n");
            printf("Enter 'e' either 'E' for encode or enter 'd' either 'D' for decode or enter 'q' either 'Q' for quit:\n");
            fflush(stdin);
            scanf("%c",&x);
        }
    }
    return 0;
}
unsigned long long int encode(int x){
    int p=0;
    unsigned long long int number=0;
    int digit_num=digit_count(x);
    for(int i=0;i<digit_num;i++){
        int digit=x%10;
        int recap=digit%3;
        x=x/10;
        for(int j=p;j<=(recap+p);j++){
            number=number+digit*power(10,j);
        }
        p=p+recap+1;
    }
    return number;
}
int decode(int x)
{   int fur=0;
    int ata=0;
    while(x>1)
    {
        int digit=x%10;
        int recap=digit%3;
        ata=ata+digit*power(10,fur);
        for(int i=0 ;i<=recap;i++)
        {
              x=x/10;
        }
        fur++;
    }
    return ata;
}
int digit_count(int x)    //Determining how many digits the given number has
{
    int i=0;
    while(x>=1)
    {
        x=x/10;
        i++;
    }
    return i;
}
unsigned long long int power(int x,int y)            //Variables are respectively x is the number y is the power
{
    unsigned long long int r=1;
    for(int i=0;i<y;i++)
    {
        r=r*x;
    }
    return r;                     //Power of the x to the y
}
int check_encode(int x)     //Function which check given number is positive and having at least 5 digits
{
    if(x<=99999)        //If given number is bigger or equal to the 99999 that means it has at least five digits and it is positive
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int check_decode(int x)     //Function which check given number is positive and having at least 15 digits
{
    if(x<=999999999999999)        //If given number is bigger or equal to the 999999999999999 that means it has at least fifteen digits and it is positive
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
