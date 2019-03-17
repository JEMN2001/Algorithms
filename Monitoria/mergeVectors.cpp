#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeVectors(vector<int> & vec1, vector<int> & vec2);
void mergeVectors_helper(vector<int> & vec1, vector<int> & vec2, size_t i, size_t j, vector<int> & out);

int main() {
	vector<int> vec1 = {1, 3, 5, 7, 9}, vec2 = {0, 2, 4, 6, 8};
	vector<int> merged = mergeVectors(vec1, vec2);
	cout << "| ";
	for (auto iter = merged.cbegin(); iter != merged.cend(); ++iter) {
		cout << *iter << " | ";
	}
	cout << endl;
	return 0;
}

vector<int> mergeVectors(vector<int> & vec1, vector<int> & vec2) {
	vector<int> out;
	mergeVectors_helper(vec1, vec2, 0, 0, out);
	return out;
}

void mergeVectors_helper(vector<int> & vec1, vector<int> & vec2, size_t i, size_t j, vector<int> & out) {
	size_t v1 = i, v2 = j;
	if (v1 >= vec1.size()) {
		for (;v2 < vec2.size(); ++v2) {
			out.push_back(vec2.at(v2));
		}
		return;
	}
	if (v2 >= vec2.size()) {
		for (;v1 < vec2.size(); ++v1) {
			out.push_back(vec1.at(v1));
		}
		return;
	}
	bool tmp = (vec1.at(v1) < vec2.at(v2)) ? true : false;
	if (tmp) {
		out.push_back(vec1.at(v1));
		mergeVectors_helper(vec1, vec2, i+1, j, out);
	}
	else {
		out.push_back(vec2.at(v2));
		mergeVectors_helper(vec1, vec2, i, j+1, out);
	}
}