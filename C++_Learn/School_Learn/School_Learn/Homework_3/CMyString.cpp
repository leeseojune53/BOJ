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
	:m_pszData(nullptr)
	, m_nLength(0)
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
	if (m_pszData != NULL) {
		delete[] m_pszData;
	}
		
	m_pszData = new char[m_nLength + 1];
	strcpy(m_pszData, rhs.GetString());
	//	��ü	�ڽſ�	����	������	��ȯ�Ѵ�.
	return	*this;
}

CMyString::CMyString(CMyString&& rhs) 
	:m_pszData(nullptr)
	, m_nLength(0) 
{
	cout << "CMyString �̵������� ȣ��" << endl;

	m_pszData = rhs.m_pszData;
	m_nLength = rhs.m_nLength;

	rhs.m_pszData = nullptr;
	rhs.m_nLength = 0;
}

CMyString::~CMyString() { /*cout << "�Ҹ�" << endl;*/ }

CMyString::operator char*() const{ return m_pszData; }

int CMyString::GetLength() const { return m_nLength; }

int CMyString::Append(const char* pszParam) {
	if (pszParam == NULL)
		return 0;

	int nLenParam = strlen(pszParam);
	if (nLenParam == 0)
		return 0;

	if (m_pszData == NULL) {
		SetString(m_pszData);
		return m_nLength;
	}

	int nLenCur = m_nLength;

	char* result = new char[m_nLength + nLenParam + 1];

	strcpy(result, m_pszData);
	strcpy(result + nLenCur, pszParam);

	Release();

	m_pszData = result;
	m_nLength = nLenCur + nLenParam;

	return m_nLength;
}

void CMyString::Release() {
	if (m_pszData != nullptr) {
		delete[] m_pszData;
		m_pszData = nullptr;
	}
}

CMyString::CMyString(const	char* pszParam)
	:m_pszData(nullptr)
	, m_nLength(0)
{
	SetString(pszParam);
}

CMyString CMyString::operator+(const CMyString& rhs) {
	int len1 = m_nLength;
	int len2 = rhs.m_nLength;
	char* buf = new char[len1 + len2 + 1];
	strcpy(buf, m_pszData);
	strcpy(buf + len1, rhs.m_pszData);
	CMyString result(buf);

	delete[] buf;

	return result;
}

CMyString& CMyString::operator+=(const CMyString& rhs) {
	Append(rhs.m_pszData);
	return *this;
}

