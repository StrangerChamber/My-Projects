#include "TextUI.h"


TextUI::TextUI(){
    std::cout<<"Welcome to my election simulator :) Here you can choose the amount of candidates in the election, the type of election, campaign strategies and how many simulations you want to run. Have fun and good luck!!" << endl;
}

void TextUI::electionType(){
    std::cout <<"What kind of election should we have (enter 0 for direct or 1 for representative, or 2 to stop)? "<<std::endl;
    return;
}

void TextUI::DemReg(){
    std::cout<<"Would you like to register a candidate for the Democrats?(y or n)"<<std::endl;
    return;
}

void TextUI::RepReg(){
    std::cout<<"Would you like to register a candidate for the Republicans?(y or n)"<<std::endl;
    return;
}

void TextUI::LibReg(){
    std::cout<<"Would you like to register a candidate for the Libertarians?(y or n)"<<std::endl;
    return;
}

void TextUI::name(){
    std::cout<<"Please enter their name" << std::endl;
}

void TextUI::campaign(){
    std::cout << "Now you have the option to send candidates to districts to swing their votes in the candidates favor. I will now show you the starting voter pool of each district" <<endl;
}


void TextUI::ElectionTime(){
    std::cout<<"You have decided that campaigning time is now over, so now we're on to the best part!"<<std::endl<<"Constituents will now head to the polls to cast their votes! How Exciting:)!!!"<<std::endl;
}