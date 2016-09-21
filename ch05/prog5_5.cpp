#include<iostream>
#include<vector>
#include<string>
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int grade;
	vector<string> array{"F", "E", "D", "C", "B", "A"};
	string litterGrade; 

	while (cin >> grade)
	{
		if (grade >= 0 && grade <= 100)
		{
			if(grade == 100)
				litterGrade = "A++";
			else
			{
				if(grade < 40)
					litterGrade = array[0];
				else
				{
					litterGrade = array[(grade - 40) / 10];
					if( grade % 10 > 7)
						litterGrade += '+';
					else if(grade % 10 < 4)
						litterGrade += '-';
				}
			}
			cout << litterGrade << endl;
		}
	}
	return 0;
}
