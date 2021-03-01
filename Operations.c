#include "LL.h"

int getLength(Statistician s)
{
	int length = 0;
	struct node *ptr = head;
	
	while (ptr != NULL)
	{
		length++;
		ptr = ptr->next;
	}
	
	return length;
}

int minimum(Statistician s, int length)
{
	int i;
	
	struct node *ptr = head;
	
	int min = ptr->data;
	
	while (ptr != NULL)
	{
		if (min > ptr->data)
		{
			min = ptr->data;
		}
		
		ptr = ptr->next;
	}
	
	return min;
}

int maximum(Statistician s, int length)
{
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
	
	return max;
}

int range(Statistician s, int min, int max)
{
	int range;
	
	range = max - min;
	
	return range;
}

float getMean(Statistician s)
{
	int count = 0;
	int sum = 0;
	float mean = 0.0;
	
	struct node *currentNode = head;
	
	while (currentNode != NULL)
	{
		count++;
		sum += currentNode->data;
		currentNode = currentNode->next;
	}
	
	mean = (double)sum / count;
	
	return mean;
}

float getMedian(Statistician s)
{
	int sum = 0;
	float median = 0.0;
	
	struct node *ptr1 = head, *ptr2 = head, *prev = head, *ptr3;
	
	if (head != NULL)
	{
		while (ptr2 != NULL && ptr2->next != NULL)
		{
			ptr3 = ptr2->next;
			ptr2 = ptr3->next;
			prev = ptr1;
			ptr1 = ptr1->next;
		}
		
		if ((getLength(s) % 2) != 0)
		{
			median = ptr1->data;
			return median;
		}
		else
		{
			sum = ptr1->data + prev->data;
			median = (double)sum/2;
			return median;
		}
	}
}

DataStore mode(Statistician s)
{
	int mod;
	
	mod = modeArray(getLength(s));
	
	return mod;
}

int modeArray(int length)
{
	int mode;
	int a[length];
	int i = 0;
	
	struct node *ptr = head;
	
	while (ptr != NULL)
	{
		a[i++] = ptr->data;
		ptr = ptr->next;
	}
	
	mode = getArrMode(a, length);
	
	return mode;
}

int getArrMode(int a[], int len)
{
	int i, j, minIndex, temp, count, countMode;
	int num = a[len];
	int mode = num;
	
	for(i = 0; i < len; i++)
	{
		minIndex = i;
		
		for (j = i + 1; j < len; j++)
		{
			if(a[j] < a[minIndex])
			{
				minIndex = j;
			}
		}
		
		temp = a[minIndex];
		a[minIndex] = a[i];
		a[i] = temp;
	}
	
	mode = num;
	
	for(i = 1; i < len; i++)
	{
		if (a[i] == num)
		{
			count++;
			
			if (count > countMode)
			{
				countMode = count;
				mode = num;
			}
		}
		else
		{
			count = 1;
			num = a[i];
		}
	}
	
	if (countMode == 1)
	{
		mode = -1;
	}
	
	return mode;
}

float getVariance(Statistician s, int length)
{
	int i, sum, mean;
	float sumSqr, var;
	
	struct node *ptr = head;
	
	length = getLength(s);
	
	int a[length];
	
	while (ptr != NULL)
	{
		a[i++] = ptr->data;
		ptr = ptr->next;
	}
	
	mean = getMean(s);
	
	for (i = 0; i < length; i++)
	{
		sumSqr += (a[i] - mean)*(a[i] - mean);
	}
	
	var = sumSqr / length;
	
	return var;
}

float standardDeviation(Statistician s)
{
	int length;
	
	float var = getVariance(s, length);
	float sdv = sqrt(var);
	
	return sdv;
}
