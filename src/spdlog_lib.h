/*
 * spdlog_lib.h
 *
 *  Created on: Sep 29, 2017
 *      Author: vietpham
 */

#ifndef SPDLOG_LIB_H_
#define SPDLOG_LIB_H_

#include "../spdlog/spdlog.h"

using namespace std;

//#define LOG_SHOWTHREAD //Show thread of msg in log

//#define LOG_ROTATE
//#define LOG_ROTATE_SIZEROTATE 1 //Size rotate log file in MB
//#define LOG_ROTATE_NUMROTATE 5

//#define LOG_DAILY
//#define LOG_DAILY_HOUR 15
//#define LOG_DAILY_MINUTE 20 //The minute is multiply of 10

class SpdLogLib
{
public:
	std::shared_ptr<spdlog::logger> spd_logger;
	SpdLogLib();
	~SpdLogLib();
};

extern SpdLogLib spdloglib;

#define LOGI(...) spdloglib.spd_logger->info(__VA_ARGS__)
#define LOGW(...) spdloglib.spd_logger->warn(__VA_ARGS__)
#define LOGE(...) spdloglib.spd_logger->error(__VA_ARGS__)

#endif /* SPDLOG_LIB_H_ */
