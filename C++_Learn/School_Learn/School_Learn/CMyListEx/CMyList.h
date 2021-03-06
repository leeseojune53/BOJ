#pragma once
struct DNode
{
	int data;
	DNode* front;
	DNode* back;
};

class CMyList {
public:
	CMyList() { m_nLength = 0; };
	CMyList(int m_nLength);
	virtual ~CMyList();
	void Insert(int num);
	virtual void PrintData() const;
	virtual int isOverlap(int num);
	DNode* gethead() const;
	void sethead(DNode* head);
	DNode* gettail() const;
	void settail(DNode* tail);
	int getLength() const;
	void setLength(int Length);
	CMyList& operator+=(const CMyList&);
	int Append(const CMyList);
	virtual void showmenu();
private:
	DNode* headNode = nullptr;
	DNode* tailNode = nullptr;
	static int m_nLength;
};