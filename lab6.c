#include<stdio.h>
#include<time.h>
int main()
{
	// generating 100 randam elements in range 1 to 200
	srand(time(0));
	int i,j, data, x,k; 
	float avg_success;
	float av;
	int s_count= 0;
	int ss_count= 0;
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
    {
		s_count++;
        if(a[k]==x)
        	ss_count++;
            break;
}
    if(k<100)
        printf("\n\nElement found at index %d",k);
    else
        printf("\n\nElement not found");
  
	
	printf("\n\n\n number of searches completed %d", s_count);
	printf("\n\nThe number of successful searches %d" , ss_count);
	avg_success = (ss_count / s_count) *100;
	av= (ss_count / s_count) ;
	
	printf("\n\n\n The average number of tests per search %d", av);
	
 	printf("\n\nThe percentage of successful searches %f" , avg_success);

   return 0;
}
