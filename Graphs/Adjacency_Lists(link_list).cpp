#include <iostream>
using namespace std;

struct edge;
struct node {
    node *next;
    char name;
    edge *adj;
    bool visited; // New field to track visited nodes
} *start = NULL;

struct edge {
    char dest;
    struct edge* link;
};

node *find(char item) {
    node *ptr = start;
    while (ptr != NULL) {
        if (item == ptr->name)
            return ptr;
        else
            ptr = ptr->next;
    }
    return NULL;
}

void insert_node(char node_name) {
    node *tmp, *ptr;
    tmp = new node;
    tmp->name = node_name;
    tmp->next = NULL;
    tmp->adj = NULL;
    tmp->visited = false; // Initialize visited field to false

    if (start == NULL)
        start = tmp;
    else {
        ptr = start;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = tmp;
    }
}

void delete_node(char u) {
    node *tmp, *q;
    if (start->name == u) {
        tmp = start;
        start = start->next;
        delete tmp;
        return;
    }

    q = start;
    while (q->next->next != NULL) {
        if (q->next->name == u) {
            tmp = q->next;
            q->next = tmp->next;
            delete tmp;
            return;
        }
        q = q->next;
    }

    if (q->next->name == u) {
        tmp = q->next;
        delete tmp;
        q->next = NULL;
    }
}

void delnode_edge(char u) {
    node *ptr;
    edge *q, *tmp;
    ptr = start;

    while (ptr != NULL) {
        if (ptr->adj->dest == u) {
            tmp = ptr->adj;
            ptr->adj = ptr->adj->link;
            delete tmp;
            continue;
        }

        q = ptr->adj;
        while (q->link->link != NULL) {
            if (q->link->dest == u) {
                tmp = q->link;
                q->link = tmp->link;
                delete tmp;
                continue;
            }
            q = q->link;
        }

        if (q->link->dest == u) {
            tmp = q->link;
            delete tmp;
            q->link = NULL;
        }
        ptr = ptr->next;
    }
}

void insert_edge(char u, char v) {


    node *locu, *locv;
    edge *ptr, *tmp;

    locu = find(u);
    locv = find(v);

    if (locu == NULL) {
        cout << "Source node not present, first insert node " << u << endl;
        return;
    }
    if (locv == NULL) {
        cout << "Destination node not present, first insert node " << v << endl;
        return;
    }

    tmp = new edge;
    tmp->dest = v;
    tmp->link = NULL;

    if (locu->adj == NULL)
        locu->adj = tmp;
    else {
        ptr = locu->adj;
        while (ptr->link != NULL)
            ptr = ptr->link;
        ptr->link = tmp;
    }
}

void del_edge(char u, char v) {
    node *locu;
    edge *ptr, *tmp, *q;
    locu = find(u);

    if (locu == NULL) {
        cout << "Source node not present" << endl;
        return;
    }

    if (locu->adj->dest == v) {
        tmp = locu->adj;
        locu->adj = locu->adj->link;
        delete tmp;
        return;
    }

    q = locu->adj;
    while (q->link->link != NULL) {
        if (q->link->dest == v) {
            tmp = q->link;
            q->link = tmp->link;
            delete tmp;
            return;
        }
        q = q->link;
    }

    if (q->link->dest == v) {
        tmp = q->link;
        delete tmp;
        q->link = NULL;
        return;
    }

    cout << "This edge not present in the graph" << endl;
}

void display() {
    node *ptr = start;
    edge *q;
    while (ptr != NULL) {
        cout << ptr->name << "->";
        q = ptr->adj;
        while (q != NULL) {
            cout << q->dest;
            q = q->link;
        }
        cout << endl;
        ptr = ptr->next;
    }
}


int main() {
    int choice;
    char node, origin, destin;

    while (true) {
        cout << "1.Insert a node\n";
        cout << "2.Insert an edge\n";
        cout << "3.Delete a node\n";
        cout << "4.Delete an edge\n";
        cout << "5.Display\n";
        cout << "6.Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a node to be inserted: ";
                cin >> node;
                insert_node(node);
                break;
            case 2:
                cout << "Enter an edge to be inserted: ";
                cin >> origin >> destin;
                insert_edge(origin, destin);
                break;
            case 3:
                cout << "Enter a node to be deleted: ";
                cin >> node;
                delete_node(node);
                delnode_edge(node);
                break;
            case 4:
                cout << "Enter an edge to be deleted: ";
                cin >> origin >> destin;
                del_edge(origin, destin);
                break;
            case 5:
                display();
                break;
            case 6:
            	exit(1);

        }
    }
    return 0;
}
