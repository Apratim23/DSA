#include <stdio.h>
int main (){
    char name[100];
    int i=0;
    printf("Enter name: ");
    fflush(stdin);
    fgets(name, 100, stdin);
    for (i = 0; name[i] != '\0'; ++i);
  
    printf("Length of name is %d\n", i-1);
    int vo=0;
    char ch;
    for (i = 0; name[i] != '\0'; i++) {
 
        ch = name[i];
        if (ch == 'a' || ch == 'e'
            || ch == 'i' || ch == 'o'
            || ch == 'u')
            vo++;
    }
    printf("No. of vowels are: %d\n",vo);

    int sp=0;
    for (i = 0; name[i] != '\0'; i++) {
 
        ch = name[i];
        if (ch == ' ')
            sp++;
    }
    printf("No. of spaces are: %d\n",sp);
    

    return 0;
}
