cmake_minimum_required(VERSION 3.24.2)
project(si310_labs)

set(CMAKE_CXX_STANDARD 14)

include_directories(Models)
include_directories(structures)
include_directories(Types)

add_executable(si310_labs
        Models/BinarySearchTree.cpp
        Models/BinarySearchTree.h
        Models/LinkedList.cpp
        Models/LinkedList.h
        Models/Queues.cpp
        Models/Queues.h
        Models/Stacks.cpp
        Models/Stacks.h
        Models/TreeNode.cpp
        Models/TreeNode.h
        structures/Node.h
        Types/types.h
        main.cpp Models/Vertex.cpp Models/Vertex.h Models/UndirectedGraph.cpp Models/UndirectedGraph.h Models/UndirectedWeightedGraph.cpp Models/UndirectedWeightedGraph.h)
