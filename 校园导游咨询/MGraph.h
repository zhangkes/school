/*
*
*  V0.2015112721	  新增FLoyd算法：求得任意一对顶点之间的最短路径
*  v0.1.201511281207  新增Dijkstra算法：单源最短路径
*  v0.2.201512211915  新增顶点附加信息
*/
#include<iostream>
#include <malloc.h>
#include <conio.h>
using namespace std;

#define ERROR -1
/* 图的邻接矩阵表示法 */

#define MaxVertexNum 100        /* 最大顶点数设为100 */
#define INFINITY 99              /* ∞设为双字节无符号整数的最大值65535*/
typedef int Vertex;             /* 用顶点下标表示顶点,为整型 */
typedef int WeightType;         /* 边的权值设为整型 */
typedef char DataType;          /* 顶点存储的数据类型设为字符型 */
bool  Visited[MaxVertexNum];

/* 边的定义 */
typedef struct ENode *PtrToENode;
struct ENode{
	Vertex V1, V2;      /* 有向边<V1, V2> */
	WeightType Weight;  /* 权重 */
};	
typedef PtrToENode Edge;
/* 顶点表头结点的定义 */
typedef struct Vnode{
	int    No;                //景点编号
	char  ScenicName[20];     //景点名
	char  Infor[100];         //景点简介
} Scenics[MaxVertexNum], Scenic;

/* 图结点的定义 */
typedef struct GNode *PtrToGNode;
struct GNode{
	int Nv;  /* 顶点数 */
	int Ne;  /* 边数   */
	WeightType G[MaxVertexNum][MaxVertexNum];  /* 邻接矩阵 */
	Scenics    Scenics[MaxVertexNum];          /* 存顶点的数据 */
	/* 注意：很多情况下，顶点无数据，此时Data[]可以不用出现 */
};
typedef PtrToGNode MGraph; /* 以邻接矩阵存储的图类型 */
MGraph Graph; /* 建立图 */

void InsertEdge(MGraph Graph, Edge E)
{
	/* 插入边 <V1, V2> */
	Graph->G[E->V1-1][E->V2-1] = E->Weight;
	/* 若是无向图，还要插入边<V2, V1> */
	Graph->G[E->V2-1][E->V1-1] = E->Weight;
}