#include <iostream>
#include <vector>
#include <queue>
#include <conio.h>
#include <locale>

using namespace std;

#define maxSize 10




template <class T>
class Graph
{
private:
	int adjMatrix[10][10];
	vector <int> vertList;
	vector <int> labelList;
	vector <bool> visitedVerts;




public:
	Graph();
	~Graph();

	int GetVertPos(const T& vertex);
	int GetAmountVerts();
	int GetAmountEdges();
	int GetWeight(const T& vertex1, const T& vertex2);
	vector<T> GetNbrs(const T& vertex);
	int Dijkstra(T& startVertex);


	void InsertVertex(const T& vertex);
	void InsertEdge(const T& vertex1, const T& vertex2, int weight);
	void Print();

	bool IsEmpty();
	bool IsFull();
};





template<class T>	//объявление шаблона с формальным параметром класс Т
Graph<T>::Graph()	//конструктор, который инициализирует значения объектов класса Graph
{
	//перебор строк и столбцов матрицы смежности и заполнение её нулями
	for (int i = 0; i < maxSize; ++i) {
		for (int j = 0; j < maxSize; ++j) {
			this->adjMatrix[i][j] = 0;
		}
	}
}


template<class T>
Graph<T>::~Graph()
{}



template <class T>
int Graph<T>::GetVertPos(const T& vertex)
{
	for (int i = 0; i < this->vertList.size(); ++i) {
		if (this->vertList[i] == vertex)
			return i;
	}
	return -1;
}



template<class T>
bool Graph<T>::IsEmpty()
{
	if (this->vertList.size() != 0)
		return false;
	else
		return true;
}


template<class T>
bool Graph<T>::IsFull()
{
	return (vertList.size() == maxSize);
}


template<class T>
int Graph<T>::GetAmountVerts()
{
	return this->vertList.size();
}



template<class T>
int Graph<T>::GetAmountEdges()
{
	int amount = 0; // обнуляем счетчик

	if (!this->IsEmpty())
	{ // проверяем, что граф не пуст
		for (int i = 0, vertListSize = this->vertList.size(); i < vertListSize; ++i)
		{
			for (int j = 0; j < vertListSize; ++j)
			{
				if (this->adjMatrix[i][j] == this->adjMatrix[j][i] && this->adjMatrix[i][j] != 0) // находим рёбра
				{
					amount += 1;		// считаем количество рёбер
				}
			}
		}
		return (amount / 2); // приводим счетчик к корректному результату и возвращаем его
	}
	else
	{
		return 0;		// если граф пуст, возвращаем 0
	}
}


template<class T>
int Graph<T>::GetWeight(const T& vertex1, const T& vertex2)
{
	if (!this->IsEmpty())
	{
		int vertPos1 = GetVertPos(vertex1);
		int vertPos2 = GetVertPos(vertex2);
		return adjMatrix[vertPos1][vertPos2];
	}
	return 0;
}



template<class T>
vector<T> Graph<T>::GetNbrs(const T& vertex)
{
	vector<T> nbrsList; // создание списка соседей
	int vertPos = this->GetVertPos(vertex); // вычисление позиции vertex в матрице смежности

	if (vertPos != (-1))
	{
		//проверка, что vertex есть в матрице смежности
		for (int i = 0, vertListSize = this->vertList.size(); i < vertListSize; ++i)
		{
			if (this->adjMatrix[vertPos][i] != 0 && this->adjMatrix[i][vertPos] != 0) // вычисление соседей
			{
				nbrsList.push_back(this->vertList[i]); //запись соседей в вектор
			}
		}
	}
	return nbrsList; //возврат списка соседей
}



template<class T>
void Graph<T>::InsertVertex(const T& vertex)
{
	if (!this->IsFull())
	{
		this->vertList.push_back(vertex);
	}
	else
	{
		cout << "Граф уже заполнен. Невозможно добавить новую вершину " << endl << endl;
		return;
	}
}



template<class T>
void Graph<T>::InsertEdge(const T& vertex1, const T& vertex2, int weight)
{
	if (this->GetVertPos(vertex1) != (-1) && this->GetVertPos(vertex2) != (-1))
	{
		int vertPos1 = GetVertPos(vertex1);
		int vertPos2 = GetVertPos(vertex2);

		if (this->adjMatrix[vertPos1][vertPos2] != 0 && this->adjMatrix[vertPos2][vertPos1] != 0)
		{
			cout << "Ребро между вершинами уже есть" << endl << endl;
			return;
		}
		else
		{
			this->adjMatrix[vertPos1][vertPos2] = weight;
			this->adjMatrix[vertPos2][vertPos1] = weight;
		}
	}
	else
	{
		cout << "Обеих вершин (или одной из них) нет в графе " << endl << endl;
		return;
	}
}



