/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represent communication paths between nations             */
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
/* finished. do not touch. */
    head = NULL;
}


/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CountryNetwork::isEmpty()
{
/* finished. do not touch. */
    return (head == NULL);
}


/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
void CountryNetwork::insertCountry(Country* previous, string countryName) {
    
    // if we are passed an empty list, just create a new head node, and return
    if (head == NULL)
    {
        cout << "adding: " << countryName << " (HEAD)" << endl;
        head = new Country;
        head->name = countryName;
        head->numberMessages = 0;
        head->next = NULL;
    }
    // if it's not empty, we need to search for previous and append our node there.
    else if(previous == NULL )
    {
        //case where it's a new head Country
        cout << "adding: " << countryName << " (HEAD)" << endl;
        Country *c = new Country;
        c->name = countryName;
        c->numberMessages = 0;
        c->next = head;
        head = c;
    }else{
        cout << "adding: " << countryName << " (prev: " << previous->name << ")" << endl;
        Country *newCountry = new Country;
        newCountry->name = countryName;
        newCountry->numberMessages = 0;
        newCountry->next = previous->next;
        previous->next = newCountry;
    }
}


/*
 * Purpose: delete the country in the network with the specified name.
 * @param countryName name of the country to delete in the network
 * @return none
 */
void CountryNetwork::deleteCountry(string countryName) {
    Country* deleteNode = searchNetwork(countryName);
    if(deleteNode == NULL){
        cout << "Country does not exist." << endl;
    }
    else{
        if(deleteNode == head){
            head = head->next;
            delete deleteNode;
        }
        else{
            Country* crawler = head;
            while(crawler->next != deleteNode){
                crawler = crawler->next;
            }
            crawler->next = deleteNode->next;
            delete deleteNode;
        }
    }
}

/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup()
{
    int num_countries = 6;
    string countries[] = {"United States", "Canada", "Brazil", "India", "China", "Australia"};
    // deleteEntireNetwork();
    Country* prev = NULL;
    for(int i = 0; i < num_countries; i++)
    {
        insertCountry(prev, countries[i]);
        prev = searchNetwork(countries[i]);
    }
}


/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 * @see insertCountry, deletecountry
 */
Country* CountryNetwork::searchNetwork(string countryName)
{
// Search until the head is NULL, or we find the country
    Country* ptr = head;
    while (ptr != NULL && ptr->name != countryName)
    {
        ptr = ptr->next;
    }
    // Return the node, or NULL
    return ptr;
}

/*
* Purpose: Creates a loop from last node to the country specified.
* @param countryName name of the country to loop back
* returns pointer to last node before loop creation (to break the loop)
*/
Country* CountryNetwork::createLoop(string countryName)
{
    Country* backToMe = searchNetwork(countryName);
    Country* crawler = head;
    while(crawler->next!= NULL){
        crawler = crawler->next;
    }
    crawler->next = backToMe;
    return crawler;
}


/*
 * Purpose: deletes all countries in the network starting at the head country.
 * @param none
 * @return none
 */
void CountryNetwork::deleteEntireNetwork()
{
    Country* crawler = head;
    if(head == NULL){
    }
    else{
        while(head!= NULL){
            cout << "deleting: " << head->name << endl;
            delete head;
            head = crawler->next;
            crawler = crawler->next;
        }
        cout << "Deleted network" << endl;
    }
}

/*
*Purpose: to detect loop in the linkedlist
* @param
* returns true if loop is detected. Otherwise return false.
*/
bool CountryNetwork::detectLoop() {
    Country* crawler = head;
    Country* runner = head;
    while(runner!=NULL){
        crawler = crawler->next;
        runner = runner->next->next;
        if(crawler == runner){
            return true;
            break;
        }

    }
    return false;   
}

/*
* Purpose: Take the chunk of nodes from start index to end index
*          Move that chunk at the end of the List
*@param: start index
*@param: end index
* return none
*/
void CountryNetwork:: readjustNetwork(int start_index, int end_index)
{
    int count = 0;
    if(head == NULL){
        cout << "Linked List is Empty" << endl;
    }
    else{
        Country* crawler = head;
        while(crawler->next != NULL){
            crawler = crawler->next;
            count++;
        }
        if(end_index<0 || end_index>count){
            cout << "Invalid end index" << endl;
        }
        else if(start_index>end_index|| start_index<0 || start_index>count){
            cout << "Invalid indices" << endl;
        }
        else{
            // crawler can be used to now point to start index node
            Country* before = head;
            for(int i = 0;i<start_index-1;i++){ // saves before to node right before start index
                before = before->next;
            }
            Country * after = head;
            Country * end = head;
            for(int j = 0; j<end_index+1;j++){ // saves after to node right after chunk to be moved
                after = after->next;
            }
            for(int k = 0; k<end_index;k++){
                end = end->next;
            }
            if(start_index == 0){
                crawler->next = head;
                head = after;
                end->next = NULL;
            }
            else{
                crawler->next = before->next; // pointing current end node to beginning of chunk
                before->next = after; // closing gap
                end->next = NULL;
            }    
        }
    }
}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath() {
    cout << "== CURRENT PATH ==" << endl;
    // If the head is NULL
    Country* ptr = head;
    if (ptr == NULL)
        cout << "nothing in path" << endl;

    // Otherwise print each node, and then a NULL
    else
    {
        while (ptr->next != NULL)
        {
            cout << ptr->name << " -> ";
            ptr = ptr->next;
        }
        cout << ptr->name << " -> ";
        cout << "NULL" << endl;
    }
    cout << "===" << endl;
}
