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
        nil = new llnode<T>(); 
        nil->next = nil; 
        nil->prev = nil; 
    };
    
    ~llist() {
        // Destructor (borra la lista)
        llnode<T> *current = nil->next; 
        while (current != nil) {
            llnode<T> *temp = current; 
            current = current->next;
            delete temp; 
        }
        delete nil; 
    };
    
    void Insert(llnode<T>* x) {
        // Inserta el nodo x en la lista.
         x->next = nil->next;  
        nil->next->prev = x;  
        nil->next = x;
        x->prev = nil;       
    };

    llnode<T>* Search(const T& k) {
        // Busca la llave iterativamente. Si la encuentra, devuelve un apuntador al nodo que la contiene; sino devuelve el nodo nil (el centinela).
        llnode<T> *current = nil->next; 
        while (current != nil) {
            if (current->key == k) {
                return current; 
            }
            current = current->next; 
        }
        return nullptr; 
    };
        
    void Delete(llnode<T>* x) {
        // Saca de la lista la llave contenida en el nodo apuntado por x.
        x->prev->next = x->next;  
        x->next->prev = x->prev;  
        delete x;                 
    };    
};

#endif /* llist_h */
