cmake_minimum_required(VERSION 3.24)
project(DP)

set(CMAKE_CXX_STANDARD 14)

add_executable(DP
        1knapsack.cpp
        coinChange.cpp
        grid_2dmatrix.cpp
        maxSum_nonAdjacent.cpp minCoins_greedy.cpp)
