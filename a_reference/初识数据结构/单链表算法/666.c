#include<stdio.h>
#include<malloc.h>
typedef struct node{
	int data;
	struct node * next;
}linknode,*linklist;
linklist creat1 (linklist head)
{
	linklist p1,p2;
	p1=p2=(linklist)malloc(sizeof(linknode));
	while(head==NULL||(p1->data)>0)
	{
		if(head==NULL)
			head=p2;
		else 
			p2->next=p1;
		p2=p1;
		p1=(linklist)malloc(sizeof(linknode));
		if(p1!=NULL)
		{
			scanf("%d",&p1->data);
			p1->next=NULL;
		}
	}
	return head;
}
linklist creat2(linklist head)
{
	int i;
	linklist p;
	head=(linklist)malloc(sizeof(linknode));
	head->next=NULL;
	scanf("%d",&i);
	while(i>0)
	{
		p=(linklist)malloc(sizeof(linknode));
		p->data=i;
		p->next=head->next;
		head->next=p;
		scanf("%d",&i);
	}
	return head;
}
linklist delet(linklist head)
{
	int i,j=0;
	linklist p1,p2;
	printf("����Ҫɾ����һ���ڵ�?\n");
	scanf("%d",&i);
	if(i==1)
	{
		p1=head->next;
		head->next=p1->next;
		free(p1);
		return head;
	}
	while((i-j)>1&&p1)
	{
		if(j==0)
			p1=head->next;
		else
			p1=p1->next;
		j++;
	}
	if((i-j)>1){
		printf("ɾ��ʧ��...\n");
		return head;
	}
	p2=p1->next;
	p1->next=p2->next;
	free(p2);
	printf("ɾ���ɹ�!\n");
	return head;
}
linklist add(linklist head)
{
	int i,j=0;
	linklist p1,p2;
	p2=(linklist)malloc(sizeof(linknode));
	printf("\n����Ҫ����һ���ڵ�����?\n");
	scanf("%d",&i);
	printf("���������ӽڵ��������.\n");
	scanf("%d",&p2->data);
	while((i-j)>=1&&p1)
	{
		if(j==0)
			p1=head->next;
		else
			p1=p1->next;
		j++;
	}
	if((i-j)>=1)
	{
		printf("���ʧ��...\n");
		return head;
	}
	p2->next=p1->next;
	p1->next=p2;
	printf("��ӳɹ�!\n");
	return head;
}
void research1(linklist head)
{
	int i,j=1;
	linklist p=head->next;
	printf("���������һ���ڵ��������?\n");
	scanf("%d",&i);
	while(j<i&&p)
	{
		p=p->next;
		j++;
	}
	if(j==i)
		printf("\n�����ɹ�!������Ϊ%d",p->data);
	else
		printf("���޴˽ڵ�...\n");
}
void research2(linklist head)
{
	int i,count=1;
	linklist p=head->next;
	printf("������һ��ֵ��λ��?\n");
	scanf("%d",&i);
	while(p->data!=i&&p)
	{
		p=p->next;
		count++;
	}
	if(p)
		printf("�����ɹ�!��%d���ڵ�",count);
	else
		printf("���޴˽ڵ�...\n");
}
linklist deletdouble(linklist head)
{
    linklist p,q,r;
    p=head->next;
    while(p)    // p���ڱ�������
    {
         q=p;
         while(q->next) // q����p����Ľ�㣬����p��ֵ�Ƚ�
         {
             if(q->next->data==p->data)
             {
                 r=q->next; // r������Ҫɾ���Ľ��
                 q->next=r->next;   // ��Ҫɾ���Ľ���ǰ�������
                 free(r);
             }
             else
                 q=q->next;
         }
         p=p->next;
    }
	return head;
}
void print(linklist head)
{
	linklist p1=head->next;
	while(p1)
	{
		printf("%d\t",p1->data);
		p1=p1->next;
	}
}
int main()
{
	int i;
	linklist head=NULL;
	printf("����1������������(��巨),��������������(ǰ�巨)\n");
	scanf("%d",&i);
	printf("��ʼ�½��������ݷ�������\n");
	if(i==1)
	head=creat1(head);//Ϊʲôһ��Ҫ������
	else
		head=creat2(head);
	printf("�½��ĵ�����Ϊ:\n");
	print(head);
	head=add(head);
	head=delet(head);
	head=deletdouble(head);
	printf("����1����ַ����,����ֵ����\n");
	scanf("%d",&i);
	if(i==1)
	research1(head);
	else
	research2(head);
	printf("\n����(Ĭ��ȥ��)��ĵ�����Ϊ:\n");
	print(head);
	return 0;
}
	
	



