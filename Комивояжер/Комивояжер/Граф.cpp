#include "Граф.h"
using namespace std;
int Weight = 1080;
int Height = 720;

bool* Mouse_Movement = new bool[MaxSize]; //массив меток (отвечает за движение мыши)
bool Graph_View = false;		          //отвечает за перестроение графа в стандартный вид 
bool Vert_Move = false;					  //отвечает за перемещение вершин 

vector<pair<int, int>> Road;			  //ребро
vector<int> NewRoad;
int R;

int Moving_Vertex;						  //перемещаемая вершина
int Cursor_X;							  //позиция курсора по Х
int Cursor_Y;							  //позиция курсора по У

VertexCoord vertCoord[MaxSize + 1];		  //массив структур (координаты вершин)
Graph graph;
int Button_Flag;
extern Graph graph;						  //создается объект класса Graph



Graph::Graph()					//обнуляет все элементы матрицы
{
	for (int i = 0; i < MaxSize; i++)
	{
		for (int j = 0; j < MaxSize; j++)
		{
			AdjMatrix[i][j] = 0;
		}
		Mouse_Movement[i] = false;
	}
}

Graph::~Graph()
{ }

int Graph::GetVertPos(const int& vertex)				//получить позицию вершины в векторе вершин
{
	for (int i = 0; i < vertList.size(); i++)
	{
		if (vertList[i] == vertex)
		{
			return i;
		}
	}
	return -1;
}

