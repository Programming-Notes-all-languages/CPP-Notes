#include "CalcList.hpp"
using namespace std;

CalcList calc;

void newOperation(string operation, double value) {
    try {
        if (operation == "addition") {
            calc.newOperation(ADDITION, value);
        } else if (operation == "subtraction") {
            calc.newOperation(SUBTRACTION, value);
        } else if (operation == "multiplication") {
            calc.newOperation(MULTIPLICATION, value);
        } else {
            calc.newOperation(DIVISION, value);
        }
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
}

void removeLastOperation() {
    try {
        calc.removeLastOperation();
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
}

void test() {
    int options;
    cin >> options;
    if (options == 0) {
        cout << calc.total() << endl;
        return;
    }
    for (int i = 0; i < options; i++) {
        string option;
        cin >> option;
        if (option == "newOperation") {
            string operation;
            double value;
            cin >> operation >> value;
            newOperation(operation, value);
        } else {
            removeLastOperation();
        }
    }
    cout << calc.toString(2) << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int testCases = 1;
    while (testCases--) {
        test();
    }
    return 0;
}

