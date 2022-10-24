//
// Created by Luka Mitrovic on 21/10/2022.
//

#ifndef PEA_ETAP1_BRUTEFORCE_H
#define PEA_ETAP1_BRUTEFORCE_H
#include <string>
#include <fstream>
#include <exception>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std::chrono;
class BruteForce {
public:
    explicit BruteForce(std::pair<std::vector<std::string>, std::vector<int>> config);
    BruteForce();
    int bruteForceAlg();
    void findShortestPath(int *arr, int l, int r);
    void printShortestPath();
    void printMatrix();
    void print();
    std::vector<std::pair<std::vector<std::string>, std::vector<int>>> createConfigsVector(std::string filename);
    std::string filename;
    int cityNum;
    int givePathWeight;
    std::vector<int> givenPath;
    int lengthOfShortestPath;
    int length;
    int **matrix;
    int *shortestPath;
    int opt;

    high_resolution_clock::time_point startTime;
    high_resolution_clock::time_point endTime;
    int iterationNum;

    void timeMeasureBruteForce(std::string outputFile);
    void measureStart();
    void measureEnd();
    long getTime();

};


#endif //PEA_ETAP1_BRUTEFORCE_H
