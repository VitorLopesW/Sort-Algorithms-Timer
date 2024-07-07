#include <vector>
#include <algorithm>
#include <random>
#include <iterator>

std::vector<int> generateArray(int size) {
    std::vector<int> array(size);
    for(int i = 1; i <= size; i++) {
        array[i - 1] = i;
    }

    return array;
}

void randomizeArray(std::vector<int>& array) {
    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(array), std::end(array), rng);
}

std::vector<int> createAndRandomize(int size) {
    std::vector<int> array = generateArray(size);
    randomizeArray(array);
    return array;
}