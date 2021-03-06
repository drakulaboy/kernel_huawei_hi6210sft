/******************************************************************************

                  版权所有 (C), 2001-2011, 华为技术有限公司

 ******************************************************************************
  文 件 名   : drv_update.c
  版 本 号   : 初稿
  作    者   : c61362
  生成日期   : 2012年3月2日
  最近修改   :
  功能描述   : 底软给上层软件封装的接口层
  修改历史   :
  1.日    期   : 2012年3月2日
    作    者   : c61362
    修改内容   : 新建Drvinterface.c

  2.日    期   : 2013年2月19日
    作    者   : 蔡喜 220237
    修改内容   : 由Drvinterface.c拆分所得

******************************************************************************/

/*****************************************************************************
  1 头文件包含
*****************************************************************************/

#include "mdrv_dload.h"


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/*****************************************************************************
  2 函数声明
*****************************************************************************/

/*****************************************************************************
  3 函数实现
*****************************************************************************/

/*****************************************************************************
 函 数 名  : DRV_GET_DLOAD_VERSION
 功能描述  : Get dload version
 输入参数  : 无。
 输出参数  : 无。
 返 回 值  : 无。
*****************************************************************************/
#if 0
BSP_S32 DRV_GET_DLOAD_VERSION(BSP_U8 *str, int len)
{
#if defined (BSP_CORE_MODEM) || defined(PRODUCT_CFG_CORE_TYPE_MODEM)
    return BSP_DLOAD_GetDloadVer((BSP_CHAR *)str, len);
#endif

#if (defined BSP_CORE_APP)
    return 0;   /* 打桩 */
#endif
}


/*****************************************************************************
 函 数 名  : DRV_SET_UPDATA_FLAG
 功能描述  : 设置升级加载标志。
 输入参数  : flag：升级加载标志，
                   0：启动后进入bootrom，进行升级加载。
                   1：启动后不进入bootrom，正常启动。
 输出参数  : 无。
 返 回 值  : 0:  操作成功；
             -1：操作失败。
*****************************************************************************/
int DRV_SET_UPDATA_FLAG(int flag)
{
#if defined (BSP_CORE_MODEM) || defined(PRODUCT_CFG_CORE_TYPE_MODEM)
    return BSP_SET_UPDATA_FLAG(flag);
#endif

#if (defined BSP_CORE_APP)
    return 0;   /* 打桩 */
#endif
}

/* Begin: DRV为OAM实现NV备份恢复流程而提供的接口 */

/********************************************************************************************************
 函 数 名  : DRV_UPGRADE_NV_SET_RESULT
 功能描述  : OAM通过该接口告诉底软NV升级成功了还是失败了；
             如果NV升级成功，底软往fastboot共享区置成功标识
             如果NV升级失败，底软什么都不做
 输入参数  : status：0表示NV升级成功；
                     其他值表示NV升级失败
 输出参数  :
 返 回 值  : 0:  操作成功；
             -1：操作失败。
 其他注意  : V9 BBIT 打桩
             V9 SFT  实现

 修改历史  :
 1.日    期   : 2012年12月6日
   作    者   : 蔡喜 00220237
   修改内容   : 新生成函数
********************************************************************************************************/
int DRV_UPGRADE_NV_SET_RESULT(int status)
{
#if defined (BSP_CORE_MODEM) || defined(PRODUCT_CFG_CORE_TYPE_MODEM)
    return BSP_DLOAD_Upgrade_Nv_Set_Result(status);
#endif

#if (defined BSP_CORE_APP)
    return 0;   /* 打桩 */
#endif
}

/********************************************************************************************************
 函 数 名  : DRV_NV_FILE_SEC_CHECK
 功能描述  : 对文件进行校验
 输入参数  : pnvFilePath：待校验文件的路径
 输出参数  :
 返 回 值  : 0:  文件校验正确；
             -1：文件校验失败。
 其他注意  : 目前条件不具备，直接打桩，以后实现

 修改历史  :
 1.日    期   : 2012年12月6日
   作    者   : 蔡喜 00220237
   修改内容   : 新生成函数
********************************************************************************************************/
int DRV_NV_FILE_SEC_CHECK(char * pnvFilePath)
{
    return 0;
}

