#include <iostream>
#include "graph.h"
#define VERYBIGINT 1000000000

Graph::Graph() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = 0;
    vertexCount = 0;
}

void Graph::addVertex(int vnumber)
{
    vertexes[vertexCount] = vnumber;
    vertexCount++;
}

void Graph::addEdge(int v1, int v2, int weight)
{
    matrix[v1][v2] = weight;
    matrix[v2][v1] = weight;
}

void Graph::delVertex(int vnumber)
{

    for (int i = 0; i < SIZE; i++)
    {
        matrix[i][vnumber] = 0;
        matrix[vnumber][i] = 0;
    }

    int foundIndex = -1;
    for (int i = 0; i < vertexCount; i++)
    {
        if (vertexes[i] == vnumber)
            foundIndex = i;
    }
    vertexCount--;
    for (int i = foundIndex; i < vertexCount; i++)
    {
        vertexes[i] = vertexes[i + 1];
    }
}

void Graph::delEdge(int v1, int v2)
{
    matrix[v1][v2] = 0;
    matrix[v2][v1] = 0;
}

bool Graph::edgeExists(int v1, int v2)
{
    return matrix[v1][v2] > 0;
}

bool Graph::vertexExists(int v)
{
    for (int i = 0; i < vertexCount; i++)
        if (vertexes[i] == v)
            return true;
    return false;
}

void Graph::findThreeHandshakesFloyd()    // Поиск пар вершин с расстоянием между ними, не превышающим трёх единиц/рукопожатий. Метод Флойда из материалов Модуля13
{
    int weights[SIZE][SIZE];
    
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (i == j)
            {
                weights[i][j] = 0;
            }
            else {
                if (!edgeExists(i, j))
                {
                    weights[i][j] = VERYBIGINT;
                }
                else {
                    weights[i][j] = matrix[i][j]; 
                }
            }
        }
    }

    for (int k = 0; k < vertexCount; k++)
    {
        int ck = vertexes[k];
        for (int i = 0; i < vertexCount; i++)
        {
            if (i == k)
                continue;
            int ci = vertexes[i];
            for (int j = 0; j < vertexCount; j++)
            {
                if (j == k)
                    continue;
                int cj = vertexes[j];
                if (weights[ci][ck] + weights[ck][cj] < weights[ci][cj])
                {
                    weights[ci][cj] = weights[ci][ck] + weights[ck][cj];
                }
            }
        }
    }

    for (int i = 0; i < vertexCount; i++)
        for(int j = 0; j < vertexCount; j++)
    {
            if (weights[vertexes[i]][vertexes[j]] <= 3 && weights[vertexes[i]][vertexes[j]] != 0)

            std::cout << "V" << i << j << ": " << weights[vertexes[i]][vertexes[j]] << ", " << std::endl;
        
    }
}

