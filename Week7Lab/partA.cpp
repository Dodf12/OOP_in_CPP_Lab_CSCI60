#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{

	//Part A: Problem 1
	ifstream file("scores.txt");
	if(file.fail())
		{
			cout << "Failure opening file" <<  endl;
			exit (1);
		}

	vector<int> scores;
	int score;

	while(file >> score)
		{
			scores.push_back(score);
		}

	int sum = 0;
	for (int i = 0; i < scores.size(); i++)
		{
			sum+=scores[i];
		}

	double average = sum / scores.size();

	//Part A: Problem 2

	ofstream outputFile("output.txt");

	if(outputFile.fail()) 
	{
		cout << "File failed to be created" << endl;
		exit (1);
	}

	outputFile << average << endl;

	for (int i = 0; i < scores.size(); i++)
		{
			if (scores[i] > average)
			{
				outputFile << scores[i] << endl;
				//cout << scores[i] << endl;
			}
		}




}