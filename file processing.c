#include <stdio.h>
#include <stdlib.h>
struct Point3D{   //Creating Structure
    float x;
    float y;
    float z;
};
void centerofmass(struct Point3D *mean,struct Point3D *obj,int count);  //Declaring function
int main()
{
    printf("By Muhammet Furkan ATALAY  172010010010\n");
    printf("This program find the mass of center object file's object\n");
    FILE* ptr;
    ptr=fopen("teapot.obj","r");  //Opening file
    char c;
    int count=0;
    while(!feof(ptr))
    {
        c=fgetc(ptr);
        if(c=='v')       //When it encounters 'v' it count
        {
        count++;
        }
    }
    fclose(ptr);     //Closing file
    struct Point3D *obj; //Opening structure in form of pointers
    obj=(struct Point3D*)malloc(count*sizeof(struct Point3D)); //Dynamic allocation
    ptr=fopen("teapot.obj","r"); //Opening file
    char c_or_f;
    float x1,y1,z1;
    int i=0;
    while(!feof(ptr))
    {
        fscanf(ptr,"%c %f %f %f \n",&c_or_f,&x1,&y1,&z1);
        if(c_or_f=='v')  //When line starts with 'v' write  it's length to the corresponding one
        {
            (obj+i)->x=x1;
            (obj+i)->y=y1;
            (obj+i)->z=z1;
            i++;
        }
    }
    struct Point3D *mean;
    mean=(struct Point3D*)malloc(count*sizeof(struct Point3D));
    centerofmass(mean,obj,count);  //Calling function*/

    printf("Center of mass : %f, %f, %f\n",mean->x,mean->y,mean->z);

    //********************************************************************
    struct Point3D *obj1; //Opening structure in form of pointers
    obj1=(struct Point3D*)malloc(9965*sizeof(struct Point3D)); //Dynamic allocation

    ptr=fopen("teapot.obj","r"); //Opening file
    char c_or_f_;
    float x1_,y1_,z1_;
    int i_=0;
    while(!feof(ptr))
    {
        fscanf(ptr,"%c %f %f %f \n",&c_or_f_,&x1_,&y1_,&z1_);
            (obj1+i_)->x=x1_;
            (obj1+i_)->y=y1_;
            (obj1+i_)->z=z1_;
            i_++;
    }
    printf("Please enter x y z value step by step");
    float x2,y2,z2;
    scanf("%f %f %f",&x2,&y2,&z2);
    for(int k=0;k<count;k++)
    {
        (obj1+k)->x=x2;
        (obj1+k)->y=y2;
        (obj1+k)->z=z2;
    }
    FILE *new_ob;
    new_ob=fopen("new_teapot.txt","w");
    for(int k=0;k<9964;k++)
    {
        if(k<3644)
        {
            fprintf(new_ob,"v %f %f %f\n",(obj1+k)->x,(obj1+k)->y,(obj1+k)->z);
        }
        else if(k==3644)
        {
            fprintf(new_ob,"\n");
        }
        else{
            fprintf(new_ob,"f %f %f %f\n",(obj1+k)->x,(obj1+k)->y,(obj1+k)->z);
        }
    }
    return 0;
}
void centerofmass(struct Point3D *mean,struct Point3D *obj,int count) //Creating function
{
    for(int i=0;i<count;i++)  //Summation of all dimension
    {
        mean->x=mean->x+(obj+i)->x;
        mean->y=mean->y+(obj+i)->y;
        mean->z=mean->z+(obj+i)->z;
    }
    mean->x=mean->x/count;   //Mean value of all dimension
    mean->y=mean->y/count;
    mean->z=mean->z/count;
}
