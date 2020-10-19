#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>

template <typename T>

class Graph
{
private:
	vector<Node<T>> node;
	vector<Edge> edge;
public:
	Graph(void) {};
	~Graph(void) {};

	bool empty(void)
	{
		if (node.size() == 0)
		{
			return true;
		}
		return false;
	}

	void clear(void)
	{
		node.clear();
		edge.clear();
	}

	void addNode(T _nodeObject)
	{
		if (isNodeExist(_nodeObject) == -1)
		{
			node.push_back(Node<T>(_nodeObject));
		}
	};
	void deleteNode(T _nodeObject)
	{
		short _nodeNumber = isNodeExist(_nodeObject);
		if (_nodeNumber != -1)
		{
			node.erase(node.begin() + _nodeNumber);
			for (int i = 0; i < edge.size(); i++)
			{
				if (isEdgeExist(i, _nodeNumber))
				{
					deleteEdge(i, _nodeNumber);
				}
			}
		}
	};

	void addEdge(short i, short j)
	{
		if (isEdgeExist(i, j) == false)
		{
			edge.push_back(Edge(i, j));
		}
	};
	void addEdge(T iObject, T jObject)
	{
		int i = isNodeExist(iObject), j = isNodeExist(jObject);
		if (i != -1 && j != -1 && isEdgeExist(i, j) == false)
		{
			edge.push_back(Edge(isNodeExist(iObject), isNodeExist(jObject)));
		}
	};
	void deleteEdge(short i, short j)
	{
		for (int k = 0; k < edge.size(); k++)
		{
			if (isEdgeExist(i, j) == true || isEdgeExist(j, i) == true)
			{
				edge.erase(edge.begin() + k);
				for (int m = k; m < edge.size() - 1; m++)
				{
					edge[m] = edge[m + 1];
				}
				edge.pop_back();
				if (edge.size() != 0)
				{
					edge.pop_back();
				}
			}
		}
	};
	void deleteEdge(T iObject, T jObject)
	{
		for (int k = 0; k < edge.size(); k++)
		{
			if (isEdgeExist(iObject, jObject) != -1)
			{
				edge.erase(edge.begin() + k);
			}
		}
	};

	short nodeDegree(T _nodeObject)
	{
		short degree = 0;
		short nodeNumber = isNodeExist(_nodeObject);
		if (nodeNumber != -1)
		{
			for (int i = 0; i < node.size(); i++)
			{
				bool isExist = isEdgeExist(i, nodeNumber);
				degree += isExist == true ? 1 : 0;
			}
			return isEdgeExist(nodeNumber, nodeNumber) == true ? ++degree : degree;
		}
		else
		{
			return -1;
		}
	};

	void edgesFromFile(string filename)
	{
		ifstream inputFileStream;
		inputFileStream.open(filename);
		if (!inputFileStream.is_open() == true)
		{
			inputFileStream.close();
			return;
		}
		short beginNode = 0, endNode = 0;
		while (inputFileStream.eof() == false)
		{
			inputFileStream >> beginNode >> endNode;
			if (beginNode >= node.size() || endNode >= node.size())
			{
				continue;
			}
			edge.push_back(Edge(beginNode, endNode));
		}
		inputFileStream.close();
	};

	bool isEdgeExist(short i, short j)
	{
		for (int k = 0; k < edge.size(); k++)
		{
			if ((edge[k].getBegin() == i && edge[k].getEnd() == j) || (edge[k].getBegin() == j && edge[k].getEnd() == i))
			{
				return true;
			}
		}
		return false;
	};
	short isEdgeExist(T iObject, T jObject)
	{
		for (int k = 0; k < edge.size(); k++)
		{
			if ((node[edge[k].getBegin()].getObject() == iObject && node[edge[k].getEnd()].getObject() == jObject) ||
				(node[edge[k].getBegin()].getObject() == jObject && node[edge[k].getEnd()].getObject() == iObject))
			{
				return k;
			}
		}
		return -1;
	};
	short isNodeExist(T _nodeObject)
	{
		for (int i = 0; i < node.size(); i++)
		{
			if (node[i].getObject() == _nodeObject)
			{
				return i;
			}
		}
		return -1;
	};
	bool isNodeExist(short _nodeNumber)
	{
		return _nodeNumber < node.size();
	};

	short countOfLoops()
	{
		short count = 0;
		for (int i = 0; i < node.size(); i++)
		{
			count += isEdgeExist(i, i) == true ? 1 : 0;
		}
		return count;
	}

	short countOfNodes()
	{
		return node.size();
	};
	short countOfEdges()
	{
		return edge.size();
	};

	void showNodes()
	{
		cout << endl;
		for (int i = 0; i < node.size(); i++)
		{
			cout << node[i].getObject() << endl;
		}
	};
	void showEdges()
	{
		cout << endl;
		for (int i = 0; i < edge.size(); i++)
		{
			cout << node[edge[i].getBegin()].getObject() << " - " << node[edge[i].getEnd()].getObject() << endl;
		}
	};