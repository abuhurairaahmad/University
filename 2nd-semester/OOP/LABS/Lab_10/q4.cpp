#include <iostream>
#include <stdexcept>
// Why is this for?
// The <stdexcept> header is included to provide access to standard
// exception classes like std::underflow_error, which is used in the
// code to throw exceptions when trying to access elements from an
// empty queue. This allows for better error handling and makes the
// code more robust by providing informative error messages when
// invalid operations are attempted on the queue.

using namespace std;

// Abstract class template for 1D dynamic array behavior.
// It stores common data members and declares pure virtual functions.
template <typename T>
class DynamicArray {
protected:
	T* arr;          // pointer to dynamically allocated array
	int capacity;    // total slots available
	int count;       // current number of elements in the queue

public:
	// Constructor: create array with given initial capacity.
	DynamicArray(int initialCapacity = 5) {
		if (initialCapacity <= 0) {
			initialCapacity = 5;
		}
		capacity = initialCapacity;
		count = 0;
		arr = new T[capacity];
	}

	// Virtual destructor so derived class object cleans correctly.
	virtual ~DynamicArray() {
		delete[] arr;
	}

	// Pure virtual methods (must be implemented in derived class).
	virtual bool isFull() const = 0;
	virtual bool isEmpty() const = 0;
	virtual int size() const = 0;
	virtual T Front() const = 0;
	virtual T Rear() const = 0;
	virtual void enqueue(const T& value) = 0;
	virtual T dequeue() = 0;
	virtual void resize() = 0;
};

// Dynamic Queue class template inherited from abstract DynamicArray.
// This queue uses circular indexing for efficient enqueue/dequeue.
template <typename T>
class DynamicQueue : public DynamicArray<T> {
private:
	int frontIndex;  // points to front element
	int rearIndex;   // points to rear element

public:
	DynamicQueue(int initialCapacity = 5)
		: DynamicArray<T>(initialCapacity), frontIndex(0), rearIndex(-1) {}

	bool isFull() const override {
		return this->count == this->capacity;
	}

	bool isEmpty() const override {
		return this->count == 0;
	}

	int size() const override {
		return this->count;
	}

	T Front() const override {
		if (isEmpty()) {
			throw underflow_error("Queue is empty. No Front element.");
		}
		return this->arr[frontIndex];
	}

	T Rear() const override {
		if (isEmpty()) {
			throw underflow_error("Queue is empty. No Rear element.");
		}
		return this->arr[rearIndex];
	}

	void enqueue(const T& value) override {
		// If queue is full, increase capacity first.
		if (isFull()) {
			resize();
		}

		// Circular movement of rear index.
		rearIndex = (rearIndex + 1) % this->capacity;
		this->arr[rearIndex] = value;
		this->count++;
	}

	T dequeue() override {
		if (isEmpty()) {
			throw underflow_error("Queue is empty. Cannot dequeue.");
		}

		T removedValue = this->arr[frontIndex];

		// Circular movement of front index.
		frontIndex = (frontIndex + 1) % this->capacity;
		this->count--;

		// If queue becomes empty, reset indexes for cleaner state.
		if (this->count == 0) {
			frontIndex = 0;
			rearIndex = -1;
		}

		return removedValue;
	}

	void resize() override {
		// Double the capacity and copy elements in correct queue order.
		int newCapacity = this->capacity * 2;
		T* newArr = new T[newCapacity];

		// Copy from old array using circular indexing so order remains same.
		for (int i = 0; i < this->count; i++) {
			newArr[i] = this->arr[(frontIndex + i) % this->capacity];
		}

		delete[] this->arr;
		this->arr = newArr;
		this->capacity = newCapacity;

		// After copying in straight order, front becomes 0 and rear is count-1.
		frontIndex = 0;
		rearIndex = this->count - 1;
	}
};

int main() {
	try {
		DynamicQueue<int> q(5);

		// Enqueue some values.
		q.enqueue(3);
		q.enqueue(4);
		q.enqueue(5);
		q.enqueue(6);
		q.enqueue(7);
		q.enqueue(8);

		cout << "Queue size: " << q.size() << "\n";
		cout << "Front element: " << q.Front() << "\n";
		cout << "Rear element: " << q.Rear() << "\n\n";

		// Dequeue one value.
		cout << "Dequeued: " << q.dequeue() << "\n";
		cout << "New Front: " << q.Front() << "\n";
		cout << "Current size: " << q.size() << "\n\n";

		// Add another value (like the diagram, add 9 at rear).
		q.enqueue(9);
		cout << "After enqueue(9), Rear: " << q.Rear() << "\n";
		cout << "Final size: " << q.size() << "\n";
	}
	catch (const exception& e) {
		cout << "Error: " << e.what() << "\n";
	}

	return 0;
}