bool Graph::IsEmpty()			//проверка на пустоту
{
	if (vertList.size() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Graph::IsFull()										//проверка на заполненность
{
	return (vertList.size() == MaxSize);
}

void Graph::InsertVertex(const int& vertex)					//добавить вершину в конец
{
	if (!IsFull())
	{
		vertList.push_back(vertex);
	}
	else
	{
		cout << "Граф заполнен. Добавить вершину не возможно" << endl;
		return;
	}
}

void Graph::InsertEdge(const int& vertex1, const int& vertex2, int weight)			//добавить ребро с весом между двух вершин
{
	if (weight < 1)																	//корректность ввода веса
	{
		cout << endl;
		cout << "Неправильный ввод веса" << endl;
		return;
	}

	if ((GetVertPos(vertex1) != -1) && (GetVertPos(vertex2) != -1))					//проверка существования вершин
	{
		int Pos1 = GetVertPos(vertex1);												//находим позиции вершин
		int Pos2 = GetVertPos(vertex2);
		if (AdjMatrix[Pos1][Pos2] != 0 && AdjMatrix[Pos2][Pos1] != 0)				//проверка существования ребра
		{
			cout << "Между вершинами уже существует ребро" << endl;
			return;
		}
		else																		
		{
			AdjMatrix[Pos1][Pos2] = weight;
		}
	}
	else
	{
		cout << "Какой-то вершины нет в графе" << endl;
		return;
	}
}


void Graph::Print()							//вывод матрицы смежности
{
	if (!IsEmpty())
	{
		cout << "Матрица смежности графа:" << endl;
		for (int i = 0; i < vertList.size(); i++)
		{
			cout << vertList[i];
			for (int j = 0; j < vertList.size(); j++)
			{
				cout << "\t" << AdjMatrix[i][j];
			}
			cout << endl;
		}
	}
	else
	{
		cout << "Граф пустой" << endl;
	}
	cout << endl << endl;
}



int Graph::GetAmountEdges()						//получить количество ребер графа
{
	int edges = 0;
	for (int i = 0; i < vertList.size(); i++)
	{
		for (int j = 0; j < vertList.size(); j++)
		{
			if (AdjMatrix[i][j] > 0)
			{
				edges++;
			}
		}
	}
	return edges;
}

void Graph::PrintGraph()				//вывод графа в OpenGL
{
	int n = graph.GetAmountVerts();
	for (int i = 0; i < n; i++)
	{
		if (!Graph_View)
		{
			setCoords(i, n);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int vert = AdjMatrix[i][j];
			if (vert != 0)
			{
				drawEdge(vert, vertCoord[i].x, vertCoord[i].y, vertCoord[j].x, vertCoord[j].y);
			}
			if (vert == AdjMatrix[j][i] && vert != 0)
			{
				drawEdge(vert, vertCoord[j].x, vertCoord[j].y, vertCoord[i].x, vertCoord[i].y);
			}
		}
	}
	drawVertex(n);
	glutPostRedisplay();
}

int** Make_Matrix()							//создается матрица с заменой нулевых ребер на -1
{
	int n = graph.GetAmountVerts();
	int** matr = new int* [n];

	for (int i = 0; i < n; i++)
	{
		matr[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int elem = graph.getAdjMatrixElem(i, j);
			if (elem == 0 or i == j)
			{
				matr[i][j] = -1;
			}
			else
			{
				matr[i][j] = elem;
			}
		}
	}

	cout << endl << "Начальная матрица:" << endl;
	Print_Matrix(matr);
	cout << endl << endl;
	return matr;
}

int* Min_Line(int* line, int n)					//минимальный элемент в строке
{
	int min = 100000;
	for (int i = 0; i < n; i++)
	{
		if (line[i] >= 0 && line[i] < min)
		{
			min = line[i];
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (line[i] >= 0)
		{
			line[i] = line[i] - min;
		}
	}
	return line;
}



void Print_Matrix(int** matrix)					//вывод матрицы
{
	int n = graph.GetAmountVerts();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

int** Reduct_Matrix(int** matrix)				//редукция матрицы
{
	int** matr = matrix;
	int n = graph.GetAmountVerts();
	int min = 100000;

	for (int i = 0; i < n; i++)
	{
		matr[i] = Min_Line(matr[i], n);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matr[j][i] >= 0 && matr[j][i] < min)
			{
				min = matr[j][i];
			}
		}
		for (int j = 0; j < n; j++)
		{
			if (matr[j][i] >= 0)
			{
				matr[j][i] = matr[j][i] - min;
			}
		}
	}
	
	cout << endl << "Редуцированная матрица:" << endl;
	Print_Matrix(matr);
	return matrix;
}

int** Matrix_Change(int** matrix)				//изменение матрицы
{		
	int n = graph.GetAmountVerts();
	int** matr = Reduct_Matrix(matrix);
	int max = -100000;
	int line, column;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matr[i][j] == 0)
			{
				int minLine = 100000;
				int minColumn = 100000;
				for (int k = 0; k < n; k++)
				{
					if (matr[i][k] != -1 && k != j && matr[i][k] < minLine)
					{
						minLine = matr[i][k];
					}
				}
				for (int k = 0; k < n; k++)
				{
					if (matr[k][j] != -1 && k != i && matr[k][j] < minColumn)
					{
						minColumn = matr[k][j];
					}
				}
				if (max < minColumn + minLine)
				{
					max = minColumn + minLine;
					line = i;
					column = j;
				}
			}
		}
	}

	pair<int, int> tmp;
	tmp.first = line + 1;
	tmp.second = column + 1;
	Road.push_back(tmp);

	matr[line][column] = -1;
	matr[column][line] = -1;

	for (int i = 0; i < n; i++)
	{
		matr[line][i] = -1;
		matr[i][column] = -1;
	}
	cout << endl;

	cout << "Матрица после вычисления оценок нулевых клеток: \n";
	Print_Matrix(matr);

	cout << endl << "Найдены промежуточные отрезки путей:   ";
	for (int i = 0; i < Road.size(); i++)
	{
		cout << Road[i].first << " -> " << Road[i].second << " ";
	}
	cout << endl;

	return matr;
}

void Result()								//решение Коммивояжера
{
	int second = Road[0].second;
	int i = 2;
	NewRoad.push_back(Road[0].first);
	NewRoad.push_back(Road[0].second);

	while (i != graph.GetAmountVerts() + 1)
	{
		for (int j = 1; j < graph.GetAmountVerts(); j++)
		{
			if (Road[j].first == second)
			{
				second = Road[j].second;
				NewRoad.push_back(second);
				i++;
			}
		}
	}
	cout << endl;

	cout << "Кратчайший путь, проходя через все вершины равен:   ";
	for (int i = 0; i < NewRoad.size(); i++)
	{
		cout << NewRoad[i];
		if (i != NewRoad.size() - 1)
		{
			cout << " -> ";
		}
	}

	int sum = 0;
	for (int i = 0; i < Road.size(); i++)
	{
		int line = Road[i].first - 1;
		int column = Road[i].second - 1;
		sum = sum + graph.getAdjMatrixElem(line, column);
	}
	cout << endl << "S = " << sum << endl;;
}


