#include "CMyList.h"
#include <cstdio>
#include <ioStream>

using	namespace	std;
int	main()
{
	CMyList	list;

	char n;
	int insert;
	while (1) {
		cout << "\n------------------------------------\n";
		cout << "CMyList �޴�\n1 : ����\n2 : ���\n0 : ����\n";
		cout << "------------------------------------\n";
		cout << "�޴��� ������(���� �Է�) : ";
		cin >> n;
		switch (n)
		{
		case '1':
			cout << "������ �����͸� �Է����ּ��� : ";
			cin >> insert;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "	0,	1,	2	��	���ڸ�	�Է��ϼ���~!\n";
				continue;
			}
			list.Insert(insert);
			getchar();
			break;
		case '2':
			list.PrintData();
			break;
		case '0':
			return 0;
		default:
			cout << "0 ~ 2�� ���� �Է��ϼ���!!";
			break;
		}
	}
	return	0;
}