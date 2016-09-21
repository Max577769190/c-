#include<iostream>
#include<string>
#include<vector>
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

	while(cin >> grade)
	{
		litterGrade = (grade < 0 || grade > 100)? "Please enter the grade between 0-100."
												: (grade == 100)? "A++"
																: (grade < 40)? array[0]
																			  : (grade % 10 > 7)? array[(grade - 40) / 10] + '+'
																								: (grade % 10 < 4)? array[(grade - 40) / 10] + '-' : array[(grade - 40) / 10];
		cout << litterGrade << endl;
	}
	return 0;
}
