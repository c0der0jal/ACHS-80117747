#include<stdio.h>

int main(){
    int ceiling,floor;
    float n;
    printf("Enter a float number: ");
    scanf("%f",&n);
    if(n>0){
        ceiling=n+1;
        floor=n;
    }
    else{
        ceiling = n;
        floor = n-1;
    }
    printf("\nTHUS\nThe required ceiling and floor value of provided decimal input is: \n");
    printf("Ceiling = %d\nFloor= %d",ceiling, floor);
    return 0;
}