/********************************FILE HEADER*********************************/
/* Author: Pin Chu, A98041513
 *
 * Filename: BST.hpp
 * Date  : April 8 2015
 * Description: This file includes method to build a BST. There are construc-
 * tor, destructor, insert, find, size, clear, empty, begin, and some 
 * additional methods that I added to help me with the starter codes.
 *
 */
/****************************************************************************/
#ifndef BST_HPP
#define BST_HPP
#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <utility> // for std::pair

template<typename Data>
class BST {

protected:

  /** Pointer to the root of this BST, or nullptr if the BST is empty */
  BSTNode<Data>* root;

  /** Number of Data items stored in this BST. */
  unsigned int isize;


public:

  /** iterator is an aliased typename for BSTIterator<Data>. */
  typedef BSTIterator<Data> iterator;

  /** Default constructor.
      Initialize an empty BST.
   */
  BST() : root(nullptr), isize(0)  {
  }


  /** Default destructor.
   *  It is virtual, to allow appropriate destruction of subclass objects.
   *  Delete every node in this BST.
   */ // TODO
  virtual ~BST() {
      clear();
  }

  /** Insert a Data item in the BST.
   *  Return a pair, with the pair's first member set to an
   *  iterator pointing to either the newly inserted element
   *  or to the equivalent element already in the set.
   *  The pair's second element is set to true
   *  if a new element was inserted or false if an
   *  equivalent element already existed.
   */ // TODO
  virtual std::pair<iterator,bool> insert(const Data& item) {
      if (root == 0) {
          root = new BSTNode<Data>(item);
          isize++;
          return std::pair<iterator, bool>(iterator(root), true);
      }
      else{
          // Initiate two variables representing current and previous node
          BSTNode<Data>* curr = root;
          BSTNode<Data>* temp = 0;
          // Find a spot to insert
          while(curr != 0){
              if(item < curr -> data){
                  temp = curr;
                  curr = curr -> left;
              }
              else if(curr -> data < item){
                  temp = curr;
                  curr = curr -> right;
              }
              else{ // Already exists in BST
                  return std::pair<iterator,bool>(iterator(curr),false);
              }
          }
          // Inserting the new node into BST
          BSTNode<Data>* node = new BSTNode<Data>(item);
          // If value of item is less than temp's data, item is left child
          if(item < temp -> data){
              temp -> left = node;
              node -> parent = temp;
              isize++;
              return std::pair<iterator, bool>(iterator(temp->left), true);

          }
          // If value of item is greater than temp's data, item is right child
          else{
              temp -> right = node;
              node -> parent = temp;
              isize++;
              return std::pair<iterator, bool>(iterator(temp->right), true);

          }
      }

  }


  /** Find a Data item in the BST.
   *  Return an iterator pointing to the item, or the end
   *  iterator if the item is not in the BST.
   */ // TODO
  iterator find(const Data& item) const {
      BSTNode<Data>* curr = root;
      if(curr == 0)
          return end();
      while(1){
          //Going Left
          if (item < curr -> data)
              curr = curr -> left;
          //Going right
          else if(curr -> data < item)
              curr = curr -> right;
          //Find it!
          else
              return typename BST<Data>::iterator(curr);
      }
  }

  
  /** Return the number of items currently in the BST.
   */ // TODO
  unsigned int size() const {
          return isize;
  }

  /** Remove all elements from this BST, and destroy them,
   *  leaving this BST with a size of 0.
   */ // TODO
  void clear() {
      BSTNode<Data>* curr = root;
      deleteAll(curr);
      isize = 0;
  }

  /** Return true if the BST is empty, else false.
   */ // TODO
  bool empty() const {
      if(isize == 0)
          return true;
      else
          return false;
  }

  /** Return an iterator pointing to the first item in the BST.
   */ // TODO
  iterator begin() const {
      BSTNode<Data>* curr = root;
      if(curr == 0)
          return end();
      while (curr -> left != 0) {
          curr = curr -> left;
      }
      return typename BST<Data>::iterator(curr);
  }

  /** Return an iterator pointing past the last item in the BST.
   */
  iterator end() const {
    return typename BST<Data>::iterator(nullptr);
  }

private:
    // A method is used for BST destructor to delete all the nodes in the tree.
    void deleteAll(BSTNode<Data> *&n){
        if(n == 0)
            return;
        //RECURSIVE
        deleteAll(n -> left);
        deleteAll(n -> right);
        delete n;
        isize = 0;
    }
  

 };


#endif //BST_HPP

