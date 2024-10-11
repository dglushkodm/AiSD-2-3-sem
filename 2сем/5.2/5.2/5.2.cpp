#include <vector>
#include <algorithm>
#include <iostream>

#define V 8

int matrix[V][V] = { { INT_MAX,  2,  INT_MAX,  8,  2,  INT_MAX,  INT_MAX, INT_MAX },
				 { 2,  INT_MAX,  3, 10,  5,  INT_MAX,  INT_MAX, INT_MAX },
				 { INT_MAX,  3,  INT_MAX,  INT_MAX, 12,  INT_MAX,  INT_MAX, 7 },
				 { 8, 10,  INT_MAX,  INT_MAX, 14,  3,  1, INT_MAX },
				 { 2,  5, 12, 14,  INT_MAX, 11,  4, 8 },
				 { INT_MAX,  INT_MAX,  INT_MAX,  3, 11,  INT_MAX,  6, INT_MAX },
				 { INT_MAX,  INT_MAX,  INT_MAX,  1,  4,  6,  INT_MAX, 9 },
				 { INT_MAX,  INT_MAX,  7,  INT_MAX,  8,  INT_MAX,  9, INT_MAX } };

using namespace std;

void KruskalAlgorithm() {
	vector <int> visited;
	vector <int> min_distanses;

	do {
		int minimum = INT_MAX;
		int j_of_min_rib = INT_MAX;
		int i_of_min_rib;
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				auto iter = find(visited.begin(), visited.end(), i);

				if (minimum > matrix[i][j] && iter == visited.end()) {
					minimum = matrix[i][j];
					j_of_min_rib = j;
					i_of_min_rib = i;
				}
			}
		}

		min_distanses.push_back(minimum);
		matrix[j_of_min_rib][i_of_min_rib] = INT_MAX;
		matrix[i_of_min_rib][j_of_min_rib] = INT_MAX;
		visited.push_back(i_of_min_rib);
		cout << i_of_min_rib + 1 << " - " << j_of_min_rib + 1 << ":  " << minimum << endl;
	} while (min_distanses.size() != V - 1);
	int sum = 0;

	for (auto i = 0; i < min_distanses.size(); i++) {
		sum += min_distanses[i];
	}
	cout << sum;
}


int main()
{
	setlocale(LC_ALL, "rus");
	KruskalAlgorithm();

	return 0;
}