#include "setOp1.h"

int main(){
    int i,choice=0;
    Person p1[L];
    float member_ship_set_1[L],member_ship_set_2[L];
    float set_result[L];
    printf("HEY THERE!\nPlease Enter the name and age of 5 people.\n");
    for(i=0;i<L;i++){
        p1[i]=get_person(i);
        member_ship_set_1[i]=p1[i].degree_of_membership1;
        member_ship_set_2[i]=p1[i].degree_of_membership2;
    }
    for(i=0;i<5;i++){
        printf("%f,%f\n",p1[i].degree_of_membership1,p1[i].degree_of_membership2);
    }
    printf("Thank for the information.\n");
    while(choice!=99){
        printf("\nYou can perform Following FUZZY SETS OPERATION \t\t\t(1-2-3-4-5)\n");
        printf("1. Fuzzy Union\n2. Fuzzy Intersection\n3. Complement A\n4.Complement B\n5. Exit\n: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
            Fuzzy_union(member_ship_set_1,member_ship_set_2,set_result);
            print_person(p1,set_result);
            break;
            }
            case 2:{Fuzzy_intersection(member_ship_set_1,member_ship_set_2,set_result);
            print_person(p1,set_result);
            break;
            }
            case 3:{
            Fuzzy_complement(member_ship_set_1,set_result);
            print_person(p1,set_result);
            break;
            }
            case 4:{
            Fuzzy_complement(member_ship_set_2,set_result);
            print_person(p1,set_result);
            break;
            }
            case 5:{
            return 0;
            }
            default:
            printf("\nPlease enter above given numbers.\n");
        }
    }
    return 0;
}


