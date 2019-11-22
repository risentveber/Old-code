void merge(data* massiv, data* temp, int left, int bar, int right, bool (*compare)(data a, data b)){
	int x = left;
	int y = bar + 1;
	for(int i = left; i <= right; i++){//Собственно слияние
		if ((x <= bar) && (y <= right)){
			if (compare(massiv[x], massiv[y])){
				temp[i] =  massiv[x];
				x++;
			}
			else{
				temp[i] =  massiv[y];
				y++;
			}
		}
		else{
			if (x <= bar){
				for(; x <= bar; x++){
					temp[i] =  massiv[x];
					i++;
				}
				break;
			}
			if (y <= right){
				for(; y <= right; y++){
					temp[i] =  massiv[y];
					i++;
				}
				break;
			}
		}
	}
	for(int i = left; i <= right; i++){
		massiv[i] = temp[i];
	}

}

void mergeSort(data* massiv, data* temp, int left, int right, bool (*compare)(data a, data b)){
	if(left < right){
		int bar = (left+right)/2;
		mergeSort(massiv, temp, left, bar, compare);
		mergeSort(massiv, temp, bar + 1, right, compare);
		merge(massiv, temp, left, bar, right, compare);
	}
}

void mergesort(data* massiv, int count, bool (*compare)(data a, data b)){
	data* temp = (data*)malloc(count*sizeof(data));
	mergeSort(massiv, temp, 0, count - 1,compare);
	free(temp);
}
