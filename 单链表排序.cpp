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
node *sort(node *head){//两两比较，把最大的先放到最后 
	node *p;
	p=head;
	int len=length(head);
	int i,j,temp;
	if(head==NULL||head->next==NULL)
		return (head);
	for(j=1;j<len;j++){
		p=head;
		for(i=0;i<len-j;i++){//第一次取最大值要进行的比较次数 
			if(p->data>p->next->data){
				temp=p->data;
				p->data=p->next->data;
				p->next->data=temp;
			}
			p=p->next;
		}
	}
	return (head);
}
int main(){
	node *xxd;
	xxd=create();
	length(xxd);
	sort(xxd);
	print(xxd);
}
