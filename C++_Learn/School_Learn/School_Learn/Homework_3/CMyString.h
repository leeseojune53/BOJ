#pragma once

class CMyString {
private:
	string str;
public:
	void SetString(string s_parm) {
		str = s_parm;
	}

	string GetString() { return str; }

	CMyString(const CMyString& rhs)
		//	:	m_nData(rhs.m_nData)
	{
		this->str = rhs.str;
		cout << "CMyData(const	CMyData	&)" << endl;
	}

	CMyString& operator=(const CMyString& rhs) {
		*str = *rhs.str;
		//	��ü	�ڽſ�	����	������	��ȯ�Ѵ�.
		return	*this;
	}
};