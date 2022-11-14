#pragma once
//========================== DEFINE CHO TOAN BO CODE ========================

#define DEBUG_SERIAL    
#define DEBUG_SERIAL_PORT       0
#define USING_SD_CARD
#define USING_MQTT
#define SERIAL_DEBUG_BAUDRATE   115200

//========================== DEFINE O3 SENSOR ========================

#define O3_SENSOR
#define O3_SENSOR_DF_ROBOT
#define O3_SENSOR_MQ131

#define PIN_MQ131_POWER      2
#define PIN_MQ131_SENSOR     4  

//========================== DEFINE CHO MAN HINH ========================

#define SCREEN_SERIAL_PORT      Serial
#define ERROR_READ_DISPLAY      777777
#define NEXTION_BAUDRATE        9600
#define EEPROM_SIZE             512
#define PIN_TX_TFT              33
#define PIN_RX_TFT              25

//========================== DEFINE CHO SENSOR TF-LP01 ========================

#define PIN_TX_TFLP01   17
#define PIN_RX_TFLP01   16

//========================== DEFINE CHO SD CARD  ========================

#define PIN_NUM_MISO    21
#define PIN_NUM_MOSI    19
#define PIN_NUM_CLK     18
#define PIN_CS_SD_CARD  5

#define ERROR_NONE 0x00
#define ERROR_FILE_NOT_FOUND 1

//========================== DEFINE CHO MAN HINH ========================

#define USING_RTC
#define PIN_SDA_GPIO    26
#define PIN_SCL_GPIO    27
#define I2C_CLOCK_SPEED 100000U
#define RTC_I2C_ADDRESS 0x68

//========================== DEFINE CHO MAN HINH ========================

#define PIN_NEO_PIXEL   23

//========================== DEFINE CHO MAN HINH ========================

#define PIN_BUTTON_1    35
#define PIN_BUTTON_2    34

//========================== DEFINE THIET BI ========================

char nameDevice[12];

// dinh nghia kieru gia tri cho cam bien
#define FIXPOINT_32_16 uint32_t    // kieru du lieu fix point dung cho cam bien

//========================== khai bao cac bien hien thi tren man hinh ========================

char  TFT_string[10];

//========================== cac bien de calib gia tri ========================

struct calibData{
    uint32_t temperature_calibInt_u32;
    uint32_t humidity_calibInt_u32;
    uint32_t pm1_calibInt_u32;
    uint32_t pm10_calibInt_u32;
    uint32_t pm25_calibInt_u32;
    uint32_t temperature_calibFloat_u32;
    uint32_t humidity_calibFloat_u32;
} calibData_st;

//=========================== Define cac chu ki =============================

#define MQTT_SENDDATA_PERIOD	    (uint32_t)10000
#define SD_WRITEDATA_PERIOD		    (uint32_t)10000
#define WIFI_RECONNECT_PERIOD	    (uint32_t)6000
#define BUTTON_PRESSED_DURATION 	(uint32_t)4000
#define WIFI_MAX_CONNECT_TRIAL      (uint8_t)120


#define TASK_DELAY       ((TickType_t) 1000 / portTICK_PERIOD_MS)
#define WIFI_TASK_DELAY  ((TickType_t) WIFI_RECONNECT_PERIOD / portTICK_PERIOD_MS)
#define MQTT_TASK_DELAY  ((TickType_t) MQTT_SENDDATA_PERIOD / portTICK_PERIOD_MS)
#define SD_TASK_DELAY    ((TickType_t) SD_WRITEDATA_PERIOD / portTICK_PERIOD_MS)
#define STACK_SIZE       1024


typedef enum 
{
    DISCONNECTED,
    CONNECTED,
    SCANNING,
    SENDING_DATA
} status_et;

struct connectionStatus
{
    status_et wifiStatus;
    status_et sdCardStatus;
    status_et TFLP01Sensor;
    status_et mqttConnection;
} connectionStatus_st;


struct sensorData {
    float      temperature;
    float      humidity;
    uint32_t   pm1_u32;
    uint32_t   pm25_u32;
    uint32_t   pm10_u32;
    uint32_t   pm25_min_u32;
    uint32_t   pm25_max_u32;
    float      o3_ppb;
    float      o3_ppm;
    float      o3_ug;
    float      o3_ppb_min;
    float      o3_ppm_min;
    float      o3_ug_min;
    float      o3_ppb_max;
    float      o3_ppm_max;
    float      o3_ug_max;

    dataCore() {
        this->temperature	  = 20.5;
        this->humidity		  = 60;
        this->pm1_u32         = 0;
        this->pm25_u32        = 0;
        this->pm10_u32        = 0;
        this->pm25_min_u32    = 0;
        this->pm25_max_u32    = 0;
        this->o3_ppb          = 0;
        this->o3_ppm          = 0;
        this->o3_ug           = 0;
        this->o3_ppb_min      = 100;
        this->o3_ppm_min      = 100;
        this->o3_ug_min       = 100;
        this->o3_ppb_max      = 0;
        this->o3_ppm_max      = 0;
        this->o3_ug_max       = 0;
    };
};

struct sensorData sensorData_st();

