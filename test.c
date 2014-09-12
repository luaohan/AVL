#include <stdio.h>

#include "avl.h"

int main()
{
    BSTree tree = NULL;
#if 0
    int a55 = 55;
    int a40 = 40;
    int a90 = 90;
    int a45 = 45;

    printf("insert 55, 40, 90, 45 \n");
    
    int taller;
    InsertAVL(&tree, &a55, &taller);
    if (isBalanceTree(tree) == 1){
        printf("after insert 55, is balance tree \n");
    } else {
        printf("after insert 55, is not balance tree \n");
    }

    InsertAVL(&tree, &a40, &taller);
    if (isBalanceTree(tree) == 1){
        printf("after insert 40, is balance tree \n");
    } else {
        printf("after insert 40, is not balance tree \n");
    }

    InsertAVL(&tree, &a90, &taller);
    if (isBalanceTree(tree) == 1){
        printf("after insert 90, is balance tree \n");
    } else {
        printf("after insert 90, is not balance tree \n");
    }

    InsertAVL(&tree, &a45, &taller);
    if (isBalanceTree(tree) == 1){
        printf("after insert 45, is balance tree \n");
    } else {
        printf("after insert 45, is not balance tree \n");
    }

    printf("GetNodeNum : %d \n", GetNodeNum(tree));
    printf("GetBiTreeDepth : %d \n", GetBSTreeDepth(tree));
    printf("GetLeafNodeNum : %d \n", GetLeafNodeNum(tree));
    printf("GetNodeNumKthLevel 1 : %d \n", GetNodeNumKthLevel(tree, 1));
    printf("GetNodeNumKthLevel 2 : %d \n", GetNodeNumKthLevel(tree, 2));        
    printf("GetNodeNumKthLevel 3 : %d \n", GetNodeNumKthLevel(tree, 3));

    printf("InVisitBiTree : \n");
    InVisitBSTree(tree);

    if (SearchBST(tree, &a55) != NULL){
        printf("have 55 \n");
    }

    if (SearchBST(tree, &a40) != NULL){
        printf("have 40 \n");
    }

    if (SearchBST(tree, &a45) != NULL){
        printf("have 45 \n");
    }

    if (SearchBST(tree, &a90) != NULL){
        printf("have 90 \n");
    }

    printf("now delete 90 \n");
    int shorter;
    if (DeleteAVL(&tree, a90, &shorter) == 1){
        printf("delete 90 success \n");
    }
    if (isBalanceTree(tree) == 1){
        printf("after delete 90, is balance tree \n");
    } else {
        printf("after delete 90, is not balance tree \n");
    }


    printf("GetNodeNum : %d \n", GetNodeNum(tree));
    printf("GetBiTreeDepth : %d \n", GetBSTreeDepth(tree));
    printf("GetLeafNodeNum : %d \n", GetLeafNodeNum(tree));
    printf("GetNodeNumKthLevel 1 : %d \n", GetNodeNumKthLevel(tree, 1));
    printf("GetNodeNumKthLevel 2 : %d \n", GetNodeNumKthLevel(tree, 2));     
    printf("GetNodeNumKthLevel 3 : %d \n", GetNodeNumKthLevel(tree, 3));     

    printf("InVisitBiTree : \n");
    InVisitBSTree(tree);
#endif

#if 0
    int a13 = 13;
    int a24 = 24;
    int a37 = 37;
    int a90 = 90;
    int a53 = 53;

    printf("insert 13, 24, 37, 90, 53 \n");
    
    int taller;
    InsertAVL(&tree, &a13, &taller);
    if (isBalanceTree(tree) == 1){
        printf("after insert 13, is balance tree \n");
    } else {
        printf("after insert 13, is not balance tree \n");
    }

    InsertAVL(&tree, &a24, &taller);
    if (isBalanceTree(tree) == 1){
        printf("after insert 24, is balance tree \n");
    } else {
        printf("after insert 24, is not balance tree \n");
    }

    InsertAVL(&tree, &a37, &taller);
    if (isBalanceTree(tree) == 1){
        printf("after insert 37, is balance tree \n");
    } else {
        printf("after insert 37, is not balance tree \n");
    }

    InsertAVL(&tree, &a90, &taller);
    if (isBalanceTree(tree) == 1){
        printf("after insert 90, is balance tree \n");
    } else {
        printf("after insert 90, is not balance tree \n");
    }

    InsertAVL(&tree, &a53, &taller);
    if (isBalanceTree(tree) == 1){
        printf("after insert 53, is balance tree \n");
    } else {
        printf("after insert 53, is not balance tree \n");
    }

    printf("GetNodeNum : %d \n", GetNodeNum(tree));
    printf("GetBiTreeDepth : %d \n", GetBSTreeDepth(tree));
    printf("GetLeafNodeNum : %d \n", GetLeafNodeNum(tree));
    printf("GetNodeNumKthLevel 1 : %d \n", GetNodeNumKthLevel(tree, 1));
    printf("GetNodeNumKthLevel 2 : %d \n", GetNodeNumKthLevel(tree, 2));        
    printf("GetNodeNumKthLevel 3 : %d \n", GetNodeNumKthLevel(tree, 3));

    printf("InVisitBiTree : \n");
    InVisitBSTree(tree);
#if 0
    if (SearchBST(tree, &a13) != NULL){
        printf("have 13 \n");
    }

    if (SearchBST(tree, &a24) != NULL){
        printf("have 24 \n");
    }

    if (SearchBST(tree, &a37) != NULL){
        printf("have 37 \n");
    }

    if (SearchBST(tree, &a90) != NULL){
        printf("have 90 \n");
    }

    if (SearchBST(tree, &a53) != NULL){
        printf("have 53 \n");
    }
#endif
    printf("now delete 13 \n");
    int shorter;
    if (DeleteAVL(&tree, a13, &shorter) == 1){
        printf("delete 13 success \n");
    }
    if (isBalanceTree(tree) == 1){
        printf("after delete 13, is balance tree \n");
    } else {
        printf("after delete 13, is not balance tree \n");
    }
    
    printf("GetNodeNum : %d \n", GetNodeNum(tree));
    printf("GetBiTreeDepth : %d \n", GetBSTreeDepth(tree));
    printf("GetLeafNodeNum : %d \n", GetLeafNodeNum(tree));
    printf("GetNodeNumKthLevel 1 : %d \n", GetNodeNumKthLevel(tree, 1));
    printf("GetNodeNumKthLevel 2 : %d \n", GetNodeNumKthLevel(tree, 2));     
    printf("GetNodeNumKthLevel 3 : %d \n", GetNodeNumKthLevel(tree, 3));     

    printf("InVisitBiTree : \n");
    InVisitBSTree(tree);

    printf("now delete 90 \n");
    if (DeleteAVL(&tree, a90, &shorter) == 1){
        printf("delete 90 success \n");
    }
    if (isBalanceTree(tree) == 1){
        printf("after delete 90, is balance tree \n");
    } else {
        printf("after delete 90, is not balance tree \n");
    }


    printf("GetNodeNum : %d \n", GetNodeNum(tree));
    printf("GetBiTreeDepth : %d \n", GetBSTreeDepth(tree));
    printf("GetLeafNodeNum : %d \n", GetLeafNodeNum(tree));
    printf("GetNodeNumKthLevel 1 : %d \n", GetNodeNumKthLevel(tree, 1));
    printf("GetNodeNumKthLevel 2 : %d \n", GetNodeNumKthLevel(tree, 2));     
    printf("GetNodeNumKthLevel 3 : %d \n", GetNodeNumKthLevel(tree, 3));     

    printf("InVisitBiTree : \n");
    InVisitBSTree(tree);

    printf("now delete 37 \n");
    if (DeleteAVL(&tree, a37, &shorter) == 1){
        printf("delete 37 success \n");
    }
    if (isBalanceTree(tree) == 1){
        printf("after delete 37, is balance tree \n");
    } else {
        printf("after delete 37, is not balance tree \n");
    }
    
    printf("GetNodeNum : %d \n", GetNodeNum(tree));
    printf("GetBiTreeDepth : %d \n", GetBSTreeDepth(tree));
    printf("GetLeafNodeNum : %d \n", GetLeafNodeNum(tree));
    printf("GetNodeNumKthLevel 1 : %d \n", GetNodeNumKthLevel(tree, 1));
    printf("GetNodeNumKthLevel 2 : %d \n", GetNodeNumKthLevel(tree, 2));     

    printf("InVisitBiTree : \n");
    InVisitBSTree(tree);
#endif
   
    int a32 = 32;
    int a67 = 67;
    int a25 = 25;
    int a14 = 14;
    int a9 = 9;
    int a27 = 27;

    int taller;
    InsertAVL(&tree, &a32, &taller);
    InsertAVL(&tree, &a67, &taller);
    InsertAVL(&tree, &a25, &taller);
    InsertAVL(&tree, &a14, &taller);
    InsertAVL(&tree, &a9, &taller);
    if (isBalanceTree(tree) == 1){
        printf("after insert 32, 67, 25, 14, 9 \n is balance tree \n");
    } else {
        printf("after insert 32, 67, 25, 14, 9 \n is not balance tree \n");
    }
    printf("GetNodeNum : %d \n", GetNodeNum(tree));
    printf("GetBiTreeDepth : %d \n", GetBSTreeDepth(tree));
    printf("GetLeafNodeNum : %d \n", GetLeafNodeNum(tree));
    printf("GetNodeNumKthLevel 1 : %d \n", GetNodeNumKthLevel(tree, 1));
    printf("GetNodeNumKthLevel 2 : %d \n", GetNodeNumKthLevel(tree, 2));     
    printf("GetNodeNumKthLevel 3 : %d \n", GetNodeNumKthLevel(tree, 3));     

    printf("InVisitBiTree : \n");
    InVisitBSTree(tree);

    InsertAVL(&tree, &a27, &taller);
    printf("insert 27 \n");
    if (isBalanceTree(tree) == 1){
        printf("after insert 27, is balance tree \n");
    } else {
        printf("after insert 27, is not balance tree \n");
    }
    printf("GetNodeNum : %d \n", GetNodeNum(tree));
    printf("GetBiTreeDepth : %d \n", GetBSTreeDepth(tree));
    printf("GetLeafNodeNum : %d \n", GetLeafNodeNum(tree));
    printf("GetNodeNumKthLevel 1 : %d \n", GetNodeNumKthLevel(tree, 1));
    printf("GetNodeNumKthLevel 2 : %d \n", GetNodeNumKthLevel(tree, 2));     
    printf("GetNodeNumKthLevel 3 : %d \n", GetNodeNumKthLevel(tree, 3));     

    printf("InVisitBiTree : \n");
    InVisitBSTree(tree);

    int shorter;
    DeleteAVL(&tree, a32, &shorter);
    if (isBalanceTree(tree) == 1){
        printf("after delete 32, is balance tree \n");
    } else {
        printf("after delete 32, is not balance tree \n");
    }
    DeleteAVL(&tree, a25, &shorter);
    if (isBalanceTree(tree) == 1){
        printf("after delete 25, is balance tree \n");
    } else {
        printf("after delete 25, is not balance tree \n");
    }
    DeleteAVL(&tree, a67, &shorter);
    if (isBalanceTree(tree) == 1){
        printf("after delete 67, is balance tree \n");
    } else {
        printf("after delete 67, is not balance tree \n");
    }
    DeleteAVL(&tree, a14, &shorter);
    if (isBalanceTree(tree) == 1){
        printf("after delete 14, is balance tree \n");
    } else {
        printf("after delete 14, is not balance tree \n");
    }
    printf("the state of the AVL is : \n");
    printf("GetNodeNum : %d \n", GetNodeNum(tree));
    printf("GetBiTreeDepth : %d \n", GetBSTreeDepth(tree));
    printf("GetLeafNodeNum : %d \n", GetLeafNodeNum(tree));
    printf("GetNodeNumKthLevel 1 : %d \n", GetNodeNumKthLevel(tree, 1));
    printf("GetNodeNumKthLevel 2 : %d \n", GetNodeNumKthLevel(tree, 2));     
    printf("GetNodeNumKthLevel 3 : %d \n", GetNodeNumKthLevel(tree, 3));     

    printf("InVisitBiTree : \n");
    InVisitBSTree(tree);

    int ret = DestroyBSTree(tree); 
    if (ret == 0){
        printf("DestroyBiTree success \n");
    }

    return 0;
}
