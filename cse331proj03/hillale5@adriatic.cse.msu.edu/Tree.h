#ifndef CTREE_H
#define CTREE_H

#include <iostream>
using std::cout;
using std::endl;

template<class T> class CTree
{
public:
    CTree() {m_root = 0;}
    ~CTree() {delete m_root;}

    //
    // class Node
    // The nested node class for objects in our tree.
    //

    class Node 
    {
    public:
        friend class CTree;

        Node() {m_ll = 0;  m_rl = 0;}
        Node(const T &t) {m_number = t;  m_ll = 0;  m_rl = 0;}
        ~Node() {delete m_ll;  delete m_rl;}

        T &Data() {return m_number;}
        const T &Data() const {return m_number;}

    private:
        Node    *m_ll;
        Node    *m_rl;
        T       m_number;

    };

    void Insert(const T &t) {
        if(m_root == 0){
            m_root = new Node(t);
        }
        else{
            Insert2(t, m_root);
        }
    }
    
    //I defined a new Insert that takes a node as an input
    //that allows me to use recursion with Insertion
    
    void Insert2(const T &t, Node *n){
        if(t < n->m_number){
            if(n->m_ll == 0){
                n->m_ll = new Node(t);
            }
            else{
                Insert2(t, n->m_ll);
            }
        }
        else{
            if(n->m_rl == 0){
                n->m_rl = new Node(t);
            }
            else{
                Insert2(t, n->m_rl);
            }
        }
    }
    
    void Preorder(std::ostream &p_str) {
        p_str << m_root->m_number << " ";
        Preorder2(p_str, m_root->m_ll);
        Preorder2(p_str, m_root->m_rl);
    }
    
    //I defined a new Preorder to take a node as the input
    //this allows me to use recursion with Preorder
    
    void Preorder2(std::ostream &p_str, Node *n){
        if(n){
        p_str << n->m_number << " ";
        Preorder2(p_str, n->m_ll);
        Preorder2(p_str, n->m_rl);
        }
    }
    
    int Depth() {
        int ldepth,rdepth;
        ldepth = Depth2(m_root->m_ll);
        rdepth = Depth2(m_root->m_rl);
        if(ldepth > rdepth){
            return ldepth;
        }
        else{
            return rdepth;
        }
    }
    
    //again, a 2nd function for recursion
    
    int Depth2(Node *n){
        int ldepth,rdepth;
        if(n==0){
            return 0;
        }
        else{
            ldepth=Depth2(n->m_ll);
            rdepth=Depth2(n->m_rl);
            if(ldepth > rdepth){
                return (ldepth + 1);
            }
            else{
                return (rdepth + 1);
            }
        }

    }

    const Node *Find(const T &t) const {
        Node *temp = m_root;

        while (temp != 0){
            if (temp->m_number == t){
                return temp;
            }

            if (t > temp->m_number){
                temp = temp->m_rl;
            }
            else if (t < temp->m_number){
                temp = temp->m_ll;
            }
         }
    }
    
    Node *Find(const T &t) {
        if(t == 0){
            return new Node;
        }
        
        Node *temp = m_root;

        while (temp != 0){
            if (temp->m_number == t){
                return temp;
            }

            if (t > temp->m_number){
                temp = temp->m_rl;
            }
            else if (t < temp->m_number){
                temp = temp->m_ll;
            }
         }
    }
    
    /*T Test(const T &t){
        Node *help = Find(t);
        T check = help->m_number;
    }*/
    
    Node *findMin(Node *t) const{
        if(t == NULL){
            return NULL;
        }
        if(t->m_ll == NULL){
            return t;
        }
        return findMin(t->m_ll);
    }
    
    Node* findparent(const T &t){
        Node* p=m_root;
        Node* q=0;
        while((p!=NULL)&&(p->m_number!=t)){
            q=p;
            if(t<p->m_number){
                p=p->m_ll;
            }
            else{
                p=p->m_rl;
            }
        }
        return q;
    }


    void Delete(const T &t){
       Node *deletenode = Find(t);
       if(deletenode->m_number == 0){
           return;
       }
       if(deletenode->m_rl != 0){
           if(deletenode->m_rl->m_rl == 0 && deletenode->m_rl->m_ll == 0){
               deletenode->m_number = deletenode->m_rl->m_number;
               deletenode->m_rl = NULL;
           }
           else{
               Node *minnode = findMin(deletenode->m_rl);
               Node *minnodeparent = findparent(minnode->m_number);
               deletenode->m_number = minnode->m_number;
               if(minnode->m_rl != 0){
                   minnodeparent->m_ll = minnode->m_rl;
               }
               minnode = NULL;
           }
       }
       else{
           if(deletenode->m_ll == 0){
               Node *parent = findparent(deletenode->m_number);
               if(parent->m_ll != 0 && parent->m_ll != NULL){
                   if(parent->m_ll->m_number == deletenode->m_number){
                       parent->m_ll = NULL;
                   }
                   else{
                       parent->m_rl = NULL;
                   }
               }
               else{
                   parent->m_rl = NULL;
               }
           }
           else{
               deletenode->m_number = deletenode->m_ll->m_number;
               deletenode->m_ll = NULL;
  
           }
       }
        
       
    }
    
    


private:
    Node *m_root;
};


#endif