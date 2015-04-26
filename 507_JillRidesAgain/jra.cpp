#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int stops[20010];

int main () {
	int b;
	scanf("%i%*c", &b);
	for (int k = 1; k <= b; k++) {
		int s;
		scanf("%i%*c", &s);
		int sum = 0, ans = 0, temp_i = 1, final_i = 1, final_j = -1;
		for(int i=1;i<s;i++)
        {
            scanf("%i%*c", &stops[i]);
            sum += stops[i];
            if(sum < 0) {
            	sum = 0;
            	temp_i = i + 1;
            }
            if(sum > ans || (sum == ans && i - temp_i > final_j - final_i)) {
            	ans = sum;
            	final_j = i;
            	final_i = temp_i;
            }
        }
        if (!ans) printf("Route %i has no nice parts\n", k);
        else printf("The nicest part of route %i is between stops %i and %i\n", k, final_i, final_j + 1);
	}
	return 0;
}