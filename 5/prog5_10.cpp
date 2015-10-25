#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, blankCnt = 0, tabCnt = 0, lineCnt = 0, ffCnt = 0, fiCnt = 0, flCnt = 0;
	char ch;
	while(cin >> ch)
	{
		switch(ch){
		
		case 'a':
		case 'A':
			++aCnt;
			break ;
		case 'e':
		case 'E':
			++eCnt;
			break;
		case 'i': 
		case 'I':
			++iCnt;
			break;
		case 'o': 
		case 'O':
			++oCnt;
			break;
		case 'u':
		case 'U':
			++uCnt;
			break;
		case ' ':
			++blankCnt;
			break;
		case '\t':
			++tabCnt;
			break;
		case '\n':
			++lineCnt;
			break;
		case 'f':
			{
				cin >> ch;
				switch(ch) {
					case 'i':
						++fiCnt;
						break;
					case 'f':
						++ffCnt;
						break;
					case 'l':
						++flCnt;
						break;
				}
			}
			break;
		}
	}

	cout << "Number of vowel a: \t" << aCnt << '\n'
		 << "Number of vowel e: \t" << eCnt << '\n'
		 << "Number of vowel i: \t" << iCnt << '\n'
		 << "Number of vowel o: \t" << oCnt << '\n'
		 << "Number of vowel u: \t" << uCnt << '\n'
		 << "Number of ff: \t" << ffCnt << '\n'
		 << "Number of fi: \t" << fiCnt << '\n'
		 << "Number of fl: \t" << flCnt << '\n'
		 << "Number of \\t: \t" << tabCnt << '\n'
		 << "Number of \\n: \t" << lineCnt << '\n'
		 << "Number of blank: \t" << blankCnt << endl;
	
	return 0;
}
