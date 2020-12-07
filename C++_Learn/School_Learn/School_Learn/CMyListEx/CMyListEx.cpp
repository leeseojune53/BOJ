#include "CMyListEx.h"
#include <iostream>
using namespace std;

CMyListEx::CMyListEx(const CMyListEx& list) {
	Append(list);
}

void CMyListEx::Insert(int num) { // tail���� �Է�
	CMyList::Insert(num);
	//if (!isOverlap(num)) {
	//	return;
	//}
	//setLength(getLength() + 1);
	////pHead�� NULL�ϋ�
	//DNode* newnode = new DNode;
	//newnode->data = num;
	//newnode->front = gettail();
	//newnode->back = nullptr;
	//if (gethead() == NULL) {
	//	sethead(newnode);
	//	settail(newnode);
	//	PrintData();
	//	return;
	//}
	//gettail()->back = newnode;
	//settail(gettail()->back);
	//
	//PrintData();

}




void CMyListEx::PrintDataTail() const{
	DNode* buf = gettail();
	int count = 0;
	if (getLength() == 0) {
		cout << "����� �����Ͱ� �����ϴ�.";
		return;
	}
	if (buf != NULL) {
		cout << "CMyList ������ : [Tail] ";
		cout << buf->data;
		buf = buf->front;
		count = 1;
	}
	while (buf != NULL) {
		cout << " - " << buf->data;
		buf = buf->front;
		count++;
	}
	cout << " [Head]\n";
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