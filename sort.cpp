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