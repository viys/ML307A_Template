# 中移物联网 OpenCPU SDK 简介 

## **注意事项（必读）**
SDK中ML307A-DCLN、ML307A-DSLN、ML307A-GSLN三个型号开发完成，用户可使用
SDK中ML307A-GCLN及ML302A、ML305A所以型号开发未完成，用户不可使用
SDK中cm_local_tts.h模块正处于开发中状态，用户不可使用

## **代码目录**
OpenCPU SDK代码目录结构，如下图所示：

| 名称          | 描述                       |
| ------------- | --------------------------|
| custom        | 用户代码目录、用户程序入口  |
| docs          | 文档                      |
| examples      | 示例代码                  |
| include       | OpenCPU API 头文件        |
| out           | 编译输出目录               |
| prebuild      | 预编译文件                 |
| third-party   | 第三方开源代码库           |
| tools         | 编译工具脚本               |

## **指导手册**
OpenCPU SDK相关指导手册，如下图所示：

| 名称             | 描述                           |
| ---------------- | ------------------------------|
| SDK开发指导      | 编译环境、SDK编译说明、下载调试  |
| API手册          | API全览说明文档，chm格式        |
| 资源综述          | 软硬件资源说明                 |
| 操作系统开发指导  | 互斥锁、信号量、定时器 ...      |
| 外围接口开发指导  | GPIO、UART、I2C、SPI ...      |
| 数据业务开发指导  | 网络状态、连接、数据发送        |
| ...              | ...           |

### 注意

本手册描述的产品及其附件特性和功能，取决于当地网络设计或网络性能，同时也取决于用户预先安装的各种软件。由于当地网络运营商、ISP，或当地网络设置等原因，可能也会造成本手册中描述的全部或部分产品及其附件特性和功能未包含在您的购买或使用范围之内。 

### 责任限制

除非合同另有约定，中移物联网有限公司对本文档内容不做任何明示或暗示的声明或保证，并且不对特定目的适销性及适用性或者任何间接的、特殊的或连带的损失承担任何责任。
 在适用法律允许的范围内，在任何情况下，中移物联网有限公司均不对用户因使用本手册内容和本手册中描述的产品而引起的任何特殊的、间接的、附带的或后果性的损坏、利润损失、数据丢失、声誉和预期的节省而负责。
 因使用本手册中所述的产品而引起的中移物联网有限公司对用户的最大赔偿（除在涉及⼈身伤害的情况中根据适⽤法律规定的损害赔偿外），不应超过用户为购买此产品而支付的金额。
 由于产品版本升级或其他原因，本文档内容会不定期进行更新。除非另有约定，本文档仅作为使用指导，本文档中的所有陈述、信息和建议不构成任何明示或暗示的担保。公司保留随时修改本手册中任何信息的权利，无需进行提前通知且不承担任何责任。


### 商标声明

为中国移动注册商标。
 本手册和本手册描述的产品中出现的其他商标、产品名称、服务名称和公司名称，均为其各自所有者的财产。 

### 进出口法规

出口、转口或进口本手册中描述的产品（包括但不限于产品软件和技术数据），用户应遵守相关进出口法律和法规。 

### 隐私保护

关于我们如何保护用户的个人信息等隐私情况，请查看相关隐私政策。 

### 操作系统更新声明

操作系统仅支持官方升级；如用户自己刷非官方系统，导致安全风险和损失由用户负责。 

### 固件包完整性风险声明

固件仅支持官方升级；如用户自己刷非官方固件，导致安全风险和损失由用户负责。 

### 版权所有© 中移物联网有限公司。保留一切权利。

本手册中描述的产品，可能包含中移物联网有限公司及其存在的许可人享有版权的软件，除非获得相关权利人的许可，否则，非经本公司书面同意，任何单位和个人不得擅自摘抄、复制本手册内容的部分或全部，并以任何形式传播。 



  
--------------------------------------------------------------------------------



