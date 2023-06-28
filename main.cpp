#include <cstdlib>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <bits/stdc++.h>
#include <time.h>  
#include <chrono> 
#include "llist.h"
#include "bstree.h"
#include "rbtree.h"
#include "chasht.h"

using namespace std;

int intAleatorio()
{
    /*const int BITS_PER_RAND = (int)(log2(RAND_MAX / 2 + 1) + 1.0);
    int ret = 0;
    for (int i = 0; i < sizeof(int) * CHAR_BIT; i += BITS_PER_RAND)
    {
        ret <<= BITS_PER_RAND;
        ret |= rand();
    }
    */
    int rangeMin = -1000000;
    int rangeMax = 1000000;

    int ret = std::rand() % (rangeMax - rangeMin + 1) + rangeMin;

    return ret;
}

void test212(){

    int _1M = 1000000;

    int n = _1M;

    llist<int> lista;

    for(int i=0; i<_1M; i++)
    {
        int randInt = intAleatorio();
        llnode<int>* newNode = new llnode<int>(randInt);
        lista.Insert(newNode);
    }

    // Start the timer
    auto startTime = std::chrono::steady_clock::now();

    int searchCount = 0;
    int success = 0;

    // Perform searches until 10 seconds have elapsed
    while (std::chrono::steady_clock::now() - startTime < std::chrono::seconds(10)) {
        // Perform a search
        if(lista.Search(intAleatorio())!=nullptr){
            success++;
        }
        searchCount++;
    }

    // Stop the timer
    auto endTime = std::chrono::steady_clock::now();

    // Calculate the elapsed time in seconds
    double elapsedTime = std::chrono::duration<double>(endTime - startTime).count();

    std::cout << "2.1.2 Lista de numeros aleatorios insertados" << std::endl;
    std::cout << "Searches performed: " << searchCount << std::endl;
    std::cout << "Successful searches performed: " << success << std::endl;
    std::cout << "Elapsed time (seconds): " << elapsedTime << std::endl;
    std::cout << "================================\n\n" << std::endl;
}

 void test213(){

    int _1M = 1000000;

    int n = _1M;

    llist<int> lista;

    for(int i=0; i<_1M; i++)
    {
        llnode<int>* newNode = new llnode<int>(i);
        lista.Insert(newNode);
    }

    // Start the timer
    auto startTime = std::chrono::steady_clock::now();

    int searchCount = 0;
    int success = 0;

    // Perform searches until 10 seconds have elapsed
    while (std::chrono::steady_clock::now() - startTime < std::chrono::seconds(10)) {
        // Perform a search
        if(lista.Search(intAleatorio())!=nullptr){
            success++;
        }
        searchCount++;
    }

    // Stop the timer
    auto endTime = std::chrono::steady_clock::now();

    // Calculate the elapsed time in seconds
    double elapsedTime = std::chrono::duration<double>(endTime - startTime).count();

    std::cout << "2.1.3 Lista de numeros en orden insertados" << std::endl;
    std::cout << "Searches performed: " << searchCount << std::endl;
    std::cout << "Successful searches performed: " << success << std::endl;
    std::cout << "Elapsed time (seconds): " << elapsedTime << std::endl;
    std::cout << "================================\n\n" << std::endl;
}   

void probarLList(){

    test212();
    test213();
}

void test222(){

    int _1M = 1000000;

    int n = _1M;

    bstree<int> arbol;

    for(int i=0; i<_1M; i++)
    {
        int randInt = intAleatorio();
        bstnode<int>* newNode = new bstnode<int>(randInt);
        arbol.Insert(newNode);
    }

    // Start the timer
    auto startTime = std::chrono::steady_clock::now();

    int searchCount = 0;
    int success = 0;

    // Perform searches until 10 seconds have elapsed
    while (std::chrono::steady_clock::now() - startTime < std::chrono::seconds(10)) {
        // Perform a search
        if(arbol.Search(arbol.root, intAleatorio())!=nullptr){
            success++;
        }
        searchCount++;
    }

    // Stop the timer
    auto endTime = std::chrono::steady_clock::now();

    // Calculate the elapsed time in seconds
    double elapsedTime = std::chrono::duration<double>(endTime - startTime).count();

    std::cout << "2.2.2 Arbol de numeros aleatorios insertados" << std::endl;
    std::cout << "Searches performed: " << searchCount << std::endl;
    std::cout << "Successful searches performed: " << success << std::endl;
    std::cout << "Elapsed time (seconds): " << elapsedTime << std::endl;
    std::cout << "================================\n\n" << std::endl;
} 

void test223(){

    int _1M = 1000000;

    bstree<int> arbol;

    arbol.buildBalancedBST(0, _1M, nullptr);

    // Start the timer
    auto startTime = std::chrono::steady_clock::now();

    int searchCount = 0;
    int success = 0;

    // Perform searches until 10 seconds have elapsed
    while (std::chrono::steady_clock::now() - startTime < std::chrono::seconds(10)) {
        // Perform a search
        if(arbol.Search(arbol.root, intAleatorio())!=nullptr){
            success++;
        }
        searchCount++;
    }

    // Stop the timer
    auto endTime = std::chrono::steady_clock::now();

    // Calculate the elapsed time in seconds
    double elapsedTime = std::chrono::duration<double>(endTime - startTime).count();

    std::cout << "2.2.3 Arbol de numeros en orden insertados" << std::endl;
    std::cout << "Searches performed: " << searchCount << std::endl;
    std::cout << "Successful searches performed: " << success << std::endl;
    std::cout << "Elapsed time (seconds): " << elapsedTime << std::endl;
    std::cout << "================================\n\n" << std::endl;
}   

