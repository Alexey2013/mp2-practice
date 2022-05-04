#pragma once 
#include "BSTree.h"
#include <iostream>
using namespace std;
#define PTBalanceNode TbNode<TData,TKey>*

//����� ����� ��� ������
template <typename TData, typename TKey>
class  TbNode : public TrNode<TData, TKey> 
{ protected:
  int balance; // ������ ������������ ������� (-1,0,1)
  public:
  // ������������
  TbNode(TKey k = {}, TData d = {}, TrNode* P = nullptr, TrNode* R = nullptr, TrNode* L = nullptr, int bal = 0): TrNode<TData, TKey> (k, d, P, L, R), balance(bal) {};
  //������
  int GetBalance() const { return balance; }
  void SetBalance(int bal) { balance = bal; }
};

//����� ��� ������
template <typename TData, typename TKey>
class  AVLTree : public BSTree<TData, TKey>
{ protected:
  //������
  int Insert(PTBalanceNode& N1, TKey k, TData d);
  int Delete(PTBalanceNode& N1, TKey k);
  int LeftBal(PTBalanceNode& N1);                        
  int RightBal(PTBalanceNode& N1);                       
  public:
  // ������������
  AVLTree() :BSTree<TData, TKey>() {}                                       
  //������
  void Insert(TKey k, TData d);                  
  void Delete(TKey k);                             
};

// P�������� �������� ��� ������ ��� ������
template <typename TData, typename TKey>
void AVLTree<TData, TKey>::Insert(TKey k, TData d) 
{ if(Find(k)!=nullptr)
  {throw 1;}
  Insert((PTBalanceNode&)Root, k, d); }
template <typename TData, typename TKey>
int AVLTree<TData, TKey>::Insert(PTBalanceNode& N1, TKey k, TData d) 
{ if (N1 == nullptr) 
  { N1= new TbNode<TData, TKey>(k, d);
    return 1; 
  }
  if (k < N1->GetKey()) 
  { if (N1->Left == nullptr) // ������� �������
    { N1->Left = new TbNode<TData, TKey>(k, d, N1);
      return LeftBal(N1);
    }
    if (Insert((PTBalanceNode&)(N1->Left), k, d) == 1) // ����� ������� ������ ������ ��������� ����������� - ������������
    { return LeftBal(N1);}
  }
  if (k > N1->GetKey())
  { if (N1->Right == nullptr)   // ������� �������
    { N1->Right = new TbNode<TData, TKey>(k, d, N1);
    return RightBal(N1);           
    }
    if (Insert((PTBalanceNode&)(N1->Right), k, d) == 1) // ����� ������� ������ ������� ��������� ����������� - ������������
    { return RightBal(N1); }
  }
} 
template <typename TData, typename TKey>
void AVLTree<TData, TKey>::Delete(TKey k)
{ if(Find(k)==nullptr)
  {throw 1;}
  Delete((PTBalanceNode&)Root, k); 
}
template <typename TData, typename TKey>
int AVLTree<TData, TKey>::Delete(PTBalanceNode& N1, TKey k)
{ if (k < N1->GetKey())
  { if (Delete((PTBalanceNode&)N1->Left, k) == 0)
    return RightBal(N1);
  }
  else
  { if (k > N1->GetKey())
    { if (Delete((PTBalanceNode&)N1->Right, k) == 0)
      return LeftBal(N1);
    }
    else
    { BSTree::Delete(N1->GetKey());
      return 0; }
  }
}
template <typename TData, typename TKey>
int AVLTree<TData, TKey>::LeftBal(PTBalanceNode& N1) 
{ switch (N1->GetBalance()) 
  { case 1: N1->SetBalance(0);   // � ��������� ��� ������� ������
           break;               // ��������������� ����������
    case 0: N1->SetBalance(-1);  // � ��������� ���� ����������
            break;               // ��������������� ������� �����
    case -1:                     // � ��������� ��� ������� ����� - ���������� ������������
           PTBalanceNode p1;
           PTBalanceNode p2;
           PTBalanceNode p3;
           p1 = (PTBalanceNode)(N1->Left);
           p3 = (PTBalanceNode)(*N1).Parent;
           if (p1->GetBalance() == -1)   // ������ 1 - ����������� LL �������
           { //1
             if (p1->Right!= nullptr)
             { (*(p1->Right)).Parent = N1; }
             N1->Left = p1->Right;  
             //2
             if (N1 != nullptr)
             { (*(N1)).Parent = p1; }
             p1->Right = N1;       
             N1->SetBalance(0); 
             (*p1).Parent = p3;
             N1 = p1;
           }
           else  // ������ 2 - ���������� LR �������
           { p2 = (PTBalanceNode)(p1->Right);
             //1
             if (p2->Left != nullptr)
             { (*(p2->Left)).Parent = p1; }
             p1->Right = p2->Left;
             //2
             if (p1 != nullptr) 
             { (*p1).Parent = p2;}
             p2->Left = p1;
             //3
             if (p2->Right != nullptr)
             { (*(p2->Right)).Parent = N1; }
             N1->Left = p2->Right;
             //4
             if (N1 != nullptr) 
             { (*N1).Parent = p2; }
             p2->Right = N1;
             if (p2->GetBalance() == -1) N1->SetBalance(1);
             else N1->SetBalance(0);  
             if (p2->GetBalance() == 1) N1->SetBalance(-1);
             else p1->SetBalance(0);     
             (*p2).Parent= p3;
             N1 = p2;
           }
           N1->SetBalance(0); 
   }
  return abs(N1->GetBalance());
}       
template <typename TData, typename TKey>
int AVLTree<TData, TKey>::RightBal(PTBalanceNode& N1) 
{ switch (N1->GetBalance())
  { case -1: N1->SetBalance(0);        // � ��������� ��� ������� �����
             break;                    // ��������������� ����������
    case 0:  N1->SetBalance(1);        // � ��������� ���� ����������
             break;                    // ��������������� ������� ������
    case 1:  // � ��������� ��� ������� ������ - ���������� ������������
             PTBalanceNode p1;
             PTBalanceNode p2;
             PTBalanceNode p3 = (PTBalanceNode)(*N1).Parent;
             p1 = (PTBalanceNode)(N1->Right);
             if (p1->GetBalance() == 1) // ������ 1 - ����������� RR �������
             { //1
               if (p1->Left != nullptr)
               { (*p1->Left).Parent = N1; }
               N1->Right = p1->Left; 
               //2
               if (N1 != nullptr)
               { (*N1).Parent = p1; }
               p1->Left = N1;
               N1->SetBalance(0);   
               N1 = p1;
               (*p1).Parent = p3;
             }
             else // ������ 2 - ���������� RL �������
             { p2 = (PTBalanceNode)(p1->Left);
               //1
               if (p2->Right != nullptr)
               { (*(p2->Right)).Parent = p1; }
               p1->Left = p2->Right;    
               //2
               if (p1 != nullptr)
               { (*(p1)).Parent = p2; }
               p2->Right = p1;      
               //3
               if (p2->Left != nullptr)
               { (*p2->Left).Parent = N1; }
               N1->Right = p2->Left;      
               //4
               if (N1 != nullptr)
               { (*N1).Parent = p2; }
               p2->Left = N1;   
               if (p2->GetBalance() == 1) N1->SetBalance(-1);
               else N1->SetBalance(0);  
               if (p2->GetBalance() == -1) N1->SetBalance(1);
               else p1->SetBalance(0);     
               (*p2).Parent = p3;
               N1 = p2;
             }
             N1->SetBalance(0); 
  }
  return abs(N1->GetBalance());;
}
