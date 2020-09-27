#ifndef _PPOOL_ERRNO_H
#define _PPOOL_ERRNO_H

#include <stdio.h>
#include <string.h>

extern int ppool_errno; //����������

#define PE_OK 0
#define PE_POOL_NO_MEM -1
#define PE_THREAD_NO_MEM -2
#define PE_THREAD_MUTEX_ERROR -3
#define PE_THREAD_COND_ERROR -4
#define PE_QUEUE_NO_MEM -5
#define PE_PRIORITY_ERROR -6
#define PE_QUEUE_NODE_NO_MEM -7

//��ӡ������Ϣ
void ppool_error(const char *msg);

//���ݴ����������ӡ������Ϣ
char *ppool_strerr(int errno);

#endif
