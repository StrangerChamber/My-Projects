/****************************************************************/
/*                Producer Consumer Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "ProducerConsumer.hpp"
#include <iostream>
#include <string>
#include <iomanip>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu()
{
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Producer (Produce items into the queue)" << endl;
	cout << "2. Consumer (Consume items from the queue)" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}
// Use getline for reading
int main(int argc, char const *argv[])
{
	ProducerConsumer PC;
	int input;
	int amount;
	string item;
	while(input != 3){
		menu();
		cin>>input;
		if(input == 1){
			cout << "Enter the number of items to be produced:" << endl;
			cin>>amount;
			for(int i = 0;i<amount;i++){
				cout << "Item" << i+1 << ':' << endl;
				cin>>item;
				PC.enqueue(item);
			}
		}
		if(input == 2){
			cout << "Enter the number of items to be consumed:" << endl;
			cin>>amount;
			for(int i = 0; i<amount;i++){
				if(PC.isEmpty()== true){
					cout << "No more items to consume from queue" << endl;
					break;
				}
				else{
					cout << "Consumed: " << PC.peek() << endl;
					PC.dequeue();
				}

			}

		}
		if(input == 3){
			cout << "Number of items in the queue:" << PC.queueSize() << endl;
		}
	}	
}
