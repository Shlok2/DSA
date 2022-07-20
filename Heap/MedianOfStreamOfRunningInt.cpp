
// Input : 5 10 15 Output : 5, 7.5, 10
// Explanation: Given the input stream as an array of integers [5,10,15]. Read integers one by one and print the median
// correspondingly. So, after reading first element 5,median is 5. After reading 10,median is 7.5 After reading 15 ,median is 10.

// Steps:
// 1) Create two heaps. One max heap to maintain elements of lower half and one min heap to maintain elements of higher half at any point of time.
// 2) Take initial value of median as 0.
// 3) For every newly read element, insert it into either max heap or min-heap and calculate the median based on the following conditions:
//   A)  If the size of max heap is greater than the size of min-heap and the element is less than the previous median then pop the top element
//     from max heap and insert into min-heap and insert the new element to max heap else insert the new element to min-heap.
//     Calculate the new median as the average of top of elements of both max and min heap.
//   B)  If the size of max heap is less than the size of min-heap and the element is greater than the previous median then pop the top element
//     from min-heap and insert into the max heap and insert the new element to min heap else insert the new element to the max heap. Calculate
//     the new median as the average of top of elements of both max and min heap.
//   C)  If the size of both heaps is the same. Then check if the current is less than the previous median or not. If the current element is less
//     than the previous median then insert it to the max heap and a new median will be equal to the top element of max heap. If the current element
//     is greater than the previous median then insert it to min-heap and new median will be equal to the top element of min heap.

#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

void printMedians(double arr[], int n)
{
    // max heap to store the smaller half elements
    priority_queue<double> s;

    // min heap to store the greater half elements
    priority_queue<double, vector<double>, greater<double>> g;

    double med = arr[0];
    s.push(arr[0]);

    cout << med << endl;

    for (int i = 1; i < n; i++)
    {
        double x = arr[i];

        // case1(left side heap has more elements)
        if (s.size() > g.size())
        {
            if (x < med)
            {
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else
                g.push(x);

            med = (s.top() + g.top()) / 2.0;
        }

        // case2(both heaps are balanced)
        else if (s.size() == g.size())
        {
            if (x < med)
            {
                s.push(x);
                med = (double)s.top();
            }
            else
            {
                g.push(x);
                med = (double)g.top();
            }
        }

        // case3(right side heap has more elements)
        else
        {
            if (x > med)
            {
                s.push(g.top());
                g.pop();
                g.push(x);
            }
            else
                s.push(x);

            med = (s.top() + g.top()) / 2.0;
        }

        cout << med << endl;
    }
}

// Driver program to test above functions
int main()
{
    double arr[] = {5, 15, 10, 20, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printMedians(arr, n);
    return 0;
}