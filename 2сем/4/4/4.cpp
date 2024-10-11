#include <iostream>
using namespace std;
const int maxV = 1000;
int i, j, n;
int GR[maxV][maxV];
int S[maxV][maxV];
int GR1[maxV][maxV] = {
	{0, 28, 21, 59, 12, 27},
	{7, 0, 24, INT_MAX, 21, 9},
	{9, 32, 0, 13, 11, INT_MAX},
	{8, INT_MAX, 5, 0, 16, INT_MAX},
	{14, 13, 15, 10, 0, 22},
	{15, 18, INT_MAX, INT_MAX, 6, 0}
};
void FUCK(int D[][maxV], int V)
{
	int k;
	for (i = 0; i < V; i++) {
		D[i][i] = 0;
		for (j = 0; j < V; j++) {
			if (i == j) {
				S[i][j] = 0;
			}
			else
				S[i][j] = j + 1;
		}
	}
		

	for (k = 0; k < V; k++)
		for (i = 0; i < V; i++)
			for (j = 0; j < V; j++)
				if (D[i][k] && D[k][j] && i != j)
					if (D[i][k] + D[k][j] < D[i][j] || D[i][j] == 0) {
						D[i][j] = D[i][k] + D[k][j];
						S[i][j] = S[i][k];
					}
					


	for (i = 0; i < V; i++)
	{
		for (j = 0; j < V; j++) cout << D[i][j] << "\t";
		cout << endl;
	}
}
void main()
{
	setlocale(LC_ALL, "Rus");
	//cout << "Количество вершин в графе > "; cin >> n;
	//cout << "Введите матрицу весов ребер:\n";
	//for (i = 0; i < n; i++)
		//for (j = 0; j < n; j++)
		//{
			//cout << "GR[" << i + 1 << "][" << j + 1 << "] > ";
			//cin >> GR[i][j];
		//}
	cout << "Матрица кратчайших путей:" << endl;
	FUCK(GR1, 6);
	cout << "Матрица последовательности вершин:" << endl;
	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 6; j++) cout << S[i][j] << "\t";
		cout << endl;
	}
}