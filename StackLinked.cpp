//--------------------------------------------------------------------
//
//  StackLinked.cpp
// 
//  Method implementations for the link-based implementation of the Stack ADT.
//
//--------------------------------------------------------------------

#include "StackLinked.h"

template <typename DataType>
StackLinked<DataType>::StackLinked(int maxNumber) :top(nullptr) {}
// end StackLinked constructor

template <typename DataType>
StackLinked<DataType>::StackNode
::StackNode(const DataType& nodeData, StackNode* nextPtr) : dataItem(nodeData), next(nextPtr) {}
// end StackNode constructor

template<typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other)
{
	*this = other; // uses overloaded operator
} // end Copy Constructor

template <typename DataType>
StackLinked<DataType>::~StackLinked()
{
	clear();
} // end destructor

template<typename DataType>
StackLinked<DataType>& StackLinked<DataType>::operator=(const StackLinked& other)
{  // creates new node instantiated with other stack and this stack's top
   // ends when other stack points to null
	for (StackNode* temp = other.top; temp != nullptr; temp = temp->next) {
		StackNode *NextNewNodePtr = new StackNode(temp->dataItem, top);
		top = NextNewNodePtr;
	} // end for
	return *this;
} // end Copy Constructor

template <typename DataType>
void StackLinked<DataType>::push(const DataType& newDataItem) throw (logic_error)
{ // pushes newDataItem onto stack and points top to nextNode
	if (!isFull())
	{
		StackNode* nextNode = new StackNode(newDataItem, top);
		top = nextNode;
	} // end if
	else
		throw logic_error("Stack is full.");
} // end push

template<typename DataType>
DataType StackLinked<DataType>::pop() throw (logic_error)
{
	if (!isEmpty())
	{
		StackNode* nodeToDelete = top; // sets nodeToDelete to top
		top = top->next;  // sets top to previous node
		DataType value = nodeToDelete->dataItem; // saves deleted node to be returned
		nodeToDelete->next = nullptr; 
		nodeToDelete = nullptr; // setting pointers to nullptr or nullptr
		delete nodeToDelete; // deleting node.
		return value;
	} // end if
	else
		throw logic_error("Stack is empty.");
} // end pop

template <typename DataType>
bool StackLinked<DataType>::isEmpty() const
{
	if (top == nullptr)
		return true;
	else
		return false;
} // end isEmpty

template <typename DataType>
bool StackLinked<DataType>::isFull() const
{
	return false; // Assume never true
} // end isFull

template<typename DataType>
void StackLinked<DataType>::clear()
{ // clears node.
	while (top != nullptr)
	{
		this->pop(); // uses pop() to clear
	} // end while
} // end clear

/*
template <typename DataType>
void StackLinked<DataType>::showStructure() const

// Linked list implementation. Outputs the data elements in a stack.
// If the stack is empty, outputs "Empty stack". This operation is
// intended for testing and debugging purposes only.

{
	if (isEmpty())
	{
		cout << "Empty stack" << endl;
	}
	else
	{
		cout << "Top\t";
		for (StackNode* temp = top; temp != nullptr; temp = temp->next) {
			if (temp == top) {
				cout << "[" << temp->dataItem << "]\t";
			}
			else {
				cout << temp->dataItem << "\t";
			}
		}
		cout << "Bottom" << endl;
	}

} // end showStructure
*/
