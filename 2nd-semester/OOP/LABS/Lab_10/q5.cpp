#include <iostream>
#include <string>

using namespace std;

// A simple queue for print jobs.
// Queue works on FIFO: First In, First Out.
// That means the first job added is the first one printed.
class PrintQueue {
private:
	static const int MAX_SIZE = 100;
	string jobs[MAX_SIZE];
	int front;
	int rear;

public:
	PrintQueue() {
		front = 0;
		rear = -1;
	}

	// Check whether the queue has no jobs.
	bool isEmpty() const {
		return front > rear;
	}

	// Check whether the queue is full.
	bool isFull() const {
		return rear == MAX_SIZE - 1;
	}

	// Add a new job at the back of the queue.
	void enqueue(const string& job) {
		if (isFull()) {
			cout << "Queue is full. Cannot add more print jobs.\n";
			return;
		}

		rear++;
		jobs[rear] = job;
		cout << "Job added: " << job << '\n';
	}

	// Remove the job from the front of the queue.
	void dequeue() {
		if (isEmpty()) {
			cout << "No jobs left in the queue.\n";
			return;
		}

		cout << "Printing job: " << jobs[front] << '\n';
		front++;
	}

	// Show the job at the front without removing it.
	string peek() const {
		if (isEmpty()) {
			return "";
		}
		return jobs[front];
	}
};

int main() {
	PrintQueue printerQueue;

	int numberOfJobs;
	cout << "Enter number of print jobs: ";
	cin >> numberOfJobs;

	cin.ignore();

	// Step 1: Add all arriving print jobs into the queue.
	for (int i = 1; i <= numberOfJobs; i++) {
		string jobName;
		cout << "Enter name for job " << i << ": ";
		getline(cin, jobName);
		printerQueue.enqueue(jobName);
	}

	cout << "\nPrinter starts processing jobs...\n";

	// Step 2: Keep printing until the queue becomes empty.
	while (!printerQueue.isEmpty()) {
		cout << "Current job at front: " << printerQueue.peek() << '\n';
		printerQueue.dequeue();
	}

	cout << "\nAll print jobs have been completed.\n";
	return 0;
}
