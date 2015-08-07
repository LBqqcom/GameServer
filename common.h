#pragma once
#include "MySocket.h"
#include <cstdint>
enum //���Ͱ�
{
	kRegister = 200,
	kLogin,
	kLoginOut,
	kGetPlayerInfo,
};

enum //���հ�
{
	kRegisterResult = 600,
	kLoginResult,
	kGetPlayerInfoResult,
};

enum //������
{
	kSucess = 0,
	kError = 100,//δ֪����
	kSameNick,//��ͬNick ��Ҳ���ע��
	kUserOrPasswdError,//�û������������
	kForbidLogin,//��ֹ��½
};


struct Nickname
{
	uint32_t len;
	char name[18];
};
typedef struct Nickname Nickname;

struct Register//c2s
{
	static const uint32_t type = kRegister;
	uint32_t age;
	Nickname nick;
	//uint32_t passworldLen;

	uint32_t address1_len;
	char address1[128];

	uint32_t address2_len;
	char address2[128];

	uint32_t address3_len;
	char address3[128];

	uint32_t phone_len;
	char phone[16];//�绰����
};
typedef struct Register Register;

struct RegisterResult
{
	static const uint32_t type = kRegisterResult;
	uint32_t result;//
};
typedef struct RegisterResult RegisterResult;//s2c


struct Login//c2s
{
	static const uint32_t type = kLogin;
	uint32_t phone_len;
	char phone[12];
};
typedef struct Login Login;

struct LoginResult
{
	static const uint32_t type = kLoginResult;
	uint32_t result;//
};
typedef struct LoginResult LoginResult;//s2c


struct LoginOut{
	static const uint32_t type = kLoginOut;
};
typedef struct LoginOut LoginOut;//c2s


struct UserRecord
{
	uint32_t user_id;			//�û�id
	uint32_t login_time;		//��¼ʱ��
	int16_t  b_enable;			//�Ƿ������¼
	int16_t  age;			    //�Ա�
	uint32_t forbid_login_time; //��ֹ��½ʱ��
	Nickname nick;				//nick
	ODSocket odSocket;			//socket 
	char ip[32] ;				//ip ��ַ
	char phone[16];				//�绰����

	uint32_t address1_len;
	char address1[512];			//���û��ַ1

	uint32_t address2_len;
	char address2[512];			//���û��ַ2

	uint32_t address3_len;
	char address3[512];			//���õ�ַ3

};
typedef UserRecord UserRecord;

struct GetPlayerInfo{
	static const uint32_t type = kGetPlayerInfo;
	int phone_len;
	char phone[12];
};
typedef struct GetPlayerInfo GetPlayerInfo;//c2s

struct PlayerInfoResult//s2c
{
	static const uint32_t type = kGetPlayerInfoResult;
	uint32_t result;//
	Nickname nick;
	uint32_t address1_len;
	char address1[128];

	uint32_t address2_len;
	char address2[128];

	uint32_t address3_len;
	char address3[128];
};
typedef struct PlayerInfoResult PlayerInfoResult;