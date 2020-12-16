#include <iostream>
#include <vector>

using namespace std;

int fib(int n) {

    if(n == 0) {
        return 0;
    }

    if(n == 1) {
        return 1;
    }

    return fib(n-1) + fib(n-2);

}


int main() {

    cout << fib(7) << endl;
    cout << fib(5) << endl;
    cout << fib(6) << endl;

    return 0;
}
