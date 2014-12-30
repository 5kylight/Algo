#include <iostream>
#include <algorithm> 

void quickSort(int array[], int left, int right){
	if ( left > right) return;

	int pivot = array[right];
	int i = left;
	int j = right-1; 
	while (i != j){
		while(array[i] >= pivot && i != j )++i;
		while(array[j] < pivot && i !=j ) j--;
		swap(array[i++], array[j--]);
		}
	std::swap(array[right], array[j]);

	quickSort(array,left,j-1);
	quickSort(array,j+1,right);

}


int main(){
	int array[] = {2,6,7,1,9,4,5,1};
	quickSort(array,0,array.length());
	for(int i = 0 ; i < array.length() ; ++i){
		cout << array[i] << "endl";
	}

}