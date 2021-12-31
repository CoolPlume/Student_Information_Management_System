#include "error.h"

void initialization_failed(int error_code)
{
	using std::cerr, std::endl;
	cerr << endl;
	cerr << "程序初始化失败！" << endl;
	switch (error_code)
	{
	case (int)error_code_Type::Open_failed:
	{
		cerr << "错误码：" << error_code << " 本地文件打开失败！" << endl;
		break;
	}
	case (int)error_code_Type::Illegal_file:
	{
		cerr << "错误码：" << error_code << " 侦测到被改动的本地文件！" << endl;
		break;
	}
	}
	cerr << "程序终止！" << endl;
	system("pause");
	exit(1);
}

void save_failed(int error_code)
{
	using std::cerr, std::endl;
	cerr << endl;
	cerr << "程序数据保存失败！" << endl;
	switch (error_code)
	{
	case (int)error_code_Type::Open_failed:
	{
		cerr << "错误码：" << error_code << " 本地文件打开失败！" << endl;
		break;
	}
	}
	cerr << "程序终止！" << endl;
	system("pause");
	exit(1);
}

void wrong_selection(int error_code, bool& flag)
{
	using std::cerr, std::endl;
	cerr << endl;
	cerr << "选择了错误的选项！" << endl;
	switch (error_code)
	{
	case (int)error_code_Type::Subscript_out_of_bounds:
	{
		cerr << "错误码：" << error_code << " 下标越界！" << endl;
		break;
	}
	}
	cerr << "请重新选择！" << endl;
	flag = true;
	system("pause");
}

void login_failed(int error_code, bool& flag)
{
	using std::cerr, std::endl;
	cerr << endl;
	cerr << "登陆失败！" << endl;
	switch (error_code)
	{
	case (int)error_code_Type::User_type_error:
	{
		cerr << "错误码：" << error_code << " 用户类型错误！" << endl;
		break;
	}
	case (int)error_code_Type::Wrong_user_name_or_password:
	{
		cerr << "错误码：" << error_code << " 用户名或密码错误！" << endl;
		break;
	}
	}
	cerr << "是否要重新输入（1：是；0：否）：";
	bool retry = false;
	std::cin >> retry;
	if (retry)
	{
		flag = true;
	}
	else
	{
		cerr << "程序终止！" << endl;
		system("pause");
		exit(1);
	}
}
