void staff_UI()
{
	fflush(stdin);
	printf("\t\t\t\t\t\t\t\t\t\t ----------------------\n");
	printf("\t\t\t\t\t\t\t\t\t\t|       Ա��ϵͳ       |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n"); 
	printf("\t\t\t\t\t\t\t\t\t\t|      1. ӰƱ����     |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|      2. �˿���Ʊ     |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");	
	printf("\t\t\t\t\t\t\t\t\t\t|      3. �������     |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");	
	printf("\t\t\t\t\t\t\t\t\t\t|      4. ����ҵ��     |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|      5. �����޸�     |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|      6.   �˳�       |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t ----------------------\n")	;
		printf("\t\t\t\t\t\t\t\t\t\t ")	;
while(1)
{
	char operation;
	operation=getch();
	switch(operation)
	{
		case '1': system("cls"); movie_sale()   ; return; 
		case '2': system("cls"); movie_return()   ; return;   
		case '3':  system("cls");seat_brokenadd()    ; return;  
		case '4':  system("cls");
		printf("\n\t\t\t\t\t\t\t\t\t\t%s����ҵ��Ϊ��%lf",nowuser.username,yj(nowuser.username,1));
		printf("\n\t\t\t\t\t\t\t\t\t\t�����������");
		getch();
		system("cls");
		staff_UI();
		 
		
		
		
		return;                          
		case '5': system("cls");password_UI(3)       ; return ;
		case '6':system("cls"); home(0) ; return ;
		default: printf("\n\t\t\t\t\t\t\t\t\t\t�����������������:\n")	  ;  break;
	}
	 
}
return ;
}
void movie_sale()
{
	fflush(stdin);
	struct seat *t=seatlist->next;
	printf("\n\t\t\t\t\t\t\t\t\t\t��ӳ�б�\n")	  ;
	while(t!=NULL)
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t%d����\t\t���ڷ�ӳ��%s\n",t->ID,t->movie_name)	  ;
		t=t->next;
	}
	printf("\n\t\t\t\t\t\t\t\t\t\t������Ӱ����ţ�") ;
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
	data_add(nowuser.username,t->movie_name,1);
	///////////////////////
	
	printf("\n\t\t\t\t\t\t\t\t\t\t���۳ɹ��������������");
	getch();
	system("cls");
	staff_UI();
}
else
{
	printf("\n\t\t\t\t\t\t\t\t\t\t����λ�޷����ۣ������������");
	getch();
	system("cls");
	staff_UI();
}
	
	return ;
}

void seat_brokenadd()  
{
	fflush(stdin);
	printf("\n\t\t\t\t\t\t\t\t\t\t������Ӱ����ţ�") ;
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


	struct seat *t=seat_find(a);
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
if(n<t->n&&n<t->m&&n>=0&&m>=0)
{
	t->seat[n][m]=3;
	seat_printf();
	///////////////////////
	
	printf("\n\t\t\t\t\t\t\t\t\t\t��ӳɹ��������������");
	getch();
	system("cls");
	staff_UI();
}
else
{
		printf("\n\t\t\t\t\t\t\t\t\t\t��λ������󣬰����������");
	getch();
	system("cls");
	staff_UI();
}
  }  
  
void movie_return()
{
	fflush(stdin);
	struct seat *t;
	printf("\n\t\t\t\t\t\t\t\t\t\t������Ӱ����ţ�") ;
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
printf("\n");
printf("\n\t\t\t\t\t\t\t\t\t\t�������к�:")	  ;
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

printf("\n\t\t\t\t\t\t\t\t\t\t�������к�:")	  ;
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
if(n<t->n&&n<t->m&&n>=0&&m>=0&&t->seat[n][m]==2)
{
	t->seat[n][m]=1;
	seat_printf();
	///////////////////////
	data_add(nowuser.username,t->movie_name,2);
	printf("\n\t\t\t\t\t\t\t\t\t\t��Ʊ�ɹ��������������");
	getch();
	system("cls");
	staff_UI();
}
else
{
	printf("\n\t\t\t\t\t\t\t\t\t\t���޴�Ʊ�������������");
	getch();
	system("cls");
	staff_UI();
}
	
	return ;
 }   
