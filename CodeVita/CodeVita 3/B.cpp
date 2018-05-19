#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

string d = "UDNEWS";

map<string,string> leftR;
map<string,string> frontM;

string turn(string x){
	return leftR[leftR[x]];
}

int main(){
	leftR.insert(make_pair("1U", "1W"));
	leftR.insert(make_pair("1W", "1D"));
	leftR.insert(make_pair("1D", "1E"));
	leftR.insert(make_pair("1E", "1U"));
	leftR.insert(make_pair("2U", "2S"));
	leftR.insert(make_pair("2S", "2D"));
	leftR.insert(make_pair("2D", "2N"));
	leftR.insert(make_pair("2N", "2U"));
	leftR.insert(make_pair("4U", "4E"));
	leftR.insert(make_pair("4E", "4D"));
	leftR.insert(make_pair("4D", "4W"));
	leftR.insert(make_pair("4W", "4U"));
	leftR.insert(make_pair("5U", "5N"));
	leftR.insert(make_pair("5N", "5D"));
	leftR.insert(make_pair("5D", "5S"));
	leftR.insert(make_pair("5S", "5U"));
	leftR.insert(make_pair("3N", "3W"));
	leftR.insert(make_pair("3W", "3S"));
	leftR.insert(make_pair("3S", "3E"));
	leftR.insert(make_pair("3E", "3N"));
	leftR.insert(make_pair("6N", "6E"));
	leftR.insert(make_pair("6E", "6S"));
	leftR.insert(make_pair("6S", "6W"));
	leftR.insert(make_pair("6W", "6N"));

	frontM.insert(make_pair("1U", "3N"));
	frontM.insert(make_pair("1W", "5N"));
	frontM.insert(make_pair("1D", "6N"));
	frontM.insert(make_pair("1E", "2N"));
	frontM.insert(make_pair("2U", "3W"));
	frontM.insert(make_pair("2S", "1W"));
	frontM.insert(make_pair("2D", "6W"));
	frontM.insert(make_pair("2N", "4W"));
	frontM.insert(make_pair("4U", "3S"));
	frontM.insert(make_pair("4E", "2S"));
	frontM.insert(make_pair("4D", "6S"));
	frontM.insert(make_pair("4W", "5S"));
	frontM.insert(make_pair("5U", "3E"));
	frontM.insert(make_pair("5N", "4E"));
	frontM.insert(make_pair("5D", "6E"));
	frontM.insert(make_pair("5S", "1E"));
	frontM.insert(make_pair("3N", "4D"));
	frontM.insert(make_pair("3W", "5D"));
	frontM.insert(make_pair("3S", "1D"));
	frontM.insert(make_pair("3E", "2D"));
	frontM.insert(make_pair("6N", "4U"));
	frontM.insert(make_pair("6E", "2U"));
	frontM.insert(make_pair("6S", "1U"));
	frontM.insert(make_pair("6W", "5U"));

	string curr, ops;

	cin >> curr;
	cin >> ops;

	for (int i = ops.size()-1; i >= 0; i--){
		if (ops[i] == 'F')
			curr = turn(frontM[turn(curr)]);
		else if (ops[i] == 'B')
			curr = frontM[turn(curr)];
		else if (ops[i] == 'L')
			curr = leftR[frontM[turn(curr)]];
		else
			curr = leftR[turn(frontM[turn(curr)])];

		//cout << curr << endl;
	}

	cout << curr << endl;
}
