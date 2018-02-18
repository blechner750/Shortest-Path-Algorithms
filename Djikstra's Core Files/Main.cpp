#include "Create.h"
#include <chrono>
int main() {
	//declare variables and intro message
	adjacencyList list2;

	cout << "Welcome to the Djikstra's algorithm test program!" << endl;
	cout << "This program will create 100 random graphs of random size between 64 and 8192 (2^x)" << endl;
	cout << "Then it will use Djikstra's algorithm to find shortest paths." << endl << endl;
	cout << "For simplicity, all destination nodes are the last node of the graph with the source as node 0\nOnly that distance will be displayed.\n" << endl;
	cout << "A heads up: For graphs of above 4096, the time needed to create the graphs is rather long.\nPlease be patience with the program." << endl;
	cout << "To set the sizes as less (and run the program quicker), in 'Create.h' \n  set the 'uniform_int_distribution<int> seed(0, 7)' to '(0,3)' " << endl;
	cout << "\nType 'start' and hit enter to start the program" << endl;
	string select;
	cin >> select;
	if (select != "start") {
		cout << "Well that doesn't seem to say 'start', but I'll run the program anyway." << endl << endl;
	}

	cout << "  Size     Distance   Hops     Time(ms)" << endl;
	//declare time variables
	auto start_time = chrono::high_resolution_clock::now();
	auto current_time = chrono::high_resolution_clock::now();

	for (int i = 0; i < 100; i++) {

		//Create List
		list2 = createList();

		start_time = chrono::high_resolution_clock::now();

		//Shortest Paths
		shortestPaths(0, list2);

		current_time = chrono::high_resolution_clock::now();
		cout << setw(10) << chrono::duration_cast<chrono::milliseconds>(current_time - start_time).count() << endl;
	}
	
	

	return 0;
}

