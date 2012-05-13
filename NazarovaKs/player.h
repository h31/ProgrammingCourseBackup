#ifndef _player_h_
#define _player_h_

#include <iostream>
#include <time.h>

using namespace std;
// ���������, ��� ���� � ������� - ��� ����� ������� � �������, ����� �����:
const unsigned short maxColumns=7; // - ������������ ���������� �������� � �������;
const unsigned short maxCells=343; // - ������ ����� ����� � ������� (����� ������ �� "������").
// ������ ����� ��� ��������� - "�����" (��. ���� "Player").
// � ���� ���������, ����� "�����" - ������� �����, �� ��� ���� ��� ��� � �����.
// � ������, ��� ������ �������� �������, � ���������� - �����������, � ������
// ��� ������������ �������� �������� � ������� �� (� ������ ������, ������� ��� ����� ������ �����).
class Player {
// � ������ "�����" �� �����:
private:
	// - ��������� ���-�� �����;
	unsigned short rows;
	// - ��������� - "������" (� ���� ��� ���� ������ �������) - ����� � ���� �������� �������������� �����������. 
	// � ���������, ��� ���������� ���������������� ������ (��� ����� �������� ��������� �������� �� �������� � �������).
	struct Cell {
		// � "������" � ��� ���������:
		// - ���������: ����������/��������� (��� ����� �����);
		Cell *prev, *next;
		// - ������ ������ � ����� ������.
		unsigned short data[maxColumns];

		Cell(); // ����������� "��-���������" - ��� ���������� ������������ ������
		Cell( unsigned short ); //����������� � ���������� - ��� ���������� ������
		~Cell() {} // ���������� - �� ������, �� �� ���������� ������������ ������
		friend ostream& operator << (ostream& out, const Cell& cell){
			for(unsigned short i=0; i<maxColumns; i++)
				out<<cell.data[i]<<" ";
			out<<endl;
			return out;
		}
	};
public:
	Cell* firstCell; // ��������� �� ������ ������ (������) � ����� �������
	Player(); // ����������� "��-���������" - ������������ 0 ����� 
	Player(unsigned short amtRows);
	~Player() {};
	//Cell* makeCell();
	//Cell* makeList();

	friend ostream& operator << (ostream& out, const Player& );
	//void output (Cell* start);
};

void createField();

#endif