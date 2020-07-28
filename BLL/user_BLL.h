

struct user_list * query(char * username);
void user_add(char *username,char *password,int jur);
int logonuser_BLL(char *user,char *) ;
int login_BLL(char *user,char *password);
int user_delete_BLL(char *username);
struct now_user
{
	char username[20];
	char ID[20];
};
struct now_user nowuser;
