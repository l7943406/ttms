
void tourist_UI()
{
	fflush(stdin);
	printf("\t\t\t\t\t\t\t\t\t\t ----------------------\n");
	printf("\t\t\t\t\t\t\t\t\t\t|       �ο�ϵͳ       |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n"); 
	printf("\t\t\t\t\t\t\t\t\t\t|     1. ӰƬ�б�      |\n");	
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|     2. ӰƬ��ѯ      |\n");	
	printf("\t\t\t\t\t\t\t\t\t\t|                      |\n");
	printf("\t\t\t\t\t\t\t\t\t\t|     3.  �˳�         |\n");
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
		default:   printf("\n\t\t\t\t\t\t\t\t\t\t �����������������")	; break;
	}
	}

	system("cls");
	home(0); 
}


