#ifndef uart_comm_ovidius_h
#define uart_comm_ovidius_h

#include <Arduino.h>            

#include <utility/sync_codes.h>
#include <utility/packets.h>
#include <utility/ports.h>

namespace uart_comm_ns {

    class uart_comm_ovidius
    {
    private:
        float _data_received_f;
        long _data_received_l;
         
    public:
        uint8_t bit32_array[BIT32_ARRAY_SIZE];

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

    };
}
#endif //uart_comm_ovidius_h


