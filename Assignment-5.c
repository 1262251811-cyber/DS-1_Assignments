#include <stdio.h>
#include <stdlib.h>

struct polynomial{
    int coeff;
    int exp;
    struct polynomial *next;
}polynomial;

void Create(struct polynomial *head){
    struct polynomial *curr;
    struct polynomial *temp=head;
    int c;

    do{
        curr=(struct polynomial*)malloc(sizeof(struct polynomial));

        printf("Enter coefficient: ");
        scanf("%d",&curr->coeff);

        printf("Enter exponent: ");
        scanf("%d",&curr->exp);

        if(head->next==head){
            head->next=curr;
            curr->next=head;
        }
        else{
            while(temp->next!=head){
                temp=temp->next;
            }
            temp->next=curr;
            curr->next=head;
        }

        printf("Do you want to add another term? (1.Yes 0.No): ");
        scanf("%d",&c);

    }while(c==1);
}

void display(struct polynomial *head)
{
    struct polynomial *curr1=head->next;

    if(curr1==head){
        printf("Polynomial is empty\n");
    }
    else{
        while(curr1!=head){
            if(curr1->coeff<0){
                printf("%dx^%d",curr1->coeff,curr1->exp);
            }
            else if(curr1->coeff>0){
                if(curr1!=head->next){
                    printf("+%dx^%d",curr1->coeff,curr1->exp);
                }
                else{
                    printf("%dx^%d",curr1->coeff,curr1->exp);
                }
            }

            curr1=curr1->next;
        }
        printf("\n");
    }
}

void Add(struct polynomial *head1,struct polynomial *head2,struct polynomial *head3)
{
    struct polynomial *curr1=head1->next;
    struct polynomial *curr2=head2->next;
    struct polynomial *curr3;
    struct polynomial *temp=head3;

    while(curr1!=head1 && curr2!=head2){
        curr3=(struct polynomial*)malloc(sizeof(struct polynomial));

        if(curr1->exp==curr2->exp){
            curr3->coeff=curr1->coeff+curr2->coeff;
            curr3->exp=curr1->exp;
            curr1=curr1->next;
            curr2=curr2->next;
        }
        else if(curr1->exp>curr2->exp){
            curr3->coeff=curr1->coeff;
            curr3->exp=curr1->exp;
            curr1=curr1->next;
        }
        else{
            curr3->coeff=curr2->coeff;
            curr3->exp=curr2->exp;
            curr2=curr2->next;
        }

        if(curr3->coeff!=0){
            temp->next=curr3;
            curr3->next=head3;
            temp=curr3;
        }
        else{
            free(curr3);
        }
    }

    while(curr1!=head1)
    {
        curr3=(struct polynomial*)malloc(sizeof(struct polynomial));
        curr3->coeff=curr1->coeff;
        curr3->exp=curr1->exp;
        temp->next=curr3;
        curr3->next=head3;
        temp=curr3;
        curr1=curr1->next;
    }

    while(curr2!=head2)
    {
        curr3=(struct polynomial*)malloc(sizeof(struct polynomial));
        curr3->coeff=curr2->coeff;
        curr3->exp=curr2->exp;
        temp->next=curr3;
        curr3->next=head3;
        temp=curr3;
        curr2=curr2->next;
    }

    printf("Resultant polynomial is: ");
    display(head3);
}

int main()
{
    int c;
    struct polynomial *head1;
    struct polynomial *head2;

    head1=(struct polynomial*)malloc(sizeof(struct polynomial));
    head1->next=head1;

    head2=(struct polynomial*)malloc(sizeof(struct polynomial));
    head2->next=head2;

    do{
        printf("Enter operation to Perform\n1.Create first polynomial\n2.Create second polynomial\n3.Display first polynomial\n4.Display second polynomial\n5.Add polynomials\n6.Exit\n");
        scanf("%d",&c);

        switch(c){

            case 1:
            head1->next=head1;
            Create(head1);
            printf("First polynomial created succesfully\n");
            break;

            case 2:
            head2->next=head2;
            Create(head2);
            printf("Second polynomial created succesfully\n");
            break;

            case 3:
            printf("First polynomial is: ");
            display(head1);
            break;

            case 4:
            printf("Second polynomial is: ");
            display(head2);
            break;

            case 5:{
            struct polynomial *head3;
            head3=(struct polynomial*)malloc(sizeof(struct polynomial));
            head3->next=head3;
            Add(head1,head2,head3);
            break;
            }

            case 6:
            printf("EXITING........");
            break;

            default:
            printf("Invalid input\n");

        }

    }while(c!=6);

    return 0;
}