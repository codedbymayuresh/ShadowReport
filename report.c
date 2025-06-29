#include <stdio.h>
#include<string.h>


typedef struct report
{
    char name[100];
    int roll;
    float marks[6];
    float total;
    float percent;
    char grade;
}rp ;

void addstudent(rp *s);


int main(){
    int n;
    printf("enter number of how many students data , u need to store : ");
    scanf("%d", &n);

    getchar();
    
    

    rp students[n];

    //opening/creating file
    FILE *fptr;
    fptr = fopen("data.txt","w");
    for(int i=0;i<n;i++){
        addstudent(&students[i]);

    

    //saving data to a file
    fprintf(fptr,"Name : %s \n", students[i].name);
    fprintf(fptr,"Roll : %d \n", students[i].roll);
    fprintf(fptr,"marks(maths) : %f \n", students[i].marks[0]);
    fprintf(fptr,"marks(phy) %f \n", students[i].marks[1]);
    fprintf(fptr,"marks(chem) %f \n", students[i].marks[2]);
    fprintf(fptr,"marks(eng) %f \n", students[i].marks[3]);
    fprintf(fptr,"marks(ec1) %f \n", students[i].marks[4]);
    fprintf(fptr,"marks(ec2) %f \n", students[i].marks[5]);
    fprintf(fptr,"total marks : %f \n", students[i].total);
    fprintf(fptr,"percentage : %f \n", students[i].percent);
    fprintf(fptr,"grade : %c \n", students[i].grade);

    
    }
    //closing a file
    fclose(fptr);

    
    
    return 0;
}

void addstudent(rp *s){
    //input data
    printf("enter your name : ");
    fgets(s->name,100,stdin);

    //remove trailing newline
    size_t len=strlen(s->name);
    if(len>0 && s->name[len-1] == '\n'){
        s->name[len-1]='\0';
    }
    printf("enter your roll no : ");
    scanf("%d", &s->roll);
    printf("enter your marks in maths : ");
    scanf("%f", &s->marks[0]);
    printf("enter your marks in phy : ");
    scanf("%f", &s->marks[1]);
    printf("enter your marks in chem : ");
    scanf("%f", &s->marks[2]);
    printf("enter your marks in english : ");
    scanf("%f", &s->marks[3]);
    printf("enter your marks in ec1 : ");
    scanf("%f", &s->marks[4]);
    printf("enter your marks in ec2 : ");
    scanf("%f", &s->marks[5]);

    //calculate total marks
    s->total=0;
    for(int j=0;j<6;j++){
        s->total += s->marks[j];
    }

    //percentage calc
    s->percent= (s->total)*100/600 ;

    //grade
    if(s->percent>=90.0){
        s->grade ='A';
    } else if(s->percent>=80 && s->percent<=90){
        s->grade = 'B';
    }else if(s->percent>=70 && s->percent<=80){
        s->grade = 'C';
    }else if(s->percent>=60 && s->percent<=70){
        s->grade = 'D';
    }else if(s->percent>=0 && s->percent<=60){
        s->grade = 'E';
    }

    getchar();


    
}