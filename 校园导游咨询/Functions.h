#include"MGraph.h"
#define INITSENICNUM 10
#define INITEDGENUM 12
ENode edges[INITEDGENUM] = {
	{ 1, 2, 3 },
	{ 1, 3, 6 },
	{ 3, 2, 2 },
	{ 7, 8, 1},
	{ 3, 4, 14},
	{ 3, 5, 13 },
	{ 4, 5, 2 },
	{ 4, 6, 5 },
	{ 4, 7, 8 },
	{ 4, 8, 6 },
	{ 8, 9, 5 },
	{ 9, 10, 10}
};					 
/*������Ϣ*/
Scenic scenics[INITSENICNUM] = {
	{ 1, "����¥", "λ��ѧУ��ˣ�1�Ž�ѧ¥" },
	{ 2, "�����", "��Է��С�ٳ�������¶�����򳡡�" },
	{ 3, "��Է����", "���㽨��������ֱ�" },
	{ 4, "������", "ѧУ�ر��Խ�����ѧ������ʱ���������õط���" },
	{ 5, "��Է�ٳ�", "�ƽ�ضΣ�����УҽԺ��" },
	{ 6, "粺�", "ƽ���ĺ��棬���̵ĺ�Ҷ��ѧϰ����ѳ�����" },
	{ 7, "��¹㳡", "������ĵط�������ѧУ���š�" },
	{ 8, "ͼ���", "ѧУ��ߴ����ԵĽ�����ѧϰ֮���ѡ��ĵط���" },
	{ 9, "��ޱ�㳡", "ѧУ�ٰ����ֻ�ĵط���" },
	{ 10, "��ˮӿȪ", "ʦ����������ˮ֮���ص�ӿȪ�౨��" }
};
void InitGraph(MGraph Graph)
{
	Vertex V, W;
	Graph->Nv = INITSENICNUM;	//������ 
	Graph->Ne = INITEDGENUM;	//����
	for (V = 0; V < Graph->Nv; V++)
	{
		memcpy(Graph->Scenics[V], &scenics[V], sizeof(Scenic));	/*������Ϣ*/
		for (W = 0; W < Graph->Nv; W++)
			Graph->G[V][W] = INFINITY;
	}

	for (int i = 0; i < Graph->Ne; i++)
	{
		InsertEdge(Graph, &edges[i]);
	}
}
void AddScenic(MGraph &Graph)
{
	int m, n;  Vertex V, W;
	cout << "\t��������Ҫ���ӵľ�����Ŀ: ";   cin >> m ;
	cout << "\t��������Ҫ���ӵľ���·����: ";   cin >> n;
	Graph->Nv += m;
	Graph->Ne += n;
	for (V = Graph->Nv - m; V < Graph->Nv; V++)
		for (W = 0; W < Graph->Nv; W++)
			 Graph->G[V][W] = INFINITY;
	for (V = 0; V < Graph->Nv - m; V++)
		for (W = Graph->Nv - m; W < Graph->Nv; W++)
			Graph->G[V][W] = INFINITY;
	
	for (int i = Graph->Nv-m; i < Graph->Nv; i++)
	{
		cout << "�������"<<i+1<<"��������Ϣ��" << endl;
		cout << "��������";	 cin >> Graph->Scenics[i]->ScenicName;
		cout << "�����飺"; cin >> Graph->Scenics[i]->Infor;
		Graph->Scenics[i]->No = i+1;
	}
	ENode e;
	for (int i = Graph->Ne - n; i < Graph->Ne; i++)
	{
			cout << "�������" << i+1 << "��·����Ϣ" << endl;
		    cout << "�����ţ�";	cin >> e.V1;
			cout << "�����ţ�";	cin >> e.V2;
			cout << "·����";	cin >> e.Weight;
			InsertEdge(Graph, &e);
	}
}
void FindInfor(MGraph Graph)
{
	char key[10];
	int i = 1;
	cout << "������Ҫ��ѯ��������ƻ��ţ�"; cin >> key;
	for (int i = 0; i < Graph->Nv; i++)
	{
		if (strcmp(Graph->Scenics[i]->ScenicName, key) == 0 || (int)key[0]-48 == Graph->Scenics[i]->No)
		{
			cout << "   ������: " << Graph->Scenics[i]->No;
			cout << "   ��������:" << Graph->Scenics[i]->ScenicName;
			cout << "   ������:" << Graph->Scenics[i]->Infor << endl;
			return;
		}
	}
	cout << "�Բ���û�иþ�����Ϣ��" << endl;
}
void ShowAllInfor(MGraph Graph)
{
	//printf("%-12s%-12s%s\n", "������", "��������", "������");
	for (int i = 0; i < Graph->Nv; ++i)
	{
		//printf("%-12d%-12s%s\n", Graph->Scenics[i]->No, Graph->Scenics[i]->ScenicName, Graph->Scenics[i]->Infor);
		cout << " ������: " << Graph->Scenics[i]->No;
		cout << "\t   ��������:" << Graph->Scenics[i]->ScenicName;
		cout << "\t   ������:" << Graph->Scenics[i]->Infor << endl;
	}

}
void Modification(MGraph Graph){
	ShowAllInfor(Graph);
	int key;
	cout << " �������޸ĵľ����ţ�"; cin >> key;
	for (int i = 0; i < Graph->Nv; i++)
	{
		if (key == Graph->Scenics[i]->No)
		{
		loop:	cout << " �޸�ѡ�1.��������  2.������  3.�˳��޸�" << endl;
			int flag; cin >> flag;
			switch (flag)
			{
			case 1:	{cout << "   ��������:"; cin >> Graph->Scenics[i]->ScenicName;  goto loop; }	break;
			case 2:{	cout << "   ������:"; cin >> Graph->Scenics[i]->Infor;	goto loop; }   break;
			//case 3:	 cout << "   ������: "; cin >> Graph->Scenics[i]->No;	break;
			case 3:	{cout << "�޸ĳɹ�!" << endl; return;}break;
			default:{ cout << "��Ч���룡"; goto loop; } break;
			}
			break;
		}
	}
	cout << "û�в鵽Ҫ�޸ľ������Ϣ" << endl;
}

Vertex FindMinDist(MGraph Graph, int dist[], int collected[])
{ /* ����δ����¼������dist��С�� */
	Vertex MinV, V;
	int MinDist = INFINITY;

	for (V = 0; V<Graph->Nv; V++) {
		if (collected[V] == false && dist[V]<MinDist) {
			/* ��Vδ����¼����dist[V]��С */
			MinDist = dist[V]; /* ������С���� */
			MinV = V; /* ���¶�Ӧ���� */
		}
	}
	if (MinDist < INFINITY) /* ���ҵ���Сdist */
		return MinV; /* ���ض�Ӧ�Ķ����±� */
	else return ERROR;  /* �������Ķ��㲻���ڣ����ش����� */
}
bool ShortestPath_Dijkstra(MGraph Graph, int dist[], int path[], Vertex S)
{
	int collected[MaxVertexNum];
	Vertex V, W;

	/* ��ʼ�����˴�Ĭ���ڽӾ����в����ڵı���INFINITY��ʾ */
	for (V = 0; V<Graph->Nv; V++) {
		dist[V] = Graph->G[S][V];
		path[V] = -1;
		collected[V] = false;
	}
	/* �Ƚ�������뼯�� */
	dist[S] = 0;
	collected[S] = true;

	while (1) {
		/* V = δ����¼������dist��С�� */
		V = FindMinDist(Graph, dist, collected);
		if (V == ERROR) /* ��������V������ */
			break;      /* �㷨���� */
		collected[V] = true;  /* ��¼V */
		for (W = 0; W<Graph->Nv; W++) /* ��ͼ�е�ÿ������W */
			/* ��W��V���ڽӵ㲢��δ����¼ */
			if (collected[W] == false && Graph->G[V][W]<INFINITY) {
				if (Graph->G[V][W]<0) /* ���и��� */
					return false; /* ������ȷ��������ش����� */
				/* ����¼Vʹ��dist[W]��С */
				if (dist[V] + Graph->G[V][W] < dist[W]) {
					dist[W] = dist[V] + Graph->G[V][W]; /* ����dist[W] */
					path[W] = V; /* ����S��W��·�� */
				}
			}
	} /* while����*/
	return true; /* �㷨ִ����ϣ�������ȷ��� */
}
/*��ӡ���������·��*/
void PrintPath(MGraph Graph,int dis[], Vertex path[], int begin, int end)
{
	/*ʡ�Ա߽���*/
	int index;           /*��ǰ·���±�*/
	int distance=dis[end];
	index = end;
	while (index >= 0)
	{
		distance += dis[index];
		cout << Graph->Scenics[index]->ScenicName << "->";   /*��ӡһ������*/
		index = path[index];
	}
	cout << Graph->Scenics[begin]->ScenicName << "->�յ�";
	cout << endl;
	cout << "��·�̣�" << distance << endl;
}
void QueryShortPath(MGraph Graph)
{
	ShowAllInfor(Graph);
	int dist[MaxVertexNum];
	int path[MaxVertexNum];
	int begin, end;
	loop: cout << "��������Ҫ��ѯ�Ŀ�ʼ������ţ�";	cin >> begin;
	cout << "��Ҫ����ľ�����ţ�"; cin >> end;
	if (begin - 1 <0 || begin - 1 > Graph->Nv||end - 1 < 0 || end - 1 > Graph->Nv)
	{
		cout << "���뾰������������������룡" << endl;
		goto loop;
	}
	ShortestPath_Dijkstra(Graph, dist, path, end - 1);
	PrintPath(Graph,dist, path, end - 1, begin - 1);
}