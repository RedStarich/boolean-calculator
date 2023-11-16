#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of variables"<<endl;
    cin >> n;
    char var[] = {'a', 'b', 'c', 'd'};
    string expression;
    for (int i=0; i<n; i++) {
        cout << "Enter expression using a, b, c, d "<< i+1<<endl;
        cout << "To make AND statement, use *"<<endl;
        cout<< "To make OR statement, use +"<<endl;
        cout << "To make NOT statement, use ' above the variable, i.e. a', b', c', d'"<<endl;
        cout << "To finish expression, enter 'finish'"<<endl;
    }
    string tmp;
    vector <string> minterm;
    vector <string> oper;
    while (tmp != "finish") {
        cin >> tmp;
        if ((tmp=="+")|(tmp=="*")) {
            oper.push_back(tmp);
        } else {
            minterm.push_back(tmp);
        }
    }

    
}