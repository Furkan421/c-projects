//By Muhammet Furkan ATALAY 172010010010
//The main idea of this programme is taking infos from users and making unique squares with using star symbol.
//First I have tried to get infos from users and I check their possibility
//These possibilities are "checking edge size and their relations(outer have to be bigger than inner one)
//Also I have tried to use "even even" and "odd odd" rule with getting datas from user
//Finaly I have done make squares with taking output of stars.
#include <stdio.h>
#include <conio.h>

int main(){

    int margin;
    int a;
    int b;

    printf("Enter bigger edge");
    scanf("%d",&a);
    printf("Enter smaller edge");
    scanf("%d",&b);
    printf("Enter pozitif marigin:");
    scanf("%d",&margin);
    if(a*b % 2 == 0){
        printf("Enter bigger edge odd number again:");
        scanf("%d",&a);
        printf("Enter smaller edge odd number:");
        scanf("%d",&b);

    }
    else{
        while(a <= b){
            printf("bigger edge cannot be smaller than smaller edge\n");
            printf("Enter bigger edge");
            scanf("%d",&a);
            printf("Enter smaller edge");
            scanf("%d",&b);

            while(a < 0){
                printf("Bigger edge cannot be negatif\n");
                printf("Enter bigger edge");
                scanf("%d",&a);
                a++;
            }

            while(b < 0){
                printf("Smaller edge cannot be negatif\n");
                printf("Enter smaller edge");
                scanf("%d",&b);
                b++;
            }

        }
        int r,c,s,x,z,u,i,n;
        r = a-b;
        c = r/2;
        int marginx2;
        marginx2 = margin*2;
        for(i = 0; i<margin; i++){
            printf("\n");
        }
        for(x = 0; x < c; x++){
            for(s = 0; s < marginx2; s++){
                printf(" ");
            }
            for(s = 0; s < a; s++){
                printf("* ");

            }
            printf("\n");

        }
        for(x = 0; x < b; x++){
            for(s = 0; s < marginx2; s++){
                printf(" ");
            }
            for(s = 0; s < c; s++){
                printf("* ");
            }

            for(s = 0; s < b; s++){
                printf("  ");
            }

            for(s = 0; s < c; s++){
                printf("* ");
            }

            printf("\n");

        }

        for(x = 0; x < c; x++){
            for(s = 0; s < marginx2; s++){
                printf(" ");
            }
            for(s = 0; s < a; s++){
                printf("* ");
            }
            printf("\n");
        }
        for(i = 0; i<margin-1; i++){
            printf("\n");
        }

    }
    return 0;
}

