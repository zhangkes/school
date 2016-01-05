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
/*顶点信息*/
Scenic scenics[INITSENICNUM] = {
	{ 1, "国教楼", "位于学校最北端，1号教学楼" },
	{ 2, "北大坑", "北苑的小操场，内设露天篮球场。" },
	{ 3, "北苑餐厅", "三层建筑，电梯直达。" },
	{ 4, "体育馆", "学校地标性建筑！学生课余时间锻炼身体好地方。" },
	{ 5, "北苑操场", "黄金地段，紧邻校医院。" },
	{ 6, "绮湖", "平静的湖面，碧绿的荷叶是学习的最佳场所。" },
	{ 7, "弘德广场", "升国旗的地方，紧邻学校正门。" },
	{ 8, "图书馆", "学校最具代表性的建筑，学习之最佳选择的地方。" },
	{ 9, "紫薇广场", "学校举办娱乐活动的地方。" },
	{ 10, "滴水涌泉", "师恩难忘，滴水之恩必当涌泉相报！" }
};
void InitGraph(MGraph Graph)
{
	Vertex V, W;
	Graph->Nv = INITSENICNUM;	//顶点数 
	Graph->Ne = INITEDGENUM;	//边数
	for (V = 0; V < Graph->Nv; V++)
	{
		memcpy(Graph->Scenics[V], &scenics[V], sizeof(Scenic));	/*顶点信息*/
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
	cout << "\t请输入您要增加的景点数目: ";   cin >> m ;
	cout << "\t请输入您要增加的景点路径数: ";   cin >> n;
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
		cout << "请输入第"<<i+1<<"个景点信息：" << endl;
		cout << "景点名：";	 cin >> Graph->Scenics[i]->ScenicName;
		cout << "景点简介："; cin >> Graph->Scenics[i]->Infor;
		Graph->Scenics[i]->No = i+1;
	}
	ENode e;
	for (int i = Graph->Ne - n; i < Graph->Ne; i++)
	{
			cout << "请输入第" << i+1 << "条路径信息" << endl;
		    cout << "景点编号：";	cin >> e.V1;
			cout << "景点编号：";	cin >> e.V2;
			cout << "路径：";	cin >> e.Weight;
			InsertEdge(Graph, &e);
	}
}
void FindInfor(MGraph Graph)
{
	char key[10];
	int i = 1;
	cout << "请输入要查询景点的名称或编号："; cin >> key;
	for (int i = 0; i < Graph->Nv; i++)
	{
		if (strcmp(Graph->Scenics[i]->ScenicName, key) == 0 || (int)key[0]-48 == Graph->Scenics[i]->No)
		{
			cout << "   景点编号: " << Graph->Scenics[i]->No;
			cout << "   景点名称:" << Graph->Scenics[i]->ScenicName;
			cout << "   景点简介:" << Graph->Scenics[i]->Infor << endl;
			return;
		}
	}
	cout << "对不起，没有该景点信息！" << endl;
}
void ShowAllInfor(MGraph Graph)
{
	//printf("%-12s%-12s%s\n", "景点编号", "景点名称", "景点简介");
	for (int i = 0; i < Graph->Nv; ++i)
	{
		//printf("%-12d%-12s%s\n", Graph->Scenics[i]->No, Graph->Scenics[i]->ScenicName, Graph->Scenics[i]->Infor);
		cout << " 景点编号: " << Graph->Scenics[i]->No;
		cout << "\t   景点名称:" << Graph->Scenics[i]->ScenicName;
		cout << "\t   景点简介:" << Graph->Scenics[i]->Infor << endl;
	}

}
void Modification(MGraph Graph){
	ShowAllInfor(Graph);
	int key;
	cout << " 请输入修改的景点编号："; cin >> key;
	for (int i = 0; i < Graph->Nv; i++)
	{
		if (key == Graph->Scenics[i]->No)
		{
		loop:	cout << " 修改选项：1.景点名称  2.景点简介  3.退出修改" << endl;
			int flag; cin >> flag;
			switch (flag)
			{
			case 1:	{cout << "   景点名称:"; cin >> Graph->Scenics[i]->ScenicName;  goto loop; }	break;
			case 2:{	cout << "   景点简介:"; cin >> Graph->Scenics[i]->Infor;	goto loop; }   break;
			//case 3:	 cout << "   景点编号: "; cin >> Graph->Scenics[i]->No;	break;
			case 3:	{cout << "修改成功!" << endl; return;}break;
			default:{ cout << "无效输入！"; goto loop; } break;
			}
			break;
		}
	}
	cout << "没有查到要修改景点的信息" << endl;
}

