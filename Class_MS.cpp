#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>

template <typename T>

template <typename T>
class Node
{
private:
	T node;
public:
	Node(T _node = T())
	{
		node = _node;
	}
	string getObject()
	{
		return node;
	}
};

class Edge {
	short begin;
	short end;
public:
	Edge(short _begin = 0, short _end = 0)
	{
		begin = _begin;
		end = _end;
	}
	short getBegin()
	{
		return begin;
	}
	short getEnd()
	{
		return end;
	}
	void setBegin(short _begin)
	{
		begin = _begin;
	}
	void setEnd(short _end)
	{
		end = _end;
	}
};

template <typename T>
class Node
{
private:
	T node;
public:
	Node(T _node = T())
	{
		node = _node;
	}
	string getObject()
	{
		return node;
	}
};

class Edge {
	short begin;
	short end;
public:
	Edge(short _begin = 0, short _end = 0)
	{
		begin = _begin;
		end = _end;
	}
	short getBegin()
	{
		return begin;
	}
	short getEnd()
	{
		return end;
	}
	void setBegin(short _begin)
	{
		begin = _begin;
	}
	void setEnd(short _end)
	{
		end = _end;
	}
};

//for alisa
class Edge_iterator
	{
	private:
		Graph<T> *graphForIteration;
		int index;

	public:
		Edge_iterator(Graph<T> &graph)
		{
			graphForIteration = &graph;
			index = 0;
		}
		bool next()
		{
			if (graphForIteration->edge.size() <= index + 1)
			{
				return false;
			}
			index++;
			return true;
		}
		bool prev()
		{
			if (index == 0)
			{
				return false;
			}
			index--;
			return true;	}
	};
//for alisa
class Node_Iterator
	{
	private:
		Graph<T> *graphForIteration;
		int index;
	public:
		Node_Iterator(Graph<T> &graph)
		{
			graphForIteration = &graph;
			index = 0;
		}

		bool next()
		{
			if (graphForIteration->node.size() <= index + 1)
			{
				return false;
			}
			index++;
			return true;
		}
		bool prev()
		{
			if (index == 0)
			{
				return false;
			}
			index--;
			return true;
		}

