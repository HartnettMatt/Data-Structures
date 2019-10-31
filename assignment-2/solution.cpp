#include <fstream>
#include <iostream>
#include <math.h>
using namespace std ;

struct wordItem{
  string word;
  int count;
};

void getStopWords(const char *ignoreWordFileName, string ignoreWords[]){
  ifstream iF;
  iF.open(ignoreWordFileName);
  string s;
  int b = 0;
  while(getline(iF, s)){
    ignoreWords[b] = s;
    b++;
  }
  iF.close();
  if(b == 0){
    cout << "Failed to open " << ignoreWordFileName <<endl;
  }
}

bool isStopWord(string word, string ignoreWords[]){
  for(int i = 0; i < 50; i++){
    if(word.compare(ignoreWords[i]) == 0){
      return true;
    }
  }
  return false;
}

int getTotalNumberNonStopWords(wordItem uniqueWords[], int length){
  int sum = 0;
  for(int i = 0; i < length; i++){
    sum += uniqueWords[i].count;
  }
  return sum;
}

void arraySort(wordItem *&uniqueWords, int length){
  int c = 0;
  for(int i = 0; i < length-1; i++){
    if(uniqueWords[i].count < uniqueWords[i+1].count){
      wordItem temp = uniqueWords[i];
      uniqueWords[i] = uniqueWords[i+1];
      uniqueWords[i+1] = temp;
      c++;
    }
  }
  if(c != 0){
    arraySort(uniqueWords, length);
  }
}

void printNext10(wordItem uniqueWords[], int n, int totalNumWords){
  for(int i = n; i < n+10; i++){
    double prob = uniqueWords[i].count/(totalNumWords*1.0);
    prob = 10000*prob;
    int temp = round(prob);
    prob = temp/10000.0;
    if(temp%10 == 0 && temp%100 != 0){
        cout << prob << "0 - " << uniqueWords[i].word << endl;
    } else if (temp%100 == 0){
        cout << prob << "00 - " << uniqueWords[i].word << endl;
    } else {
        cout << prob << " - " << uniqueWords[i].word << endl;
    }
  }
}

void doubleArray(wordItem *&arr, int &length){
  wordItem *temp = new wordItem[length*2];
  for(int i = 0; i < length; i++){
    temp[i] = arr[i];
  }
  delete [] arr;

  arr = temp;
  length = length*2;
}

int main (int argc, char const *argv[])
{
  if(argc != 4){
    cout <<"Usage: Assignment2Solution <number of words><inputfilename.txt> <ignoreWordsfilename.txt>" << endl;
    return 1;
  }

  int n = stoi(argv[1]);
  string inputFN = argv[2];
  string ignoreArr[50];

  getStopWords(argv[3], ignoreArr);

  int len = 100;
  wordItem *words = new wordItem[len];

  ifstream iF;
  iF.open(inputFN);
  string s;
  wordItem temp;
  int wA = 0;
  bool counted = false;
  int wordCounter = 0;
  int doubleCounter = 0;

  wordItem *testPtr = new wordItem[5];

  while(iF >> s){
    wordCounter++;
    counted = false;
    if(!isStopWord(s, ignoreArr)){
      if(wA == 0){
        words[0].word = s;
        words[0].count = 1;
        wA++;
      } else {
        for(int i = 0; i <= wA; i++){
          if(words[i].word.compare(s) == 0){
            words[i].count++;
            counted = true;
          }
        }
        if(wA >= len-1){
          doubleArray(words, len);
          doubleCounter++;
        }
        if(!counted){
          words[wA].word = s;
          words[wA].count = 1;
          wA++;
          counted = true;
        }
      }
    }
  }
  iF.close();

  int number = getTotalNumberNonStopWords(words, wA);
  arraySort(words, len);

  cout << "Array doubled: "<<doubleCounter << "\n#\nUnique non-common words: " << wA << "\n#\nTotal non-common words: " << number << "\n#\nProbability of next 10 words from rank " << n << "\n---------------------------------------" << endl;

  printNext10(words, n, number);

  return 0;
}
