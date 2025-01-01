#include "ball.hpp"

class objlinkedlist
{
    protected:
        int listSize;
        
        struct node
        {   

            int index;
            node* next;

        };
        
        node* head;

    
    public:
        objlinkedlist();
        ~objlinkedlist();

        objlinkedlist(const objlinkedlist &r);
        objlinkedlist &operator=(const objlinkedlist &r);

        void addItem(int index);
        void removeItem(int index);

        int getSize();




};