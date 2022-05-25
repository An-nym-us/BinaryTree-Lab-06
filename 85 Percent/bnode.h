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
   return 99;
}


/******************************************************
 * ADD LEFT
 * Add a node to the left of the current node
 ******************************************************/
inline void addLeft(BNode * pNode, BNode * pAdd)
{

}

/******************************************************
 * ADD RIGHT
 * Add a node to the right of the current node
 ******************************************************/
inline void addRight (BNode * pNode, BNode * pAdd)
{

}

/******************************************************
 * ADD LEFT
 * Add a node to the left of the current node
 ******************************************************/
inline void addLeft (BNode  * pNode, const int & t)
{

}

inline void addLeft(BNode * pNode, int && t)
{

}

/******************************************************
 * ADD RIGHT
 * Add a node to the right of the current node
 ******************************************************/
void addRight (BNode  * pNode, const int & t)
{

}

void addRight(BNode * pNode, int && t)
{

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
      return;
   }
   clear(pThis->pLeft);
   clear(pThis->pRight);
   delete pThis;

}

/***********************************************
 * SWAP
 * Swap the list from LHS to RHS
 *   COST   : O(1)
 **********************************************/
inline void swap(BNode *& pLHS, BNode *& pRHS)
{

}

/**********************************************
 * COPY BINARY TREE
 * Copy pSrc->pRight to pDest->pRight and
 * pSrc->pLeft onto pDest->pLeft
 *********************************************/
BNode  * copy(const BNode  * pSrc)
{

   if (pSrc)
   {

      BNode* node = new BNode();


      if (pSrc->data)
      {
         node->data = pSrc->data;

      };


      if (!node->pLeft)
      {
         //std::cout << "Left was called" << std::endl;


      }



      if (!node->pRight)
      {
        // std::cout << "Right was called" << std::endl;


        // node->pRight->pParent = node;
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
      //clear(pDest);
      pDest = nullptr;
      return;
   }
   if (pDest == nullptr && pSrc != nullptr)
   {
      //std::cout << "This was  was called" << std::endl;
      pDest = new BNode(pSrc->data);
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
