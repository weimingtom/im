// ----------------------------------------------------------------
// �ļ�:MsgObj.h
// �汾: 
// ����: xy
// ����: 2006-7-6
// ----------------------------------------------------------------
// �汾��ʷ			ע��
// ----------------------------------------------------------------
// v0.1				��ʼ�汾
// 
// ----------------------------------------------------------------


#pragma once


#include <vector>
#include <string>
using namespace std;


enum MSGOBJ_TYPE
{
	MOT_COMMON_MSG,	// ��ͨ��Ϣ
	MOT_WEB_PIC,	// ָ��url���ӵ�webͼƬ
	MOT_FLASH,		// flash�ļ�
	MOT_MOVIE,		// Ӱ���ļ���Ϣ
};

struct MSGOBJ_SEG
{
	int		nType;	// ��Ϣ����:
	string	sData;	// ��Ϣ����
};

typedef vector<MSGOBJ_SEG> MSGOBJARR;


//------------------------------------------------------
// ������Ϣ��
//------------------------------------------------------

class CMsgObj
{
public:

	CMsgObj(void);

	~CMsgObj(void);

public:
	//------------------------------------------------------
	// ������Ϣ������Ϣ���Ϊ��Ϣ�Σ���Ϣ���м������ͣ��ο�MSGOBJ_TYPE��
	//------------------------------------------------------
	void				Load(const char* szMsg);
	//------------------------------------------------------
	// ��ȡ��Ϣ�а�����ͼƬurl���Ӷ���
	//------------------------------------------------------
	void				GetWebImage(vector<string>& arrImg) const;
	//------------------------------------------------------
	// ����Ϣ�е�ͼƬ�����滻Ϊָ����ͼƬ��
	//------------------------------------------------------
	bool				ReplaceWebImage(const vector<string> arrName);
	//------------------------------------------------------
	// ��ȡ��Ϣ���ַ���
	//------------------------------------------------------
	string				ToMsg() const;
	//------------------------------------------------------
	// ��ȡ��Ϣ��
	//------------------------------------------------------
	const MSGOBJARR&	GetMsgSegs() const
	{ return m_arrMsgSeg; };

protected:
	//------------------------------------------------------
	// ����Ϣ�е�ת��հ��ַ���%20���滻Ϊ�հ��ַ�' '
	//------------------------------------------------------
	void				ProcBlank(string& sUrl);

private:
	
	MSGOBJARR		m_arrMsgSeg;

};