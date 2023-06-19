//
//  llist.h
//

#ifndef llist_h
#define llist_h

// Nodos de la lista:
template <typename T>
class llnode
{
public:
    // Esta clase es para ser usada por otras clases. Por eficiencia los atributos se dejan publicos.
    T key;
    llnode<T> *prev, *next;
    
    // Constructor por omision.
    llnode() {
    };
    
    // Inicializacion de los datos miembro.
    llnode (const T& k, llnode<T> *w = nullptr, llnode<T> *y = nullptr):key(k), prev(w), next(y)  {};
    
    ~llnode() {
    };
};

// Lista enlazada con nodo centinela:
template <typename T>
class llist
{
public:
    llnode<T> *nil;        // nodo centinela

    llist() {
        // Constructor (crea una lista vacia)
        nil = new llnode<T>(); // Create a new sentinel node
        nil->next = nil; // Point the sentinel node to itself
        nil->prev = nil; // Point the sentinel node to itself
    };
    
    ~llist() {
        // Destructor (borra la lista)
        llnode<T> *current = nil->next; // Start from the first node after sentinel
        while (current != nil) {
            llnode<T> *temp = current; // Keep track of the current node
            current = current->next; // Move to the next node
            delete temp; // Deallocate memory for the current node
        }
        delete nil; // Deallocate memory for the sentinel node
    };
    
    void Insert(llnode<T>* x) {
        // Inserta el nodo x en la lista.
         x->next = nil->next;  // Set x's next pointer to the current first node
        nil->next->prev = x;  // Set the current first node's prev pointer to x
        nil->next = x;        // Set nil's next pointer to x
        x->prev = nil;        // Set x's prev pointer to nil
    };

    llnode<T>* Search(const T& k) {
        // Busca la llave iterativamente. Si la encuentra, devuelve un apuntador al nodo que la contiene; sino devuelve el nodo nil (el centinela).
        llnode<T> *current = nil->next; // Start from the first node after sentinel
        while (current != nil) {
            if (current->key == k) {
                return current; // Found the node with value k, return it
            }
            current = current->next; // Move to the next node
        }
        return nullptr; // Value k was not found in the list, return nullptr
    };
        
    void Delete(llnode<T>* x) {
        // Saca de la lista la llave contenida en el nodo apuntado por x.
        x->prev->next = x->next;  // Update the next pointer of the previous node
        x->next->prev = x->prev;  // Update the prev pointer of the next node
        delete x;                 // Deallocate memory for the node
    };    
};

#endif /* llist_h */
