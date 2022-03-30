#include<stdio.h>  
#include<stdlib.h>
#include<string.h>
#define MAX_LEN 100
  
typedef struct Mobile
{  
   char model[50];
   char brand[50];
   int memory;
   float price;
}mobile,temp;

int insert(int n1,mobile mb[])
{
	int i;
	for(i=0;i<n1;i++)
	{
		printf("\nEnter the Model");
		scanf("%s",&mb[i].model);
		printf("\nEnter brand?");
		scanf("%s",&mb[i].brand);
		printf("\nEnter memory?");
		scanf("%d",&mb[i].memory);
		printf("\nEnter price?");
		scanf("%f",&mb[i].price);
	}
 	
}

void display(int n1,mobile mb[])
{
	int i;
	printf("\nDisplaying the data:");
	for(i=0;i<n1;i++)
	{
		printf("\nModel:%s",mb[i].model);
		printf("\nBrand:%s",mb[i].brand);
		printf("\nMemory:%d",mb[i].memory);
		printf("\nPrice:%f",mb[i].price);
		printf("\n");
		printf("**");
	}
	
}

//Selection Sort 
void sortb(int n,int n1,mobile mb[],mobile temp)
{
    int i, j, min_idx;
  
    // One by one move boundary of unsorted subarray
    char minStr[MAX_LEN];
    for (i = 0; i < n1-1; i++)
    {
        // Find the minimum element in unsorted array
        int min_idx = i;
        strcpy(minStr, mb[i].brand);
        for (j = i+1; j < n1; j++)
        {
            // If min is greater than arr[j]
            if (strcmp(minStr, mb[j].brand) > 0)
            {
                // Make arr[j] as minStr and update min_idx
                strcpy(minStr, mb[j].brand);
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        if (min_idx != i)
        {
            char temp[MAX_LEN];
            strcpy(temp, mb[i].brand); //swap item[pos] and item[i]
            strcpy(mb[i].brand, mb[min_idx].brand);
            strcpy(mb[min_idx].brand, temp);
        }
    }
}
  



//Insertion sort
void sortp(int n1,mobile mb[],mobile temp)
{
	int i,j;
	printf("\nSorted on the basis of prices:");
	for (i = 1; i <=n1-1; i++){
      for (j = i; mb[j-1].price>mb[j].price; j--) {
            temp = mb[j];
            mb[j] = mb[j - 1];
            mb[j - 1] = temp;
      }
}
display(n1, mb);
}


void main()
{
	mobile mb[20]; 
	mobile temp;
	int choice;   
	int n, n1;
	while(choice != 5)   
    {      
        printf("\n1.Insert\n2.Display\n3.Sort on brand\n4.Sort on price\n5.Exit\n");  
        printf("\nEnter your choice : ");  
        scanf("%d",& choice);  
        switch(choice)  
        {  
            case 1:  
            printf("\nHow many will you enter?");
            scanf("%d",&n1);
            insert(n1, mb);
            break;   
            case 2:  
   			display(n1,mb);
   			break;
			case 3:
			sortb(n,n1,mb,temp);
			break;  
			case 4:
			sortp(n1,mb,temp);
			break;
			case 5:
			exit(0);
            default:   
            printf("\nEnter valid choice. . . .\n");  
            break;
        }  
    }  
}
