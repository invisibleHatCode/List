#include <iostream>
#include <string>


#ifndef TESTLIST_H
#define TESTLIST_H

class ListTest {
public:
    List<Pack> *list;

    ListTest() {
        list = new List<Pack>();
        Node<Pack> *aa = new Node<Pack>(new Pack(10, 5));
        Node<Pack> *bb = new Node<Pack>(new Pack(7, 12));
        Node<Pack> *cc = new Node<Pack>(new Pack(1, 2));
        Node<Pack> *dd = new Node<Pack>(new Pack(3, 7));
        Node<Pack> *ee = new Node<Pack>(new Pack(2, 5));

        list->addNode(aa);
        list->addNode(bb);
        list->addNode(cc);
        list->addNode(dd);
        list->addNode(ee);

        int size = list->size();

        Node<Pack> *p = NULL;
        size = list->size();
        std::cout << "Size: " << size << "\n";
        for (int i = 0; i < size; i++) {
            p = list->getNodeAt(i);
            std::cout << "i: " << i << " c: " << p->getContent()->cost << " w: " << p->getContent()->weight << " p: " << p->getContent()->proportion << "\n";
        }
        std::cout << "\n";
    }
    
    ~ListTest(){
        delete list;
    }

    void testSwitch01() {
        try {
            list->switchNode(0, 1);
            Node<Pack> *p;
            int size = list->size();
            for (int i = 0; i < size; i++) {
                p = list->getNodeAt(i);
                std::cout << "i: " << i << " c: " << p->getContent()->cost << " w: " << p->getContent()->weight << " p: " << p->getContent()->proportion << "\n";
            }

            std::cout << "\n";
        } catch (IndexOutOfBound iob) {

        }
    }

    void testSwitch02() {
        try {
            list->switchNode(0, 2);
            Node<Pack> *p;
            int size = list->size();
            for (int i = 0; i < size; i++) {
                p = list->getNodeAt(i);
                std::cout << "i: " << i << " c: " << p->getContent()->cost << " w: " << p->getContent()->weight << " p: " << p->getContent()->proportion << "\n";
            }

            std::cout << "\n";
        } catch (IndexOutOfBound iob) {

        }
    }

    void testSwitch04() {
        try {
            list->switchNode(0, 4);
            Node<Pack> *p;
            int size = list->size();
            for (int i = 0; i < size; i++) {
                p = list->getNodeAt(i);
                std::cout << "i: " << i << " c: " << p->getContent()->cost << " w: " << p->getContent()->weight << " p: " << p->getContent()->proportion << "\n";
            }

            std::cout << "\n";
        } catch (IndexOutOfBound iob) {

        }
    }

    void testSwitch13() {
        try {
            list->switchNode(1, 3);
            Node<Pack> *p;
            int size = list->size();
            for (int i = 0; i < size; i++) {
                p = list->getNodeAt(i);
                std::cout << "i: " << i << " c: " << p->getContent()->cost << " w: " << p->getContent()->weight << " p: " << p->getContent()->proportion << "\n";
            }

            std::cout << "\n";
        } catch (IndexOutOfBound iob) {

        }
    }

    void testSwitch12() {
        try {
            list->switchNode(1, 2);
            Node<Pack> *p;
            int size = list->size();
            for (int i = 0; i < size; i++) {
                p = list->getNodeAt(i);
                std::cout << "i: " << i << " c: " << p->getContent()->cost << " w: " << p->getContent()->weight << " p: " << p->getContent()->proportion << "\n";
            }

            std::cout << "\n";
        } catch (IndexOutOfBound iob) {

        }
    }

    void testSwitch34() {
        try {
            list->switchNode(3, 4);
            Node<Pack> *p;
            int size = list->size();
            for (int i = 0; i < size; i++) {
                p = list->getNodeAt(i);
                std::cout << "i: " << i << " c: " << p->getContent()->cost << " w: " << p->getContent()->weight << " p: " << p->getContent()->proportion << "\n";
            }

            std::cout << "\n";
        } catch (IndexOutOfBound iob) {

        }
    }

    void testBruteForceSwitch() {
        try {
            Node<Pack> *p;
            int size = list->size();
            for (int i = 0; i < size; i++) {
                for (int j = i + 1; j < size; j++) {
                    list->switchNode(i, j);
                    std::cout << "i: " << i << " j: " << j << "\n";
                    for (int k = 0; k < size; k++) {
                        p = list->getNodeAt(k);
                        std::cout << "i: " << k << " c: " << p->getContent()->cost << " w: " << p->getContent()->weight << " p: " << p->getContent()->proportion << "\n";
                    }

                    std::cout << "\n";
                }
            }
            std::cout << "BACK BROUTE FORCE" << "\n";
            for (int i = size - 2; i >= 0; i--) {
                for (int j = size - 1; j > i; j--) {

                    list->switchNode(i, j);

                    std::cout << "i: " << i << " j: " << j << "\n";
                    for (int k = 0; k < size; k++) {
                        p = list->getNodeAt(k);
                        std::cout << "i: " << k << " c: " << p->getContent()->cost << " w: " << p->getContent()->weight << " p: " << p->getContent()->proportion << "\n";
                    }
                    std::cout << "\n";
                }
            }

        } catch (IndexOutOfBound iob) {

        }
    }

    void testSortBubble() {
        this->testBruteForceSwitch();

        PackSort *ps = new PackSort(list);
        ps->bubbleSort();
        Node<Pack> *p;
        int size = list->size();
        std::cout << "SORTED \n";
        for (int i = 0; i < size; i++) {
            p = list->getNodeAt(i);
            std::cout << "i: " << i << " c: " << p->getContent()->cost << " w: " << p->getContent()->weight << " p: " << p->getContent()->proportion << "\n";
        }

        std::cout << "\n";
    }

};


#endif /* TESTLIST_H */

