//
//  chtable.h
//

#ifndef chtable_h
#define chtable_h

#include <list>
#include <vector>

template <typename T>

// Tabla de dispersi�n con encadenamiento
class chtable {
public:
    // Constructor que especifica el tama�o de la tabla
    chtable(int sz) {
        size = sz;
        table.resize(sz);
    };
        
    // Destructor (borra la tabla)
    ~chtable() {
        for (auto& entry : table) {
            entry.clear();
        }
        table.clear();
    };
    
    // Inserta el elemento en la tabla
    void Insert(const T& k) {
        int index = Hash(k);
        table[index].push_back(k);
    };
    
    // Retorna un puntero a la llave o nullptr si no se encuentra
    T* Search(const T& k) {
        int index = Hash(k);
        std::list<T>& entries = table[index];
        for (auto& entry : entries) {
            if (entry == k) {
                return &entry;
            }
        }
        return nullptr;
    };
    
    
private:
    // N�mero de entradas en la tabla
    int size;
    
    // La tabla es un vector de listas de STL
    std::vector<std::list<T> > table;

    int Hash(const T& k) {
        
        T absK = std::abs(k);//Valor absoluto en caso de llave negativa
    
        return absK % size;
    }

};

#endif /* chtable_h */
