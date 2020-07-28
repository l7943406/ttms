int login_BLL(char *user,char *password)
{
	user_scanf();
	struct user_list *t;
	t=userlist->next;
	while(t!=NULL)
	{
		
		if(strcmp(t->user_name,user)==0)
		{
			if(strcmp(t->user_password,password)==0)
			{
				strcpy(nowuser.username,user) ;
				return t->jurisdiction;
			}
			else
			{
				return 99;
			}
		}
		t=t->next;
	}
	
	return 99;
}
int logonuser_BLL(char *user,char *pass)   //注册：用户名密码查重，查符合要求 返回1长度问题，返回2用户名已存在
{
	int i;
	for(i=0;i<strlen(user);i++)
	{
		if((user[i]>='0'&&user[i]<='9')||(user[i]>='a'&&user[i]<='z')||(user[i]>='A'&&user[i]<='Z'))
		{
			continue;
		}
		else
		{
			return 100;
		}
	}
	if(strlen(user)>19||strlen(user)<7||strlen(pass)>19||strlen(pass)<7)
	{
        return 1;		
	}
    if(!((user[0]<='z'&&user[0]>='a')||(user[0]<='Z'&&user[0]>='A'))) 
    {
    	return 1;
	}
	struct user_list *  now = query(user);
	if(now!=NULL)
	{
		return 2;
	}
	return 0;
} 
void user_add(char *username,char *password,int jur)
{
	struct user_list * t=(struct user_list *)malloc(sizeof(struct user_list));
	strcpy(t->user_name,username);
	strcpy(t->user_password,password);
	t->jurisdiction=jur;
	t->next=userlist->next;
	userlist->next=t;
	user_printf();
	return ;
}
struct user_list * query(char * username)
{
	struct user_list * t;
	t=userlist->next;
	while(t!=NULL)
	{
		if(strcmp(username,t->user_name)==0)
		{
			return t;
		}
		t=t->next;
	}
	return NULL;
}
int user_delete_BLL(char *username)
{
	struct user_list * t,*p;
	t=userlist;
	while(t->next!=NULL)
	{
		if(strcmp(username,t->next->user_name)==0)
		{
			break;
		}
		t=t->next;
	}
	if(t->next==NULL) return 0;
	p=t->next;
	t->next=t->next->next;
	free(p);
	user_printf();
	return 1;
}
