#include <stdio.h>
#include <stdlib.h>

int nums[7000];
int numCount;

int search(int num){
	int min = 0, max = numCount - 1;
	while(min <= max){
		int mid = (min + max) / 2;
		if(nums[mid] == num){
			return 1;
		}
		if(nums[mid] < num){
			min = mid + 1;
		} else {
			max = mid - 1;
		}
	}
	return 0;
}

int main(){
    /*
	scanf("%d", &numCount);
	for(i = 0; i < numCount; i++){
		scanf("%d", &nums[i]);
	}
	*/

	int i, i2, total = 0;
    numCount = 7000;

	for(i = 1; i <= numCount; i++){
        nums[i-1] = i*i;
	}

	for(i = 0; i < numCount - 2; i++){
		for(i2 = i + 1; i2 < numCount; i2++){
			int diff = nums[i2] - nums[i];
			int succ = nums[i2] + diff;
			if(search(succ)){
				total++;
			}
		}
	}
	printf("%d\n", total);
	return 0;
}
