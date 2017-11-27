#include<iostream>
using namespace std;
class Integer{
public:
    int value;
    Integer(int x):value(x){}
    const Integer &operator =(const Integer & integer){
        cout<<"Operator is overload"<<endl;
        value = integer.value;
        return *this;
    }
    const Integer &operator++(){ //++A
        value++;
        return *this;
    }
    const Integer operator++(int){ //A++
        Integer temp = *this;
        ++(*this);
        return temp;
    }
     const Integer operator&(){
         return value;
    }
};
    
int main(){
    
}
