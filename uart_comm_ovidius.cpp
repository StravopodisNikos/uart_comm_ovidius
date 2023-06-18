    #include <uart_comm_ovidius.h>

    using namespace uart_comm_ns;

    uart_comm_ovidius::uart_comm_ovidius(/* args */)
    {
    }
    
    uart_comm_ovidius::~uart_comm_ovidius()
    {
    }

    template<typename T>
    void uart_comm_ovidius::split_32bits_to_bytes(T val, uint8_t *byte_array) {
        uint8_t *ptr = reinterpret_cast<uint8_t*>(&val);
        for (int i = 0; i < BIT32_ARRAY_SIZE; i++) {
            byte_array[i] = ptr[i];
        }
    }
    template void uart_comm_ovidius::split_32bits_to_bytes<float>(float val, uint8_t *byte_array);
    template void uart_comm_ovidius::split_32bits_to_bytes<long>(long val, uint8_t *byte_array);

    template<typename R>
    void uart_comm_ovidius::merge_bytes_to_32bits(R & val, uint8_t *byte_array) {
        uint8_t *ptr = reinterpret_cast<uint8_t*>(&val);
        for (int i = 0; i < BIT32_ARRAY_SIZE; i++) {
            ptr[i] = byte_array[i];
        }
        return;
    }
    template void uart_comm_ovidius::merge_bytes_to_32bits<float&>(float&, uint8_t *byte_array);
    template void uart_comm_ovidius::merge_bytes_to_32bits<long&>(long&, uint8_t *byte_array);

    template<typename T>
    void uart_comm_ovidius::sendBack4bytes(T val, Stream& debug_serial, Stream& comm_serial, uint8_t * Byte4Array) {
        debug_serial.println("8");
        // Break val to 4 bytes
        split_32bits_to_bytes(val, Byte4Array);
        // Send the 4 bytes
        for (int i = 0; i < BIT32_ARRAY_SIZE; i++){
            debug_serial.print("Sent Byte["); debug_serial.print(i); debug_serial.print("]:");
            debug_serial.println(Byte4Array[i],BIN);
            comm_serial.write(Byte4Array[i]);
        }
        return;
    }
    template void uart_comm_ovidius::sendBack4bytes<float>(float, Stream&, Stream&, uint8_t *);
    template void uart_comm_ovidius::sendBack4bytes<long>(long, Stream&, Stream&, uint8_t * );

    template<typename S>
    void uart_comm_ovidius::sendBack4bytes_num(S val, Stream& comm_serial, uint8_t * Byte4Array) {
        // Break val to 4 bytes
        split_32bits_to_bytes(val, Byte4Array);
        // Send the 4 bytes
        for (int i = 0; i < BIT32_ARRAY_SIZE; i++){
            comm_serial.write(Byte4Array[i]);
        }
        return;
    }
    template void uart_comm_ovidius::sendBack4bytes_num<float>(float, Stream&, uint8_t *);
    template void uart_comm_ovidius::sendBack4bytes_num<long>(long, Stream&, uint8_t * );

    void uart_comm_ovidius::print4Bytes(Stream& debug_serial, Stream& comm_serial, uint8_t * Byte4Array) {
        debug_serial.println("8");
        for (int i = 0; i < BIT32_ARRAY_SIZE; i++){
            while(!comm_serial.available());
            *(Byte4Array + i) = comm_serial.read();
            debug_serial.print("Received Byte["); debug_serial.print(i); debug_serial.print("]:");
            debug_serial.println(Byte4Array[i],BIN);
        }
    }

