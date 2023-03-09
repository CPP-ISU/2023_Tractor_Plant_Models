#ifndef PORTABLE_WORDSIZES
#ifdef __MW_TARGET_USE_HARDWARE_RESOURCES_H__
#ifndef __MW_TARGET_HARDWARE_RESOURCES_H__
#define __MW_TARGET_HARDWARE_RESOURCES_H__

#define MW_MULTI_TASKING_MODE 1
#include "MW_raspi_init.h"
#include "MW_Pyserver_control.h"

#define MW_USECODERTARGET 1
#define MW_TARGETHARDWARE Raspberry Pi
#define MW_CONNECTIONINFO_XCPONTCPIP_IPADDRESS codertarget.raspi.getDeviceAddress
#define MW_CONNECTIONINFO_XCPONTCPIP_PORT 17727
#define MW_CONNECTIONINFO_XCPONTCPIP_VERBOSE 0
#define MW_CONNECTIONINFO_XCPONTCPIP_RUNINBACKGROUND 0
#define MW_CONNECTIONINFO_TCPIP_IPADDRESS codertarget.raspi.getDeviceAddress
#define MW_CONNECTIONINFO_TCPIP_PORT 17725
#define MW_CONNECTIONINFO_TCPIP_VERBOSE 0
#define MW_CONNECTIONINFO_TCPIP_RUNINBACKGROUND 0
#define MW_EXTMODE_CONFIGURATION XCP on TCP/IP
#define MW_EXTMODE_SIGNALBUFFERSIZE 1000000.000000
#define MW_EXTMODE_TARGETPOLLINGTIMEMODE 0
#define MW_EXTMODE_TARGETPOLLINGTIME 2
#define MW_EXTMODE_RUNNING on
#define MW_RTOS Linux
#define MW_RTOSBASERATETASKPRIORITY 40
#define MW_DETECTTASKOVERRUNS 0.000000
#define MW_SCHEDULER_INTERRUPT_SOURCE 0
#define MW_BOARDPARAMETERS_DEVICEADDRESS 169.254.11.56
#define MW_BOARDPARAMETERS_DEVICENAME 
#define MW_BOARDPARAMETERS_USERNAME pi
#define MW_BOARDPARAMETERS_PASSWORD raspberry
#define MW_BOARDPARAMETERS_BUILDDIR /home/pi
#define MW_BOARDPARAMETERS_ONLINEBUILDDIR /home/pi
#define MW_RUNTIME_BUILDACTION 1
#define MW_RUNTIME_RUNONBOOT 0
#define MW_BUILDTIME_ENABLEPARALLELBUILD 1
#define MW_SPI_SPI0CE0BUSSPEED 6
#define MW_SPI_SPI0CE1BUSSPEED 6
#define MW_CAN_CANBUSSPEED 9
#define MW_CAN_CANOSCILLATORFREQUENCY 1
#define MW_CAN_INTERRUPTPIN 12
#define MW_CAN_ALLOWALLFILTER 1
#define MW_CAN_BUFFER0IDTYPE 0
#define MW_CAN_ACCEPTANCEMASK0 0
#define MW_CAN_ACCEPTANCEFILTER0 255
#define MW_CAN_INVERSEFILTER0 0
#define MW_CAN_BUFFER1IDTYPE 0
#define MW_CAN_ACCEPTANCEMASK1 0
#define MW_CAN_ACCEPTANCEFILTER1 255
#define MW_CAN_INVERSEFILTER1 0
#define MW_CAN_BUFFER2IDTYPE 1
#define MW_CAN_ACCEPTANCEMASK2 0
#define MW_CAN_ACCEPTANCEFILTER2 255
#define MW_CAN_INVERSEFILTER2 0
#define MW_CAN_BUFFER3IDTYPE 1
#define MW_CAN_ACCEPTANCEMASK3 0
#define MW_CAN_ACCEPTANCEFILTER3 255
#define MW_CAN_INVERSEFILTER3 0
#define MW_MQTT_BROKERADDRESS mqtt3.thingspeak.com
#define MW_MQTT_USERNAME 
#define MW_MQTT_PASSWORD 
#define MW_MQTT_CLIENTID 
#define MW_SIMULINKIO_TRANSPORTLAYERTYPE 0
#define MW_SIMULINKIO_TRANSPORTLAYERTYPEONLINE 0
#define MW_SIMULINKIO_MODELTRANSPORTDATAFCN codertarget.raspi.ioclient.getModelTransportInfo
#define MW_SIMULINKIO_SERVERDEPLOYFCN codertarget.raspi.ioclient.deployServer
#define MW_MODBUS_MODBUS_COMMS 0
#define MW_MODBUS_MODBUS_MODE 0
#define MW_MODBUS_MODBUS_SERVERREMOTEPORT 502
#define MW_MODBUS_MODBUS_SERVERLOCALPORT 502
#define MW_MODBUS_MODBUS_CONFIGCOIL 49
#define MW_MODBUS_MODBUS_COILADDR 0
#define MW_MODBUS_MODBUS_COILNUM 1
#define MW_MODBUS_MODBUS_CONFIGINPUT 49
#define MW_MODBUS_MODBUS_INPUTADDR 0
#define MW_MODBUS_MODBUS_INPUTNUM 1
#define MW_MODBUS_MODBUS_CONFIGHOLDINGREG 49
#define MW_MODBUS_MODBUS_HOLDINGREGADDR 0
#define MW_MODBUS_MODBUS_HOLDINGREGNUM 1
#define MW_MODBUS_MODBUS_CONFIGINPUTREG 49
#define MW_MODBUS_MODBUS_INPUTREGADDR 0
#define MW_MODBUS_MODBUS_INPUTREGNUM 1
#define MW_MODBUS_MODBUS_MASTERTIMEOUT 100
#define MW_DASHBOARDPARAMETERS_ENABLEDEPLOYMENT 0
#define MW_DASHBOARDPARAMETERS_IPADDRESSTYPE 0
#define MW_DASHBOARDPARAMETERS_IPADDRESS 
#define MW_DASHBOARDPARAMETERS_WEBSOCKETPORT 8000
#define MW_DASHBOARDPARAMETERS_HTTPPORT 8184
#define MW_DATAVERSION 2016.02
#define MW_DASHBOARDCODEGENINFO_ENABLECODEGEN 0
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBCIRCULARGAUGE_CODEGEN 1
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBCIRCULARGAUGE_BLOCKCLASS codertarget.raspi.internal.RaspiCircularGauge
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBCIRCULARGAUGE_REGFCN codertarget.raspi.blocks.registerDashboardBlock
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBCIRCULARGAUGE_VALIDATEFCN codertarget.targetHiddenBlkInsert.internal.isDashboardBlockCodegenEnabled
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBHORIZONTALGAUGE_CODEGEN 1
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBHORIZONTALGAUGE_BLOCKCLASS codertarget.raspi.internal.RaspiHorizontalGauge
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBHORIZONTALGAUGE_REGFCN codertarget.raspi.blocks.registerDashboardBlock
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBHORIZONTALGAUGE_VALIDATEFCN codertarget.targetHiddenBlkInsert.internal.isDashboardBlockCodegenEnabled
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBVERTICALGAUGE_CODEGEN 1
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBVERTICALGAUGE_BLOCKCLASS codertarget.raspi.internal.RaspiVerticalGauge
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBVERTICALGAUGE_REGFCN codertarget.raspi.blocks.registerDashboardBlock
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBVERTICALGAUGE_VALIDATEFCN codertarget.targetHiddenBlkInsert.internal.isDashboardBlockCodegenEnabled
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBLAMP_CODEGEN 1
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBLAMP_BLOCKCLASS codertarget.raspi.internal.RaspiLamp
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBLAMP_REGFCN codertarget.raspi.blocks.registerDashboardBlock
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBLAMP_VALIDATEFCN codertarget.targetHiddenBlkInsert.internal.isDashboardBlockCodegenEnabled
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBKNOB_CODEGEN 1
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBKNOB_BLOCKCLASS codertarget.raspi.internal.RaspiKnob
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBKNOB_REGFCN codertarget.raspi.blocks.registerDashboardBlock
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBKNOB_VALIDATEFCN codertarget.targetHiddenBlkInsert.internal.isDashboardBlockCodegenEnabled
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBSWITCH_CODEGEN 1
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBSWITCH_BLOCKCLASS codertarget.raspi.internal.RaspiSwitch
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBSWITCH_REGFCN codertarget.raspi.blocks.registerDashboardBlock
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBSWITCH_VALIDATEFCN codertarget.targetHiddenBlkInsert.internal.isDashboardBlockCodegenEnabled
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBPUSHBUTTON_CODEGEN 1
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBPUSHBUTTON_BLOCKCLASS codertarget.raspi.internal.RaspiPushButton
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBPUSHBUTTON_REGFCN codertarget.raspi.blocks.registerDashboardBlock
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBPUSHBUTTON_VALIDATEFCN codertarget.targetHiddenBlkInsert.internal.isDashboardBlockCodegenEnabled
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBHORIZONTALSLIDER_CODEGEN 1
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBHORIZONTALSLIDER_BLOCKCLASS codertarget.raspi.internal.RaspiHorizontalSlider
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBHORIZONTALSLIDER_REGFCN codertarget.raspi.blocks.registerDashboardBlock
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBHORIZONTALSLIDER_VALIDATEFCN codertarget.targetHiddenBlkInsert.internal.isDashboardBlockCodegenEnabled
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBVERTICALSLIDER_CODEGEN 1
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBVERTICALSLIDER_BLOCKCLASS codertarget.raspi.internal.RaspiVerticalSlider
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBVERTICALSLIDER_REGFCN codertarget.raspi.blocks.registerDashboardBlock
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBVERTICALSLIDER_VALIDATEFCN codertarget.targetHiddenBlkInsert.internal.isDashboardBlockCodegenEnabled
#define MW_IOBLOCKSMODE deployed

#endif /* __MW_TARGET_HARDWARE_RESOURCES_H__ */

#endif

#endif