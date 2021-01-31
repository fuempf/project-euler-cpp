// Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
// How many such routes are there through a 20×20 grid?

#include <chrono>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

typedef long long unsigned int llui;

int main(){
    auto start = std::chrono::high_resolution_clock::now();

    const int size = 21;
    llui map[size][size];
    for(int i = 0;i < size; i++){
        for(int j = 0; j < size; j++){
            map[i][j] = 0;
        }
    }

    for(int x = 0; x < size; x++){
      for(int y = 0; y < size; y++){
        if(x==0&&y==0) map[x][y] = 1;
        else{
          map[x][y] += (x>0)?map[x-1][y]:0;
          map[x][y] += (y>0)?map[x][y-1]:0;
        }
      }
    }

    llui result = map[size-1][size-1];
    
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "result: " << result << std::endl;
    std::cout << "time: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "us" << std::endl;

    return 0;
}