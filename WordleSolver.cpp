// WordleSolver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <fstream>
#include <string>
#include <iomanip>      // std::setprecision
#include <thread>
#include <mutex>
using namespace std;

mutex myMutex;

list<string> fiveLetters;
void add(string myText)
{ 
    // add to list and output only 5 letter words
    if (myText.length() == 5)
    {
        fiveLetters.push_back(myText);
        cout << myText << endl;
    }
}

int main()
{
    time_t start, end;
    
    ifstream MyFile("words.txt");
    string myText;
    time(&start);
    while (getline(MyFile, myText)) {
        add(myText);
    }
    time(&end);
    // Calculating total time taken by the program.
    double time_taken = double(end - start);
    cout << "Time taken by program is : " << fixed
        << time_taken << setprecision(5);
    cout << " sec " << endl;
    return 0;
}

