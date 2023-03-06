#include <iostream> 
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;

struct wordItem{
    string word;
    int count;
};

void getStopWords(const char *ignoreWordFileName, string ignoreWords[]){
    ifstream infile;
    infile.open(ignoreWordFileName);
    string line, first;
    int i = 0;
    if(infile.is_open() == true){
        while(infile >> line){
            ignoreWords[i] = line;
            i++;
        }
    }
    else{
      cout<<"Failed to open "<< ignoreWordFileName <<endl;  
    }
    infile.close();
}

bool isStopWord(string word, string ignoreWords[]){
    int counter = 0;
    for(int i = 0; i<50;i++){
        if(word == ignoreWords[i]){
            counter++;
            return true;
            break;
        }
        else{
            if(i == 49){
                return false;
            }
        }
    }
    return false;
}

int getTotalNumberNonStopWords(wordItem uniqueWords[], int length){
    int total = 0;
    for(int i = 0;i<length;i++){
        total = total + uniqueWords[i].count;
    }
    return total;
}

void arraySort(wordItem uniqueWords[], int length){// bubble sort in descending order
    for(int k = 0;k< length-1;k++){
        for(int i = 0; i< length-k-1;i++){
            if(uniqueWords[i].count<=uniqueWords[i+1].count){
                int temp = uniqueWords[i].count;
                string tempy = uniqueWords[i].word;
                uniqueWords[i].count = uniqueWords[i+1].count;
                uniqueWords[i].word = uniqueWords[i+1].word;
                uniqueWords[i+1].count = temp;
                uniqueWords[i+1].word = tempy;

            }
        }
    }
}

void printNext10(wordItem uniqueWords[], int N, int totalNumWords){
    int end = N + 10;

    for(int i = N;i<end;i++){
        cout << fixed<< setprecision(4) << (float)uniqueWords[i].count/(float)totalNumWords << " - " << uniqueWords[i].word << endl; 
    }
}


int main(int argc, char* const argv[]){
  if(argc != 4){
      cout << "Usage: Assignment2Solution <number of words> <inputfilename.txt> <ignoreWordsfilename.txt>" << endl;
    return -1;
  }
  int doublingCount = 0; //use this to keep track of how many times the array doubles
  int capacity = 100;
  string ignoreThese[50];
  string line;
  int i = 0;
  int k = 0;
  int count = 0;
  getStopWords(argv[3],ignoreThese);
  wordItem *ptr = new wordItem[100];
  for(int i = 0;i<100;i++){
      ptr[i].count = 0;
  }
  ifstream inFile;
  inFile.open(argv[2]);
  while(inFile >> line){
      if(isStopWord(line, ignoreThese) == false){
          for(int j = 0; j<i;j++){
              if(line == ptr[j].word){
                  ptr[j].count++;
                  count++;
                  break;
              }
          }  
          if(count == 0){
            ptr[i].word = line;
            ptr[i].count++;
            i++;
          }
          count = 0;
        if(i+1 == capacity)
        {
            doublingCount++;
            int newCapacity = 2*capacity;
            wordItem *newArr= new wordItem[newCapacity];
            for(int k = 0;k<capacity;k++){
                newArr[k].word = ptr[k].word;
                newArr[k].count = ptr[k].count; 
            }
            capacity = newCapacity;
            delete[] ptr;
            ptr = newArr;
        }
        k++;
      }  
    }
    arraySort(ptr, i+1);
    cout << "Array doubled: " << doublingCount << endl << '#' << endl;
    cout << "Unique non-common words: " << i << endl << '#' << endl;
    cout << "Total non-common words: " << k << endl << "#" << endl; 
    cout<< "Probability of next 10 words from rank " << argv[1] << endl;
    cout << "---------------------------------------" << endl;
    printNext10(ptr, stoi(argv[1]) , k);


}