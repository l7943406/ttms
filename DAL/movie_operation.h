
struct movie_list
{
	char movie_chinese_name[100];
	char movie_english_name[100];
	char movie_performer[100];
	char movie_producer[100];
	char movie_company[100];
	char movie_location[100];
	char movie_director[100];
	char movie_screenwriter[100];
	char movie_brief[1000];
	char movie_time[100];
	double money;
	struct movie_list *next;
};
struct movie_list * movielist;
void movie_scanf();
void movie_printf();


