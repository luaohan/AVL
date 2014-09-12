#include <stdio.h>
#include <stdlib.h>

#include "avl.h"

static void R_Rotate(BSTree *tree)
{
    BSTree lc;

    lc = (*tree)->lchild;
    (*tree)->lchild = lc->rchild;
    lc->rchild = (*tree);
    (*tree) = lc;

}

static void L_Rotate(BSTree *tree)
{
    BSTree rc;

    rc = (*tree)->rchild;
    (*tree)->rchild = rc->lchild;
    rc->lchild = (*tree);
    (*tree) = rc;

}

static void LeftBalance(BSTree *T)
{
    BSTree lc, rd;
    lc = (*T)->lchild;
    switch(lc->bf)
    {
        case LH: //R_Rotate
            (*T)->bf = lc->bf = EH;
            R_Rotate(T);
            break;
        case RH:
            rd = lc->rchild;
            switch(rd->bf) // note
            {   
                case LH:
                    (*T)->bf = RH;  lc->bf = EH;  break;
                case EH:
                    (*T)->bf = lc->bf = EH;  break;
                case RH:
                    (*T)->bf = EH;  lc->bf = LH;  break;
            }
            rd->bf = EH;
            L_Rotate( &((*T)->lchild) );
            R_Rotate(T);
    }
}

static void RightBalance(BSTree *T) 
{ 
    BSTree rc,rd; 
    rc = (*T)->rchild; 
    switch(rc->bf)
    { 
        case RH: 
            (*T)->bf = rc->bf = EH; 
            L_Rotate(T); 
            break; 
        case LH: 
            rd = rc->lchild; 
            switch(rd->bf) // note 
            { 
                case RH:  
                    (*T)->bf = LH; rc->bf = EH; break; 
                case EH:  
                    (*T)->bf = rc->bf = EH;  break; 
                case LH: 
                    (*T)->bf = EH; rc->bf = RH; break; 
            } 
            rd->bf = EH; 
            R_Rotate( &((*T)->rchild) ); 
            L_Rotate(T); 
    }  
}

int InsertAVL(BSTree *T, ElemType *e, int *taller)
{
    if (*T == NULL)
    {
        *T = (BSTree)malloc( sizeof(BSTNode) );
        if (*T == NULL)
        {
            return ERROR;
        }

        (*T)->data = *e;
        (*T)->lchild = (*T)->rchild = NULL;
        (*T)->bf = EH;

        *taller = TRUE;
    } 
    else 
    {
        if (*e == (*T)->data)
        {
            *taller = FALSE;
            return FALSE;
        }

        if (*e < (*T)->data) //insert to T->lchild
        {
            if (InsertAVL( &((*T)->lchild), e, taller) == -1) // no insert
            {
                return FALSE;
            }

            //inserted
            if (*taller == TRUE) //taller
            {
                switch((*T)->bf)
                {
                    case LH:
                        LeftBalance(T);  *taller = FALSE;  break;
                    case EH:
                        (*T)->bf = LH;  *taller = TRUE;  break;
                    case RH:
                        (*T)->bf = EH;  *taller = FALSE;  break;
                }
            }
        } 
        else  //insert to T->rchild
        {
            if (InsertAVL( &((*T)->rchild), e, taller) == -1) //no insert
            {
                return FALSE;
            }

            //inserted
            if (*taller == TRUE)
            {
                switch ((*T)->bf)
                {
                    case LH:
                        (*T)->bf = EH;  *taller = FALSE;  break;
                    case EH:
                        (*T)->bf = RH;  *taller = TRUE;  break;
                    case RH:
                        RightBalance(T);  *taller = FALSE;  break;
                }
            }
        }
    }

    return OK;
}

BSTree SearchBST(BSTree T, ElemType *e)
{                                     
    if (T == NULL || T->data == *e){                                         
        return T;                                                            
    } else if (*e < T->data){                                                
        return SearchBST(T->lchild, e);                                      
    } else {
        return SearchBST(T->rchild, e);                                      
    }                                                                        

}    

