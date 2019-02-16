#include "Stack.h"

int main() {

	Stack *stack = CreateStack();
	char buf[MAXBUF];

	while (1) {
		PrintStack(stack);
		memset(buf, 0x00, MAXBUF);
		printf("\n>>>>> Input your data : ");
		fgets(buf, MAXBUF, stdin);

		if (strncmp(buf, "#exit", strlen("#exit")) == 0) break;			// escape.
		else if (strncmp(buf, "#pop", strlen("#pop")) == 0) Pop(stack);		// #pop
		else if (strncmp(buf, "#pad", strlen("#pad")) == 0) RemoveAllNodeInStack(stack);	// delete data.
		else AppendNode(stack, CreateNode(buf));

		system("cls");
	}

	system("pause");
	return 0;
}