#include "HighScores.h"



HighScores::HighScores()
{
	
}

HighScores::~HighScores()
{

}

bool HighScores::AddNewScore(char *new_name,int score)
{
	Names.push_back(new_name);
	Scores.push_back(score);
	return true;
}

bool HighScores::SaveToFile()
{
    FILE * ScoresFile=fopen("ScoresList.txt","a+");
	if(ScoresFile)
	{
		for(unsigned int i=0;i<Scores.size();i++)
		{
			fprintf(ScoresFile,"%s\t%d",Names[i],Scores[i]);
		}
		return true;
	}
	return false;

}
