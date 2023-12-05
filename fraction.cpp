#include <iostream>
#include <sstream>
#include <stack>
#include <utility>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

pair<int, int> reduce(int numerator, int denominator) {
    int d = gcd(numerator, denominator);
    numerator /= d;
    denominator /= d;
    return make_pair(numerator, denominator);
}

int main() {
    int length;
    cin >> length;
    cin.ignore(); 

    string input;
    getline(cin, input);
    stringstream ss(input);
    stack<pair<int, int>> s;

    char token;
    while (ss >> token) {
        if (token == '(') {
            continue;
        }
        else if (token == ')') {
            auto third = s.top(); s.pop();
            auto second = s.top(); s.pop();
            auto first = s.top(); s.pop();

            pair<int, int> result;
            result = reduce(
                first.first * second.second * third.first + second.first * first.second * third.second,
                third.first * first.second * second.second
            );
            s.push(result);
        }
        else {
            ss.unget();
            int number;
            ss >> number;
            s.push(make_pair(number, 1));
        }
    }

    if (!s.empty()) {
        auto result = s.top();
        cout << result.first << " " << result.second << endl;
    }

    return 0;
}
