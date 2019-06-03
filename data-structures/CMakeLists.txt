cmake_minimum_required(VERSION 3.2.2)
project(Algorithms)

add_executable(hello-ds hello-ds.cpp)
add_executable(dfs-graph  dfs-graph.cpp Graph.h Graph.cpp)
add_executable(count-islands  count-islands.cpp Graph.h Graph.cpp)
add_executable(heap-sample heap-sample.cpp Heap.h Heap.cpp)
add_executable(binary-tree-sample binary-tree-sample.cpp BinaryTree.h BinaryTree.cpp)
