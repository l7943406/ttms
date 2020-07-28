struct data
{
	char user[100];
	char movie[100];
	char s[100];
	struct data * next;
};
void data_printf();
void data_scanf(); 
struct data * datalist;
double yj(char *s,int k);
