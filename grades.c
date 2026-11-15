#include <stdio.h>
#include <string.h>
int main()
{int con=0;
    char header[200],id[10],name[50],target[50];
    float grade[5], sum=0,avg =0;
    int found=0;
    FILE *f =fopen("stu.csv","r");
       if (f==NULL)
    {printf("file not found!");
    return 1;}
   
   do{
    sum=0;
    found=0;
    rewind(f);

   fgets(header,200,f);

    printf("Enter student ID or number : ");
    scanf(" %49[^\n]",target);


while (fscanf(f," %9[^,],%49[^,],%f,%f,%f,%f,%f",id,name,&grade[0],&grade[1],&grade[2],&grade[3],&grade[4] )==7){
        if(strcasecmp(id , target)==0 || strcasecmp(name, target)==0)
                {for (int i=0;i<5;i++)
                 {sum += grade[i];}}
avg=sum/5;

printf("Avarage = %.2f\n",avg);


float max = grade[0];
float min = grade[0];

for(int i=0 ;i<5;i++)
    {
    if(grade[i]>max){max=grade[i];}
    if(grade[i]<min){min=grade[i];}
   }

printf("Max=%.2f\n",max);
printf("Min=%.2f\n",min);

found =1;
break;
}




if (found == 0)
    {printf("Student not found !\n");}

    

printf("Do you want to Enter another name or ID number (Y=1/N=0)");
scanf("%d",&con);}
while (con == 1);
fclose(f);
return 0;}


