void movie_add(struct movie_list s)
{
	struct movie_list * t=(struct movie_list *)malloc(sizeof(struct movie_list));
	strcpy(t->movie_chinese_name,s.movie_chinese_name);
	strcpy(t->movie_company,s.movie_company);
	strcpy(t->movie_brief,s.movie_brief);
	strcpy(t->movie_director,s.movie_director);
	strcpy(t->movie_english_name,s.movie_english_name);
	strcpy(t->movie_location,s.movie_location);
	strcpy(t->movie_performer,s.movie_performer);
	strcpy(t->movie_producer,s.movie_producer);
	strcpy(t->movie_screenwriter,s.movie_screenwriter);
	strcpy(t->movie_time,s.movie_time);
	t->next=movielist->next;
	movielist->next=t;
	movie_printf();
	return ;
}
struct movie_list * moviequery(char * moviename)
{
	struct movie_list * t;
	t=movielist->next;
	while(t!=NULL)
	{
		if(strcmp(moviename,t->movie_chinese_name)==0)
		{
			return t;
		}
		t=t->next;
	}
	return NULL;
}
int movie_delete_BLL(char *moviename)
{
	struct movie_list * t,*p;
	t=movielist;
	while(t->next!=NULL)
	{
		if(strcmp(moviename,t->next->movie_chinese_name)==0)
		{
			break;
		}
		t=t->next;
	}
	if(t->next==NULL) return 0;
	p=t->next;
	t->next=t->next->next;
	free(p);
	movie_printf();
	return 1;
}
