void manager_UI()
{
	fflush(stdin);
	printf("\t\t\t\t\t\t\t\t\t\t ----------------------\n");
	printf("\t\t\t\t\t\t\t\t\t\t|       ����ϵͳ       |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n"); 
	printf("\t\t\t\t\t\t\t\t\t\t|    1. ӰƬ��Ϣ����   |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");	
	printf("\t\t\t\t\t\t\t\t\t\t|    2. ��ӳ����       |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");	
	printf("\t\t\t\t\t\t\t\t\t\t|    3. Ʊ������       |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|    4. �����޸�       |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|    5.   �˳�         |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t ----------------------\n")	;
	printf("\t\t\t\t\t\t\t\t\t\t ")	;
while(1)
{
	char operation;
	operation=getch();
	switch(operation)
	{
		case '1': system("cls"); movie_manager_UI()   ; return;  
		case '2':  system("cls");movie_project_UI()   ; return;  
		case '3':  system("cls");money_manager_UI()  ; return;                          
		case '4': system("cls");password_UI(3)       ; return ;
		case '5':system("cls"); home(0) ; return ;
		default: printf("\n\t\t\t\t\t\t\t\t\t\t�����������������\n")	  ;  break;
	}
	 
}
	
	
	
	
	return;
}
void movie_manager_UI()
{
	fflush(stdin);
	printf("\t\t\t\t\t\t\t\t\t\t ----------------------\n");
	printf("\t\t\t\t\t\t\t\t\t\t|     ӰƬ����ϵͳ     |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n"); 
	printf("\t\t\t\t\t\t\t\t\t\t|     1. ӰƬ�б�      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");	
	printf("\t\t\t\t\t\t\t\t\t\t|     2. ӰƬ��ѯ      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");	
	printf("\t\t\t\t\t\t\t\t\t\t|     3. ӰƬ����      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|     4. ӰƬɾ��      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|     5.   �˳�        |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t ----------------------\n")	;
	printf("\t\t\t\t\t\t\t\t\t\t ")	;
	while(1)
{
	char operation;
	operation=getch();
	system("cls");
	switch(operation)
	{
		case '1':  movie_list_UI(2)   ; return;  
		case '2':  movie_find_UI(2)    ; return;  
		case '3':  movie_add_UI()  ; return;                          
		case '4':  movie_delete_UI()       ; return ;
		case '5':  manager_UI() ; return ;
		default: printf("\n\t\t\t\t\t\t\t\t\t\t�����������������\n")	  ;  break;
	}
	
	
	
	
	
	
 } 
}
 void movie_add_UI()  
 {
 	struct movie_list t;
 	double money,wa;
 	char s[1000];
 	int i,flag=0;
 	fflush(stdin);
 	printf("\n\t\t\t\t\t\t\t\t\t\t ������ӰƬ��������")	;
 	gets(t.movie_chinese_name) ;
	printf("\n\t\t\t\t\t\t\t\t\t\t ������ӰƬӢ������")	;
 	gets(t.movie_english_name) ;
 	printf("\n\t\t\t\t\t\t\t\t\t\t ������Ʊ�ۣ�"); 
	gets(s);
	for(i=1;i<strlen(s)-1;i++)
	{
		if(s[i]<'0'||s[i]>'9')
		{
			if(s[i]=='.')
			{
				flag++;
			}
			else
			{
				flag=10;
				break;
			}
		}
	}
	if(!(flag==0||flag==1)||s[0]<'0'||s[0]>'9'||s[strlen(s)-1]<'0'||s[strlen(s)-1]>'9')
	{
		printf("\t\t\t\t\t\t\t\t\t\t������󣬰����������");
		getch();
		system("cls");
		manager_UI();
		return ;
	}
	money=strtod(s,NULL);
 	money_add(t.movie_chinese_name,money)  ;
 	printf("\n\t\t\t\t\t\t\t\t\t\t ������ӰƬʱ����")	;
 	gets(t.movie_time) ;
 		printf("\n\t\t\t\t\t\t\t\t\t\t ����������������")	;
 	gets(t.movie_performer) ;
 		printf("\n\t\t\t\t\t\t\t\t\t\t �����뵼��������")	;
 	gets(t.movie_director) ;
 		printf("\n\t\t\t\t\t\t\t\t\t\t ��������Ƭ�ˣ�")	;
 	gets(t.movie_producer) ;
 		printf("\n\t\t\t\t\t\t\t\t\t\t ����������ص㣺")	;
 	gets(t.movie_location) ;
 		printf("\n\t\t\t\t\t\t\t\t\t\t �����뷢�й�˾��")	;
 	gets(t.movie_company) ;
 		printf("\n\t\t\t\t\t\t\t\t\t\t �������磺")	;
 	gets(t.movie_screenwriter) ;
 		printf("\n\t\t\t\t\t\t\t\t\t\t ������ӰƬ�����飺")	;
 	gets(t.movie_brief) ;

 	
	 movie_add(t);
 	
 	
 	printf("\t\t\t\t\t\t\t\t\t\t��ӳɹ���������ӣ�y/n��");
	char a = getch();
	system("cls");
	if(a!='y')
	manager_UI();
	else
	movie_add_UI()  ;
 	
 	return;
 	
	
 	
 	
 }
 void movie_delete_UI()       
 {
 	fflush(stdin);
	printf("\t\t\t\t\t\t\t\t\t\t ɾ����Ӱ�������ɻָ�!!!\n");
	printf("\t\t\t\t\t\t\t\t\t\t ������Ҫɾ���ĵ�Ӱȫ��:");
	char movie[1000];
	gets(movie);
	int ch=movie_delete_BLL(movie);
 	if(ch==1)
	 {
	 	printf("\t\t\t\t\t\t\t\t\t\tɾ���ɹ�,�������������һ��");
	  } 
	else
	{
		system("cls");
		movie_0find(movie);
	 	printf("\t\t\t\t\t\t\t\t\t\t������ĵ�Ӱ������,���������������"); 
	 	getch();
	 	movie_delete_UI();
	 	return;
	}
	getch();
	 	system("cls");
		 manager_UI();
		 return;
 }
 
 void movie_project_UI() 
 {
 	fflush(stdin);
 	printf("\t\t\t\t\t\t\t\t\t\t ----------------------\n");
	printf("\t\t\t\t\t\t\t\t\t\t|     ��ӳ����ϵͳ     |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n"); 
	printf("\t\t\t\t\t\t\t\t\t\t|    1. ���ŷ�ӳ       |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");	
	printf("\t\t\t\t\t\t\t\t\t\t|    2. �޸ķ�ӳ       |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|    3.   �˳�         |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t ----------------------\n")	;
	printf("\t\t\t\t\t\t\t\t\t\t ")	;
while(1)
{
	char operation;
	operation=getch();
	switch(operation)
	{
		case '1':  system("cls"); movie_start_UI()   ; return;  
		case '2':  system("cls"); movie_mode_UI()    ; return;  
		case '3':  system("cls"); manager_UI()       ; return;                          
		default: printf("\n\t\t\t\t\t\t\t\t\t\t�����������������")	  ;  break;
	}
	 
}
	
	return;
 	
 }
 void movie_start_UI()   
 {
 	fflush(stdin);
 	struct seat * t=seatlist ->next;
 	while(1)
 	{
 		printf("\n\t\t\t\t\t\t\t\t\t\t�������ӳ��ID��");
	 int id;
	 char ss[1000];
	 scanf("%s",ss);
	 double aa=strtod(ss,NULL);
	 id=(int)aa;

	 while(t!=NULL)
	 {
	 	if(t->ID==id)
	 	{
	 		break;
		 }
	 	t=t->next;
	 }
	 if(t==NULL) 
	 {
	 	printf("\n\t\t\t\t\t\t\t\t\t\t��ӳ�������ڣ�����������");
	 	t=seatlist ->next;
	 }
	 else break;
	 }
	 printf("\n\t\t\t\t\t\t\t\t\t\t������Ҫ��ӳ�ĵ�Ӱȫ����");
	 char s[100];
	 scanf("%s",s);
	 struct movie_list * p=moviequery(s);
	 if(p==NULL)
	 {
	 	movie_0find(s);
	 	printf("\n\t\t\t\t\t\t\t\t\t\t������ĵ�Ӱ�����ڣ��������루y/n��");
	 	char qq=getch();
	 	if(qq=='y')
	 	{
	 		system("cls");
	 		movie_start_UI() ;
			 return; 
		 }
	 	else
	 	{
	 		system("cls");
		 manager_UI();
		 return;
		 }
	 	
	  } 
	  strcpy(t->movie_name,p->movie_chinese_name);
	  seat_reset(t);
	  seat_printf();
	  printf("\n\t\t\t\t\t\t\t\t\t\t��ӷ�ӳ�ɹ��������������");
	 	getch();
	 	system("cls");
		 manager_UI();
		 return;
 }
 void movie_mode_UI()
 {
 	fflush(stdin);
 	struct seat * t=seatlist ->next;
 	while(1)
 	{
 		printf("\n\t\t\t\t\t\t\t\t\t\t�������ӳ��ID��");
	 int id;
	 char ss[1000];
	 scanf("%s",ss);
	 double aa=strtod(ss,NULL);
	 id=(int)aa;
	 
	 while(t!=NULL)
	 {
	 	if(t->ID==id)
	 	{
	 		break;
		 }
	 	t=t->next;
	 }
	 if(t==NULL) 
	 {
	 	printf("\n\t\t\t\t\t\t\t\t\t\t��ӳ�������ڣ�����������");
	 	t=seatlist ->next;
	 }
	 else break;
	 }
	 printf("\n\t\t\t\t\t\t\t\t\t\t���ڷ�ӳ��%s\n",t->movie_name);
	 printf("\n\t\t\t\t\t\t\t\t\t\t������Ҫ��ӳ�ĵ�Ӱȫ����");
	 char s[100];
	 scanf("%s",s);
	 struct movie_list * p=moviequery(s);
	 if(p==NULL)
	 {
	 	movie_0find(s);
	 	printf("\n\t\t\t\t\t\t\t\t\t\t������ĵ�Ӱ�����ڣ��������루y/n��");
	 	char qq=getch();
	 	if(qq=='y')
	 	{
	 		system("cls");
	 		movie_start_UI() ;
			 return ;
		 }
	 	else
	 	{
	 		system("cls");
		 manager_UI();
		 return;
		 }
	  } 
	  strcpy(t->movie_name,p->movie_chinese_name);
	  seat_printf();
	  printf("\n\t\t\t\t\t\t\t\t\t\t�޸ķ�ӳ�ɹ��������������");
 	  getch();
 	  system("cls");
	  manager_UI();
	  return;
 }
 void money_manager_UI()  
 {
 	fflush(stdin);
 	printf("\t\t\t\t\t\t\t\t\t\t ----------------------\n");
	printf("\t\t\t\t\t\t\t\t\t\t|     Ʊ������ϵͳ     |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n"); 
	printf("\t\t\t\t\t\t\t\t\t\t|    1. ��ӰƱ��       |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");	
	printf("\t\t\t\t\t\t\t\t\t\t|    2. Ա��ҵ��       |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|    3.   �˳�         |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t ----------------------\n")	;
	printf("\t\t\t\t\t\t\t\t\t\t ")	;
while(1)
{
	char operation;
	operation=getch();
	switch(operation)
	{
		case '1':  system("cls"); movie_money_UI()   ; return;  
		case '2':  system("cls"); staff_money_UI()    ; return;  
		case '3':  system("cls"); manager_UI()       ; return;                          
		default: printf("\n\t\t\t\t\t\t\t\t\t\t�����������������");  break;
	}
	 
}
 	return;
 	

 }
 void movie_money_UI()
 {
 	fflush(stdin);
 	struct movie_list *t=movielist->next;
 	 printf("\n\t\t\t\t\t\t\t\t\t\t����������ʽ��ţ�1.����2.����"); 
 	 char ch;
 	 while(1)
 	 {
 	 	ch=getch();
 	 	if(ch=='1'||ch=='2') break;
 	 	else printf("\n\t\t\t\t\t\t\t\t\t\t�����������������");
	  }
 	 while(t!=NULL)
       {
       	  t->money=yj(t->movie_chinese_name,2);
       	  t=t->next;
	   }
 	 
     sort1(movielist->next,ch-'0');
     t=movielist->next;
     system("cls");
          printf("\n\t\t\t\t\t\t%-50s\t\t\t\t\t%-50s","��Ӱ","Ʊ��"); 
       while(t!=NULL)
       {
       	  printf("\n\t\t\t\t\t\t%-50s\t\t\t\t\t%-50lf",t->movie_chinese_name,t->money); 
       	  t=t->next;
	   }
	  
 	printf("\n\t\t\t\t\t\t\t�����������");
 	getch();
 	system("cls");
 	money_manager_UI();
 	return;
 }
 void staff_money_UI()  
 {
 	fflush(stdin);
 	struct user_list * t=userlist;
 	printf("\n\t\t\t\t\t\t%-50s\t\t\t\t\t%-50s","Ա��id","ҵ����Ԫ��"); 
       while(t!=NULL)
       {
	   	  if(t->jurisdiction==3)
       	  printf("\n\t\t\t\t\t\t%-50s\t\t\t\t\t%-50lf",t->user_name,yj(t->user_name,1)); 
       	  t=t->next;
	   }
	  
 	printf("\n\t\t\t\t\t\t\t�����������");
 	getch();
 	system("cls");
 	money_manager_UI();
 	return;
 }  
