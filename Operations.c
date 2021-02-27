#include "LL.h"

void maximum()
{
	int a[10];
	int i;
	
	struct node *ptr = head;
	
	int max = ptr->data;
	
	while (ptr != NULL)
	{
		if (max < ptr->data)
		{
			max = ptr->data;
		}
		
		ptr = ptr->next;
	}
	printf("\nMaximum Number: %d",max); 
}
