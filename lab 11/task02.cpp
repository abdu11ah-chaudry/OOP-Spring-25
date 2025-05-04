#include<iostream>
#include<exception>

using namespace std;

class qeueOverFlowException:public exception{
    //no overriding of what() as mentioned in the task.
};

class qeueUnderFlowException:public exception{
    //no overriding of what() as mentioned in the task.
};

template<typename T>
class Qeue{
private:
    int rear, front;
    int capacity, count;
    T* arr;
public:
    Qeue(int size):capacity(size),rear(0),front(0),count(0){
        arr=new T[capacity];
    }
    
    void enqeue(T value){
        if(capacity==count)
            throw qeueOverFlowException();
        arr[rear]=value;
        rear= (rear+1)%capacity;
        count++;
    }

    T deqeue(){
        if(count==0)
            throw qeueUnderFlowException();
        T value = arr[front];
        front = (front + 1) % capacity;
        count--;
        return value;
    }

    ~Qeue(){
        delete[] arr;
    }
};

int main(){

    Qeue<int> q(3);

    try{
        cout<<"Attempting to enqueue to a full queue..."<<endl;
        q.enqeue(1);
        q.enqeue(2);
        q.enqeue(3);
        q.enqeue(4);  // This should throw
    }

    catch(const qeueOverFlowException& e) {
        cout << "Caught QueueOverflowException what(): " << e.what()<<endl;
    }

    try{
        Qeue<int> emptyq(2);
        cout<<"Attempting to dequeue from an empty queue..."<<endl;
        emptyq.deqeue();  // This should throw
    }
    catch(const qeueUnderFlowException& e){
        cout<<"Caught QueueUnderflowException what(): "<<e.what()<<endl;
    }
    return 0;
}
