//--------------------------------------------------------------------
//
//  StackLinked.h
// 
//  Class declaration for the link-based implementation of the Stack ADT.
//
//--------------------------------------------------------------------

#ifndef STACKLINKED_H
#define STACKLINKED_H

#include "Stack.h"

template <typename DataType>
class StackLinked : public Stack<DataType> {

public:

	StackLinked(int maxNumber = Stack<DataType>::MAX_STACK_SIZE);
	StackLinked(const StackLinked& other);
	StackLinked& operator=(const StackLinked& other);
	~StackLinked();

	void push(const DataType& newDataItem) throw (logic_error);
	DataType pop() throw (logic_error);

	void clear();

	bool isEmpty() const;
	bool isFull() const;

	//void showStructure() const;

private:
	class StackNode {
	public:
		StackNode(const DataType& nodeData, StackNode* nextPtr);

		DataType dataItem;
		StackNode* next;
	};
	StackNode* top;
};
#endif		//#ifndef STACKLINKED_H