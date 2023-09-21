#include <stdio.h>

int main(){
    char mon[40];
    printf("Enter the month name (all small): ");
    scanf("%s",mon);
    switch (mon[0]){
        case 'j':
        if (mon[1]=='a'){
        printf("\n1");
        break;}
        else if (mon[2]=='l'){
            printf("\n7");
            break;
        }
        else if(mon[2]=='n'){
            printf("\n6");
            break;
        }
        else{
            printf("\nError month");
            break;
        }
        case 'f':printf("\n2");
        break;
        case 'm':
        if(mon[2]=='r'){printf("\n3");}
        else if(mon[2]=='y'){printf("\n5");}
        else{printf("\nWrong");}
        break;
        case 'a':
        if (mon[1]=='p'){
            printf("\n4");
        }
        else if(mon[1]=='u'){
            printf("\n8");
        }
        else{
            printf("Error month");
        }
        break;
        case 's':printf("\n9");
        break;
        case 'o':printf("\n10");
        break;

        case 'n':printf("\n11");
        break;
        case 'd':printf("\n12");
        break;
        default:
        printf("\nEnter correct month correctly (eg: january)");
        break;
        return 0;
    }
    
    




    return 0;
}
