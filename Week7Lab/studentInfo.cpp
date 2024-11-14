#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

//Part B1
class studentInfo
	{
		private:
			string firstName_;
			string lastName_;
			string classLevel_;
			double GPA_;
		public:
			studentInfo()
				{
					firstName_ = "N/A";
					lastName_ = "N/A";
					classLevel_ = "N/A";
					GPA_ = 0.0;
				}

			studentInfo(string f, string l, string cl, double gpa)
				{
					firstName_ = f;
					lastName_ = l;
					classLevel_ = cl;
					GPA_ = gpa;
				}

			string getFirstName() {return firstName_;}
			string getLastName() {return lastName_;}
			string getClassLevel() {return classLevel_;}
			double getGPA() {return GPA_;}

	};

int main()
{
	//Part B2
	vector<studentInfo> students;
	ifstream file("lab7studentlist.txt");
	if(file.fail())
		{
			cout << "Failure opening file" <<  endl;
			exit (1);
		}

	string fName = "";
	string lName = "";
	string classLevel = "";
	double gpa;

	while(file >> fName >> lName >> classLevel >> gpa)
		{
			students.push_back(studentInfo(fName,lName,classLevel,gpa));

		}

	cout << students[0].getFirstName() << endl;
	cout << students[0].getLastName() << endl;
	cout << students[0].getClassLevel() << endl;
	cout << students[0].getGPA() << endl;

	//Part B3
	double averageGPA = 0.0;
	for (int i = 0; i <  students.size(); i++)
		{
			averageGPA += students[i].getGPA();
		}
	averageGPA /= students.size();

	ofstream outputFile("partBOutput.txt");

	if(outputFile.fail()) 
	{
		cout << "File failed to be created" << endl;
		exit (1);
	}

	outputFile << averageGPA << endl;

	for (int i = 0; i < students.size(); i++)
		{
			if (students[i].getGPA() > averageGPA)
			{
				outputFile << students[i].getFirstName() << " " 
				<< students[i].getLastName() << endl;
			}
		}

};