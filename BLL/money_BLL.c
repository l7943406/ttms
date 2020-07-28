void money_add(char *s,double money)
{
	struct money * t=moneylist;
	struct money * p=(struct money *)malloc(sizeof(struct money));
	p->money=money;
	strcpy(p->movie,s);
	while(t->next!=NULL)
	{
		if(t->money>=money)
		{
			break;
		}
		t=t->next;
	}
	if(t->next==NULL)
	{
		t->next=p;
		p->last=t;
		p->next=NULL;
	}
	else
	{
		p->next=t->next;
		p->last=t;
		t->next=p;
		p->next->last=p;
	}
	money_printf();
	return ;
}
void money_del(char *s)
{
	struct money * t=moneylist->next;
	while(t!=NULL)
	{
		if(strcmp(t->movie,s)==0)
		{
			break;
		}
		t=t->next;
	}
	if(t==NULL)
	return;
	if(t->next==NULL)
	{
		t->last->next=NULL;
		free(t);
	}
	else
	{
		t->last->next=t->next;
		t->next->last=t->last;
		free(t); 
	}
	
	
	
	money_printf();
}
double money_find(char *s)
{
	struct money * t=moneylist;
	while(t!=NULL)
	{
		if(strcmp(s,t->movie)==0)
		{
			break;
		}
		t=t->next;
	}
	return t->money;
	return ;
}
