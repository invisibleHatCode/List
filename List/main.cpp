#include <iostream>
#include <string>

using namespace std;

class IndexOutOfBound {
public:
    std::string errText = "Index out of bound array !!!";
    std::string errTextEmptyList = "List is empty.";

    IndexOutOfBound(int n) {
        cout << "[" << n << "] " << errText << "\n";
        if (n == 0) {
            cout << errTextEmptyList << "\n";
        }
    }
};

template<class T>
class Node {
private:
    Node<T> *prev;
    Node<T> *next;
    T *content;
public:

    ~Node() {
        this->prev = NULL;
        this->next = NULL;
        delete content;
    }

    Node(T *content) {
        this->prev = NULL;
        this->next = NULL;
        this->content = content;
    }

    T * getContent() {
        return this->content;
    }

    void setContent(T * content) {
        this->content = content;
    }

    Node<T> * getPrev() {
        return this->prev;
    }

    Node<T> * getNext() {
        return this->next;
    }

    void setNext(Node<T> *node) {
        this->next = node;
    }

    void setPrev(Node<T> *node) {
        this->prev = node;
    }
};

template<class T>
class List {
private:
    Node<T> *frontNode;
public:

    List() {
        this->frontNode = NULL;
    }

    List(Node<T> *node) {
        this->frontNode = node;
    }

    ~List() {
        if (this->frontNode->getNext() == NULL) {
            delete frontNode;
        }

        int size = this->size();
        Node<T> *temp = NULL;
        for (int i = 0; i < size; i++) {
            temp = this->frontNode->getNext();
            if (temp == NULL) {
                delete this->frontNode;
                break;
            }
            this->frontNode = temp;
            delete this->frontNode->getPrev();
        }

    }

    void addNode(Node<T> * node) {
        if (this->frontNode == NULL) {
            this->frontNode = node;
            return;
        }

        Node<T> *currentNode = this->frontNode;
        Node<T> *tempNode = currentNode->getNext();
        if (tempNode == NULL) {
            node->setPrev(currentNode);
            currentNode->setNext(node);
            return;
        }
        while (tempNode != NULL) {
            currentNode = tempNode;
            tempNode = currentNode->getNext();
        }
        node->setPrev(currentNode);
        currentNode->setNext(node);
    }

    void setNode(Node<T> *node, int n) {
        if (this->frontNode == NULL) {
            throw new IndexOutOfBound(n);
            return;
        }

        int counter = 0;
        Node<T> *temp = this->frontNode->getNext();
        if (n == 0) {
            if (temp != NULL) {
                temp->setPrev(node);
            }
            node->setNext(this->frontNode->getNext());
            node->setPrev(NULL);
            this->frontNode = node;
            return;
        }

        counter++;
        Node<T> *prev;
        Node<T> *next;
        while (temp != NULL) {
            if (counter == n) {
                prev = temp->getPrev();
                next = temp->getNext();
                if (next == NULL) {
                    node->setPrev(prev);
                    node->setNext(next);
                    prev->setNext(node);
                } else {
                    node->setPrev(prev);
                    node->setNext(next);
                    next->setPrev(node);
                    prev->setNext(node);
                }
                return;
            }
            temp = temp->getNext();
            counter++;
        }
        throw new IndexOutOfBound(n);
        return;
    }

    Node<T> * outNodeAt(int n) {
        Node<T> * outNode = this->getNodeAt(n);
        Node<T> * prev = outNode->getPrev();
        Node<T> * next = outNode->getNext();
        prev->setNext(next);
        next->setPrev(prev);
        outNode->setNext(NULL);
        outNode->setPrev(NULL);
        return outNode;
    }

    void switchNode(int indexA, int indexB) {
        Node<T> * nodeA = this->getNodeAt(indexA);
        Node<T> * nodeB = this->getNodeAt(indexB);

        Node<T> * nodeAPrev = nodeA->getPrev();
        Node<T> * nodeANext = nodeA->getNext();

        Node<T> * nodeBPrev = nodeB->getPrev();
        Node<T> * nodeBNext = nodeB->getNext();


        if (indexB - indexA == 1) {
            if (nodeAPrev != NULL) {
                nodeAPrev->setNext(nodeB);
            }
            nodeB->setPrev(nodeAPrev);

            nodeB->setNext(nodeA);
            nodeA->setPrev(nodeB);

            nodeA->setNext(nodeBNext);
            if (nodeBNext != NULL) {
                nodeBNext->setPrev(nodeA);
            }

        } else {

            if (nodeAPrev != NULL) {

                nodeAPrev->setNext(nodeB);
                nodeANext->setPrev(nodeB);
                nodeB->setNext(nodeANext);
                nodeB->setPrev(nodeAPrev);

            } else {
                nodeANext->setPrev(nodeB);
                nodeB->setNext(nodeANext);
                nodeB->setPrev(nodeAPrev);
            }

            if (nodeBNext != NULL) {

                nodeBPrev->setNext(nodeA);
                nodeBNext->setPrev(nodeA);

                nodeA->setNext(nodeBNext);
                nodeA->setPrev(nodeBPrev);
            } else {
                nodeBPrev->setNext(nodeA);
                nodeA->setNext(nodeBNext);
                nodeA->setPrev(nodeBPrev);
            }

        }

        if (indexA == 0) {
            this->frontNode = nodeB;
        }

    }

    Node<T> * getNodeAt(int n) {
        if (this->frontNode == NULL) {
            throw new IndexOutOfBound(n);
            return NULL;
        }

        int counter = 0;
        if (n == 0) {
            return this->frontNode;
        }
        Node<T> *temp = this->frontNode->getNext();
        counter++;
        while (temp != NULL) {
            if (counter == n) {
                return temp;
            }
            temp = temp->getNext();
            counter++;
        }
        throw new IndexOutOfBound(n);
        return NULL;
    }

    int size() {
        if (this->frontNode == NULL) {
            return 0;
        }

        int counter = 0;
        Node<T> *temp = this->frontNode->getNext();
        counter++;
        while (temp != NULL) {
            temp = temp->getNext();
            counter++;
        }
        return counter;
    }
};

class Pack {
public:
    int cost;
    int weight;
    double proportion;

public:

    Pack(int x, int y) {
        this->cost = x;
        this->weight = y;
        this->proportion = (double) x / y;
    }

    int compareNode(Pack *p) {
        if (this->proportion == p->proportion) {
            return 0;
        } else if (this->proportion < p->proportion) {
            return 1;
        } else {
            return -1;
        }
    }
};

class PackSort {
public:
    List<Pack> *list;

    PackSort(List<Pack> *list) {
        this->list = list;
    }

    void bubbleSort() {
        int size = list->size();
        Node<Pack> *tempPack;
        Node<Pack> *tempNextPack;
        int resultCompare = 0;
        std::cout << "SIZE: " << size << "\n";
        do {
            for (int i = 0; i < size - 1; i++) {
                tempPack = list->getNodeAt(i);
                tempNextPack = list->getNodeAt(i + 1);
                resultCompare = tempPack->getContent()->compareNode(tempNextPack->getContent());
                if (resultCompare == 1) {
                    list->switchNode(i, i + 1);
                }
            }
            size = size - 1;
        } while (size > 1);
    }
};

#include "TestList.h"

int main() {
    ListTest *lt = new ListTest();
    lt->testSwitch01();
    lt->testSwitch02();
    lt->testSwitch04();
    lt->testSwitch01();
    lt->testSwitch13();
    lt->testSwitch34();
    lt->testSortBubble();

    delete lt;
    return 0;
}