class Node
{
    public:
        Node(int val)
        {
            this->val = val;
        }
    Node *next = NULL;
    int val;
};

class MyLinkedList
{
    Node *head = NULL;
    int len = 0;
    Node *tail = NULL;
    public:
        MyLinkedList() {}

    int get(int index)
    {
        if (index >= len)
            return -1;
        Node *tempHead = head;
        int count = 0;
        while (tempHead != NULL)
        {
            if (index == count)
                return tempHead->val;
            tempHead = tempHead->next;
            count++;
        }
        return 10;
    }

    void addAtHead(int val)
    {
        len++;
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;

            return;
        }
        newNode->next = head;
        head = newNode;
        return;
    }

    void addAtTail(int val)
    {
        len++;
        Node *newNode = new Node(val);
        if (tail == NULL)
        {
            head = newNode;
            tail = newNode;

            return;
        }

        tail->next = newNode;
        tail = newNode;
        return;
    }

    void addAtIndex(int index, int val)
    {
        if (index > len)
            return;
        if (index == len)
        {
            addAtTail(val);
            return;
        }
        Node *tempHead = head;
        int count = 0;
        Node *prev = NULL;
        Node *newNode = new Node(val);

        while (tempHead != NULL)
        {
            if (count  == index)
            {
                if (prev != NULL)
                {
                    newNode->next = prev->next;
                    prev->next = newNode;
                    len++;
                }
                else
                {
                    addAtHead(val);
                }
                return;
            }
            prev = tempHead;
            tempHead = tempHead->next;
            count++;
        }
    }

    void deleteAtIndex(int index)
    {
        if (index >= len)
            return;
        len--;
        Node *tempHead = head;
        int count = 0;
        Node *prev = NULL;
        while (tempHead != NULL)
        {
            if (index == count)
            {
                if (prev != NULL)
                {
                    prev->next = tempHead->next;
                    if (prev->next == NULL)
                        tail = prev;
                }
                else
                {
                    if(head == tail){
                        head = tail = tempHead->next;
                    }
                    head = tempHead->next;
                    
                }
                return;
            }
            prev = tempHead;
            tempHead = tempHead->next;
            count++;
        }
    }
};

/**
 *Your MyLinkedList object will be instantiated and called as such:
 *MyLinkedList* obj = new MyLinkedList();
 *int param_1 = obj->get(index);
 *obj->addAtHead(val);
 *obj->addAtTail(val);
 *obj->addAtIndex(index,val);
 *obj->deleteAtIndex(index);
 */