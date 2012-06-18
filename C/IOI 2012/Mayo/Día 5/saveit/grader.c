#include "grader.h"
#include "encoder.h"
#include "decoder.h"
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

static int h[1000][1000], hcnt;

#define FOR(i,n) for (i = 0; i < (n); i++)

static int bits[16000000], nb;
static int curbit = 0;
static bool wrong = false;

void encode_bit(int bit) {
	if (nb >= 16000000)
		assert(false);
	bits[nb++] = bit;
}

int decode_bit(void) {
	if (curbit >= nb)
		assert(false);
	return bits[curbit++];
}

void hops(int a, int b, int d) {
	if (h[a][b] != d) {
		//printf("%d -> %d: %d NOT %d\n", a, b, h[a][b], d);
		wrong = true;
	}
	h[a][b] = -1;
	hcnt++;
}

static int nv, ne, c;
static int v1[1234567], v2[1234567];

int main(int argc, char **argv) {
	int i,j;
	assert(3 == scanf("%i%i%i", &nv, &ne, &c));
	FOR(i,ne) assert(2 == scanf("%i%i", v1+i, v2+i));
	for (i=0;i<c;i++) for (j=0;j<nv;j++) scanf("%d",&h[i][j]);
	encode(nv, c, ne, v1, v2);
	decode(nv, c);
	if (hcnt != c*nv) {
		wrong = true;
	}
	printf("%s\n",nb<=70000 && !wrong?"OK":"NO");
	return 0;
}
