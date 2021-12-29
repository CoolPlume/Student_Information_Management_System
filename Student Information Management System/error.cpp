#include "error.h"

void initialization_failed(int error_code)
{
	using std::cerr, std::endl;
	cerr << "程序初始化失败！" << endl;
	switch (error_code)
	{
	case 1:
	{
		cerr << "错误码：" << error_code << " 本地文件打开失败！" << endl;
		break;
	}
	}
	cerr << "程序终止！" << endl;
	system("pause");
	exit(1);
}
