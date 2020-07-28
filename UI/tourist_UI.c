
void tourist_UI()
{
	fflush(stdin);
	printf("\t\t\t\t\t\t\t\t\t\t ----------------------\n");
	printf("\t\t\t\t\t\t\t\t\t\t|       游客系统       |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n"); 
	printf("\t\t\t\t\t\t\t\t\t\t|     1. 影片列表      |\n");	
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|     2. 影片查询      |\n");	
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|     3.  退出         |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t ----------------------\n")	;
	printf("\t\t\t\t\t\t\t\t\t\t ")	;
	char operation;
	while(1)
	{
	operation=getch();
	switch(operation)
	{
		case '1':  system("cls")  ;movie_list_UI(0) ; return;  
		case '2':  system("cls")  ;movie_find_UI(0)    ;  return;  
		case '3':  system("cls")  ;home(0);                       return;
		default:   printf("\n\t\t\t\t\t\t\t\t\t\t 输入错误，请重新输入")	; break;
	}
	}

	system("cls");
	home(0); 
}


