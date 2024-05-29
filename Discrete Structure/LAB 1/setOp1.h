#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 20
#define L 5
int n;       //'n' is for the number of iteration to operate elements of set
int c=0;     // how many elements are in the result set

typedef struct PERSON{
    char name[20];                          
    int age;
    float degree_of_membership1;
    float degree_of_membership2;
}Person;

void set_in(int [],int );
void set_out(int [],int y);
void Union(int [],int [],int []);            // Takes input arrays (sets) NOTE: PERFORMS UNION OPERATION for 1st two array and puts the result into 3rd array
void Intersection(int [],int [],int []);     // Takes input arrays (sets) NOTE: PERFORMS AND OPERATION for 1st two array and puts the result into 3rd array
void Difference(int [],int [],int []);       // Takes input arrays (sets) NOTE: PERFORMS DIFFERENCE OPERATION for 1st two array and puts the result into 3rd array
void s_difference(int [],int [],int []);     // Takes input arrays (sets) NOTE: PERFORMS SYMTRICAL DIFFERENCE OPERATION for 1st two array and puts the result into 3rd array
void booll_into_result(int [],int [],int []);// Takes an Union set and the boolean_result and puts it into the 3rd array as final result
void initalitizing_set(int [],int [],int[]);
Person get_person(int );
void Fuzzy_union(float [],float [],float []);
void Fuzzy_intersection(float [],float [],float []);
void Fuzzy_complement(float [],float []);
float max(float, float);
float min(float, float);
void print_person(Person [],float []);
void set_in(int x[N], int y){
    int i;
    for(i=0;i<y;i++){
        printf("Enter element %d: ",i+1);
        scanf("%d",&x[i]);
    }
}
void set_out(int x[N],int y){
    int i;
    printf("\n\n\n\n");
    if(y!=0){
        printf("THE RESULTANT SET IS : \n{");
        for(i=0;i<y;i++){
            printf("%d, ",x[i]);
        }
        printf("\b\b}\n");
    }
    else{
    printf("The RESULTANT SET IS: \n{ NULL }");
    }
}
void initalitizing_set(int x1[N],int x2[N],int x3[N]){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(x1[i]==x2[j]){
                x3[i]=1;
                break;
            }
            else{
                x3[i]=0;
            }
        }
    }
}
void Union(int x1[N],int x2[N],int x3[N]){ 
    int i;
    for(i=0;i<n;i++){
        x3[i]= x1[i] || x2[i];
    }
}
void Intersection(int x1[N],int x2[N],int x3[N]){
    int i;
    for(i=0;i<n;i++){
        x3[i]= x1[i] && x2[i];
    }
}
void Difference(int x1[N],int x2[N],int x3[N]){
    int i;
    for(i=0;i<n;i++){
        x3[i]= x1[i] - x2[i];
    }
    
}
void s_difference(int x1[N], int x2[N], int x3[N])
{
    int i;
    int U[100],I[100];
    Union(x1,x2,U);
    Intersection(x1,x2,I);
    Difference(U,I,x3);
}
void booll_into_result(int x1[N], int x2[N],int x3[N]){
    int i;
    for(i=0;i<n;i++){
        x3[c]=(x1[i]*x2[i]);
        if (x3[c]!=0 && x3[c]>0){
            c++;
        }
    }
}
Person get_person(int x){
    Person result;
    printf("Enter the name of the person %d: ",x+1);
    scanf("%s",&result.name);
    printf("Enter the age of the person %d: ",x+1);
    scanf("%d",&result.age);
    if(result.age<=20){
        result.degree_of_membership1=1;
    }
    else if(result.age>20 && result.age<=30){
        result.degree_of_membership1=(30.00-result.age)/10.00;
    }
    else if(result.age>30){
        result.degree_of_membership1=0;
    }


    if(result.age<=15){
        result.degree_of_membership2=1;
    }
    else if(result.age>15 && result.age<=35){
        result.degree_of_membership2=(35.00-result.age)/20.00;
    }
    else if(result.age>35){
        result.degree_of_membership2=0;
    }
    return result;
}
void Fuzzy_union(float x1[L],float x2[L],float x3[L]){
    int i;
    for(i=0;i<L;i++){
        x3[i]=max(x1[i],x2[i]);
    }
}
void Fuzzy_intersection(float x1[L],float x2[L],float x3[L]){
    int i;
    for(i=0;i<L;i++){
        x3[i]=min(x1[i],x2[i]);
    }
}
void Fuzzy_complement(float x1[L],float x2[L]){
    int i;
    for(i=0;i<L;i++){
        x2[i]=1-x1[i];
    }
}
void print_person(Person x1[L],float x2[L]){
    int i;
    printf("THE RESULT IS: { (name, degree_of_membership),.....} \n{ ");
    for(i=0;i<L;i++){
        printf("(%s,%2f), ",x1[i].name,x2[i]);
    }
    printf("\b\b }");
}
float max(float x, float y){
    float z;
    if(x<y)
    {z=y;}
    else
    {z=x;}
    return z;

}
float min(float x, float y){
    float z;
    if(x>y)
    {z=y;}
    else
    {z=x;}
    return z;
}