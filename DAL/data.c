
void data_scanf()
{
	FILE * fp;
	fp=fopen("./DAL/data.ini","r");
		if(fp==NULL)
	{
		printf("\t\t\t\t\t\t\t\t\t\t日志文件打开失败！！");
		getch();
		exit(0);
	}
	char user[100];
	char movie[100];
	char s[100];
	struct data *head,*p,*q;
	head=(struct data *)malloc(sizeof(struct data));
	head->next=NULL;
	while(fscanf(fp,"%s%s%s",user,s,movie)!=EOF) 
	{
		p=(struct data *)malloc(sizeof(struct data));
		p->next=NULL;
		strcpy(p->movie,movie);
		strcpy(p->s,s);
		strcpy(p->user,user);
		if(head->next==NULL)
		{
			head->next=p;
			q=p;
		}
		else
		{
			q->next=p;
			q=p;
		}	
	}
	fclose(fp);
	datalist=head;
	return;
}
void data_printf()
{
	FILE *fp;
	fp=fopen("./DAL/data.ini","w+");
		if(fp==NULL)
	{
		printf("\t\t\t\t\t\t\t\t\t\t日志文件打开失败！！");
		getch();
		exit(0);
	}
	struct data * t;
	t=datalist->next;
	while(t!=NULL)
	{
		fprintf(fp,"%s\n%s\n%s\n",t->user,t->s,t->movie);
		t=t->next;
	}
	fclose(fp);
	return ;	
}
void data_add(char *s,char *movie,int sale)
{
	struct data * t=datalist;
	struct data * p=(struct data *)malloc(sizeof(struct data));
	p->next=t->next;
	t->next=p;
	strcpy(p->movie,movie);
	strcpy(p->user,s);
	if(sale==1)
	{
		
		strcpy(p->s,"sale");
	}
	else
	{
		strcpy(p->s,"sell");
	}
	data_printf();
	return ;
}
double yj(char *s,int k)
{
	double ans=0;
	struct data * t=datalist->next;
	
	if(k==1)
	{
		while(t!=NULL)
		{
			if(strcmp(t->user,s)==0)
			{
				if(strcmp(t->s,"sale")!=0)
				ans-=money_find(t->movie);
				else
				ans+=money_find(t->movie);
			}
			t=t->next;
		}
	}
	
	
	if(k==2)
	{
        while(t!=NULL)
		{
			if(strcmp(t->movie,s)==0)
			{
				if(strcmp(t->s,"sale")!=0)
				ans-=money_find(t->movie);
				else
				ans+=money_find(t->movie);
			}
			t=t->next;
		}
	}
	return ans;
}


