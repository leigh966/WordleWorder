// WordleSolver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <fstream>
#include <string>
#include <iomanip>      // std::setprecision
using namespace std;

int main()
{
    time_t start, end;
    list<string> fiveLetters;
    ifstream MyFile("words.txt");
    string myText;
    time(&start);
    while (getline(MyFile, myText)) {
        // Output the text from the file
        if (myText.length() == 5)
        {
            fiveLetters.push_back(myText);
            cout << myText << endl;
        }     
    }
    time(&end);
    // Calculating total time taken by the program.
    double time_taken = double(end - start);
    cout << "Time taken by program is : " << fixed
        << time_taken << setprecision(5);
    cout << " sec " << endl;
    return 0;
}

