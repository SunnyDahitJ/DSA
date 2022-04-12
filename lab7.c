#include<stdio.h>
#include<stdlib.h>

#define ARRAY_MAX 20

struct inventory
{
	int part_number;
	int quantity;
}part[ARRAY_MAX];

void insert(int loc, int num, int qty)
{
	part[loc].part_number = num;
	part[loc].quantity = qty; 
}
void search(struct inventory hash[])
{
	int key, key_index;
	printf("\n\n***SEARCHING***\nEnter a Product number to be search: ");
	scanf("%d", &key);

	key_index = key % ARRAY_MAX;
		
	while(key_index < ARRAY_MAX)
	{
		if(hash[key_index].part_number == key)
		{
			printf("\nQuantity Sold for searched product is : %d", hash[key_index].quantity);
			return;
		}
		else
		{
			key_index+=1;
		}
	}
	
	printf("\nProduct not found");
}
void hashing_table()
{
	struct inventory hash[ARRAY_MAX] = {0};
	int hashed_index, i, collision = 0;
	for(i = 0; i < ARRAY_MAX; i++)
	{
//MODULO DIVISION
		hashed_index = part[i].part_number % ARRAY_MAX;
check:
//Collision resolution using LINEAR PROBING
		if(hash[hashed_index].part_number == 0)
		{
			hash[hashed_index] = part[i];
		}
		else
		{
			collision++;
			hashed_index += 1;
			goto check;
		}
	}

	printf("\n\nNumber of Collisions are : %d", collision);

//DISPLAY HASH TABLE
	printf("\nThe Hashed Table is as follows: ");
	for(i = 0; i < ARRAY_MAX; i++)
	{
		printf("\n%d", hash[i].part_number);
		printf("--%d", hash[i].quantity);
	}
	
	search(hash);
}



int main()
{
	int i;
	
	insert(0,112,12);
	insert(1,130,30);
	insert(2,156,56);
	insert(3,173,17);
	insert(4,197,19);
	insert(5,150,50);
	insert(6,166,66);
	insert(7,113,13);
	insert(8,123,12);
	insert(9,143,14);
	insert(10,167,16);
	insert(11,189,18);
	insert(12,193,19);
	insert(13,117,11);
	insert(14,176,76);
	
	printf("\nThe Given Table is as follows: ");

	for(i = 0; i < ARRAY_MAX; i++)
	{
		printf("\n%d", part[i].part_number);
		printf("--%d", part[i].quantity);
	}
	
	hashing_table();
	
	return 0;
}
