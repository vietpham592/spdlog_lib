/*
 * spdlog_lib.cpp
 *
 *  Created on: Sep 29, 2017
 *      Author: vietpham
 */




#include "spdlog_lib.h"

SpdLogLib spdloglib;

const std::string myLoggerName = "lib_logger";

SpdLogLib::SpdLogLib()
{
	//--- Customize msg format for all messages
#ifdef LOG_SHOWTHREAD
	spdlog::set_pattern("[%Y-%m-%d %T]\t[%t]\t%v");
#else
//	spdlog::set_pattern("[%Y-%m-%d %T:%e]\t[%l]\t%v");
	spdlog::set_pattern("[%Y-%m-%d %T:%e]\t%v");
#endif
	//---
#ifdef LOG_ROTATE
	spd_logger = spdlog::rotating_logger_mt("rotate","logs_rotate.txt",1048576*LOG_ROTATE_SIZEROTATE,LOG_ROTATE_NUMROTATE);
	spd_logger->flush_on(spdlog::level::info);
#else
#ifdef LOG_DAILY
	spd_logger = spdlog::daily_logger_mt("daily_logger","daily.txt",LOG_DAILY_HOUR,LOG_DAILY_MINUTE);
	spd_logger->flush_on(spdlog::level::info);
#else
	spd_logger = spdlog::stdout_color_mt("console");
#endif
#endif
}

SpdLogLib::~SpdLogLib()
{
	spdlog::drop_all();
}
