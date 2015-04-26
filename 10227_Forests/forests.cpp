#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>

using namespace std;

typedef vector<int> vi;

class UnionFind {
private:
  vi p, rank, setSize;
  int numSets;
public:
    UnionFind(int N) {
        setSize.assign(N, 1); 
        numSets = N; 
        rank.assign(N, 0);
        p.assign(N, 0); 
        for (int i = 0; i < N; i++) 
            p[i] = i; 
    }

    int findSet(int i) { 
        if (p[i] == i) {
            return i;
        }
        else {
            return p[i] = findSet(p[i]);
        }
    }

    bool isSameSet(int i, int j) { 
        return findSet(i) == findSet(j); 
    }
    
    void unionSet(int i, int j) { 
        if (!isSameSet(i, j)) { 
            numSets--; 
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) { 
                p[y] = x; 
                setSize[x] += setSize[y]; 
            }
            else { 
                p[x] = y; 
                setSize[y] += setSize[x];
                if (rank[x] == rank[y]) 
                    rank[y]++; 
                } 
        } 
    }
    int numDisjointSets() { 
        return numSets; 
    }
    int sizeOfSet(int i) { 
        return setSize[findSet(i)]; 
    }
};

int main () {
	int t;
	scanf("%i%*c", &t);
	getchar();
	for (int m = 0; m < t; m++) {
		if (m) printf("\n");
		int P, T;
		scanf("%i %i%*c", &P, &T);
		vector < bitset <100> > people(P);
		char s[10];
		int person, tree;
		while (gets(s) && sscanf(s, "%i %i%*c", &person, &tree) == 2) {
			people[person - 1].set(tree - 1, 1);
		}
		UnionFind dis = UnionFind(P);

		for (int i = 0; i < P; i++) {
			for (int j = 0; j < P; j++) {
				if (people[i] == people[j] && !dis.isSameSet(i, j)) {
					dis.unionSet(i, j);
				}
			}
		}
		printf("%i\n", dis.numDisjointSets());
	}
	return 0;
}