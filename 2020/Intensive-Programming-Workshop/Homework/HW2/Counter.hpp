#include <iostream>
#include <map>
#include <vector>
#include <set>
#ifndef HEADER_FILE_NAME
#define HEADER_FILE_NAME

template<class T>
class Counter{
    public:
    Counter();
    Counter(std::vector<T> vals);
    int Count();
    int Count(T key);
    int Count(T min, T max);
    void Remove(T key);
    void Increment(T key);
    void Increment(T key, int n);
    void Decrement(T key);
    void Decrement(T key, int n);
    T MostCommon();
    std::vector<T> MostCommon(int n);
    T LeastCommon();
    std::vector<T> LeastCommon(int n);
    std::map<T, double> Normalized();
    std::set<T> Keys();
    std::vector<int> Values();
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Counter<U> &b);

    private:
    std::map<T,int> myMap;

};

#endif

template <class T>
Counter<T>::Counter(){
    std::map<T, int> myMap_;
    myMap = myMap_;
}

template <class T>
Counter<T>::Counter(std::vector<T> vals){
    for(int i = 0;i<vals.size();i++){
        if(myMap.find(vals[i])!=myMap.end()){
            //already in map so increment key
            myMap[vals[i]] += 1;
        } else{//add the key and set value to 1
            myMap.insert(std::pair<T,int>(vals[i],1));
        }
    }
}

template <class T> 
int Counter<T>::Count(){
    int sum = 0;
    for(std::pair<T, int> pair : myMap){
        sum += pair.second;
    }
    return sum;
}

template <class T> 
int Counter<T>::Count(T key){
    //search for key 
    //if found return value
    // else return 0
    if(myMap.find(key) != myMap.end()){
        return myMap.at(key);
    }
    return 0;
}

template <class T> 
int Counter<T>::Count(T min, T max){
    int sum = 0;
    for( T i = min;i<max;i++){
        sum += myMap[i];
    }
    return sum;
}

template <class T> 
void Counter<T>::Remove(T key){
    myMap.at(key) = 0;
    myMap.erase(myMap.find(key));
}

template <class T> 
void Counter<T>::Increment(T key){
    myMap.at(key) +=1;
}

template <class T> 
void Counter<T>::Increment(T key, int n){
    myMap.at(key) +=n;
}

template <class T> 
void Counter<T>::Decrement(T key){
    myMap.at(key) -=1;
    if(myMap.at(key)<0){
        myMap.at(key) = 0;
    }
}

template <class T> 
void Counter<T>::Decrement(T key, int n){
    myMap.at(key) -=n;
        if(myMap.at(key)<0){
        myMap.at(key) = 0;
    }
}

template <class T> 
T Counter<T>::MostCommon(){
    int highest = 0;
    T save;
    for(std::pair<T, int> pair: myMap){
        if(pair.second>highest){
            highest = pair.second;
            save = pair.first;
        }      
    }
    return save;
}

template <class T> 
std::vector<T> Counter<T>::MostCommon(int n){
    std::vector<T> myV;
    if(myMap.empty() == true){
        return myV;
    }
    T save;
    int most = 0;
    int count = 0;
    for(int i = 0;i<n;i++){
        for(std::pair<T, int> pair : myMap){
            if(pair.second>most){
                for(int j = 0;j<myV.size();j++){
                    if(pair.first == myV[j]){
                        count++;
                    }
                }
                if(count == 0){
                    most = pair.second;
                    save = pair.first;
                }    
            }   
            count = 0;   
        }
        myV.push_back(save);
        most =0;
    }  
    return myV;
}

template <class T> 
T Counter<T>::LeastCommon(){
    int lowest = 100;
    T save;
    for(std::pair<T, int> pair: myMap){
        if(pair.second<lowest){
            lowest = pair.second;
            save = pair.first;
        }      
    }
    return save;
}

template <class T> 
std::vector<T> Counter<T>::LeastCommon(int n){
    std::vector<T> myV;
    if(myMap.empty() == true){
        return myV;
    }
    T save;
    int least = 0;
    int count = 0;
    for(int i = 0;i<n;i++){
        for(std::pair<T, int> pair : myMap){
            if(pair.second<least){
                for(int j = 0;j<myV.size();j++){
                    if(pair.first == myV[i]){
                        count++;
                    }
                }
                if(count == 0){
                    least = pair.second;
                    save = pair.first;
                }    
            }      
        }
        myV.push_back(save);
        least =0;
        count = 0;
    }
    return myV;
}

template <class T> 
std::map<T,double> Counter<T>::Normalized(){
    std::map<T,double> map2;
    int sum = 0;
    for(std::pair<T, int> pair : myMap){
        sum += pair.second;
    }
    for(std::pair<T, int> pair : myMap){
        map2[pair.first] = (pair.second/sum);
    }    
    return map2;
}

template <class T> 
std::set<T> Counter<T>::Keys(){
    std::set<T> keys;
    int i =0;
    for(std::pair<T, int> pair: myMap){
        keys.insert(pair.first);
        i++;
    }
    return keys;   
}


template <class T> 
std::vector<int> Counter<T>::Values(){
    std::vector<int> vals;
    int i = 0;
    for(std::pair<T, int> pair: myMap){
        vals[i] = pair.second;
        i++;
    }
    return vals;   
}


template <typename U>
std::ostream& operator<<(std::ostream& os, const Counter<U> &b) {
      for(std::pair<U, int> pair: b){
          os << pair.first <<": "<<pair.second<<", ";
      }
}