/********************************************************************************************************
 函 数 名  : DRV_GET_FS_ROOT_DIRECTORY
 功能描述  : 查询根目录的分区情况
 输入参数  : data：用于存放根目录字符串的缓冲区的首地址
             len:缓冲区data的长度
 输出参数  :
 返 回 值  : 0:  操作成功；
             -1：操作失败。

 修改历史  :
 1.日    期   : 2012年12月6日
   作    者   : 蔡喜 00220237
   修改内容   : 新生成函数
********************************************************************************************************/
int DRV_GET_FS_ROOT_DIRECTORY(char * data, unsigned int len)
{
#if defined (BSP_CORE_MODEM) || defined(PRODUCT_CFG_CORE_TYPE_MODEM)
    return BSP_DLOAD_Get_Fs_Root_Directory(data, len);
#endif

#if (defined BSP_CORE_APP)
    return 0;   /* 打桩 */
#endif
}

/********************************************************************************************************
 函 数 名  : DRV_NVBACKUP_EXT_READ
 功能描述  : 从Flash中的LastBackup区读取数据，为NV备份数据丢失的容错恢复机制提供支持
 输入参数  : len：从LastBackup起始处开始，需要读取的NV项长度（字节数）。
 输出参数  : pRamAddr：目的RAM地址，用于存放读出的NV项数据。
 返 回 值  : 0:  操作成功；
             -1：操作失败。
 其他注意  : V3R3 SFT  打桩
             V9R1 SFT  实现

 修改历史  :
 1.日    期   : 2013年10月22日
   作    者   : 蔡喜 00220237
   修改内容   : 新增函数
********************************************************************************************************/
int DRV_NVBACKUP_EXT_READ(unsigned char *pRamAddr, unsigned int len)
{
#if defined (BSP_CORE_MODEM) || defined(PRODUCT_CFG_CORE_TYPE_MODEM)
    return BSP_DLOAD_NVBackupExtRead(pRamAddr, len);
#endif

#if (defined BSP_CORE_APP)
    return 0;   /* 打桩 */
#endif
}

/********************************************************************************************************
 函 数 名  : DRV_NVBACKUP_EXT_WRITE
 功能描述  : 将特定数据写入Flash中的LastBackup区，为NV备份数据丢失的容错恢复机制提供支持
 输入参数  : pRamAddr：源RAM地址，用于存放需要写入的NV项数据。
             len：从LastBackup区起始处开始，需要写入的NV项长度（字节数）。
 输出参数  : 无。
 返 回 值  : 0:  操作成功；
             -1：操作失败。
 其他注意  : V3R3 SFT  打桩
             V9R1 SFT  实现

 修改历史  :
 1.日    期   : 2013年10月22日
   作    者   : 蔡喜 00220237
   修改内容   : 新增函数
********************************************************************************************************/
int DRV_NVBACKUP_EXT_WRITE(unsigned char *pRamAddr, unsigned int len)
{
#if defined (BSP_CORE_MODEM) || defined(PRODUCT_CFG_CORE_TYPE_MODEM)
    return BSP_DLOAD_NVBackupExtWrite(pRamAddr, len);
#endif

#if (defined BSP_CORE_APP)
    return 0;   /* 打桩 */
#endif
}

/* End: DRV为OAM实现NV备份恢复流程而提供的接口 */

/*****************************************************************************
* 函 数 名  : BSP_DLOAD_GetBootromVer
*
* 功能描述  : 获取BOOTROM版本号
*
* 输入参数  : BSP_S8 *str   :字符串缓冲区
*             BSP_S32 len   :字符串长度
* 输出参数  : BSP_S8 *str   :字符串缓冲区
*
* 返 回 值  : DLOAD_ERROR   :输入参数非法
*             其它          :返回字符串长度
*
* 其它说明  : 无
*
*****************************************************************************/
BSP_S32 BSP_DLOAD_GetBootromVer(BSP_CHAR *str, BSP_U32 len)
{
    return 0;
}

