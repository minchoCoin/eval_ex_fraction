#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"


Node *mkIntNode(int n) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->type = INT_NODE;
    node->data.ival = n;
    return node;
}





Node *mkFractionNode(Node* a, Node* b, Node* c) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->type = FRACTION_NODE;
    node->data.exFraction.left=a;
    node->data.exFraction.numerator=b;
    node->data.exFraction.denominator=c;
    return node;
}



void printTree(Node *node, int indent) {
    if (node == NULL) return;

    
    
    for (int i = 0; i < indent; i++) printf("   ");
    switch (node->type) {
        case INT_NODE:
            printf("Int(%d)\n", node->data.ival);
            break;
        case FRACTION_NODE:
            printf("Op(mkFraction)\n");
            printTree(node->data.exFraction.left,indent+1);
            printTree(node->data.exFraction.numerator,indent+1);
            printTree(node->data.exFraction.denominator,indent+1);
            break;
    }
}

int gcd(int a, int b){
    if(a<b) return gcd(b,a);
    if (b==0) return (a<0 ? -a:a);
    return gcd(b,a%b);
}

/* making irreducible fraction */
Fraction reduce(Fraction f){
    int g = gcd(f.num, f.den);
    f.num/=g;
    f.den/=g;
    if(f.den<0){
        f.den=-f.den;
        f.num=-f.num;
    }
    return f;
}

/* fraction addition: a + b */
Fraction fraction_add(Fraction a, Fraction b) {
    Fraction r;
    r.num = a.num * b.den + b.num * a.den;
    r.den = a.den * b.den;
    return reduce(r);
}

/* fraction division: a / b */
Fraction fraction_div(Fraction a, Fraction b) {
    Fraction r;
    r.num = a.num * b.den;
    r.den = a.den * b.num;
    return reduce(r);
}

Fraction evaluate(Node* node) {
    if (node == NULL) {
        //  (null node)
        Fraction zero = {0, 1};
        return zero;
    }

    if (node->type == INT_NODE) {
        // leaf node(integer node)
        Fraction r;
        r.num = node->data.ival;
        r.den = 1;
        return r;
    }
    
    
    Fraction A = evaluate(node->data.exFraction.left);
    Fraction B = evaluate(node->data.exFraction.numerator);
    Fraction C = evaluate(node->data.exFraction.denominator);

    
    Fraction divPart = fraction_div(B, C);
    Fraction result  = fraction_add(A, divPart);
    return result;
    
}