void probarBstree(){

    test222();
    test223();
}

void test232(){

    int _1M = 1000000;

    int n = _1M;

    rbtree<int> arbolrn;

    for(int i=0; i<_1M; i++)
    {
        int randInt = intAleatorio();
        rbtnode<int>* newNode = new rbtnode<int>(randInt);
        arbolrn.Insert(newNode);
    }

    // Start the timer
    auto startTime = std::chrono::steady_clock::now();

    int searchCount = 0;
    int success = 0;

    // Perform searches until 10 seconds have elapsed
    while (std::chrono::steady_clock::now() - startTime < std::chrono::seconds(10)) {
        // Perform a search
        if(arbolrn.Search(arbolrn.root, intAleatorio())!= arbolrn.nil){
            success++;
        }
        searchCount++;
    }

    // Stop the timer
    auto endTime = std::chrono::steady_clock::now();

    // Calculate the elapsed time in seconds
    double elapsedTime = std::chrono::duration<double>(endTime - startTime).count();

    std::cout << "2.3.2 Arbol rojinegro de numeros aleatorios insertados" << std::endl;
    std::cout << "Searches performed: " << searchCount << std::endl;
    std::cout << "Successful searches performed: " << success << std::endl;
    std::cout << "Elapsed time (seconds): " << elapsedTime << std::endl;
    std::cout << "================================\n\n" << std::endl;
} 

void test233(){

    int _1M = 1000000;

    rbtree<int> arbolrn;

    for(int i=0; i<_1M; i++)
    {
        rbtnode<int>* newNode = new rbtnode<int>(i);
        arbolrn.Insert(newNode);
    }

    // Start the timer
    auto startTime = std::chrono::steady_clock::now();

    int searchCount = 0;
    int success = 0;

    // Perform searches until 10 seconds have elapsed
    while (std::chrono::steady_clock::now() - startTime < std::chrono::seconds(10)) {
        // Perform a search
        if(arbolrn.Search(arbolrn.root, intAleatorio())!= arbolrn.nil){
            success++;
        }
        searchCount++;
    }

    // Stop the timer
    auto endTime = std::chrono::steady_clock::now();

    // Calculate the elapsed time in seconds
    double elapsedTime = std::chrono::duration<double>(endTime - startTime).count();

    std::cout << "2.3.3 Arbol rojinegro de numeros en orden insertados" << std::endl;
    std::cout << "Searches performed: " << searchCount << std::endl;
    std::cout << "Successful searches performed: " << success << std::endl;
    std::cout << "Elapsed time (seconds): " << elapsedTime << std::endl;
    std::cout << "================================\n\n" << std::endl;
}   

void probarRBTree()
{
    test232();
    test233();
}

void test242(){

    int _1M = 1000000;

    int n = 2000003;

    chtable<int> tabla(n);

    for(int i=0; i<_1M; i++)
    {
        int randInt = intAleatorio();
        tabla.Insert(randInt);
    }

    // Start the timer
    auto startTime = std::chrono::steady_clock::now();

    int searchCount = 0;
    int success = 0;

    // Perform searches until 10 seconds have elapsed
    while (std::chrono::steady_clock::now() - startTime < std::chrono::seconds(10)) {
        // Perform a search
        if(tabla.Search(intAleatorio())!=nullptr){
            success++;
        }
        searchCount++;
    }

    // Stop the timer
    auto endTime = std::chrono::steady_clock::now();

    // Calculate the elapsed time in seconds
    double elapsedTime = std::chrono::duration<double>(endTime - startTime).count();

    std::cout << "2.4.2 Tabla hash de numeros aleatorios insertados" << std::endl;
    std::cout << "Searches performed: " << searchCount << std::endl;
    std::cout << "Successful searches performed: " << success << std::endl;
    std::cout << "Elapsed time (seconds): " << elapsedTime << std::endl;
    std::cout << "================================\n\n" << std::endl;
} 

void test243(){

    int _1M = 1000000;

    int n = 2000003;

    chtable<int> tabla(n);

    for(int i=0; i<_1M; i++)
    {
        tabla.Insert(i);
    }

    // Start the timer
    auto startTime = std::chrono::steady_clock::now();

    int searchCount = 0;
    int success = 0;

    // Perform searches until 10 seconds have elapsed
    while (std::chrono::steady_clock::now() - startTime < std::chrono::seconds(10)) {
        // Perform a search
        if(tabla.Search(intAleatorio())!=nullptr){
            success++;
        }
        searchCount++;
    }

    // Stop the timer
    auto endTime = std::chrono::steady_clock::now();

    // Calculate the elapsed time in seconds
    double elapsedTime = std::chrono::duration<double>(endTime - startTime).count();

    std::cout << "2.4.3 Tabla hash de numeros en orden insertados" << std::endl;
    std::cout << "Searches performed: " << searchCount << std::endl;
    std::cout << "Successful searches performed: " << success << std::endl;
    std::cout << "Elapsed time (seconds): " << elapsedTime << std::endl;
    std::cout << "================================\n\n" << std::endl;
}   

void probarHashTable()
{
    test242();
    test243();
}

int main(int argc, char *argv[])
{
    probarLList();
    probarBstree();
    probarRBTree();
    probarHashTable();

    return 0;
}