static void LeftBalance_div(BSTree *p, int *shorter)
{
    BSTree  p1,p2;
    if((*p)->bf == 1){ //p缁撶偣鐨勫乏瀛愭爲楂橈紝鍒犻櫎缁撶偣鍚巔鐨刡f鍑?,鏍戝彉鐭?
        (*p)->bf = 0; 
        *shorter = 1; 

    } else if ((*p)->bf == 0){ //p缁撶偣宸︺€佸彸瀛愭爲绛夐珮锛屽垹闄ょ粨鐐瑰悗p鐨刡f鍑?,鏍戦珮涓嶅彉
        (*p)->bf = -1; 
        *shorter = 0; 
    } else {  //p缁撶偣鐨勫彸瀛愭爲楂?
        p1 = (*p)->rchild;//p1鎸囧悜p鐨勫彸瀛愭爲
        if(p1->bf == 0){  //p1缁撶偣宸︺€佸彸瀛愭爲绛夐珮,鍒犻櫎缁撶偣鍚巔鐨刡f涓?2,
            //杩涜宸︽棆澶勭悊锛屾爲楂樹笉鍙?
            L_Rotate(p);
            p1->bf = 1; 
            (*p)->bf = 1; // !!!!!!!
            *shorter = 0;
        } else if (p1->bf == -1){ //p1鐨勫彸瀛愭爲楂橈紝宸︽棆澶勭悊鍚庯紝鏍戝彉鐭?
            L_Rotate(p);
            p1->bf = (*p)->bf = 0; 
            *shorter = 1;
        } else { //p1鐨勫乏瀛愭爲楂?杩涜鍙屾棆澶勭悊(鍏堝彸鏃嬪悗宸︽棆)锛屾爲鍙樼煯
            p2 = p1->lchild;
            p1->lchild = p2->rchild; 
            p2->rchild = p1; 
            (*p)->rchild = p2->lchild; 
            p2->lchild = *p;

            if (p2->bf == 0){ 
                (*p)->bf = 0; 
                p1->bf = 0; 
            } else if (p2->bf == -1){ 
                (*p)->bf = 1;
                p1->bf = 0; 
            } else { 
                (*p)->bf = 0;
                p1->bf = -1; 
            }

            p2->bf = 0; 
            (*p) = p2; 
            *shorter = 1;
        }
    }
}

static void RightBalance_div(BSTree *p, int *shorter)
{
    BSTree  p1,p2;
    if ((*p)->bf == -1){ 
        (*p)->bf = 0; 
        *shorter = 1; 
    } else if ((*p)->bf == 0){ 
        (*p)->bf = 1; 
        *shorter = 0; 
    } else {
        p1 = (*p)->lchild;
        if (p1->bf == 0) {
            R_Rotate(p);
            p1->bf = -1; 
            (*p)->bf = 1; 
            *shorter = 0;
        } else if (p1->bf == 1) {
            R_Rotate(p);
            p1->bf = (*p)->bf = 0; 
            *shorter = 1;
        } else {
            p2 = p1->rchild; 
            p1->rchild = p2->lchild; 
            p2->lchild = p1; 
            (*p)->lchild = p2->rchild; 
            p2->rchild = (*p); 

            if (p2->bf == 0) { 
                (*p)->bf = 0; 
                p1->bf = 0; 
            } else if (p2->bf==1) { 
                (*p)->bf = -1; 
                p1->bf = 0; 
            } else { 
                (*p)->bf = 0; 
                p1->bf = 1; 
            }

            p2->bf = 0; 
            (*p) = p2; 
            *shorter = 1;
        }
    }
}

static void Delete(BSTree q, BSTree  *r, int *shorter)
{
    if ((*r)->rchild == NULL){
        q->data = (*r)->data; 
        q = (*r);
        (*r) = (*r)->lchild; 
        free(q);
        *shorter = 1;
    } else { 
        Delete(q, &((*r)->rchild), shorter);
        if ((*shorter) == 1) {
            RightBalance_div(r,shorter);
        }
    }
}

