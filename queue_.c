#include <stdio.h>
#include <stdlib.h>
#define MAX 50

void insert();
void delete ();
void display();
void add();

int queue_array[MAX];
int rear = -1;
int front = -1;
int cnt = 0;
int temp = 0;
int add_item = 0;
int sum = 0;
int main()
{
    int choice;
    while (1)
    {
        printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Add and Avg \n");
        printf("4.Display\n");
        printf("5.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Insert the element in queue : ");
            scanf("%d", &add_item);
            insert(add_item);
            break;
        case 2:
            delete ();
            break;
        case 3:
            add();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Wrong choice \n");
        }
    }
return 0;	
}

void insert(int add_item)
{
    if (rear == MAX - 1)
        printf("Queue Overflow \n");
    else
    {
        if (front == -1)
            front = 0;
        rear = rear + 1;
        if (add_item >= 0)
        {
            queue_array[rear] = add_item;
            cnt++;
        }
    }
}

void delete ()
{
    int a;
    if (front == -1)
    {
        printf("Queue Underflow \n");
        return;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", queue_array[front]);
        temp = queue_array[front];
        front = front + 1;
    }
}

void display()
{
    int i;
    if (front == -1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
}

void add()
{
    int i, a;
    float avg;
    for (i = front; i < cnt; i++)
    {
        delete ();
        sum = sum + temp;
        insert(temp);
        cnt--;
    }
    printf("\n%d", sum);
    avg = (float)sum / (cnt);
    a = cnt - front;
    printf("\n%f\n", avg);
}
