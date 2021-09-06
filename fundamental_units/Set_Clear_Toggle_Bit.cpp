#include <iostream>

using namespace std;

int main()
{

    // Setting 
    unsigned char x = 4;
    // set 7th bit  7 6 5 4 3 2 1 0
    x = x | (1 << 7);
    
    cout << (int)x << endl;
    
    // Clearing
    x = 127;
    // Clear 4th bit
    x = x & ~(1 << 4);
    
    cout << (int)x << endl;
    
    // Toggling
    x = 30;
    // Toggle 5th bit
    x = x ^ (1 << 5);
    
    cout << (int)x << endl;
    
    x = x ^ (1 << 5);
    cout << (int)x << endl;
    
    return 0;
}
