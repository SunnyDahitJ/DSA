#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct phon
{
    char model[20];
    char brand[20];
    int memory;
    float price;
} phone[5], temp;

int main()
{
    int choice;
    while (1)
    {
        //		struct phon phone;
        int i;

        printf("\nSructure Sorting\n");
        printf("1.Enter data\n");
        printf("2.Display data\n");
        printf("3.Sorting based on Brand\n");
        printf("4.Sorting based on Price\n");
        printf("5.Exit\n");

        printf("\n Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n Enter the data\n");
            for (i = 0; i < 2; i++)
            {
                printf("\nEnter Model: ");
                scanf("%s", phone[i].model);
                printf("\nEnter Brand: ");
                scanf("%s", phone[i].brand);
                printf("\nEnter memory:  ");
                scanf("%d", &phone[i].memory);
                printf("\nEnter price: ");
                scanf("%f", &phone[i].price);
            }
            break;

        case 2:
            printf("\n Displaying the Structure Data ");
            for (int i = 0; i < 2; i++)
            {
                printf("\n%s\t%s\t%d\t%f", phone[i].model, phone[i].brand, phone[i].memory, phone[i].price);
            }
            break;

        case 3:
            printf("\nSorting based on brand\n");
            for (int i = 1; i <= 2; i++)
            {
                for (int j = 0; j < 2 - i; j++)
                {
                    if (strcmp(phone[j].brand, phone[j + 1].brand) > 0)
                    {
                        temp = phone[j];
                        phone[j] = phone[j + 1];
                        phone[j + 1] = temp;
                    }
                }
            }

            printf("\n Displaying after Sorting based on brand\n");
            for (int i = 0; i < 2; i++)
            {
                printf("\n%s\t%s\t%d\t%f", phone[i].model, phone[i].brand, phone[i].memory, phone[i].price);
            }
            break;

        case 4:
            printf("\nSorting based on price ");
            for (int i = 1; i <= 2; i++)
            {
                for (int j = 0; j < 2 - i; j++)
                {
                    if ((phone[j].price, phone[j + 1].price) > 0)
                    {
                        temp = phone[j];
                        phone[j] = phone[j + 1];
                        phone[j + 1] = temp;
                    }
                }
            }
            printf("\n Displaying after Sorting based on brand\n");
            for (int i = 0; i < 2; i++)
            {
                printf("\n%s\t%s\t%d\t%f", phone[i].model, phone[i].brand, phone[i].memory, phone[i].price);
            }
            break;

        case 5:
            exit(1);
            break;

        default:
            printf("\nInvalid choice");
            break;
        }
    }
}
