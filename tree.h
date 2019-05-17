#ifndef TREE_H
#define TREE_H

#include <iostream>

#include "node.h"

using namespace std;

class Tree {
    private:
        Node* root;

        // Node** getNext(Node** pointer, bool side) {
        //     pointer = &((*pointer)->childs[side]);
        //     while ((*pointer)->childs[!side]) {
        //         pointer = &((*pointer)->childs[!side]);
        //     }
        //
        //     return pointer;
        // }

        void printInOrder(Node* root) {
            if (root) {
                printInOrder(root->left);
                cout << root->data << " ";
                printInOrder(root->right);
            }
        }

        bool is_op (char data, Node* node) {
          switch (data) {
            case '+':
              node->weight = 1;
              return true;
            default:
              return false;
          }
        }

    public:
      Node* insert_func(Node* node, char data) {
          if (node == NULL) {
            node = new Node;
            root = node;
            root->left = NULL;
            root->right = NULL;
            root->data = data;
          }


          if (is_op(data, node)) {
            root = node;
          }

          else {
            if (data < node->data) {
              node->left = insert_func(node->left, data);
              root = node;
            }
            if (data > node->data) {
              node->right = insert_func(node->right, data);
              root = node;
            }
          }

          return node;
        }


        bool insert(char data) {
            Node* tmp = insert_func(root, data);

            if (tmp != NULL) {
              return true;
            }


            else {
              return false;
            }
          }


      void printInOrder() {
              printInOrder(root);
              std::cout << "alo?" << '\n';
          }


};

#endif
