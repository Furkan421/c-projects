#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct student{
    char name[40];
    char surname[40];
    int number;
    float midterm_grade;
    float final_grade;
    float course_grade;
    int degisken;
};

void show_directive();
void new_record(struct student *);
void find_record(struct student *);
void show_statistic(struct student *);

int main(){

    char choose;
    int var = 0;

    struct student guide[100];
    guide[0].number = -1;

    while(var == 0){
        show_directive();
        scanf("%s",&choose);

        switch(choose){
            case  'a' :
                new_record(guide);
                break;
            case  'A' :
                new_record(guide);
                break;
            case  'f' :
                find_record(guide);
                break;
            case  'F' :
                find_record(guide);
                break;
            case  's' :
                show_statistic(guide);
                break;
            case  'S' :
                show_statistic(guide);
                break;
            case  'q' :
                var = 1;
                printf("pres any key to exit");
                break;
            case  'Q' :
                var = 1;
                printf("pres any key to exit");
                break;
            default:
                printf("wrong enter");
        }
        getch();
    }
    return 0;
}
void show_directive(){
    system("cls");
    printf("By Muhammet Furkan ATALAY 172010010010\n");
    printf("Grade calculator\n");
    printf("please just follow the instructions\n");
    printf("Grade Calculator Menu :\n");
    printf("--------------------------\n");
    printf("'a' or 'A' for add new record\n");
    printf("'f' or 'F' for find a record\n");
    printf("'s' or 'S' for show basic statistics\n");
    printf("'q' or 'Q' for quit\n");
    printf("\choose your select :\n ");
}
void new_record(struct student *guide){
    int s;
    for(s = 0; s<100; s++){
        if(guide[s].number == -1){
            break;
        }
    }
        printf("student name : \n");
        scanf("%s", guide[s].name);
        printf("student surname : \n");
        scanf("%s", guide[s].surname);
        printf("student number : \n");
        scanf("%d",&(guide[s].number));
        printf("midterm grade : \n");
        scanf("%f",&(guide[s].midterm_grade));
        printf("final grade : \n");
        scanf("%f",&(guide[s].final_grade));
        guide[s].course_grade = ((guide[s].midterm_grade*0.4) + (guide[s].final_grade*0.6));
        guide[s+1].number = -1;
        printf("The person is registered.");
}
void find_record(struct student *guide){
    int a;
    printf("what is the student's number : ");
    scanf("%d",&a);
    for(int s = 0; s < 100; s++){
        if(guide[s].number == a){
            printf("%s %s\n",guide[s].name,guide[s].surname);
            printf("midterm grade : %.2f\n",guide[s].midterm_grade);
            printf("final grade : %.2f\n",guide[s].final_grade);
            printf("course grade : %.2f\n",guide[s].course_grade);
            if(guide[s].course_grade>60){
            printf("Passed");
        }
            else{
                printf("failed");
            }
        }
    }
}

void show_statistic(struct student *guide){
        int s = 0;
        while(guide[s].number != -1){
                s++;
        }
        printf("number of students :  %d\n",s);

        float total = 0;
        int number_pas = 0;

        for(int i = 0; i < s; i++){
            total =total + guide[i].course_grade;
            if(guide[i].course_grade>60){
                number_pas++;
            }
        }
        printf("number of passed students : %d\n",number_pas);
        int number_failed = s - number_pas;
        printf("number of failed students : %d\n",number_failed);
        float avarage;
        avarage = total/s;
        printf("course avarage : %.2f",avarage);
}
