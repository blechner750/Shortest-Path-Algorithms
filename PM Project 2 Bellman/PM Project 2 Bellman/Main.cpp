#include "Create.h"
#include <iomanip>
#include <string>
#include <chrono>


int main()
{
	//declare variables and intro message
	vector< list< pair<int, int> > > adjacencyList;
	int vertices = 0;
	vector< pair<int, int> > distances;
	int startVertex;
	auto start_time = chrono::high_resolution_clock::now();
	auto current_time = chrono::high_resolution_clock::now();
	int j = 1, i = 1, y = 0;

	cout << "Welcome to the Bellman-Ford algorithm test program!" << endl;
	cout << "This program will create 100 random graphs of random size between 64 and 8192 (2^x)" << endl;
	cout << "Then it will use the Bellman-Ford algorithm to find shortest paths." << endl << endl;
	cout << "For simplicity, all destination nodes are the last node of the graph with the source as node 0\nOnly that distance will be displayed.\n" << endl;
	cout << "A heads up: For graphs of above 2048, the time needed to run the algorithm is on the order of minutes.\nPlease be patience with the program." << endl;
	cout << "To set the sizes as less (and run the program quicker), in 'Create.h' \n  set the 'uniform_int_distribution<int> seed(0, 7)' to '(0,3)' " << endl;
	cout << "\nType 'start' and hit enter to start the program" << endl;
	string select;
	cin >> select;
	
	if (select != "start") {
		cout << "Well that doesn't seem to say 'start', but I'll run the program anyway." << endl << endl;
	}

	cout << "ArraySize     Distance     Time     Hops" << endl;

	//100 Arrays Shortest Path and Output
	for (int x = 0; x < 100; x++) {

		//Create List and mark variables
		adjacencyList = createList();
		i = 1; j = 1; y = 0;
		vertices = adjacencyList.size();
		distances.resize(vertices);

		startVertex = 0;

		start_time = chrono::high_resolution_clock::now();

		//Compute distances
		bellmanFord(adjacencyList, vertices - 1, startVertex, distances);

		current_time = chrono::high_resolution_clock::now();

		//Find hops (available in distances[].second)
		j = distances[vertices - 1].second;

		if (distances[vertices - 1].first == 1) {
			i = 0; j = 0;
		}

		y = 1;
		while (i != 0 && j >= 0) {
			i = distances[j].second;
			y++;
			if (i == 0) {
				break;
			}
			j = distances[i].second;
			if (j == 0) {
				y++;
				break;
			}
		}
		
		//Cout for INF nodes (differ for ms and s)
		if (distances[vertices - 1].first > 10000000) {
			cout << setw(4) << vertices << setw(15) << "INF";
			if (chrono::duration_cast<chrono::milliseconds>(current_time - start_time).count() > 5000) {
				cout << setw(9) << chrono::duration_cast<chrono::seconds>(current_time - start_time).count()
					<< " s" << setw(11) << 0 << endl;
			}
			else {
				cout << setw(9) << chrono::duration_cast<chrono::milliseconds>(current_time - start_time).count()
					<< " ms" << setw(10) << 0 << endl;
			}

		}

		//Regular output (differ for ms and s)
		else if (chrono::duration_cast<chrono::milliseconds>(current_time - start_time).count() > 5000) {
			cout << setw(4) << vertices << setw(15) << distances[vertices - 1].first << setw(9) <<
				chrono::duration_cast<chrono::seconds>(current_time - start_time).count() << " s" << setw(11) << y << endl;
		}
		else {
			cout << setw(4) << vertices << setw(15) << distances[vertices - 1].first << setw(9) <<
				chrono::duration_cast<chrono::milliseconds>(current_time - start_time).count() << " ms" << setw(10) << y << endl;
		}
	}//end loop

	return 0;
}