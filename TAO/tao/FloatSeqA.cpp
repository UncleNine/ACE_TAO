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

#include "FloatSeqC.h"
#include "tao/TypeCode.h"
#include "tao/Any_Dual_Impl_T.h"

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:290

static const CORBA::Long _oc_CORBA_FloatSeq[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  31,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x6f6d672e),
  ACE_NTOHL (0x6f72672f),
  ACE_NTOHL (0x434f5242),
  ACE_NTOHL (0x412f466c),
  ACE_NTOHL (0x6f617453),
  ACE_NTOHL (0x65713a31),
  ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/CORBA/FloatSeq:1.0
    9,
  ACE_NTOHL (0x466c6f61),
  ACE_NTOHL (0x74536571),
  ACE_NTOHL (0x0),  // name = FloatSeq
    CORBA::tk_sequence, // typecode kind
  12, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_float,

    0U,

};

static CORBA::TypeCode _tc_TAO_tc_CORBA_FloatSeq (
    CORBA::tk_alias,
    sizeof (_oc_CORBA_FloatSeq),
    (char *) &_oc_CORBA_FloatSeq,
    0,
    sizeof (CORBA::FloatSeq)
  );

namespace CORBA
{
  ::CORBA::TypeCode_ptr _tc_FloatSeq =
    &_tc_TAO_tc_CORBA_FloatSeq;
}

// TAO_IDL - Generated from
// be\be_visitor_sequence/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::FloatSeq &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::FloatSeq>::insert_copy (
      _tao_any,
      CORBA::FloatSeq::_tao_any_destructor,
      CORBA::_tc_FloatSeq,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::FloatSeq *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::FloatSeq>::insert (
      _tao_any,
      CORBA::FloatSeq::_tao_any_destructor,
      CORBA::_tc_FloatSeq,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::FloatSeq *&_tao_elem
  )
{
  return _tao_any >>= ACE_const_cast (
      const CORBA::FloatSeq *&,
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const CORBA::FloatSeq *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<CORBA::FloatSeq>::extract (
        _tao_any,
        CORBA::FloatSeq::_tao_any_destructor,
        CORBA::_tc_FloatSeq,
        _tao_elem
      );
}



#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Dual_Impl_T<
        CORBA::FloatSeq
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        CORBA::FloatSeq \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

