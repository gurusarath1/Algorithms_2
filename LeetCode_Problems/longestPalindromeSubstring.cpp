#include <iostream>
using namespace std;

int isPalindrome(string s);
string longestPalindrome(string s);
string reverse_string(string s);
string longestPalindrome_support(string s, int bestSoFar, string BestString);

int main()
{

	string strIn = "babaddtattarrattatddetartrateedredividerb";

	if(len == 0)
    {
        return s;
    }


	string sMax = longestPalindrome(strIn);

	cout << sMax;

	return 0;
}


string longestPalindrome(string s)
{
	int len = s.length();

	for(int i=len; i>0; i--)
	{
		if( isPalindrome(s) )
		{
			
			return s;

		} else {
			string s1 = s;
			string s2 = s;
			s1.erase(s1.length()-1, s1.length());
			s2.erase(0, 1);

			string sBestTemp = s.substr(0,0);
			string S_max_1 = longestPalindrome_support(s1, 1, sBestTemp);
			string S_max_2 = longestPalindrome_support(s2, S_max_1.length(), S_max_1);

			if(S_max_1.length() > S_max_2.length())
			{
				return S_max_1;
			} else {
				return S_max_2;
			}
		}
	}

	string s_none = "None";
	return s_none;

}

string longestPalindrome_support(string s, int bestSoFar, string BestString)
{
	int len = s.length();

	if(len <= bestSoFar)
	{
		//cout << "Prune !";
		return BestString;
	}

	for(int i=len; i>0; i--)
	{
		if( isPalindrome(s) )
		{
			
			return s;

		} else {
			string s1 = s;
			string s2 = s;
			s1.erase(s1.length()-1, s1.length());
			s2.erase(0, 1);

			string S_max_1 = longestPalindrome_support(s1, BestString.length(), BestString);
			string S_max_2 = longestPalindrome_support(s2, S_max_1.length(), S_max_1);

			if(S_max_1.length() > S_max_2.length())
			{
				return S_max_1;
			} else {
				return S_max_2;
			}
		}
	}

	string s_none = "None";
	return s_none;

}


int isPalindrome(string s)
{
	/*
	if(s == reverse_string(s))
	{
		return 1;
	} else {
		return 0;
	}
	*/

	for(int i=0, j=s.length()-1; i <= (s.length()/2) + 1 ; i++, j--)
	{
		if(s[i] != s[j])
			return 0;
	}

	return 1;
}

string reverse_string(string s)
{
	char s_rev[s.length()+1];

	s_rev[s.length()] = '\0';

	for(int i=s.length()-1, j=0 ; i >= 0; i--, j++)
	{
		s_rev[j] = s[i];
	}

	string s_rev_obj  = s_rev;

	return s_rev_obj;

}