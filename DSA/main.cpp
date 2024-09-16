#include "BinaryTree.hpp"
#include "RecursiveBinaryTree.hpp"


int main() {
    RecursiveBST* myBST = new RecursiveBST();
    myBST->rInsert(100);
    myBST->insert(47);
    myBST->insert(21);
    myBST->insert(76);
    myBST->insert(18);
    myBST->insert(27);
    myBST->insert(52);
    myBST->insert(82);



    std::cout << myBST->rContains(100) << " ";

    std::cout << myBST->rContains(17) << " ";
    myBST->rInsert(17);

    std::cout << myBST->rContains(17);

    return 0;
}