void drawButton1()								//кнопока создания нового графа
{
	if (Button_Flag == 1)
	{
		glColor3f(0.0, 1, 1);
	}
	else
	{
		glColor3f(1, 1, 0.0);
	}

	glBegin(GL_QUADS);
	glVertex2i(50, Height - 20);
	glVertex2i(50, Height - Height / 7);
	glVertex2i(Weight / 7, Height - Height / 7);
	glVertex2i(Weight / 7, Height - 20);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2i(50, Height - 20);
	glVertex2i(50, Height - Height / 7);
	glVertex2i(Weight / 7, Height - Height / 7);
	glVertex2i(Weight / 7, Height - 20);
	glEnd();

	string name = "Create a new graph";
	glRasterPos2i(Weight / 20, 0.91 * Height);

	for (int i = 0; i < name.length(); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, name[i]);
	}
}

void drawButton2()								//кнопока нахождения кратчайшего пути (задача Комивояжера)
{
	if (Button_Flag == 2)
	{
		glColor3f(0.0, 1, 1);
	}
	else
	{
		glColor3f(1, 1, 0.0);
	}

	glBegin(GL_QUADS);
	glVertex2i(50, Height - Height / 7 - 20);
	glVertex2i(50, Height - 2 * (Height / 7));
	glVertex2i(Weight / 7, Height - 2 * (Height / 7));
	glVertex2i(Weight / 7, Height - Height / 7 - 20);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2i(50, Height - Height / 7 - 20);
	glVertex2i(50, Height - 2 * (Height / 7));
	glVertex2i(Weight / 7, Height - 2 * (Height / 7));
	glVertex2i(Weight / 7, Height - Height / 7 - 20);
	glEnd();

	string name = "Find shortest way";
	glRasterPos2i(Weight / 18, 0.77 * Height);

	for (int i = 0; i < name.length(); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, name[i]);
	}
}

void drawButton3()						//кнопока вывода матрицы смежности
{
	if (Button_Flag == 3)
	{
		glColor3f(0.0, 1, 1);
	}
	else
	{
		glColor3f(1, 1, 0.0);
	}

	glBegin(GL_QUADS);
	glVertex2i(50, Height - 2 * (Height / 7) - 20);
	glVertex2i(50, Height - 3 * (Height / 7));
	glVertex2i(Weight / 7, Height - 3 * (Height / 7));
	glVertex2i(Weight / 7, Height - 2 * (Height / 7) - 20);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2i(50, Height - 2 * (Height / 7) - 20);
	glVertex2i(50, Height - 3 * (Height / 7));
	glVertex2i(Weight / 7, Height - 3 * (Height / 7));
	glVertex2i(Weight / 7, Height - 2 * (Height / 7) - 20);
	glEnd();

	string name = "Adjacency matrix";
	glRasterPos2i(Weight / 17, 0.63 * Height);

	for (int i = 0; i < name.length(); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, name[i]);
	}
	glRasterPos2i(Weight / 16, (0.63 * Height) - 15);	
}

void drawButton4()							//кнопока удаления всего графа
{
	if (Button_Flag == 4)
	{
		glColor3f(0.0, 1, 1);
	}
	else
	{
		glColor3f(1, 1, 0.0);
	}

	glBegin(GL_QUADS);
	glVertex2i(50, Height - 3 * (Height / 7) - 20);
	glVertex2i(50, Height - 4 * (Height / 7));
	glVertex2i(Weight / 7, Height - 4 * (Height / 7));
	glVertex2i(Weight / 7, Height - 3 * (Height / 7) - 20);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2i(50, Height - 3 * (Height / 7) - 20);
	glVertex2i(50, Height - 4 * (Height / 7));
	glVertex2i(Weight / 7, Height - 4 * (Height / 7));
	glVertex2i(Weight / 7, Height - 3 * (Height / 7) - 20);
	glEnd();

	string name = "Delete whole graph";
	glRasterPos2i(Weight / 18.5, 0.49 * Height);

	for (int i = 0; i < name.length(); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, name[i]);
	}


}


void drawCircle(int x, int y, int R)				//рисует круга
{	
	float x1, y1, x2, y2;

	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);

	for (int i = 0; i < 360; i++)
	{
		float alpha = 2.0f * 3.1415926f * float(i) / float(360);
		y1 = R * cos(alpha) + y;
		x1 = R * sin(alpha) + x;;
		glVertex2f(x1, y1);
	}
	glEnd();

	glColor3f(0.0f, 0.0f, 1.0f);	
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; i++)
	{
		float alpha = 2.0f * 3.1415926f * float(i) / float(360);
		y2 = R * cos(alpha) + y;
		x2 = R * sin(alpha) + x;
		glVertex2f(x2, y2);
	}
	glEnd();
}

