#include<stdio.h>
#include<stdlib.h>
#define MAX 8


void insertionsort();
void selectionsort();
void bubblesort();
void display(int *);
void swap(int *, int *);

int main()
{
	int arr[MAX]={83,25,243,2,24,5,42,34};
	int i, j, key;
	int choice,noofelements;
	while(1)
	{
		printf("\n1. insertion sort\n");
		printf("\n2. Seletion sort");
		printf("\n3. Quick Sort");
		printf("\n4. Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
	switch(choice)
	{
		int i;
		case 1:	insertionsort();
				break;
		case 2: selectionsort();			
				break;
		case 3: bubblesort();					
				break;
		case 4: exit(1);
				break;
		default:printf("\n Invalid input!!!\n");
				break;
	}
    }
	return 0;
}



	
void insertionsort()
{
	int arr[MAX]={83,25,243,2,24,5,42,34};
	int i, j, key;
	
	printf("\nArray before sorting:\n");
	for( i = 0; i < MAX; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n\n\n");
	
	for(i=0; i< MAX; i++)
	{
		key = arr[i];
		j=i-1;
		while(j>=0 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j--; 
		}
		arr[j+1] = key;
	}
	
display(arr);	
}


  
void selectionsort()
{
	int arr[MAX]={83,25,243,2,24,5,42,34};
    int i, j, min_idx;
  
    // One by one move boundary of unsorted subarray
    for (i = 0; i < MAX-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < MAX; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
  
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
    display(arr);
}


void bubblesort()
{
	int arr[MAX]={83,25,243,2,24,5,42,34};
   int i, j;
   for (i = 0; i < MAX-1; i++)     
 
       // Last i elements are already in place  
       for (j = 0; j < MAX-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
              
    display(arr);
}


void display(int arr[])
{
	int i;
	for(i=0; i< MAX; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n==================================");
}



void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}





