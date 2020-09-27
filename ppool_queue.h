#ifndef _PPOOL_QUEUE_H
#define _PPOOL_QUEUE_H

#include "ppool_errno.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef void (*ppool_work)(void *);

typedef struct ppool_node
{
	int priority; //���ȼ�
	ppool_work task; //����
	void *arg; //����

	struct ppool_node *next;
}pool_node;

//�����б�ͷָ��
typedef struct
{
	int len; //��������
	pool_node *head; //�б�ͷָ��
}pool_w;

pool_w *ppool_queue_init(void);
//��ʼ��һ�������б�

pool_node *ppool_queue_new(ppool_work task,void *arg,int priority);
/* ����һ���ڵ�
 * taskΪ������
 * argΪ�������
 * priorityΪ���������ȼ�
 */

void ppool_queue_add(pool_w *head,pool_node *node);
// ���һ������

pool_node *ppool_queue_get_task(pool_w *head);
//��ȡһ������

void ppool_queue_cleanup(pool_w *head);
//���������б�

void ppool_queue_destroy(pool_w *head);
//���������б�

#endif
