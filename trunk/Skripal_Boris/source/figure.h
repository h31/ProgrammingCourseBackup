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
	//����������� ���� �����
	bool canPawnTurn(Figure ** desk,const int startX,const int startY,const int finishX,const int finishY, const bool whitePlayer);
	//����������� ���� ������
	bool canKingTurn(Figure ** desk,const int startX,const int startY,const int finishX,const int finishY);
	//����������� ���� �����
	bool canRookTurn(Figure ** desk,const int startX,const int startY,const int finishX,const int finishY);
	//����������� ���� �����
	bool canQueenTurn(Figure ** desk,const int startX,const int startY,const int finishX,const int finishY);
	//����������� ���� ����
	bool canHourseTurn(Figure ** desk,const int startX,const int startY,const int finishX,const int finishY);
	//����������� ���� �����
	bool canElephantTurn(Figure ** desk,const int startX,const int startY,const int finishX,const int finishY);
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
	//�������� ������������
	Figure& operator = (const Figure& figure);

	friend class Desk;
};

#endif