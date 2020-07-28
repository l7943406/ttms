void admin_UI()
{
	fflush(stdin);
	printf("\t\t\t\t\t\t\t\t\t\t ----------------------\n");
	printf("\t\t\t\t\t\t\t\t\t\t|    管 理 员 系 统    |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n"); 
	printf("\t\t\t\t\t\t\t\t\t\t|     1. 用户列表      |\n");	
	printf("\t\t\t\t\t\t\t\t\t\t|     2. 添加用户      |\n");	
	printf("\t\t\t\t\t\t\t\t\t\t|     3. 注销用户      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|     4. 用户权限      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|     5. 座位管理      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|     6. 退出          |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t ----------------------\n")	;
	char operation;
	printf("\t\t\t\t\t\t\t\t\t\t 请选择要进行的操作:");
	operation=getch();
	system("cls");
	switch(operation)
	{
		case '1':  user_list_UI()   ;   break;  
		case '2':  user_add_UI()    ;   break;  
		case '3':  user_delete_UI() ;   break;                           
		case '4':  user_access_UI() ;   break;
		case '5':  seat_admin()     ;   break;
		case '6':  home(0)         ;   break;
		default:  printf("\n\t\t\t\t\t\t\t\t\t\t 输入错误，请重新输入")         ; admin_UI();  break;
	}
	return ;
}
void user_list_UI()
{
		fflush(stdin);

	struct user_list *t;
	t=userlist;
	t=t->next;
	while(t!=NULL)
	{
		printf("\t\t\t\t\t\t\t\t\t\t 用户名:%s\t用户权限:%d\n",t->user_name,t->jurisdiction);
		t=t->next;
	}
	printf("\n");
	printf("\t\t\t\t\t\t\t\t\t\t 按任意键返回上一层");
	getch();
	system("cls");
	admin_UI();
	return;
}
void user_add_UI()
{
		fflush(stdin);

	char password[1000],user[1000];
	printf("\t\t\t\t\t\t\t\t\t\t 请输入用户名(长度7-19且以字母开头)：");
	scanf("%s",user); 
	printf("\t\t\t\t\t\t\t\t\t\t 请输入密码(长度7-19)：");
	scanf("%s",password);
	int step=logonuser_BLL(user,password);
	if(step==1)
	{
		system("cls");	
		printf("\n\t\t\t\t\t\t\t\t\t\t 用户名或密码长度不符合要求，请重新输入\n");
		user_add_UI();
		return ;
	}
	else if(step==2)
	{
		system("cls");	
		printf("\n\t\t\t\t\t\t\t\t\t\t 用户名已存在，请重新输入\n");
		user_add_UI();
		return ;
	}
	printf("\n\t\t\t\t\t\t\t\t\t\t 请选择该用户权限：1.管理员  2.经理  3.员工 4.用户\n\t\t\t\t\t\t\t\t\t\t");
	int ch;
	while(1)
	{
		ch=getch();
		if(ch>'4'||ch<'1')
		{
			printf("\n\t\t\t\t\t\t\t\t\t\t 输入错误，请重新输入:\n");
			continue;
		} 
		else
		{
			user_add(user,password,ch-'0');
			break;
		}

		 
	}
	
	
	printf("\n\t\t\t\t\t\t\t\t\t\t 新增用户成功按任意键返回上一页");
	getch();
	system("cls");
 	admin_UI();
	return ;
	
	
}
void  user_delete_UI()  
{
		fflush(stdin);
	
	printf("\n\t\t\t\t\t\t\t\t\t\t 删除用户操作不可恢复!!!\n");
	printf("\n\t\t\t\t\t\t\t\t\t\t 请输入要删除的用户名:");
	char user[1000];
	scanf("%s",user);
	int ch=user_delete_BLL(user);
 	if(ch==1)
	 {
	 	printf("\n\t\t\t\t\t\t\t\t\t\t注销成功,按任意键返回上一层");
	  } 
	else
	{
	 	printf("\n\t\t\t\t\t\t\t\t\t\t用户不存在,按任意键返回上一层"); 
	}
	getch();
	 	system("cls");
		 admin_UI();
		 return; 
}
 
void user_access_UI()
{
		fflush(stdin);
	
	printf("\n\t\t\t\t\t\t\t\t\t\t请输入要修改权限的用户名:"); 
	char user[1000];
	scanf("%s",user);
	struct user_list * tep=query(user);
	if(tep==NULL) 
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t用户名不存在,按任意键返回"); 
		getch();
	 	system("cls");
		 admin_UI();
		 return; 
	}
	printf("\n\t\t\t\t\t\t\t\t\t\t用户名:%s  权限等级 %d\n",tep->user_name,tep->jurisdiction); 
	printf("\n\t\t\t\t\t\t\t\t\t\t修改权限为:"); 
	char ch;
		while(1)
	{
		ch=getch();
		if(ch>'4'||ch<'1')
		{
			printf("\n\t\t\t\t\t\t\t\t\t\t 输入错误，请重新输入:\n");
			continue;
		} 
		else
		{
			tep-> jurisdiction=ch-'0';
			user_printf();
			break;
		}

		 
	}
	
	
	
	printf("\n\t\t\t\t\t\t\t\t\t\t 修改权限成功任意键返回上一页\n");
	getch();
	system("cls");
 	admin_UI();
	return ;
	
	
	
	
	
	
	
}

