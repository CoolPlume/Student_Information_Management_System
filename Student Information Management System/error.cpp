#include "error.h"

void initialization_failed(int error_code)
{
	using std::cerr, std::endl;
	cerr << "�����ʼ��ʧ�ܣ�" << endl;
	switch (error_code)
	{
	case Open_failed:
	{
		cerr << "�����룺" << error_code << " �����ļ���ʧ�ܣ�" << endl;
		break;
	}
	case Illegal_file:
	{
		cerr << "�����룺" << error_code << " ��⵽���Ķ��ı����ļ���" << endl;
	}
	}
	cerr << "������ֹ��" << endl;
	system("pause");
	exit(1);
}
