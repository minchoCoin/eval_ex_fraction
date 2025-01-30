#ifndef AST_H
#define AST_H


typedef enum {
    INT_NODE,
    FRACTION_NODE
} NodeType;


typedef struct{
    int num; // numerator
    int den; //denominator
} Fraction;

//(left + numerator/denominator)
typedef struct Node {
    NodeType type;
    union {
        int ival;                  
        struct {          
            struct Node *left;  
            struct Node *numerator;
            struct Node *denominator;
            
        } exFraction;
    } data;
} Node;


Node *mkIntNode(int n);
Node *mkFractionNode(Node* a, Node* b, Node* c);


void printTree(Node *node, int indent);

Fraction evaluate(Node* node);

#endif