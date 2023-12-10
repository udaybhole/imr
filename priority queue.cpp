#include <iostream>
#include <list>

using namespace std;

class PriorityQueue {
private:
    struct Node {
        string data;
        int priority;
    };

    list<Node> itemList;

public:
    void enqueue(const string& data, int priority) {
        Node newNode{data, priority};

        auto it = itemList.begin();
        while (it != itemList.end() && it->priority <= priority) {
            ++it;
        }

        itemList.insert(it, newNode);
    }

    string dequeue() {
        if (!itemList.empty()) {
            string data = itemList.front().data;
            itemList.pop_front();
            return data;
        } else {
            throw out_of_range("PriorityQueue is empty");
        }
    }

    bool isEmpty() const {
        return itemList.empty();
    }

    void displayQueue() const {
        for (const auto& node : itemList) {
            cout << "Data: " << node.data << " Priority: " << node.priority << endl;
        }
    }
};

int main() {
    // Example usage of the PriorityQueue
    PriorityQueue priorityQueue;

    priorityQueue.enqueue("Item1", 2);
    priorityQueue.enqueue("Item2", 1);
    priorityQueue.enqueue("Item3", 3);

    cout << "Priority Queue after enqueue:" << endl;
    priorityQueue.displayQueue();

    cout << "Dequeue: " << priorityQueue.dequeue() << endl;

    cout << "Priority Queue after dequeue:" << endl;
    priorityQueue.displayQueue();

    return 0;
}