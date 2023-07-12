// Master DUE Ports
#define DXL_SERIAL          Serial
#define DEBUG_SERIAL        SerialUSB
#define SerialJ1Actuator    Serial1         
#define SerialIDDH          Serial2         
//#define Serial3           --unused yet--

// IDDH (Intermediate Due Data Handler) Ports
#define Serial2Master       Serial1         
#define Serial2I3DFMU       Serial2         
#define Serial2I9DIMU       Serial3         

#define SerialUSB_BAUD      115200
#define Serial2I3DFMU_BAUD  250000
#define Serial2MASTER_BAUD  250000

// ASA (Active Stepper Actuator) - DUE board 
#define DEBUG_ASA          Serial
#define SERIAL_DATA_ASA    SerialUSB
#define SerialASA2Master   Serial1 
// ASA (Active Stepper Actuator) - MEGA board -> Deprecated as of 11-7-23
#define DEBUG_ASA          Serial
#define ASA2Master_TxPin    2
#define ASA2Master_RxPin   3

// Sensor's Integrated Units ports (Add for each unit in separate place)
// 1. I3DFMU - Integrated 3D Force Measurement - Arduino Mega
//#define Serial         Serial2PC
// Software Serial Port is used fir establishing connection between I3DFMU and IDDH!
//define I3DFMU_TxPin          2
//#define I3DFMU_RxPin          3
#define i3dfmu2iddh_serial   Serial2 
#define T_ping_unit_ms         5000             
// 2. I9DIMU - Integrated 9dof IMU sensor (under devel)