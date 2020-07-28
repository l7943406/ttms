/*void seat_printf();
void seat_scanf(); 
struct seat
{
	int ID;
	int n,m;
	int seat[100][100];
	char movie_name[100];
};
struct seat * seatlist;*/
void seat_scanf()
{
	FILE * fp;
	fp=fopen("./DAL/seat_list.ini","r");
		if(fp==NULL)
	{
		printf("\t\t\t\t\t\t\t\t\t\t座位信息文件打开失败！！");
		getch();
		exit(0);
	}
	int i,j,ID,n,m;
	struct seat *head,*p,*q;
	head=(struct seat *)malloc(sizeof(struct seat));
	head->next=NULL;
	while(fscanf(fp,"%d %d %d",&ID,&n,&m)!=EOF) 
	{
		p=(struct seat *)malloc(sizeof(struct seat));
		p->next=NULL;
		p->n=n;
		p->m=m;
		p->ID=ID;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				fscanf(fp,"%d",&p->seat[i][j]);
			}
		}
		fscanf(fp,"%s",p->movie_name);
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
	seatlist=head;
	return;
}
void seat_printf()
{
	FILE *fp;
	fp=fopen("./DAL/seat_list.ini","w+");
		if(fp==NULL)
	{
		printf("\t\t\t\t\t\t\t\t\t\t座位信息文件打开失败！！");
		getch();
		exit(0);
	}
	struct seat * t;
	t=seatlist->next;
	int i,j;
	while(t!=NULL)
	{
		fprintf(fp,"%d %d %d\n",t->ID,t->n,t->m);
		for(i=0;i<t->n;i++)
		{
			for(j=0;j<t->m;j++)
			{
				fprintf(fp,"%d ",t->seat[i][j]);
			}
			fprintf(fp,"\n");
		}
		fprintf(fp,"%s\n",t->movie_name);
		t=t->next;
	}
	fclose(fp);
	return ;	
}
