#include "setOp1.h"
int main(){
    int i,j;
    int set_A[N],set_B[N],n_A,n_B;
    printf("%30s","HI THERE, I'll HELP YOU FIND THE CARTESIAN PRODUCT OF 2 sets\n");
    printf("Enter the number of elements in set A: ");
    scanf("%d",&n_A);
    printf("Now enter the elements in Set_A (Which is subset of U_set):\n");
    set_in(set_A,n_A);
    printf("Enter the number of elements in set B: ");
    scanf("%d",&n_B);
    printf("Now enter the elements in Set_A (Which is subset of U_set):\n");
    set_in(set_B,n_B);
    printf("\nThe Cartesian product of given sets is :\n{ ");
    for(i=0;i<n_A;i++){
        for(j=0;j<n_B;j++){
            printf("(%d,%d), ",set_A[i],set_B[j]);
        }
    }
    printf("\b\b }");
    printf("\nTHANK YOU\n");
}
