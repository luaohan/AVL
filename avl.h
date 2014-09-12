// avl.h (2014-09-03)
// WangPeng (1245268612@qq.com)

#ifndef _AVL_H_
#define _AVL_H_


#define OK 0
#define TRUE 1
#define FALSE -1
#define ERROR -1

#define LH 1      //Light High
#define EH 0      //Equal High
#define RH -1     //Right High

typedef int ElemType;

typedef struct BSTNode
{
    ElemType data;
    int bf;          // balance factor
    struct BSTNode *lchild, *rchild;

}BSTNode, *BSTree;

static void R_Rotate(BSTree *tree);
static void L_Rotate(BSTree *tree);

static void LeftBalance(BSTree *tree);
static void RightBalance(BSTree *tree);

//鑻?tree 涓笉瀛樺湪 e锛屽垯鎻掑叆 e, 骞惰繑鍥?0锛?
//鍚﹀垯杩斿洖 -1锛?
//鑻?tree 鍥犳彃鍏ユ搷浣滆€屽け琛★紝鍒欏仛骞宠　澶勭悊锛?
//taller 鏍囪 tree 鏄惁闀块珮
int InsertAVL(BSTree *tree, ElemType *e, int *taller);

//鎴愬姛杩斿洖鎸囧悜璇ュ厓绱犵粨鐐圭殑鎸囬拡锛屽惁鍒欒繑鍥炵┖                             
BSTree SearchBST(BSTree T, ElemType *e);

static void LeftBalance_div(BSTree *p,int *shorter);//鍒犻櫎缁撶偣鏃跺乏骞宠　鏃嬭浆澶勭悊
static void RightBalance_div(BSTree *p,int *shorter);//鍒犻櫎缁撶偣鏃跺彸骞宠　鏃嬭浆澶勭悊
static void Delete(BSTree q,BSTree  *r,int *shorter);//鍒犻櫎缁撶偣
int DeleteAVL(BSTree *p,int x,int *shorter);//骞宠　浜屽弶鏍戠殑鍒犻櫎鎿嶄綔          

int DestroyBSTree(BSTree T);

void Visit(BSTree T);  
void PreVisitBSTree(BSTree T);                                                
void InVisitBSTree(BSTree T);                                                 
void PostVisitBSTree(BSTree T);                                               

//姹備簩鍙夋爲绗琄灞傜殑鑺傜偣涓暟                                                      
int GetNodeNumKthLevel(BSTree T, int k);                                      
//姹備簩鍙夋爲涓彾瀛愯妭鐐圭殑涓暟                                                     
int GetLeafNodeNum(BSTree T);        
int GetNodeNum(BSTree T);                                                     
int GetBSTreeDepth(BSTree T);     
int isBalanceTree(BSTree T);  

#endif
