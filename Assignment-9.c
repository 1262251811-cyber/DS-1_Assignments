#include <stdio.h>

struct job {
    int jobid;
    char jt[10];
};

int isFull(int front, int rear, int size) 
{
    if ((rear + 1) % size == front)
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

int AddQ(struct job que[], int front, int rear, int size) 
{
    struct job temp;

    if (isFull(front, rear, size)) 
    {
        printf("Queue is full\n");
        return rear;
    }

    printf("Enter Job ID: ");
    scanf("%d", &temp.jobid);
    printf("Enter Job Title: ");
    scanf("%s", temp.jt);

    rear = (rear + 1) % size;
    que[rear] = temp;
    return rear;
}

int DeleteQ(struct job que[], int front, int rear, int size) 
{
    if (isEmpty(front, rear)) 
    {
        printf("Queue is empty!\n");
        return front;
    }

    front = (front + 1) % size;

    printf("Performing Job...\n");
    printf("Job ID: %d\n", que[front].jobid);
    printf("Job Title: %s\n", que[front].jt);
    printf("Job completed successfully!\n");

    return front;
}

int main() {
    struct job que[10];
    int size = 10;
    int front = 0;
    int rear = 0;
    int choice;

    do {
        printf("\nPRINT QUEUE\n");
        printf("1. Add Job\n");
        printf("2. Perform Job\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                rear = AddQ(que, front, rear, size);
                break;

            case 2:
                front = DeleteQ(que, front, rear, size);
                break;

            case 3:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while (choice != 3);

    return 0;
}