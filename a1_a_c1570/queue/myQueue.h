#ifndef _MYQUEUE_H_
#define _MYQUEUE_H_

using namespace std;

template <class T>
class myQueue {
public:
	myQueue(int maxSz);
	~myQueue();
	void enqueue(T item);
	T dequeue();
    int currentSize();
    bool isEmpty();
    bool isFull();

private:
	T *contents; /*Dynamic initiate (C++ keyword new) the holder array*/
	int front,rear;  /*Index in the array of the front and rear element*/
	int arrayLength;  /*The length of the contents holder array*/
		/* Keep in mind that the Queue will only hold up to (arrayLength - 1) elements*/
};

template <class T>
myQueue<T>::myQueue(int maxSz) {
	arrayLength = maxSz;
	contents = new T[arrayLength - 1];
	front = 0;
	rear = -1;
}

template <class T>
myQueue<T>::~myQueue() {
        delete []contents;
}

template <class T>
void myQueue<T>::enqueue(T item) {
	++rear;
	contents[rear] = item;
}

template <class T>
T myQueue<T>::dequeue() {
	T item = contents[front];
	++front;
	return item;
}

template <class T>
int myQueue<T>::currentSize() {
    return rear;
}

template <class T>
bool myQueue<T>::isEmpty() {
    int index = this -> currentSize();

	if (front == -1 && index == -1){
        return 1;
	}else if (front > index){
	    return 1;
	}else{
	    return 0;
	}
}

template <class T>
bool myQueue<T>::isFull() {
    int index = this -> currentSize();

	if (index >= (arrayLength - 1)){
        return 1;
	}else{
	    return 0;
	}
}

#endif
