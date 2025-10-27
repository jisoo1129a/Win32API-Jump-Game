#include "CPathMgr.h"

CPathMgr::CPathMgr()
    : m_szContentPath()
    , m_szRelativePath()
{

}
CPathMgr::~CPathMgr()
{

}

void CPathMgr::init()
{
    GetCurrentDirectory(255, m_szContentPath);
    int iLen = (int)wcslen(m_szContentPath);

    for (int i = iLen; i >= 0; i--)
    { 
        if (m_szContentPath[i] == '\\')
        {
            m_szContentPath[i] = '\0';
            break;
        }
    }

    wcscat_s(m_szContentPath, 255, L"\\Output\\bin\\content\\");
}

wstring CPathMgr::GetRelativePath(const wchar_t* _filePath)
{
    wstring strFilePath = _filePath;
    size_t iAbslen = wcslen(m_szContentPath);
    size_t iFullLen = strFilePath.length();
    wstring strRelativePath = strFilePath.substr(iAbslen, iFullLen - iAbslen);

    return strRelativePath;
}