void seat_admin()
{
		fflush(stdin);
	
	printf("\t\t\t\t\t\t\t\t\t\t ----------------------\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n"); 
	printf("\t\t\t\t\t\t\t\t\t\t|   1. 损坏座位列表    |\n");	
	printf("\t\t\t\t\t\t\t\t\t\t|   2. 已修复座位添加  |\n");	
	printf("\t\t\t\t\t\t\t\t\t\t|   3. 退出            |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t ----------------------\n")	;
			printf("\t\t\t\t\t\t\t\t\t\t ")	;
while(1)
{
	char operation;
	operation=getch();
	switch(operation)
	{
		case '1':  system("cls");seat_brokenlist()   ; return;  
		case '2':  system("cls");seat_brokendel()    ; return;  
		case '3':  system("cls");admin_UI()  ; return;                          
		default: printf("\n\t\t\t\t\t\t\t\t\t\t输入错误，请重新输入:\n")	  ;  break;
	}
	 
}
	
	return ;
} 
void seat_brokenlist()
{
		fflush(stdin);

	struct seat * t=seatlist->next;
	int i,j;
	int p=0;
	while(t!=NULL)
	{
		for(i=0;i<t->n;i++)
		{
			for(j=0;j<t->m;j++)
			{
				if(t->seat[i][j]==3)
				{
					printf("\n\t\t\t\t\t\t\t\t\t\t%d号放映室\t\t%d行%d列\n",t->ID,i,j);
					p=1;
				}
				
			}
		}
		
		t=t->next;
	}
	if(p==0)
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t无损坏\n")	  ;
	}
	printf("\n\t\t\t\t\t\t\t\t\t\t按任意键返回")	  ;
	getch();
	system("cls");
	seat_admin();
	return;

}
void seat_brokendel()
{
		fflush(stdin);

	struct seat * t=seatlist->next;
	int a,i,j,n,m;
	int p=0;
	while(t!=NULL)
	{
		for(i=0;i<t->n;i++)
		{
			for(j=0;j<t->m;j++)
			{
				if(t->seat[i][j]==3)
				{
					printf("\n\t\t\t\t\t\t\t\t\t\t%d号放映室\t\t%d行%d列\n",t->ID,i,j);
					p=1;
				}
				
			}
		}
		
		t=t->next;
	}
	if(p==0)
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t无损坏,按任意键返回\n")  ; 
			getch();
	system("cls");
	seat_admin();
	return;
	}
	char ss[1000];
	printf("\n\t\t\t\t\t\t\t\t\t\t请输入放映厅：") ; 
	scanf("%s",ss);
	for(i=0;i<strlen(ss);i++)
	{
		if(ss[i]<'0'||ss[i]>'9')
		{
			printf("\n\t\t\t\t\t\t\t\t\t\t输入错误，按任意键返回");
	getch();
	system("cls");
	seat_admin();
	return;
		}
	}
	double pp=strtod(ss,NULL);
	a=(int)pp;
	
	
	printf("\n\t\t\t\t\t\t\t\t\t\t请输入行号：") ; 
	scanf("%s",ss);
	for(i=0;i<strlen(ss);i++)
	{
		if(ss[i]<'0'||ss[i]>'9')
		{
			printf("\n\t\t\t\t\t\t\t\t\t\t输入错误，按任意键返回");
	getch();
	system("cls");
	seat_admin();
	return;
		}
	}
pp=strtod(ss,NULL);
	n=(int)pp;
	printf("\n\t\t\t\t\t\t\t\t\t\t请输入列号：") ; 
		scanf("%s",ss);
	for(i=0;i<strlen(ss);i++)
	{
		if(ss[i]<'0'||ss[i]>'9')
		{
			printf("\n\t\t\t\t\t\t\t\t\t\t输入错误，按任意键返回");
	getch();
	system("cls");
	seat_admin();
	return;
		}
	}
pp=strtod(ss,NULL);
	m=(int)pp;
	t=seat_find(a);
	if(t->seat[n][m]==3)
	{
		t->seat[n][m]=1;
		seat_printf();
			printf("\n\t\t\t\t\t\t\t\t\t\t已修改，按任意键返回")	  ;
	getch();
	system("cls");
	seat_admin();
	return;
		
	}
	else
	{
		system("cls");
		printf("\n\t\t\t\t\t\t\t\t\t\t输入错误,请重新输入\n\n");
		seat_brokendel();
		return ; 
		
	}
	
	
	
	
	
	
 } 
