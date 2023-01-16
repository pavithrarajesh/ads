#include <iostream>
#include <cstdlib>

const int MAX_KEYS = 3;
const int MIN_KEYS = MAX_KEYS - 1;
struct Node {
  int num_keys;
  int keys[MAX_KEYS];
  Node* children[MAX_KEYS + 1];
  bool is_leaf;
};


Node* create_node() {
  Node* node = new Node;
  node->num_keys = 0;
  node->is_leaf = true;
  for (int i = 0; i < MAX_KEYS + 1; i++) {
    node->children[i] = NULL;
  }
  return node;
}


void insert_key(Node* node, int key) {

  int i = node->num_keys - 1;
  while (i >= 0 && key < node->keys[i]) {
    node->keys[i + 1] = node->keys[i];
    i--;
  }
  node->keys[i + 1] = key;
  node->num_keys++;
}



void split_node(Node* node, int key, Node*& new_node) {
  new_node = create_node();
  new_node->is_leaf = node->is_leaf;


  int median_key = node->keys[MIN_KEYS];


  for (int i = MIN_KEYS + 1; i < MAX_KEYS; i++) {
    new_node->keys[i - MIN_KEYS - 1] = node->keys[i];
  }
  for (int i = MIN_KEYS + 1; i < MAX_KEYS + 1; i++) {
    new_node->children[i - MIN_KEYS - 1] = node->children[i];
  }
  new_node->num_keys = MAX_KEYS - MIN_KEYS - 1;
  node->num_keys = MIN_KEYS;


  if (key < median_key) {
    insert_key(node, key);
  } else {
    insert_key(new_node, key);
  }
}





void insert(Node*& root, int key) {
  if (root == NULL) {

    root = create_node();
    root->keys[0] = key;
    root->num_keys++;
  } else {

    if (root->num_keys == MAX_KEYS) {
      Node* new_root = NULL;
      split_node(root, key, new_root);
      root = new_root;
    } else {

      int i = root->num_keys - 1;
      while (i >= 0 && key < root->keys[i]) {
        i--;
      }
      i++;
      if (root->is_leaf) {
        insert_key(root, key);
      } else {
        if (root->children[i]->num_keys == MAX_KEYS) {
          Node* new_node = NULL;
          split_node(root->children[i], key, new_node);
          root->keys[i] = new_node->keys[0];
          root->children[i + 1] = new_node;
        } else {
          insert(root->children[i], key);
        }
      }
    }
  }
}


void display(Node* root) {
  if (root != NULL) {

    for (int i = 0; i < root->num_keys; i++) {
      std::cout << root->keys[i] << " ";
    }
    std::cout << std::endl;


    for (int i = 0; i <= root->num_keys; i++) {
      display(root->children[i]);
    }
  }
}

int main() {
  Node* root = NULL;


  insert(root, 10);
  insert(root, 20);
  insert(root, 30);
  insert(root, 40);
  insert(root, 50);
  insert(root, 60);


  display(root);

  return 0;
}
