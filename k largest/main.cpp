#include <iostream>
using namespace std;
#define MAX 1000

void heapify(int arr[], int n, int i)
{
    int parent = (i - 1) / 2;

    if (arr[parent] > 0) {
        if (arr[i] > arr[parent]) {
            swap(arr[i], arr[parent]);
            heapify(arr, n, parent);
        }
    }
}
void insertNode(int arr[], int& n, int Key)
{
    n = n + 1;
    arr[n - 1] = Key;
    heapify(arr, n, n - 1);
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
void printKLargest(int arr[], int k){
        for(int i=0;i<k;i++){
            cout<< arr[i] << " ";
        }
}
int main()
{
    int arr[MAX] = { 10, 5, 3, 2, 4 };
    int n = 5;
    int k;
    insertNode(arr,n,16);
    cout<< "Input k value: \n" ;
    cin >>k;
    printKLargest(arr,k);
    return 0;
}
