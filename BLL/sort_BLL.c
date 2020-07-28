
void sort1(struct movie_list * t,int p)
{
	struct movie_list * i,*j;
	if(p==1)
	{
	for(i=t;i!=NULL;i=i->next)
		{
			for(j=i->next;j!=NULL;j=j->next)
			{
				if(i->money<j->money)
				{
					swap(i->movie_chinese_name,j->movie_chinese_name);
					swap(i->movie_english_name,j->movie_english_name);
					swap(i->movie_performer,j->movie_performer);
					swap(i->movie_producer,j->movie_producer);
					swap(i->movie_company,j->movie_company);
					swap(i->movie_location,j->movie_location);
					swap(i->movie_director,j->movie_director);
					swap(i->movie_screenwriter,j->movie_screenwriter);
					swap(i->movie_brief,j->movie_brief);
					double x=i->money;
                           i->money=j->money;
                           j->money=x;
					swap(i->movie_time,j->movie_time);
				}
				
			}
		}
	}
	else
	{
		for(i=t;i!=NULL;i=i->next)
		{
			for(j=i->next;j!=NULL;j=j->next)
			{
				if(i->money>j->money)
				{
					swap(i->movie_chinese_name,j->movie_chinese_name);
					swap(i->movie_english_name,j->movie_english_name);
					swap(i->movie_performer,j->movie_performer);
					swap(i->movie_producer,j->movie_producer);
					swap(i->movie_company,j->movie_company);
					swap(i->movie_location,j->movie_location);
					swap(i->movie_director,j->movie_director);
					swap(i->movie_screenwriter,j->movie_screenwriter);
					swap(i->movie_brief,j->movie_brief);
					double x=i->money;
                           i->money=j->money;
                           j->money=x;
					swap(i->movie_time,j->movie_time);
				}
				
			}
		}
	}
	return;
}
void swap(char *a,char *b)
{
	char s[1000];
	strcpy(s,a);
	strcpy(a,b);
	strcpy(b,s);
	
	return;
}