template<class T>
void Graph<T>::Print()
{
	if (!this->IsEmpty())
	{
		cout << "Матрица смежности графа: " << endl;

		for (int i = 0, vertListSize = this->vertList.size(); i < vertListSize; ++i)
		{
			cout << this->vertList[i] << "\t";
			for (int j = 0; j < vertListSize; ++j)
			{
				cout << this->adjMatrix[i][j] << "\t";
			}
			cout << endl;
		}
	}
	else
	{
		cout << "Граф пуст " << endl;
	}
}


template<class T>
int Graph<T>::Dijkstra(T& startVertex)
{
	int from[10];
	int distance[10];
	bool visited[10];
	int count, index = 0, u = 0, i, m = startVertex + 1;
	

	for (i = 0; i < vertList.size(); i++)
	{
		distance[i] = 10000;
		visited[i] = false;
		from[i] = -1;
	}
	
	distance[startVertex] = 0;

	for (count = 0; count < vertList.size() - 1; count++)
	{
		int min = 10000;

		for (i = 0; i < vertList.size(); i++)
		{
			if (!visited[i] && distance[i] <= min)
			{
				min = distance[i];
				index = i;
			}
		}

		u = index;
		visited[u] = true;

		for (i = 0; i < vertList.size(); i++)
		{
			if (!visited[i] && adjMatrix[u][i] && distance[u] != 10000 && distance[u] + adjMatrix[u][i] < distance[i])
			{
				from[i] = u;
				distance[i] = distance[u] + adjMatrix[u][i];
			}
		}
	}
	
	cout << "\nПуть из начальной вершины до остальных:\t\n";
	for (i = 0; i < vertList.size(); i++)
	{
		if (distance[i] != 10000)
		{
			cout << m << " => " << i + 1 << " = " << distance[i] << endl;
		}
	}
}



int main()
{
	setlocale(LC_ALL, "Russian");

	Graph<int> graph; // создание графа, содержащего вершины с номерами целого типа
	int amountVerts, amountEdges, vertex, sourceVertex, targetVertex, edgeWeight; // создание необходимых для ввода графа переменных 

	cout << "Введите количество вершин графа: ";
	cin >> amountVerts;		// ввод количества рёбер графа в переменную amountVerts
	cout << endl;

	cout << "Введите количество ребер графа: ";
	cin >> amountEdges;		// ввод количества рёбер графа в переменную amountEdges
	cout << endl;

	cout << "Номера вершин:" << endl;
	for (int i = 1; i <= amountVerts; ++i)
	{
		cout << "Вершина: " << i;
		
		graph.InsertVertex(i); //передаём ссылку на вершину в функцию InsertVertex; происходит вставка вершины в вектор вершин
		cout << endl;
	}
	cout << endl;

	cout << "Введите ребра графа" << endl << endl;
	for (int i = 0; i < amountEdges; ++i)
	{
		cout << "Исходная вершина: ";
		cin >> sourceVertex;		// ввод исходной вершины
		cout << endl;
		int* sourceVertPtr = &sourceVertex; // запоминаем адрес исходной вершины

		cout << "Конечная вершина: ";
		cin >> targetVertex;		// ввод вершины, до которой будет идти ребро от исходной вершины
		cout << endl;
		int* targetVertPtr = &targetVertex; // запоминаем адрес конечной вершины 

		cout << "Вес ребра: ";
		cin >> edgeWeight;			// ввод числового значения веса ребра в переменную edgeWeight
		cout << endl;
		graph.InsertEdge(*sourceVertPtr, *targetVertPtr, edgeWeight); // вставка ребра весом edgeWeight между исходной и конечной вершинами
		cout << endl;
	}
	cout << endl;

	graph.Print(); // печать матрицы смежности
	cout << endl;

	cout << "Введите какая вершина является начальной точкой (отсчет идет с 0)" << endl;
	cin >> vertex;
	int* VertPtr = &vertex;

	graph.Dijkstra(*VertPtr);
	cout << endl;
	return 0;
}
