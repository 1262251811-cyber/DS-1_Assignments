#include <stdio.h>

int a[10][10], b[10][10], c[10][10];
int r1,c1,r2,c2;

void input(int x[10][10], int r, int c)
{
    int i,j;

    printf("Enter elements:\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&x[i][j]);
        }
    }
}

void display(int x[10][10], int r, int c)
{
    int i,j;

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d ",x[i][j]);
        }
        printf("\n");
    }
}

void addition()
{
    int i,j;

    if(r1!=r2 || c1!=c2)
    {
        printf("Addition not possible\n");
        return;
    }

    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            c[i][j]=a[i][j]+b[i][j];
        }
    }

    printf("Result:\n");
    display(c,r1,c1);
}

void subtraction()
{
    int i,j;

    if(r1!=r2 || c1!=c2)
    {
        printf("Subtraction not possible\n");
        return;
    }

    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            c[i][j]=a[i][j]-b[i][j];
        }
    }

    printf("Result:\n");
    display(c,r1,c1);
}

void multiplication()
{
    int i,j,k;

    if(c1!=r2)
    {
        printf("Multiplication not possible\n");
        return;
    }

    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            c[i][j]=0;
            for(k=0;k<c1;k++)
            {
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }

    printf("Result:\n");
    display(c,r1,c2);
}

void transpose()
{
    int i,j;

    printf("Transpose of Matrix A:\n");

    for(i=0;i<c1;i++)
    {
        for(j=0;j<r1;j++)
        {
            printf("%d ",a[j][i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice;

    printf("Enter rows and columns of Matrix A: ");
    scanf("%d%d",&r1,&c1);

    input(a,r1,c1);

    printf("Enter rows and columns of Matrix B: ");
    scanf("%d%d",&r2,&c2);

    input(b,r2,c2);

    do
    {
        printf("\n1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Transpose of Matrix A\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                addition();
                break;

            case 2:
                subtraction();
                break;

            case 3:
                multiplication();
                break;

            case 4:
                transpose();
                break;

            case 5:
                break;

            default:
                printf("Invalid Choice\n");
        }

    }while(choice!=5);

    return 0;
}