#include <iostream>
#include "graph.h"
#include "person.h"



int main()
{
    Person p0(0, "Nastia");
    Person p1(1, "Nikita");
    Person p2(2, "Oleg");
    Person p3(3, "Vania");
    Person p4(4, "Jenia");

    Graph g;

    g.addVertex(0);
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    

    g.addEdge(0, 1, 1);       // Рукопожатие представлено единичным ребром графа
    g.addEdge(0, 3, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(3, 4, 1);


    std::cout << "Three Handshakes's couple:" << std::endl;

    g.findThreeHandshakesFloyd();

    std::cout << "Persons names:" << std::endl;
    std::cout << "0: " << p0.getPersonName() << std::endl;
    std::cout << "1: " << p1.getPersonName() << std::endl;
    std::cout << "2: " << p2.getPersonName() << std::endl;
    std::cout << "3: " << p3.getPersonName() << std::endl;
    std::cout << "4: " << p4.getPersonName() << std::endl;


    return 0;
}