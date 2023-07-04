/**
 * @file        cm_sd.h
 * @brief       SDCARD
 * @copyright   Copyright © 2022 China Mobile IOT. All rights reserved.
 * @author      By WangPeng
 * @date        2022/12/16
 *
 * @defgroup SDCARD SDCARD
 * @ingroup SDCARD
 * @{
 */

#ifndef __CM_SDCARD_H__
#define __CM_SDCARD_H__

/****************************************************************************
 * Included Files
 ****************************************************************************/
#include <stdint.h>
#include <stdbool.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/
#define CM_SD_SEEK_SET      (0)      /*!< SEEK_SET */
#define CM_SD_SEEK_CUR      (1)      /*!< SEEK_CUR */
#define CM_SD_SEEK_END      (2)      /*!< SEEK_END */

#define CM_SD_MAX_PATH (256)

/****************************************************************************
 * Public Types
 ****************************************************************************/
typedef struct
{
    long long free_size;  /*!< 当前可用文件系统大小 */
    long long total_size; /*!< 文件系统总大小 */
} cm_sd_system_info_t;


/****************************************************************************
 * Public Data
 ****************************************************************************/


/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

#ifdef __cplusplus
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/**
 *  @brief 查询（SD卡）文件系统是否格式化
 *
 *  @param [in] vol 逻辑驱动器号指针
 *
 *  @return 
 *   TRUE  - SD卡已格式化 \n
 *   FALSE - SD卡未格式化
 *
 *  @details SD卡功能与uart0互斥，不可同时使用，仅8M内存的模组支持SD
 */
bool cm_sd_is_formatted(char *vol);

/**
 *  @brief 格式化（SD卡）文件系统
 *
 *  @param [in] vol 逻辑驱动器号指针
 *
 *  @return 
 *   = 0  - 成功 \n
 *   < 0  - 失败, 返回值为错误码
 *
 *  @details SD卡功能与uart0互斥，不可同时使用，仅8M内存的模组支持SD
 */
int32_t cm_sd_format(char *vol);

/**
 *  @brief 打开一个文件
 *
 *  @param [in] filename 文件名称
 *  @param [in] mode 参数（r w c a +）
 *
 *  @return 
 *   >= 0 - 文件描述符 \n
 *   < 0  - 失败, 返回值为错误码
 *
 *  @details r: read \n
 *          w: write \n
 *          c: create \n
 *          a: append and write \n
 *          +: read and write \n
 *          SD卡功能与uart0互斥，不可同时使用，仅8M内存的模组支持SD
 */
int32_t cm_sd_fopen(const char *filename, const char *mode);

/**
 *  @brief 关闭一个文件
 *
 *  @param [in] fd 文件描述符
 *
 *  @return 
 *   = 0  - 成功 \n
 *   < 0  - 失败, 返回值为错误码
 *
 *  @details SD卡功能与uart0互斥，不可同时使用，仅8M内存的模组支持SD
 */
int32_t cm_sd_fclose(int32_t fd);

/**
 *  @brief 读取文件内容
 *
 *  @param [in]  fd   文件描述符
 *  @param [out] buf  存储数据的缓冲区指针
 *  @param [in]  size 要读取的数据长度
 *
 *  @return
 *   >= 0 - 实际的读取长度 \n
 *   <  0 - 读取失败
 *
 *  @details SD卡功能与uart0互斥，不可同时使用，仅8M内存的模组支持SD
 */
int32_t cm_sd_fread(int32_t fd, void *buf, uint32_t size);

/**
 *  @brief 写入文件内容
 *
 *  @param [in] fd   文件描述符
 *  @param [in] buf  存储数据的缓冲区指针
 *  @param [in] size 要写入的数据长度
 *
 *  @return
 *   >= 0 - 实际的写入长度 \n
 *   <  0 - 写入失败
 *
 *  @details SD卡功能与uart0互斥，不可同时使用，仅8M内存的模组支持SD
 */
int32_t cm_sd_fwrite(int32_t fd, const void *buf, uint32_t size);

