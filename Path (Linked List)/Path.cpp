#include "Path.h"
#include <iostream>

using namespace std;

Path::Path()
{
	_startNode = nullptr;
	_topNode = nullptr;
	_length = 0;
}

Path::Path(int size):
	_length(size)
{
	_startNode = nullptr;
	_topNode = nullptr;

}

Path::Path(const Path& otherPath)
{
	_length = otherPath.getLength();
	_startNode = new Node[_length];

	Node* otherPathNodes = otherPath.getPathNodes();

	if (otherPathNodes)
	{
		for (int i = 0; i < _length; i++)
		{
			_startNode[i] = otherPathNodes[i];
		}
	}
}


Path Path::operator=(const Path& otherPath)
{
	_length = otherPath.getLength();
	_startNode = new Node[_length];

	Node* otherPathNodes = otherPath.getPathNodes();

	if (otherPathNodes)
	{
		for (int i = 0; i < _length; i++)
		{
			_startNode[i] = otherPathNodes[i];
		}
	}

	return (*this);
}

void Path::addNode(int x, int y)
{
	Node* newNode = new Node; //Create new node

	newNode->x = x;  //Set node position values
	newNode->y = y;

	if (_length == 0) //If path is empty 
	{
		_startNode = newNode;  //Point start node to new node
		_topNode = newNode;    //Point top node to new node
	}

	
	_topNode->_nextNode = newNode;   //Link node that was previously top to the new node
	_topNode = _topNode->_nextNode;  //Point top to the new node in list
	newNode->_nextNode = nullptr;

	_length++; //Increment length of list by 1;
}


void Path::popBack()
{
	if (_startNode)
	{
		Node* temp = _startNode; 

		while (temp->_nextNode != nullptr)  //while the next node doesnt = nullptr
		{
			_topNode = temp;              //update top to current node
			temp = temp->_nextNode;       //update temp to next node
		}

		delete temp;
		_topNode->_nextNode = nullptr;
		_length--;
	}
}

bool Path::empty()
{
	if (_length > 0)
	{
		return false;
	}

	return true;
}


Path::~Path()
{
	popAll();

	if (_startNode->_nextNode)
	{
		delete _startNode;
		_startNode = nullptr;
	}
}

void Path::printList()
{
	if (!empty())
	{
		Node* temp = _startNode;

		while (temp != nullptr)
		{
			printf("(%i, %i) -- ", temp->x, temp->y);
			temp = temp->_nextNode;
		}
	}
}

void Path::popAll()
{
	while (!empty())
	{
		popBack();
	}
}


Node* Path::getNode(int index) const
{
	if (index > 0 && index <= _length)
	{
		Node* temp = _startNode;

		for (int i = 1; i < index; i++)
		{
			temp = temp->_nextNode;
		}
		return temp;
	}

	return nullptr;
}


void Path::popFront()
{
	if (!empty())
	{
		Node* temp = _startNode->_nextNode;
		delete _startNode;
		_startNode = temp;
		_length--;
	}
}

void Path::removeNode(int index)
{
	if (!empty())
	{
		if (index == 1)
		{
			Node* temp = _startNode;
			_startNode = _startNode->_nextNode;
			delete temp; 
			temp = nullptr;
			_length--;
		}
		else if (index > 1 && index <= _length)
		{
			Node* current = _startNode;
			Node* previous = new Node;

			for (int i = 1; i < index; i++)
			{
				previous = current;
				current = current->_nextNode;
			}

			previous->_nextNode = current->_nextNode;
			delete current;
			current = nullptr;
			_length--;
		}
	}
}


void Path::insertNode(int x, int y, int index)
{
	if (!empty())
	{
		if (index == 1)
		{
			Node* newNode = new Node;
			newNode->x = x;
			newNode->y = y;

			newNode->_nextNode = _startNode;
			_startNode = newNode;
			_length++;
		}
		else if (index > 1 && index <= _length)
		{
			Node* newNode = new Node;
			newNode->x = x;
			newNode->y = y;

			Node* current = _startNode;
			Node* previous = new Node;

			for (int i = 1; i < index; i++)
			{
				previous = current;
				current = current->_nextNode;
			}

			previous->_nextNode = newNode;
			newNode->_nextNode = current;
			_length++;
		}
	}
}
