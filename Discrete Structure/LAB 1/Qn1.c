#include "setOp1.h"
int main(){
    int i,j,choice,n_A,n_B;
    //Integer array as the set inputs
    int set_U[N],set_A[N], set_B[N],set_result[N];
    //following arrays are the boolean sets for above respective input sets
    int bool_U[N],bool_A[N],bool_B[N], bool_result[N];
    printf("Enter the number of elements for universal set: ");
    scanf("%d",&n);
    printf("Now enter the elements of Universal Set: \n");
    set_in(set_U,n);
    for(i=0;i<n;i++){
        bool_U[i]=1;
    }
    printf("Enter the number of elements for A set: ");
    scanf("%d",&n_A);
    printf("Now enter the elements in Set_A (Which is subset of U_set): \nNOTE: PUT '0' IF THE ELEMENT DOESNT EXIST IN THE SET\n");
    set_in(set_A,n_A);
    printf("Enter the number of elements for B set: ");
    scanf("%d",&n_B);
    printf("Now enter the elements in Set_B (Which is subset of U_set): \nNOTE: PUT '0' IF THE ELEMENT DOESNT EXIST IN THE SET\n");
    set_in(set_B,n_B);
    initalitizing_set(set_U,set_A,bool_A);
    initalitizing_set(set_U,set_B,bool_B);
    while(choice!=99){
        printf("\n\n\n\nHi there, operate different boolean expn to these sets.");
        printf("\nPlease choose among following option \t\t(1-2-3-4-5)\nPERFORM FOLLOWING OPERATIONS\n");
        printf("1. A U B \n2. A n B \n3. A - B\n4. B - A\n5. A <> B\n6. Complement of A\n7.Complement of B\n8.EXIT\n: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
            Union(bool_A,bool_B,bool_result); //PERFORMS bool_result = bool_U || bool_A
            booll_into_result(set_U,bool_result,set_result);
            set_out(set_result,c);
            c=0;
            break;
            }
            case 2:{
            Intersection(bool_A,bool_B,bool_result); //PERFORMS bool_result = bool_U && bool_A
            booll_into_result(set_U,bool_result,set_result);
            set_out(set_result,c);
            c=0;
            break;
            }
            case 3:{
            Difference(bool_A,bool_B,bool_result); //PERFORMS bool_result = bool_U - bool_A
            booll_into_result(set_U,bool_result,set_result);
            set_out(set_result,c);
            c=0;
            break;
            }
            case 4:{
            Difference(bool_B,bool_A,bool_result); //PERFORMS bool_result = bool_U - bool_A
            booll_into_result(set_U,bool_result,set_result);
            set_out(set_result,c);
            c=0;
            break;
            }
            case 5:{
            s_difference(bool_A,bool_B,bool_result); //PERFORMS bool_result
            booll_into_result(set_U,bool_result,set_result);
            set_out(set_result,c);
            c=0;
            break;
            }
            case 6:{
            Difference(bool_U,bool_A,bool_result);
            booll_into_result(set_U,bool_result,set_result);
            set_out(set_result,c);
            c=0;
            break;
            }
            case 7: {
            Difference(bool_U,bool_B,bool_result); //PERFORMS bool_result = bool_U - bool_A
            booll_into_result(set_U,bool_result,set_result);
            set_out(set_result,c);
            c=0;
            break;
            }
            case 8:{
                return 0;
            }
            default:
            printf("Please enter from above given option.");
        }
    }
    return 0;
}