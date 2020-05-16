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
#define FLOAT_TYPE 3

typedef char* string;

typedef struct _Node
{
	char name[MAXTOKENLEN];
	int type;

	int intVal;
	double doubleVal;
	char charVal;

	struct _Node* next;
} * Node;

static Node Table;

void Insert(int type, string name, int lineNo)
{
	Node temp;
	temp = Table;
	while (temp->next != NULL)
	{
		if (strcmp(name, temp->next->name) == 0)
			return;
		temp = temp->next;	
	}
	Node newNode = (Node)malloc(sizeof(Node));
	strcpy(newNode->name, name);
	newNode->type = type;
	newNode->next = NULL;
	temp->next = newNode;
}

Node GetNode(string name)
{
	Node temp = Table->next;
	while ((strcmp(name, temp->name) != 0))
	{
		temp = temp->next;
		if (temp == NULL)
			return NULL;
	}
	return temp;
}

//return value of symbol(name)
int GetValue(string name)
{
	Node temp = Table->next;

	while ((strcmp(name, temp->name) != 0))
	{
		temp = temp->next;
		if (temp == NULL)
			return -1;
	}
	
	return temp->intVal;
}
//set value(v) of symbol(name)
int SetValue(string name, int v)
{
	Node temp = Table->next;

	while ((strcmp(name, temp->name) != 0))
	{
		temp = temp->next;
		if(temp == NULL)
			return -1;
	}
	
	temp->intVal = v;
	return 0;
}

void PrintType(int _type)
{
	switch(_type)
	{
		case INT_TYPE:
			printf("int");
			break;
		case DOUBLE_TYPE:
			printf("double");
			break;
		case FLOAT_TYPE:
			printf("float");
			break;
		case CHAR_TYPE:
			printf("char");
			break;
		default:
			break;
	}
}
//get data type
int GetType(string name)
{
	Node temp = Table->next;

	while ((strcmp(name, temp->name) != 0))
	{
		temp = temp->next;
		if (temp == NULL)
			return -1;
	}

	return temp->type;
}
//set data type(t)
int SetType(string name, int t)
{
	Node temp = Table->next;

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
