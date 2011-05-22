#include "pr_interface.h"

void pr_interface::menu()
{
	cout << "�� ���������� � ���� ���������!!" << endl << endl;
	cout << "1.���� ������" << endl;
	cout << "2.���������� � �������������." << endl;
	cout << "3.������������ ������������� � ������."  << endl;
	cout << "4.�����." << endl;

	int choise = 0;

	cout << "������� ����� 1-4" << endl;
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
			cout << "������� ������ ������������� (��� / ������� / �������� / ����� �������� / ����) " << endl;
			tch.getTeacherInfo(cin);
			cout << "������� ������ ������: " << endl;
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
	cout << "���� ��� ������" << endl << endl;

	cout <<"1.������� ���� �������������� � �����." << endl;
	cout <<"2.������� ������ ��������������." << endl;
	cout <<"3.��������� � ������� ����." << endl;

	int choise = 0;

	cout << "������� ����� 1-3" << endl;
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
	cout << "��� �������� � ���� �������: b" << endl;
	cout << "��� ������ �������: q" << endl;
	string ans;
	cin >> ans;
	if (ans == "b")
	{
		system("cls");
		menu();
	}
		
	else exit(13);
}