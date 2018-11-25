#include <stdio.h>

typedef struct binary_tree{
	char ch;
	struct binary_tree* leftnode;
	struct binary_tree* rightnode;
	
}binary_tree;

void recursion(binary_tree* root){   //二叉数递归遍历
	if(root == NULL){
		return;
	}
	
	
	//前序遍历
	
	
	
	recursion(root->leftnode);  //遍历左子树
	
	
	recursion(root->rightnode);  //遍历右子树
	printf("%c",root->ch);      //打印根节点
}

int main(){
	//创建节点
	binary_tree node1 = {'A', NULL, NULL};
	binary_tree node2 = {'B', NULL, NULL};
	binary_tree node3 = {'C', NULL, NULL};
	binary_tree node4 = {'D', NULL, NULL};
	binary_tree node5 = {'E', NULL, NULL};
	binary_tree node6 = {'F', NULL, NULL};
	binary_tree node7 = {'G', NULL, NULL};
	binary_tree node8 = {'H', NULL, NULL};
	//建立关系
	node1.leftnode = &node2;
	node1.rightnode = &node6;
	
	node2.rightnode = &node3;
	node3.leftnode = &node4;
	node3.rightnode = &node5;
	
	node6.rightnode = &node7;
	node7.leftnode = &node8;
	
	
	recursion(&node1);
	
	printf("\n");
	
	
	return 0;
}


