  // У԰������ѯ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"Functions.h"
void Manage()
{
	cout << "\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[" << endl;
	cout << "\t�d�T�T�T  У԰������ѯƽ̨    �T�T�T�g" << endl;
	cout << "\t�d�T�T�T    1--- ��ѯ����     �T�T�T�g" << endl;
	cout << "\t�d�T�T�T    2--- ��ʾ����     �T�T�T�g" << endl;
	cout << "\t�d�T�T�T    3--- ��������     �T�T�T�g" << endl;
	cout << "\t�d�T�T�T    4--- ѯ��·��     �T�T�T�g" << endl;
	cout << "\t�d�T�T�T    5--- �޸ľ���     �T�T�T�g" << endl;
	cout << "\t�d�T�T�T    0--- �˳�ϵͳ     �T�T�T�g" << endl;
	cout << "\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a" << endl;

}
int _tmain(int argc, _TCHAR* argv[])
{
    Graph = (MGraph)malloc(sizeof(struct GNode)); /* ����ͼ */
	InitGraph(Graph);
	int in;
	while (1){
		system("cls");
		Manage();
		cout << "���������ѡ� ";  cin >> in;
		switch (in)
		{
		case 1: FindInfor(Graph); break;
		case 2: ShowAllInfor(Graph); break;
		case 3: AddScenic(Graph); break;	
		case 4: QueryShortPath(Graph); break;
		case 5: Modification(Graph); break;
		case 0: exit(0); break;
		default: cout << "\t����������������롣" << endl;
		}
		cout << endl;
		system("pause");
	}
	return 0;
}

