#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define LEFT 0
#define RIGHT 1

typedef struct node {
  int key;
  struct node *left;
  struct node * right;
} node_type;

int getword(char *word, int lim);
int getch(void);
void ungetch(int c);
node_type * search_key(node_type **root, int key);
void ins_bint(node_type **root, int p_key, int c_key, int lr);
void show_tree (node_type *root);
void free_node(node_type **root);
void create_sample_one(node_type **p);
void create_sample_two(node_type **p);
void create_sample_three(node_type **p);
int is_bsearch_tree(node_type *r);
int take_max(node_type *r);
int take_min(node_type *r);

int main(void) {
  node_type *root;
  int k;

  root = NULL;
  create_sample_one(&root);
  show_tree(root);
  if (is_bsearch_tree(root)) {
    printf("この木は２分探索木です。\n");
  } else {
    printf("この木は２分探索木ではありません。\n");
  }
  free_node(&root);

  return 0;
}

/*  ここに関数 is_bsearch_tree を記述します。 */
int is_bsearch_tree(node_type* r) {
  if(r -> left == NULL && r->right == NULL) {
    return 1;
  } else if(r->left != NULL && r->right != NULL) {
    if(is_bsearch_tree(r->left) && is_bsearch_tree(r->right) && r->key > take_max(r->left) && r->key < take_min(r->right)) {
       return 1;
    } else {
       return 0;
    }
  } else if(r->right != NULL) {
    if(is_bsearch_tree(r->right) && r->key < take_min(r->right)) {
      return 1;
    } else {
      return 0;
    }
  } else if(r->left != NULL){
    if(is_bsearch_tree(r->left) && r->key > take_max(r->left)) {
      return 1;
    } else {
      return 0;
    }
  }

}

int take_max(node_type *r)
{
  if (r->right != NULL) {
    return take_max(r->right);
  } else {
    return r->key;
  }
}

int take_min(node_type *r)
{
  if (r->left != NULL) {
    return take_min(r->left);
  } else {
    return r->key;
  }
}

void create_sample_one(node_type **p)
{
  ins_bint(p, 0, 50, LEFT);
  ins_bint(p, 50, 30, LEFT);
  ins_bint(p, 50, 65, RIGHT);
  ins_bint(p, 30, 18, LEFT);
  ins_bint(p, 30, 42, RIGHT);
  ins_bint(p, 65, 44, LEFT);
  ins_bint(p, 65, 28, RIGHT);
  ins_bint(p, 18, 47, LEFT);
  ins_bint(p, 42, 17, LEFT);
  ins_bint(p, 42, 48, RIGHT);
  ins_bint(p, 44, 35, RIGHT);
  ins_bint(p, 28, 12, LEFT);
  ins_bint(p, 28, 52, RIGHT);
  ins_bint(p, 47, 63, RIGHT);
  ins_bint(p, 17, 84, LEFT);
  ins_bint(p, 48, 54, LEFT);
  ins_bint(p, 12, 55, LEFT);
  ins_bint(p, 84, 25, LEFT);
  ins_bint(p, 84, 10, RIGHT);
}

void create_sample_two(node_type **p)
{
  printf("Hahaha!\n");  /* debug */
  ins_bint(p, 0, 50, LEFT);
  ins_bint(p, 50, 30, LEFT);
  ins_bint(p, 50, 80, RIGHT);
  ins_bint(p, 30, 15, LEFT);
  ins_bint(p, 30, 43, RIGHT);
  ins_bint(p, 80, 65, LEFT);
  ins_bint(p, 80, 90, RIGHT);
  ins_bint(p, 15, 11, LEFT);
  ins_bint(p, 43, 40, LEFT);
  ins_bint(p, 43, 48, RIGHT);
  ins_bint(p, 65, 77, RIGHT);
  ins_bint(p, 90, 86, LEFT);
  ins_bint(p, 90, 95, RIGHT);
  ins_bint(p, 11, 14, RIGHT);
  ins_bint(p, 40, 35, LEFT);
  ins_bint(p, 48, 45, LEFT);
  ins_bint(p, 86, 82, LEFT);
  ins_bint(p, 35, 31, LEFT);
  ins_bint(p, 35, 37, RIGHT);
}

void create_sample_three(node_type **p)
{
  ins_bint(p, 0, 50, LEFT);
  ins_bint(p, 50, 30, LEFT);
  ins_bint(p, 50, 80, RIGHT);
  ins_bint(p, 30, 15, LEFT);
  ins_bint(p, 30, 43, RIGHT);
  ins_bint(p, 80, 65, LEFT);
  ins_bint(p, 80, 90, RIGHT);
  ins_bint(p, 15, 11, LEFT);
  ins_bint(p, 43, 40, LEFT);
  ins_bint(p, 43, 48, RIGHT);
  ins_bint(p, 65, 77, RIGHT);
  ins_bint(p, 90, 86, LEFT);
  ins_bint(p, 90, 95, RIGHT);
  ins_bint(p, 11, 14, RIGHT);
  ins_bint(p, 40, 29, LEFT);
  ins_bint(p, 48, 45, LEFT);
  ins_bint(p, 86, 82, LEFT);
  ins_bint(p, 29, 31, LEFT);
  ins_bint(p, 29, 37, RIGHT);
}

node_type * search_key(node_type **root, int key)
{
  node_type *temp = NULL;
  if (*root == NULL) {
    return NULL;
  }
  if ((*root)->key == key) {
    return *root;
  }
  temp = search_key(&((*root)->left), key);
  if (temp != NULL) {
    return temp;
  } else {
    return search_key(&((*root)->right), key);
  }
}

void ins_bint(node_type **root, int p_key, int c_key, int lr)
{
  node_type *p, *r;

  r = (node_type *) malloc(sizeof(node_type));
  r->key = c_key;
  r->left = NULL;
  r->right = NULL;

  if (*root == NULL) {
    *root = r;
  } else {
    p = search_key(root, p_key);
    if (p == NULL) {
      printf("親ノード %d が見つかりませんでした。\n", p_key);
      free(r);
    } else {
      if (lr == LEFT && p->left == NULL) {
        p->left = r;
      } else if (lr == RIGHT && p->right == NULL){
        p->right = r;
      } else {
        printf("%d->%d 連結失敗！\n", p_key, c_key);
        free(r);
      }
    }
  }
}

void show_tree (node_type *root)
{
  printf("%d ", root->key);
  if (root->left != NULL) {
    printf(" left: %d ", root->left->key);
  } else {
    printf(" left: NULL");
  }
  if (root->right != NULL) {
    printf(" right: %d ", root->right->key);
  } else {
    printf(" right: NULL");
  }
  putchar('\n');
  if (root->left != NULL) {
    show_tree(root->left);
  }
  if (root->right != NULL) {
    show_tree(root->right);
  }
}

void free_node(node_type **root)
{
  if (*root != NULL) {
    free_node(&((*root)->left));
    free_node(&((*root)->right));
    free(*root);
  }
}