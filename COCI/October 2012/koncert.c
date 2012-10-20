#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 200000

int M, N;
int MTicketsCount, NTicketsCount;

bool onehasticket;
int MNoTickets[MAXN];
int MTickets[MAXN];
int Ms, Me, Mnos, Mnoe;

int NTickets[MAXN];
int NTicketsCount;

int main(void) {
	int i, last = 0;

	scanf("%d %d", &M, &MTicketsCount);

	for (i = 0; i < MTicketsCount; i++)
		scanf("%d", &MTickets[i]);
	onehasticket = MTickets[0] == 1;
	Me = MTicketsCount;

	for (last = 0, i = 1; last < MTicketsCount; last++){
		while (i < MTickets[last])
			MNoTickets[Mnoe++] = i++;
		i++;
	}
	while (i <= M)
		MNoTickets[Mnoe++] = i++;

	scanf("%d %d", &N, &NTicketsCount);
	for (i = 0; i < NTicketsCount; i++)
		scanf("%d", &NTickets[i]);

	for (i = 0; i < NTicketsCount && Mnos < Mnoe; i++){
		MTickets[Me++] = MNoTickets[Mnos];
		printf("GIVE GIRL %d GUY %d\n", NTickets[i], MNoTickets[Mnos++]);
	}

	for (i = 0; i < Me; i++)
		printf("ENTER GUY %d\n", MTickets[i]);

	for (i = 0; i < Me; i++)
		if (MTickets[i] != 1)
			printf("GIVE GUY %d GUY 1\n", MTickets[i]);
	Ms = Me;

	int oneTicketCount = Me;

	while (Mnos < Mnoe){
		printf("EXIT GUY 1\n");
		for (i = 1; i < oneTicketCount && Mnos < Mnoe; i++){
			MTickets[Me++] = MNoTickets[Mnos];
			printf("GIVE GUY 1 GUY %d\n", MNoTickets[Mnos++]);
		}
		oneTicketCount = 1;

		printf("ENTER GUY 1\n");
		for (i = Ms; i < Me; i++)
			printf("ENTER GUY %d\n", MTickets[i]);

		while (Mnos + oneTicketCount - 1 < Mnoe && Ms < Me){
			if (MTickets[Ms] != 1){
				printf("GIVE GUY %d GUY 1\n", MTickets[Ms]);
				oneTicketCount++;
			}
			Ms++;
		}
		Ms = Me;
	}

	return 0;
}
