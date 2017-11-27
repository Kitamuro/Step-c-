#include<iostream>
using namespace std;
/*
class String{
    int size;
    char *stroka;
public:
    explicit String(){
        size = 80;
        stroka = new char[size];
    }
    explicit String(int size){
        this->size= size;
        stroka = new char[size];
    }
    //Copy constructor
    explicit String(const String &s){
        this->size = s.size;
        *stroka = *s.stroka;
    }
    ~String(){
        delete stroka;
    }
    int getSize(){
        return size;
    }
    void setStroka(){
        for(int i = 0 ; i <size; i++){
            cin>>stroka[i];
        }
    }
    void getStroka(){
        for(int i = 0 ; i < size; i++){
            cout<<stroka[i]<<" ";
        }
    }
};
 */
/*
class Array{
    int size;
    int *value;
    static int index;
public:
    Array(int size){
        this->size = size;
        value = new int[size];
        index = 0;
    }
    Array(const Array &ar){
        this->size = ar.size;
        this->index = ar.index;
        this->value = ar.value;
    }
    ~Array(){
        delete value;
    }
    void setSize(int size){
        this->size = size;
    }
    void getValue(){
        for(int i = 0; i < size; i++){
            cout<<value[i]<<" ";
        }
        cout<<endl;
    }
    void add(int val){
        value[index] = val;
        index++;
    }
    void changeSize(int size){
        if(this->size > size){
            cout<<"Your size is less than current"<<endl;
        }else{
            this->size = size;
            delete value;
            value = new int[size];
        }
    }
    void BubbleSort(){
        int temp;
        for(int i = 0 ; i < size - 1; i++){
            for(int j = 0; j < size-1; j++){
                if(value[j] > value[j+1]){
                    temp = value[j];
                    value[j] = value[j+1];
                    value[j+1] = temp;
                }
            }
        }
    }
    void findMinMax(){
        int max = INT_MIN;
        int min = INT_MAX;
        for(int i = 0 ; i < size; i++){
            if(value[i] > max){
                max = value[i];
            }else if(value[i] < min){
                min = value[i];
            }
        }
        cout<<"Min value is: "<<min<<endl;
        cout<<"Max value is: "<<max<<endl;
    }
};
*/

class Book{
    string *autor;
    string *name;
    string *publishing;
    int *year;
    int *amount;
public:
    
};

int main(){
}
