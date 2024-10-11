#include <iostream>
#include "vector"
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	int N;
	int inp;
	cout << "Введите размер последовательности: "; cin >> N;
	vector<int> line;
	for (int i = 0; i < N; i++)
	{
		cin >> inp;
		//inp = 1 + rand() % 100;
		line.push_back(inp);
		//cout << inp << " ";
	}
	cout << endl;
	int elemVal = -1;
	int length = 0;
	vector<int> lineLenght;

	for (int i = 0; i < N; i++)
	{
		if (line[i] > elemVal)
		{
			length++;
			lineLenght.push_back(length);
			elemVal = line[i];
		}
		else {
			lineLenght.push_back(length);
		}
	}
	int counter = 1;
	cout << endl << length << endl;
	for (int i = 0; i < lineLenght.size(); i++)
	{
		if (lineLenght[i] == counter)
		{
			cout << line[i] << " ";
			counter++;
		}
	}


}