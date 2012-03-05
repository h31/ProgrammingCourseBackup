#ifndef _figure_h_
#define _figure_h_

enum Type
{
	emptyCell,//������ ������
	elephant,//����
	horse,//����
	king,//������
	pawn,//�����
	queen,//�����
	rook//�����
};

enum CellType
{
	blackCell,//������ ������
	whiteCell//����� ������
};

class Figure
{
public:
	//���� ������
	bool whiteFigure;
	//���� ������
	CellType cellType;
	//��� ������
	Type type;
	//���������� �����, ��������� �������
	int steps;
	//�����������
	Figure();
};

#endif