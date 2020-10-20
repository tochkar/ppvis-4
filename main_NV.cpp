int main(void)
{
	short choise = 1;
	string str_1 = "";
	string str_2 = "";

	Graph<string>* G = new Graph<string>();

	while (true)
	{
		cout << "1. Add node" << endl;
		cout << "2. Add edge" << endl;
		cout << "3. Delete node" << endl;
		cout << "4. Delete edge" << endl;
		cout << "5. Import from file" << endl;
		cout << "6. Number of edges and nodes" << endl;
		cout << "7. Show nodes" << endl;
		cout << "8. Show edges" << endl;
		cout << "9. Degree of node" << endl;
		cout << "10. Iterator for nodes" << endl;
		cout << "11. Iterator for edges" << endl;
		cout << "12. Is node exist" << endl;
		cout << "13. Is edge exist" << endl;
		cout << "14. Is container empty" << endl;
		cout << "15. Clear" << endl;
		cout << "0. Exit" << endl;
		cout << "Your choise: ";

		cin >> choise;
		switch (choise)
		{
		case 0:
		{
			return 0;
		}
		case 1:
		{
			cout << endl << "Enter node name: ";
			cin >> str_1;
			system("cls");
			G->addNode(str_1);
			break;
		}
		case 3:
		{
			cout << endl << "Enter node name: ";
			cin >> str_1;
			system("cls");
			G->deleteNode(str_1);
			break;
		}
		case 2:
		{
			cout << endl << "Enter nodes names: ";
			cin >> str_1 >> str_2;
			system("cls");
			G->addEdge(str_1, str_2);
			break;
		}
		case 4:
		{
			cout << endl << "Enter nodes names: ";
			cin >> str_1 >> str_2;
			system("cls");
			G->deleteEdge(str_1, str_2);
			break;
		}
		case 5:
		{
			cout << endl << "Enter a file name: ";
			cin >> str_1;
			system("cls");
			G->edgesFromFile(str_1);
			break;
		}
		case 6:
		{
			cout << endl << "Nodes: " << G->countOfNodes()
				<< endl << "Edges: " << G->countOfEdges()
				<< endl;
			Sleep(1000);
			system("cls");
			break;
		}
		case 7:
		{
			if (G->countOfNodes() == 0)
			{
				cout << "No nodes" << endl;
				Sleep(1000);
				system("cls");
				break;
			}
			G->showNodes();
			Sleep(1000);
			system("cls");
			break;
		}
		case 8:
		{
			if (G->countOfEdges() == 0)
			{
				cout << "No edges";
				Sleep(1000);
				system("cls");
				break;
			}
			G->showEdges();
			Sleep(1000);
			system("cls");
			break;
		}
		case 9:
		{
			cout << endl << "Enter a node name: ";
			cin >> str_1;
			short degree = G->nodeDegree(str_1);
			if (degree == -1)
			{
				cout << "No node with this name" << endl;
			}
			else
			{
				cout << "Node degree: " << degree;
			}
			Sleep(1000);
			system("cls");
			break;
		}
		case 10:
		{
			Graph<string>::Node_Iterator G_iterator(*G);
			while (choise != 5)
			{
				cout << endl << "1. Next node" << endl;
				cout << "2. Previous node" << endl;
				cout << "3.Get adjacent nodes" << endl;
				cout << "4.Get incident edges" << endl;
				cout << "5.Exit" << endl;
				cout << "Your choise: ";
				cin >> choise;

				switch (choise)
				{
				case 1:
				{
					if (G_iterator.next() == false)
					{
						cout << endl << "Iterator is on the last node" << endl;
					}
					else
					{
						cout << endl << "Iterator moved to next node" << endl;
					}
					break;
				}
				case 2:
				{
					if (G_iterator.prev() == false)
					{
						cout << endl << "Iterator is on the first node" << endl;
					}
					else
					{
						cout << endl << "Iterator moved to previous node" << endl;
					}
					break;
				}
				case 3:
				{
					G_iterator.getAdjacentNodes();
					break;
				}
				case 4:
				{
					G_iterator.getIncidentEdges();
					break;
				}
				default:
					Sleep(1000);
					system("cls");
					break;
				}
			}
			break;
		}
		case 12:
		{
			cout << endl << "Enter node name: ";
			cin >> str_1;
			if (G->isNodeExist(str_1) != -1)
			{
				cout << endl << "This node exist" << endl;
			}
			else
			{
				cout << endl << "This node doesn't exist" << endl;
			}
			Sleep(1000);
			system("cls");
			break;
		}
		case 11:
		{
			Graph<string>::Node_Iterator G_iterator(*G);
			while (choise != 3)
			{
				cout << endl << "1. Next edge" << endl;
				cout << "2. Previous edge" << endl;
				cout << "3. Exit" << endl;
				cout << endl << "Your hoose: ";
				cin >> choise;

				switch (choise)
				{
				case 1:
				{
					if (G_iterator.next() == false)
					{
						cout << endl << "Iterator is on the last edge" << endl;
					}
					else
					{
						cout << endl << "Iterator moved to next edge" << endl;
					}
					break;
				}
				case 2:
				{
					if (G_iterator.prev() == false)
					{
						cout << endl << "Iterator is on the first edge" << endl;
					}
					else
					{
						cout << endl << "Iterator moved to previous edge" << endl;
					}
					break;
				}
				default:
					Sleep(1000);
					system("cls");
					break;
				}
			}
			break;
		}
		case 13:
		{
			cout << endl << "Enter a nodes names: ";
			cin >> str_1 >> str_2;
			if (G->isEdgeExist(str_1, str_2) != -1)
			{
				cout << endl << "This edge exist" << endl;
			}
			else
			{
				cout << endl << "This edge doesn't exist" << endl;
			}
			Sleep(1000);
			system("cls");
			break;
		}
		case 14:
		{
			(G->empty() == true) ? cout << endl << "Empty" << endl : cout << endl << "Not empty" << endl;
			Sleep(1000);
			system("cls");
			break;
		}
		case 15:
		{
			G->clear();
			Sleep(1000);
			system("cls");
			break;
		}
		default: break;
		}
	}
}