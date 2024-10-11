#include <Windows.h>
#include <iostream>
#include <vector>
#include <limits>
#include <math.h>
using namespace std;

void BackPack(const vector<int>& wts, const vector<int>& cost, const vector<string> name, int W);


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const vector<int> weight = { 15, 20, 35 };
    const vector<int> cost = { 15, 20, 35 };
    const vector<string> name = { "������", "����", "����" };
    int N;

    for (int i = 0; i < name.size(); i++)
    {
        cout << i + 1 << ")" << name[i] << ", ���������:" << cost[i] << ", ���:" << weight[i] << endl;
    }

    cout << "\n������� ������������ ������� �������: "; cin >> N;
    BackPack(weight, cost, name, N);

}


void BackPack(const vector<int>& weight, const vector<int>& cost, const vector<string> name, int size)
{
    int n = weight.size();
    vector<vector<int> > dp(size + 1, vector<int>(n + 1, 0));
    vector<string> names;

    for (size_t i = 1; i <= n; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            if (weight[i - 1] <= j)
            {
                if (dp[j][i - 1] > dp[j - weight[i - 1]][i - 1] + cost[i - 1])
                {
                    dp[j][i] = dp[j][i - 1];
                }
                else
                {
                    dp[j][i] = dp[j - weight[i - 1]][i - 1] + cost[i - 1];
                }
            }
            else
            {
                dp[j][i] = dp[j][i - 1];
            }
        }
    }
    /*for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < size + 1; j++)
        {
            cout << dp[j][i] << "\t";
        }
        cout << "\n";
    }*/

    /* bool* need = new bool[n];*/
    bool need[5];

    for (int i = 0; i < n; i++)
    {
        need[i] = true;
    }

    int i = n, j = size;
    while (true)
    {
        if (i == 0)
        {
            break;
        }
        if (dp[j][i] == dp[j][i - 1])
        {
            need[i - 1] = false;
            i--;
        }

        else
        {
            j -= weight[i - 1];
            i--;
        }
    }
    cout << "\n���� � �������: " << endl;
    for (int i = 0; i < n; i++)
    {
        if (need[i] == true)
        {
            cout << name[i] << " ";
        }
    }

    cout << "\n������������ ���������: " << dp[size][n] << endl;
}


