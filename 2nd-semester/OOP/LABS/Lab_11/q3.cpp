#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;


// You are given N integers. Store N integers in a vector and write a function Sort for
// sorting the N integers and print the sorted order. Now use the sorting algorithms
// provided in STL for sorting the vector. Measure the time taken by the two methods for
// sorting the vector and print the results. [Hint: You can use built-in function time( ) or
// anyother built-in method for measuring the processing time of sorting operation.]

// Solution: implement a simple selection sort as the custom Sort function and compare
// its runtime with `std::sort` from the STL. We measure durations using
// `std::chrono::high_resolution_clock` and print timings in milliseconds.

// Selection sort: O(N^2) stable-ish simple algorithm — good for teaching but
// intentionally slower than the highly-optimized `std::sort`.
void selectionSort(vector<int> &a) {
    size_t n = a.size();
    for (size_t i = 0; i + 1 < n; ++i) {
        size_t minIdx = i;
        for (size_t j = i + 1; j < n; ++j) {
            if (a[j] < a[minIdx]) minIdx = j;
        }
        if (minIdx != i) swap(a[i], a[minIdx]);
    }
}

// Helper to print vector contents (but limit output for large N)
void printVector(const vector<int> &v) {
    const size_t limit = 100; // avoid flooding the console
    size_t n = v.size();
    if (n <= limit) {
        for (size_t i = 0; i < n; ++i) cout << v[i] << (i + 1 < n ? ' ' : '\n');
    } else {
        // print first and last few elements to show sorted order
        for (size_t i = 0; i < 10; ++i) cout << v[i] << ' ';
        cout << "... ";
        for (size_t i = n - 10; i < n; ++i) cout << v[i] << (i + 1 < n ? ' ' : '\n');
    }
}

int main_student_q3() {
    cout << "Enter number of integers N, then N integers (separated by spaces or newlines):\n";
    size_t N;
    if (!(cin >> N)) {
        cerr << "Invalid input for N\n";
        return 1;
    }

    vector<int> data;
    data.reserve(N);
    for (size_t i = 0; i < N; ++i) {
        int x; cin >> x;
        data.push_back(x);
    }

    // Make copies for fair comparison
    vector<int> a = data; // for custom selection sort
    vector<int> b = data; // for std::sort

    // Time selection sort
    auto t1 = chrono::high_resolution_clock::now();
    selectionSort(a);
    auto t2 = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> sel_ms = t2 - t1;

    // Time std::sort
    auto t3 = chrono::high_resolution_clock::now();
    sort(b.begin(), b.end());
    auto t4 = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> stl_ms = t4 - t3;

    // Output results
    cout << "\nSelection sort result (showing up to first/last elements):\n";
    printVector(a);
    cout << "\nstd::sort result (showing up to first/last elements):\n";
    printVector(b);

    // Verify correctness
    if (a == b) cout << "\nVerification: both methods produced IDENTICAL sorted vectors.\n";
    else cout << "\nVerification: results differ!\n";

    cout << "\nTimings:\n";
    cout << "  Selection sort: " << sel_ms.count() << " ms\n";
    cout << "  std::sort      : " << stl_ms.count() << " ms\n";

    return 0;
}

// Default main will call the student main. If you prefer to keep a stub, adapt accordingly.
int main() { return main_student_q3(); }