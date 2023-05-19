#include <iostream>

using namespace std;

long long int factorial (int n) {
   if (n == 0 || n == 1)
   return 1;
   else
   return n * factorial(n - 1);
}

long long int combination(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n-r));
}

long long int pickUpsticks(int log_stick) {
    int one = 0;
    int two = 0;
    int three = 0;
    
    long long int result = 0;
    
    for (one = 0; one <= log_stick; one++) {
        if (one + 2*two + 3*three == log_stick) result+=1;
        for (two = 0; two <= log_stick/2; two++) {
            for (three = 0; three <= log_stick/3; three++) {
                //cout << one << " " << two << " " << three; //FOR TESTING
                
                if (one + 2*two + 3*three == log_stick) {
                    //cout << " YES" << endl; //FOR TESTING
                    int max = one + two + three;
                    long long int addition = combination(max, one)*combination(max-one, two)*combination(max-one-two,three);
                    result+=addition;
                }
                else {
                    //cout << endl; //FOR TESTING
                }
            }
        }
    }
    
    //cout << result;
    
    return result;
    
}   

int main()
{
    int log_stick = 45; //Initialize
   
    cout << pickUpsticks(log_stick);
    
    
    return 0;
}