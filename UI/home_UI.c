

void home(int wrong)
{
	fflush(stdin);
	system("color 70");
	printf("\t\t\t\t\t\t\t\t\t\t ----------------------\n");
	printf("\t\t\t\t\t\t\t\t\t\t|     剧院管理系统     |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n"); 
	printf("\t\t\t\t\t\t\t\t\t\t|     1. 用户登录      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");	
	printf("\t\t\t\t\t\t\t\t\t\t|     2. 用户注册      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");	
	printf("\t\t\t\t\t\t\t\t\t\t|     3.   游客        |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|     4.   退出        |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t ----------------------\n")	;
	if(wrong)
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t 输入有误，请重新输入操作序号:")	;
	}
	else
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t 请输入要执行的操作序号:"); 
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


void login_UI(int state)   //登录，根据权限进不同界面 
{
	fflush(stdin);
	int grade;
	char account[2000];
	char password[2000];
	if(state==-1)
	{	
		printf("\t\t\t\t\t\t\t\t\t\t   密码或账号错误\n\n");
		printf("\t\t\t\t\t\t\t\t\t\t   0     退出程序\n\n");
		printf("\t\t\t\t\t\t\t\t\t\t   1     重新登录\n\n");
		printf("\t\t\t\t\t\t\t\t\t\t   2     返回主页\n\n");
		printf("\t\t\t\t\t\t\t\t\t\t 请输入您要进行的操作序号："); 
		
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
				printf("\n\t\t\t\t\t\t\t\t\t\t输入错误，请重新输入:");
				continue;
			}
			return ;
		}
		
	}
	printf("\n\t\t\t\t\t\t\t\t\t\t 请输入账号:");
	gets(account);
	if(strlen(account)>30)
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t账号超长，请重新登录\n");
		getch();
		login_UI(-1);
		 
		 
	}
	printf("\n\t\t\t\t\t\t\t\t\t\t 请输入密码:");
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
		printf("\n\t\t\t\t\t\t\t\t\t\t密码超长，请重新登录\n");
		getch();
		login_UI(-1);
		 
		 
	}
	
	system("cls");
	grade=login_BLL(account,b);
	switch(grade)
	{
		case 1:printf("\n\t\t\t\t\t\t\t\t\t\t 欢迎：%s (admin)\n",nowuser.username);
  			 
		admin_UI();   return;       //管理员 
		
		case 2:
			
		printf("\n\t\t\t\t\t\t\t\t\t\t 欢迎：%s (manager)\n",nowuser.username);
		
		manager_UI(); return;      //经理 
		
		case 3:printf("\n\t\t\t\t\t\t\t\t\t\t 欢迎：%s (staff)\n",nowuser.username);
		
		staff_UI();   return;		//员工
		
		case 4:printf("\n\t\t\t\t\t\t\t\t\t\t 欢迎：%s (user)\n",nowuser.username);
		
		user_UI();   return;	   //用户 
		
		default:login_UI(-1);return;
	}
	
	
	return ;
}

void logon_UI(int step)    //注册；此处注册权限为4 
{
	fflush(stdin);
	printf("\n\t\t\t\t\t\t\t\t\t\t 请输入账号（需以字母开头且包含7-19个字符）：");
	char username[1000],password[1000];
		gets(username);
	printf("\n\t\t\t\t\t\t\t\t\t\t 请输入密码（长度为7-19个字符）：");
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
		printf("\n\t\t\t\t\t\t\t\t\t\t 账号或密码长度不符合要求，请重新输入\n");
		logon_UI(0);
		return; 
	}
	if(s1==2)
	{
		system("cls");
		printf("\n\t\t\t\t\t\t\t\t\t\t 账号已存在，请重新注册\n");
		logon_UI(0);
		return ;
	 } 
	 if(s1==100)
	 {
	 	system("cls");
		printf("\n\t\t\t\t\t\t\t\t\t\t 账号或密码存在特殊字符，请重新注册\n");
		logon_UI(0);
		return ;
	 }
	 if(s1==0)
	 {
	 	user_add(username,password,4);
	 }
	system("cls");
	printf("\n\t\t\t\t\t\t\t\t\t\t 注册成功,前往登录\n");
	login_UI(0);
	
/*	struct user_list * query(char * username)*/
	return;
}

