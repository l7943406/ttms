void admin_UI()
{
	fflush(stdin);
	printf("\t\t\t\t\t\t\t\t\t\t ----------------------\n");
	printf("\t\t\t\t\t\t\t\t\t\t|    �� �� Ա ϵ ͳ    |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n"); 
	printf("\t\t\t\t\t\t\t\t\t\t|     1. �û��б�      |\n");	
	printf("\t\t\t\t\t\t\t\t\t\t|     2. ����û�      |\n");	
	printf("\t\t\t\t\t\t\t\t\t\t|     3. ע���û�      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|     4. �û�Ȩ��      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|     5. ��λ����      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|     6. �˳�          |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t ----------------------\n")	;
	char operation;
	printf("\t\t\t\t\t\t\t\t\t\t ��ѡ��Ҫ���еĲ���:");
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
		default:  printf("\n\t\t\t\t\t\t\t\t\t\t �����������������")         ; admin_UI();  break;
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
		printf("\t\t\t\t\t\t\t\t\t\t �û���:%s\t�û�Ȩ��:%d\n",t->user_name,t->jurisdiction);
		t=t->next;
	}
	printf("\n");
	printf("\t\t\t\t\t\t\t\t\t\t �������������һ��");
	getch();
	system("cls");
	admin_UI();
	return;
}
void user_add_UI()
{
		fflush(stdin);

	char password[1000],user[1000];
	printf("\t\t\t\t\t\t\t\t\t\t �������û���(����7-19������ĸ��ͷ)��");
	scanf("%s",user); 
	printf("\t\t\t\t\t\t\t\t\t\t ����������(����7-19)��");
	scanf("%s",password);
	int step=logonuser_BLL(user,password);
	if(step==1)
	{
		system("cls");	
		printf("\n\t\t\t\t\t\t\t\t\t\t �û��������볤�Ȳ�����Ҫ������������\n");
		user_add_UI();
		return ;
	}
	else if(step==2)
	{
		system("cls");	
		printf("\n\t\t\t\t\t\t\t\t\t\t �û����Ѵ��ڣ�����������\n");
		user_add_UI();
		return ;
	}
	printf("\n\t\t\t\t\t\t\t\t\t\t ��ѡ����û�Ȩ�ޣ�1.����Ա  2.����  3.Ա�� 4.�û�\n\t\t\t\t\t\t\t\t\t\t");
	int ch;
	while(1)
	{
		ch=getch();
		if(ch>'4'||ch<'1')
		{
			printf("\n\t\t\t\t\t\t\t\t\t\t �����������������:\n");
			continue;
		} 
		else
		{
			user_add(user,password,ch-'0');
			break;
		}

		 
	}
	
	
	printf("\n\t\t\t\t\t\t\t\t\t\t �����û��ɹ��������������һҳ");
	getch();
	system("cls");
 	admin_UI();
	return ;
	
	
}
void  user_delete_UI()  
{
		fflush(stdin);
	
	printf("\n\t\t\t\t\t\t\t\t\t\t ɾ���û��������ɻָ�!!!\n");
	printf("\n\t\t\t\t\t\t\t\t\t\t ������Ҫɾ�����û���:");
	char user[1000];
	scanf("%s",user);
	int ch=user_delete_BLL(user);
 	if(ch==1)
	 {
	 	printf("\n\t\t\t\t\t\t\t\t\t\tע���ɹ�,�������������һ��");
	  } 
	else
	{
	 	printf("\n\t\t\t\t\t\t\t\t\t\t�û�������,�������������һ��"); 
	}
	getch();
	 	system("cls");
		 admin_UI();
		 return; 
}
 
void user_access_UI()
{
		fflush(stdin);
	
	printf("\n\t\t\t\t\t\t\t\t\t\t������Ҫ�޸�Ȩ�޵��û���:"); 
	char user[1000];
	scanf("%s",user);
	struct user_list * tep=query(user);
	if(tep==NULL) 
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t�û���������,�����������"); 
		getch();
	 	system("cls");
		 admin_UI();
		 return; 
	}
	printf("\n\t\t\t\t\t\t\t\t\t\t�û���:%s  Ȩ�޵ȼ� %d\n",tep->user_name,tep->jurisdiction); 
	printf("\n\t\t\t\t\t\t\t\t\t\t�޸�Ȩ��Ϊ:"); 
	char ch;
		while(1)
	{
		ch=getch();
		if(ch>'4'||ch<'1')
		{
			printf("\n\t\t\t\t\t\t\t\t\t\t �����������������:\n");
			continue;
		} 
		else
		{
			tep-> jurisdiction=ch-'0';
			user_printf();
			break;
		}

		 
	}
	
	
	
	printf("\n\t\t\t\t\t\t\t\t\t\t �޸�Ȩ�޳ɹ������������һҳ\n");
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
	printf("\t\t\t\t\t\t\t\t\t\t|   1. ����λ�б�    |\n");	
	printf("\t\t\t\t\t\t\t\t\t\t|   2. ���޸���λ���  |\n");	
	printf("\t\t\t\t\t\t\t\t\t\t|   3. �˳�            |\n");
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
		default: printf("\n\t\t\t\t\t\t\t\t\t\t�����������������:\n")	  ;  break;
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
					printf("\n\t\t\t\t\t\t\t\t\t\t%d�ŷ�ӳ��\t\t%d��%d��\n",t->ID,i,j);
					p=1;
				}
				
			}
		}
		
		t=t->next;
	}
	if(p==0)
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t����\n")	  ;
	}
	printf("\n\t\t\t\t\t\t\t\t\t\t�����������")	  ;
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
					printf("\n\t\t\t\t\t\t\t\t\t\t%d�ŷ�ӳ��\t\t%d��%d��\n",t->ID,i,j);
					p=1;
				}
				
			}
		}
		
		t=t->next;
	}
	if(p==0)
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t����,�����������\n")  ; 
			getch();
	system("cls");
	seat_admin();
	return;
	}
	char ss[1000];
	printf("\n\t\t\t\t\t\t\t\t\t\t�������ӳ����") ; 
	scanf("%s",ss);
	for(i=0;i<strlen(ss);i++)
	{
		if(ss[i]<'0'||ss[i]>'9')
		{
			printf("\n\t\t\t\t\t\t\t\t\t\t������󣬰����������");
	getch();
	system("cls");
	seat_admin();
	return;
		}
	}
	double pp=strtod(ss,NULL);
	a=(int)pp;
	
	
	printf("\n\t\t\t\t\t\t\t\t\t\t�������кţ�") ; 
	scanf("%s",ss);
	for(i=0;i<strlen(ss);i++)
	{
		if(ss[i]<'0'||ss[i]>'9')
		{
			printf("\n\t\t\t\t\t\t\t\t\t\t������󣬰����������");
	getch();
	system("cls");
	seat_admin();
	return;
		}
	}
pp=strtod(ss,NULL);
	n=(int)pp;
	printf("\n\t\t\t\t\t\t\t\t\t\t�������кţ�") ; 
		scanf("%s",ss);
	for(i=0;i<strlen(ss);i++)
	{
		if(ss[i]<'0'||ss[i]>'9')
		{
			printf("\n\t\t\t\t\t\t\t\t\t\t������󣬰����������");
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
			printf("\n\t\t\t\t\t\t\t\t\t\t���޸ģ������������")	  ;
	getch();
	system("cls");
	seat_admin();
	return;
		
	}
	else
	{
		system("cls");
		printf("\n\t\t\t\t\t\t\t\t\t\t�������,����������\n\n");
		seat_brokendel();
		return ; 
		
	}
	
	
	
	
	
	
 } 
