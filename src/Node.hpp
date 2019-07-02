#ifndef ED_TP3_NODE_HPP
#define ED_TP3_NODE_HPP

class Node {
public:
	explicit Node(char data);
	Node();
	~Node();

	char getData() const;
	Node* getLeft() const;
	Node* getRight() const;

	void setData(char data);
	void setLeft(Node* left);
	void setRight(Node* right);

private:
	char data;
	Node* left;
	Node* right;
};

#endif // ED_TP3_NODE_HPP
