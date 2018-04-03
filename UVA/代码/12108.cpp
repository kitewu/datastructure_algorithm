#include<stdio.h>
#define maxn 1000000
typedef struct Stu {
	int a, b, c;
} Stu;

int main() {
	int n, flag = 0;
	while (scanf("%d", &n) && n) {
		Stu stu[n];
		for (int i = 0; i < n; i++)
			scanf("%d%d%d", &stu[i].a, &stu[i].b, &stu[i].c);
		bool ok = false;
		int x = 1;
		for (; x < maxn; x++) {
			int awake = 0;//醒着的人数
			for (int i = 0; i < n; i++)
				if (stu[i].c <= stu[i].a)
					awake++;
			if (awake == n) {
				ok = true;
				break;
			}
			for (int i = 0; i < n; i++) {
				if (stu[i].c == stu[i].a + stu[i].b
						|| (stu[i].c == stu[i].a && awake >= n - awake))
					stu[i].c = 0;
				stu[i].c++;
			}
		}
		printf("Case %d: %d\n", ++flag, ok ? x : -1);
	}
	return 0;
}
