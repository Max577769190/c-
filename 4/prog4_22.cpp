#include<iostream>
#include<string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int grade;
	string littergrade;
	
	//release 1
	/*
	while(cin >> grade)
	{
		littergrade = (grade > 90) ? "High pass"
					 : (grade > 75) ? "Pass"
									: (grade > 60) ? "Low pass": "Fail";
		cout << littergrade << endl;
	}
	*/
	
	//release 2
	while(cin >> grade)
	{
		if(grade > 90)
			littergrade = "High pass";
		else if(grade > 75)
			littergrade = "Pass";
		else if(grade > 60)
			littergrade = "Low pass";
		else
			littergrade = "Fail";
		cout << littergrade << endl;
	}
	return 0;
}
