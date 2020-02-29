#pragma once



struct Node
{
	int x;
	int y;
	Node* _nextNode;
};

class Path
{
public:
	Path();
	Path(int size);
	Path(const Path& otherPath);
	~Path();
	Path operator=(const Path& otherPath);

	//Modifiers
	void addNode(int x, int y);
	void popBack();
	void popFront();
	void popAll();
	void removeNode(int index);
	void insertNode(int x, int y, int index);


	void printList();

	bool empty();
	Node* getNode(int index) const;
	int getLength()const { return _length; }
	Node* getPathNodes() const { return _startNode; }
	Node* _topNode;
	Node* _startNode;
	int _length;
private:
	

};

