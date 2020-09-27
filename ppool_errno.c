#include "ppool_errno.h"

int ppool_errno=0;

void ppool_error(const char *msg)
{
	if(!msg)
		printf("%s\n",ppool_strerr(ppool_errno));
	else
		printf("%s : %s\n",ppool_strerr(ppool_errno));
}

char *ppool_strerr(int errno)
{
	switch(errno)
	{
		case 0:
			return "�ɹ�!";
		case -1:
			return "�޷�Ϊ�̳߳ؿ��ٿռ䣬�����̳߳�ʧ��!";
		case -2:
			return "�޷�Ϊ���������̷߳����㹻���ڴ�!";
		case -3:
			return "pthread��ʼ��������ʧ�ܣ���ʹ��ppool_error�鿴������Ϣ!";
		case -4:
			return "pthread��ʼ����������ʧ�ܣ���ʹ��ppool_error�鿴������Ϣ!";
		case -5:
			return "�޷�Ϊ������п��ٿռ�!";
		case -6:
			return "��������ȼ�!";
		case -7:
			return "�޷�Ϊ���б�����һ����㣬�����ڴ����!";
		default:
			return "δ֪����!";
	}
}