/**
 *  @brief 文件指针定位
 *
 *  @param [in] fd 文件描述符
 *  @param [in] offset 指针偏移量
 *  @param [in] base 偏移起始点，CM_SD_SEEK_SET：文件开头 CM_SD_SEEK_CUR：当前位置 CM_SD_SEEK_END：文件末尾
 *
 *  @return
 *   = 0 - 成功 \n
 *   < 0 - 失败
 *
 *  @details offset不支持为负数 \n
 *           SD卡功能与uart0互斥，不可同时使用，仅8M内存的模组支持SD
 */
int32_t cm_sd_fseek(int32_t fd, int32_t offset, int32_t base);

/**
 *  @brief 删除文件
 *
 *  @param [in] file_name 文件路径
 *
 *  @return
 *   >= 0 - 成功 \n
 *   <  0 - 失败
 *
 *  @details SD卡功能与uart0互斥，不可同时使用，仅8M内存的模组支持SD
 */
int32_t cm_sd_fdelete(const char *file_name);

/**
 *  @brief 更改文件名
 *
 *  @param [in] src  原文件名
 *  @param [in] dest 新文件名
 *
 *  @return
 *   = 0 - 成功 \n
 *   < 0 - 失败
 *
 *  @details SD卡功能与uart0互斥，不可同时使用，仅8M内存的模组支持SD
 */
int32_t cm_sd_fmove(const char *src, const char *dest);

/**
 *  @brief 检查文件是否存在
 *
 *  @param [in] file_name 文件名称
 *
 *  @return
 *   = 1 - 存在 \n
 *   = 0 - 不存在
 *
 *  @details SD卡功能与uart0互斥，不可同时使用，仅8M内存的模组支持SD
 */
int32_t cm_sd_exist(const char *file_name);

/**
 *  @brief 获取文件大小
 *
 *  @param [in] file_name 文件路径
 *
 *  @return
 *   >= 0 - 文件长度 \n
 *   <  0 - 操作失败
 *
 *  @details SD卡功能与uart0互斥，不可同时使用，仅8M内存的模组支持SD
 */
int32_t cm_sd_filesize(const char *file_name);

/**
 *  @brief 创建文件夹
 *
 *  @param [in] path 文件夹路径
 *
 *  @return
 *   = 0 - 成功 \n
 *   < 0 - 失败
 *
 *  @details SD卡功能与uart0互斥，不可同时使用，仅8M内存的模组支持SD
 */
int32_t cm_sd_mkdir(char *path);

/**
 *  @brief 删除文件夹
 *
 *  @param [in] path 文件夹路径
 *  @return
 *   = 0 - 成功 \n
 *   < 0 - 失败
 *
 *  @details SD卡功能与uart0互斥，不可同时使用，仅8M内存的模组支持SD
 */
int32_t cm_sd_rmdir(char *path);

/**
 *  @brief 设置当前文件夹路径
 *
 *  @param [in] path 文件夹路径
 *
 *  @return
 *   = 0 - 成功 \n
 *   < 0 - 失败
 *
 *  @details SD卡功能与uart0互斥，不可同时使用，仅8M内存的模组支持SD
 */
int32_t cm_sd_set_currentdir(char *path);

/**
 *  @brief 获取当前文件夹路径
 *
 *  @param [out] path 用于保存文件夹路径的buffer
 *  @param [in]  max_len 用于保存文件夹路径的buffer的长度
 *
 *  @return
 *   = 0 - 成功 \n
 *   < 0 - 失败
 *
 *  @details SD卡功能与uart0互斥，不可同时使用，仅8M内存的模组支持SD
 */
int32_t cm_sd_get_currentdir(char *path, uint32_t max_len);

/**
 *  @brief 获取文件系统信息
 *
 *  @param [in] vol 逻辑驱动器号指针
 *  @param [out] info 文件系统信息
 *
 *  @return
 *   = 0 - 成功 \n
 *   < 0 - 失败
 *
 *  @details SD卡功能与uart0互斥，不可同时使用，仅8M内存的模组支持SD
 */
int32_t cm_sd_getinfo(char *vol, cm_sd_system_info_t *info);


#undef EXTERN
#ifdef __cplusplus
}
#endif

/** @}*/
/** @}*/

#endif /* __CM_SDCARD_H__ */

