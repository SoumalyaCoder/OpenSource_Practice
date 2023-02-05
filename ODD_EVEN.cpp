#include <iostream>
using namespace std;

// Create a node
struct Node
{
    int val;
    struct Node *next;
};
typedef struct Node node;

// CREATE ✅
node *CREATE(node *h)
{
    int n = 0;
    cout << "CREATE A LIST " << endl;
    cout << "IF YOU ENTER 33 THEN IT GONNA STOP" << endl;
    while (n != 33)
    {
        cout << "Enter a number " << endl;
        cin >> n;
        if (n != 33)
        {
            h->val = n;
            h->next = (struct Node *)malloc(sizeof(struct Node));
            h = h->next;
        }
        else
        {
            h->val = n;
            h->next = NULL;
        }
        cout << "THE " << n << " IS INSERTED" << endl;
    }
    return h;
}

// DISPLAY ✅
void DISPLAY(Node *h)
{
    cout << "THE ELEMENTS ARE :" << endl;
    struct Node *temp = h;
    while (temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << endl;
    cout << "out" << endl;
}

node *FIN(node *h)
{
    if (h->next != NULL)
        FIN(h->next);
    else
        return h;
}

// 6-> 53 -> 20 -> 36 -> 31 -> 33
// 7 ->9 -> 10  -> 11 -> 19 -> 13 ->
// 6->8 -> 11 -> 34 -> 35 -> 36 ->
node *SWAP(node *h, node *End)
{
    node *temp = h;
    node *prev;
    while (temp != End)
    {
        if (temp == h && h->val % 2 != 0)
        {
            h = h->next;
            temp->next = End->next;
            End->next = temp;
            temp = h;
            prev = temp;
        }
        else if (temp != h && temp->val % 2 != 0)
        {
            prev->next = temp->next;
            temp->next = End->next;
            End->next = temp;
            temp = prev->next;
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
    if (temp->next == NULL)
        cout << "YES" << endl;
    if (h->next == NULL)
        cout << "YES" << endl;
    cout << "head" << h->val << endl;
    cout << "head->next" << h->next->val << endl;

    return h;
}

int main()
{

    node *head;
    node *End;
    head = new Node();
    head = CREATE(head);
    DISPLAY(head);
    cout << "swapping started " << endl;
    End = FIN(head);
    head = SWAP(head, End);
    cout << "Elements are swapped" << endl;
    DISPLAY(head);
    return 0;
}