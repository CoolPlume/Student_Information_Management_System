#include "error.h"

[[noreturn]] void initialization_failed(int error_code)
{
	using std::cerr, std::endl;
	cerr << endl;
	cerr << "程序初始化失败！" << endl;
	switch (error_code)
	{
	case static_cast<int>(error_code_Type::Open_failed):
	{
		cerr << "错误码：" << error_code << " 本地文件打开失败！" << endl;
		break;
	}
	case static_cast<int>(error_code_Type::Illegal_file):
	{
		cerr << "错误码：" << error_code << " 侦测到被改动的本地文件！" << endl;
		break;
	}
	}
	cerr << "程序终止！" << endl;
	system("pause");
	exit(1);
}

[[noreturn]] void save_failed(int error_code)
{
	using std::cerr, std::endl;
	cerr << endl;
	cerr << "程序数据保存失败！" << endl;
	switch (error_code)
	{
	case static_cast<int>(error_code_Type::Open_failed):
	{
		cerr << "错误码：" << error_code << " 本地文件打开失败！" << endl;
		break;
	}
	}
	cerr << "程序终止！" << endl;
	system("pause");
	exit(1);
}

[[noreturn]] void wrong_selection(int error_code, bool& flag)
{
	using std::cerr, std::endl;
	cerr << endl;
	cerr << "选择了错误的选项！" << endl;
	switch (error_code)
	{
	case static_cast<int>(error_code_Type::Subscript_out_of_bounds):
	{
		cerr << "错误码：" << error_code << " 下标越界！" << endl;
		break;
	}
	}
	cerr << "请重新选择！" << endl;
	flag = true;
	system("pause");
}

[[noreturn]] void login_failed(int error_code, bool& flag)
{
	using std::cerr, std::endl;
	cerr << endl;
	cerr << "登陆失败！" << endl;
	switch (error_code)
	{
	case static_cast<int>(error_code_Type::User_type_error):
	{
		cerr << "错误码：" << error_code << " 用户类型错误！" << endl;
		break;
	}
	case static_cast<int>(error_code_Type::Wrong_user_name_or_password):
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

bool add_information_failed(int error_code, bool& flag)
{
	using std::cerr, std::endl;
	cerr << endl;
	cerr << "添加失败！" << endl;
	switch (error_code)
	{
	case static_cast<int>(error_code_Type::The_two_passwords_are_inconsistent):
	{
		cerr << "错误码：" << error_code << " 两次密码不一致！" << endl;
		break;
	}
	case static_cast<int>(error_code_Type::Incorrect_username_format):
	{
		cerr << "错误码：" << error_code << " 用户名格式错误！" << endl;
		break;
	}
	}
	cerr << "是否要重新输入（1：是；0：否）：";
	bool retry = false;
	std::cin >> retry;// BUG : 输入其他数字将引发bug
	if (retry)
	{
		flag = true;
	}
	else
	{
		return true;
	}
	return false;
}
