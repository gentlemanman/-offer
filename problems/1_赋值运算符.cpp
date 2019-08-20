//
// Created by zhaohan on 2019/8/1.
//

#include <iostream>
#include <cstring>

using namespace std;
class CMyString
{
public:
    CMyString(char* pData = nullptr);
    CMyString(const CMyString& str);
    ~CMyString(void);

    CMyString& operator = (const CMyString& str);

private:
    char* m_pData;
};

CMyString::CMyString(char *pData) {
    if(pData == nullptr){
        m_pData = new char[1];
        m_pData[0] = '\0';
    }
    else{
        m_pData = new char[strlen(pData) + 1];
        strcpy(m_pData, pData);
    }
}

CMyString::CMyString(const CMyString &str) {
    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString() {
    delete[] m_pData;
}

CMyString& CMyString::operator=(const CMyString &str) {
    if(this != &str){
        CMyString strTemp(str);
        char* pTemp = strTemp.m_pData;
        strTemp.m_pData = m_pData;
        m_pData = pTemp;
    }
}
