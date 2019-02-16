#include "Stack.h"

Stack *CreateStack() {
	Stack *NewStack = (Stack*)malloc(sizeof(Stack));

	NewStack->HeadNode = NULL;
	NewStack->TailNode = NULL;
	NewStack->Capacity = 0;

	return NewStack;
}

Node *CreateNode(char *nData) {
	Node *NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = (char*)malloc(strlen(nData) + 1);	// + 1 is the position of NULL.

	strncpy(NewNode->Data, nData, strlen(nData) + 1);
	NewNode->NextNode = NULL;

	return NewNode;
}

void AppendNode(Stack *stack, Node *NewNode) {
	if (stack->HeadNode == NULL) {
		stack->HeadNode = NewNode;
		stack->TailNode = NewNode;
	}
	else {
		stack->TailNode->NextNode = NewNode;
		stack->TailNode = NewNode;
	}
	stack->Capacity++;
}

void PrintStack(Stack *stack) {
	if (stack->HeadNode != NULL) {
		Node *Current = stack->HeadNode;
		while (Current != NULL) {
			printf("> %s", Current->Data);
			Current = Current->NextNode;
		}
	}
	else puts("> ::: No Data.. :::");

	printf("\n\n Stack Capacity : %d\n", stack->Capacity);
}

void DestroyNode(Node *dNode) {
	free(dNode->Data);
	free(dNode);
}

int Pop(Stack *stack) {		// If successful, the return value is 1.
	if (stack->HeadNode != NULL) {
		if (stack->HeadNode == stack->TailNode) {
			DestroyNode(stack->TailNode);
			stack->HeadNode = NULL;
			stack->TailNode = NULL;
		}
		else {
			Node *Temp = stack->HeadNode;
			while (Temp->NextNode != stack->TailNode) Temp = Temp->NextNode;
			DestroyNode(stack->TailNode);
			Temp->NextNode = NULL;
			stack->TailNode = Temp;
		}
		stack->Capacity--;
		return 1;
	}
	return 0;
}

void RANIS_inner(Node *rNode) {		// Recursive function of RemoveAllNodeInList.
	if (rNode->NextNode != NULL) RANIS_inner(rNode->NextNode);
	DestroyNode(rNode);
}

void RemoveAllNodeInStack(Stack *stack) {
	if (stack->HeadNode != NULL) {
		RANIS_inner(stack->HeadNode);
		stack->HeadNode = NULL;
		stack->TailNode = NULL;
		stack->Capacity = 0;
	}
}