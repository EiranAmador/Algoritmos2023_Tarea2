//
//  bstree.h
//

#ifndef bstree_h
#define bstree_h

#include <iostream>

// Nodos del arbol:
template <typename T>
class bstnode
{
public:
    // Esta clase es usada por otras clases. Para mayor eficiencia, los atributos se hacen publicos.
    T key;
    bstnode<T> *p, *left, *right;
    
    // Constructor por omision
    bstnode() {
    };
    
    // Inicializacion de datos miembro
    bstnode(const T& k, bstnode<T> *w = nullptr, bstnode<T> *y = nullptr, bstnode<T> *z = nullptr):key(k), p(w), left(y), right(z) {};
    
    ~bstnode() {
    };
};

// Arbol de busqueda binario:
template <typename T>
class bstree
{
public:
    bstnode<T> *root;    // raiz del arbol

    bstree() {
        // Constructor (crea un arbol vacio)
        root = nullptr; 
    };
    
    void Clear(bstnode<T>* node) 
    {
        if (node != nullptr) 
        {
            Clear(node->left);  
            Clear(node->right); 
            delete node;
        }
    }

    ~bstree() {
        // Destructor (borra el arbol)
        Clear(root);
    };
    
    void Insert(bstnode<T>* z) {
        
        // Inserta el nodo z en la posicion que le corresponde en el arbol.
        bstnode<T> *y = nullptr;
        bstnode<T> *x = this->root;
        while ( x != nullptr ){
            y = x;
            if ( z->key < x->key ){
                x = x->left;
            }else{
                x = x->right;
            }           
        }
        z->p = y;
        if ( y == nullptr ){
            this->root = z; //Arbol vacio
        }else if( z->key < y->key ){
            y->left = z;
        }else{
            y->right = z;
        }
    };
    
    void InorderWalk(bstnode<T> *x) {
        // Recorre en orden el sub�arbol con raiz x, imprimiendo la llave de cada nodo en 
        //en una nueva linea de la salida estandar despues de recorrido el subarbol izquierdo 
        //y antes de recorrer el subarbol derecho.
        if (x != nullptr) 
        {
            InorderWalk(x->left);        
            std::cout << x->key << " ";
            InorderWalk(x->right);
        }
    };
    
    bstnode<T>* Search(bstnode<T> *x, const T& k) {
        // Busca la llave k recursivamente en el subarbol con raiz x. Si la encuentra devuelve 
        //un apuntador al nodo que la contiene, sino devuelve nullptr.
        if (x == nullptr || k == x->key) 
        {
            return x;  
        }

        if (k < x->key) 
        {
            return Search(x->left, k); 
        } 
        else 
        {
            return Search(x->right, k); 
        }
    };
    
    bstnode<T>* IterativeSearch(bstnode<T> *x, const T& k) {
        // Busca la llave k iterativamente en el subarbol con raiz x. 
        //Si la encuentra devuelve un apuntador al nodo que la contiene, sino devuelve nullptr.
        while (x != nullptr && k != x->key) 
        {
            if (k < x->key) 
            {
                x = x->left;  
            } else 
            {
                x = x->right; 
            }
        }

        return x;
    };
    
    bstnode<T>* Minimum(bstnode<T> *x) {
        // Devuelve el nodo que tiene la llave menor. 
        //Si el arbol esta� vacio, devuelve nullptr.
        while (x != nullptr && x->left != nullptr) 
        {
            x = x->left;
        }

        return x;
    };
    
    bstnode<T>* Maximum(bstnode<T> *x) {
        // Devuelve el nodo que tiene la llave mayor. Si el arbol esta vacio devuelve nullptr.
        while (x != nullptr && x->right != nullptr) 
        {
            x = x->right;
        }

        return x;
    };
    
    bstnode<T>* Successor(bstnode<T> *x) {
        // Devuelve el nodo cuya llave es la que le sigue a la del nodo x. 
        //Si no existe el nodo, devuelve nullptr.
        if (x->right != nullptr) 
        {
            return Minimum(x->right);
        }

        bstnode<T>* y = x->parent;

        while (y != nullptr && x == y->right) 
        {
            x = y;
            y = y->parent;
        }

        return y;
    };

    void Replace(bstnode<T>* u, bstnode<T>* v) {
        //Intercambiar un nodo por otro
        if (u->parent == nullptr) {
            root = v; // If u is the root, update the root of the tree
        } else if (u == u->parent->left) {
            u->parent->left = v; // If u is a left child, update the parent's left child
        } else {
            u->parent->right = v; // If u is a right child, update the parent's right child
        }

        if (v != nullptr) {
            v->parent = u->parent; // Update the parent of v
        }
    }
    
    void Delete(bstnode<T>* z) {
        // Saca del arbol la llave contenida en el nodo apuntado por z.
        if (z->left == nullptr) 
        {
            Replace(z, z->right);
        } else if (z->right == nullptr) 
        {
            Replace(z, z->left); 
        } else 
        {
            bstnode<T>* y = Minimum(z->right); 
            if (y->parent != z) 
            {
                Replace(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            Replace(z, y); 
            y->left = z->left;
            y->left->parent = y;
        }

        delete z;
    };  

    //2.2.3 Para insertar numeros en orden
    bstnode<T>* buildBalancedBST(int min, int max, bstnode<T>* parent) {
        if (min > max) {
            return nullptr;
        }

        int mid = min + (max - min) / 2;
        bstnode<T>* newNode = new bstnode<T>(mid);
        newNode->left = buildBalancedBST(min, mid - 1, newNode);
        newNode->right = buildBalancedBST(mid + 1, max, newNode);

        if (parent == nullptr) {
            root = newNode;
        }

        return newNode;
    }
};

#endif /* bstree_h */

