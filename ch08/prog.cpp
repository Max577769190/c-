#include<sstream>
#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::ostringstream;
using std::string;

struct People {
	string name;
	vector<string> phones;
};

bool valid(const string &nums) {
	return nums.size() == 11 ?  1 : 0 ;
}

string format(const string &nums) {
	string s1, s2, s3, s4;
	for(decltype(nums.size()) index = 0; index != nums.size(); ++index) {
		if(index < 3)
			s1 += nums[index];
		else if(index < 7)
			s2 += nums[index];
		else
			s3 += nums[index];
	}
	s4 = s1 + "-" + s2 +"-" + s3;
	return s4;
}

void readPeople(std::istream &is, vector<People> &people) {
	string information, phonesNum;
	People info;
	while(getline(is, information)) {
		std::istringstream iss(information);
		iss >> info.name;
		while(iss >> phonesNum)
			info.phones.push_back(phonesNum);
		people.push_back(info);
	}
}

int main()
{
	vector<People> people;
	std::ifstream input("infile");
	readPeople(input, people);
	for(const auto &entry : people) {
		ostringstream formatted, badNums;
		for(const auto &nums : entry.phones) {
			if(!valid(nums))
				badNums << " " << nums;
			else 
				formatted << " " << format(nums);
		}
		if(badNums.str().empty())
			cout << entry.name << " " << formatted.str() << endl;
		else
			std::cerr << "Input error: " << entry.name << " invalid number(s) " << badNums.str() << endl;
	}
	return 0;
}