int DeleteAVL(BSTree *p,int x, int *shorter)
{
    int k;
    BSTree q;
    if ((*p) == NULL) { 
        printf("涓嶅瓨鍦ㄨ鍒犻櫎鐨勫叧閿瓧!!\n"); 
        return 0;
    } else if ( x < (*p)->data ) { //鍦╬鐨勫乏瀛愭爲涓繘琛屽垹闄?
        k = DeleteAVL(&((*p)->lchild), x, shorter);
        if ( *shorter == 1){
            LeftBalance_div(p, shorter);
        }
        return k;
    } else if ( x > (*p)->data ) { //鍦╬鐨勫彸瀛愭爲涓繘琛屽垹闄?
        k = DeleteAVL( &((*p)->rchild), x, shorter);
        if (*shorter == 1){
            RightBalance_div(p, shorter);
        }
        return k;
    } else {
        q = *p;
        if ((*p)->rchild == NULL) //鍙冲瓙鏍戠┖鍒欏彧闇€閲嶆帴瀹冪殑宸﹀瓙鏍?
        {
            (*p) = (*p)->lchild; 
            free(q); 
            *shorter = 1; 
        } else if ((*p)->lchild == NULL) {  //宸﹀瓙鏍戠┖鍒欏彧闇€閲嶆帴瀹冪殑鍙冲瓙鏍?
            (*p) = (*p)->rchild; 
            free(q); 
            *shorter = 1; 
        } else { //宸﹀彸瀛愭爲鍧囦笉绌?
            Delete(q, &(q->lchild), shorter);
            if (*shorter == 1){
                LeftBalance_div(p, shorter);
            }

            (*p) = q; 
        }
        return 1;
    }
}

#if 0    
 
          //it is wrong !!!!!

int DeleteAVL(BSTree *T, int key, int *shorter){  
    if (*T == NULL)  
    {//No such key  
        *shorter = FALSE;  
        return 0;  
    }  
    else  
    {  
        if (key == (*T)->data)    //鎵惧埌浜嗛渶瑕佸垹闄ょ殑缁撶偣  
        {  
            //濡傛灉璇ョ粨鐐圭殑lchild 鍜? 
            //rchild 鑷冲皯鏈変竴涓负NULL  
            //鍒欏ぇ鍔熷憡鎴愶紝鍚﹀垯璇峰弬鐓? 
            //涓嬫柟瑙ｉ噴  
            BSTree q = *T;  
            if ((*T)->lchild == NULL)//濡傛灉璇ョ粨鐐圭殑lchild 涓篘ULL  
            {  
                (*T) = (*T)->rchild;  
                free(q);  
                *shorter = TRUE;  
                return 1;  
            }  
            else if ((*T)->rchild == NULL){//濡傛灉璇ョ粨鐐圭殑rchild 涓?NULL  
                (*T) = (*T)->lchild;//濡傛灉涓嶆槸&锛堝紩鐢級鐨勫己澶у姛鑳斤紝杩欏彞璇濇槸娌℃湁鎰忎箟鐨? 
                free(q);  
                *shorter = TRUE;  
                return 1;  
            }  
            else {  
                //鍒犻櫎涓€涓乏鍙冲瀛愰兘涓嶄负绌虹殑缁撶偣  
                //浣胯缁撶偣鐨勭洿鎺ュ墠椹眕鐨刣ata鏇挎崲璇ョ粨鐐圭殑data  
                //鐒跺悗鏀瑰彉key=p.data  
                BSTree s = (*T)->lchild;  
                while (s->rchild)  
                    s = s->rchild;  
                (*T)->data = s->data;  
                key = s->data;//Now, delete the vertice whose data was the new key  
            }  
        }  
        if (key < (*T)->data){//杩欓噷涓嶪nsertAVL涓嶅悓  
            if (!DeleteAVL(&((*T)->lchild), key, shorter)) return 0;  
            if (*shorter == TRUE){  
                switch((*T)->bf){  
                    case LH:(*T)->bf = EH; *shorter = TRUE;break;  
                    case EH:(*T)->bf = RH; *shorter = FALSE;break;  
                    case RH:RightBalance(T);   
                            if ((*T)->rchild->bf == EH)  
                                *shorter = FALSE;  
                            else   
                                *shorter = TRUE;break;  
                }  
            }  
        }  
        else{  
            if (!DeleteAVL(&((*T)->rchild), key, shorter)) return 0;  
            if (*shorter == TRUE){  
                switch((*T)->bf){  
                    case LH:LeftBalance(T);  
                            if ((*T)->lchild->bf == EH)  
                                *shorter = FALSE;  
                            else   
                                *shorter = TRUE;break;  
                    case EH:(*T)->bf = LH; *shorter = FALSE;break;  
                    case RH:(*T)->bf = EH; *shorter = TRUE;break;  
                }  
            }  
        }  
    }  
    return 1;  
}//Delete  

