#ifndef _PPOOL_H
#define _PPOOL_H

#include <pthread.h>
#include "ppool_queue.h"

typedef char pbool;

#define PTRUE 1
#define PFALSE 0

pthread_mutex_t PPOOL_LOCK;

#define ppool_entry() pthread_mutex_lock(&PPOOL_LOCK)
#define ppool_leave() pthread_mutex_unlock(&PPOOL_LOCK)

typedef struct
{
	int pool_max_num; //�̳߳�����߳�����
	int rel_num; //�̳߳���ʵ���߳���
	pool_w *head; //�߳�ͷ
	pthread_t *id; //�߳�id

	pthread_mutex_t ppool_lock;
	pthread_cond_t ppool_cond;
}pool_t;

//�������ݽṹ
typedef struct
{
	int priority; //���ȼ�
	ppool_work task; //����
	void *arg; //����
}pool_task;

//��ʼ��һ���̳߳�
pool_t *ppool_init(int pool_max_num);

//���̳߳������һ������
pbool ppool_add(pool_t *pool,pool_task *task);

//����һ���̳߳�
void ppool_destroy(pool_t *pool);

#endif
