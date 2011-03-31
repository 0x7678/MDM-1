/*!
 * \file mdm_device_dslam_alcatel_73xx.h Defines for DSLAM ALCATEL 73xx.
 *
 * \author Marcelo Gornstein <marcelog@gmail.com>
 */
#ifndef	_MDM_DEVICE_DSLAM_ALCATEL_73XX_H_
#define	_MDM_DEVICE_DSLAM_ALCATEL_73XX_H_

#include	<mdm_connection.h>
#include	<mdm_device.h>

/*! Commands. */
typedef enum
{
/* 0  */	MDM_DSLAM_ALCATEL_73xx_CMD_UPTIME,
/* 1  */	MDM_DSLAM_ALCATEL_73xx_CMD_SOFT_VERSION,
/* 2  */	MDM_DSLAM_ALCATEL_73xx_CMD_SHOW_SLOTS,
/* 3  */	MDM_DSLAM_ALCATEL_73xx_CMD_SHOW_SLOT_PORT,
/* 4  */	MDM_DSLAM_ALCATEL_73xx_CMD_SHOW_SPECTRUM_PROFILE_DETAIL,
/* 5  */	MDM_DSLAM_ALCATEL_73xx_CMD_SHOW_SERVICE_PROFILE,
/* 6  */	MDM_DSLAM_ALCATEL_73xx_CMD_SHOW_ALL_PORTS,
/* 7  */	MDM_DSLAM_ALCATEL_73xx_CMD_GET_IP,
/* 8  */	MDM_DSLAM_ALCATEL_73xx_CMD_GET_ROUTES,
/* 9  */	MDM_DSLAM_ALCATEL_73xx_CMD_SHOW_PORT_DESCRIPTION,
/* 10 */	MDM_DSLAM_ALCATEL_73xx_CMD_SHOW_PORT_PROFILE,
/* 11 */	MDM_DSLAM_ALCATEL_73xx_CMD_SHOW_PORT_DATA_NEAR_END,
/* 12 */	MDM_DSLAM_ALCATEL_73xx_CMD_SHOW_PORT_REL_CAP_OCC_DOWN,
/* 13 */	MDM_DSLAM_ALCATEL_73xx_CMD_SHOW_PORT_ATM_PVC,
/* 14 */	MDM_DSLAM_ALCATEL_73xx_CMD_SHOW_PORT_INFO_VLAN,
/* 15 */	MDM_DSLAM_ALCATEL_73xx_CMD_SHOW_BACKUP_STATUS,
/* 16 */	MDM_DSLAM_ALCATEL_73xx_CMD_SHOW_DOWNLOAD_BACKUP_DB2,
/* 17 */	MDM_DSLAM_ALCATEL_73xx_CMD_SHOW_PORT_ATM_PVC2,
/* 18 */	MDM_DSLAM_ALCATEL_73xx_CMD_LOAD_PORTS_SLOT,
/* 19 */	MDM_DSLAM_ALCATEL_73xx_CMD_LOAD_PORTS_ALL,
/* 20 */	MDM_DSLAM_ALCATEL_73xx_CMD_SYSLOG_GET_1,
/* 21 */	MDM_DSLAM_ALCATEL_73xx_CMD_SYSLOG_GET_2,
/* 22 */	MDM_DSLAM_ALCATEL_73xx_CMD_SHOW_ATM_PVC_TRAFFIC_1,
/* 23 */	MDM_DSLAM_ALCATEL_73xx_CMD_SHOW_ATM_PVC_TRAFFIC_2,
/* 24 */	MDM_DSLAM_ALCATEL_73xx_CMD_SHOW_ATM_PVC_TRAFFIC_3,
/* 25 */	MDM_DSLAM_ALCATEL_73xx_CMD_ALARM_GET_2,
/* 26 */	MDM_DSLAM_ALCATEL_73xx_CMD_ALARM_GET,
/* 27 */	MDM_DSLAM_ALCATEL_73xx_CMD_PORTS_GET_TRAFFIC,
/* 28 */	MDM_DSLAM_ALCATEL_73xx_CMD_PORTS_GET,
/* 29 */	MDM_DSLAM_ALCATEL_73xx_CMD_ALARM_GET_COUNT,
/* 30 */ MDM_DSLAM_ALCATEL_73xx_CMD_NOP,
/* 31 */ MDM_DSLAM_ALCATEL_73xx_CMD_SET_TIMEZONE,
/* 32 */ MDM_DSLAM_ALCATEL_73xx_CMD_GET_NTP,
/* 33 */ MDM_DSLAM_ALCATEL_73xx_CMD_CREATE_SERVICE_PROFILE,
/* 34 */ MDM_DSLAM_ALCATEL_73xx_CMD_DELETE_SERVICE_PROFILE,
/* 35 */ MDM_DSLAM_ALCATEL_73xx_CMD_CFG_RAMODEUP_SERVICE_PROFILE,
/* 36 */ MDM_DSLAM_ALCATEL_73xx_CMD_CFG_RAMODEDOWN_SERVICE_PROFILE,
/* 37 */ MDM_DSLAM_ALCATEL_73xx_CMD_CFG_PBITRATEUP_SERVICE_PROFILE,
/* 38 */ MDM_DSLAM_ALCATEL_73xx_CMD_CFG_PBITRATEDOWN_SERVICE_PROFILE,
/* 39 */ MDM_DSLAM_ALCATEL_73xx_CMD_CFG_MDELAYUP_SERVICE_PROFILE,
/* 40 */ MDM_DSLAM_ALCATEL_73xx_CMD_CFG_MDELAYDOWN_SERVICE_PROFILE,
/* 41 */ MDM_DSLAM_ALCATEL_73xx_CMD_CFG_MAXBITRATEUP_SERVICE_PROFILE,
/* 42 */ MDM_DSLAM_ALCATEL_73xx_CMD_CFG_MAXBITRATEDOWN_SERVICE_PROFILE,
/* 43 */ MDM_DSLAM_ALCATEL_73xx_CMD_CFG_MINBITRATEUP_SERVICE_PROFILE,
/* 44 */ MDM_DSLAM_ALCATEL_73xx_CMD_CFG_MINBITRATEDOWN_SERVICE_PROFILE,
/* 45 */ MDM_DSLAM_ALCATEL_73xx_CMD_REBOOT_HOT,
/* 46 */ MDM_DSLAM_ALCATEL_73xx_CMD_REBOOT_ALL,
/* 47 */ MDM_DSLAM_ALCATEL_73xx_CMD_REBOOT_SHUB,
/* 48 */ MDM_DSLAM_ALCATEL_73xx_CMD_PORT_ENABLE,
/* 49 */ MDM_DSLAM_ALCATEL_73xx_CMD_PORT_DISABLE,
/* 50 */ MDM_DSLAM_ALCATEL_73xx_CMD_FILETRANSFER,
/* 51 */ MDM_DSLAM_ALCATEL_73xx_CMD_FILETRANSFER_HOST_USER_PASS,
/* 52 */ MDM_DSLAM_ALCATEL_73xx_CMD_DATABASE_UPLOAD_ACTIVE,
	MDM_DSLAM_ALCATEL_73xx_CMD_DUMMY
} mdm_device_cmd_dslam_alcatel_73xx_t;

