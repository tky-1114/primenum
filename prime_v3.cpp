#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <atomic>
#include <csignal>
#include <chrono>

using namespace std;
std::atomic<bool> stop_signal(false);

void stop(int sig)
{
    if (sig == SIGINT)
    {
        stop_signal = true;
    }
}

int main()
{
    signal(SIGINT, stop);

    long long n = 2;              /*判定される数*/
    long long i = 1;              /*割る数*/
    long long count;              /*公約数の数*/
    vector<long long> p_num = {}; /*素数たちの箱*/

    std::ifstream in("lastnum.txt");
    if (in)
    {
        in >> n;
        std::cout << "Resume from " << n << std::endl;
    }
    in.close();

    auto start = std::chrono::high_resolution_clock::now();
    while (!stop_signal)
    {
        i = 1;
        count = 0;

        bool isPrime = true;
        for (int p : p_num)
        {
            if (p * p > n)
                break;
            if (n % p == 0)
            {
                isPrime = false;
                break;
            }
        }

        while (n >= i)
        {
            int result = n % i;
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
            p_num.push_back(n);
        }

        n = n + 1;
        count = 0;
        i = 0;
        if (n % 1000000 == 0)
        {
            std::ofstream save("lastnum.txt");
            save << n;
        }
        if (n % 100 == 0)
        {
            auto now = std::chrono::high_resolution_clock::now();
            double elapsed = std::chrono::duration<double>(now - start).count();
            double cps = (double)p_num.size() / elapsed;
            std::cout << "CPS: " << cps << "\r" << std::flush;
            std::ofstream out("index.csv", std::ios::app);
            out << n << "," << cps << "\n";
            out.close();
        }
    }

    std::cout << "Calculation has benn stopped safety.\n";
    std::cout << "last number is " << n << std::endl;
    std::cout << "This number is saved." << std::endl;
    auto now = std::chrono::high_resolution_clock::now();
    double elapsed = std::chrono::duration<double>(now - start).count();
    double cps = (double)p_num.size() / elapsed;
    std::cout << "Final CPS: " << cps << std::endl;

    std::ofstream out("lastnum.txt");
    out << n;
    out.close();
}