cmake_minimum_required(VERSION 3.2.2)
project(Algorithms)

add_executable(hello-ds hello-ds.cpp)
add_executable(dfs-graph  dfs-graph.cpp Graph.h Graph.cpp)
add_executable(count-islands  count-islands.cpp Graph.h Graph.cpp)
add_executable(heap-sample heap-sample.cpp Heap.h Heap.cpp)
add_executable(binary-tree-sample binary-tree-sample.cpp BinaryTree.h BinaryTree.cpp)
add_executable(linked-list-sample linked-list-sample.cpp LinkedList.h LinkedList.cpp)
add_executable(bfs-binary-tree bfs-binary-tree.cpp)
add_executable(pointer pointer.cpp)
add_executable(smart_pointer smart-pointer.cpp)
add_executable(custom_stack custom-stack.cpp)

