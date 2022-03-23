#include <stdlib.h>
#include <stdio.h>
     
void create();
void display();
void insert_begin();
void delete_neg();
 
 
struct node
{
        int info;
        struct node *next;
};
struct node *head = NULL;
int main()     
{
        int choice;
        while(1){
               
                printf("\n                MENU                            \n");
                printf("\n 1.Create/insert at end\n");
                printf("\n 2.Display \n");
                printf("\n 3.Insert at the beginning \n");
                printf("\n 4.Delete the node following a node with a negative key\n");
                printf("\n 5.Exit   \n");
                printf("\n--------------------------------------\n");
                printf("\nEnter your choice:");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                        create();
                                        break;
                        case 2:
                                        display();
                                        break;
                        case 3: 
                                        insert_begin();
                                        break;
                        case 4:
                                        delete_neg();
                                        break;
                        case 5:
                                        exit(1);
                                        break;
                        default:
                                        printf("\n Wrong Choice:\n");
                                        break;
                }
        }
        return 0;
}

void create()
{

	struct node *temp, *ptr;
	temp = (struct node *)malloc(sizeof(struct node));
	if(temp == NULL)
	{
		printf("Unable to allocate memory!!\n");
		exit(1);
	}
	printf("\n enter the element to be inserted :");
	scanf("%d", &temp->info);
	temp->next=NULL;
	if( head == NULL)
	{
		head = temp;
	}
	else
	{
		ptr = head;
		while(ptr->next!= NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = temp;
	}	
}

void insert_begin()
{
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nUnable to allocate memory!!\n");
                return;
        }
        printf("\nEnter the data value for the node:\t" );
        scanf("%d",&temp->info);
        temp->next =NULL;
        if(head==NULL)
        {
                head=temp;
        }
        else
        {
                temp->next=head;
                head=temp;
        }
}


void display()
{
	struct node *ptr;
	ptr=head;
	printf("\n The link list content is: ")
	while(ptr!=NULL)
	{	
		printf("%d ", ptr->info);	
		ptr= ptr->next;
	}	
}


void delete_neg()
{
	struct node *temp, *ptr;
	
	if( head == NULL)
	{
		printf("\nLinked list is empty\n");
		return;
	}
	else
	{
		ptr= head;
		while(ptr->info >= 0)
		{
			temp=ptr;
			ptr = ptr->next;
		}
		if(ptr==NULL)
		{
			printf("\n no item fpund after negative number\n");
			return;
		}
		// temp points to the node with -ve element after breaking out of the while loop
		temp = ptr;
		// go to the node after the -ve element
		ptr = ptr->next;
		// assign the address of -ve element to temp-link
//		temp->next=ptr;
		printf("\n delete elemet form the node: %d", ptr->info);
		if(ptr == NULL)
		{
			temp->next=NULL;
		}
		else
		// if the node deleted is not last node then link the -ve element node link of deleted node to point to nex element
		{
			temp->next = ptr->next; 
		}
	}
}
	



