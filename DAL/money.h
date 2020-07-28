struct money
{
	char movie[100];
	double money;
	struct money * next;
	struct money * last;
};
void money_printf();
void money_scanf(); 
struct money * moneylist;
