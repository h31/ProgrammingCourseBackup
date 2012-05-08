// HighScores.cpp: implementation of the HighScores class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HighScores.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

HighScores::HighScores()
{
	
}

HighScores::~HighScores()
{

}

bool HighScores::addNewScore(char *new_name,int score)
{
	Names.push_back(new_name);
	Scores.push_back(score);
	return true;
}

bool HighScores::saveToFile()
{
	FILE *scoresFile=fopen("Result.txt","a+");
	if(scoresFile)
	{
		for(unsigned int i=0;i<Scores.size();i++)
		{
			fprintf(scoresFile,"%s\t%d",Names[i],Scores[i]);
		}
		return true;
	}
	return false;
}
