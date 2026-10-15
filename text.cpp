# include<iostream>
# include<fstream>

using namespace std;

int main()
{
    int a = 10;
    ofstream outputfile("test.txt");
    outputfile<<a;
    outputfile.close();
}