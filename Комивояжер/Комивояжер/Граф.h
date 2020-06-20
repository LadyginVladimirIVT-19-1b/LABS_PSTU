#pragma once
#include <glut.h>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <cmath>
using namespace std;

const int MaxSize = 10;                      // ћаксимальное число вершин
extern int Weight;							 // Ўирина окна
extern int Height;							 // ¬ысота окна


struct VertexCoord		                     //  оординат вершин
{
	int x, y;
};


class Graph
{
private:
	vector<int> vertList;					 // ¬ектор вершин
	int AdjMatrix[MaxSize][MaxSize];		 // ћатрица смежности
public:
	Graph();                                 //конструктор (обнул€ет все элементы матрицы)
	~Graph();                                //деструктор 
	bool IsEmpty();		                     //проверка на пустоту
	bool IsFull();		                     //проверка на заполненность графа

	int getVertValue(int i) { return vertList[i]; }									//получить значение вершины
	vector<int> getVertList() { return  vertList; }									//получить вектор вершин
	int getAdjMatrixElem(int i, int j) { return AdjMatrix[i][j]; }					//получить элемент матрицы смежности
	void SetZeroingElem(int i, int j) { AdjMatrix[i][j] = 0; AdjMatrix[j][i] = 0; } //обнуление элементов матрицы 
	int GetAmountVerts() { return vertList.size(); }								//получить количество вершин графа
	int GetVertPos(const int& vertex);												//получить позицию вершины в векторе вершин
	int GetAmountEdges();															//получить количество ребер графа


	void InsertVertex(const int& vertex);											//добавить вершину в конец
	void InsertEdge(const int& vertex1, const int& vertex2, int weigth);			//добавить ребро с весом между двух вершин
	void Print();																	//вывод матрицы смежности
	void PrintGraph();																//вывод графа в OpenGL
};


int** Make_Matrix();																//создаетс€ матрица с заменой нулевых ребер на -1
int* Min_Line(int* line, int n);													//минимальный элемент в строке
void Print_Matrix(int** matrix);													//вывод матрицы
int** Reduct_Matrix(int** matrix);													//редукци€ матрицы
int** Matrix_Change(int** matrix);													//изменение матрицы
void Result();																		//решение  оммиво€жера


// –исование элементов графа (OpenGL)


void drawButton1();																 //кнопоки
void drawButton2();
void drawButton3();
void drawButton4();


void makeGraph();                                                                //создание графа
void setCoords(int i, int n);                                                    //ставит координаты вершинам
void reshape(int w, int h);                                                      //масштаб окна
void display();                                                                  //изображение окна
void mouseMove(int x, int y);                                                    //движени€ мыши
void mouseClick(int button, int state, int x, int y);                            //нажатие мыши


void drawCircle(int x, int y, int R);											 //круга
void drawVertex(int n);															 //вершины
void drawCircleMouse(int x, int y, int R);										 //новый круг при наведении мыши
void drawEdge(int text, int x0, int y0, int x1, int y1);						 //ребра
void drawWeightEdge(int nom, int x1, int y1);                                    //веса ребра


bool Salesman(int** matrix);													 //проверка решени€ задачи
int Circle(int x, int y);														 //проверка наведени€ на вершину
void Button(int x, int y);														 //проверка наведени€ на кнопку

