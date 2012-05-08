
#ifndef _HighScores_h_
#define _HighScores_h_

#include <vector>
class HighScores  
{
public:
	HighScores();
	virtual ~HighScores();
	
	std::vector<char*>Names;
	std::vector<int>Scores;

	bool addNewScore(char * new_name,int score);
	bool saveToFile();
	bool loadFromFile();

};

#endif 
