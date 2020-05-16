#ifndef __SYMBOLTABLE__
#define __SYMBOLTABLE__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 200
#define MAXTOKENLEN 50

#define TRUE 1
#define FALSE 0

#define INT_TYPE 0
#define DOUBLE_TYPE 1
#define CHAR_TYPE 2 

typedef struct Node
{
	char name[MAXTOKENLEN];
	int type;

	int intVal;
	double doubleVal;
	char charVal;

	struct Node* next;
};

static struct Node* Table;

void Insert(int type, char* name, int lineNo)
{
	struct Node* temp;
	temp = Table;
	while (temp->next != NULL)
	{
		if (strcmp(name, temp->next->name) == 0)
			return;
		temp = temp->next;	
	}
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
	printf("defined new var %s \n", name);
	strcpy(newNode->name, name);
	newNode->type = type;
	newNode->next = NULL;
	temp->next = newNode;
}

struct Node* GetNode(char* name)
{
	struct Node* temp = Table->next;
	printf("first %s \n", temp->name);
	while ((strcmp(name, temp->name) != 0))
	{
		printf("get var %s \n", temp->name);
		temp = temp->next;
		if (temp == NULL)
			return NULL;
	}
	return temp;
}

//return value of symbol(name)
int GetValue(char* name)
{
	struct Node* temp = Table->next;

	while ((strcmp(name, temp->name) != 0))
	{
		temp = temp->next;
		if (temp == NULL)
			return -1;
	}
	
	return temp->intVal;
}
//set value(v) of symbol(name)
int SetValue(char* name, int v)
{
	struct Node* temp = Table->next;

	while ((strcmp(name, temp->name) != 0))
	{
		temp = temp->next;
		if(temp == NULL)
			return -1;
	}
	
	temp->intVal = v;
	return 0;
}
//get data type
int GetType(char* name)
{
	struct Node* temp = Table->next;

	while ((strcmp(name, temp->name) != 0))
	{
		temp = temp->next;
		if (temp == NULL)
			return -1;
	}

	return temp->type;
}
//set data type(t)
int SetType(char* name, int t)
{
	struct Node* temp = Table->next;

	while ((strcmp(name, temp->name) != 0))
	{
		temp = temp->next;
		if (temp == NULL)
			return -1;
	}

	temp->type = t;
	return 0;
}
#endif
