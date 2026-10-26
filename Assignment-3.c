#include <stdio.h>

struct Employee 
{
    int empid;
    char name[20];
    float salary;
};

struct Employee emp[100];
int sorted = 0;   

void accept(struct Employee emp[], int n) 
{
    for (int i = 0; i < n; i++) 
	{
        printf("\nEmployee %d\n", i + 1);
        printf("ID: ");
        scanf("%d", &emp[i].empid);
        printf("Name: ");
        scanf("%s", emp[i].name);
        printf("Salary: ");
        scanf("%f", &emp[i].salary);
    }
}

void display(struct Employee emp[], int n) 
{
    printf("Employee Database:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("ID: %d ", emp[i].empid);
        printf("Name: %s ", emp[i].name);
        printf("Salary: %.2f\n", emp[i].salary);
    }
}

int linearSearch(struct Employee emp[], int n, int id) 
{
    for (int i = 0; i < n; i++) 
    {
        if (emp[i].empid == id) 
        {
            printf("Found at index %d\n", i);
            return i;
        }
    }
    printf("Not found\n");
    return -1;
}

int binarySearch(struct Employee emp[], int n, int id) 
{
    if (!sorted) 
    {
        printf("Sort the data before binary search.\n");
        return -1;
    }
    int l = 0, h = n - 1;
    while (l <= h) {
        int mid = (l + h) / 2;
        if (emp[mid].empid == id) {
            printf("Found at index %d\n", mid);
            return mid;
        } else if (emp[mid].empid > id) {
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    printf("Not found\n");
    return -1;
}

void bubbleSort(struct Employee emp[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (emp[j].empid > emp[j + 1].empid) 
			{
                struct Employee temp = emp[j];
                emp[j] = emp[j + 1];
                emp[j + 1] = temp;
            }
        }
    }
    sorted = 1;
    printf("Sorted successfully.\n");
}

void selectionSort(struct Employee emp[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
	{
        int min_index = i;
        for (int j = i + 1; j < n; j++) 
		{
            if (emp[j].empid < emp[min_index].empid) 
			{min_index = j;}
        }
        if (min_index != i) 
		{
            struct Employee temp = emp[i];
            emp[i] = emp[min_index];
            emp[min_index] = temp;
        }
    }
     sorted = 1;
    printf("Sorted successfully.\n");
}

void insertionSort(struct Employee emp[], int n) 
{
    for (int i = 1; i < n; i++) 
	{
        struct Employee key = emp[i];
        int j = i - 1;
        while (j >= 0 && emp[j].empid > key.empid) 
		{   emp[j + 1] = emp[j];
            j--;
        }
        emp[j + 1] = key;
    }
 sorted = 1;
    printf("Sorted successfully.\n");
}

void shellSort(struct Employee emp[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2) 
    {
        for (int i = gap; i < n; i++) 
        {
            struct Employee temp = emp[i];
            int j = i;
            while (j >= gap && emp[j - gap].empid > temp.empid) 
            {
                emp[j] = emp[j - gap];
                j -= gap;
            }
            emp[j] = temp;
        }
    }
    sorted = 1;
    printf("Sorted successfully.\n");
}

int main() 
{
    int ch, n, id;

    printf("Enter number of employees: ");
    scanf("%d", &n);
    accept(emp, n);

    do {
        printf("\n1.Accept\n2.Display\n3.Linear Search\n4. Binary Search\n5.Bubble Sort\n6.Selection Sort \n7.Insertion Sort \n8.Shell Sort \nEnter your Choice: ");
        scanf("%d", &ch);

        switch (ch) 
        {
            case 1:
                accept(emp, n);
                break;

            case 2:
                display(emp, n);
                break;

            case 3:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                linearSearch(emp, n, id);
                break;

            case 4:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                binarySearch(emp, n, id);
                break;

            case 5:
                bubbleSort(emp, n);
                display(emp, n);
                break;

            case 6:
                selectionSort(emp, n);
                display(emp, n);
                break;

            case 7:
                insertionSort(emp, n);
                display(emp, n);
                break;

            case 8:
                shellSort(emp, n);
                display(emp, n);
                break;

            case 9:
                printf("Exiting.\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (ch != 9);

    return 0;
}






