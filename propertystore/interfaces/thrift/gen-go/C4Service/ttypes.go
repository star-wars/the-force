// Autogenerated by Thrift Compiler (0.9.1)
// DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING

package C4Service

import (
	"fmt"
	"git.apache.org/thrift.git/lib/go/thrift"
	"math"
)

// (needed to ensure safety because of naive import list construction.)
var _ = math.MinInt32
var _ = thrift.ZERO
var _ = fmt.Printf

var GoUnusedProtection__ int

type TRowKey int64

type TColumnKey int16

type TTTL int32

type TValue []byte

type NotFoundException struct {
}

func NewNotFoundException() *NotFoundException {
	return &NotFoundException{}
}

func (p *NotFoundException) Read(iprot thrift.TProtocol) error {
	if _, err := iprot.ReadStructBegin(); err != nil {
		return fmt.Errorf("%T read error", p)
	}
	for {
		_, fieldTypeId, fieldId, err := iprot.ReadFieldBegin()
		if err != nil {
			return fmt.Errorf("%T field %d read error: %s", p, fieldId, err)
		}
		if fieldTypeId == thrift.STOP {
			break
		}
		if err := iprot.ReadFieldEnd(); err != nil {
			return err
		}
	}
	if err := iprot.ReadStructEnd(); err != nil {
		return fmt.Errorf("%T read struct end error: %s", p, err)
	}
	return nil
}

func (p *NotFoundException) Write(oprot thrift.TProtocol) error {
	if err := oprot.WriteStructBegin("NotFoundException"); err != nil {
		return fmt.Errorf("%T write struct begin error: %s", p, err)
	}
	if err := oprot.WriteFieldStop(); err != nil {
		return fmt.Errorf("%T write field stop error: %s", err)
	}
	if err := oprot.WriteStructEnd(); err != nil {
		return fmt.Errorf("%T write struct stop error: %s", err)
	}
	return nil
}

func (p *NotFoundException) String() string {
	if p == nil {
		return "<nil>"
	}
	return fmt.Sprintf("NotFoundException(%+v)", *p)
}

type InvalidRequestException struct {
	Why string `thrift:"why,1,required"`
}

func NewInvalidRequestException() *InvalidRequestException {
	return &InvalidRequestException{}
}

func (p *InvalidRequestException) Read(iprot thrift.TProtocol) error {
	if _, err := iprot.ReadStructBegin(); err != nil {
		return fmt.Errorf("%T read error", p)
	}
	for {
		_, fieldTypeId, fieldId, err := iprot.ReadFieldBegin()
		if err != nil {
			return fmt.Errorf("%T field %d read error: %s", p, fieldId, err)
		}
		if fieldTypeId == thrift.STOP {
			break
		}
		switch fieldId {
		case 1:
			if err := p.readField1(iprot); err != nil {
				return err
			}
		default:
			if err := iprot.Skip(fieldTypeId); err != nil {
				return err
			}
		}
		if err := iprot.ReadFieldEnd(); err != nil {
			return err
		}
	}
	if err := iprot.ReadStructEnd(); err != nil {
		return fmt.Errorf("%T read struct end error: %s", p, err)
	}
	return nil
}

func (p *InvalidRequestException) readField1(iprot thrift.TProtocol) error {
	if v, err := iprot.ReadString(); err != nil {
		return fmt.Errorf("error reading field 1: %s")
	} else {
		p.Why = v
	}
	return nil
}

func (p *InvalidRequestException) Write(oprot thrift.TProtocol) error {
	if err := oprot.WriteStructBegin("InvalidRequestException"); err != nil {
		return fmt.Errorf("%T write struct begin error: %s", p, err)
	}
	if err := p.writeField1(oprot); err != nil {
		return err
	}
	if err := oprot.WriteFieldStop(); err != nil {
		return fmt.Errorf("%T write field stop error: %s", err)
	}
	if err := oprot.WriteStructEnd(); err != nil {
		return fmt.Errorf("%T write struct stop error: %s", err)
	}
	return nil
}

func (p *InvalidRequestException) writeField1(oprot thrift.TProtocol) (err error) {
	if err := oprot.WriteFieldBegin("why", thrift.STRING, 1); err != nil {
		return fmt.Errorf("%T write field begin error 1:why: %s", p, err)
	}
	if err := oprot.WriteString(string(p.Why)); err != nil {
		return fmt.Errorf("%T.why (1) field write error: %s", p)
	}
	if err := oprot.WriteFieldEnd(); err != nil {
		return fmt.Errorf("%T write field end error 1:why: %s", p, err)
	}
	return err
}

func (p *InvalidRequestException) String() string {
	if p == nil {
		return "<nil>"
	}
	return fmt.Sprintf("InvalidRequestException(%+v)", *p)
}