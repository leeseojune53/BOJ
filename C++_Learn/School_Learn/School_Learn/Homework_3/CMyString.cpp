#include "CMyString.h"

CMyString::CMyString(const CMyString& rhs)
//	:	m_nData(rhs.m_nData)
{
	m_nLenth = strlen(rhs.GetString());
	m_pszData = new char[m_nLenth + 1];
	strcpy(m_pszData, rhs.GetString());
	cout << "CMyData(const	CMyData	&)" << endl;
}

CMyString::CMyString()
{
	//cout << "default constructor" << endl;
}

const char* CMyString::GetString() const {
	if (m_pszData != nullptr)
		return m_pszData;
	return "";
}


int CMyString::SetString(const char* pszparm) {
	m_nLenth = strlen(pszparm);
	if (m_nLenth > 0) {
		m_pszData = new char[m_nLenth + 1];
		strcpy(m_pszData, pszparm);
	}
	return 0;
}

CMyString& CMyString::operator=(const CMyString& rhs) {
	m_nLenth = strlen(rhs.GetString());
	if (m_pszData != nullptr)
		delete[] m_pszData;
	m_pszData = new char[m_nLenth + 1];
	strcpy(m_pszData, rhs.GetString());
	//	��ü	�ڽſ�	����	������	��ȯ�Ѵ�.
	return	*this;
}

CMyString::~CMyString() { /*cout << "�Ҹ�" << endl;*/ }

CMyString::operator char*() { return m_pszData; }

CMyString::CMyString(const char* ) {

}