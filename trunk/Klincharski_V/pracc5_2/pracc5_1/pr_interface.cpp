#include "pr_interface.h"

void pr_interface::menu()
{
	cout << "Вы находитесь в меню программы!!" << endl << endl;
	cout << "1.Базы данных" << endl;
	cout << "2.Информация о преподавателе." << endl;
	cout << "3.Присоединить преподавателя к группе."  << endl;
	cout << "4.Выход." << endl;

	int choise = 0;

	cout << "Введите номер 1-4" << endl;
	cin >> choise;

	switch(choise)
	{
	case 1 : 
		{
			system("cls");
			base_menu();
			retoMenu();
			break;
		}
	case 2 :
		{
			teacher tch;

			system("cls");
			tch.getTeacherName(cin);
			tch.AddTch(fin_tch);
			retoMenu();
			break;
		}
	case 3 :
		{
			teacher tch;
			group gr;

			system("cls");
			ld.printPay();
			
			cout << endl << endl;
			cout << "Введите данные преподавателя (имя / фамилия / отчество / номер телефона / стаж) " << endl;
			tch.getTeacherInfo(cin);
			cout << "Введите данные группы: " << endl;
			gr.getInfo(cin);
			ld.AddLd(tch, gr, fin);
			tch.AddTch(fin_tch);
			pr_interface(fin, fin_tch);
			retoMenu();
			break;
		}
	case 4 :
		{
			exit(100);
		}
	}
}

void pr_interface::base_menu()
{
	cout << "Меню баз данных" << endl << endl;

	cout <<"1.Вывести базу преподавателей и групп." << endl;
	cout <<"2.Вывести оплату преподавателей." << endl;
	cout <<"3.Вернуться в главное меню." << endl;

	int choise = 0;

	cout << "Введите номер 1-3" << endl;
	cin >> choise;

	switch(choise)
	{
	case 1:
		{
			system("cls");
			ld.printLoad();
			break;
		}
	case 2:
		{
			system("cls");
			ld.printPay();
			break;
		}
	case 3: 
		{
			system("cls");
			menu();
			break;
		}
	}
}

void pr_interface::retoMenu()
{
	cout << endl;
	cout << "Для возврата в меню введите: b" << endl;
	cout << "Для выхода введите: q" << endl;
	string ans;
	cin >> ans;
	if (ans == "b")
	{
		system("cls");
		menu();
	}
		
	else exit(13);
}