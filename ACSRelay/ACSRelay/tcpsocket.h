#ifndef __TCPSOCKET_H
#define __TCPSOCKET_H

#include "socket.h"

#define TCP_BUFFER_SIZE 1024

/**
 * @brief Subclass of the Socket virtual class.
 *        TCPSocket provides basic functionality for communication
 *        over a TCP socket.
 */
class TCPSocket : public Socket
{
    
public:
    /**
     * @brief The type of TCP socket.
     * @brief FROM_FD This marks a TCPSocket object constructed
     *                from an existing socket file descriptor.
     * @brief SERVER This marks a TCPSocket object constructed
     *               by specifying parameters such as remote host
     *               and remote TCP port.
     */
    enum Type {
        FROM_FD,
        SERVER
    };
    
    // CTOR
    
    /**
     * @brief TCPSocket object constructor
     * @param type TCPSocket::Type describing how this TCPSocket should be constructed.
     * @param param If type is FROM_FD, param is the socket file descriptor.
     *              If type is SERVER, param is the TCP port on which to listen.
     */
    TCPSocket ( Type type, const unsigned int param );
    /**
     * @brief TCPSocket object constructor
     * @param host Hostname of the TCP correspondent.
     * @param remote_port Port on which to send as a long integer.
     */
    TCPSocket ( const std::string host, const unsigned int remote_port );
    virtual ~TCPSocket() {}
    /**
     * @brief Send bytes through the socket.
     * @param msg Array containing bytes.
     * @param len Number of bytes in the array.
     * @return -1 on error, otherwise the number of sent bytes.
     */
    long Send ( const char* msg, const size_t len ) const;
    /**
     * @brief Read bytes from the socket (if any available).
     * @param msg Pointer to a byte array to hold the incoming data.
     * @param len Maximum number of bytes to read.
     * @return -1 on error, otherwise the number of read bytes.
     */
    long Read ( char *msg, const size_t len );
    /**
     * @brief Wrapper around the standard accept() C function.
     * @return Same values as accept()
     */
    int Accept ();
    /**
     * @brief Wrapper around the standard connect() C function.
     * @param timeout Number of seconds after which the connection will timeout.
     * @return Negative value on error, 0 on successful connection.
     */
    int Connect ( unsigned short timeout );
    
private:
    
    // CTOR
    
    /**
     * @brief TCPSocket object constructor.
     */
    TCPSocket () {}
    
    // VARS
    
    /**
     */
    bool mIsConnected;
};

#endif