#include "AllGameMatrix.h"

bool AllGameMatrix::isright()
{
	if(matr.size() == 0)
		return true;
	bool flag = true;
	int nstb;
	nstb = matr[0].size();
	for(int ix = 1; ix < matr.size(); ix++)
	{
		if(matr[ix].size() != nstb)
			flag = false;
	}
	return flag;
}

bool AllGameMatrix::issquare()
{
	if(isright())
		return matr[0].size() == matr.size();
	else
		return false;
}

void AllGameMatrix::add(int val, int nstr)
{
	if(nstr < 0)
		return;
	for(int ix = matr.size(); ix < nstr; ix++)
	{
		vector<int> tvect;
		matr.push_back(tvect);
	}
	matr[nstr - 1].push_back(val);
}

const vector<int> &AllGameMatrix::operator[](int ix)
{
	return matr[ix];
}

int AllGameMatrix::numstr()
{
	return matr.size();
}

void AllGameMatrix::clear()
{
	matr.erase(matr.begin(), matr.end());
}

void AllGameMatrix::print_str(int nstr, ostream &out)
{
	if(nstr > matr.size() || nstr < 1)
		return;
	for(int ix = 0; ix < matr[nstr - 1].size(); ix++)
	{
		out << matr[nstr - 1][ix] << ' ';
	}
}