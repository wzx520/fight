
//**********************************************************
// ����༭��
//**********************************************************

// MsgTalk.h: interface for the CMsgTalk class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _MSGTALK_H
#define _MSGTALK_H

#include "NetMsg.h"
#include "NetStringPacker.h"

WORLDKERNEL_BEGIN
class CMsgTalk : public CNetMsg
{
public:
    CMsgTalk();
    virtual ~CMsgTalk();

    BOOL	Create	(char* pszSpeaker, char* pszHearer, char* pszWords,
                     char* pszEmotion = NULL, DWORD dwColor = 0xffffff,
                     USHORT unAttribute = _TXTATR_NORMAL, USHORT unStyle = _TXT_NORMAL);

public:
    BOOL			Create		(char* pbufMsg, DWORD dwMsgSize);
    void			Process		(void* pInfo);

private:
    typedef struct
    {
        MSGHEAD_DEFINE

        DWORD	dwWordsColor;
        USHORT	unTxtAttribute;
        USHORT	unTxtStyle;
        DWORD	dwTime;
        char	szBuf[1];
    } MSG_Info;

    MSG_Info*	m_pInfo;

private:
    CNetStringPacker	m_StrPacker;

};
WORLDKERNEL_END

#endif
