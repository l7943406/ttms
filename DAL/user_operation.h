void user_printf();
void user_scanf(); 
struct user_list
{
	char user_name[20];
	char user_password[20];
	int jurisdiction;
	struct user_list *next;
};
struct user_list * userlist;
