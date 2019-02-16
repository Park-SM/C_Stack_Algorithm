#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXBUF 1024

typedef struct tagNode {
	char *Data;
	struct tagNode *NextNode;
}Node;

typedef struct tagStack {
	Node *HeadNode;
	Node *TailNode;
	int Capacity;
}Stack;

Stack *CreateStack();
Node *CreateNode(char *nData);
void AppendNode(Stack *stack, Node *NewNode);
void PrintStack(Stack *stack);
void DestroyNode(Node *dNode);
int Pop(Stack *stack);
void RANIS_inner(Node *rNode);
void RemoveAllNodeInStack(Stack *stack);

#endif