/***********************************************************************
 *     
 *  Filename    :  uuptDecrypt.h
 *
 *  Author       :  gpengyuan
 *  Create       :  2016-11-30
 *
 *  Description :
 *                            
 *  Copyright (C), 2016, Beijing Run.Co., Ltd.
 *
 *  ChangeLog   :      1111       
 *
 ***********************************************************************/

#ifndef __UUPTDECRYPT_H__
#define __UUPTDECRYPT_H__
#include <iostream>
#include <netinet/in.h>

using namespace std;

#define KEY_LENTH	16
#define UUPT_IN_HEX	0
#define UUPT_IN_ORI	1

//�������ݽṹ
struct UUPT_DECRYPT_ARG_S
{
	unsigned char *pSrc;	//��������buffer
	int nSrcLen;		//�������ݳ���
	unsigned char *pKey;	//��Կ�ַ���
	int nKeyLen;		//��Կ�ַ�������
	unsigned char *pDst;	//��������buffer
	int nDstLen;		//�������ݳ���
	int nOffSet;		//��Ч��Ϣƫ����
	short nInType;		//ԭʼ��������

	UUPT_DECRYPT_ARG_S()		
	{
		pSrc = NULL;
		nSrcLen = 0;
		pKey = NULL;
		nKeyLen = 0;
		pDst = NULL;
		nDstLen = 0;
		nOffSet = 0;
		nInType = 0;
	}
};


//��Կת�����ݽṹ
struct UUPT_FORMAT_KEY
{
	int Key1;
	int Key2;
	int Key3;
	int Key4;

	UUPT_FORMAT_KEY()
	{
		Key1 = 0;
		Key2 = 0;
		Key3 = 0;
		Key4 = 0;
	}	
};


bool UUPT_Decrypt(UUPT_DECRYPT_ARG_S *arg);

bool UUPT_Decode( unsigned char *pIn,   int nInLen,  int nInPos, unsigned char *pKey, int nKeylen, unsigned char *pOut,  int nOutPos);

bool UUPT_FormatKey(unsigned char *pKey, int nKeylen, UUPT_FORMAT_KEY &DstFormatKey);

int ConvertIntToByteArray(int nInt);

int ConvertByteArrayToInt(unsigned char *pByteArray, int nByteArrayLen,  int nOffset);

int hex2int(char ch);

bool is_hex(char ch);

bool hex2byte(unsigned char *pHex, int nHexLen, unsigned char *pByte, int &nByteLen);

#endif