/*****************************************************************************
* 函 数 名  : BSP_DLOAD_Reset
*
* 功能描述  : 单板重启
*
* 输入参数  : BSP_VOID
* 输出参数  : 无
*
* 返 回 值  : 无
*
* 其它说明  : AT模块调用
*             华为私有接口
*             正常模式支持
*             下载模式不支持
*             正常模式接受到此命令以后单板将重新启动
*
*****************************************************************************/
BSP_VOID BSP_DLOAD_Reset(BSP_VOID)
{
    return;
}


BSP_S32 DRV_GET_AUTHORITY_ID(unsigned char *buf, BSP_S32 len)
{
    return 0;
}

BSP_S32 DRV_GET_AUTHORITY_VERSION(BSP_U8 *str, BSP_S32 len)
{
    return 0;
}

BSP_S32 DRV_GET_DLOAD_INFO(unsigned char atCmdBuf[], unsigned int dloadType)
{
    return 0;
}
#endif
/*****************************************************************************
* 函 数 名  : mdrv_dload_set_curmode
*
* 功能描述  : 设置当前工作模式
*
* 输入参数  : void
* 输出参数  : DLOAD_MODE_NORMAL     :正常模式
*             DLOAD_MODE_DATA       :数据模式
*             DLOAD_MODE_DOWNLOAD   :下载模式
*
* 返 回 值  : 无
*
* 其它说明  : AT模块调用
*             正常模式支持的有:
*                 BSP_DLOAD_GetCurMode(DLOAD_MODE_DOWNLOAD)
*             下载模式支持的有:
*                 BSP_DLOAD_GetCurMode(DLOAD_MODE_DATA)
*
*****************************************************************************/
void mdrv_dload_set_curmode(DLOAD_MODE_E eDloadMode)
{
    return;
}

/*****************************************************************************
* 函 数 名  : BSP_DLOAD_GetCurMode
*
* 功能描述  : 获取当前工作模式
*
* 输入参数  : void
* 输出参数  : 无
*
* 返 回 值  : DLOAD_MODE_NORMAL     :正常模式
*             DLOAD_MODE_DATA       :数据模式
*             DLOAD_MODE_DOWNLOAD   :下载模式
*
* 其它说明  : 无
*
*****************************************************************************/
DLOAD_MODE_E mdrv_dload_get_curmode(void)
{
    return DLOAD_MODE_DOWNLOAD;
}

/*****************************************************************************
* 函 数 名  : mdrv_dload_set_softload
*
* 功能描述  : 设置启动标志
*
* 输入参数  : BSP_BOOL bSoftLoad  :
*             BSP_FALSE :从vxWorks启动
*             BSP_TRUE  :从bootrom启动
* 输出参数  : 无
*
* 返 回 值  : 无
*
* 其它说明  : 无
*
*****************************************************************************/
void mdrv_dload_set_softload (int bSoftLoad)
{
    return ;
}

/*****************************************************************************
* 函 数 名  : mdrv_dload_get_softload
*
* 功能描述  : 获取启动标志
*
* 输入参数  : void
* 输出参数  : 无
*
* 返 回 值  : BSP_TRUE  :从bootrom启动
*             BSP_FALSE :从vxWorks启动
*
* 其它说明  : 无
*
*****************************************************************************/
int mdrv_dload_get_softload (void)
{
    return 0;
}

/*****************************************************************************
* 函 数 名  : mdrv_dload_get_info
*
* 功能描述  : 返回升级版本信息
*
* 输入参数  : 无
* 输出参数  : 无
*
* 返 回 值  : 不为空 返回升级版本信息
                    为空 返回失败
*
* 其它说明  : 无
*
*****************************************************************************/
DLOAD_VER_INFO_S g_dload_ver_info = {
    0,       /*productname*/
    0,       /*productnamelen*/
    0,       /*softwarever*/
    0,
    0,
    0,
    0,
    0
};

DLOAD_VER_INFO_S * mdrv_dload_get_info(void)
{
    return &g_dload_ver_info;
}





#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

