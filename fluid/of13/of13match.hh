#ifndef OPENFLOW_MATCH_H
#define OPENFLOW_MATCH_H 1

#include <string>
#include <stdint.h>
#include "fluid/util/ethaddr.hh"
#include "fluid/util/ipaddr.hh"
#include "openflow-13.h"
#include <list>
#include <map>
#include <vector>

namespace fluid_msg {

namespace of13 {

class MatchHeader {
protected:
    uint16_t type_;
    uint16_t length_;
public:
    MatchHeader();
    MatchHeader(uint16_t type, uint16_t length);
    virtual ~MatchHeader() {
    }
    bool operator==(const MatchHeader &other) const;
    bool operator!=(const MatchHeader &other) const;
    virtual size_t pack(uint8_t *buffer);
    virtual of_error unpack(uint8_t *buffer);
    uint16_t type() {
        return this->type_;
    }
    uint16_t length() {
        return this->length_;
    }
    void type(uint16_t type) {
        this->type_ = type;
    }
    void length(uint16_t length) {
        this->length_ = length;
    }
};

struct oxm_req {
    uint16_t eth_type_req[2];
    uint8_t ip_proto_req;
    uint8_t icmp_req;
};

class OXMTLV {
protected:
    uint16_t class__;
    uint8_t field_;
    bool has_mask_;
    uint8_t length_;
    struct oxm_req reqs;
    void create_oxm_req(uint16_t eth_type1, uint16_t eth_type2,
        uint8_t ip_proto, uint8_t icmp);
public:
    OXMTLV();
    OXMTLV(uint16_t class_, uint8_t field, bool has_mask, uint8_t length);
    virtual ~OXMTLV() {
    }
    virtual bool equals(const OXMTLV & other);
    virtual bool operator==(const OXMTLV &other) const;
    virtual bool operator!=(const OXMTLV &other) const;
    virtual OXMTLV& operator=(const OXMTLV& field);
    virtual OXMTLV* clone() {
        return new OXMTLV(*this);
    }
    virtual size_t pack(uint8_t *buffer);
    virtual of_error unpack(uint8_t *buffer);
    uint16_t class_() {
        return this->class__;
    }
    uint8_t field() {
        return this->field_;
    }
    bool has_mask() {
        return this->has_mask_;
    }
    uint8_t length() {
        return this->length_;
    }
    struct oxm_req oxm_reqs() {
        return this->reqs;
    }

