
void movie_scanf()
{
	FILE * fp;
	fp=fopen("./DAL/movie_list.ini","rt+");
		if(fp==NULL)
	{
		printf("\t\t\t\t\t\t\t\t\t\t电影信息文件打开失败！！");
		getch();
		exit(0);
	}
	char moviechinesename[100];
	char movieenglishname[100];
	char movieproducer[100];
	char movieperformer[100];
	char moviecompany[100];
	char movielocation[100];
	char moviedirector[100];
	char moviescreenwriter[100];
	char moviebrief[1000];
	char movietime[100];
	struct movie_list *head,*p,*q;
	head=(struct movie_list *)malloc(sizeof(struct movie_list));
	head->next=NULL;
	while(fgets(moviechinesename,100,fp)!=NULL) 
	{
		moviechinesename[strlen(moviechinesename)-1]=0;
		fgets(movieenglishname,100,fp);
		movieenglishname[strlen(movieenglishname)-1]=0;
		fgets(movieperformer,100,fp);
		movieperformer[strlen(movieperformer)-1]=0;
		fgets(movieproducer,100,fp);
		movieproducer[strlen(movieproducer)-1]=0;
		fgets(moviecompany,100,fp);
		moviecompany[strlen(moviecompany)-1]=0;
		fgets(movielocation,100,fp);
		movielocation[strlen(movielocation)-1]=0;
		fgets(moviedirector,100,fp);
		moviedirector[strlen(moviedirector)-1]=0;
		fgets(moviescreenwriter,100,fp);
		moviescreenwriter[strlen(moviescreenwriter)-1]=0;
		fgets(movietime,100,fp);
		movietime[strlen(movietime)-1]=0;
		fgets(moviebrief,1000,fp);
		moviebrief[strlen(moviebrief)-1]=0;
		
		p=(struct movie_list *)malloc(sizeof(struct movie_list));
		p->next=NULL;
		strcpy(p->movie_chinese_name,moviechinesename);
		strcpy(p->movie_performer,movieperformer);
		strcpy(p->movie_english_name,movieenglishname);
		strcpy(p->movie_producer,movieproducer);
		strcpy(p->movie_company,moviecompany);
		strcpy(p->movie_location,movielocation);
		strcpy(p->movie_director,moviedirector);
		strcpy(p->movie_screenwriter,moviescreenwriter);
		strcpy(p->movie_time,movietime);
		strcpy(p->movie_brief,moviebrief);
		if(head->next==NULL)
		{
			head->next=p;
			q=p;
		}
		else
		{
			q->next=p;
			q=p;
		}	
	}
	fclose(fp);
	movielist=head;
	return;
}
void movie_printf()
{
	FILE *fp;
	fp=fopen("./DAL/movie_list.ini","wt+");
		if(fp==NULL)
	{
		printf("\t\t\t\t\t\t\t\t\t\t电影信息文件打开失败！！");
		getch();
		exit(0);
	}
	struct movie_list * t;
	t=movielist->next;
	while(t!=NULL)
	{
		fprintf(fp,"%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",t->movie_chinese_name,t->movie_english_name,t->movie_performer,t->movie_producer,t->movie_company,t->movie_location,t->movie_director,t->movie_screenwriter,t->movie_time,t->movie_brief);
		t=t->next;
	}
	fclose(fp);
	return ;	
}
