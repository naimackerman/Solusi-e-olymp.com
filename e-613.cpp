/*
* Nur Ahmad Khatim
* 22 Maret 2021
*/

#include <bits/stdc++.h>

using namespace std;

int main ()
{
	int n, k, memo[100] = {0};
	vector <int> v[100];
	cin >> n >> k;
	for (int i=10; i<=99; i++) {
		int temp = i * i;
		if (temp / 100 > 9) {
			memo[i] = temp / 100;
		}
		else {
			memo[i] = temp / 10;
		}
	}
//	for (int i=10; i<=99; i++) {
//		cout << i << " " << memo[i] << endl;
//	}
//	cout << endl;
	int j;
	for (int i=10; i<=99; i++) {
		int cek[100] = {0};
		if (cek[i] == 0) {
			cek[i] = 1;
			v[i].push_back(i);
			v[i].push_back(memo[i]);
			j = memo[i];
			while (cek[j] == 0) {
				cek[j] = 1;
				v[i].push_back(memo[j]);
				j = memo[j];
			}
		}
	}
//	cout << endl;
//	for (int i=10; i<=99; i++) {
//		for (int j=0; j<v[i].size(); j++) {
//			cout << v[i].at(j) << " ";
//		}
//		cout << endl;
//	}
	int num = n, temp = n;
	while (k >= v[num].size()) {
		if (temp == v[num].back()) {
			k = k % (v[num].size() - 1);
			k = k % v[num].size();
			break;
		}
		if (num == 10 || v[num].back() == 10) {
			cout << "10" << endl;
			return 0;
		}
		k = k - v[num].size() + 1;
		num = v[num].back();
		temp = num;
	}
	cout << v[num].at(k) << endl;
}
