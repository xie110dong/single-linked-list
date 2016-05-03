#include<stdio.h>
#include <stdlib.h>
typedef struct student{
	int data;
	struct student *next;
}node;

node *create(){
	int num,cycle=1;
	node *p,*head,*s;
	head=(node*)malloc(sizeof(node));
	p=head;
	p->next=NULL;
	while(cycle){
		printf("请输入数字：");
		scanf("%d",&num);
		if(num!=0){
			s=(node*)malloc(sizeof(node));
			s->data=num;
			s->next=p->next;
			p->next=s;
		}
		else
			cycle=0;
	}
	head=head->next;
	return (head);
}
int length(node *head){
	node *p;
	int i=0;
	p=head;
	while(p!=NULL){
		i++;
		p=p->next;
	}
	return (i);
} 
void print(node* head){
	node *p;
	p=head;
	int len=length(head);
	printf("\n链表的长度为%d",len);
	while(p!=NULL){
		printf("\n%d\t",p->data);
		p=p->next;
	}
	if(head==NULL)
		{
			printf("\n该链表为空");
		}
}

node *reverse(node *head){
	node *p1,*p2,*p3;
	p1=head;
	p2=p1->next;
	if(head==NULL||head->next==NULL){
		return (head);
	} 
	while(p2){
		p3=p2->next;
		p2->next=p1;
		p1=p2;
		p2=p3;
	}
	head->next=NULL;
	head=p1;
	return (head);
}

int main(){
	node *xxd;
	xxd=create();
	print(xxd); 
//	xxd=reverse(xxd);//方法一 
	print(reverse(xxd));//方法二 
}
