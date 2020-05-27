#include <iostream>  
#include <iomanip>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>
#include <queue>
#include <list>

using namespace std;

int main()
{
    //Program Header
    cout << "Project_6" << endl;
    cout << "Long Beach City College" << endl;
    cout << "Author: Chandaralong" << endl;
    cout << "May. 06, 2020" << endl;
    cout << "======================================================================" << endl;
    //declaration of various variable
    double GPA;
    double highestGPA;
    string name;
    queue<string> bestqueue;
    list<string> bestlist;
    ifstream read;
    ostream_iterator<string> screen(cout, "\n");

    //Open the file in order to read from the file
    read.open("HighestGPAData.txt");

    //If there is no file detected
    if (!read)
    {
        cout << "The input file does not exist. Program terminates!" << endl;
        return 1;
    }

    //Output GPA with teo decimal places
    cout << fixed << showpoint;
    cout << setprecision(2);

    //read the file for GPA and the student name
    read >> GPA >> name;
    //cout << GPA << " " << name;

    //Set the current GPA to highest GPA
    highestGPA = GPA;

    //While there are something to read
    while (read)
    {
        //if current GPA that was read is higher than highest GPA
        if (GPA > highestGPA)
        {
            //initilize the list
            bestlist.clear();
            bestlist.push_back(name);
            //Set the current GPA to highest GPA
            highestGPA = GPA;
        }
        else if (GPA == highestGPA)
        {
            bestlist.push_back(name);
        }
        read >> GPA >> name;
    }

    //output highest GPA
    cout << "(i) Using the STL list" << endl;
    cout << "Highest GPA = " << highestGPA << endl;
    //output students with highest GPA
    cout << "The students holding the " << "highest GPA are:" << endl;
    copy(bestlist.begin(), bestlist.end(), screen);
    read.close();

    cout << "======================================================================" << endl;

    //Open the file in order to read from the file
    read.open("HighestGPAData.txt");

    //If there is no file detected
    if (!read)
    {
        cout << "The input file does not exist. Program terminates!" << endl;
        return 1;
    }

    //Output GPA with teo decimal places
    cout << fixed << showpoint;
    cout << setprecision(2);

    //read the file for GPA and the student name
    read >> GPA >> name;
    //cout << GPA << " " << name;

    //Set the current GPA to highest GPA
    highestGPA = GPA;

    //While there are something to read
    while (read)
    {
        //if current GPA that was read is higher than highest GPA
        if (GPA > highestGPA)
        {
            //initilize the queue
            while (!bestqueue.empty())
            {
                bestqueue.pop();
            }
            bestqueue.push(name);
            //Set the current GPA to highest GPA
            highestGPA = GPA;

        }
        else if (GPA == highestGPA)
        {
            bestqueue.push(name);
        }
        read >> GPA >> name;
    }

    //output highest GPA
    cout << "(ii) Using the STL queue" << endl;
    cout << "Highest GPA = " << highestGPA << endl;
    //output students with highest GPA
    cout << "The students holding the " << "highest GPA are:" << endl;
    while (!bestqueue.empty())
    {
        cout << bestqueue.front() << endl;
        bestqueue.pop();
    }
    read.close();

    return 0;
}