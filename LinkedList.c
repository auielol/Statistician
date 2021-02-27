#include "LL.h"

bool isEmpty()
{
		if (head == NULL)
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
}

void doesNotExist()
{
	system("cls");
	
	printf("\nNO EXISTING STATISTICIAN\n\n");
	
	system("pause");
	system("cls");
	
	return;
}

Statistician newStatistician()
{
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	
	newNode->data = NULL;
	newNode->next = NULL;
	
	head = newNode;
	head->next = NULL;
	tail = newNode;
	tail->next = NULL;
	
	printf("\nNEW STATISTICIAN CREATED SUCCESSFULLY\n");
}

void destroyStatistician(Statistician *s)
{
	struct node *curr = head;
	nodePtr *next = NULL;
	
	while (curr != NULL)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	head = NULL;
	
	printf("\nEXISTING STATISTICIAN SUCCESSFULLY DESTROYED\n");
}

void add(Statistician s, int x)
{
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	struct node *ptr;
	
	if (newNode == NULL)
	{
		printf("\nMemory cannot be allocated.");
		return;
	}
	else
	{
		newNode->data = x;
		newNode->next = NULL;
		tail->next = newNode;
		tail = newNode;
	}
	
}

void removeData(Statistician s, int x) {
	struct node *curr = head, *prev = NULL;
	int count = 0;
	
	while (curr != NULL)
	{
		if (curr->data == x)
		{
			if (prev == NULL)
			{
				head = curr->next;
			}
			else
			{
				prev->next = curr->next;
			}
		printf("\nDATA SUCCESSFULLY REMOVED\n");
		
		count = 1;
		free(curr);
		
		break;
		}
	prev = curr;
	curr = curr->next;
	}
	if (count == 0);
	{
		printf("\nDATA NOT FOUND\n");
	}
}

void displayData(Statistician s)
{
	struct node *ptr;
	ptr = head;
	
	ptr = ptr->next;
	
	printf("\nData : \n");
	while (ptr != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	maximum();
	printf("\n");	
}
