#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct BSTNode {
    ElemType data;
    struct BSTNode *lchild;
    struct BSTNode *rchild;
} BSTNode, *BSTree;

// 查找（递归）
BSTNode *searchBST_R(BSTree T, ElemType key) {
    if (T == NULL)
        return NULL;
    else if (T->data == key)
        return T;
    else if (T->data > key)
        return searchBST_R(T->lchild, key);
    else // T->data < key
        return searchBST_R(T->rchild, key);
}

// 查找（迭代）
BSTNode *searchBST(BSTree T, ElemType key) {
    while (T != NULL && T->data != key) {
        if (T->data > key)
            T = T->lchild;
        else if (T->data < key)
            T = T->rchild;
    }
    return T;
}

// 插入
int insertBST(BSTree *T, ElemType key) {
    if (*T == NULL) {
        *T = (BSTNode *)malloc(sizeof(BSTNode));
        if (*T == NULL) return 0; // 内存分配失败
        (*T)->data = key;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
        return 1;
    } else if ((*T)->data == key) {
        return 0; // 重复节点
    } else if ((*T)->data > key) {
        return insertBST(&(*T)->lchild, key);
    } else {
        return insertBST(&(*T)->rchild, key);
    }
}

void buildBST(BSTree *T, ElemType key[], int n) {
    *T = NULL; // 初始化树为空
    for (int i = 0; i < n; i++) {
        insertBST(T, key[i]);
    }
}

// 删除节点
int deleteBST(BSTree *T, ElemType key) {
    if (*T == NULL)
        return 0;

    if (key < (*T)->data) {
        return deleteBST(&(*T)->lchild, key);
    } else if (key > (*T)->data) {
        return deleteBST(&(*T)->rchild, key);
    } else {
        // 找到要删除的节点
        if ((*T)->lchild == NULL && (*T)->rchild == NULL) {
            // 1. 该节点是叶子节点
            free(*T);
            *T = NULL;
        } else if ((*T)->lchild == NULL) {
            // 2. 该节点只有右子节点
            BSTNode *temp = *T;
            *T = (*T)->rchild;
            free(temp);
        } else if ((*T)->rchild == NULL) {
            // 2. 该节点只有左子节点
            BSTNode *temp = *T;
            *T = (*T)->lchild;
            free(temp);
        } else {
            // 3. 该节点有两个子节点
            BSTNode *temp = (*T)->rchild;
            while (temp->lchild != NULL) {
                temp = temp->lchild;
            }
            (*T)->data = temp->data; // 用右子树中最小节点的值替换当前节点的值
            return deleteBST(&(*T)->rchild, temp->data); // 删除右子树中的最小节点
        }
        return 1;
    }
}

// 中序遍历（用于测试）
void inorderTraversal(BSTree T) {
    if (T != NULL) {
        inorderTraversal(T->lchild);
        printf("%d ", T->data);
        inorderTraversal(T->rchild);
    }
}

int main() {
    BSTree T;
    ElemType keys[] = {50, 30, 20, 40, 70, 60, 80};
    int n = sizeof(keys) / sizeof(keys[0]);

    buildBST(&T, keys, n);
    printf("中序遍历结果: ");
    inorderTraversal(T);
    printf("\n");

    printf("删除节点 20\n");
    deleteBST(&T, 20);
    printf("中序遍历结果: ");
    inorderTraversal(T);
    printf("\n");

    printf("删除节点 30\n");
    deleteBST(&T, 30);
    printf("中序遍历结果: ");
    inorderTraversal(T);
    printf("\n");

    printf("删除节点 50\n");
    deleteBST(&T, 50);
    printf("中序遍历结果: ");
    inorderTraversal(T);
    printf("\n");

    return 0;
}
