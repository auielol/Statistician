#include <stdio.h>
#include <stdlib.h>

#define bool int
#define TRUE 1
#define FALSE 0

void selection(int sel);

typedef bool Boolean;
typedef struct node *nodePtr;

struct node
{
	int data;
	nodePtr *next;
}NODE;

struct node *head, *tail;

typedef nodePtr Statistician, DataStore;

void doesNotExist();
bool isEmpty();

Statistician newStatistician();
void destroyStatistician(Statistician *s);
void add(Statistician s, int x);
void removeData(Statistician s, int x);
void displayData(Statistician s);

void maximum();
