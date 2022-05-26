#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(nullptr) {}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

// exists() member function
// calls helper function and passes in the list calling exists's head
// can't have a member function exist() that passes in the list's head because head
// is encapsulated meaning it is hidden from the user (they can't access it)
bool IntList::exists(int value) const {
   return exists(this->head, value);
}

// exists() helper function
// we have to use a helper function because if we define temp within the function
// and point it to head, the recursive call will point temp to head's next
// but then repoint it back to head (infinite recursion)

// to avoid this, then pass an IntNode pointer as a parameter storing the location of the node
// you want to start at 
bool IntList::exists(IntNode *temp, int val) const {
   // if the list is empty
   if (temp == nullptr) {
      return false;
   }
   // if the value stored in temp is equal to the value we're looking for return true
   if (temp->value == val) {
      return true;
   // otherwise call exists() on the list after the first node and see if the value exists anywhere there
   } else {
      return exists(temp->next, val);
   }
}

// operator<< member function
ostream & operator<<(ostream &out, const IntList &pList) {
   return operator<<(out, pList.head);
}

// operator<< helper function
ostream & operator<<(ostream &o, IntNode *temp) {
   // if the list is empty return blank
   if (temp == nullptr) {
      return o;
   }
   // if there's one node in the list
   if (temp->next == nullptr) {
      o << temp->value;
   }
   // recursive case: save temp's value to o, then call operator<< which will save the values of the list
   // starting after the first node into o
   else {
      o << temp->value << ' ';
      operator<<(o, temp->next);
   }
   return o;
}
