#include "load.h"

class pr_interface
{
private :
	void menu();
	void base_menu();
	void retoMenu();
	teacher tch;
	group gr;
	load ld;
	char *fin, *fin_tch;
public :
	pr_interface(char *_in, char *_in_tch)
	{
		fin = _in; fin_tch = _in_tch;
		ifstream in(_in);ifstream in_tch(_in_tch);


		ld.buildLd(in);
		ld.paycoef = 500;
		ld.buildPay(in_tch);
		
		menu();
	}
};