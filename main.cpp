#include <cstdlib>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <bits/stdc++.h>
#include <time.h>  
#include <chrono> 
#include "llist.h"
#include "bstree.h"

using namespace std;

int intAleatorio()
{
    const int BITS_PER_RAND = (int)(log2(RAND_MAX / 2 + 1) + 1.0);
    int ret = 0;
    for (int i = 0; i < sizeof(int) * CHAR_BIT; i += BITS_PER_RAND)
    {
        ret <<= BITS_PER_RAND;
        ret |= rand();
    }
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

    // Perform searches until 10 seconds have elapsed
    while (std::chrono::steady_clock::now() - startTime < std::chrono::seconds(10)) {
        // Perform a search
        lista.Search(intAleatorio());
        searchCount++;
    }

    // Stop the timer
    auto endTime = std::chrono::steady_clock::now();

    // Calculate the elapsed time in seconds
    double elapsedTime = std::chrono::duration<double>(endTime - startTime).count();

    std::cout << "2.1.2 Lista de numeros aleatorios insertados" << std::endl;
    std::cout << "Searches performed: " << searchCount << std::endl;
    std::cout << "Elapsed time (seconds): " << elapsedTime << std::endl;
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

    // Perform searches until 10 seconds have elapsed
    while (std::chrono::steady_clock::now() - startTime < std::chrono::seconds(10)) {
        // Perform a search
        lista.Search(intAleatorio());
        searchCount++;
    }

    // Stop the timer
    auto endTime = std::chrono::steady_clock::now();

    // Calculate the elapsed time in seconds
    double elapsedTime = std::chrono::duration<double>(endTime - startTime).count();

    std::cout << "2.1.3 Lista de numeros en orden insertados" << std::endl;
    std::cout << "Searches performed: " << searchCount << std::endl;
    std::cout << "Elapsed time (seconds): " << elapsedTime << std::endl;
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

    // Perform searches until 10 seconds have elapsed
    while (std::chrono::steady_clock::now() - startTime < std::chrono::seconds(10)) {
        // Perform a search
        arbol.Search(arbol.root, intAleatorio());
        searchCount++;
    }

    // Stop the timer
    auto endTime = std::chrono::steady_clock::now();

    // Calculate the elapsed time in seconds
    double elapsedTime = std::chrono::duration<double>(endTime - startTime).count();

    std::cout << "2.2.2 Arbol de numeros aleatorios insertados" << std::endl;
    std::cout << "Searches performed: " << searchCount << std::endl;
    std::cout << "Elapsed time (seconds): " << elapsedTime << std::endl;
} 

void test223(){

    int _1M = 1000000;

    bstree<int> arbol;

    arbol.buildBalancedBST(0, _1M, nullptr);

    // Start the timer
    auto startTime = std::chrono::steady_clock::now();

    int searchCount = 0;

    // Perform searches until 10 seconds have elapsed
    while (std::chrono::steady_clock::now() - startTime < std::chrono::seconds(10)) {
        // Perform a search
        arbol.Search(arbol.root, intAleatorio());
        searchCount++;
    }

    // Stop the timer
    auto endTime = std::chrono::steady_clock::now();

    // Calculate the elapsed time in seconds
    double elapsedTime = std::chrono::duration<double>(endTime - startTime).count();

    std::cout << "2.2.3 Arbol de numeros en orden insertados" << std::endl;
    std::cout << "Searches performed: " << searchCount << std::endl;
    std::cout << "Elapsed time (seconds): " << elapsedTime << std::endl;
}   

void probarBstree(){

    test222();
    test223();
}

int main(int argc, char *argv[])
{
    probarLList();
    probarBstree();

    return 0;
}