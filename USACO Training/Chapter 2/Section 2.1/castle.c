/*
    ID: frceped1
    LANG: C
    TASK: castle
 */

#include <stdio.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("castle.in", "r", stdin); freopen("castle.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXMAP 51

#define TOPROCESS -1

typedef enum {
	west = 1,
	north = 2,
	east = 4,
	south = 8
} directions;

int xdir[9] = { [1] = -1, [2] = 0, [4] = 1, [8] = 0 };
int ydir[9] = { [1] = 0, [2] = -1, [4] = 0, [8] = 1 };

#define isBlocked(dir, place) (place & dir)
#define canGo(dir, place) !isBlocked(dir, place)

int height, width;
int map[MAXMAP][MAXMAP];

int room[MAXMAP][MAXMAP];
int nextRoom = 1;

int roomSize[MAXMAP*MAXMAP];

int max;
int largestRoom;
int bestx, besty;
char bestDir;

void flood_fill(void){
	int didStuff;
	do {
		int i,j;
		didStuff = 0;
		for (i = 0; i < width; i++){
			for (j = 0; j < height; j++){
				if (room[i][j] != TOPROCESS) continue;

				room[i][j] = nextRoom;
				roomSize[nextRoom]++;
				didStuff = 1;

				int dir;
				for (dir = 1; dir <= 8; dir <<= 1){
					if (canGo(dir, map[i][j]) && !room[i+xdir[dir]][j+ydir[dir]]){
						room[i+xdir[dir]][j+ydir[dir]] = TOPROCESS;
					}
				}
			}
		}
	} while (didStuff);
	if (roomSize[nextRoom] > largestRoom) largestRoom = roomSize[nextRoom];
	nextRoom++;
}

void tryJoining(int a, int b, int x, int y, char dir){
	if (x >= width || y < 0) return;

	if (room[a][b] == room[x][y]) return;

	int sum = roomSize[room[a][b]] + roomSize[room[x][y]];

	if (sum > max){
		max = sum;
		bestx = a;
		besty = b;
		bestDir = dir;
	}
}

int main(void){
	openFiles();

	int i, j;

	scanf("%d %d", &width, &height);

	for (j = 0; j < height; j++)
		for (i = 0; i < width; i++)
			scanf("%d", &map[i][j]);

	for (j = 0; j < height; j++){
		for (i = 0; i < width; i++){
			if (!room[i][j]){
				room[i][j] = TOPROCESS;
				flood_fill();
			}
		}
	}

	for (i = 0; i < width; i++){
		for (j = height - 1; j >= 0; j--){
			if (isBlocked(north, map[i][j])){
				tryJoining(i,j,i,j-1,'N');
			}
			if (isBlocked(east, map[i][j])){
				tryJoining(i,j,i+1,j,'E');
			}
		}
	}

	printf("%d\n", nextRoom-1);
	printf("%d\n", largestRoom);
	printf("%d\n", max);
	printf("%d %d %c\n", besty + 1, bestx + 1, bestDir);


	return 0;
}
