#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct item{
	char name[20];    //����ͻ����� 
	char gender[20];  //����ͻ��Ա� 
	int  age;         //����ͻ����� 
	char tel[20];     //����ͻ����� 
} guest;
typedef struct node {
	guest data;         //������ 
	struct node * next; //ָ���� 
}* link;

link T;//ͷָ��
void init() {
	link p,s;
	FILE *fp;
	int i  = 0;
	s = p=(link)malloc(sizeof(struct node));
	p->next = 	NULL;

	if((fp=fopen("1.txt","r"))==NULL) {
		printf("load error!");
		exit(1);
	}
	while(!feof(fp)) {

		fscanf(fp,"%s\t%s\t%d\t%s\t\n",p->data.name,p->data.gender,&p->data.age,p->data.tel);
		i++;
		if(i!=1) {
			s->next = p;
			s=p;
		}
		else{
			T->next = p;
		}
		p=(link)malloc(sizeof(struct node));
		p->next = NULL;


	}
	printf("������i=====%d\n",i);
	if(fclose(fp)) {
		printf("Can't close the file!\n");
		exit(1);
	}
}

//����
int find() {
	link p;
	char mod[25];
	printf("������Ҫ���ҵĿͻ�����:\n");
	scanf("%s",mod);
	p = T->next;
	while(p!=NULL&&strcmp(p->data.name,mod)!=0)
		p=p->next;
	if(p==NULL) {
		printf("���޴���!\n");
		return 0;
	} else {
		printf("��ѯ��Ϣ���£�\n");
		printf("%s\t\n","�����Ա�������ϵ��ʽ");
		printf("%s\t",p->data.name);
		printf("%s\t",p->data.gender);
		printf("%d\t",p->data.age);
		printf("%s\n",p->data.tel);
		return 1;
	}
}


//���
void look() {
	link p;
	p=T->next;
	while(p!=NULL) {
		printf("%s\t%s\t%s\t%s\n","����","�Ա�","����","��ϵ��ʽ");
		printf("%s\t",p->data.name);
		printf("%s\t",p->data.gender);
		printf("%d\t",p->data.age);
		printf("%s\n",p->data.tel);
		p=p->next;
	}
}


//ɾ��
int del() {
	link p,q;
	FILE *fp;
	char mod[25];
	printf("��������Ҫɾ���Ŀͻ�����:\n");
	scanf("%s",mod);
	p=T;
	while(p->next!=NULL&&strcmp(p->next->data.name,mod)!=0)
		p=p->next;
	if(p->next==NULL) {
		printf("���޴��ˣ�\n");
		return 0;
	}
	q = p;
	p = p->next;
	q->next = p->next; 
	delete(p);
	printf("ɾ���ɹ���\n");
	if((fp=fopen("1.txt","wt"))==NULL) {
		printf("error!\n");
		exit(0);
	}
	
	p=T->next;
	while(p!=NULL) {
		printf("%s",p->data.name);
		fprintf(fp,"%s\t%s\t%d\t%s\t\n",p->data.name,p->data.gender,p->data.age,p->data.tel);
		p = p->next; 

	}
	if(fclose(fp)) {
		printf("can't close the file!\n");
		exit(1);
	}
}


//���
void create() {
	link p,s;
	FILE *fp;
	int yn;
	s=T;
	while(s->next!=NULL) {
		s=s->next;
	}
	do {
		p=(link)malloc(sizeof(struct node));
		printf("������ͻ�������\n");
		scanf("%s",p->data.name);
		printf("������ͻ��Ա�\n");
		scanf("%s",p->data.gender);
		printf("������ͻ����䣺\n");
		scanf("%d",&p->data.age);
		printf("������ͻ���ϵ��ʽ��\n");
		scanf("%s",p->data.tel);
		p->next=NULL;
		s->next=p;
		s=p;
		if((fp=fopen("1.txt","at"))==NULL) {
			printf("write error!\n");
			exit(0);
		}
		printf("д��һ��\n");
		fprintf(fp,"%s\t%s\t%d\t%s\n",p->data.name,p->data.gender,p->data.age,p->data.tel);
		if(fclose(fp)) {
			printf("can't close the file!\n");
			exit(0);
		}
		printf("��ӳɹ�!\n");
		printf("�Ƿ�������������0��1:");
		scanf("%d",&yn);
	} while(yn);
}


//�޸�
int revise() {
	link p;
	FILE *fp;
	char mod[25];
	int n;
	printf("���޸Ŀͻ�����:\n");
	scanf("%s",mod);
	p=T->next;
	while(p!=NULL&&strcmp(p->data.name,mod)!=0)
		p=p->next;
	if(p==NULL) {
		printf("���޴��ˣ�\n");
		return 0;
	}
	printf("1.���� 2.�Ա� 3.���� 4.��ϵ��ʽ\n");
	do {
		printf("�������޸���:\n");
		scanf("%d",&n);
		fflush(stdin);
		switch(n) {
			case 1:
				printf("�������޸ĺ������:\n");
				scanf("%s",p->data.name);
				break;
			case 2:
				printf("�������޸ĺ���Ա�:\n");
				scanf("%s",p->data.gender);
				break;
			case 3:
				printf("�������޸ĺ������:\n");
				scanf("%d",&p->data.age);
				break;
			case 4:
				printf("�������޸ĺ����ϵ��ʽ:\n");
				scanf("%s",p->data.tel);
				break;
		}
		printf("�Ƿ�����޸ģ�����0��1\n");
		scanf("%d",&n);
	} while(n);
	p=T->next;
	if((fp=fopen("1.txt","wt"))==NULL) {
		printf("error!\n");
		exit(0);
	}
	while(p!=NULL) {

		fprintf(fp,"%s\t%s\t%d\t%s\t\n",p->data.name,p->data.gender,p->data.age,p->data.tel);
		printf("�޸ĳɹ���\n");
		p = p->next; 

	}
	if(fclose(fp)) {
		printf("can't close the file!\n");
		exit(1);
	}
}
int main() {
	//��ʼ��ͷָ��
	T=(link)malloc(sizeof(struct node));
	T->next = NULL;
	init();
	//link1 p = T->next;
	//printf("%s",p->data.name);
	//revise1();
	look();
	del();
	look(); 
	/*init1();
	look1();
	find1();
	del1();
	look1();*/
	//create1();
	//del1(); 
	return 0;
}

