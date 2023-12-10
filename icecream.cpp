#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertNode(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

bool searchNode(Node* head, int value) {
    while (head) {
        if (head->data == value) {
            return true;
        }
        head = head->next;
    }
    return false;
}

void deleteLinkedList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

Node* computeUnion(Node* setA, Node* setB) {
    Node* resultUnion = nullptr;
    while (setA) {
        insertNode(resultUnion, setA->data);
        if (!searchNode(setB, setA->data)) {
            setA = setA->next;
        }
        setA = setA->next;
    }
    while (setB) {
        insertNode(resultUnion, setB->data);
        setB = setB->next;
    }
    return resultUnion;
}

Node* computeIntersection(Node* setA, Node* setB) {
    Node* resultIntersection = nullptr;
    while (setA && setB) {
        if (setA->data == setB->data) {
            insertNode(resultIntersection, setA->data);
            setA = setA->next;
            setB = setB->next;
        } else if (setA->data < setB->data) {
            setA = setA->next;
        } else {
            setB = setB->next;
        }
    }
    return resultIntersection;
}

Node* computeOnlyVanilla(Node* setA, Node* setB) {
    Node* resultOnlyVanilla = nullptr;
    while (setA) {
        if (!searchNode(setB, setA->data)) {
            insertNode(resultOnlyVanilla, setA->data);
        }
        setA = setA->next;
    }
    return resultOnlyVanilla;
}

Node* computeOnlyButterscotch(Node* setA, Node* setB) {
    Node* resultOnlyButterscotch = nullptr;
    while (setB) {
        if (!searchNode(setA, setB->data)) {
            insertNode(resultOnlyButterscotch, setB->data);
        }
        setB = setB->next;
    }
    return resultOnlyButterscotch;
}

int computeNeitherCount(Node* resultUnion) {
    int neitherCount = 0;
    Node* temp = resultUnion;
    while (temp) {
        neitherCount++;
        temp = temp->next;
    }
    return neitherCount;
}

int main() {
    Node* setA = nullptr;
    Node* setB = nullptr;

    insertNode(setA, 1);
    insertNode(setA, 2);
    insertNode(setA, 3);

    insertNode(setB, 2);
    insertNode(setB, 3);
    insertNode(setB, 4);

    cout << "Set A: ";
    displayList(setA);

    cout << "Set B: ";
    displayList(setB);

    Node* resultUnion = computeUnion(setA, setB);
    Node* resultIntersection = computeIntersection(setA, setB);
    Node* resultOnlyVanilla = computeOnlyVanilla(setA, setB);
    Node* resultOnlyButterscotch = computeOnlyButterscotch(setA, setB);

    cout << "Set of students who like either vanilla or butterscotch or both: ";
    displayList(resultUnion);

    cout << "Set of students who like both vanilla and butterscotch: ";
    displayList(resultIntersection);

    cout << "Set of students who like only vanilla not butterscotch: ";
    displayList(resultOnlyVanilla);

    cout << "Set of students who like only butterscotch not vanilla: ";
    displayList(resultOnlyButterscotch);

    cout << "Number of students who like neither vanilla nor butterscotch: "
         << computeNeitherCount(resultUnion) << endl;

    deleteLinkedList(setA);
    deleteLinkedList(setB);
    deleteLinkedList(resultUnion);
    deleteLinkedList(resultIntersection);
    deleteLinkedList(resultOnlyVanilla);
    deleteLinkedList(resultOnlyButterscotch);

    return 0;
}