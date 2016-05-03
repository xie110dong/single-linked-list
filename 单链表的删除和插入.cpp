#include <iostream> 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
using namespace std; 
typedef struct student{
	int data;
	struct student *next;
}node;

node *create(){
	node *head ,*p ,*s;
	int x, cycle=1;
	head=(node*)malloc(sizeof(node));
	p=head;
	p->next=NULL;
	while(cycle){
		printf("\n请输入数据:");
		scanf("%d",&x);
		if(x!=0){
			s=(node*)malloc(sizeof(node));
			s->data=x;
			s->next=p->next;
			p->next=s;
//			p->next=s;
//			p=s;
		}
		else cycle=0;
	}
	head=head->next;
	return (head);
 }
int length(node *head){
	int n=0;
	node *p;
	p=head;
	while(p!=NULL){
		p=p->next;
		n++;
	}
	printf("\n链表长度为：%d",n);
	return (n);
}
void print(node *head){
	node *p;
	p=head;
	while(p!=NULL){
		printf("\n\t%d",p->data);
		p=p->next;
	}
	if(head==NULL){
		printf("\n该链表为空");
	}
}

node *del(node *head , int num){
	node *p1,*p2;
	p1=head;
	while(p1->next!=NULL&&p1->data!=num){
		p2=p1;
		p1=p1->next;
	}
	if(p1->data=num){
		if(p1==head){
			head=head->next;
			free(p1);
		}
		else{
			p2->next=p1->next;
		}
	}
	else
		printf("该链表无此元素！");
	return head;
}
node *insert(node *head , int num){
	node *p0,*p2,*p1;
	p1=head;
	p0=(node *)malloc(sizeof(node));
	p0->data=num;
	while(p1->next!=NULL&&p1->data<num){
		p2=p1;
		p1=p1->next;
	}
	if(p1->data>=num){
		if(p1==head){
			p0->next=head;
			head=p0;
		}
		else{
			p0->next=p1;
			p2->next=p0;
		}
	}
	else{
		p1->next=p0;
		p0->next=NULL;
	}
	return head;
}

int main(){
 	node *xxd;
	xxd=create();
	print(xxd);
	int num;
	printf("\n请输入你想插入的元素：");
	scanf("%d",&num);
	xxd=insert(xxd,num);
	print(xxd);
	printf("\n请输入你想删除的元素：");
	scanf("%d",&num);
	xxd=del(xxd,num);
	print(xxd);
}
