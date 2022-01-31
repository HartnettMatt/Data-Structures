#include <iostream>
#include <fstream>
#include "fundamentals_1.hpp"
#include "fundamentals_1.cpp"
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{

    if(argc<2)
    {
        cout<< "file name missing"<<endl;
        return -1;
    }

	string filename = argv[1];
	ifstream data;
	data.open(filename.c_str());
if (data.fail()){
    cout << "Failed to open the file." << endl;
}

float numarr[100]={0};
string line;
string input;
int numElements = 0;

 if(data.is_open()){
     while(getline(data,line)){
    stringstream ss(line);
    getline(ss, input);
    float newValue=stof(input);
    addToArrayDesc(numarr,numElements,newValue);
    numElements++;
 }



}

    return 0;
}
