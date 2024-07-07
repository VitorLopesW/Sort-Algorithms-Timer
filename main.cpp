#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip> 

std::vector<int> createAndRandomize(int size);

std::vector<int> insertionSort(std::vector<int>& array);

void printArray(const std::vector<int>& array) {
    for (std::size_t i = 0; i < array.size(); ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

double calculateTime(std::string algorithim, std::vector<int> array){
    
    auto start = std::chrono::steady_clock::now();

    if (algorithim == "insertionSort") insertionSort(array);


    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    auto durationSeconds = duration / 1000000.0;
    std::cout << "inside: " << durationSeconds << "\n";
    return durationSeconds;
}


int main() {

    std::vector<int> array = createAndRandomize(5000);
    
    double time = calculateTime("insertionSort", array);
    
    std::cout << "outside> " << time << "\n";


    return 0;
}

//std::cout << "Duration: " << std::fixed << std::setprecision(3) << durationSeconds << " seconds" << std::endl;
