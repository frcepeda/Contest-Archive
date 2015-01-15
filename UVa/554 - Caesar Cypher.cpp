#include <iostream>
#include <set>
#include <string>

using namespace std;

set<string> dict;

int toDig(char x){
	return isalpha(x) ? x - 'A' + 1: 0;
}

char fromDig(int x){
	return x ? x + 'A' - 1 : ' ';
}

int main() {
	string str;
	
	while (getline(cin, str), str[0] != '#')
		dict.insert(str);
		
	getline(cin, str);
	
	int bestmatches = 0;
	string b;
	
	for (int k = 0; k < 27; k++){
		string x = str;
		
		for (int j = 0; j < x.length(); j++)
			x[j] = fromDig((toDig(x[j]) + k) % 27);
		
		int matches = 0, l;
		for (int i = 0; i < x.length(); i += l+1){
			
			for (l = 1; i+l < x.length() && x[i+l] != ' '; l++);
			
			if (dict.find(x.substr(i, l)) != dict.end())
					matches++;
		}
		
		if (matches > bestmatches){
			bestmatches = matches;
			b = x;
		}
	}
	
	int i, l, soFar = 0;
	string bef = "";
	
	for (i = 0; i < b.length(); i += l+1){
		for (l = 1; i+l < b.length() && b[i+l] != ' '; l++);
		
		if (soFar + l + bef.length() > 60){
			cout << '\n';
			bef = "";
			soFar = 0;
		}
		
		soFar += l + bef.length();
		cout << bef << b.substr(i, l);
		bef = " ";
	}
	
	cout << '\n';
}