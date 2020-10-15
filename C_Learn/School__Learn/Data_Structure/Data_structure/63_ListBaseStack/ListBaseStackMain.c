#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "ListBaseStack.h"

printMenu()
{
	printf("\n\n+++++++++++++++++++++++++++++\n");
	printf("\t1 - ���� \n");
	printf("\t2 - ���� \n");
	printf("\t3 - ��� \n");
	printf("\tq - ���α׷� ���� \n");
	printf("+++++++++++++++++++++++++++++\n");
	printf("�޴��� �����ϼ���. >> \n");
}

void printStack(Stack* s)
{
	if (SIsEmpty(s)) {
		printf("---> Stack is Empty!!");
	}
	else {
		Node* pStack = s->head; 
		while (pStack != NULL) {
			printf("%d -> ", pStack->data);
			pStack = pStack->next; 
		}
	}
}
void freeStack(Stack* s)
{
	Data data;
	Node* freeNode = s->head;
	Node* freeNodeNext = freeNode;

	while (freeNodeNext != NULL) {
		freeNodeNext = freeNode->next;
		data = freeNode->data;
		free(freeNode);
		freeNode = freeNodeNext;

		printf("[%d]free-", data);
	}
}
int main(void)
{
	// Stack�� ���� �� �ʱ�ȭ ///////
	Stack stack;
	StackInit(&stack);
	Data value;
	char menu = '1';	// Default 

	while (1) {
		printMenu();
		scanf(" %c", &menu);

		switch (menu)
		{
		case '1':		// Push 
			printf("���ÿ� ������ ����Ÿ�� �Է��Ͻÿ�. \n");
			scanf("%d", &value);
			SPush(&stack, value);
			break;

		case '2':		// Pop
			value = SPop(&stack);
			printStack(&stack);
			break;

		case '3':		//Print
			printStack(&stack);
			break;

		case 'q':		// ����
			freeStack(&stack);
			return -1;

		default:		// ����ó��
			printf("���� �޴��Դϴ�. �޴��� �ٽ� �����ϼ���! \n");
			break;
		}
	}

	return 0;
}