#ifndef uart_comm_ovidius_h
#define uart_comm_ovidius_h

#include <Arduino.h>          
#include <Stream.h>   
#include <utility/sync_codes.h>
#include <utility/packets.h>

#include <utility/operation.h>
#include <utility/debug.h>
#include <C:\Users\Nikos\Documents\Arduino\libraries\i3dfmu\utility\calibration.h>

#if defined(ARDUINO_AVR_MEGA2560)
    #include <utility/ports_avr.h>
#elif defined(ARDUINO_AVR_UNO)
    #include <utility/ports_avr.h>
#else defined(ARDUINO_SAM_DUE)
    #include <utility/ports.h>
#endif

namespace uart_comm_ns {

    typedef unsigned char debug_error_uart_comm;

    class uart_comm_ovidius
    {
    private:
        float _data_received_f;
        long _data_received_l;
        uint8_t _synced_response;
        unsigned long _Tping;
        unsigned long _ping_unit_start;
        bool _timeout_error;
        uint8_t _Byte4Array[BIT32_ARRAY_SIZE];
        //Stream _port;

    public:
        // Data Buffers for connected units
        float i3dfmu_data_buffer[SENSOR_AXES];
        
        // Timing vars for .ino file
        unsigned long comm_start;
        unsigned long last_get_data_fx_ms;        
        unsigned long last_get_data_fy_ms; 
        unsigned long last_get_data_fz_ms; 

        uart_comm_ovidius();
        ~uart_comm_ovidius();

        template<typename T>
        void split_32bits_to_bytes(T val);

        template<typename R>
        void merge_bytes_to_32bits(R & val);

        template<typename T>
        void sendBack4bytes(T val, Stream& debug_serial, Stream& comm_serial);
    
        template<typename S>
        void sendBack4bytes_num(S val, Stream& comm_serial);

        template<typename T>
        void send4Bytes(T val, Stream& debug_serial, Stream& comm_serial, uint8_t Send4BytesCmd);

        void print4Bytes(Stream& debug_serial, Stream& comm_serial);

        template<typename H>
        void get4Bytes(H & received_val, Stream& debug_serial, Stream& comm_serial, uint8_t Get4BytesCmd);
        template<typename H>
        void get4Bytes_num(H & received_val, Stream& comm_serial, uint8_t Get4BytesCmd);

        template<typename H>
        void getBack4bytes_num(H & received_val, Stream& comm_serial);

        bool ping_unit_timeout( Stream& comm_serial, uint8_t ConnectCmd);

        void serialPrintDataBuffer(float *Buffer, int buffer_size);
    };
}
#endif //uart_comm_ovidius_h


