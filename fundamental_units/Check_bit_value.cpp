
#include <iostream>

using namespace std;

int main()
{
    
    unsigned char x = 8;
    
    // Check if bit 3 is set or not ? (7 6 5 4 3 2 1 0)
    if( (x & (1 << 3)) != 0 )
        cout << "3rd Bit is set" << endl;
    else
        cout << "3rd Bit is not set" << endl;

}
