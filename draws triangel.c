#include <stdio.h>
#include <stdlib.h>


int main() {
	printf("By Muhammet Furkan Atalay 172010010010\n");
	printf("First assignment prints a triangle using char numbers\n");
	printf("Second assignment taking input from the user and does the math\n ");
	printf("How programs work is written in consol");
	
	printf("First assignment:\n");
	int first_c = 47;
	int second_c = 92;
	int c3 = 45;
	
	printf("%5c%c\n",first_c,second_c);
	printf("%4c%3c\n",first_c,second_c);
	printf("%3c%5c\n",first_c,second_c);
	printf("%2c%7c\n",first_c,second_c);
	printf("%2c%c%c%c%c%c%c%c\n",c3,c3,c3,c3,c3,c3,c3,c3);
	 
	
	printf("Second assignment\n");
	
	float first_number;
	float second_number;
	float result;
	char Operator;
	int equal = 61;
	printf("Enter first number and enter operator then enter second number:\n");
	scanf("%f %c %f",&first_number,&Operator,&second_number);
	
	if(Operator == '+'){
		result = first_number + second_number;
		printf("%.2f %c %.2f %c %.2f",first_number,Operator,second_number,equal,result);
	}
	else if(Operator == '-'){
		result = first_number - second_number;
		printf("%.2f %c %.2f %c %.2f",first_number,Operator,second_number,equal,result);
	}
	else if(Operator == '*'){
		result = first_number * second_number;
		printf("%.2f %c %.2f %c %.2f",first_number,Operator,second_number,equal,result);
	}
	else if(Operator == '/'){
		result = first_number / second_number;
		printf("%.2f %c %.2f %c %.2f",first_number,Operator,second_number,equal,result);
	}
	else{
        printf("Follow the steps correctly");
    }

	
	return 0;
}
