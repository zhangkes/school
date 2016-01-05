  // 校园导游咨询.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"Functions.h"
void Manage()
{
	cout << "\t╔═════════════════╗" << endl;
	cout << "\t╠═══  校园导游咨询平台    ═══╣" << endl;
	cout << "\t╠═══    1--- 查询景点     ═══╣" << endl;
	cout << "\t╠═══    2--- 显示景点     ═══╣" << endl;
	cout << "\t╠═══    3--- 新增景点     ═══╣" << endl;
	cout << "\t╠═══    4--- 询问路径     ═══╣" << endl;
	cout << "\t╠═══    5--- 修改景点     ═══╣" << endl;
	cout << "\t╠═══    0--- 退出系统     ═══╣" << endl;
	cout << "\t╚═════════════════╝" << endl;

}
int _tmain(int argc, _TCHAR* argv[])
{
    Graph = (MGraph)malloc(sizeof(struct GNode)); /* 建立图 */
	InitGraph(Graph);
	int in;
	while (1){
		system("cls");
		Manage();
		cout << "请输入操作选项： ";  cin >> in;
		switch (in)
		{
		case 1: FindInfor(Graph); break;
		case 2: ShowAllInfor(Graph); break;
		case 3: AddScenic(Graph); break;	
		case 4: QueryShortPath(Graph); break;
		case 5: Modification(Graph); break;
		case 0: exit(0); break;
		default: cout << "\t输入错误，请重新输入。" << endl;
		}
		cout << endl;
		system("pause");
	}
	return 0;
}

