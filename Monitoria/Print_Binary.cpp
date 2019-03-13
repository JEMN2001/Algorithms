#include <iostream>
#include <string>
using namespace std;


void printBinary_aux(int n);
void printBinary(int n);

string to_Binary(int n, string temp = "");

int main() {
  for (int i = -9; i < 11; ++i) {
    printBinary(i);
  }
  cout << "---------------------" << endl;
  for (int i = -9; i < 11; ++i) {
    string tmp = to_Binary(i);
    cout << tmp << endl;
  }
  return 0;
}

void printBinary(int n) {
    printBinary_aux(n);
    cout << endl;
}

void printBinary_aux(int n) {
  if (n < 0) {
    cout << "-";
    printBinary_aux(-1*n);
  }
  else if (n == 0 || n == 1) {
    cout << n;
  }
  else {
    printBinary_aux(n/2);
    cout << n%2;
  }
}

string to_Binary(int n, string temp) {
  string out = temp;
  if (n < 0) {
    out = "-";
    out.append(to_Binary(-1*n));
    return out;
  }
  else if (n == 0 || n == 1) {
    out.append(to_string(n));
    return out;
  }
  else {
    out = to_Binary(n/2, out);
    out.append(to_string(n%2));
    return out;
  }
}
