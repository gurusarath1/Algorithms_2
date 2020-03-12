#include <iostream>

using namespace std;

int isPalindrome(int num);

int main()
{

	cout << isPalindrome(132231) << "\n";
	cout << isPalindrome(121) << "\n";
	cout << isPalindrome(0) << "\n";
	cout << isPalindrome(10) << "\n";
	cout << isPalindrome(99) << "\n";
	cout << isPalindrome(12345) << "\n";
	cout << isPalindrome(998899) << "\n";
	cout << isPalindrome(9981899) << "\n";

	return 0;
}


int isPalindrome(int num)
{

	int temp_num = num;
	int rev_num_half = 0;
	int digit = 0;

	if(num < 0 || (num%10 == 0 && num!=0) )
	{
		return false;
	}

	while(temp_num != 0)
	{
		digit = temp_num % 10;
		
		rev_num_half = rev_num_half*10 + digit;

		if(rev_num_half > temp_num/10)
		{
			//cout << rev_num_half << "   " << rev_num_half/10 << "   " << temp_num << "   " << temp_num/10 << "\n";
			break;
		}

		temp_num = temp_num / 10;

	}

	if( (temp_num == rev_num_half) || (temp_num == rev_num_half/10) )
	{
		return 1;
	} else {
		return 0;
	}
}