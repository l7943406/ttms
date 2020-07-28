void seat_reset(struct seat * t)
{
	int n=t->n;
	int m=t->m;
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(t->seat[i][j]==2)
			{
				t->seat[i][j]==1;
			}
		}
	}
	return;
}
struct seat * seat_find(int id)
{
	struct seat * t=seatlist->next;
	while(t!=NULL)
	{
		if(t->ID==id)
		{
			return t;
		}
		
		t=t->next;
	}
	
	
	return NULL;
	
	
	
}

