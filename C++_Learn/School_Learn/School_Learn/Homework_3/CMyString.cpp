#include "CMyString.h"

CMyString::CMyString(const CMyString& rhs) 
//	:	m_nData(rhs.m_nData)
{
	m_nLength = strlen(rhs.GetString());
	m_pszData = new char[m_nLength + 1];
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
	m_nLength = strlen(pszparm);
	if (m_nLength > 0) {
		m_pszData = new char[m_nLength + 1];
		strcpy(m_pszData, pszparm);
	}
	return 0;
}

CMyString& CMyString::operator=(const CMyString& rhs) {
	m_nLength = strlen(rhs.GetString());
	if (m_pszData != nullptr)
		delete[] m_pszData;
	m_pszData = new char[m_nLength + 1];
	strcpy(m_pszData, rhs.GetString());
	//	��ü	�ڽſ�	����	������	��ȯ�Ѵ�.
	return	*this;
}

CMyString::~CMyString() { /*cout << "�Ҹ�" << endl;*/ }

CMyString::operator char*() const{ return m_pszData; }

CMyString::CMyString(const	char* pszParam)
	:m_pszData(nullptr)
	, m_nLength(0)
{
	SetString(pszParam);
}

