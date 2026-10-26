#include <stdio.h>
#include <string.h>

int top = -1;
int stack[20];

int IsEmpty()
{
    if(top == -1)
    { return 1; }
    else
    { return 0; }
}

void push(int Stack[20], int elem)
{
    top = top + 1;
    Stack[top] = elem;
}

int pop(int Stack[20])
{
    int elem = Stack[top];
    top -= 1;
    return elem;
}

int ISP(char ch)
{
    if(ch == '(')
    { return 0; }
    else if (ch == '^')
    { return 4; }
    else if (ch == '*' || ch == '/' || ch == '%')
    { return 2; }
    else if (ch == '+' || ch == '-')
    { return 1; }
    else
    { return -1; }
}

int ICP(char ch)
{   
    if(ch == '(')
    { return 5; }
    else if (ch == '^')
    { return 3; }
    else if (ch == '*' || ch == '/' || ch == '%')
    { return 2; }
    else if (ch == '+' || ch == '-')
    { return 1; }
    else
    { return -1; }
}

void Postfix_to_Infix(char Postfix[20], char Infix[20])
{
    char s[20][20];
    int top = -1;
    int i = 0;

    while (Postfix[i] != '$') 
    {
        char sym = Postfix[i];
        
        if ((sym >= '0' && sym <= '9') || (sym >= 'A' && sym <= 'Z') || (sym >= 'a' && sym <= 'z')) 
        {
            top++;
            s[top][0] = sym;
            s[top][1] = '\0';
        } 
        else 
        {
            char op2[20], op1[20], temp[40];
            strcpy(op2, s[top--]);
            strcpy(op1, s[top--]);
            
            int j = 0, k = 0;
            temp[j++] = '(';
            
            while (op1[k] != '\0')
            { temp[j++] = op1[k++];}
            temp[j++] = sym;
            
            k = 0;
            while (op2[k] != '\0')
            {temp[j++] = op2[k++];}
            temp[j++] = ')';
            temp[j] = '\0';
            
            top++;
            strcpy(s[top], temp);
        }
        i++;
    }
    strcpy(Infix, s[top]);
}

void Prefix_to_Infix(char Prefix[20], char Infix[20])
{
    char s[20][20];
    int top = -1;

    int len = 0;
    while (Prefix[len] != '$' && Prefix[len] != '\0') {
        len++;
    }

    int i = len - 1;
    while (i >= 0) 
    {
        char sym = Prefix[i];
        
        if ((sym >= '0' && sym <= '9') || (sym >= 'A' && sym <= 'Z') || (sym >= 'a' && sym <= 'z')) 
        {
            top++;
            s[top][0] = sym;
            s[top][1] = '\0';
        } 
        else 
        {
            char op1[20], op2[20], temp[40];
            
            strcpy(op1, s[top--]);
            strcpy(op2, s[top--]);
            
            int j = 0, k = 0;
            temp[j++] = '(';
            
            while (op1[k] != '\0') temp[j++] = op1[k++];
            temp[j++] = sym;
            
            k = 0;
            while (op2[k] != '\0') temp[j++] = op2[k++];
            temp[j++] = ')';
            temp[j] = '\0';
            
            top++;
            strcpy(s[top], temp);
        }
        i--;
    }
    strcpy(Infix, s[top]);
}


int main()
{
    char expr[20];
    char infix[40];
    int ch;

    printf("Expression Converter & Solver \n");
    printf("1. Postfix Expression\n");
    printf("2. Prefix Expression\n");
    printf("Enter your choice : ");
    scanf("%d", &ch);

    printf("Enter the expression (must end with $): ");
    scanf("%s", expr);

    switch (ch)
    {
        case 1:
        {
            Postfix_to_Infix(expr, infix);
            printf("\nConverted Infix Expression: %s\n", infix);

            top = -1;
            int i = 0;

            while (expr[i] != '$' && expr[i] != '\0')
            {
                char sym = expr[i];

                if (sym >= '0' && sym <= '9')
                {
                    push(stack, sym - '0');
                }
                else if (sym == '+' || sym == '-' || sym == '*' ||
                         sym == '/' || sym == '%')
                {
                    int op2 = pop(stack);
                    int op1 = pop(stack);
                    int res = 0;

                    if (sym == '+')
                    res = op1 + op2;
                    else if (sym == '-') 
                    res = op1 - op2;
                    else if (sym == '*') 
                    res = op1 * op2;
                    else if (sym == '/') 
                    res = op1 / op2;
                    else if (sym == '%') 
                    res = op1 % op2;

                    push(stack, res);
                }

                i++;
            }

            printf("Evaluated Result: %d\n", pop(stack));
            break;
        }

        case 2:
        {
            Prefix_to_Infix(expr, infix);
            printf("\nConverted Infix Expression: %s\n", infix);

            top = -1;
            int len = 0;

            while (expr[len] != '$' && expr[len] != '\0')
            {
                len++;
            }

            int i = len - 1;

            while (i >= 0)
            {
                char sym = expr[i];

                if (sym >= '0' && sym <= '9')
                {
                    push(stack, sym - '0');
                }
                else if (sym == '+' || sym == '-' || sym == '*' ||
                         sym == '/' || sym == '%')
                {
                    int op1 = pop(stack);
                    int op2 = pop(stack);
                    int res = 0;

                    if (sym == '+') 
                    res = op1 + op2;
                    else if (sym == '-') 
                    res = op1 - op2;
                    else if (sym == '*')
                    res = op1 * op2;
                    else if (sym == '/')
                    res = op1 / op2;
                    else if (sym == '%') 
                    res = op1 % op2;

                    push(stack, res);
                }

                i--;
            }

            printf("Evaluated Result: %d\n", pop(stack));
            break;
        }

        default:
        {
            printf("Invalid choice!\n");
            break;
        }
    }

    return 0;
}
