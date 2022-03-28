/**************************************************************************
*	Registernumber:2147135
*   Name :Sunny Dahit
*	lab 4- part A
*
*
**************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#define size 20

void create(int);//works
void display(int);//works
//void sort_brand();
void sort_price(int);//works

struct mobile
{
	char model_name[size];
	char brand_name[size];
	int mem_cap;
	float price;
	struct mobile *link;
};


struct mobile *ptr = NULL;
int main()
{	
	int choice,noofelements;
	while(1)
	{
		printf("\n1. Add mobile detail\n");
		printf("\n2. display details");
		printf("\n3. sort the list based on brands and display details");
		printf("\n4. sort the list based on price display details");
		printf("\n5. Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
	switch(choice)
	{
		int i;
		case 1: printf("\nEnter the no of elements: ");
				scanf("%d", &noofelements);
				ptr = (struct mobile *)malloc(noofelements*sizeof(struct mobile));
				create(noofelements);
				break;
		case 2: display(noofelements);			
				break;
//		case 3: sort_brand();					
//				break;
		case 4: sort_price(noofelements);
				break;
		case 5: exit(1);
				break;
		default:printf("\n Invalid input!!!\n");
				break;
	}
}
	
	return 0;
}

void create(int noofelements)
{
	int i;
	for(i=0;i<noofelements; i++)
		{
			printf("\n Enter the Model Name: ");
			scanf("%s", &(ptr + i)->model_name);
			printf("\n Enter the brand name: ");
			scanf("%s", &(ptr + i)->brand_name);
			printf("\n Enter the memory size: ");
			scanf("%d", &(ptr + i)->mem_cap);
			printf("\n Enter the price: ");
			scanf("%f", &(ptr + i)->price);
			printf("\n %d st set of element inserted\n\n", i+1);
		}
}

void display(int noofelements)
{
	int i;
	for(i=0;i<noofelements; i++)
	{
		printf("Model Name\t:%s\t\n", (ptr + i)->model_name);
		printf("brand name\t:%s\t\n", (ptr + i)->brand_name);
		printf("memory capacity\t:%d\t\n", (ptr + i)->mem_cap);
		printf("price\t:%.2f\t\n", (ptr + i)->price);
		printf("\n\n\n");
	}
}


void sort_price(int noofelements) 
{
	struct mobile *temp_node;
	temp_node = ptr;
	int i,j;
	float key;
  	for (i = 1; i <= noofelements-1; i++) 
	  {
    		key	= (temp_node + i)->price;
    		j = i-1;
    		while( j>=0 && ((temp_node + j)->price > key))
    		{
    			(temp_node + j +1)->price = (temp_node + j)->price;
    			j--;
			}
			(temp_node + j +1)->price = key;
      }
	for(i = 0; i < noofelements; i++)
	{
		printf("Model Number\t:%s\t\n", (ptr + i)->model_name);
		printf("Brand name\t:%s\t\n", (ptr + i)->brand_name);
		printf("Memory size\t:%d\t\n", (ptr + i)->mem_cap);
		printf("Price\t:%.2f\t\n", (ptr + i)->price);
		printf("\n\n\n");
	}
}


//void sort_brand(int noofelements)
//{
//	struct mobile *temp_node;
//	int i, j;
//	char key[size];
//  for (i = 1; i <= noofelements-1; i++) 
//  {
//  	key[size]= (temp_node + i)->brand_name;
//  	j = i-1;
//    while(j>=0 && (temp_node + j)->brand_name > key)
//	{
//    	(temp_node + j +1)->brand_name = (temp_node + j)->brand_name;
//    	j--;
//	}
//	(temp_node + j +1)->brand_name = key;
//  }
//	for(i = 0; i < noofelements; i++)
//	{
//		printf("Model Number\t:%s\t\n", (ptr + i)->model_name);
//		printf("Brand name\t:%s\t\n", (ptr + i)->brand_name);
//		printf("Memory size\t:%d\t\n", (ptr + i)->mem_cap);
//		printf("Price\t:%.2f\t\n", (ptr + i)->price);
//		printf("\n\n\n");
//	}	
//    
//}
