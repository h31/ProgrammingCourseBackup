#include "pr_interface.h"
#include <locale.h>

int main(int argc, char *argv[])
{
	setlocale(LC_ALL,"Russian");
	if(argc != 3)
	{
		cout << "Не введен файл содержащий базу данных!!!";
		exit(100);
	}

	pr_interface pr_int(argv[1], argv[2]);

	return -100;
}