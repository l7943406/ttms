

void home(int wrong)
{
	fflush(stdin);
	system("color 70");
	printf("\t\t\t\t\t\t\t\t\t\t ----------------------\n");
	printf("\t\t\t\t\t\t\t\t\t\t|     ��Ժ����ϵͳ     |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n"); 
	printf("\t\t\t\t\t\t\t\t\t\t|     1. �û���¼      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");	
	printf("\t\t\t\t\t\t\t\t\t\t|     2. �û�ע��      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");	
	printf("\t\t\t\t\t\t\t\t\t\t|     3.   �ο�        |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|     4.   �˳�        |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t ----------------------\n")	;
	if(wrong)
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t ������������������������:")	;
	}
	else
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t ������Ҫִ�еĲ������:"); 
	}
	char operation;
	operation=getch();
	system("cls");
	switch(operation)
	{
		case '1':  login_UI(0)   ; break;  
		case '2':  logon_UI(4)    ; break;  
		case '3':  tourist_UI()  ; break;                           
		case '4':  return;       ; break;
		default:   home(1)       ; break;
	}
	 
	
	
	return ;
}


void login_UI(int state)   //��¼������Ȩ�޽���ͬ���� 
{
	fflush(stdin);
	int grade;
	char account[2000];
	char password[2000];
	if(state==-1)
	{	
		printf("\t\t\t\t\t\t\t\t\t\t   ������˺Ŵ���\n\n");
		printf("\t\t\t\t\t\t\t\t\t\t   0     �˳�����\n\n");
		printf("\t\t\t\t\t\t\t\t\t\t   1     ���µ�¼\n\n");
		printf("\t\t\t\t\t\t\t\t\t\t   2     ������ҳ\n\n");
		printf("\t\t\t\t\t\t\t\t\t\t ��������Ҫ���еĲ�����ţ�"); 
		
		while(1)
		{
			char ch=getch();
			if(ch=='0') 
			{
				system("cls");
				return;
			}
			else if(ch=='1')
			{
				system("cls");
				login_UI(0);
				return ;
			 } 
			else if(ch=='2')
			{
			 	 system("cls");
				 home(0); 
				 return ;
			 } 
			else 
			{
				printf("\n\t\t\t\t\t\t\t\t\t\t�����������������:");
				continue;
			}
			return ;
		}
		
	}
	printf("\n\t\t\t\t\t\t\t\t\t\t �������˺�:");
	gets(account);
	if(strlen(account)>30)
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t�˺ų����������µ�¼\n");
		getch();
		login_UI(-1);
		 
		 
	}
	printf("\n\t\t\t\t\t\t\t\t\t\t ����������:");
	int k;
	char b[31];
	for(k=0;k<30;k++)
	{
		b[k]=getch();
		printf("*");
		if(b[k]==8&&k>0)
		{
			printf("\b\b  \b\b");
			k-=2;
		}
		if(b[k]==8&&k==0)
		{
			printf("\b \b");
			k--;
			continue;
		}
		if(b[k]==13)
		{
			printf("\b\b  \b\b*");
			b[k]=0;
			break;
		}
	}
	if(strlen(b)==30&&b[29]!='\0')
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t���볬���������µ�¼\n");
		getch();
		login_UI(-1);
		 
		 
	}
	
	system("cls");
	grade=login_BLL(account,b);
	switch(grade)
	{
		case 1:printf("\n\t\t\t\t\t\t\t\t\t\t ��ӭ��%s (admin)\n",nowuser.username);
  			 
		admin_UI();   return;       //����Ա 
		
		case 2:
			
		printf("\n\t\t\t\t\t\t\t\t\t\t ��ӭ��%s (manager)\n",nowuser.username);
		
		manager_UI(); return;      //���� 
		
		case 3:printf("\n\t\t\t\t\t\t\t\t\t\t ��ӭ��%s (staff)\n",nowuser.username);
		
		staff_UI();   return;		//Ա��
		
		case 4:printf("\n\t\t\t\t\t\t\t\t\t\t ��ӭ��%s (user)\n",nowuser.username);
		
		user_UI();   return;	   //�û� 
		
		default:login_UI(-1);return;
	}
	
	
	return ;
}

void logon_UI(int step)    //ע�᣻�˴�ע��Ȩ��Ϊ4 
{
	fflush(stdin);
	printf("\n\t\t\t\t\t\t\t\t\t\t �������˺ţ�������ĸ��ͷ�Ұ���7-19���ַ�����");
	char username[1000],password[1000];
		gets(username);
	printf("\n\t\t\t\t\t\t\t\t\t\t ���������루����Ϊ7-19���ַ�����");
	int k;
	char b[1000];
	for(k=0;k<1000;k++)
	{
		b[k]=getch();
		printf("*");
		if(b[k]==8&&k>0)
		{
			printf("\b\b  \b\b");
			k-=2;
		}
		if(b[k]==8&&k==0)
		{
			printf("\b \b");
			k--;
			continue;
		}
		if(b[k]==13)
		{
			printf("\b\b  \b\b*");
			b[k]=0;
			break;
		}
	}
	strcpy(password,b);
	int s1=logonuser_BLL(username,password);
	if(s1==1)
	{
		system("cls");
		printf("\n\t\t\t\t\t\t\t\t\t\t �˺Ż����볤�Ȳ�����Ҫ������������\n");
		logon_UI(0);
		return; 
	}
	if(s1==2)
	{
		system("cls");
		printf("\n\t\t\t\t\t\t\t\t\t\t �˺��Ѵ��ڣ�������ע��\n");
		logon_UI(0);
		return ;
	 } 
	 if(s1==100)
	 {
	 	system("cls");
		printf("\n\t\t\t\t\t\t\t\t\t\t �˺Ż�������������ַ���������ע��\n");
		logon_UI(0);
		return ;
	 }
	 if(s1==0)
	 {
	 	user_add(username,password,4);
	 }
	system("cls");
	printf("\n\t\t\t\t\t\t\t\t\t\t ע��ɹ�,ǰ����¼\n");
	login_UI(0);
	
/*	struct user_list * query(char * username)*/
	return;
}

