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

int main(){
 	node *xxd;
	xxd=create();
	length(xxd);
	print(xxd);
}
