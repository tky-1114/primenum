#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
int main(){
    int n = 0; /*pow(10,7);*/
    int i = 1;
    int count;
    vector<int> p_num = {};
    while (n >= 0)
    {
        i = 1;
        count = 0;

        bool isPrime = true;
        for(int p:p_num)
        {
            if(p*p>n) break;
            if(n%p==0)
            {
                isPrime = false;
                break;
            }
        }
        
        while (n >= i)
        {
            int  result = n % i;
            if (result == 0)
            {
                count = count + 1;
            }
            else
            {
                /*pass*/
            }
            i = i + 1;
            
        }
        
        if (count == 2)
        {
            cout << n << endl;
            p_num.push_back(n);
        }
        
        n = n + 1;
        count = 0;
        i = 0;    
    }
}
/*10s 72643*/
/*1280001287*/