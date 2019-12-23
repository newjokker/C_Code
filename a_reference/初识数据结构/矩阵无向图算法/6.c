#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define  n  8
typedef  char  vextype;
typedef  int  adjtype;
typedef  struct xt
{ 
	vextype  vex[n];
    adjtype  arcs[n][n];
} graph;
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
graph *ga;
int visited[n];
void creat()
{
	int i,j,k;  
	printf("Input the vexs:\n");
	for(i=0;i<6;i++)
	{
      scanf("%c",&ga->vex[i]);
	  fflush(stdin);
	}
	printf("Input the arcs:\n");
	for ( i=0; i<n; i++ )
		for ( j=0; j<n; j++ )
          ga->arcs[i][j]=0;
		for ( k=0; k<n; k++ )
		{ 
			scanf("%d%d",&i,&j);
			i--;
			j--;
			ga->arcs[i][j]=1;  
			ga->arcs[j][i]=1; 
		}
}
DFS(int i) /*��vi+1�����������ڽӾ����ʾ��ͼ*/
{ int j;
  printf("node:%c\n",ga->vex[i]);/*���ʳ�����vi+1*/
  visited[i]=1; /*���vi+1 �ѷ��ʹ�*/
  for ( j=0; j<n; j++ ) /*��������vi+1 ���ڽӵ�*/
  if ((ga->arcs[i][j]==1)&&(!visited[j])) 
      DFS(j); 
   /*��vi+1���ڽӵ�vj+1δ�����ʹ������vj+1 ������������*/
}
BFS(int i) 
 /*��vk+1������������������ڽӾ����ʾ��ͼ*/
{ int visited[n];
  int j;
  memset(visited,0,4*n);
  InitQueue(&Q);  /*�ÿն�Q*/
  printf("node:%c\n",ga->vex[i]);  /*���ʳ�����vk+1*/
  visited[i]=1; /*����ѷ��ʹ�*/
  EnQueue(&Q,i); /*�ѷ��ʹ��Ķ��㣨��ţ����*/
  while (!QueueEmpty(&Q))   /*�ӷǿ�ʱִ��*/
  { 
	  i=DeQueue(&Q);   /*��ͷԪ����ų���*/
      for ( j=0; j<n; j++)
        if ((ga->arcs[i][j]==1)&&(!visited[j]))//DFS's visited influenced
           { /*����vi+1��δ�����ʵĵ�vj+1 */
              printf("node:%c\n",ga->vex[j]);
              visited[j]=1; 
              EnQueue(&Q,j); /*���ʹ��Ķ������*/
            } 
     } /*while*/
 } /*DFS*/
int main()
{ 
	ga=(graph *)malloc(sizeof(struct xt));
	creat();
	printf("���������������:\n");
	DFS(0);
	printf("���������������:\n");
	BFS(0);
	return 0;
}
  

