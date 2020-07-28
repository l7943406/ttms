void seat_printf();
void seat_scanf(); 
struct seat
{
	int ID;
	int seatbroke;
	int n,m;
	int seat[100][100];
	char movie_name[100];
	struct seat *next; 
};
struct seat * seatlist;
