#include <iostream>
#include <cstring>
using namespace std;
#define inf 999999
#define INF 9999999
#define V 8

int G[V][V] = {
    {0, 2, inf, 8, 2, inf, inf, inf }, //1
    {2, 0, 3, 10, 5, inf, inf, inf },  //2
    {inf, 3, 0, inf, 12, inf, inf, 7 },//3
    {8, 10, inf, 0, 14, 3, 1, inf},    //4
    {2, 5, 12, 14, 0, 11, 4, 8},     //5
    {inf, inf, inf, 3, 11, 0, 6, inf}, //6 
    {inf, inf, inf, 1, 4, 6, 0, 9},    //7
    {inf, inf, 7, inf, 8, inf, 9, 0}   //8
};

int main() {

    int no_edge = 0; 
    int selected[V];
    memset(selected, false, sizeof(selected));
    selected[0] = true;

    int x;         
    int y;           
    int summ = 0;
   
    while (no_edge < V - 1) {

        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j]) { 
                        if (min > G[i][j]) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }

                    }
                }
            }
        }
        cout << x+1 << " - " << y+1 << " :  " << G[x][y];
        summ += G[x][y];
        cout << endl;
        selected[y] = true;
        no_edge++;
    }
    cout << "symma: " << summ;
    return 0;
}