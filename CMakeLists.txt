cmake_minimum_required(VERSION 3.27)
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
        main.cpp
        Models/AvlNode.h
        Models/AvlNode.cpp
        Models/AvlTree.h
        Models/AvlTree.cpp
        Models/BinaryTree.h
        Models/VanillaTreeNode.h
        Models/VanillaTreeNode.cpp
        Models/VanillaTreeNode.cpp
        Models/BinaryTree.cpp
        Models/UndirectedGraph.cpp
        Models/Vertex.cpp)
