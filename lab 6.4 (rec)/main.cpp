#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void initialization(int* n, const int length, const int low, const int high, int i);
void print(int* n, const int length, int i);
int multiplication(int* n, const int length, int i);
int sum(int* n, int i, int finish);
void sort(int* n, const int length, int i, int j, int &k);
int defineStart(int* n, const int length, int i);
int defineFinish(int* n, const int length, int i);

int main()
{
    int n;
    srand((unsigned)time(NULL));
    int Low = -3;
    int High = 3;
    cout << "n = "; cin >> n;
    int* a = new int[n];
    initialization(a, n , Low, High, 0);
    print(a, n, 0);
    int start = defineStart(a, n, 0), finish = defineFinish(a, n, n-1);
    cout << "Добуток: " << multiplication(a, n, 0) << endl;
    cout << "Сума: " << sum(a, start, finish) << endl;
    int k = 0;
    sort(a, n, 1, 0, k);
    print(a, n, 0);
    delete[] a;
    return 0;
}
void initialization(int* n, const int length, const int low, const int high, int i)
{
    n[i] = low + rand() % (high - low + 1);
    if(i < length - 1)
        initialization(n, length, low, high, i+1);
}
void print(int* n, const int length, int i)
{
    cout << setw(4) << n[i];
    
    if(i < length - 1)
        print(n, length, i + 1);
    else
        cout << endl;
}
int multiplication(int* n, const int length, int i)
{
    if(i < length)
        return n[i]*multiplication(n, length, i+2);
    else
        return 1;
}
int sum(int* n, int i, int finish)
{
    if(i<finish)
        return n[i] + sum(n, i+1, finish);
    else
        return 0;
}
void sort(int* n, const int length, int i, int j, int &k)
{
    if (n[j]<n[j+1])
    {
        int tmp = n[j];
        n[j] = n[j+1];
        n[j+1] = tmp;
        k=1;
    }
    if (j<length-i-1)
        sort(n, length, i, j+1, k);
    if (k==0)
        return;
    if (i<length-1)
    {
    k=0;
    sort(n, length, i+1, 0, k);
    }

}
int defineStart(int* n, const int length, int i)
{
    if(n[i] == 0)
        return i;
    else
       return defineStart(n, length, i+1);
}
int defineFinish(int* n, const int length, int i)
{
    if(n[i] == 0)
        return i;
    else
        return defineFinish(n, length, i-1);
}

