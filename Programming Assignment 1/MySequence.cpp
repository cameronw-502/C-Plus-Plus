
#include <iostream>
#include <cstdio>
using namespace std;

template <class T>
class Sequence
{
private: // Internal Representation
    
    class NodeRecord {
    public:
        T value;
        NodeRecord* next;
    };
    NodeRecord* head;
    int size;
    
public:
    Sequence ();
    ~Sequence ();
    void clear (void);
    
    //implement the following four functions
    void add (T& x, int pos);
    //! updates self
    //! restores pos
    //! clears x
    //! requires: 0 â‰¤ pos â‰¤ |self|
    //! ensures: self = #self[0, pos) * <#x> * #self[pos, |#self|)
    
    void remove (T& x, int pos);
    //! updates self
    //! restores pos //! replaces x
    //!requires: 0 â‰¤ pos < |self|
    //!ensures: <x> = #self[pos, pos+1) and
    //!        self = #self[0, pos) * #self[pos+1, |#self|)
    
    T& entry (int pos);
    //! restores self, pos
    //! requires: 0 â‰¤ pos < |self|
    //! ensures: <entry> = self[pos, pos+1)
    
    int length (void);
    //! restores self
    //! ensures: length = |self|
    
    void outputSequence(void);
    //! restores self
    //! ensures: self = #self
    
private: // Internal operations
    void reclaimAllNodes (NodeRecord*& p);
};

template <class T>
Sequence<T>::Sequence ()
{
    head = NULL;
    size = 0;
}// Sequence

template <class T>
Sequence<T>::~Sequence ()
{
    reclaimAllNodes(head);
}    // ~Sequence


template <class T>
void Sequence<T>::clear (void)
{
    reclaimAllNodes(head);
    head = NULL;
} // clear

template <class T>
void Sequence<T>::reclaimAllNodes (NodeRecord*& initialP)
// requires: Null(initialP)  or  Alive(initialP)
//  ensures: all nodes in linked list
//           beginning with initialP are reclaimed
{
    if (initialP != NULL) {
        reclaimAllNodes(initialP->next);
        delete (initialP);
    } // end if
} // reclaimAllNodes

// You are required to implement add, remove, entry, length, and outputSequence functions here.

int main(){
    /* Complete this main function to test all functions of the Sequence class.
       Must use at least 3 Sequence type objects to test the functions.
       Make sure to test all boundary conditions (See Canvas assignment for more info.).
       Copy and paste properly labeled outputs below the main function.
    */
    return 0;
}

/*  Copy and paste PROPERLY LABELED (Must identify each and every output, what Sequence and what function being tested)
 */