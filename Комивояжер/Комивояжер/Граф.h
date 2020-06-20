#pragma once
#include <glut.h>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <cmath>
using namespace std;

const int MaxSize = 10;                      // ������������ ����� ������
extern int Weight;							 // ������ ����
extern int Height;							 // ������ ����


struct VertexCoord		                     // ��������� ������
{
	int x, y;
};


class Graph
{
private:
	vector<int> vertList;					 // ������ ������
	int AdjMatrix[MaxSize][MaxSize];		 // ������� ���������
public:
	Graph();                                 //����������� (�������� ��� �������� �������)
	~Graph();                                //���������� 
	bool IsEmpty();		                     //�������� �� �������
	bool IsFull();		                     //�������� �� ������������� �����

	int getVertValue(int i) { return vertList[i]; }									//�������� �������� �������
	vector<int> getVertList() { return  vertList; }									//�������� ������ ������
	int getAdjMatrixElem(int i, int j) { return AdjMatrix[i][j]; }					//�������� ������� ������� ���������
	void SetZeroingElem(int i, int j) { AdjMatrix[i][j] = 0; AdjMatrix[j][i] = 0; } //��������� ��������� ������� 
	int GetAmountVerts() { return vertList.size(); }								//�������� ���������� ������ �����
	int GetVertPos(const int& vertex);												//�������� ������� ������� � ������� ������
	int GetAmountEdges();															//�������� ���������� ����� �����


	void InsertVertex(const int& vertex);											//�������� ������� � �����
	void InsertEdge(const int& vertex1, const int& vertex2, int weigth);			//�������� ����� � ����� ����� ���� ������
	void Print();																	//����� ������� ���������
	void PrintGraph();																//����� ����� � OpenGL
};


int** Make_Matrix();																//��������� ������� � ������� ������� ����� �� -1
int* Min_Line(int* line, int n);													//����������� ������� � ������
void Print_Matrix(int** matrix);													//����� �������
int** Reduct_Matrix(int** matrix);													//�������� �������
int** Matrix_Change(int** matrix);													//��������� �������
void Result();																		//������� ������������


// ��������� ��������� ����� (OpenGL)


void drawButton1();																 //�������
void drawButton2();
void drawButton3();
void drawButton4();


void makeGraph();                                                                //�������� �����
void setCoords(int i, int n);                                                    //������ ���������� ��������
void reshape(int w, int h);                                                      //������� ����
void display();                                                                  //����������� ����
void mouseMove(int x, int y);                                                    //�������� ����
void mouseClick(int button, int state, int x, int y);                            //������� ����


void drawCircle(int x, int y, int R);											 //�����
void drawVertex(int n);															 //�������
void drawCircleMouse(int x, int y, int R);										 //����� ���� ��� ��������� ����
void drawEdge(int text, int x0, int y0, int x1, int y1);						 //�����
void drawWeightEdge(int nom, int x1, int y1);                                    //���� �����


bool Salesman(int** matrix);													 //�������� ������� ������
int Circle(int x, int y);														 //�������� ��������� �� �������
void Button(int x, int y);														 //�������� ��������� �� ������

