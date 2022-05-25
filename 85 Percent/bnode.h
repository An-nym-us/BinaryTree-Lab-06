/***********************************************************************
 * Header:
 *    BINARY NODE
 * Summary:
 *    One node in a binary tree (and the functions to support them).
 *        ____     _______        __
 *      .' __ '.  |  _____|   _  / /
 *      | (__) |  | |____    (_)/ /
 *      .`____'.  '_.____''.   / / _
 *     | (____) | | \____) |  / / (_)
 *     `.______.'  \______.' /_/
 *
 *
 *    This will contain the class definition of:
 *        BNode         : A class representing a BNode
 *    Additionally, it will contain a few functions working on Node
 * Author
 *    <your names here> 
 ************************************************************************/

#pragma once

#include <iostream>  // for OFSTREAM
#include <cassert>
#include <new> 
#include <memory>  

/*****************************************************************
 * BNODE
 * A single node in a binary tree.  Note that the node does not know
 * anything about the properties of the tree so no validation can be done.
 *****************************************************************/
class BNode
{
public:
   // 
   // Construct
   //
   BNode()             
   {
      pLeft = nullptr;
      pRight = nullptr;
      pParent = nullptr;
      data = int();
   }
   BNode(const int &  t) 
   {
      pLeft = nullptr;
      pRight = nullptr;
      pParent = nullptr;
      data = t;
   }
   BNode(int && t) 
   {
      pLeft = nullptr;
      pRight = nullptr;
      pParent = nullptr;
      data = t;
   }

   // 
   // Data
   //
   BNode * pLeft;
   BNode * pRight;
   BNode * pParent;

   // the data of unknown type: cannot validate so is public
   int data;
};

/*******************************************************************
 * SIZE BTREE
 * Return the size of a b-tree under the current node
 *******************************************************************/
inline size_t size(const BNode * p)
{
   if (p == nullptr)
   {
      return 0;
   }
   else
   {
      return size(p->pLeft) + 1 +size(p->pRight); 
   }

}


/******************************************************
 * ADD LEFT
 * Add a node to the left of the current node
 ******************************************************/
inline void addLeft(BNode * pNode, BNode * pAdd)
{
   if (pAdd != nullptr)
   {
      pAdd->pParent = pNode;
   }
   pNode->pLeft = pAdd;


}

/******************************************************
 * ADD RIGHT
 * Add a node to the right of the current node
 ******************************************************/
inline void addRight (BNode * pNode, BNode * pAdd)
{
   if (pAdd != nullptr)
   {
      pAdd->pParent = pNode;
   }
   pNode->pRight = pAdd;


}

/******************************************************
 * ADD LEFT
 * Add a node to the left of the current node
 ******************************************************/
inline void addLeft (BNode  * pNode, const int & t)
{
   BNode* pAdd = new BNode(t);
   pAdd->pParent = pNode;
   pNode->pLeft = pAdd;

}

inline void addLeft(BNode * pNode, int && t)
{
   BNode* pAdd = new BNode(t);
   pAdd->pParent = pNode;
   pNode->pLeft = pAdd;


}

/******************************************************
 * ADD RIGHT
 * Add a node to the right of the current node
 ******************************************************/
void addRight (BNode  * pNode, const int & t)
{
   BNode* pAdd = new BNode(t);
   pAdd->pParent = pNode;
   pNode->pRight = pAdd;
}

void addRight(BNode * pNode, int && t)
{
   BNode* pAdd = new BNode(t);
   pAdd->pParent = pNode;
   pNode->pRight = pAdd;
}

/*****************************************************
 * DELETE BINARY TREE
 * Delete all the nodes below pThis including pThis
 * using postfix traverse: LRV
 ****************************************************/
void clear(BNode  * & pThis)
{
   if (pThis == nullptr)
   {
      return ;
   }

   clear(pThis->pLeft);
   clear(pThis->pRight);

   pThis = nullptr;
   delete pThis;
}

/***********************************************
 * SWAP
 * Swap the list from LHS to RHS
 *   COST   : O(1)
 **********************************************/
inline void swap(BNode *& pLHS, BNode *& pRHS)
{
   std::swap(pRHS, pLHS);

}

/**********************************************
 * COPY BINARY TREE
 * Copy pSrc->pRight to pDest->pRight and
 * pSrc->pLeft onto pDest->pLeft
 *********************************************/
BNode  * copy(const BNode  * pSrc)
{

   if (pSrc != nullptr)
   {
      BNode* node = new BNode();


      if (pSrc->data)
      {
         node->data = pSrc->data;
      }


      node->pLeft = copy(pSrc->pLeft);
      if (pSrc->pLeft != nullptr)
      {
         node->pLeft->pParent = node;
      }



      node->pRight = copy(pSrc->pRight);
      if (pSrc->pRight != nullptr)
      {
         node->pRight->pParent = node;
      }



      return node;
   }
   else 
   {
      return nullptr;
   }



}

/**********************************************
 * assign
 * copy the values from pSrc onto pDest preserving
 * as many of the nodes as possible.
 *********************************************/
void assign(BNode  * & pDest, const BNode * pSrc)
{

   if (pSrc == nullptr)
   {

      pDest = nullptr;
      return;
   }
   if (pDest == nullptr && pSrc != nullptr)
   {
      //std::cout << "Left was called" << std::endl;

      BNode* node = new BNode(pSrc->data);
      pDest = node;
      assign(pDest->pRight, pSrc->pRight);
      assign(pDest->pLeft, pSrc->pLeft);
   }
   if (pDest != nullptr && pSrc != nullptr)
   {
      //std::cout << "Right was called" << std::endl;
      pDest->data = pSrc->data;

      assign(pDest->pRight, pSrc->pRight);
      assign(pDest->pLeft, pSrc->pLeft);
   }


}
