#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define min(X,Y) (X) < (Y) ? (X) : (Y)

int waitTime;
int peopleCount;
int people[100000];
int bestOffsets[100000];
int total;

int search(int arrival, int departure){
    int min = 0, max = peopleCount - 1;
    while(min <= max){
        int mid = (min + max) / 2;
        if(people[mid] >= arrival && people[mid] <= departure){
            return 1;
        }
        if(people[mid] < arrival){
            min = mid + 1;
        } else if(people[mid] > departure){
            max = mid - 1;
        }
    }
    return 0;
}

int countBuses(int offset){
	int lastBus = people[peopleCount - 1] / waitTime;
	int i, buses = 0;
	for(i = 0; i <= lastBus; i++){
	    int arrival = (i * waitTime) + offset;
        int departure = arrival + waitTime - 1;
        if(search(arrival, departure)){
            buses++;
        }
    }
	return buses;
}

int main()
{
    scanf("%d %d", &waitTime, &peopleCount);
    int i;
    for(i = 0; i < peopleCount; i++){
		scanf("%d", &people[i]);
    }
    int min = INT_MAX, max = min(waitTime, people[0]);

    /*
    Si el tiempo de espera de cada camión es de 10 ns,
    esto quiere decir que Juanito puede decidir que el
    primer camión llegue en cualquier momento entre el
    nanosegundo 0 y el nanosegundo 10. En la salida
    deberán aparecer todos los nanosegundos entre 0 y 10
    en donde el número de camiones utilizados sea igual
    al mínimo posible.
    */

    /*
    La salida no cumple con ese requisito. Para
    que cuente el ns 0, cambiar i = 1 a i = 0.
    */

    for(i = 1; i <= max; i++){
		int curr = countBuses(i);
		if(curr < min){
			total = 0;
		    min = curr;
		}
		if (curr == min){
			bestOffsets[total++] = i;
        }
    }
    printf("%d\n", min);
    for(i = 0; i < total; i++){
        printf("%d ", bestOffsets[i]);
    }
    return 0;
}
