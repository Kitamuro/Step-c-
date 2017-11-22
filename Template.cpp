#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

template <class T>
T min(T &a, T &b){
    return a>b ? b:a;
}

template <class T>
void swap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
T arithmeticA(T a[], int num){
    double arithmeticNumber = 0;
    for(int i = 0; i < num; i++){
        arithmeticNumber += a[i];
    }
    return arithmeticNumber/num;
}

template <class T>
T max( T &a, T &b){
    return a>b ? a:b;
}

template <class T>
T bubbleSort(T arr[], int size){
    int temp;
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return *arr;
}

int main() {
    srand(time_t(NULL));
    /*
    int size;
    cin>>size;
    double a[size];
    for(int i = 0; i < size; i++){
    a[i] = rand()%100+1/((rand()%10+1)/10);
    cout<<a[i]<<endl;
    }
    cout<<endl;
    cout<<arithmeticA(a, size)<<endl;
     //
     
    int a,b;
    cin>>a>>b;
     cout<<"Max is: "<<max(a,b)<<endl;
    //
    int *arr;
    int size;
    cin>>size;
    arr = new int[size];
    for(int i = 0; i < size; i++){
        arr[i] = rand()%10+1;
        cout<<arr[i]<<endl;
    }
    cout<<endl;
    bubbleSort(arr, size);
    for(int i = 0 ; i <size; i++){
        cout<<arr[i]<<endl;
    }*/
}
