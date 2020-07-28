
void user_scanf()
{
	FILE * fp;
	fp=fopen("./DAL/user_list.ini","r");
	if(fp==NULL)
	{
		printf("\t\t\t\t\t\t\t\t\t\t用户文件打开失败！！");
		getch();
		exit(0);
	}
	int jurisdiction; //权限
	char username[20];
	char password[20];
	struct user_list *head,*p,*q;
	head=(struct user_list *)malloc(sizeof(struct user_list));
	head->next=NULL;
	while(fscanf(fp,"%s %s %d",username,password,&jurisdiction)!=EOF) 
	{
		p=(struct user_list *)malloc(sizeof(struct user_list));
		p->next=NULL;
		p->jurisdiction=jurisdiction;
		strcpy(p->user_name,username);
		strcpy(p->user_password,password);
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
	userlist=head;
	return;
}
void user_printf()
{
	FILE *fp;
	fp=fopen("./DAL/user_list.ini","w+");
	if(fp==NULL)
	{
		printf("\t\t\t\t\t\t\t\t\t\t用户文件打开失败！！");
		getch();
		exit(0);
	}
	struct user_list * t;
	t=userlist->next;
	while(t!=NULL)
	{
		fprintf(fp,"%s %s %d\n",t->user_name,t->user_password,t->jurisdiction);
		t=t->next;
	}
	fclose(fp);
	return ;	
}
