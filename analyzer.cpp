#include <iostream>
#include "StringData.h"
#include <vector>
#include <chrono>
#include <string>

void test_algorithm(std::vector<std::string>* wordList, std::string element);
int linear_search(std::vector<std::string>* container, std::string element);
int binary_search(std::vector<std::string>* container, std::string element);


int main() {
    std::vector<std::string> wordList = getStringData();
    test_algorithm(&wordList, "not_here");
    test_algorithm(&wordList, "mzzdsfajasgfsdagzz");
    test_algorithm(&wordList, "aaaaa");
    return 0;
}

void test_algorithm(std::vector<std::string>* wordList, std::string element) {
    std::cout << "Testing binary search:" << std::endl;
    std::cout << "Searching for " << element << std::endl;


    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
    int location = binary_search(wordList, element);
    std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
    if(location == -1){
        printf("Element not found.\n");
    }
    else {
        printf("Element found: %d\n", location);
    }
    std::chrono::duration<double> diff = end - start;
    //Asked UF AI how to convert a duration into an integer
    double duration = std::chrono::duration_cast<std::chrono::duration<float, std::milli>>(diff).count()/1000;

    //UF ai helping with time because time is weird
    std::time_t time_since_epoch_start = std::chrono::system_clock::to_time_t(start);
    std::time_t time_since_epoch_end = std::chrono::system_clock::to_time_t(end);

    printf("Time to search: %f\n", duration);
    std::cout << "Start: " << time_since_epoch_start << std::endl;
    std::cout << "End: " << time_since_epoch_end << std::endl;

    printf("\n");

    std::cout << "Testing linear search:" << std::endl;
    std::cout << "Searching for " << element << std::endl;


    start = std::chrono::system_clock::now();
    location = linear_search(wordList, element);
    end = std::chrono::system_clock::now();
    if(location == -1){
        printf("Element not found.\n");
    }
    else {
        printf("Element found: %d\n", location);
    }
    diff = end - start;
    //Asked UF AI how to convert a duration into an integer
    duration = std::chrono::duration_cast<std::chrono::duration<float, std::milli>>(diff).count()/1000;

    //UF ai helping with time because time is weird
    time_since_epoch_start = std::chrono::system_clock::to_time_t(start);
    time_since_epoch_end = std::chrono::system_clock::to_time_t(end);

    printf("Time to search: %f\n", duration);
    std::cout << "Start: " << time_since_epoch_start << std::endl;
    std::cout << "End: " << time_since_epoch_end << std::endl;

    printf("\n");


}

int linear_search(std::vector<std::string>* container, std::string element){
    int i = 0;
    for(std::string item:(*container)) {
        if(item.compare(element) == 0){
            return i;
        }
        i++;
    }

    return -1;
}

int binary_search(std::vector<std::string>* container, std::string element) {
    //based on zybooks implementation
    int low = 0;
    int high = container->size() - 1;

    while(high >= low) {
        int mid = (high + low)/2;
        if(container->at(mid).compare(element) < 0) {
            low = mid + 1;
        } else if(container->at(mid).compare(element) > 0) {
            high = mid - 1;
        } else {
            return mid;
        }
    }

    return -1;
}
