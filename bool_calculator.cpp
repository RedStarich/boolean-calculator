#include <iostream>
#include <vector>
#include <set>
using namespace std;

string simplify_minterm(string a) {
    set <char> s (a.begin(), a.end());
    string b;
    for (set<char>::iterator it=s.begin(); it!= s.end(); ++it) {
        b.push_back(*it);
    }

    bool iszero = false;
    for (int i=0; i<b.size(); i++) {
        if (islower(b[i])) {
            for (int j=0; j<b.size(); j++) {
                if (toupper(b[i])==b[j]) {
                    iszero = true;
                }
            }
        }
    }
    if (iszero) {b = '0';}
    return b;
}

vector<string> copy_minterms(vector<string> &v) {
    set <string> s (v.begin(), v.end());
    vector <string> res;
    for (set<string>::iterator it=s.begin(); it!=s.end(); ++it) {
        if (*it != "0") {
        res.push_back(*it);
    }}    
    return res;
}

bool check_true (vector<string>&b) {

    for (int i=0; i<b.size(); i++) {
        if (b[i].length() == 1) {
            if (islower(b[i][0])) {
            for (int j=0; j<b.size(); j++) {

                if (toupper(b[i][0])==b[j][0]) {
                    return true;
                }
            }
        }
            
        }
    }
    return false;
}

int main() {
    string res;
    int n;
    cout << "Enter number of variables"<<endl;
    cin >> n;
    while ((n < 2)|(n>4)) {
        cout << "Number of variables cannot be less than 2 or more than 4"<<endl;
        cin >> n;
    }
    char var[] = {'a', 'b', 'c', 'd'};
    string expression;
    for (int i=0; i<n; i++) {
        cout << "Enter expression using a, b, c, d "<< i+1<<endl;
        cout << "To make NOT statement, use ' above the variable, i.e. A, B, C, D'"<<endl;
        cout << "To finish expression, enter 'finish'"<<endl;
    }
    string tmp;
    vector <string> minterm;
    while (tmp != "finish") {
        cin >> tmp;
        if (tmp =="finish") {break;}
        minterm.push_back(tmp);
    }

    for (int j=0; j<minterm.size(); j++)
    {
        cout << simplify_minterm(minterm[j])<<endl;
        minterm[j] = simplify_minterm(minterm[j]);
    }

    minterm = copy_minterms(minterm);

    if (check_true(minterm)) {
        res = "1";
        cout<<"DNF = " << res<<endl;
    }
    else {
        cout << "DNF = ";
    for (int i=0; i<minterm.size(); i++) {
        cout << minterm[i];
        if (i!=minterm.size()-1) {cout<<" + ";}
    }}

}