    void class_(uint16_t class_) {
        this->class__ = class_;
    }
    void field(uint8_t field) {
        this->field_ = field;
    }
    void has_mask(bool has_mask) {
        this->has_mask_ = has_mask;
    }
    void length(uint8_t length) {
        this->length_ = length;
    }
    static uint32_t make_header(uint16_t class_, uint8_t field, bool has_mask,
        uint8_t length);
    static uint16_t oxm_class(uint32_t header);
    static uint8_t oxm_field(uint32_t header);
    static bool oxm_has_mask(uint32_t header);
    static uint8_t oxm_length(uint32_t header);
};

class InPort: public OXMTLV {
private:
    uint32_t value_;
public:
    InPort() {
        create_oxm_req(0, 0, 0, 0);
    }
    InPort(uint32_t value);
    ~InPort() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual InPort* clone() {
        return new InPort(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    uint32_t value() {
        return this->value_;
    }
    void value(uint32_t value) {
        this->value_ = value;
    }
};

class InPhyPort: public OXMTLV {
private:
    uint32_t value_;
public:
    InPhyPort() {
        create_oxm_req(0, 0, 0, 0);
    }
    InPhyPort(uint32_t value);
    ~InPhyPort() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual InPhyPort* clone() {
        return new InPhyPort(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    uint32_t value() {
        return this->value_;
    }
    void value(uint32_t value) {
        this->value_ = value;
    }
};

class Metadata: public OXMTLV {
private:
    uint64_t value_;
    uint64_t mask_;
public:
    Metadata() {
        create_oxm_req(0, 0, 0, 0);
    }
    Metadata(uint64_t value);
    Metadata(uint64_t value, uint64_t mask);
    ~Metadata() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual Metadata* clone() {
        return new Metadata(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    uint64_t value() {
        return this->value_;
    }
    uint64_t mask() {
        return this->mask_;
    }
    void value(uint64_t value) {
        this->value_ = value;
    }
    void mask(uint64_t mask) {
        this->mask_ = mask;
    }
};

class EthDst: public OXMTLV {
private:
    EthAddress value_;
    EthAddress mask_;
public:
    EthDst() {
        create_oxm_req(0, 0, 0, 0);
    }
    EthDst(EthAddress value);
    EthDst(EthAddress value, EthAddress mask);
    ~EthDst() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual EthDst* clone() {
        return new EthDst(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    EthAddress value() {
        return this->value_;
    }
    EthAddress mask() {
        return this->mask_;
    }
    void value(EthAddress value) {
        this->value_ = value;
    }
    void mask(EthAddress mask) {
        this->mask_ = mask;
    }
};

class EthSrc: public OXMTLV {
private:
    EthAddress value_;
    EthAddress mask_;
public:
    EthSrc() {
        create_oxm_req(0, 0, 0, 0);
    }
    EthSrc(EthAddress value);
    EthSrc(EthAddress value, EthAddress mask);
    ~EthSrc() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual EthSrc* clone() {
        return new EthSrc(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    EthAddress value() {
        return this->value_;
    }
    EthAddress mask() {
        return this->mask_;
    }
    void value(EthAddress value) {
        this->value_ = value;
    }
    void mask(EthAddress mask) {
        this->mask_ = mask;
    }
};

class EthType: public OXMTLV {
private:
    uint16_t value_;
public:
    EthType() {
        create_oxm_req(0, 0, 0, 0);
    }
    EthType(uint16_t value);
    ~EthType() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual EthType* clone() {
        return new EthType(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    uint16_t value() {
        return this->value_;
    }
    void value(uint16_t value) {
        this->value_ = value;
    }
};

class VLANVid: public OXMTLV {
private:
    uint16_t value_;
    uint16_t mask_;
public:
    VLANVid() {
        create_oxm_req(0, 0, 0, 0);
    }
    VLANVid(uint16_t value);
    VLANVid(uint16_t value, uint16_t mask);
    ~VLANVid() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual VLANVid* clone() {
        return new VLANVid(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    uint16_t value() {
        return this->value_;
    }
    uint16_t mask() {
        return this->mask_;
    }
    void value(uint16_t value) {
        this->value_ = value;
    }
    void mask(uint16_t mask) {
        this->mask_ = mask;
    }
};

class VLANPcp: public OXMTLV {
private:
    uint8_t value_;
public:
    VLANPcp() {
        create_oxm_req(0, 0, 0, 0);
    }
    VLANPcp(uint8_t value);
    ~VLANPcp() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual VLANPcp* clone() {
        return new VLANPcp(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    uint8_t value() {
        return this->value_;
    }
    void value(uint8_t value) {
        this->value_ = value;
    }
};

class IPDSCP: public OXMTLV {
private:
    uint8_t value_;
public:
    IPDSCP() {
        create_oxm_req(0x0800, 0x86dd, 0, 0);
    }
    IPDSCP(uint8_t value);
    ~IPDSCP() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual IPDSCP* clone() {
        return new IPDSCP(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    uint8_t value() {
        return this->value_;
    }
    void value(uint8_t value) {
        this->value_ = value;
    }
};

class IPECN: public OXMTLV {
private:
    uint8_t value_;
public:
    IPECN() {
        create_oxm_req(0x0800, 0x86dd, 0, 0);
    }
    IPECN(uint8_t value);
    ~IPECN() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual IPECN* clone() {
        return new IPECN(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    uint8_t value() {
        return this->value_;
    }
    void value(uint8_t value) {
        this->value_ = value;
    }
};

class IPProto: public OXMTLV {
private:
    uint8_t value_;
public:
    IPProto() {
        create_oxm_req(0x0800, 0x86dd, 0, 0);
    }
    IPProto(uint8_t value);
    ~IPProto() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual IPProto* clone() {
        return new IPProto(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    uint8_t value() {
        return this->value_;
    }
    void value(uint8_t value) {
        this->value_ = value;
    }
};

class IPv4Src: public OXMTLV {
private:
    IPAddress value_;
    IPAddress mask_;
public:
    IPv4Src()
        : value_((uint32_t) 0),
          mask_((uint32_t) 0) {
        create_oxm_req(0x0800, 0, 0, 0);
    }
    IPv4Src(IPAddress value);
    IPv4Src(IPAddress value, IPAddress mask);
    ~IPv4Src() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual IPv4Src* clone() {
        return new IPv4Src(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    IPAddress value() {
        return this->value_;
    }
    IPAddress mask() {
        return this->mask_;
    }
    void value(uint32_t value) {
        this->value_ = value;
    }
    void mask(uint32_t mask) {
        this->mask_ = mask;
    }
};

class IPv4Dst: public OXMTLV {
private:
    IPAddress value_;
    IPAddress mask_;
public:
    IPv4Dst()
        : value_((uint32_t) 0),
          mask_((uint32_t) 0) {
        create_oxm_req(0x0800, 0, 0, 0);
    }
    IPv4Dst(IPAddress value);
    IPv4Dst(IPAddress value, IPAddress mask);
    ~IPv4Dst() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual IPv4Dst* clone() {
        return new IPv4Dst(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    IPAddress value() {
        return this->value_;
    }
    IPAddress mask() {
        return this->mask_;
    }
    void value(IPAddress value) {
        this->value_ = value;
    }
    void mask(IPAddress mask) {
        this->mask_ = mask;
    }
};

class TCPSrc: public OXMTLV {
private:
    uint16_t value_;
public:
    TCPSrc() {
        create_oxm_req(0x0800, 0x86dd, 6, 0);
    }
    TCPSrc(uint16_t value);
    ~TCPSrc() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual TCPSrc* clone() {
        return new TCPSrc(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    uint16_t value() {
        return this->value_;
    }
    void value(uint16_t value) {
        this->value_ = value;
    }

};

class TCPDst: public OXMTLV {
private:
    uint16_t value_;
public:
    TCPDst() {
        create_oxm_req(0x0800, 0x86dd, 6, 0);
    }
    TCPDst(uint16_t value);
    ~TCPDst() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual TCPDst* clone() {
        return new TCPDst(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    uint16_t value() {
        return this->value_;
    }
    void value(uint16_t value) {
        this->value_ = value;
    }
};

class UDPSrc: public OXMTLV {
private:
    uint16_t value_;
public:
    UDPSrc() {
        create_oxm_req(0x0800, 0x86dd, 17, 0);
    }
    UDPSrc(uint16_t value);
    ~UDPSrc() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual UDPSrc* clone() {
        return new UDPSrc(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    uint16_t value() {
        return this->value_;
    }
    void value(uint16_t value) {
        this->value_ = value;
    }
};

class UDPDst: public OXMTLV {
private:
    uint16_t value_;
public:
    UDPDst() {
        create_oxm_req(0x0800, 0x86dd, 17, 0);
    }
    UDPDst(uint16_t value);
    ~UDPDst() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual UDPDst* clone() {
        return new UDPDst(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    uint16_t value() {
        return this->value_;
    }
    void value(uint16_t value) {
        this->value_ = value;
    }
};

class SCTPSrc: public OXMTLV {
private:
    uint16_t value_;
public:
    SCTPSrc() {
        create_oxm_req(0x0800, 0x86dd, 132, 0);
    }
    SCTPSrc(uint16_t value);
    ~SCTPSrc() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual SCTPSrc* clone() {
        return new SCTPSrc(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    uint16_t value() {
        return this->value_;
    }
    void value(uint16_t value) {
        this->value_ = value;
    }

};

class SCTPDst: public OXMTLV {
private:
    uint16_t value_;
public:
    SCTPDst() {
        create_oxm_req(0x0800, 0x86dd, 132, 0);
    }
    SCTPDst(uint16_t value);
    ~SCTPDst() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual SCTPDst* clone() {
        return new SCTPDst(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    uint16_t value() {
        return this->value_;
    }
    void value(uint16_t value) {
        this->value_ = value;
    }
};

class ICMPv4Code: public OXMTLV {
private:
    uint8_t value_;
public:
    ICMPv4Code() {
        create_oxm_req(0x0800, 0, 1, 0);
    }
    ICMPv4Code(uint8_t value);
    ~ICMPv4Code() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual ICMPv4Code* clone() {
        return new ICMPv4Code(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    uint8_t value() {
        return this->value_;
    }
    void value(uint8_t value) {
        this->value_ = value;
    }
};

class ICMPv4Type: public OXMTLV {
private:
    uint8_t value_;
public:
    ICMPv4Type() {
        create_oxm_req(0x0800, 0, 1, 0);
    }
    ICMPv4Type(uint8_t value);
    ~ICMPv4Type() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual ICMPv4Type* clone() {
        return new ICMPv4Type(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    uint8_t value() {
        return this->value_;
    }
    void value(uint8_t value) {
        this->value_ = value;
    }
};

class ARPOp: public OXMTLV {
private:
    uint16_t value_;
public:
    ARPOp() {
        create_oxm_req(0x0806, 0, 0, 0);
    }
    ARPOp(uint16_t value);
    ~ARPOp() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual ARPOp* clone() {
        return new ARPOp(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    uint16_t value() {
        return this->value_;
    }
    void value(uint16_t value) {
        this->value_ = value;
    }
};

class ARPSPA: public OXMTLV {
private:
    IPAddress value_;
    IPAddress mask_;
public:
    ARPSPA() {
        create_oxm_req(0x0806, 0, 0, 0);
    }
    ARPSPA(IPAddress value);
    ARPSPA(IPAddress value, IPAddress mask);
    ~ARPSPA() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual ARPSPA* clone() {
        return new ARPSPA(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    IPAddress value() {
        return this->value_;
    }
    IPAddress mask() {
        return this->mask_;
    }
    void value(IPAddress value) {
        this->value_ = value;
    }
    void mask(IPAddress mask) {
        this->mask_ = mask;
    }

};

class ARPTPA: public OXMTLV {
private:
    IPAddress value_;
    IPAddress mask_;
public:
    ARPTPA() {
        create_oxm_req(0x0806, 0, 0, 0);
    }
    ARPTPA(IPAddress value);
    ARPTPA(IPAddress value, IPAddress mask);
    ~ARPTPA() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual ARPTPA* clone() {
        return new ARPTPA(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    IPAddress value() {
        return this->value_;
    }
    IPAddress mask() {
        return this->mask_;
    }
    void value(IPAddress value) {
        this->value_ = value;
    }
    void mask(IPAddress mask) {
        this->mask_ = mask;
    }
};

class ARPSHA: public OXMTLV {
private:
    EthAddress value_;
    EthAddress mask_;
public:
    ARPSHA() {
        create_oxm_req(0x0806, 0, 0, 0);
    }
    ARPSHA(EthAddress value);
    ARPSHA(EthAddress value, EthAddress mask);
    ~ARPSHA() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual ARPSHA* clone() {
        return new ARPSHA(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    EthAddress value() {
        return this->value_;
    }
    EthAddress mask() {
        return this->mask_;
    }
    void value(EthAddress value) {
        this->value_ = value;
    }
};

class ARPTHA: public OXMTLV {
private:
    EthAddress value_;
    EthAddress mask_;
public:
    ARPTHA() {
        create_oxm_req(0x0806, 0, 0, 0);
    }
    ARPTHA(EthAddress value);
    ARPTHA(EthAddress value, EthAddress mask);
    ~ARPTHA() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual ARPTHA* clone() {
        return new ARPTHA(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    EthAddress value() {
        return this->value_;
    }
    EthAddress mask() {
        return this->mask_;
    }
    void value(EthAddress value) {
        this->value_ = value;
    }
    //void value(std::string value);
};

class IPv6Src: public OXMTLV {
private:
    IPAddress value_;
    IPAddress mask_;
public:
    IPv6Src() {
        create_oxm_req(0, 0x86dd, 0, 0);
    }
    IPv6Src(IPAddress value);
    IPv6Src(IPAddress value, IPAddress mask);
    ~IPv6Src() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual IPv6Src* clone() {
        return new IPv6Src(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    IPAddress value() {
        return this->value_;
    }
    IPAddress mask() {
        return this->mask_;
    }
    void value(IPAddress value) {
        this->value_ = value;
    }
    void mask(IPAddress mask) {
        this->mask_ = mask;
    }
};

class IPv6Dst: public OXMTLV {
private:
    IPAddress value_;
    IPAddress mask_;
public:
    IPv6Dst() {
        create_oxm_req(0, 0x86dd, 0, 0);
    }
    IPv6Dst(IPAddress value);
    IPv6Dst(IPAddress value, IPAddress mask);
    ~IPv6Dst() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual IPv6Dst* clone() {
        return new IPv6Dst(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    IPAddress value() {
        return this->value_;
    }
    IPAddress mask() {
        return this->mask_;
    }
    void value(IPAddress value) {
        this->value_ = value;
    }
    void mask(IPAddress mask) {
        this->mask_ = mask;
    }
};

class IPV6Flabel: public OXMTLV {
private:
    uint32_t value_;
    uint32_t mask_;
public:
    IPV6Flabel() {
        create_oxm_req(0, 0x86dd, 0, 0);
    }
    IPV6Flabel(uint32_t value);
    IPV6Flabel(uint32_t value, uint32_t mask);
    ~IPV6Flabel() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual IPV6Flabel* clone() {
        return new IPV6Flabel(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    uint32_t value() {
        return this->value_;
    }
    uint32_t mask() {
        return this->mask_;
    }
    void value(uint32_t value) {
        this->value_ = value;
    }
    void mask(uint32_t mask) {
        this->mask_ = mask;
    }
};

class ICMPv6Type: public OXMTLV {
private:
    uint8_t value_;
public:
    ICMPv6Type() {
        create_oxm_req(0, 0x86dd, 58, 0);
    }
    ICMPv6Type(uint8_t value);
    ~ICMPv6Type() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual ICMPv6Type* clone() {
        return new ICMPv6Type(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    uint8_t value() {
        return this->value_;
    }
    void value(uint8_t value) {
        this->value_ = value;
    }
};

class ICMPv6Code: public OXMTLV {
private:
    uint8_t value_;
public:
    ICMPv6Code() {
        create_oxm_req(0, 0x86dd, 58, 0);
    }
    ICMPv6Code(uint8_t value);
    ~ICMPv6Code() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual ICMPv6Code* clone() {
        return new ICMPv6Code(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    uint8_t value() {
        return this->value_;
    }
    void value(uint8_t value) {
        this->value_ = value;
    }
};

class IPv6NDTarget: public OXMTLV {
private:
    IPAddress value_;
public:
    IPv6NDTarget() {
        create_oxm_req(0, 0x86dd, 58, 135);
    }
    IPv6NDTarget(IPAddress value);
    ~IPv6NDTarget() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual IPv6NDTarget* clone() {
        return new IPv6NDTarget(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    IPAddress value() {
        return this->value_;
    }
    void value(IPAddress value) {
        this->value_ = value;
    }
};

class IPv6NDSLL: public OXMTLV {
private:
    EthAddress value_;
public:
    IPv6NDSLL() {
        create_oxm_req(0, 0x86dd, 58, 136);
    }
    IPv6NDSLL(EthAddress value);
    ~IPv6NDSLL() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual IPv6NDSLL* clone() {
        return new IPv6NDSLL(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    EthAddress value() {
        return this->value_;
    }
    void value(EthAddress value) {
        this->value_ = value;
    }
};

class IPv6NDTLL: public OXMTLV {
private:
    EthAddress value_;
public:
    IPv6NDTLL() {
        create_oxm_req(0, 0x86dd, 58, 136);
    }
    IPv6NDTLL(EthAddress value);
    ~IPv6NDTLL() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual IPv6NDTLL* clone() {
        return new IPv6NDTLL(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    EthAddress value() {
        return this->value_;
    }
    void value(EthAddress value) {
        this->value_ = value;
    }
};

class MPLSLabel: public OXMTLV {
private:
    uint32_t value_;
public:
    MPLSLabel() {
        create_oxm_req(0x8847, 0x8848, 0, 0);
    }
    MPLSLabel(uint32_t value);
    ~MPLSLabel() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual MPLSLabel* clone() {
        return new MPLSLabel(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    uint32_t value() {
        return this->value_;
    }
    void value(uint32_t value) {
        this->value_ = value;
    }
};

class MPLSTC: public OXMTLV {
private:
    uint8_t value_;
public:
    MPLSTC() {
        create_oxm_req(0x8847, 0x8848, 0, 0);
    }
    MPLSTC(uint8_t value);
    ~MPLSTC() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual MPLSTC* clone() {
        return new MPLSTC(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    uint8_t value() {
        return this->value_;
    }
    void value(uint8_t value) {
        this->value_ = value;
    }
};

class MPLSBOS: public OXMTLV {
private:
    uint8_t value_;
public:
    MPLSBOS() {
        create_oxm_req(0x8847, 0x8848, 0, 0);
    }
    MPLSBOS(uint8_t value);
    ~MPLSBOS() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual MPLSBOS* clone() {
        return new MPLSBOS(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    uint8_t value() {
        return this->value_;
    }
    void value(uint8_t value) {
        this->value_ = value;
    }
};

class PBBIsid: public OXMTLV {
private:
    uint32_t value_;
    uint32_t mask_;
public:
    PBBIsid() {
        create_oxm_req(0x88E7, 0, 0, 0);
    }
    PBBIsid(uint32_t value);
    PBBIsid(uint32_t value, uint32_t mask);
    ~PBBIsid() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual PBBIsid* clone() {
        return new PBBIsid(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    uint32_t value() {
        return this->value_;
    }
    uint32_t mask() {
        return this->mask_;
    }
    void value(uint32_t value) {
        this->value_ = value;
    }
    void mask(uint32_t mask) {
        this->mask_ = mask;
    }
};

class TUNNELId: public OXMTLV {
private:
    uint64_t value_;
    uint64_t mask_;
public:
    TUNNELId() {
        create_oxm_req(0, 0, 0, 0);
    }
    TUNNELId(uint64_t value);
    TUNNELId(uint64_t value, uint64_t mask);
    ~TUNNELId() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual TUNNELId* clone() {
        return new TUNNELId(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    uint64_t value() {
        return this->value_;
    }
    void value(uint64_t value) {
        this->value_ = value;
    }
};

class IPv6Exthdr: public OXMTLV {
private:
    uint16_t value_;
    uint16_t mask_;
public:
    IPv6Exthdr() {
        create_oxm_req(0, 0x86dd, 0, 0);
    }
    IPv6Exthdr(uint16_t value);
    IPv6Exthdr(uint16_t value, uint16_t mask);
    ~IPv6Exthdr() {
    }
    virtual bool equals(const OXMTLV & other);
    OXMTLV& operator=(const OXMTLV& field);
    virtual IPv6Exthdr* clone() {
        return new IPv6Exthdr(*this);
    }
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    uint16_t value() {
        return this->value_;
    }
    uint16_t mask() {
        return this->mask_;
    }
    void value(uint16_t value) {
        this->value_ = value;
    }
    void mask(uint16_t mask) {
        this->mask_ = mask;
    }
};

class Match: public MatchHeader {
private:
    /*Current tlvs present by field*/
    std::vector<uint8_t> curr_tlvs_;
    /*Vector of OXM TLVs*/
    std::vector<OXMTLV*> oxm_tlvs_;
public:
    Match();
    Match(const Match &match);
    Match& operator=(Match other);
    ~Match();
    bool operator==(const Match &other) const;
    bool operator!=(const Match &other) const;
    void swap(Match& first, Match& second);
    size_t pack(uint8_t *buffer);
    of_error unpack(uint8_t *buffer);
    OXMTLV *oxm_field(uint8_t field);
    bool check_pre_req(OXMTLV *tlv);
    bool check_dup(OXMTLV *tlv);
    void add_oxm_field(OXMTLV &tlv);
    void add_oxm_field(OXMTLV* tlv);
    uint16_t oxm_fields_len();
    static OXMTLV * make_oxm_tlv(uint8_t field);
    InPort* in_port();
    InPhyPort* in_phy_port();
    Metadata* metadata();
    EthSrc* eth_src();
    EthDst* eth_dst();
    EthType* eth_type();
    VLANVid* vlan_vid();
    VLANPcp* vlan_pcp();
    IPDSCP* ip_dscp();
    IPECN* ip_ecn();
    IPProto* ip_proto();
    IPv4Src* ipv4_src();
    IPv4Dst* ipv4_dst();
    TCPSrc* tcp_src();
    TCPDst* tcp_dst();
    UDPSrc* udp_src();
    UDPDst* udp_dst();
    SCTPSrc* sctp_src();
    SCTPDst* sctp_dst();
    ICMPv4Type* icmpv4_type();
    ICMPv4Code* icmpv4_code();
    ARPOp* arp_op();
    ARPSPA* arp_spa();
    ARPTPA* arp_tpa();
    ARPSHA* arp_sha();
    ARPTHA* arp_tha();
    IPv6Src* ipv6_src();
    IPv6Dst* ipv6_dst();
    IPV6Flabel* ipv6_flabel();
    ICMPv6Type* icmpv6_type();
    ICMPv6Code* icmpv6_code();
    IPv6NDTarget* ipv6_nd_target();
    IPv6NDSLL* ipv6_nd_sll();
    IPv6NDTLL* ipv6_nd_tll();
    MPLSLabel* mpls_label();
    MPLSTC* mpls_tc();
    MPLSBOS* mpls_bos();
    PBBIsid* pbb_isid();
    TUNNELId* tunnel_id();
    IPv6Exthdr* ipv6_exthdr();
};

} //End of namespace of13

} //End of namespace fluid_msg
#endif

