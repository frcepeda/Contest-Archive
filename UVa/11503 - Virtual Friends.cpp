// Accepted
#include <iostream>
#include <string>
#include <map>

using namespace std;

#define MAXN 100100

map<string,int> nameID;
int _set[MAXN];
int rank[MAXN];
int size[MAXN];
int N, lastid;

int id(int x){
	if (_set[x] == x)
		return x;
	else return _set[x] = id(_set[x]);
}

int getID(const string &a){
	if (nameID.find(a) != nameID.end())
		return id(nameID[a]);
	_set[lastid] = lastid;
	size[lastid] = 1;
	nameID[a] = lastid;
	return lastid++;
}

void join(const string &a, const string &b){
	int i = getID(a);
	int j = getID(b);
	
	if (i == j) return;
	
	if (rank[i] < rank[j]){
		_set[i] = j;
		size[j] += size[i];		
	} else if (rank[j] < rank[i]){
		_set[j] = i;
		size[i] += size[j];
	} else {
		_set[i] = j;
		rank[j]++;
		size[j] += size[i];
	}
}

int netSize(const string &i){
	return size[getID(i)];
}

int main(void) {
	int T;
	string a, b;
	
	cin >> T;
	
	while (T--){
		lastid = 0;
		cin >> N;
		
		nameID.clear();
		
		while (N--){
			cin >> a;
			cin >> b;
			join(a,b);
			cout << netSize(a) << endl;
		}
	}
	
	return 0;
}
