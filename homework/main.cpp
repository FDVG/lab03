#include <iostream>
#include <string>
//some comments
//some more comments
//#include <cstlib> // for system
using namespace std;



int main()
{
    string name;
    cout << "Enter your name: " <<endl;
    cin >> name;
    cout << "Hello, world from "<< name << endl;
    //system("pause"): //for those who use MS VC
    return 0;
}
