#include<iostream>
using namespace std;
class Array{
    int *arr;
public:
    static int count;
    Array(int i){
        arr = new int[i];
        count++;
    }
    Array(const Array & prevArray){
        arr = prevArray.arr;
    }
    Array(){
        
    }
    int getArray(){
        return *arr;
    }
    void setArray(int *arr){
        this->arr = arr;
    }
    ~Array(){
        delete arr;
    }
};
int main(){
    Array *r1 = new Array(2);
    Array *r2 = new Array(3);
    cout<<r2->count<<endl;
    delete r1;
    delete r2;
}

