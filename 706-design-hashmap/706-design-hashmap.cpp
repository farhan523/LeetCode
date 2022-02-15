class Node{
    public:
        int key;
        int val;
        Node* next = NULL;
};

class MyHashMap {
    Node* head;
public:
    MyHashMap() {
        head = NULL;
    }
    
    void put(int key, int value) {
        Node* tempNode = head;
        Node* newNode = new Node;
        newNode->key  = key;
        newNode->val = value;
        if(head == NULL){
            head = newNode;
            return;
        }
            
        while(tempNode != NULL){
            if(tempNode->key == key){
                tempNode->val = value;
                delete newNode;
                return;
            }
            tempNode = tempNode->next;
        }
        newNode->next = head;
        head = newNode;
        
    }
    
    int get(int key) {
        Node* tempNode = head;
        while(tempNode != NULL){
            if(tempNode->key == key)
                return tempNode->val;
            tempNode = tempNode->next;
        }
        return -1;
    }
    
    void remove(int key) {
        Node* tempNode = head;
        Node* prev = NULL;
        Node* tempHold = NULL;
        while(tempNode != NULL){
            if(tempNode->key == key){
                if(prev == NULL){
                    head = tempNode->next;
                    delete tempNode;
                    return;
                }else{
                     prev->next = tempNode->next;
                    delete tempNode;
                    return;
                }
            }
            prev = tempNode;
            tempNode = tempNode->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */