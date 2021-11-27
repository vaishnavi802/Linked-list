//Display list using headerfile
#include<stdio.h>
#include<stdlib.h>
#include"list.h"

void main()
{
	LIST p;
	init(&p);
	addbeg(&p,20);
	addbeg(&p,10);
	addend(&p,30);
	addend(&p,40);
	display(&p);
	return;
}
