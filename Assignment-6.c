#include <stdio.h>
#include <string.h>

#define MAX 20 

char Stack[20];
int top = -1;

int IsEmpty()
{
    if(top == -1)
    { return 1; }
    else
    { return 0; }
}

void push(char Stack[20], char elem)
{
    top = top + 1;
    Stack[top] = elem;
}

char pop(char Stack[20])
{
    char elem = Stack[top];
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

void Infix_to_Postfix(char Infix[20], char Postfix[20])
{
  int i = 0, k = 0;
  char pst;
  
  while(Infix[i] != '$')
  {
    char sym = Infix[i];
    if((sym >= '0' && sym <= '9') || (sym >= 'A' && sym <= 'Z') || (sym >= 'a' && sym <= 'z'))
    {
      Postfix[k] = Infix[i];
      k++;
      i++;
    }
    else
    {
      if(sym == '(') 
      {
        push(Stack, sym);
        i++;
      }
      else
      {
        if(sym == ')') 
        {
            while((pst = pop(Stack)) != '(')
            {
                Postfix[k] = pst;
                k++;
            }
            i++;
        }
        else
        {
            while(IsEmpty() == 0 && ISP(Stack[top]) >= ICP(sym))
            {
                pst = pop(Stack);
                Postfix[k] = pst;
                k++; 
            }
            push(Stack, sym);
            i++;
        }
      }
    }
  }
  
  while(IsEmpty() == 0)
  {
    pst = pop(Stack);
    Postfix[k] = pst;
    k++;
  }
  Postfix[k] = '\0';
}

void Postfix_to_Infix(char Postfix[20], char Infix[20])
{
    char s[20][20];
    int top = -1;
    int i = 0;

    while (Postfix[i] != '$') 
    {
        char sym = Postfix[i];
        
        // If operand, push directly to stack
        if ((sym >= '0' && sym <= '9') || (sym >= 'A' && sym <= 'Z') || (sym >= 'a' && sym <= 'z')) 
        {
            top++;
            s[top][0] = sym;
            s[top][1] = '\0';
        } 
        else // If operator
        {
            char op2[20], op1[20], temp[40];
            strcpy(op2, s[top--]);
            strcpy(op1, s[top--]);
            
            // Build "(op1 + sym + op2)" manually without sprintf
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
        i++;
    }
    strcpy(Infix, s[top]);
}
void Prefix_to_Postfix(char Prefix[20], char Postfix[20])
{
    char s[20][20];
    int top = -1;
    int len = 0;
    
    while (Prefix[len] != '$') 
    {
        len++;
    }
    
    // Scan prefix expression from right to left
    int i = len - 1;
    while (i >= 0) 
    {
        char sym = Prefix[i];
        
        // If operand, push directly to stack
        if ((sym >= '0' && sym <= '9') || (sym >= 'A' && sym <= 'Z') || (sym >= 'a' && sym <= 'z')) 
        {
            top++;
            s[top][0] = sym;
            s[top][1] = '\0';
        } 
        else // If operator
        {
            char op1[20], op2[20], temp[40];
            strcpy(op1, s[top--]);
            strcpy(op2, s[top--]);
            
            // Build op1 + op2 + sym manually without sprintf
            int j = 0, k = 0;
            while (op1[k] != '\0') temp[j++] = op1[k++];
            k = 0;
            while (op2[k] != '\0') temp[j++] = op2[k++];
            temp[j++] = sym;
            temp[j] = '\0';
            
            top++;
            strcpy(s[top], temp);
        }
        i--;
    }
    strcpy(Postfix, s[top]);
}

int main()
{   
    int ch;
    char infix[20];
    char postfix[20];
    do
    {
    printf("Enter the operation to be performed:\n1. Infix to Postfix \n2. Postfix to Infix\n3. Prefix to Postfix\n");
    scanf("%d", &ch); 
    
    switch(ch)
    {
        case 1: 
               printf("Enter infix expression: ");
               scanf("%s", infix);
               Infix_to_Postfix(infix, postfix);
               printf("Postfix expression: %s\n", postfix);
               break;

        case 2: 
               printf("Enter Postfix expression: ");
               scanf("%s", infix);
               Postfix_to_Infix(infix, postfix);
               printf("Infix expression: %s\n", postfix);
               break;

        case 3: 
               printf("Enter Prefix expression: ");
               scanf("%s", infix);
               Prefix_to_Postfix(infix, postfix);
               printf("Postfix expression: %s\n", postfix);
               break;

        case 4:
               printf("Exiting...");
               break;

        default:
               printf("Invalid choice!\n");
    }
  }while(ch!=4);

  return 0;
}