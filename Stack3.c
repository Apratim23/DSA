#include <stdio.h>//for printf(), scanf(), gets(), strcat()
#include <stdlib.h>//for exit()
#include <ctype.h>//for isdigit() and isalpha()

#define MAX_SIZE 100

char stack[max];
int top = -1;

void push(char item)
{
    if (top == max - 1)//if the stack is full
    {
        printf("Stack Overflow\n");
        exit(1);
    } else
    {
        top++;
        stack[top] = item;
    }
}

char pop()
{
    char item;
    if (top == -1)//if the stack is empty
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    else
    {
        item = stack[top];//item = stack[0]
        top--;//top = -1
        return item;
    }
}

int is_operator(char s)
{
    if (s == '+' || s == '-' || s == '*' || s == '/' || s == '^')//if s is an operator
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int precedence(char sy)
{
    if (sy == '^')//if sy is ^ since ^ has the highest precedence
    {
        return 3;
    }
    else if (sy == '*' || sy == '/')//if sy is * or / since * and / have the same precedence
    {
        return 2;
    }
    else if (sy == '+' || sy == '-')//if sy is + or - since + and - have the same precedence
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void infix_to_postfix(char infix[], char postfix[])
{
    int i = 0;
    int j = 0;
    char item;
    char x;

    push('(');//push a ( to the stack
    strcat(infix, ")");//add a ) to the end of the infix expression
    item = infix[i];//item = infix[0] = 1

    while (item != '\0')//while item is not the null character
    {
        if (item == '(')//if item is (
        {
            push(item);//push ( to the stack
        }
        else if (isdigit(item) || isalpha(item))//if item is a digit or a letter
        {
            postfix[j] = item;//postfix[0] = 1
            j++;//j = 1
        }
        else if (is_operator(item) == 1)
        {
            x = pop();//x = stack[0] = (
            while (is_operator(x) == 1 && precedence(x) >= precedence(item))//while x is an operator and the precedence of x is greater than or equal to the precedence of item
            {
                postfix[j] = x;
                j++;
                x = pop();//x = stack[0] = (
            }
            push(x);
            push(item);
        }
        else if (item == ')')//if item is )
        {
            x = pop();
            while (x != '(')//while x is not (
            {
                postfix[j] = x;//postfix[1] = 1
                j++;//j = 2
                x = pop();
            }
        }
        else
        {
            printf("Invalid infix expression\n");
            exit(1);
        }
        i++;
        item = infix[i];//item = infix[1] = +
    }

    if (top > 0)
    {
        printf("Invalid infix expression\n");
        exit(1);
    }

    postfix[j] = '\0';
}

int main()
{
    char infix[max];
    char postfix[max];

    printf("Enter infix expression: ");
    gets(infix);//infix = 1+2

    infix_to_postfix(infix, postfix);//postfix = 12+

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
