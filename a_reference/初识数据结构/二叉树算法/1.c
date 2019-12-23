#include<stdio.h>
#include<malloc.h>

typedef  struct  node{
	char  data;
	struct
	node  *lchild,*rchild;
}bitree;

typedef struct{
	bitree *tree[100];
	int top;
}seqstack;

void initstack (seqstack * s)
{
	s->top=0;
}

int stackempty (seqstack * s)
{
	return s->top==0;
}

void push (seqstack * s,bitree * e)
{
	s->tree[s->top]=e;
	s->top++;
}

int stacksize(seqstack * s)
{
	return s->top;
}

bitree * pop (seqstack * s)
{
	bitree *r;
	s->top--;
	r=s->tree[s->top];
	return r;
}
bitree * creat1( )  /*����ָ�����ָ��*/
{  
	char  ch;
	int  front, rear;  /*��ͷ�Ͷ�βָ��*/
	bitree *Q[100];
	bitree  *root,*s;
	root=NULL;          /*�ÿն�����*/
	front=1;
	rear=0;     /*�ÿն���*/
	ch=getchar( );      /*�����һ���ַ�*/
	while(ch!='#')     /*���ǽ�����*/
	{ 
		s=NULL;
		if(ch!='@')        /*@��ʾ����*/
		{ 
			s=(bitree *)malloc(sizeof(bitree));
			s->data=ch;
			s->lchild=NULL; 
			s->rchild=NULL; 
     }
  /*������ָ��NULL���½���ַ���*/ 
  rear++;
  Q[rear]=s;    
    if(rear==1) 
       root=s;   /*����ĵ�һ�����Ϊ�����*/
  else
      { 
	  if(s&&Q[front])/*���Ӻ�˫�׽�����������*/ 
           if (rear%2==0)  Q[front]->lchild=s;/*��*/
           else  Q[front]->rchild=s;          /*��*/
        if (rear%2==1)  
           front++;  /*���������Ӵ�����ϣ�����*/
      } 
       ch=getchar( );  /*������һ���ַ�*/
    } /*while*/
  return  root;      /*���ظ�ָ��*/
} /*creat1*/
bitree* creat2(bitree * r)
{
	char c;
	scanf("%c",&c);
	if(c=='@')
		r=NULL;
	else
	{
		r=(bitree*)malloc(sizeof(bitree));
		r->data=c;
		r->lchild=creat2(r->lchild);
	    r->rchild=creat2(r->rchild);
	}
	return r;
}
void preorder(bitree *r)
{
	bitree * p;
	seqstack s;
	initstack(&s);
	push(&s,r);
	while(!stackempty(&s))
	{
		p=pop(&s);
		printf("%c",p->data);
		if(p->rchild!=NULL)
			push(&s,p->rchild);
		if(p->lchild!=NULL)
			push(&s,p->lchild);
	}
}
void inorder(bitree * r)
{
	seqstack s;
	bitree *p=r;
	initstack(&s);
	while(!stackempty(&s)||p)
	{
		while(p!=NULL)
		{
			push(&s,p);
			p=p->lchild;
		}
		p=pop(&s);
		printf("%c",p->data);
		p=p->rchild;
	}
}
void postorder (bitree* r)
{
	if(r)
	{
		postorder(r->lchild);
		postorder(r->rchild);
		printf("%c",r->data);
	}
}
void postorder1(bitree * r)  // ��������ķǵݹ�     ˫ջ��  
{    
    seqstack s1,s2;    
    bitree * t,* curr ;           // ָ��ǰҪ���Ľڵ�  
	t=r;
	initstack(&s1);
	initstack(&s2);
    push(&s1,t);  
    while(!stackempty(&s1))  // ջ��ʱ����    
    {  
        curr=pop(&s1);  
        push(&s2,curr);  
        if(curr->lchild)  
			push(&s1,curr->lchild);  
        if(curr->rchild)  
            push(&s1,curr->rchild);  
    }  
    while(!stackempty(&s2))  
        printf("%c",pop(&s2)->data);  
}  

int main()
{
	int i;
	bitree *BT=NULL;
	printf("����1�ǵݹ齨��������,����ݹ齨��������\n");
	scanf("%d",&i);
	fflush(stdin);//very important
	if(i==1)
	{
		printf("��ʼ�ǵݹ齨��������\n");
		BT=creat1();
	}
	else{
		printf("��ʼ�ݹ齨��������\n");
		BT=creat2(BT);
	}
	printf("ǰ�����\n");
	preorder(BT);
	printf("\n�������:\n");
	inorder(BT);
	printf("\n�������:\n");
	postorder1(BT);
	printf("\n");
	return 0;
}




