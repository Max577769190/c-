/**
 * @file prog.cpp
 * @Synopsis  调试帮助
 * @author Max577769190
 * @version 
 * @date 2015-11-08
 */
#include<iostream>
#include<string>
#include<cassert>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::cerr;

int main()
{
	string line;
	cin >> line;
	if(line.size() < 10)
		cerr << "Error: " << __FILE__
			 << " : in function " << __func__
			 << " at line " << __LINE__ << endl
			 << "	Compiler on " << __DATE__
			 << " at " << __TIME__ << endl
			 << " 		Word read was \"" << line 
			 << "\": length too short" << endl;
	
	return 0;
}