/*! Options for dslam connection. */
typedef struct
{
	mdm_connection_type_t connection_type; /*!< Connection type. */
	char target[256]; /*!< If serial, filename. If network, host:port. */
	char username[16]; /*!< Username for login. */
	char password[16]; /*!< Password for login. */
	int to_recv; /*!< If blocking >= 0, wait at most this amount of milliseconds
		before timeout. If -1, will block. */
	int to_connect; /*!< If < 1 timeouts when os decides, otherwise, time in
		milliseconds for timeouting a connect(). */
} mdm_device_dslam_alcatel_73xx_options_t;

/*! This will hold internal data regarding the current connection. */
typedef struct
{
	int promptlen; /*!< We need the prompt length because when the dslam
	echoes our issued command, it adds the prompt length to make the command
	fit in 80 columns. */
} mdm_device_dslam_alcatel_73xx_data_t;

/*!
 * Used to post process dslam responses.
 * See #mdm_device_dslam_alcatel_73xx_post_exec_t
 */
typedef void (*mdm_device_dslam_alcatel_73xx_post_exec_t)(
	mdm_device_descriptor_t *, mdm_operation_result_t *
);

extern const char *MDM_DEVICE_CMDNAME_DSLAM_ALCATEL_73xx_STR[];
extern const char *MDM_DEVICE_CMD_DSLAM_ALCATEL_73xx_STR[];

extern void mdm_device_dslam_alcatel_73xx_open(
	mdm_device_descriptor_t *, mdm_connection_type_t, mdm_operation_result_t *
);
extern void mdm_device_dslam_alcatel_73xx_exec(
	mdm_device_descriptor_t *, mdm_operation_result_t *
);

extern void mdm_device_dslam_alcatel_73xx_close(
	mdm_device_descriptor_t *, mdm_operation_result_t *
);

extern void mdm_device_dslam_alcatel_73xx_new(
	mdm_device_t *, mdm_operation_result_t *
);
extern void mdm_device_dslam_alcatel_73xx_free(mdm_device_t *);

extern void mdm_device_dslam_alcatel_73xx_prepare_exec(
	mdm_device_descriptor_t *, mdm_device_cmd_t,
	const char *, mdm_operation_result_t *
);

extern void mdm_device_dslam_alcatel_73xx_post_exec(
	mdm_device_descriptor_t *, 
	mdm_device_cmd_t, mdm_operation_result_t *
);

extern void mdm_device_dslam_alcatel_73xx_check_error(
	mdm_device_descriptor_t *, mdm_operation_result_t *
);

#endif
