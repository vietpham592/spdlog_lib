/*
 * spdlog_main.cpp
 *
 *  Created on: Oct 11, 2017
 *      Author: vietpham
 */




#include "spdlog_lib.h"
#include <thread>

using namespace std;

void test_log()
{
	int count = 0;
	while(1)
	{
		LOGW("Count: %d",count);
		count++;
		usleep(500);
//		sleep(1);
	}
}

int main()
{
	thread th1(test_log);
//	thread th2(test_log);
	th1.join();
//	th2.join();

	spdlog::drop_all();
	return 1;
}
