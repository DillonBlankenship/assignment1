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
    contents = new T[arrayLength];
    front = 0;
    rear = 0;
}
template <class T>
myQueue<T>::~myQueue() {
	// TODO
	delete contents;
}

template <class T>
void myQueue<T>::enqueue(T item) {
	// TODO
	if(isFull() == false)
    {
	    rear++;
	    //Implement for loop to move contents to right once
	    for(int current = rear; current > 0; current--)
        {
	        contents[current] = contents[current -1];
        }
	    //Insert new element into the front of array
	    contents[front] = item;
    }
    else
    {
        cout << "Cannot enqueue. The queue is full. " << endl;
    }
}

template <class T>
T myQueue<T>::dequeue() {
	// TODO
	if(isEmpty() == false){
	    //Move rear index down once then return contents of that index
	    rear--;
	    return contents[rear];

	}
}

template <class T>
int myQueue<T>::currentSize() {
	// TODO
    return rear -1;
}

template <class T>
bool myQueue<T>::isEmpty() {
	// TODO
	if(rear = 0){
	    return true;
	}
    else{
        return false;
    }
}
template <class T>
bool myQueue<T>::isFull() {
	// TODO
    if(rear == arrayLength){
        return true;
    }
    else{
        return false;
    }
}

#endif