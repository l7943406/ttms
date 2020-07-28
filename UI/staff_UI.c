void staff_UI()
{
	fflush(stdin);
	printf("\t\t\t\t\t\t\t\t\t\t ----------------------\n");
	printf("\t\t\t\t\t\t\t\t\t\t|       员工系统       |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n"); 
	printf("\t\t\t\t\t\t\t\t\t\t|      1. 影票出售     |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|      2. 顾客退票     |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");	
	printf("\t\t\t\t\t\t\t\t\t\t|      3. 坏座添加     |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");	
	printf("\t\t\t\t\t\t\t\t\t\t|      4. 今日业绩     |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|      5. 密码修改     |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|      6.   退出       |\n");
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
		printf("\n\t\t\t\t\t\t\t\t\t\t%s今日业绩为：%lf",nowuser.username,yj(nowuser.username,1));
		printf("\n\t\t\t\t\t\t\t\t\t\t按任意键返回");
		getch();
		system("cls");
		staff_UI();
		 
		
		
		
		return;                          
		case '5': system("cls");password_UI(3)       ; return ;
		case '6':system("cls"); home(0) ; return ;
		default: printf("\n\t\t\t\t\t\t\t\t\t\t输入错误，请重新输入:\n")	  ;  break;
	}
	 
}
return ;
}
void movie_sale()
{
	fflush(stdin);
	struct seat *t=seatlist->next;
	printf("\n\t\t\t\t\t\t\t\t\t\t放映列表\n")	  ;
	while(t!=NULL)
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t%d号厅\t\t正在放映：%s\n",t->ID,t->movie_name)	  ;
		t=t->next;
	}
	printf("\n\t\t\t\t\t\t\t\t\t\t请输入影厅序号：") ;
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
		default: printf("\n\t\t\t\t\t\t\t\t\t\t输入错误，请重新输入:\n")	  ;  break;
	}
	
	 if(a!=0) break;
}
t=seat_find(a);
system("cls");
seat_print(t);
printf("\n");
printf("\n\t\t\t\t\t\t\t\t\t\t请输入N:")	  ;
int i,n,m;
char ss[1000];
double pp;
scanf("%s",ss);
for(i=0;i<strlen(ss);i++)
{
	if(ss[i]<'0'||ss[i]>'9')
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t输入错误，按任意键返回");
			getch();
			system("cls");
			staff_UI();
		return; 
	}
}
pp=strtod(ss,NULL);
n=(int)pp;

printf("\n\t\t\t\t\t\t\t\t\t\t请输入M:")	  ;
scanf("%s",ss);
for(i=0;i<strlen(ss);i++)
{
	if(ss[i]<'0'||ss[i]>'9')
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t输入错误，按任意键返回");
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
	
	printf("\n\t\t\t\t\t\t\t\t\t\t出售成功，按任意键返回");
	getch();
	system("cls");
	staff_UI();
}
else
{
	printf("\n\t\t\t\t\t\t\t\t\t\t此座位无法出售，按任意键返回");
	getch();
	system("cls");
	staff_UI();
}
	
	return ;
}

void seat_brokenadd()  
{
	fflush(stdin);
	printf("\n\t\t\t\t\t\t\t\t\t\t请输入影厅序号：") ;
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
		default: printf("\n\t\t\t\t\t\t\t\t\t\t输入错误，请重新输入:\n")	  ;  break;
	}
	
	 if(a!=0) break;
}


	struct seat *t=seat_find(a);
	seat_print(t);
	
printf("\n");
printf("\n\t\t\t\t\t\t\t\t\t\t请输入N:")	  ;
int i,n,m;
char ss[1000];
double pp;
scanf("%s",ss);
for(i=0;i<strlen(ss);i++)
{
	if(ss[i]<'0'||ss[i]>'9')
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t输入错误，按任意键返回");
			getch();
			system("cls");
			staff_UI();
		return; 
	}
}
pp=strtod(ss,NULL);
n=(int)pp;

printf("\n\t\t\t\t\t\t\t\t\t\t请输入M:")	  ;
scanf("%s",ss);
for(i=0;i<strlen(ss);i++)
{
	if(ss[i]<'0'||ss[i]>'9')
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t输入错误，按任意键返回");
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
	
	printf("\n\t\t\t\t\t\t\t\t\t\t添加成功，按任意键返回");
	getch();
	system("cls");
	staff_UI();
}
else
{
		printf("\n\t\t\t\t\t\t\t\t\t\t座位输入错误，按任意键返回");
	getch();
	system("cls");
	staff_UI();
}
  }  
  
void movie_return()
{
	fflush(stdin);
	struct seat *t;
	printf("\n\t\t\t\t\t\t\t\t\t\t请输入影厅序号：") ;
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
		default: printf("\n\t\t\t\t\t\t\t\t\t\t输入错误，请重新输入:\n")	  ;  break;
	}
	
	 if(a!=0) break;
}
t=seat_find(a);
system("cls");
printf("\n");
printf("\n\t\t\t\t\t\t\t\t\t\t请输入行号:")	  ;
int i,n,m;
char ss[1000];
double pp;
scanf("%s",ss);
for(i=0;i<strlen(ss);i++)
{
	if(ss[i]<'0'||ss[i]>'9')
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t输入错误，按任意键返回");
			getch();
			system("cls");
			staff_UI();
		return; 
	}
}
pp=strtod(ss,NULL);
n=(int)pp;

printf("\n\t\t\t\t\t\t\t\t\t\t请输入列号:")	  ;
scanf("%s",ss);
for(i=0;i<strlen(ss);i++)
{
	if(ss[i]<'0'||ss[i]>'9')
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t输入错误，按任意键返回");
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
	printf("\n\t\t\t\t\t\t\t\t\t\t退票成功，按任意键返回");
	getch();
	system("cls");
	staff_UI();
}
else
{
	printf("\n\t\t\t\t\t\t\t\t\t\t查无此票，按任意键返回");
	getch();
	system("cls");
	staff_UI();
}
	
	return ;
 }   
