void movie_list_UI(int ste)
{
	fflush(stdin);
	struct movie_list *t;
	t=movielist;
	t=t->next;
	printf("\n%-40s%-100s%-40s\n","Ƭ��","����","Ƭ��");
	while(t!=NULL)
	{
		printf("%-40s%-100s%-40s\n",t->movie_chinese_name,t->movie_performer,t->movie_time);
		t=t->next;
	}
	printf("�������������һ��");
	getch();
	system("cls");
	if(ste==0)
	tourist_UI();
	else if(ste==1)
	user_UI();
	else if(ste==2)
	movie_manager_UI();
	return;
}

void movie_find_UI(int ste)
{
	fflush(stdin);
	system("cls");
	printf("\t\t\t\t\t\t\t\t\t\t ----------------------\n");
	printf("\t\t\t\t\t\t\t\t\t\t|        ӰƬ����      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n"); 
	printf("\t\t\t\t\t\t\t\t\t\t|     1. ��Ƭ������    |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n"); 	
	printf("\t\t\t\t\t\t\t\t\t\t|     2. �����ݲ���    |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n"); 	
	printf("\t\t\t\t\t\t\t\t\t\t|     3.   �˳�        |\n");
	printf("\t\t\t\t\t\t\t\t\t\t ----------------------\n")	;
	printf("\t\t\t\t\t\t\t\t\t\t ")	;
	char operation;
	while(1)
	{
	operation=getch();
	switch(operation)
	{
		case '1':  system("cls")  ;movie_find1_UI(ste);  return;  
		case '2':  system("cls")  ;movie_find2_UI(ste);  return;  
		case '3':  
		{							system("cls")  ;	
			 	   				  	if(ste==0)
			 	   				  	tourist_UI();
	 								else if(ste==1)
									user_UI();
									else if(ste==2)
									movie_manager_UI(); 
									return;
		}
		default:   printf("\n\t\t\t\t\t\t\t\t\t\t �����������������")	; 
	}

	}
}
void movie_find1_UI(int ste)
{
	fflush(stdin);
	struct movie_list *t;
	t=movielist;
	t=t->next;
	printf("\t\t\t\t\t\t\t\t\t\t ����ӰƬ���ƣ�");
	char s[100];
	scanf("%s",s); 
	while(t!=NULL)
	{
		if(strcmp(s,t->movie_chinese_name)==0)
		{
			movie_print_UI(t);
			printf("\t\t\t\t\t\t\t\t\t\t�����������");
			getch();
			movie_find_UI(ste);
			return ;
		}
		t=t->next;
	}
	t=movielist;
	t=t->next;
	int x=0;
	while(t!=NULL)
	{
		if(strstr(t->movie_chinese_name,s)!=NULL)
		{
			x=1;
			break;
		}
		t=t->next;
	}
	t=movielist;
	t=t->next;
	if(x==1) printf("\t\t\t\t\t\t\t\t\t\tû�ҵ�ѽ����Ҫ�ҵ��ǲ��ǣ�\n");
	else
	{
		printf("\t\t\t\t\t\t\t\t\t\tδ�ҵ�ӰƬ������������أ�\n");
		getch();
		movie_find_UI(ste);
		return ;
	}
	printf("\n%-40s%-100s%-40s\n","Ƭ��","����","Ƭ��");
	while(t!=NULL)
	{
		if(strstr(t->movie_chinese_name,s)!=NULL)
		{
			printf("%-40s%-100s%-40s\n",t->movie_chinese_name,t->movie_performer,t->movie_time);
		}
		t=t->next;
	}
	printf("\t\t\t\t\t\t\t\t\t\t����������أ�");
	getch();
	movie_find_UI(ste);
	return ;
	
}
void movie_find2_UI(int ste)
{
	fflush(stdin);
	struct movie_list *t;
	t=movielist;
	t=t->next;
	printf("\t\t\t\t\t\t\t\t\t\t ��������������");
	char s[100];
	scanf("%s",s); 
	t=movielist;
	t=t->next;
	int x=0;
	while(t!=NULL)
	{
		if(strstr(t->movie_performer,s)!=NULL)
		{
			x=1;
			break;
		}
		t=t->next;
	}
	t=movielist;
	t=t->next;
	if(x!=1) 
	{
		printf("\t\t\t\t\t\t\t\t\t\tδ�ҵ�������Ϣ������������أ�\n");
		getch();
		movie_find_UI(ste);
		return ;
	}
	printf("\n%-40s%-100s%-40s\n","Ƭ��","����","Ƭ��");
	while(t!=NULL)
	{
		if(strstr(t->movie_performer,s)!=NULL)
		{
			printf("%-40s%-100s%-40s\n",t->movie_chinese_name,t->movie_performer,t->movie_time);
		}
		t=t->next;
	}
	printf("\t\t\t\t\t\t\t\t\t\t����������أ�");
	getch();
	movie_find_UI(ste);
	return ;
}
void movie_print_UI(struct movie_list *t)
{
	fflush(stdin);
	system("cls");
	int i;
	for(i=0;i<189;i++)
	printf("=") ;
	printf("\n ӰƬ�� ��%-60sӢ������%-60s\n",t->movie_chinese_name,t->movie_english_name);
	printf("  ����  ��%-60s ��Ա ��%-60s\n",t->movie_director,t->movie_performer);
	printf("��Ʒ��˾��%-60s��Ƭ�ˣ�%-60s\n",t->movie_company,t->movie_producer);
	printf(" ����� ��%-60s ��� ��%-60s\n",t->movie_location,t->movie_screenwriter);
	printf("�����飺\n");
	printf("%s\n\n",t->movie_brief);
		for(i=0;i<189;i++)
	printf("=") ;
	
	
	
	
	return ;
 } 
 
 
 
 
void movie_0find(char *s)
{
	fflush(stdin);
	struct movie_list *t;
	t=movielist;
	t=t->next;
	int x=0;
	while(t!=NULL)
	{
		if(strstr(t->movie_chinese_name,s)!=NULL)
		{
			x=1;
			break;
		}
		t=t->next;
	}
	t=movielist;
	t=t->next;
	if(x==1)
	{
		printf("\n\t\t\t\t\t\t\t\t\t\tû�ҵ�ѽ����Ҫ�ҵ��ǲ��ǣ�\n");
		printf("\n%-40s%-100s%-40s\n","Ƭ��","����","Ƭ��");
	}
	while(t!=NULL)
	{
		if(strstr(t->movie_chinese_name,s)!=NULL)
		{
			printf("%-40s%-100s%-40s\n",t->movie_chinese_name,t->movie_performer,t->movie_time);
		}
		t=t->next;
	}
	return ;
	
	
	
}
