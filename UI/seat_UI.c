void seat_print(struct seat *t)
{
	fflush(stdin);
	system("cls");	
	int n=t->n;
	int m=t->m;
	int i,j,k;
	printf("\n");
	for(i=0;i<189;i++)
	printf("=");
	struct movie_list * p=moviequery(t->movie_name);
	printf("\t\t\t\t\t\t\t\tVIP%dºÅÌü",t->ID);
	if(p!=NULL)
    printf("\t\tÓ°Æ¬Ãû£º%s\t\tÆ¬³¤£º%s",t->movie_name,p->movie_time);
	printf("\n");
	printf("\t\t\t\t\t\tN\\M     ");
	for(i=0;i<m;i++)
	{
		printf("%d\t",i);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(j==0) printf("\t\t\t\t\t\t%d\t",i);
			else 
			{
				if(t->seat[i][j-1]!=1)
				printf("X\t");
				else
				printf("O\t");
			}
		}
		printf("\n");
	}
	for(i=0;i<189;i++)
	printf("=");
	printf("\n");

	return;
}