Vertex FindMinDist(MGraph Graph, int dist[], int collected[])
{ /* 返回未被收录顶点中dist最小者 */
	Vertex MinV, V;
	int MinDist = INFINITY;

	for (V = 0; V<Graph->Nv; V++) {
		if (collected[V] == false && dist[V]<MinDist) {
			/* 若V未被收录，且dist[V]更小 */
			MinDist = dist[V]; /* 更新最小距离 */
			MinV = V; /* 更新对应顶点 */
		}
	}
	if (MinDist < INFINITY) /* 若找到最小dist */
		return MinV; /* 返回对应的顶点下标 */
	else return ERROR;  /* 若这样的顶点不存在，返回错误标记 */
}
bool ShortestPath_Dijkstra(MGraph Graph, int dist[], int path[], Vertex S)
{
	int collected[MaxVertexNum];
	Vertex V, W;

	/* 初始化：此处默认邻接矩阵中不存在的边用INFINITY表示 */
	for (V = 0; V<Graph->Nv; V++) {
		dist[V] = Graph->G[S][V];
		path[V] = -1;
		collected[V] = false;
	}
	/* 先将起点收入集合 */
	dist[S] = 0;
	collected[S] = true;

	while (1) {
		/* V = 未被收录顶点中dist最小者 */
		V = FindMinDist(Graph, dist, collected);
		if (V == ERROR) /* 若这样的V不存在 */
			break;      /* 算法结束 */
		collected[V] = true;  /* 收录V */
		for (W = 0; W<Graph->Nv; W++) /* 对图中的每个顶点W */
			/* 若W是V的邻接点并且未被收录 */
			if (collected[W] == false && Graph->G[V][W]<INFINITY) {
				if (Graph->G[V][W]<0) /* 若有负边 */
					return false; /* 不能正确解决，返回错误标记 */
				/* 若收录V使得dist[W]变小 */
				if (dist[V] + Graph->G[V][W] < dist[W]) {
					dist[W] = dist[V] + Graph->G[V][W]; /* 更新dist[W] */
					path[W] = V; /* 更新S到W的路径 */
				}
			}
	} /* while结束*/
	return true; /* 算法执行完毕，返回正确标记 */
}
/*打印任意两点的路径*/
void PrintPath(MGraph Graph,int dis[], Vertex path[], int begin, int end)
{
	/*省略边界检查*/
	int index;           /*当前路径下标*/
	int distance=dis[end];
	index = end;
	while (index >= 0)
	{
		distance += dis[index];
		cout << Graph->Scenics[index]->ScenicName << "->";   /*打印一个顶点*/
		index = path[index];
	}
	cout << Graph->Scenics[begin]->ScenicName << "->终点";
	cout << endl;
	cout << "总路程：" << distance << endl;
}
void QueryShortPath(MGraph Graph)
{
	ShowAllInfor(Graph);
	int dist[MaxVertexNum];
	int path[MaxVertexNum];
	int begin, end;
	loop: cout << "请输入你要查询的开始景点代号：";	cin >> begin;
	cout << "你要到达的景点代号："; cin >> end;
	if (begin - 1 <0 || begin - 1 > Graph->Nv||end - 1 < 0 || end - 1 > Graph->Nv)
	{
		cout << "输入景点代号有误，请重新输入！" << endl;
		goto loop;
	}
	ShortestPath_Dijkstra(Graph, dist, path, end - 1);
	PrintPath(Graph,dist, path, end - 1, begin - 1);
}