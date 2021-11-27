//create a list as a headerfile

typedef struct node
{
	int data;
	struct node *next;
	
}NODE;
typedef struct list
{
	NODE *st;
	int cnt;
}LIST;
void init(LIST *t)
{
	t->st=NULL;
	t->cnt=0;
}
NODE* createnode(int d)
{
	NODE *a;
	a=(NODE*)malloc(sizeof(NODE));
	
	a->data=d;
	a->next=NULL;
	return a;	
}
void display(LIST *t)
{
	NODE *a=t->st;
	if(t->st==NULL)
	   printf("\n empty list");
	else
	{
		while(a!=NULL)
		{
			printf("%4d",a->data);
			a=a->next;
		}
	}
}
void addbeg(LIST *t,int d)
{
	NODE *a;
	a=createnode(d);
	a->next=t->st;
	t->st=a;
	t->cnt=t->cnt+1;
}
void addend(LIST *t,int d)
{
	NODE *a,*b;
	a=createnode(d);
	if(t->st==NULL)
	    t->st=a;
	else
	{
		b=t->st;
		while(b->next!=NULL)
		    b=b->next;
		b->next=a;
	}
	t->cnt=t->cnt+1;
}
int total(LIST *t)
{
	int tot=0;
	NODE *a=t->st;
	while(a!=NULL)
	{
		tot+=a->data;
		a=a->next;
	}
	return tot;	
}
int findmax(LIST *t)
{
	int max;
	NODE *a=t->st;
	while(a!=NULL)
	{
		if(a==t->st)
		    max=a->data;
		else
		{
			if(a->data>max)
			   max=a->data;
		}
		a=a->next;
	}
	return max;
}
int findmin(LIST *t)
{
	int min;
	NODE *a=t->st;
	while(a!=NULL)
	{
		if(a==t->st)
		    min=a->data;
		else
		{
			if(a->data<min)
			   min=a->data;
		}
		a=a->next;
	}
	return min;
}
int search(LIST *t,int sv)
{
	int flag=0;
	NODE *a=t->st;
	while(a!=NULL)
	{
		if(a->data==sv)
		{
			flag=1;
			break;
		}
		a=a->next;
	}
	return flag;
}
void findreplace(LIST *t,int sv,int rv)
{
	NODE *a=t->st;
	while(a!=NULL)
	{
		if(a->data==sv)
		{
			a->data=rv;
		}
		a=a->next;
	}
	return;
}
void delfirst(LIST *t)
{
	NODE *a=t->st;
	if(t->st==NULL)
	   return;
	t->st=a->next;
	t->cnt=t->cnt-1;
	free(a);
}
void dellast(LIST *t)
{
	NODE *a=t->st;
	NODE *b;
	if(t->st==NULL)
	   return;
	if(a->next==NULL)
	   t->st=NULL;
	else
	{
		while(a->next!=NULL)
		{
			b=a;
			a=a->next;
		}
		b->next=NULL;
	}
	t->cnt=t->cnt-1;
	free(a);
}
//Function to make entire list empty
void delall(LIST *t)
{
	while(t->st!=NULL)
	   delfirst(t);
}
//Function to delete all nodes
void empty(LIST *t)
{
	NODE *a=t->st;
	NODE *b;
	while(a!=NULL)
	{
		b=a->next;
		free(a);
		a=b;
	}
	t->st=NULL;
	t->cnt=0;
}
//function to delete ith node
void delinode(LIST *t,int pos)
{
	NODE *a=t->st,*b;
	int i=1;
	if(t->st==NULL)
	   return;
	if(pos<1||pos>t->cnt)
	   return;
	if(pos==1)
	   delfirst(t);
	else
	{
		if(pos=t->cnt)
		   dellast(t);
		else
		{
			while(i<pos)
			{
				b=a;
				a=a->next;
				i++;
			}
			b->next=a->next;
			free(a);
			t->cnt=t->cnt-1;
		}
	}
	
}
// function to reverse list
void reverse(LIST *t)
{
	NODE *a=t->st,*b,*c=NULL;
	while(a!=NULL)
	{
		b=a->next;
		a->next=c;
		c=a;
		a=b;
	}
	t->st=c;
}
// function to count odd nodes
int oddcount(LIST *t)
{
	NODE *a=t->st;
	int cnt=0;
	while(a!=NULL)
	{
		cnt+=(a->data%2==0);
		a=a->next;
	}
	return cnt;
}
// function to count even nodes
int evencount(LIST *t)
{
	NODE *a=t->st;
	int cnt=0;
	while(a!=NULL)
	{
		if(a->data%2==0)
		  cnt++;
		a=a->next;
	}
	return cnt;
}
//function to check data in ascending order or not
int isordered(LIST *t)
{
	NODE *a=t->st,*b;
	if(t->cnt==0)
	    return 0;
	b=a;
	for(a=a->next;a!=NULL;a=a->next)
	{
		if(a->data>b->data)
		    b=a;
		else 
		    break;
	}
	if(a!=NULL)
	   return 0;
	else
	   return 1;	
}
//function to copy list
LIST* copy(LIST *t)
{
	NODE *a=t->st;
	LIST k;
	init(&k);
	while(a!=NULL)
	{
		addend(&k,a->data);
		a=a->next;
	}
	return k;
}
//function to copy list in reverse order
LIST* rcopy(LIST *t)
{
	NODE *a=t->st;
	LIST k;
	init(&k);
	while(a!=NULL)
	{
		addbeg(&k,a->data);
		a=a->next;
	}
	return k;
}
//function
void revdisplay(NODE *a)
{
	if(a==NULL)
		return;
	reversedisplay(a->next);
	printf("%4d",a->data);
}
void sort(LIST *t)
{
	NODE *a=t->st,*b,*c;
	int temp;
	while(a->next!=NULL)
	{
		b=a;
		c=a->next;
		while(c!=NULL)
		{
			if(c->data<b->data)
				b=c;
			c=c->next;
		}
		if(a!=b)
		{
			temp=a->data;
			a->data=b->data;
			b->data=temp;
			
		}
		a=a->next;
	}
	
}
//
void insertb(LIST *t,int d,int pos)
{
	NODE *a=t->st;,*b,*c;
	int i=1;
	if(t->cnt==0)
		return;
	if(pos<1||pos>t->cnt)
		return;
	if(pos==1)
		addbeg(t,d);
	else
	{
		while(i<pos)
		{
			b=a;
			a=a->next;
			i++;
		}
		c=createnode(d);
		b->next=c;
		c->next=a;
		t->cnt++;
	}
}
//
void inserta(LIST *t,int d,int pos)
{
	NODE *a=t->st;,*b,*c;
	int i=1;
	if(t->cnt==0)
		return;
	if(pos<1||pos>t->cnt)
		return;
	if(pos==1)
		addend(t,d);
	else
	{
		while(i<=pos)
		{
			b=a;
			a=a->next;
			i++;
		}
		c=createnode(d);
		b->next=c;
		c->next=a;
		t->cnt++;
	}
}
