#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
    char name[30];
    int regno;
    struct student *next;
}student;

void Add(struct student *head){
    struct student *curr;
    struct student *temp = head->next;
    curr = (struct student*)malloc(sizeof(struct student));


    printf("Enter name of student: ");
    scanf("%s",curr->name);

    printf("Enter regno. of student: ");
    scanf("%d", &curr->regno);


    if(head->next==NULL){
        head->next=curr;
    }
    else{
        while(temp->next !=NULL){

            temp=temp->next;

        }
        temp->next=curr;
    }

    curr->next=NULL;

}

void delete(struct student *head){
    if(head->next==NULL){
        printf("List is Empty\n");
    }
    else{
    char name[30];

    printf("Enter student name to delete: ");
    scanf("%s", name);

    struct student *curr = head->next;
    struct student *prev = head;

    while (curr != NULL)
    {
        if (strcmp(curr->name, name) == 0)
        {
            prev->next = curr->next;
            free(curr);
            printf("Student deleted succesfully \n");
            return;
        }

        prev = curr;
        curr = curr->next;
    }

    if(curr == NULL){
    printf("Student not found\n");
    }
    }
}

void display(struct student *head){

    if(head->next==NULL){
        printf("List is empty\n");
    }
    else{
    struct student *curr=head->next;

    while(curr!=NULL){
        printf("Address of current node is: %p\n",(void*)curr);
        printf("Name of students is: %s\n",curr->name);
        printf("Student's Registration no. is: %d\n",curr->regno);
        printf("Address of next node is: %p\n",(void*)curr->next);
        curr=curr->next;
    }
    }


}

void count(struct student *head){
    int count=0;
    struct student *curr=head->next;

    while(curr!=NULL){
        count++;
        curr=curr->next;
    }

    printf("Total participants are: %d \n",count);
}

void sort(struct student *head){
    struct student *curr;
    struct student *temp;
    char name[30];
    int regno;

    for(curr=head->next;curr!=NULL;curr=curr->next){
        for(temp=curr->next;temp!=NULL;temp=temp->next){
            if(strcmp(curr->name,temp->name)>0){
                strcpy(name,curr->name);
                strcpy(curr->name,temp->name);
                strcpy(temp->name,name);

                regno=curr->regno;
                curr->regno=temp->regno;
                temp->regno=regno;
            }
        }
    }

    printf("List sorted succesfully\n");
}

void reverse(struct student *head){
    struct student *prev=NULL;
    struct student *curr=head->next;
    struct student *next=NULL;

    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }

    head->next=prev;
    printf("List reversed succesfully\n");
}

int main(){
    int c;
    struct student *head;
    head = (struct student*)malloc(sizeof(struct student));
    head->next=NULL;

    do{
    printf("Enter operation to Perform\n1.Add student\n2.Delete student\n3.Display \n4.Count participants\n5.Sort list\n6.Reverse list\n7.Exit\n");
    scanf("%d",&c);

    switch(c){

        case 1:
        Add(head);
        printf("Student added succesfully.....\n");
        break;

        case 2:
        delete(head);
        break;

        case 3:
        printf("Displaying cotents of linked list......\n");
        display(head);
        break;

        case 4:
        count(head);
        break;

        case 5:
        sort(head);
        break;

        case 6:
        reverse(head);
        break;

        case 7:
        printf("EXITING........");
        break;

        default:
        printf("Invalid input");

    }
 }while(c!=7);

    return 0;
}