#ifndef uart_comm_ovidius_h
#define uart_comm_ovidius_h

#include <Arduino.h>            

#include <utility/sync_codes.h>
#include <utility/packets.h>
#include <utility/ports.h>
#include <utility/operation.h>
#include <utility/debug.h>
#include <C:\Users\Nikos\Documents\Arduino\libraries\i3dfmu\utility\calibration.h>

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

    public:
        unsigned long last_get_data_fx_ms;        
        unsigned long last_get_data_fy_ms; 
        unsigned long last_get_data_fz_ms; 

        uart_comm_ovidius();
        ~uart_comm_ovidius();

        template<typename T>
        void split_32bits_to_bytes(T val, uint8_t *byte_array);

        template<typename R>
        void merge_bytes_to_32bits(R & val, uint8_t *byte_array);

        template<typename T>
        void sendBack4bytes(T val, Stream& debug_serial, Stream& comm_serial, uint8_t * Byte4Array);
    
        template<typename S>
        void sendBack4bytes_num(S val, Stream& comm_serial, uint8_t * Byte4Array);

        void print4Bytes(Stream& debug_serial, Stream& comm_serial, uint8_t * Byte4Array);

        template<typename H>
        void get4Bytes(H & received_val, Stream& debug_serial, Stream& comm_serial, uint8_t * Byte4Array, uint8_t Get4BytesCmd);
        template<typename H>
        void get4Bytes_num(H & received_val, Stream& comm_serial, uint8_t * Byte4Array, uint8_t Get4BytesCmd);

        bool ping_unit_timeout(Stream& debug_serial, Stream& comm_serial, uint8_t ConnectCmd);
    };
}
#endif //uart_comm_ovidius_h


