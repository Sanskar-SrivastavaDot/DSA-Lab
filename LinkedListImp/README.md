## __Linked List Implementation__
---
### Linked List Class(ll):
> A ll class Contains just two Node pointers head and tail and when it is instantiated both head and tail are __NULL__.
### Node Definition:
> A Node class object contains a integer value and a pointer to the another Node object which comes after that node(NULL if its the Tail).

### Functionalities added to Linked List:

- __add(int val)__: It is used to add a elemennt in the list if the list is empty it makes a new node and assign that to head pointer else it takes the tail and add the new node to tail->next and make it the new tail.
- __delete(int idx)__: It is used to delete the element in the linked list. It finds the element by searching it in the list if the list doesnt have any element returns the message "List is empty" otherwise delete the element at the given idx by removing it link to prev and next element and join its prev elements link to the next ones.
- __search(int val)__: It finds the entered element and returns its index otherwise returns not found. It uses a simple loop and a variable node temp to move accross the list and chec if element exist or not.
- __show()__ : A loop with a variable node temp that iterates the loop and print the values of the nodes one by one.


