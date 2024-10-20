#include <iostream>
#include <fstream>  // Include fstream for file operations
#include "family_tree.h"

int main() {
    FamilyTree familyTree;

    std::string userName;
    std::cout << "Enter your name: ";
    std::getline(std::cin, userName);
    familyTree.setRoot(userName);

    while (true) {
        std::string relativeName, parentName, answer;
        std::cout << "Do you want to add a relative (yes/no)? ";
        std::getline(std::cin, answer);
        if (answer == "no") break;

        std::cout << "Enter the name of the relative you want to add a parent for: ";
        std::getline(std::cin, relativeName);
        
        std::cout << "Enter the name of the parent: ";
        std::getline(std::cin, parentName);
        
        std::string parentRelation;
        std::cout << "Is this the mother or father? ";
        std::getline(std::cin, parentRelation);
        
        familyTree.addParent(relativeName, parentName, parentRelation);
    }

    std::ofstream outFile("family_tree.out");
    if (!outFile) {
        std::cerr << "Error opening file for writing." << std::endl;
        return 1;
    }

    familyTree.traverse(outFile);

    outFile.close();

    return 0;
}