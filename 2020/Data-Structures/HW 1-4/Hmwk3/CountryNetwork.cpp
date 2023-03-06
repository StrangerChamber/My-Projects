/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represet communication paths between nations             */
/****************************************************************/

#include "CountryNetwork.hpp"

using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CountryNetwork::CountryNetwork()
{
    // set header to null 
    head = NULL;
}


/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
void CountryNetwork::insertCountry(Country* previous, string countryName)
{  
    Country* ptr = new Country();
    ptr->name = countryName;
    if(previous == NULL){// insert into head
        cout << "adding: " << countryName << " (HEAD)" << endl;
        ptr->next = head;
        head = ptr;
    }
    else{// insert into middle or end
        cout << "adding: " << countryName << " (prev: " << previous->name<< ")" << endl;
        ptr->next = previous->next;
        previous->next = ptr;
    }
}


/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup()
{
    insertCountry( head ,"United States");
    insertCountry( head,"Canada");
    insertCountry(head->next , "Brazil");
    insertCountry( head->next->next, "India");
    insertCountry(head->next->next->next , "China");
    insertCountry( head->next->next->next->next, "Australia");
}

/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 */
Country* CountryNetwork::searchNetwork(string countryName)
{
    int counter = 0;
    Country* ptr = head;
    while(ptr!= 0){
        if(ptr->name == countryName){
            counter++;
            break;
        }
        ptr = ptr->next;
    }
    if(counter == 0){
        return NULL;
    }
    else{
        return ptr;
    }


}

/*
 * Purpose: Transmit a message across the network to the
 *   receiver. Msg should be stored in each country it arrives
 *   at, and should increment that country's count.
 * @param receiver name of the country to receive the message
 * @param message the message to send to the receiver
 * @return none
 */
void CountryNetwork::transmitMsg(string receiver, string message)
{
    int counter = 0;
    int count = 0;
    Country* crawler = head;
    if(crawler == NULL){
        cout<< "Empty list" << endl;        
    }
    else if(searchNetwork(receiver)== NULL){
        cout << "Country not found" << endl;
    }
    else{
        while(crawler!= NULL){
            counter++;
            crawler->numberMessages++;
            crawler->message = message;
            cout << crawler->name << " [# messages received: " << crawler->numberMessages << "] received: " << crawler->message << endl;
            if(crawler->name == receiver ){
                count++;
                break;
            }
            crawler = crawler->next;
        } 
    }
}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath()
{
    Country* crawler = head;
    cout << "== CURRENT PATH ==" << endl;      
    if(head == NULL){
        cout << "nothing in path" << endl;
    }
    else{  
        while(crawler != NULL){
            cout << crawler->name << " -> ";
            crawler = crawler->next;
        }
        cout << "NULL" << endl;
    }
    cout << "===" << endl;
}
