#include "error.h"

void initialization_failed(int error_code)
{
	using std::cerr, std::endl;
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
