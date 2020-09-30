#pragma once
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct _node {
	char N;
	int K, E, M, C, S, R;
	struct _node* Next;
} Node;

typedef Node* Ldata;

typedef struct _list {
	Ldata Head;
	Ldata Cur;
	Ldata Before;
	int NumOfData;
	int (*comp)(Ldata, Ldata);
} LinkedList;

typedef LinkedList List;

//����Ʈ�� �ʱ�ȭ
void InitList(List*);

//�ڷ� ����
void LInsert(List*, Ldata);

//ù �ڷᰡ �ִ°�?
int LFirst(List*, Ldata);

//���� �ڷᰡ �ִ°�?
int LNext(List*, Ldata);

//�ڷ� ����
Ldata LRemove(List*);

//����Ʈ �ڷ��� ���
void LPrint(List*);

//����Ʈ �ڷ��� ���� ��ȯ
int LCount(List*);

//���� ��Ģ ����
void SetSortRule(List*, int (*comp)(Ldata, Ldata));

//��ŷ �ޱ��
void Rank(List* list);

//������ ����
void Tie_delete(List* list);