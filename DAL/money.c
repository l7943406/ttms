
void money_scanf()
{
	FILE * fp;
	fp=fopen("./DAL/money.ini","r+");
		if(fp==NULL)
	{
		printf("\t\t\t\t\t\t\t\t\t\t票务信息文件打开失败！！");
		getch();
		exit(0);
	}
	char movie[100];
	double money;
	struct money *head,*p,*q;
	head=(struct money *)malloc(sizeof(struct money));
	head->next=NULL;
	head->last=NULL;
	while(fscanf(fp,"%s",movie)!=EOF) 
	{
		p=(struct money *)malloc(sizeof(struct money));
		fscanf(fp,"%lf",&money);
		char a;
		fscanf(fp,"%c",&a);
		p->next=NULL;
		p->last=NULL;
		strcpy(p->movie,movie);
        p->money=money;
		if(head->next==NULL)
		{
			head->next=p;
			p->last=head;
			q=p;
		}
		else
		{
			q->next=p;
			p->last=q;
			q=p;
		}	
	}
	fclose(fp);
	moneylist=head;
	return;
}
void money_printf()
{
	FILE *fp;
	fp=fopen("./DAL/money.ini","w+");
		if(fp==NULL)
	{
		printf("\t\t\t\t\t\t\t\t\t\t票务信息文件打开失败！！");
		getch();
		exit(0);
	}
	struct money * t;
	t=moneylist->next;
	while(t!=NULL)
	{
		fprintf(fp,"%s\n%lf\n",t->movie,t->money);
		t=t->next;
	}
	fclose(fp);
	return ;	
}
