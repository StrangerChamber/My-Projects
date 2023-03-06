#include <iostream>
#include<math.h>
using namespace std;

// CS1300 Fall 2019
// Author: Jack Blackburn
// Recitation: f19 – Lucas
// Project 1 - Problem 6...

  double matches1=0;
double match1(string genome1, string sequence){             // funstion for comparing genome 1 with the sequence and getting the number of matches 
        for (int i=0; i<=genome1.length();i++){
            if (genome1[i]==sequence[i]){
                matches1++;
            }
        }
        return matches1;
    }
    
    double matches2=0;
    double match2(string genome2, string sequence){       // same as above function just for genome 2
        for (int j=0;j<= genome2.length();j++){
            if (genome2[j]==sequence[j]){
                matches2++;
            }
        }
        return matches2;
    }
    double matches3=0;
   double match3(string genome3, string sequence){       // function for genome 3
       for (int k=0;k<=genome3.length();k++){
           if (genome3[k]==sequence[k]){
               matches3++;
           }
     
   }
   return matches3;
   }





void findMatchedGenome(string genome1, string genome2, string genome3, string sequence){            //function for getting the comparisons right
  
   if (genome1=="" || genome2=="" || genome3==""|| sequence== ""){
        cout<< "Genomes or sequence is empty."<< endl;
    }
  else if (genome1.length()!=genome2.length() || genome1.length()!=genome3.length() || genome2.length()!=genome3.length()){
        cout << "Lengths of genomes are different."<< endl;
    }
   else if (matches1>=matches2 && matches2>=matches3){                  // i couldnt figure out how to do the if else statements to get the right output i believe i was close
       cout << "Genome 1 is the best match.";
         
   else if (matches2>=matches1 && matches1>=matches3){
       cout << "Genome 2 is the best match.";
   }
 else if (matches3>=matches1 && matches1>=matches2){
       cout << "Genome 3 is the best match.";
   }
}
}


 


    
   
 
  
    




int main(){
  //  cout << findMatchedGenome("TAAGGCA","TACCTAC","AGCCAGA", "TCT")<<endl<< " should be 'Genome 2 is the best match.'" << endl;
//    cout << findMatchedGenome("fez", "fez", "fez", "fez")<<endl<< " should be all 3 outputs" << endl;

 
}