

#ifndef _HighScores_h_
#define _HighScores_h_


#include <vector>
#include <stdio.h>
class HighScores  
{
public:
	HighScores();
	virtual ~HighScores();
	

	std::vector<char*>Names;
	std::vector<int>Scores;

	bool AddNewScore(char * new_name,int score);
	bool SaveToFile();
	bool LoadFromFile();

};

#endif 
