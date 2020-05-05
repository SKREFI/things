#include <bits/stdc++.h>
using namespace std;

int getRandom(int min, int max);
vector<int> range(int stop);
vector<int> range(int start, int stop);
vector<int> range(int start, int stop, int step);
template <class T>
T get(string prompt);
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v);
template <class T>
void print(T ret = "\n", string sep = "", string end = "\n");
template <typename T, typename S>
ostream &operator<<(ostream &out, const pair<T, S> &v);

void my_exit() {
    print("\n\n__-==DONE==-__");

    exit(1);
}

bool is_hole(vector<int> v, int i, int j) {
    for (int k = i + 1; k < j; k++) {
        if (!(v[i] > v[k] && v[k] < v[j])) return false;
    }
    return true;
}

int main() {
    vector<int> v{12, 1, 10, 3, 4, 11, 5, 8, 7, 9, 2, 6};
    vector<pair<int, int>> sol;
    for (int i = 0; i < v.size() - 2; i++) {
        for (int j = i + 2; j < v.size(); j++) {
            if (is_hole(v, i, j)) {
                sol.push_back(make_pair(v[i], v[j]));
            }
        }
    }
    
    print(sol);

    my_exit();
}

int getRandom(int min, int max) { return rand() % max + min; }
vector<int> range(int stop) {
    vector<int> ret;
    for (int i = 0; i < stop; i++) {
        ret.push_back(i);
    }
    return ret;
}
vector<int> range(int start, int stop) {
    vector<int> ret;
    for (int i = start; i < stop; i++) {
        ret.push_back(i);
    }
    return ret;
}
vector<int> range(int start, int stop, int step) {
    vector<int> ret;
    for (int i = start; i < stop; i + step) {
        ret.push_back(i);
    }
    return ret;
}
template <class T>
T get(string prompt) {
    cout << prompt;
    T ret;
    cin >> ret;
    return ret;
}
// Operator overloading pentru vectori, print vector adica :))
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    os << "V";
    os << v.size();
    os << ": [";
    for (int i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1) os << ", ";
    }
    os << "]";
    return os;
}
template <class T>
void print(T ret, string sep, string end) {
    cout << ret << sep << end;
}
template <typename T, typename S>
ostream &operator<<(ostream &out, const pair<T, S> &v) {
    out << "(";
    out << v.first << ", " << v.second << ")";
    return out;
}