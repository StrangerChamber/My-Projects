#include <iostream>

// Name: John Blackburn
//

// Write any functions you need here!

    int func(int * input){
        *(input) = 15;
        return *input;
    }

    int funcp(int & input){
        input = 30;
        return input;
    }

    class money{
    public:
    money();
    bool operator==(const money & rhs) const;
    int operator+(const money & rhs) ;
    private:
    int cash;
};
bool money::operator==(const money & rhs) const {
    if(cash == rhs.cash){
        return 1;
    }
    else{
        return 0;
    }
}
int money::operator+(const money & rhs){
    return (cash + rhs.cash);
}
money:: money(){
    cash = 1000;
}
int main() {
    // Add as many prints to cout as you need to answer the questions.
    // Leave them in your code when you turn it in.
    // If you have lines of code that cause errors that test the questions,
    // leave this code in your file but comment it out.
    
    // 1) Declare an int
    int x = 1;
    // 2) Declare a pointer to that int
    int* p = &x;
    // 3) Increment the int via the pointer
    *p = *p + 1;
    std::cout << x << std::endl;
    // 4) Declare a reference to your int
    int & ref = x;
    // 5) Increment the int via the reference
    ref = 4;
    std::cout << x << std::endl;
    // 6) When you increment the int via the variable declared in #1, which
    x = 10;
    std::cout << *p << ", " << ref << std::endl;

    // variables will be modified to see the changes? (the pointer , reference or both?)
    // Answer: 
    
    //They both were updated. I changed the value of x to 10 through the int itself 
    //and then printed both the dereferenced pointer as well as the reference and they both 
    //were updated to the correct value of x.

    // 7) When you increment the int via the pointer declared in #2, which
    // variables will be modified to see the changes?
    *p = 12;
    std::cout << x << ", " << *p << ", " << ref << std::endl;
    // Answer: The variables modified will be the int x itself will be changed as well as my reference pointer will also be modified

    // 8) When you increment the int via the reference declared in #4, which
    ref = 14;
    std::cout << x << ", " << *p << ", " << ref << std::endl;    
    // variables will be modified to see the changes?
    
    // Answer: The int x will be modified, so will the reference, and the pointer will still point to the same spot 

    // 9) Write a function that takes an int * parameter. How would you pass the 
    // variable from #1 into this function? (write the function header and function call below)
    
    // you pass the pointer version into the function and then dereference to update the value 
    std::cout <<func(p) << std::endl;//should be 15
    
    // 10) Can you pass your reference from #4 to the function from #9 without accessing its address?
    
    // Answer: no you cannot when you pass a reference into the function you get an error
    //func(ref);

    // 11) Write a function that takes an int & parameter. How would you pass the 
    // variable from #1 into this function? (write the function header and call below)
    std::cout << funcp(ref) << std::endl;//should be 30
    
    //answer: you pass your reference variable from #4 
    
    // 12) Can you pass your pointer from #2 to the function from #11 without dereferencing it?
    
    // Answer: no you cannot 

    // 13) Can you pass your reference from #4 to the function from #11?
   
    // Answer: yes you can

    // 14) Write a function that takes one const reference input parameter and one pointer
    // output parameter. The function should fill in the value of the output parameter based
    // on the value of the input parameter. (what it does exactly is up to you).
    // Call your function 3 times below. Be sure to include output as necessary to be sure
    // your function works as described.
   
    // 15) What is/are the difference(s) between output parameters and return values?
    // Answer: ouput parameters can return multiple values while return statements can only give back one value

    // 16) Create a custom class with at least one private field/class attribute. Overload the == and + operator for this class
    // such that == can be used to compare the objects of the class and + can be used to add
    // 2 objects of the class together. Implement an appropriate constructor for your class.
    // When you overload these operators, the resulting return value should make sense.
    // Instantiate at least 2 objects of this class and perform the == and + operations on them.
    // hint: for operator+, the function signature when implemented as a member function of the Object class is:
    // Object operator+(const Object &other)
    // Answer:
    money m1;
    money m2;
    if(m1==m2){
        std::cout << "overload"<<std::endl;
        std:: cout << m1 + m2;
    }
}
