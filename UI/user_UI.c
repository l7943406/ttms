void user_UI()
{
	fflush(stdin);
	printf("\t\t\t\t\t\t\t\t\t\t ----------------------\n");
	printf("\t\t\t\t\t\t\t\t\t\t|       �û�ϵͳ       |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n"); 
	printf("\t\t\t\t\t\t\t\t\t\t|      1. ӰƬ�б�     |\n");	
	printf("\t\t\t\t\t\t\t\t\t\t|      2. ӰƬ��ѯ     |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|      3. ��λԤ��     |\n");	
	printf("\t\t\t\t\t\t\t\t\t\t|      4. �����޸�     |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|      5.   �˳�       |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t ----------------------\n")	;
	printf("\t\t\t\t\t\t\t\t\t\t ");
	char  operation; 
	while(1)
	{
 	operation=getch();
	switch(operation)
	{
		case '1':  system("cls")  ;movie_list_UI(1) ; return;  
		case '2':  system("cls")  ;movie_find_UI(1) ; return;  
		case '3':  system("cls")  ;seat_buy()          ;return;
		case '4':  system("cls")  ;password_UI(1);     return;
		case '5':  system("cls")  ;home(0);     return;		
		default:   printf("\t\t\t\t\t\t\t\t\t\t ����������������룺")	; break;
	}
	}


return ;
}
void password_UI(int ste)
{
	fflush(stdin);
	char old[100],new[100],new1[100]; 
	printf("\n\t\t\t\t\t\t\t\t\t\t ������ԭ���룺");
	int k;
	for(k=0;k<100;k++)
	{
		old[k]=getch();
		printf("*");
		if(old[k]==8&&k>0)
		{
			printf("\b\b  \b\b");
			k-=2;
		}
		if(old[k]==8&&k==0)
		{
			printf("\b \b");
			k--;
			continue;
		}
		if(old[k]==13)
		{
			printf("\b\b  \b\b*");
			old[k]=0;
			break;
		}
	}
		struct user_list * q=query(nowuser.username);
	if(strcmp(old,q->user_password)!=0) 
	{
	printf("\n\t\t\t\t\t\t\t\t\t\t��������󣬰������������һҳ");
			getch();
		system("cls");
		if(ste==1)
		user_UI();
		else if(ste==2)
		staff_UI();
		else if(ste==3)
		manager_UI();
		return ;
	}
	printf("\n\t\t\t\t\t\t\t\t\t\t ������������(����7-19λ)��");
	for(k=0;k<100;k++)
	{
		new[k]=getch();
		printf("*");
		if(new[k]==8&&k>0)
		{
			printf("\b\b  \b\b");
			k-=2;
		}
		if(new[k]==8&&k==0)
		{
			printf("\b \b");
			k--;
			continue;
		}
		if(new[k]==13)
		{
			printf("\b\b  \b\b*");
			new[k]=0;
			break;
		}
	}
	printf("\n\t\t\t\t\t\t\t\t\t\t ���ٴ����������룺");
		for(k=0;k<100;k++)
	{
		new1[k]=getch();
		printf("*");
		if(new1[k]==8&&k>0)
		{
			printf("\b\b  \b\b");
			k-=2;
		}
		if(new1[k]==8&&k==0)
		{
			printf("\b \b");
			k--;
			continue;
		}
		if(new1[k]==13)
		{
			printf("\b\b  \b\b*");
			new1[k]=0;
			break;
		}
	}

	if(strcmp(new1,new)==0&&!(strlen(new)>19||strlen(new)<7))
	{
		strcpy(q->user_password,new);
		user_printf();
		printf("\n\t\t\t\t\t\t\t\t\t\t �����޸ĳɹ��������������");
		getch();
		system("cls");
		if(ste==1)
		user_UI();
		else if(ste==2)
		staff_UI();
		else if(ste==3)
		manager_UI();
		return ;
	}
	else
	{
		printf("\n\t\t\t\t\t\t\t\t\t�������벻һ�»򳤶Ȳ�����Ҫ���������޸�\n");
		password_UI(ste); 
	}
	
	
	
	
	
	
	
	return; 
}

void seat_buy()  
{
	fflush(stdin);
	struct seat *t=seatlist->next;
	printf("\n\t\t\t\t\t\t\t\t\t\t���ڷ�ӳ\n")	  ;
	while(t!=NULL)
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t%d\t\t%s\n",t->ID,t->movie_name)	  ;
		t=t->next;
	}
	printf("\n\t\t\t\t\t\t\t\t\t\t������Ҫ���ĵ�Ӱ��ţ�");
 	int a=0; 
	char operation;
while(1)
{
	
	operation=getch();
	switch(operation)
	{
		case '1':   a=1;break;
		case '2':  a=2;break;
		case '3':       a=3;break;  
		case '4': a=4;break;   
		default: printf("\n\t\t\t\t\t\t\t\t\t\t�����������������:\n")	  ;  break;
	}
	
	 if(a!=0) break;
}
t=seat_find(a);
system("cls");
seat_print(t);
printf("\n");
printf("\n\t\t\t\t\t\t\t\t\t\t������N:")	  ;
int i,n,m;
char ss[1000];
double pp;
scanf("%s",ss);
for(i=0;i<strlen(ss);i++)
{
	if(ss[i]<'0'||ss[i]>'9')
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t������󣬰����������");
			getch();
			system("cls");
			staff_UI();
		return; 
	}
}
pp=strtod(ss,NULL);
n=(int)pp;

printf("\n\t\t\t\t\t\t\t\t\t\t������M:")	  ;
scanf("%s",ss);
for(i=0;i<strlen(ss);i++)
{
	if(ss[i]<'0'||ss[i]>'9')
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t������󣬰����������");
			getch();
			system("cls");
			staff_UI();
		return; 
	}
}
pp=strtod(ss,NULL);
m=(int)pp;

if(n<t->n&&n<t->m&&n>=0&&m>=0&&t->seat[n][m]==1)
{
	t->seat[n][m]=2;
	seat_printf();
	///////////////////////
	data_add(nowuser.username,t->movie_name,1);
	printf("\n\t\t\t\t\t\t\t\t\t\t��Ʊ�ɹ���ף����Ӱ��죬�����������");
	getch();
	system("cls");
	user_UI();
}
else
{
	printf("\n\t\t\t\t\t\t\t\t\t\t����λ�޷����ۣ������������");
	getch();
	system("cls");
	user_UI();
}
	
	
	
	
	
	
	
	
	
	return ;
}
