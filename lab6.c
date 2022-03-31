#include<stdio.h>

int main()
{
	// generating 100 randam elements in range 1 to 200
	int i,j, data, x,k; 
	int a[100];
	for(i = 0; i<100; i++)
	{	
		data= (rand() % ((200  - 1)+1));
        printf(" %d ", data);
 		a[j] = data;
 	}
 	
 	
    x= (rand() % ((200  - 1)+1));
    printf("\n\n element to be searched is %d", x);
    for(k=0;k<100;++k)
        if(a[k]==x)
            break;
     
    if(k<100)
        printf("\n\nElement found at index %d",k);
    else
        printf("\n\nElement not found");
  

    return 0;
}