void drawCircleMouse(int x, int y, int R)					// рисует новый круг при наведении мыши
{
	float x1, y1, x2, y2;

	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		float alpha = 2.0f * 3.1415926f * float(i) / float(360);
		y1 = R * cos(alpha) + y;
		x1 = R * sin(alpha) + x;;
		glVertex2f(x1, y1);
	}
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; i++)
	{
		float alpha = 2.0f * 3.1415926f * float(i) / float(360);
		y2 = R * cos(alpha) + y;
		x2 = R * sin(alpha) + x;
		glVertex2f(x2, y2);
	}
	glEnd();
}

void drawWeightEdge(int text, int x1, int y1)				//рисует веса ребра
{
	glColor3f(0.0, 0.0, 0.0);
	GLvoid* font = GLUT_BITMAP_HELVETICA_18;
	string s = to_string(text);
	glRasterPos2i(x1 - 5, y1 - 5);

	for (size_t j = 0; j < s.length(); j++)
	{
		glutBitmapCharacter(font, s[j]);
	}
}

void drawEdge(int text, int x0, int y0, int x1, int y1)			//рисует ребро ориентированного взвешенного графа
{
	glColor3i(1, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(x0, y0);
	glVertex2i(x1, y1);
	glEnd();
	drawWeightEdge(text, (x0 + x1) / 2 + 10, (y0 + y1) / 2 + 10);

	float Vert_x = x0 - x1;
	float Vert_y = y0 - y1;
	float s = 1.0f / sqrt(Vert_x * Vert_x + Vert_y * Vert_y);
	Vert_x = Vert_x * s;
	Vert_y = Vert_y * s;
	x1 = x1 + R * Vert_x;
	y1 = y1 + R * Vert_y;

	glColor3i(0, 0, 1);
	glBegin(GL_TRIANGLES);
	glVertex2f(x1, y1);
	glVertex2f(x1 + 10 * (Vert_x + Vert_y), y1 + 10 * (Vert_y - Vert_x));
	glVertex2f(x1 + 10 * (Vert_x - Vert_y), y1 + 10 * (Vert_y + Vert_x));
	glEnd();
}

void drawVertex(int n)										//рисует вершины
{
	for (int i = 0; i < n; i++)
	{
		if (Mouse_Movement[i])
		{
			drawCircleMouse(vertCoord[i].x, vertCoord[i].y, R);
		}
		else
		{
			drawCircle(vertCoord[i].x, vertCoord[i].y, R);
		}
		drawWeightEdge(i + 1, vertCoord[i].x, vertCoord[i].y);
	}

}

void setCoords(int i, int n)							//ставит координаты вершинам
{
	int R1;
	int x0 = Weight / 2;
	int y0 = Height / 2;

	if (Weight > Height)
	{
		R = 5 * (Height / 13) / n;
		R1 = Height / 2 - R - 10;
	}
	else
	{
		R = 5 * (Weight / 13) / n;
		R1 = Weight / 2 - R - 10;
	}

	float alpha = 2.0f * 3.1415926f * i / n;
	int y1 = R1 * cos(alpha) + y0;
	int x1 = R1 * sin(alpha) + x0;
	vertCoord[i].x = x1;
	vertCoord[i].y = y1;
}

void makeGraph()								//создание графа
{
	Graph_View = false;
	int amountVerts, amountEdges, sourceVertex, targetVertex, edgeWeight;

	cout << "Введите количество вершин графа: ";
	cin >> amountVerts;
	cout << "Введите количество ребер графа: "; 
	cin >> amountEdges;

	for (int i = 1; i <= amountVerts; i++) {

		graph.InsertVertex(i);
	}

	for (int i = 0; i < amountEdges; i++)
	{
		cout << "Исходная вершина: ";
		cin >> sourceVertex;
		cout << "Конечная вершина: "; 
		cin >> targetVertex;
		cout << "Вес ребра: "; 
		cin >> edgeWeight;
		graph.InsertEdge(sourceVertex, targetVertex, edgeWeight);
	}
	cout << endl;
	graph.Print();
}

bool Salesman(int** matrix)								//проверяет возможно ли решить задачу Комивояжер
{
	if (graph.IsEmpty())
	{
		return false;
	}
	for (int i = 0; i < graph.GetAmountVerts(); i++)
	{
		int tmp = 0;
		for (int j = 0; j < graph.GetAmountVerts(); j++)
		{
			if (matrix[i][j] > 0)
			{
				tmp++;
			}
		}
		if (tmp < 1)
		{
			return false;
		}
	}
	return true;
}

int Circle(int x, int y)					//проверка наведения на вершину мышкой
{
	for (int i = 0; i < graph.GetAmountVerts(); i++)
	{
		if (pow(x - vertCoord[i].x, 2) + pow(y - vertCoord[i].y, 2) <= pow(R, 2))
		{
			return i;
		}
	}
	return -1;
}

void Button(int x, int y)						//проверка наведения на кнопку мышкой
{
	if (x > 50 && x < Weight / 7 && y < (Height - 20) && y >(Height - Height / 7))
	{
		Button_Flag = 1;
	}
	else if (x > 50 && x < Weight / 7 && y < (Height - Height / 7 - 20) && y > Height - 2 * (Height / 7))
	{
		Button_Flag = 2;
	}
	else if (x > 50 && x < Weight / 7 && y < Height - 2 * (Height / 7) - 20 && y > Height - 3 * (Height / 7))
	{
		Button_Flag = 3;
	}
	else if (x > 50 && x < Weight / 7 && y > Height - 4 * (Height / 7) && y < Height - 3 * (Height / 7) - 20)
	{
		Button_Flag = 4;
	}
	else
	{
		Button_Flag = 0;
	}
}

void mouseMove(int x, int y)					//отвечает за движение мыши
{
	y = Height - y;
	Cursor_X = x;
	Cursor_Y = y;
	int i = Circle(x, y);

	if (i != -1)
	{
		Mouse_Movement[i] = true;
	}
	else
	{
		for (int j = 0; j < graph.GetAmountVerts(); j++)
		{
			Mouse_Movement[j] = false;
		}
	}

	if (Vert_Move)
	{
		vertCoord[Moving_Vertex].x = Cursor_X;
		vertCoord[Moving_Vertex].y = Cursor_Y;
	}
	Button(x, y);
	glutPostRedisplay();
}


void reshape(int w, int h)				//отвечает за масштаб окна
{
	Weight = w;
	Height = h;
	glViewport(0, 0, (GLsizei)Weight, (GLsizei)Height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, (GLdouble)Weight, 0, (GLdouble)Height);
	glutPostRedisplay();
}

void display()							//отвечает за изображение окна
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, Weight, 0, Height);
	glViewport(0, 0, Weight, Height);
	glClearColor(0.9, 0.7, 0.5, 0.5);
	glClear(GL_COLOR_BUFFER_BIT);
	drawButton1();
	drawButton2();
	drawButton3();
	drawButton4();
	graph.PrintGraph();
	glutSwapBuffers();
}


