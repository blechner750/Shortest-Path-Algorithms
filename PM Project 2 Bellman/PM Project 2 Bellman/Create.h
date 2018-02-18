#pragma once
#include "Header.h"
#include <random>

vector< list< pair<int, int> > > createList() {

	mt19937 rng;
	rng.seed(random_device()());
	uniform_int_distribution<int> gen(0, 5);
	uniform_int_distribution<int> random1(0, 63);
	uniform_int_distribution<int> random2(0, 127);
	uniform_int_distribution<int> random3(0, 255);
	uniform_int_distribution<int> random4(0, 511);
	uniform_int_distribution<int> random5(0, 1023);
	uniform_int_distribution<int> random6(0, 2047);
	uniform_int_distribution<int> random7(0, 4095);
	uniform_int_distribution<int> random8(0, 8191);

	int r = gen(rng);

	int sizeArray[8] = { 64,128,256,512,1024,2048,4096,8192 };
	
	

	uniform_int_distribution<int> seed(0, 7);

	int s = seed(rng);
	int size = sizeArray[s];

	vector< list< pair<int, int> > > adjacencylist;

	
	adjacencylist.resize(size);
	

	vector<vector<double>> matrix;

	matrix.resize(size);

	int w = 0, v = 0;

	for (int i = 0; i < size; i++) {
		matrix[i].resize(size);
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			r = gen(rng);
			matrix[i][j] = r;
		}
	}

	if (size == 64) {
		for (int x = 0; x < size; x++) {
			for (int y = 1; y < size / 10; y++) {
				v = random1(rng);
				w = matrix[x][y];
				if (w == 0) {
					continue;
				}
				adjacencylist[x].push_back(make_pair(v, w));
			}
		}
	}
	if (size == 128) {
		for (int x = 0; x < size; x++) {
			for (int y = 1; y < size / 20; y++) {
				v = random2(rng);
				w = matrix[x][y];
				if (w == 0) {
					continue;
				}
				adjacencylist[x].push_back(make_pair(v, w));
			}
		}
	}
	if (size == 256) {
		for (int x = 0; x < size; x++) {
			for (int y = 1; y < size / 40; y++) {
				v = random3(rng);
				w = matrix[x][y];
				if (w == 0) {
					continue;
				}
				adjacencylist[x].push_back(make_pair(v, w));
			}
		}
	}
	if (size == 512) {
		for (int x = 0; x < size; x++) {
			for (int y = 1; y < size / 80; y++) {
				v = random4(rng);
				w = matrix[x][y];
				if (w == 0) {
					continue;
				}
				adjacencylist[x].push_back(make_pair(v, w));
			}
		}
	}
	if (size == 1024) {
		for (int x = 0; x < size; x++) {
			for (int y = 1; y < size / 160; y++) {
				v = random5(rng);
				w = matrix[x][y];
				if (w == 0) {
					continue;
				}
				adjacencylist[x].push_back(make_pair(v, w));
			}
		}
	}
	if (size == 2048) {
		for (int x = 0; x < size; x++) {
			for (int y = 1; y < size / 320; y++) {
				v = random6(rng);
				w = matrix[x][y];
				if (w == 0) {
					continue;
				}
				adjacencylist[x].push_back(make_pair(v, w));
			}
		}
	}
	if (size == 4096) {
		for (int x = 0; x < size; x++) {
			for (int y = 1; y < size / 640; y++) {
				v = random7(rng);
				w = matrix[x][y];
				if (w == 0) {
					continue;
				}
				adjacencylist[x].push_back(make_pair(v, w));
			}
		}
	}
	if (size == 8192) {
		for (int x = 0; x < size; x++) {
			for (int y = 1; y < size / 1280; y++) {
				v = random8(rng);
				w = matrix[x][y];
				if (w == 0) {
					continue;
				}
				adjacencylist[x].push_back(make_pair(v, w));
			}
		}
	}
	return adjacencylist;
}