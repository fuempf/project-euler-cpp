
#include <chrono>
#include <iostream>
#include <vector>

std::string input = "75 95 64 17 47 82 18 35 87 10 20 04 82 47 65 19 01 23 75 03 34 88 02 77 73 07 63 67 99 65 04 28 06 16 70 92 41 41 26 56 83 40 80 70 33 41 48 72 33 47 32 37 16 94 29 53 71 44 65 25 43 91 52 97 51 14 70 11 33 28 77 73 17 78 39 68 17 57 91 71 52 38 17 14 91 43 58 50 27 29 48 63 66 04 68 89 53 67 30 73 16 69 87 40 31 04 62 98 27 23 09 70 98 73 93 38 53 60 04 23";

int main(){
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<int> numlist;
    int pos = 0;
    while ((pos = input.find(" ")) != std::string::npos) {
        numlist.push_back(std::stoi(input.substr(0, pos)));
        input.erase(0, pos+1);
    }
    numlist.push_back(std::stoi(input)); // add last 

    
    std::vector<std::vector<int>> tree;
    int linelength = 1;
    int current = 0;
    for(int num: numlist){
        if(current >= linelength){
             current = 0;
             linelength++;
        }
        if(current == 0) tree.push_back(std::vector<int>(linelength));
        tree[linelength-1][current] = num;
        current++;
    }


    for(int line = tree.size()-2; line >= 0; line--){
        for(int cell = 0; cell < tree[line].size(); cell++){
            if(tree[line+1][cell] > tree[line+1][cell+1]) tree[line][cell] += tree[line+1][cell];
            else tree[line][cell] += tree[line+1][cell+1];
        }
    }

    int result = tree[0][0];
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "result: " << result << std::endl;
    std::cout << "time: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "μs" << std::endl;

    return 0;
}