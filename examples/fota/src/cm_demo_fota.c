/*********************************************************
 *  @file    cm_demo_fota.c
 *  @brief   OpenCPU FOTA示例
 *  Copyright (c) 2022 China Mobile IOT.
 *  All rights reserved.
 *  created by WangPeng 2022/8/29
 ********************************************************/

#include "stdio.h"
#include "string.h"
#include "cm_fota.h"
#include "cm_sys.h"
#include "cm_os.h"
#include "cm_demo_uart.h"

/**
 *  UART口FOTA功能调试使用示例
 *  CM:FOTA:TWO_PACKAGE_HTTP             //HTTP FOTA双包升级方式，配置HTTP服务器信息（仅为示例，配置的url不可使用）
 *  CM:FOTA:TWO_PACKAGE_FTP              //FTP FOTA双包升级方式，配置FTP服务器信息（仅为示例，配置的url不可使用）
 *  CM:FOTA:FULLPACKAGE_HTTP             //HTTP FOTA完整包升级方式，配置HTTP服务器信息（仅为示例，配置的url不可使用）
 *  CM:FOTA:FULLPACKAGE_FTP              //FTP FOTA完整包升级方式，配置FTP服务器信息（仅为示例，配置的url不可使用）
 *  CM:FOTA:UPGRADE                      //升级，须在完成配置后使用
 */
void cm_test_fota(unsigned char **cmd,int len)
{
    unsigned char operation[20] = {0};
    sprintf((char *)operation, "%s", cmd[2]);
    int ret = 0;

    if (0 == strcmp((const char *)operation, "TWO_PACKAGE_HTTP"))               //HTTP FOTA双包升级方式，配置FOTA信息
    {
        cm_fota_set_ota_plan(CM_FOTA_ASR_PLAN_MINI);
        ret = cm_fota_set_url("http://xxx.com:8080/system_patch.bin_1");        //仅作为示例，url不可使用，该方式下url中下载的文件名须以.bin_1结尾

        if (0 != ret){
            cm_log_printf(0, "cm_fota_set_url() error");
        }
    }
    else if (0 == strcmp((const char *)operation, "TWO_PACKAGE_FTP"))          //FTP FOTA双包升级方式，配置FOTA信息
    {
        cm_fota_set_ota_plan(CM_FOTA_ASR_PLAN_MINI);
        ret = cm_fota_set_url("ftp://xxx.com:23/system_patch.bin_1");           //仅作为示例，url不可使用，该方式下url中下载的文件名须以.bin_1结尾

        if (0 != ret){
            cm_log_printf(0, "cm_fota_set_url() error");
        }

        ret = cm_fota_set_auth("user", "password");

        if (0 != ret){
            cm_log_printf(0, "cm_fota_set_auth() error");
        }
    }
    else if (0 == strcmp((const char *)operation, "FULLPACKAGE_HTTP"))          //HTTP FOTA完整包升级方式，配置FOTA信息
    {
        cm_fota_set_ota_plan(CM_FOTA_ASR_PLAN_MINI_INTEGRATE);
        ret = cm_fota_set_url("http://xxx.com:8080/system_patch.bin");          //仅作为示例，url不可使用

        if (0 != ret){
            cm_log_printf(0, "cm_fota_set_url() error");
        }
    }
    else if (0 == strcmp((const char *)operation, "FULLPACKAGE_FTP"))          //FTP FOTA完整包升级方式，配置FOTA信息
    {
        cm_fota_set_ota_plan(CM_FOTA_ASR_PLAN_MINI_INTEGRATE);
        ret = cm_fota_set_url("ftp://xxx.com:23/system_patch.bin");             //仅作为示例，url不可使用

        if (0 != ret){
            cm_log_printf(0, "cm_fota_set_url() error");
        }

        ret = cm_fota_set_auth("user", "password");

        if (0 != ret){
            cm_log_printf(0, "cm_fota_set_auth() error");
        }
    }
    else if (0 == strcmp((const char *)operation, "UPGRADE"))                 //启动升级
    {
        cm_fota_info_t info = {0};
        cm_fota_read_config(&info);

        if (CM_FOTA_TYPE_HTTP_HTTPS == info.fixed_info.fota_mode)
        {
            cm_log_printf(0, "HTTP server [%s]", info.fixed_info.url);
        }
        else if (CM_FOTA_TYPE_FTP == info.fixed_info.fota_mode)
        {
            cm_log_printf(0, "FTP server [%s] [%s] [%s]", info.fixed_info.url, info.fixed_info.username, info.fixed_info.passwd);
        }
        else
        {
            cm_log_printf(0, "HTTP server error");
            return;
        }

        osDelay(200);

        cm_fota_exec_upgrade();
    }
    else
    {
        cm_demo_printf("[FOTA] Illegal operation\n"); 
    }
    return;
}