#endif

int DestroyBSTree(BSTree T) 
{
    if(T != NULL)                                                               
    {  
        DestroyBSTree(T->lchild);                                               
        DestroyBSTree(T->rchild);                                               
        free( T );  
        T = NULL;                                                               

        return OK;                                                              
    }  

    return ERROR;
}   

int GetNodeNum(BSTree T)
{
    if (T == NULL){
        return 0;
    }

    return GetNodeNum(T->lchild) + GetNodeNum(T->rchild) + 1;
} 

int GetBSTreeDepth(BSTree T)
{
    if (T == NULL){
        return 0;
    }

    int num_left = GetBSTreeDepth(T->lchild);
    int num_right = GetBSTreeDepth(T->rchild);

    return num_left > num_right ? (num_left + 1) : (num_right + 1);

}

void Visit(BSTree T)
{
    printf("%d, ", T->data);
    return ;
}

void PreVisitBSTree(BSTree T)
{
    if (T == NULL){
        return ;
    }

    Visit(T);

    PreVisitBSTree(T->lchild);
    PreVisitBSTree(T->rchild);

    return ;
}

void InVisitBSTree(BSTree T)
{
    if (T == NULL){
        return ;
    }

    InVisitBSTree(T->lchild);
    Visit(T);
    InVisitBSTree(T->rchild);

    return ;
}

void PostVisitBSTree(BSTree T)
{
    if (T == NULL){
        return ; 
    }

    PostVisitBSTree(T->lchild);
    PostVisitBSTree(T->rchild);
    Visit(T);

    return ;
}

int GetNodeNumKthLevel(BSTree T, int k)  
{  
    if( T == NULL || k < 1 ){ 
        return 0;  
    }

    if(k == 1){
        return 1;
    }

    int numLeft = GetNodeNumKthLevel(T->lchild, k-1); // 宸﹀瓙鏍戜腑k-1灞傜殑鑺傜偣涓暟  
    int numRight = GetNodeNumKthLevel(T->rchild, k-1); // 鍙冲瓙鏍戜腑k-1灞傜殑鑺傜偣涓暟  

    return (numLeft + numRight);  
}  

int GetLeafNodeNum(BSTree T)  
{  
    if(T == NULL) { 
        return 0;  
    }

    if(T->lchild == NULL && T->rchild == NULL) {
        return 1;
    }

    int numLeft = GetLeafNodeNum(T->lchild); // 宸﹀瓙鏍戜腑鍙惰妭鐐圭殑涓暟  
    int numRight = GetLeafNodeNum(T->rchild); // 鍙冲瓙鏍戜腑鍙惰妭鐐圭殑涓暟 

    return (numLeft + numRight);
}

int isBalanceTree(BSTree T) 
{  
    if ( T == NULL ) {  
        return TRUE;  
    }  

    int depthLeft = GetBSTreeDepth(T->lchild);  
    int depthRight = GetBSTreeDepth(T->rchild);  

    if (abs( depthLeft - depthRight ) > 1) { 
        return FALSE;  
    } else { 
        return (isBalanceTree(T->lchild) == TRUE ) && 
            (isBalanceTree(T->rchild) == TRUE );  
    }
}  

