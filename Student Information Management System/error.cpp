#include "error.h"

void initialization_failed(int error_code)
{
	using std::cerr, std::endl;
	cerr << "�����ʼ��ʧ�ܣ�" << endl;
	switch (error_code)
	{
	case (int)error_code_Type::Open_failed:
	{
		cerr << "�����룺" << error_code << " �����ļ���ʧ�ܣ�" << endl;
		break;
	}
	case (int)error_code_Type::Illegal_file:
	{
		cerr << "�����룺" << error_code << " ��⵽���Ķ��ı����ļ���" << endl;
		break;
	}
	}
	cerr << "������ֹ��" << endl;
	system("pause");
	exit(1);
}

void save_failed(int error_code)
{
	using std::cerr, std::endl;
	cerr << "�������ݱ���ʧ�ܣ�" << endl;
	switch (error_code)
	{
	case (int)error_code_Type::Open_failed:
	{
		cerr << "�����룺" << error_code << " �����ļ���ʧ�ܣ�" << endl;
		break;
	}
	}
	cerr << "������ֹ��" << endl;
	system("pause");
	exit(1);
}
