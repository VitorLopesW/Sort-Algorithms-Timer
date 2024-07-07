#include <iostream>
#include <vector>

std::vector<int> insertionSort(std::vector<int>& nonSortedArray) {
    std::vector<int> array = nonSortedArray;
    for(int index = 1 ; index < array.size() ; index++){

        int current = array[index];
        int position = index - 1;

        while(position > -1 && current < array[position]){
            array[position + 1] = array[position];
            position--;
        }
        array[position + 1] = current;
    }
    return array;
}

std::vector<int> bubbleSort(std::vector<int>& nonSortedArray) {
    std::vector<int> array = nonSortedArray;
    for(int index = 0 ; index < array.size() - 1; index++){
        for(int indexJ = 0 ; indexJ < array.size() - 1 ; indexJ++ ){
            if(array[indexJ] > array[indexJ+1]){
                int temp = array[indexJ];
                array[indexJ] = array[indexJ+1];
                array[indexJ+1] = temp;
            }
        }
    }
    return array;
}