void mouseClick(int button, int state, int x, int y)			//отвечает за нажатие мыши
{
	int j = Circle(x, Height - y);

	if (button == 3 || button == 4)
	{
		Graph_View = true;
		if (button == 3)
		{
			if (R != 300)
				R++;
		}
		else if (button == 4)
		{
			if (R != 15)
				R--;
		}
	}

	if (x >= 50 and x <= (Weight / 7) and y >= 20 and y <= (Height / 7))
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			NewRoad.clear();
			Road.clear();
			Graph New;
			graph = New;
			makeGraph();
			return;

		}
		if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		{
			Graph_View = false;
			return;
		}
	}
	if (x >= 50 and x <= (Weight / 7) and y >= ((Height / 7) + 20) and y <= 2 * (Height / 7))
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			NewRoad.clear();
			Road.clear();
			cout << "\nЗадача Коммивояжера:\n";

			int** matrix = Make_Matrix();
			bool checker = Salesman(matrix);

			if (!checker)
			{
				cout << "\nЗадача Коммивояжера для данного графа некорректна\n\n";
				return;
			}

			int n = graph.GetAmountVerts();
			while (Road.size() < n)
			{
				matrix = Matrix_Change(matrix);
			}
			cout << endl;
			Result();
			return;
		}
	}
	if (x >= 50 and x <= (Weight / 7) and y >= (2 * (Height / 7) + 20) and y <= 3 * (Height / 7))
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			graph.Print();
			return;
		}
	}
	if (x >= 50 && x <= Weight / 7 && y <= 4 * (Height / 7) && y >= 3 * (Height / 7) + 20)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			system("cls");
		}

	}
}
