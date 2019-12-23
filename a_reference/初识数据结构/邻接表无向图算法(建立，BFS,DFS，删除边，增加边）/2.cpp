#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef struct node1
{
	int adjvex;        
	struct node1 *next;
}edgenode;
typedef struct
{
	int vertex;
	edgenode *link;
}vexnode;
typedef struct node {	
    int data;	         //���н������
    struct node *link;            //�����ָ��
}QueueNode;
typedef struct {
    QueueNode *rear,*front;
}LinkQueue;
LinkQueue Q;
void InitQueue(LinkQueue *Q){//void InitQueue(LinkQueue Q){
    Q->rear=Q->front=NULL;  // Q.rear=Q.front=NULL;
}                           //
int QueueEmpty(LinkQueue *Q ) {
    return Q->front==NULL;
}
int EnQueue (LinkQueue *Q,int x ) {//���
    QueueNode *p=(QueueNode *)malloc(sizeof(QueueNode));
    p->data=x;  
	p->link=NULL;
    if(Q->front==NULL )  
        //��,������һ�����
       Q->front=Q->rear=p;
    else Q->rear->link=p; //���
		 Q->rear=p;
    return 1;
}
int DeQueue(LinkQueue *Q) {//����
//ɾȥ��ͷ��㣬�����ض�ͷԪ�ص�ֵ
	int x;
	QueueNode * p;
    if(QueueEmpty(Q)) 
		return 0;	//�жӿ�
    p=Q->front;		
    x=p->data;	//�����ͷ��ֵ
 	Q->front= Q->front->link; 	//�¶�ͷ
	free(p);
    return x;				
}
vexnode ga[20];
int dnum,bnum;
void creat ()
{
	int i,j,k;
	int num[10];
	edgenode *s;
	printf("���붥�����:\n");
	scanf("%d",&dnum);
	printf("����߸���:\n");
	scanf("%d",&bnum);
	printf("���붥��ID:\n");
	for(i=1;i<=dnum;i++)
		scanf("%d",&num[i]);
	for(i=1;i<=dnum;i++)
	{
		ga[i].vertex=num[i];
		ga[i].link=NULL;
	}
	printf("�������������ԣ�\n");
	for(k=0;k<bnum;k++)
	{
		scanf("%d%d",&i,&j);
		s=(edgenode*)malloc(sizeof(edgenode));
		s->adjvex=j;
		s->next=ga[i].link;
		ga[i].link=s;
		s=(edgenode*)malloc(sizeof(edgenode));
		s->adjvex=i;
		s->next=ga[j].link;
		ga[j].link=s;
	}
}
int visited[20];
void DFSL(int i)
{
	edgenode *p;
	printf("node:%d\n",ga[i].vertex);
	visited[i]=1;
	p=ga[i].link;
    while(p!=NULL)
	{
		if(!visited[p->adjvex])
			DFSL(p->adjvex);
		p=p->next;
	}
}
void BFSL(int k)
{
	edgenode *p;
    InitQueue(&Q);
	printf("node:%d\n",ga[k].vertex);
	visited[k]=1;
	EnQueue(&Q,k);
	while(!QueueEmpty(&Q))
	{
		k=DeQueue(&Q);
		p=ga[k].link;
		while(p!=NULL)
		{
			if(!visited[p->adjvex])
			{
				
				printf("node:%d\n",ga[p->adjvex].vertex);
				visited[p->adjvex]=1;
				EnQueue(&Q,p->adjvex);
			}
			p=p->next;
		}
	}
}
void count()
{
	int count1=0,count2=0,i,j;
	edgenode *p;
	printf("����һ������ĳ��Ⱥ����\n");
	scanf("%d",&i);
	p=ga[i].link;
	while(p)
	{
		count1++;
		p=p->next;
	}
	for(j=1;j<=dnum;j++)
	{
		p=ga[j].link;
		while(p)
		{
			if(p->adjvex==i)
				count2++;
			p=p->next;
		}
	}
	printf("����%d�ĳ���:%d  ���:%d\n",i,count1,count2);
}
void add()
{
	int i,j;
	edgenode *p,*q;
	q=(edgenode *)malloc(sizeof(edgenode));
	q->next=NULL;
	printf("������һ����:\n");
	scanf("%d %d",&i,&j);
	q->adjvex=j;
	p=ga[i].link;
	while(p->next)
		p=p->next;
	p->next=q;
	q->adjvex=i;
	p=ga[j].link;
	while(p->next)
		p=p->next;
	p->next=q;
}
void delet()
{
	int i,j;
	edgenode *p,*q;
	printf("����ɾ����һ��\n");
	scanf("%d %d",&i,&j);
	p=ga[i].link;
	if(p->adjvex==j)
		ga[i].link=p->next;
	else
		while(p)
		{
			q=p;
			p=p->next;
			if(p->adjvex==j)
			{
				q->next=p->next;
				free(p);
				break;
			}
		}
	p=ga[j].link;
	if(p->adjvex==i)
		ga[j].link=p->next;
	else
		while(p)
		{
			q=p;
			p=p->next;
			if(p->adjvex==i)
			{
				q->next=p->next;
				free(p);
				break;
			}
		}
}
void main()
{
	memset(visited,0,80);
	creat();
	printf("������ȱ�������:\n");
	DFSL(1);
	printf("������ȱ�������:\n");
	memset(visited,0,80);
	BFSL(1);
	count();
	add();
	printf("������ȱ�������:\n");
	memset(visited,0,80);
    BFSL(1);
	delet();
	printf("������ȱ�������:\n");
	memset(visited,0,80);
	BFSL(1);
}

