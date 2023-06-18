// Master DUE Ports
#define DXL_SERIAL      Serial
#define DEBUG_SERIAL    SerialUSB
#define Serial1         SerialJ1Actuator
#define Serial2         SerialIDDH
//#define Serial3       --unused yet--

// IDDH (Intermediate Due Data Handler) Ports
#define Serial1         Serial2Master
#define Serial2         Serial2I3DFMU
#define Serial3         Serial2I9DIMU

// Sensor's Integrated Units ports (Add for each unit in separate place)
// 1. I3DFMU - Integrated 3D Force Measurement - Arduino Mega
//#define Serial         Serial2PC
// Software Serial Port is used fir establishing connection between I3DFMU and IDDH!
#define I3DFMU_TxPin          2
#define I3DFMU_RxPin          3
              
// 2. I9DIMU - Integrated 9dof IMU sensor (under devel)
