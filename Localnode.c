//Implementation using local pointer
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
	
}NODE;

NODE* createnode(int d)
{
	NODE *a=(NODE*)malloc(sizeof(NODE));
	
	a->data=d;
	a->next=NULL;
	return a;	
}
NODE* getlastnode(NODE *a)
{
	while(a->next!=NULL)
	    a=a->next;
	return a;
}
void display(NODE *a)
{
	if(a==NULL)
	    printf("\n empty list");
	else
	{
		while(a!=NULL)
		{
			printf("%4d",a->data);
			a=a->next;
		}
	}
	return;
}
void sorting(NODE *ptr)
{
	NODE *cpt;
	int temp;
	
	while(ptr->next!=NULL)
	{
		cpt=ptr->next;
		while(cpt!=NULL)
		{
			if(ptr->data>cpt->data)
			{
				temp=ptr->data;
				ptr->data=cpt->data;
				cpt->data=temp;
			}
			cpt=cpt->next;
		}
		ptr=ptr->next;
	}
}
void addbeg(NODE**p,int d)
{
	NODE *a=createnode(d);
	a->next=*p;
	*p=a;
}
void addend(NODE**p,int d)
{
	NODE *a=createnode(d);
	NODE *b;
	if(*p==NULL)
	    *p=a;
	else
	{
		b=getlastnode(*p);
		b->next=a;
	}
}
void reverse(NODE**p)
{
	NODE *prev=NULL;
	NODE *current=*p;
	NODE *next=NULL;
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	*p=prev;
}
void main()
{
	NODE *st=NULL;
	addbeg(&st,10);
	addbeg(&st,20);
	addend(&st,50);
	addend(&st,40);
	display(st);
	printf("\n reversed linked list");
	reverse(&st);
	display(st);
	sorting(st);
	printf("\nafter sorting");
	display(st);
	
}
