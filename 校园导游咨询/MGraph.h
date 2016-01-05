/*
*
*  V0.2015112721	  ����FLoyd�㷨���������һ�Զ���֮������·��
*  v0.1.201511281207  ����Dijkstra�㷨����Դ���·��
*  v0.2.201512211915  �������㸽����Ϣ
*/
#include<iostream>
#include <malloc.h>
#include <conio.h>
using namespace std;

#define ERROR -1
/* ͼ���ڽӾ����ʾ�� */

#define MaxVertexNum 100        /* ��󶥵�����Ϊ100 */
#define INFINITY 99              /* ����Ϊ˫�ֽ��޷������������ֵ65535*/
typedef int Vertex;             /* �ö����±��ʾ����,Ϊ���� */
typedef int WeightType;         /* �ߵ�Ȩֵ��Ϊ���� */
typedef char DataType;          /* ����洢������������Ϊ�ַ��� */
bool  Visited[MaxVertexNum];

/* �ߵĶ��� */
typedef struct ENode *PtrToENode;
struct ENode{
	Vertex V1, V2;      /* �����<V1, V2> */
	WeightType Weight;  /* Ȩ�� */
};	
typedef PtrToENode Edge;
/* �����ͷ���Ķ��� */
typedef struct Vnode{
	int    No;                //������
	char  ScenicName[20];     //������
	char  Infor[100];         //������
} Scenics[MaxVertexNum], Scenic;

/* ͼ���Ķ��� */
typedef struct GNode *PtrToGNode;
struct GNode{
	int Nv;  /* ������ */
	int Ne;  /* ����   */
	WeightType G[MaxVertexNum][MaxVertexNum];  /* �ڽӾ��� */
	Scenics    Scenics[MaxVertexNum];          /* �涥������� */
	/* ע�⣺�ܶ�����£����������ݣ���ʱData[]���Բ��ó��� */
};
typedef PtrToGNode MGraph; /* ���ڽӾ���洢��ͼ���� */
MGraph Graph; /* ����ͼ */

void InsertEdge(MGraph Graph, Edge E)
{
	/* ����� <V1, V2> */
	Graph->G[E->V1-1][E->V2-1] = E->Weight;
	/* ��������ͼ����Ҫ�����<V2, V1> */
	Graph->G[E->V2-1][E->V1-1] = E->Weight;
}