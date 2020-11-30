#include <iostream>
#include "CMyListEx.h"
using namespace std;

CMyList::~CMyList() {

	DNode* deleteNode;
	while (headNode != NULL) {
		deleteNode = headNode;
		headNode = headNode->back;
		delete deleteNode;

	}
}

DNode* CMyList::gethead() {
	return headNode;
}

void CMyList::sethead(DNode* head) {
	this->headNode = head;
}

DNode* CMyList::gettail() {
	return tailNode;
}

void CMyList::settail(DNode* tail) {
	this->tailNode = tail;
}

int CMyList::getLength() {
	return m_nLength;
}

void CMyList::setLength(int Length) {
	this->m_nLength = Length;
}

void CMyListEx::Insert(int num) { // tail���� �Է�
	if (!isOverlap(num)) {
		return;
	}
	setLength(getLength() + 1);
	//pHead�� NULL�ϋ�
	DNode* newnode = new DNode;
	newnode->data = num;
	newnode->front = gettail();
	newnode->back = nullptr;
	if (gethead() == NULL) {
		sethead(newnode);
		settail(newnode);
		PrintData();
		return;
	}
	gettail()->back = newnode;
	settail(gettail()->back);
	
	PrintData();

}

int CMyListEx::isOverlap(int num) {
	DNode* buf = gethead();
	if (buf == NULL)
		return 1;

	do {
		if (buf->data == num) {

			cout << "�ߺ���.\n";
			return 0;
		}
		buf = buf->back;
	} while (buf != NULL);
	return 1;
}

void CMyListEx::PrintData() { // head���� ���
	DNode* buf = gethead();
	int count = 0;
	if (getLength() == 0) {
		cout << "����� �����Ͱ� �����ϴ�.";
		return;
	}
	if (buf != NULL) {
		cout << "CMyList ������ : [Head] ";
		cout << buf->data;
		buf = buf->back;
		count = 1;
	}
	while (buf != NULL) {
		cout << " - " << buf->data;
		buf = buf->back;
		count++;
	}
	cout << " [Tail]\n";
	cout << "������ ���� : " << getLength << "��";

}

void CMyListEx::PrintDataTail() {
	DNode* buf = gettail();
	int count = 0;
	if (getLength() == 0) {
		cout << "����� �����Ͱ� �����ϴ�.";
		return;
	}
	if (buf != NULL) {
		cout << "CMyList ������ : [Head] ";
		cout << buf->data;
		buf = buf->front;
		count = 1;
	}
	while (buf != NULL) {
		cout << " - " << buf->data;
		buf = buf->front;
		count++;
	}
	cout << " [Tail]\n";
	cout << "������ ���� : " << getLength() << "��";
}

void CMyListEx::InsertHead(int num) {
	if (!isOverlap(num)) {
		return;
	}
	setLength(getLength() + 1);
	//pHead�� NULL�ϋ�
	DNode* newnode = new DNode;
	newnode->data = num;
	newnode->front = nullptr;
	newnode->back = gethead();
	if (gethead() == NULL) {
		sethead(newnode);
		settail(newnode);
		PrintData();
		return;
	}
	gethead()->front = newnode;
	sethead(newnode);

	PrintData();
}

void CMyListEx::DeleteTail() {
	if (getLength() == 0) {
		cout << "������ ������ ����";
		return;
	}
	DNode* deletedata = gettail();
	if (deletedata->front != NULL) {
		settail(deletedata->front);
		deletedata->front->back = nullptr;
	}
	setLength(getLength() - 1);
	delete deletedata;
	PrintData();
}

void CMyListEx::DeleteHead() {
	if (getLength() == 0) {
		cout << "������ ������ ����";
		return;
	}
	DNode* deletedata = gethead();
	if (deletedata->back != NULL) {
		sethead(deletedata->back);
		deletedata->back->front = nullptr;
	}
	if (deletedata->back == NULL) {
		sethead(nullptr);
	}
	setLength(getLength() - 1);
	delete deletedata;
	PrintData();
}