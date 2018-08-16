#include <iostream>
#include<string>
using namespace std;

        struct Node
        {
            string prodname;
            int timeseq;
            int price;
            int counter;

            Node* next;
        };


        Node* sortedMerge(Node* a,Node* b)
        {
            Node* result=NULL;

            if(a==NULL)
            {
                return b;
            }
            else if(b==NULL)
            {
                return a;
            }

            if(a->timeseq <= b->timeseq)
            {
                result=a;
                result->next=sortedMerge(a->next,b);
            } else
            {
                result=b;
                result->next=sortedMerge(a,b->next);
            }
            return result;
        }

        void FrontBackSplit(Node* source,Node** frontref,Node** backref)
        {
            Node* fast;
            Node* slow;

            slow=source;
            fast=source->next;

            while(fast!=NULL)
            {
                fast=fast->next;

                if(fast!=NULL)
                {
                    slow=slow->next;
                    fast=fast->next;

                }
            }

            *frontref=source;
            *backref=slow->next;
            slow->next=NULL;
        }

        void mergeSort(Node** headref)
        {
            Node* head= *headref;
            Node* a;
            Node* b;

            if ((head == NULL) || (head->next == NULL))
            {
                return;
            }

            FrontBackSplit(head, &a, &b);

            mergeSort(&a);
            mergeSort(&b);

            *headref = sortedMerge(a, b);
        }

        void push(Node** headref,string pname,int t,int pr,int c)
        {

            Node* newNode = new Node;

            newNode->prodname=pname;
            newNode->price=pr;
            newNode->timeseq=t;
            newNode->counter=c;

            newNode->next=*headref;

            (*headref)=newNode;

        }

        void del(Node** before_del)
        {
            Node *temp;
            temp=*before_del;
            (*before_del)=temp->next;
            delete temp;
        }

        void listmerge(Node** oref,Node** qref)
        {
            while ((*qref)!=NULL) {
                push(oref, (*qref)->prodname, (*qref)->timeseq, (*qref)->price, (*qref)->counter);
                del(qref);
            }
        }

        void printlist(Node* node)
        {
            while(node!=NULL)
            {
                cout<<node->prodname<<","<<node->timeseq<<","<<node->price<<","<<node->counter<<endl;
                node = node->next;
            }
        }

        void Merge(Node** oref,Node** qref)
        {
            listmerge(oref,qref);
            mergeSort(oref);
            printlist(*oref);
        }

int main() {

    Node* order=NULL;
    Node* quote=NULL;

    push(&order,"GOLD",1000,9999,1);
    push(&order,"SILVER",3001,1200,2);
    push(&order,"GOLD",1233,900,3);
    push(&order,"COPPER",2200,500,4);
    push(&order,"SILVER",1010,2200,5);
    push(&order,"GOLD",1002,550,6);

    push(&quote,"GOLD",999,1000,7);
    push(&quote,"SILVER",1001,490,8);
    push(&quote,"GOLD",2330,459,9);
    push(&quote,"COPPER",2000,2100,10);
    push(&quote,"SILVER",3010,3000,11);
    push(&quote,"GOLD",1100,999,12);

    Merge(&order,&quote);
    //printlist(order);

    //cout << "Hello, World!" << std::endl;
    return 0;
}