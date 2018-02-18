#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <limits>
#include <set>
#include <utility>
#include <algorithm>
#include <iterator>
#include <iomanip>
using namespace std;

typedef int vertex;
typedef double weight;

const weight max_weight = numeric_limits<double>::infinity();

struct neighbor {
	neighbor(vertex arg_target, weight arg_weight) {
		target = arg_target;
		wght = arg_weight;
	}
	vertex target;
	weight wght;

};

typedef vector<vector<neighbor>> adjacencyList;


void shortestPaths(vertex source, const adjacencyList &adjList) {

	int n = adjList.size();
	vector<weight> min_distance; vector<vertex> previous;
	vector<int> hops;
	min_distance.resize(n, max_weight);
	min_distance[source] = 0;
	previous.resize(n, -1);
	hops.resize(n);

	set<pair<weight, vertex> > queue;
	queue.insert(make_pair(min_distance[source], source));

	while (!queue.empty()) {
		weight dist = queue.begin()->first;
		vertex u = queue.begin()->second;
		queue.erase(queue.begin());

		const vector<neighbor> &nbs = adjList[u];
		for (vector<neighbor>::const_iterator nbs_iter = nbs.begin(); nbs_iter != nbs.end(); nbs_iter++) {
			vertex v = nbs_iter->target;
			weight wgt = nbs_iter->wght;
			weight distance = dist + wgt;
			
			if (distance < min_distance[v]) {
				queue.erase(make_pair(min_distance[v], v));
				min_distance[v] = distance;
				previous[v] = u;
				queue.insert(make_pair(min_distance[v], v));
			}//end if
		}//end for
	}//end while
	vertex vert = n-1;
	int hop=0;
	for (; vert!= -1; vert = previous[vert]) {
		hop++;
	}
	
	hop = hop - 1;

	for (int i = 0; i < min_distance.size(); i++) {
		if (i == (min_distance.size()) - 1) {
			cout << setw(6) << i+1 << setw(10) <<  min_distance[i] << setw(8) << hop;
		}
		
	}
}//end shortestPaths





