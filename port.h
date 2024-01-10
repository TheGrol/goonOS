#ifndef __PORT_H
#define __PORT_H

class Port {
    protected:
        unsigned short portnum;
        Port(unsigned short portnum);
        ~Port();
};

class Port8Bit : public Port {
    public:
        Port8Bit(unsigned short portnum);
        ~Port8Bit();
        virtual void Write(unsigned char data);
        virtual unsigned char Read();
};
class Port16Bit : public Port {
    public:
        Port16Bit(unsigned short portnum);
        ~Port16Bit();
        virtual void Write(unsigned short data);
        virtual unsigned short Read();
};
class Port32Bit : public Port {
    public:
        Port32Bit(unsigned short portnum);
        ~Port32Bit();
        virtual void Write(unsigned long data);
        virtual unsigned long Read();
};

#endif