#include <iostream>
#include "BruteForce.h"

std::vector<std::pair<std::vector<std::string>, std::vector<int>>> createConfigsVector(std::string filename) {
    std::fstream file(filename);
    int configNum = std::count(std::istreambuf_iterator<char>(file),
                               std::istreambuf_iterator<char>(), '\n');
    file.close();
    std::fstream configFile(filename);
    int iterationNum,givePathWeight;
    std::vector<std::pair<std::vector<std::string>, std::vector<int>>> configs;
    for(int i = 0; i < configNum; i++){
        std::vector<std::string> strings;
        std::vector<int> edges;
        configFile >> filename;
        configFile >> iterationNum;
        configFile >> givePathWeight;
        strings.push_back(filename);
        strings.push_back(std::to_string(iterationNum));
        strings.push_back(std::to_string(givePathWeight));
        std::string str = "";
        configFile >> str;
        if(str == "["){
            while(str != "]"){
                configFile >> str;
                if(str == "]") break;
                edges.push_back(stoi(str));
            }
        }
        std::pair<std::vector<std::string>, std::vector<int>> pair(strings,edges);
        configs.push_back(pair);
    }
    return configs;
}
int main() {
    std::vector<std::pair<std::vector<std::string>, std::vector<int>>> configs = createConfigsVector("/Users/lukamitrovic/Desktop/m13.ini");
    for (auto config : configs){
        BruteForce *bf = new BruteForce(config);
        bf->print();
        std::cout << bf->bruteForceAlg()<< std::endl;
        std::cout << "\n\nDroga : ";
        bf->printShortestPath();
        bf->timeMeasureBruteForce("/Users/lukamitrovic/Desktop/output.csv");
    }

    return 0;
}
