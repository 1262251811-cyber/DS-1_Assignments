#include <stdio.h>


struct job {
    int jobid;
    char jt[10];
};

int isFull(int rear,int size) 
{
    if (rear == size)
        return 1;
    else
        return 0;
}

int isEmpty(int front, int rear) 
{
    if (front == rear)
        return 1;
    else
        return 0;
}

int AddQ(struct job que[], int rear,int size) 
{
    struct job temp;

    if (isFull(rear,size)) 
    {
        printf("Queue is full");
        return rear;
    }

    printf("Enter Job ID: ");
    scanf("%d", &temp.jobid);
    printf("Enter Job Title: ");
    scanf("%s", temp.jt);

    rear++;
    que[rear] = temp;
    return rear;
}

int DeleteQ(struct job que[], int front, int rear) 
{
    if (isEmpty(front, rear)) 
    {
        printf("Queue is empty!");
        return front;
    }

    printf("Performing Job...");
    printf("Job ID: %d\n", que[front].jobid);
    printf("Document: %s\n", que[front].jt);

    front++;

    printf("Job completed successfully!\n");

    return front;
}

int main() {
    struct job que[10];
    int size=10;
    int front=0;
    int rear=0;
    int ch;

    do {
        printf("\nPRINT QUEUE\n");
        printf("1. Add Job\n");
        printf("2. Perform Job\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) 
        {
            case 1:
                rear = AddQ(que,rear,size);
                break;

            case 2:
                front = DeleteQ(que,front,rear);
                break;

            case 3:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while (ch != 3);

    return 0;
}