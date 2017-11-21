#include<iostream>
using namespace std;

class Entity {
protected:
    int id;
public:
    Entity() {
        
    }
    explicit Entity(int id) {
        this->id = id;
    }
    Entity(const Entity &entity) {
        setId(entity.id);
    }
    ~Entity() {
        
    }
    int getId() {
        return id;
    }
    void setId(int id) {
        this->id = id;
    }
};

class Operation :public Entity {
public:
    Operation * next;
    string name;
    int timestamp;
    explicit Operation(string name, int timestamp) {
        this->name = name;
        this->timestamp = timestamp;
    }
    Operation(const Operation &operat){
        this->name = operat.name;
        this->timestamp = operat.timestamp;
    }
    Operation() {
        
    }
    ~Operation() {
        delete next;
    }
};

class User :public Entity {
public:
    string firstName, secondName;
    Operation *firstoperation, *lastoperation;
    Entity *op;
    
    explicit User(string firstName, string secondName) {
        this->firstName = firstName;
        this->secondName = secondName;
    }
    User(){
        
    }
    ~User() {
        delete firstoperation;
        delete lastoperation;
        delete op;
    }
    
    void addOperation(string name, int timestamp) {
        Operation *temp = new Operation(name, timestamp);
        if (!firstoperation) {
            firstoperation = temp;
            lastoperation = temp;
        }
        else {
            lastoperation->next = temp;
            lastoperation = temp;
        }
    }
    void readOperation() {
        Operation *temp = firstoperation;
        while (temp) {
            cout <<"id: "<<op->getId()<< "timestamp: " << temp->timestamp << "name: " << temp->name << endl;
            temp = temp->next;
        }
    }
    void addUser(){
        string firstName, lastName;
        int c = 10000;
        cout<<"Input your first and last name: "<<endl;
        cin>>firstName>>lastName;
        this->firstName = firstName;
        this->secondName = lastName;
        op->setId(c);
        c++;
    }
};
int main()
{
    User *user1 = new User[100];
    int key;
    bool check = true;
    int i = 0, k = 0;
    cout << "Enter 1-to add user, 2-to add operation, 3-show operation" << endl;
    cin>>key;
    while(check){
    switch(key){
        case 1:{
            user1[i].addUser();
            i++;
            cout<<"Your id is: "<<user1[i].getId()<<endl;
        }
        case 2:{
            cout<<"Input name and time(UNIX)"<<endl;
            user1[i].readOperation();
            i++;
        }
        case 3:{
            cout<<"Input your id: "<<endl;
            cin>>k;
            for(int j = 0 ; j < i; j++){
                if(k == user1[i].getId()){
                    user1[j].readOperation();
                }
            }
        }
        case 4:
            check = true;
        default:
            break;
    }
    }
    delete [] user1;
}

