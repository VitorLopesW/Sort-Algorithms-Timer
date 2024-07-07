#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip> 

std::vector<int> createAndRandomize(int size);

std::vector<int> insertionSort(std::vector<int>& array);
std::vector<int> bubbleSort(std::vector<int>& nonSortedArray);


void printArray(const std::vector<int>& array) {
    for (std::size_t i = 0; i < array.size(); ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

double calculateTime(std::string algorithim, std::vector<int> array){
    
    auto start = std::chrono::steady_clock::now();

    if (algorithim == "insertionSort") insertionSort(array);
    else if (algorithim == "bubbleSort") insertionSort(array);

    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    auto durationMiliseconds = duration / 1000.0;
    auto durationSeconds = durationMiliseconds / 1000.0;
    return durationSeconds;
}

int userInput(){
    std::cout << "Please specify the desired size for the randomized array: ";
    int size {};
    std::cin >> size;
    return size;
}
int main() {

    std::vector<int> array = createAndRandomize(userInput());

    std::cout << "Insertion Sort: " << calculateTime("insertionSort", array) << " seconds" << "\n";
    std::cout << "Bubble Sort: " << calculateTime("bubbleSort", array) << " seconds" << "\n";;




    
    
    return 0;
}

