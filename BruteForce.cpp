//
// Created by Luka Mitrovic on 21/10/2022.
//

#include "BruteForce.h"

BruteForce::BruteForce(std::pair<std::vector<std::string>, std::vector<int>> config) {
    filename = config.first.at(0);
    iterationNum = stoi(config.first.at(1));
    givePathWeight = stoi(config.first.at(2));
    for (auto edge : config.second ){
        givenPath.push_back(edge);
    }
    std::string numberofcities;

    std::fstream dataFile(filename);
    dataFile >> cityNum;

    matrix = new int *[cityNum];
    for (int i = 0; i <= cityNum; i++) {
        matrix[i] = new int[cityNum];
        for (int j = 0; j < cityNum; j++) {
            dataFile >> matrix[i][j];
        }
    }
//    dataFile >> opt;
    lengthOfShortestPath = INT32_MAX;
    shortestPath = new int[cityNum + 1];
    for (int i = 0; i < cityNum + 1; i++) {
        shortestPath[i] = 0;
    }
}

int BruteForce::bruteForceAlg() {
    int *arr = new int[cityNum + 1];
    for (int i = 0; i < cityNum; i++) {
        arr[i] = i;
    }
    arr[cityNum] = 0;
    findShortestPath(arr, 1, cityNum - 1);
    return lengthOfShortestPath;
}

void BruteForce::timeMeasureBruteForce(std::string outputFile){
    std::fstream dataFile(outputFile,std::ios::app);
    dataFile << filename << "\n";
    for (int i = 0; i < iterationNum; i++){
        std::string pathToSave = "";
        measureStart();
        int pathWeight = bruteForceAlg();
        measureEnd();
        for (int i = 0; i < cityNum + 1; i++) {
            pathToSave =  pathToSave +  std::to_string(shortestPath[i]) + " ";
        }

        dataFile << getTime() << ";" << pathWeight << ";[ " << pathToSave << "]" << std::endl;
    }
    dataFile.close();
}

void BruteForce::findShortestPath(int *arr, int l, int r)
{
    if (l == r)
    {
        int pathLength = 0;
        int currentCity = 0;

        /*Wyliczanie dlugosci drogi*/
        for (int i = 0; i < cityNum; i++)
        {
            pathLength += matrix[currentCity][arr[i + 1]];
            currentCity = arr[i + 1];
        }
        int tmpLenth = 0;
        for (int i = 0; i < cityNum + 1; i++)
        {
            if(i<cityNum)
            {
                tmpLenth += matrix[arr[i]][arr[i + 1]];
            }
        }

        if (tmpLenth<length)
        {
            length = tmpLenth;
            std::cout<<length<<" ";
        }
        /*Zmiana wartosci najkrotszej drogi */
        if (pathLength < lengthOfShortestPath)
        {
            lengthOfShortestPath = pathLength;
            for (int i = 0; i < cityNum + 1; i++)
            {
                shortestPath[i] = arr[i];
            }
        }

    } else
    {
        for (int i = l; i <= r; i++)
        {
            std::swap(arr[l], arr[i]);
            findShortestPath(arr, l + 1, r);
            std::swap(arr[l], arr[i]);
        }
    }

}

void BruteForce::printShortestPath()
{
    for (int i = 0; i < cityNum + 1; i++)
    {
        std::cout << "(" << shortestPath[i] << ")";

        if (i < cityNum)
        {
            std::cout << "--" << matrix[shortestPath[i]][shortestPath[i + 1]] << "-->";
        }
    }
    std::cout << std::endl;
}

void BruteForce::printMatrix()
{
    for (int i = 0; i < cityNum; i++)
    {
        for (int j = 0; j < cityNum; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

}

void BruteForce::print() {
    std::cout << "File name: " << filename << std::endl;
    std::cout << "Number of cities: " << cityNum << std::endl;
    std::cout << "Adjacency matrix: " << std::endl;
    printMatrix();
}

void BruteForce::measureStart() {
    this->startTime = high_resolution_clock::now();
}

void BruteForce::measureEnd() {
    this->endTime = high_resolution_clock::now();
}

long BruteForce::getTime() {
    return duration_cast<nanoseconds>(endTime - startTime).count();;
}

BruteForce::BruteForce() {

}
