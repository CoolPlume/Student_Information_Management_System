#include "error.h"

void initialization_failed(int error_code)
{
	using std::cerr, std::endl;
	cerr << endl;
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
	cerr << endl;
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

void wrong_selection(int error_code, bool& flag)
{
	using std::cerr, std::endl;
	cerr << endl;
	cerr << "ѡ���˴����ѡ�" << endl;
	switch (error_code)
	{
	case (int)error_code_Type::Subscript_out_of_bounds:
	{
		cerr << "�����룺" << error_code << " �±�Խ�磡" << endl;
		break;
	}
	}
	cerr << "������ѡ��" << endl;
	flag = true;
	system("pause");
}

void login_failed(int error_code, bool& flag)
{
	using std::cerr, std::endl;
	cerr << endl;
	cerr << "��½ʧ�ܣ�" << endl;
	switch (error_code)
	{
	case (int)error_code_Type::User_type_error:
	{
		cerr << "�����룺" << error_code << " �û����ʹ���" << endl;
		break;
	}
	case (int)error_code_Type::Wrong_user_name_or_password:
	{
		cerr << "�����룺" << error_code << " �û������������" << endl;
		break;
	}
	}
	cerr << "�Ƿ�Ҫ�������루1���ǣ�0���񣩣�";
	bool retry = false;
	std::cin >> retry;
	if (retry)
	{
		flag = true;
	}
	else
	{
		cerr << "������ֹ��" << endl;
		system("pause");
		exit(1);
	}
}
