// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

#include "CurrentC.h"
#include "tao/TypeCode.h"
#include "tao/Any_Impl_T.h"

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:290

static const CORBA::Long _oc_CORBA_Current[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  30,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x6f6d672e),
  ACE_NTOHL (0x6f72672f),
  ACE_NTOHL (0x434f5242),
  ACE_NTOHL (0x412f4375),
  ACE_NTOHL (0x7272656e),
  ACE_NTOHL (0x743a312e),
  ACE_NTOHL (0x30000000),  // repository ID = IDL:omg.org/CORBA/Current:1.0
    8,
  ACE_NTOHL (0x43757272),
  ACE_NTOHL (0x656e7400),  // name = Current
  };

static CORBA::TypeCode _tc_TAO_tc_CORBA_Current (
    CORBA::tk_objref,
    sizeof (_oc_CORBA_Current),
    (char *) &_oc_CORBA_Current,
    0,
    sizeof (CORBA::Current)
  );

namespace CORBA
{
  ::CORBA::TypeCode_ptr _tc_Current =
    &_tc_TAO_tc_CORBA_Current;
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<CORBA::Current>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<CORBA::Current>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<CORBA::Current>::demarshal_value (TAO_InputCDR &)
{
  return 0;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::Current_ptr _tao_elem
  )
{
  CORBA::Current_ptr _tao_objptr =
    CORBA::Current::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::Current_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<CORBA::Current>::insert (
      _tao_any,
      CORBA::Current::_tao_any_destructor,
      CORBA::_tc_Current,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::Current_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<CORBA::Current>::extract (
        _tao_any,
        CORBA::Current::_tao_any_destructor,
        CORBA::_tc_Current,
        _tao_elem
      );
}



#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Impl_T<
        CORBA::Current
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Impl_T< \
        CORBA::Current \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

