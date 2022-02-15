class Node
{
public:
    int key;
    int val;
    Node *next = NULL;
    Node *prev = NULL;
};

class LRUCache
{
private:
    int cap;
    int size = 0;
    Node *head = NULL;
    Node *tail = NULL;
    unordered_map<int, Node *> mp;
   
  

   void updateNode(Node* &node){
       if(tail == node){
           head->prev = tail;
           tail->next = head;
           head = tail;
           tail = tail->prev;
           tail->next = NULL;
           return;
       }
       if(head == node){
           return;
       }
       node->prev->next = node->next;
       node->next->prev = node->prev;
       head->prev = node;
       node->prev = NULL;
       node->next = head;
       head = node;
   }


    void addNode(Node* node){
        head->prev = node;
        node->next = head;
        head = node;
        return;
    }

public:
    LRUCache(int capacity)
    {
        cap = capacity;
    }

    int get(int key)
    {
         auto it = mp.find(key);
         if(it != mp.end()){
          
          updateNode(it->second);
          return it->second->val;
      }
      return -1;
    }

    void put(int key, int value)
    {
      auto it = mp.find(key);
      
      if(it != mp.end()){
          it->second->val = value;
          updateNode(it->second);
          return;
      }


     if(head == NULL){
          Node* newNode = new Node;
         newNode->key = key;
         newNode->val = value;
         mp.insert({key,newNode});
         head = newNode;
         tail = newNode;
         size++;
         return;
      }
      
     if(size < cap){
         Node* newNode = new Node;
         newNode->key = key;
         newNode->val = value;
         mp.insert({key,newNode});
         addNode(newNode);
         size++;
         return;
     }

    mp.erase(tail->key);
    head->prev = tail;
    tail->next = head;
    head = tail;
    tail = head->prev;
    tail->next = NULL;
    head->key = key;
    head->val = value;
    mp.insert({key,head});
}

};