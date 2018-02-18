#pragma once

#include <cstdio>
#include <climits>
#include <vector>
#include <list>
#include <utility>
#include <iostream>
using namespace std;


void bellmanFord( vector< list< pair<int, int> > > adjList, int vert, int startVertex, vector< pair<int, int> > & distances) {
	list< pair<int, int> >::iterator traverse;
	int i;

	for (i = 0; i <= vert; ++i) {
		distances[i].first = INT_MAX;
		distances[i].second = -1;
	}

	
	distances[startVertex].first = 0;
	distances[startVertex].second = 0;

	for (i = 0; i <= vert - 1; ++i) {
		for (int j = 0; j <= vert; ++j) {

			traverse = adjList[j].begin();

			while (traverse != adjList[j].end()) {
				if (distances[j].first == INT_MAX) {
					++traverse;
					continue;
				}

				if ( (*traverse).second + distances[j].first < distances[(*traverse).first].first) {
					distances[(*traverse).first].first = (*traverse).second + distances[j].first;
					distances[(*traverse).first].second = j;
				}
				++traverse;
			} //end while
		}//end j for
	}//end i for
}//end bellmanFord
