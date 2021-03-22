/*
* Nur Ahmad Khatim
* 22 Maret 2021
*/

#include <stdio.h>

int main ()
{
	int n, k, memo[100] = {0};
	int v[100][100], size[100] = {0};
	scanf("%d%d", &n, &k);
	int i;
	for (i=10; i<=99; i++) {
		int temp = i * i;
		if (temp / 100 > 9) {
			memo[i] = temp / 100;
		}
		else {
			memo[i] = temp / 10;
		}
	}
	int j;
	for (i=10; i<=99; i++) {
		int cek[100] = {0};
		if (cek[i] == 0) {
			cek[i] = 1;
			v[i][size[i]++] = i;
			v[i][size[i]++] = memo[i];
			j = memo[i];
			while (cek[j] == 0) {
				cek[j] = 1;
				v[i][size[i]++] = memo[j];
				j = memo[j];
			}
		}
	}
	int num = n, temp = n;
	while (k >= size[num]) {
		if (temp == v[num][size[num] - 1]) {
			k = k % (size[num] - 1);
			k = k % size[num];
			break;
		}
		if (num == 10 || v[num][size[num] - 1] == 10) {
			printf("10\n");
			return 0;
		}
		k = k - size[num] + 1;
		num = v[num][size[num] - 1];
		temp = num;
	}
	printf("%d\n", v[num][k]);
}
