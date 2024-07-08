#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip> 

std::vector<int> createAndRandomize(int size);

std::vector<int> insertionSort(std::vector<int>& array);
std::vector<int> bubbleSort(std::vector<int>& nonSortedArray);
std::vector<int> selectionSort(std::vector<int>& nonSortedArray);


void printArray(const std::vector<int>& array) {
    for (std::size_t i = 0; i < array.size(); ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

double calculateTime(std::string algorithim, std::vector<int> array){
    
    auto start = std::chrono::steady_clock::now();

    if (algorithim == "insertionSort") insertionSort(array);
    else if (algorithim == "bubbleSort") bubbleSort(array);
    else if (algorithim == "selectionSort") selectionSort(array);

    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    auto durationMiliseconds = duration / 1000.0;
    auto durationSeconds = durationMiliseconds / 1000.0;
    return durationSeconds;
}

int userInput(){
    std::cout << "Please specify the desired size for the randomized array: (min 500 - max 50.000)";
    int size {};
    std::cin >> size;
    //if(size < 500) size = 500;
    //else if(size > 50000) size = 50000;
    return size;
}

int initLoop() {
    std::vector<int> array = createAndRandomize(userInput());
    
    std::cout << "Insertion Sort: " << calculateTime("insertionSort", array) << " seconds" << "\n";
    std::cout << "Bubble Sort: " << calculateTime("bubbleSort", array) << " seconds" << "\n";
    std::cout << "Selection Sort: " << calculateTime("selectionSort", array) << " seconds" << "\n";

    char userChoice;
    std::cout << "Do you want to run the loop again? (y/n): ";
    std::cin >> userChoice;

    if (userChoice == 'y' || userChoice == 'Y') {
        return initLoop();
    } else {
        return 0;
    }
}

int main() {
    initLoop();
    return 0;
}

