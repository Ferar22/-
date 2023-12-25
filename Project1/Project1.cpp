#include <iostream>
using namespace std;

void reverse (const char* str) {
    if (*str == '\0') {
        return; 
    }

    reverse(str + 1);

    cout << *str;
}
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode* nextNode = head->next;
    head->next = swapPairs(nextNode->next);
    nextNode->next = head;
    return nextNode;
}


void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
int climbStairs(int n2) {
    if (n2 <= 1) {
        return 1;
    }
    else {
        return climbStairs(n2 - 1) + climbStairs(n2 - 2);
    }
}
double myPow(double x, int n) {
    if (n == 0) {
        return 1.0;
    }
    if (n == 1) {
        return x;
    }
    if (n % 2 != 0) {
        double halfPow = myPow(x, (n - 1) / 2);
        return x * halfPow * halfPow;
    }
    double halfPow = myPow(x, n / 2);
    return halfPow * halfPow;
}
int main(int argc, char* argv[]) {
    cout << "Task 1 \n";
    const char* inputString = "tiger";

    reverse (inputString);

    cout << endl;
    cout << "\n Task 2 \n";
    cout << "(0 to end)List = ";

    ListNode* head = nullptr;
    ListNode* current = nullptr;

    int value;
    while (cin >> value && value != 0) {
        if (head == nullptr) {
            head = new ListNode(value);
            current = head;
        }
        else {
            current->next = new ListNode(value);
            current = current->next;
        }
    }
    head = swapPairs(head);
    cout << "List = ";
    printList(head);
    cout << "\n Task 3 \n";
    cout << "n =  ";
    int n;
    cin >> n;
    int result = fibonacci(n);
    cout << "F(" << n << ") = " << result << endl;
    cout << "\n Task 4 \n";
    cout << "n = ";
    int n2;
    cin >> n2;
    int result2 = climbStairs(n2);
    cout << "result = " <<  result2 << endl;
    cout << "\n Task 5 \n";
    cout << "x = ";
    double x;
    cin >> x;
    std::cout << "n = ";
    int n3;
    cin >> n3;
    double result3 = myPow(x, n3);
    cout << "result = " << result3 << endl;


    return 0;
}