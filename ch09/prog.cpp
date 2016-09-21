#include<string>
#include<iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string s,  oldVal, newVal, word;

	cout << "Please enter a english setence: " ;
	getline(cin, s);
	cout << "Please enter oldVal: ";
	cin >> oldVal;
	cout << "Please enter newVal: ";
	cin >> newVal;

	auto sBegin = s.begin(), oldBegin = s.begin();
	while(sBegin <= s.end()) {
		if(*sBegin == ' ') {
			word.assign(oldBegin, sBegin);
			cout << word << endl;
			if(word == oldVal) {
				s.replace(oldBegin, sBegin, newVal);
				oldBegin = --sBegin;
				cout << "sBegin = " << *sBegin << endl;
				++sBegin;
			} else {
				++sBegin;
				oldBegin = sBegin;
			}
		}
		++sBegin;
	}

	cout << s << endl;

	return 0;
}
