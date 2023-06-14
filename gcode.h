#ifndef _GCODE_H_
#define _GCODE_H_

#define TFT28		0
#define TFT24		1
#define ROBIN		2

typedef enum
{
	PRINTER_NOT_CONNECT,
	PRINTER_IDLE,
	PRINTER_PRINTING,
	PRINTER_PAUSE,
} PRINT_STATE;


typedef struct
{
	int print_rate;
	int print_hours;
	int print_mins;
	int print_seconds;
	String file_name;
	int file_size;
} PRINT_FILE_INF;

typedef struct
{
	float curSprayerTemp[2];	// 2����ͷ�¶�
	float curBedTemp;	//�ȴ��¶�
	float desireSprayerTemp[2];// 2����ͷĿ���¶�
	float desireBedTemp;// �ȴ�Ŀ���¶�
	
	String sd_file_list;
	//String sd_file_list_t; //����
	//String udisk_file_list;	
	//String udisk_file_list_t;//����

	PRINT_STATE print_state;	//��ӡ״̬
	PRINT_FILE_INF print_file_inf;

	
} PRINT_INF;

extern char M3_TYPE;
extern boolean GET_VERSION_OK;

extern PRINT_INF gPrinterInf;
extern bool file_list_flag;
extern bool getting_file_flag;

extern File treeFile;

#define TELEGRAM

#ifdef TELEGRAM
extern void initTelegram(String ip);
#endif
extern void setPrintState(PRINT_STATE value);

#ifdef __cplusplus
extern "C" {
#endif

extern void paser_cmd(uint8_t *cmdRxBuf);
extern void net_print(const uint8_t *sbuf, uint32_t len);

#ifdef __cplusplus
}
#endif
#endif
