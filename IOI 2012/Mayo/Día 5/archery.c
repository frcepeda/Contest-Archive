#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <strings.h>

#define MAXNUM 200010

#define clear(a) memset(a, 0, sizeof(a))

typedef struct {
	int a, b;
} pair;

pair makePair(int a, int b){
	pair p = {a,b};
	return p;
}

int targetCount, rounds;

typedef enum {
	xLost,
	yLost,
	zLost
} loser;

/* x = better than me
 * y = me
 * z = worse than me
 */
int x[MAXNUM*3+1];
int y[MAXNUM*3+1];
int z[MAXNUM*3+1];

int ranks[MAXNUM*2];
int myRank;

pair cache[MAXNUM];
bool cached[MAXNUM];

pair simulate(int position){
	int i, loops = 0;

	int start = position/2;
	if (cached[start])
		return cache[start];
	cached[start] = true;

	if (myRank == 1){
		cache[start] = makePair(1, 0);
	} else if (myRank <= targetCount + 1){
		clear(x);
		clear(y);
		clear(z);

		y[position/2] = 1;

		for (i = 1; i < targetCount * 2; i++){
			int target = (i - 1 + (i > position ? 1 : 0)) / 2;
			if (ranks[i] < myRank)
				x[target]++;
			else
				z[target]++;
		}

		int xCandidates = 0, yCandidates = 0, zCandidates = 0;
		int xinFirstTarget = 0, yinFirstTarget = 0, zinFirstTarget = 0;

		int archer1, archer2;

		if (position < 2){
			archer1 = ranks[1];
			archer2 = myRank;
		} else {
			archer1 = ranks[1];
			archer2 = ranks[2];
		}

		if (archer1 < myRank)
			xinFirstTarget++;
		else if (archer1 == myRank)
			yinFirstTarget++;
		else
			zinFirstTarget++;

		if (archer2 < myRank)
			xinFirstTarget++;
		else if (archer2 == myRank)
			yinFirstTarget++;
		else
			zinFirstTarget++;

		int found = -1;
		for (i = 0; i < targetCount*3; i++){
			if (i >= targetCount*2 && yinFirstTarget == 1){
				found = i;
				break;
			}

			loser l;
			if (xinFirstTarget > 0){
				if (xinFirstTarget == 2)
					l = xLost;
				else if (yinFirstTarget == 1){
					l = yLost;
					loops++;
				} else
					l = zLost;
			} else {
				l = zLost;
			}

			int nextChance = i + targetCount;
			if (nextChance <= targetCount*3){
				switch (l){
					case xLost:
						x[nextChance]++;
						xinFirstTarget--;
						break;
					case yLost:
						y[nextChance]++;
						yinFirstTarget--;
						break;
					case zLost:
						z[nextChance]++;
						zinFirstTarget--;
						break;
				}
			}

			xCandidates += x[i+1];
			yCandidates += y[i+1];
			zCandidates += z[i+1];

			if (xCandidates > 0){
				xinFirstTarget++;
				xCandidates--;
			} else if (yCandidates > 0){
				yinFirstTarget++;
				yCandidates--;
			} else {
				zinFirstTarget++;
				zCandidates--;
			}
		}

		if (rounds > found)
			loops++;

		cache[start] = makePair(targetCount - ((rounds - found + targetCount - 1) % targetCount), loops);
	} else {
		clear(y);
		clear(z);

		y[position/2] = 1;

		for (i = 1; i < targetCount * 2; i++){
			int target = (i - 1 + (i > position ? 1 : 0)) / 2;
			if (ranks[i] > myRank)
				z[target]++;
		}

		int countZ = 0, countY = 0;

		for (i = 0; i < 3; i++){
			int target = 0;
			do {
				int currZ = countZ + z[target];
				int currY = countY + y[target];

				if (currZ + currY > 1){
					if (target > 0){
						y[target] = 0;
						z[target] = 1;
						countZ = currZ - 1;
						if (currY > 0){
							countY = currY;
						} else {
							countY = 0;
						}
					} else {
						if (currY > 0){
							y[target] = 1;
							z[target] = 0;
							countY = currY - 1;
							countZ = currZ;
						} else {
							y[target] = 0;
							z[target] = 1;
							countY = 0;
							countZ = currZ - 1;
						}
					}
				} else {
					if (target > 0){
						y[target] = currY;
						z[target] = currZ;
						countY = countZ = 0;
					} else {
						if (currY > 0)
							loops++;
						z[target] = y[target] = 0;
						countY = currY;
						countZ = currZ;
					}
				}

				if (target == 0)
					target = targetCount - 1;
				else
					target--;
			} while (target > 0);
		}

		for (i = 0; i < targetCount; i++){
			if (y[i] > 0){
				cache[start] = makePair(i+1, loops);
				break;
			}
		}
	}

	return cache[start];
}

pair binarySearch(int lo, int hi){
	int mid;
	pair high, low, middle;

	low = simulate(lo*2 - 1);
	high = simulate(hi*2 - 1);

	while ((hi - lo) > 1){
		mid = (hi + lo) / 2;

		middle = simulate(mid*2 - 1);

		if (low.a < middle.a){
			hi = mid;
			high = middle;
		} else {
			lo = mid;
			low = middle;
		}
	}

	if (low.a < high.a)
		return makePair(low.a, lo);
	else
		return makePair(high.a, hi);
}

int main(void){
	int i, best;

	scanf("%d%d", &targetCount, &rounds);
	rounds = (2 * targetCount) + (rounds % targetCount);

	scanf("%d", &myRank);
	for (i = 1; i < targetCount*2; i++)
		scanf("%d", &ranks[i]);

	pair high, low, middle;
	int hi = targetCount, lo = 1, mid;

	low = simulate(1);
	high = simulate(2*targetCount - 1);

	if (low.b > high.b){
		while ((hi - lo) > 1){
			mid = (hi + lo) / 2;

			middle = simulate(mid*2 - 1);

			if (middle.b > high.b){
				lo = mid;
				low = middle;
			} else {
				hi = mid;
				high = middle;
			}
		}

		if (low.b > high.b)
			mid = hi;
		else
			mid = lo;

		pair first = binarySearch(1, mid-1);
		pair last = binarySearch(mid, targetCount);

		if (first.a < last.a)
			best = first.b;
		else
			best = last.b;
	} else {
		pair ans = binarySearch(1, targetCount);
		best = ans.b;
	}

	printf("%d\n", best);

	return 0;
}

