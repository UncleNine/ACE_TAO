// -*- C++ -*-

//=============================================================================
/**
 *  @file    TypeCode.h
 *
 *  $Id$
 *
 *  Header file the @c CORBA::TypeCode class.
 *
 *  @author Ossama Othman <ossama@dre.vanderbilt.edu>
 *  @author DOC group at Vanderbilt University, Washington University
 *          and the University of California at Irvine.
 */
//=============================================================================

#ifndef TAO_TYPECODE_H
#define TAO_TYPECODE_H

#include /**/ "ace/pre.h"

#include "tao/TAO_Export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/UserException.h"
#include "tao/Basic_Types.h"
#include "tao/OBV_Constants.h"


namespace CORBA
{

  /**
   * @enum TCKind
   *
   * Kinds of @c TypeCodes in the CORBA namespace, as defined by the
   * OMG.
   */
  enum TCKind
  {
    // = Kinds of typecodes.

    // Do not change these enum values, or duplicate them if you need
    // to add values.  They are used to index tables, and if you
    // change the values you'll need to find and update all of those
    // tables.  The values are also part of the Common Data
    // Representation, and hence are part of IIOP and other ORB
    // protocols.

    tk_null               = 0,
    tk_void               = 1,
    tk_short              = 2,
    tk_long               = 3,
    tk_ushort             = 4,
    tk_ulong              = 5,
    tk_float              = 6,
    tk_double             = 7,
    tk_boolean            = 8,
    tk_char               = 9,
    tk_octet              = 10,
    tk_any                = 11,
    tk_TypeCode           = 12,
    tk_Principal          = 13,
    tk_objref             = 14,
    tk_struct             = 15,
    tk_union              = 16,
    tk_enum               = 17,
    tk_string             = 18,
    tk_sequence           = 19,
    tk_array              = 20,
    tk_alias              = 21,
    tk_except             = 22,

    tk_longlong           = 23,
    tk_ulonglong          = 24,
    tk_longdouble         = 25,
    tk_wchar              = 26,
    tk_wstring            = 27,
    tk_fixed              = 28,
    tk_value              = 29,
    tk_value_box          = 30,
    tk_native             = 31,
    tk_abstract_interface = 32,
    tk_local_interface    = 33,
    tk_component          = 34,
    tk_home               = 35,
    tk_event              = 36,

    // This symbol is not defined by CORBA 3.0.  It's used to speed up
    // dispatch based on TCKind values, and lets many important ones
    // just be table lookups.  It must always be the last enum value!!

    TC_KIND_COUNT
  };

  typedef TCKind & TCKind_out;

  /**
   * @class TypeCode
   *
   * @brief
   *
   *
   */
  class TAO_Export TypeCode
  {
  public:

    /**
     * @class Bounds
     *
     * @brief Out-of-bounds member index exception.
     *
     * Exception thrown when attempting to pass an out-of-bounds index
     * value to a @c TypeCode operation that accepts a member index
     * argument.
     */
    class TAO_Export Bounds : public UserException
    {
    public:

      /// Constructor.
      Bounds (void);

      static Bounds * _downcast (CORBA::Exception * ex);
      static CORBA::Exception * _alloc (void);

      virtual CORBA::Exception * _tao_duplicate (void) const;

      virtual void _raise (void) const;

      virtual void _tao_encode (TAO_OutputCDR & cdr
                                ACE_ENV_ARG_DECL) const;
      virtual void _tao_decode (TAO_InputCDR & cdr
                                ACE_ENV_ARG_DECL);

    };

    /**
     * @class BadKind
     *
     * @brief Invalid @c TypeCode operation exception.
     *
     * Exception thrown when attempting to invoke a @c TypeCode
     * operation that is not valid for the type represented by the
     * @c TypeCode.
     */
    class TAO_Export BadKind : public CORBA::UserException
    {
    public:

      BadKind (void);

      static BadKind * _downcast (CORBA::Exception * ex);
      static CORBA::Exception * _alloc (void);

      virtual CORBA::Exception * _tao_duplicate (void) const;

      virtual void _raise (void) const;

      virtual void _tao_encode (TAO_OutputCDR & cdr
                                ACE_ENV_ARG_DECL) const;
      virtual void _tao_decode (TAO_InputCDR & cdr
                                ACE_ENV_ARG_DECL);

    };

    static CORBA::TypeCode_ptr const _tc_Bounds;
    static CORBA::TypeCode_ptr const _tc_BadKind;

    /// Duplicate this @c TypeCode.
    /**
     * Statically instantiated @c TypeCodes incur no reference count
     * manipulation, i.e. reference counting is a no-op.
     *
     * Dynamically instantiated @c TypeCodes will have their reference
     * count incremented by one each time this function is called.
     */
    static CORBA::TypeCode_ptr _duplicate (CORBA::TypeCode_ptr tc);

    /// Returns a NULL typecode.
    static CORBA::TypeCode_ptr _nil (void);

    /**
     * @name @c CORBA::TypeCode Methods
     *
     * These methods are part of the public interface of @c
     * CORBA::TypeCode class, as defined by the OMG CORBA
     * specification and C++ mapping.
     *
     * The C++ mapping does not declare the methods in the public
     * @c CORBA::TypeCode API as @c virtual, so work around that by
     * making these methods inlined to forward all calls to the
     * corresponding protected template method (i.e. the design
     * pattern, not the C++ feature) listed below in the @c protected
     * block.
     */
    //@{
    /// Equality of two @c TypeCodes.
    /**
     * @return @c true if and only if the set of legal operations is
     *         the same and invoking any operation on the this
     *         @c TypeCode and @a tc returns identical results.
     */
    Boolean equal (TypeCode_ptr tc
                   ACE_ENV_ARG_DECL) const;

    /// Equivalence of two @c TypeCodes.
    /**
     * Equivalence of two @c TypeCodes satisfies a subset of the
     * requirements necessary for equality.
     *
     * @see equal
     */
    Boolean equivalent (TypeCode_ptr tc
                        ACE_ENV_ARG_DECL) const;

    /// The kind of @c TypeCode.
    TCKind kind (ACE_ENV_SINGLE_ARG_DECL) const;

    /// Return @c TypeCode stripped of optional @c name and
    /// @c member_name fields.
    /**
     * @note Calling this method will incur additional run-time memory
     *       consumption since TAO's implementation relies on the
     *       TypeCodeFactory to dynamically create a compact @c
     *       TypeCode; the exception being @c TypeCodes with empty
     *       parameter lists.  Those @c TypeCodes are already compact,
     *       meaning that call this method on such @c TypeCodes incurs
     *       no additional run-time memory requirements.
     *
     *       Unless you need to send compact @c TypeCodes
     *       "over-the-wire" or your @c TypeCode corresponds to a
     *       type with a large number of members, try to stick with
     *       the existing potentially non-compact @c TypeCode.
     *
     * @note Compact @c TypeCodes may also be generated statically by
     *       the TAO_IDL compiler by invoking it with its "-Gt"
     *       (i.e. enable optimized TypeCodes) command line option.
     */
    TypeCode_ptr get_compact_typecode (ACE_ENV_SINGLE_ARG_DECL) const;

    /// The @c RepositoryId globally identifying the type.
    /**
     * This method is valid for the following kinds of @c TypeCodes:
     *
     * @li @c tk_objref
     * @li @c tk_struct
     * @li @c tk_union
     * @li @c tk_enum
     * @li @c tk_alias
     * @li @c tk_value
     * @li @c tk_value_box
     * @li @c tk_native
     * @li @c tk_abstract_interface
     * @li @c tk_local_interface
     * @li @c tk_except
     * @li @c tk_component
     * @li @c tk_home
     * @li @c tk_event
     *
     * @note CORBA::TypeCode::id() does not follow the usual parameter
     *       passing rules defined by the C++ mapping.  This behavior
     *       is required by the C++ mapping.  In particular, ownership
     *       is maintained by the @c TypeCode.
     */
    char const * id (ACE_ENV_SINGLE_ARG_DECL) const;

    /// The simple name identifying the type within its enclosing
    /// scope.
    /**
     * This method is valid for the following kinds of @c TypeCodes:
     *
     * @li @c tk_objref
     * @li @c tk_struct
     * @li @c tk_union
     * @li @c tk_enum
     * @li @c tk_alias
     * @li @c tk_value
     * @li @c tk_value_box
     * @li @c tk_native
     * @li @c tk_abstract_interface
     * @li @c tk_local_interface
     * @li @c tk_except
     * @li @c tk_component
     * @li @c tk_home
     * @li @c tk_event
     *
     * @note CORBA::TypeCode::name() does not follow the usual
     *       parameter passing rules defined by the C++ mapping.  This
     *       behavior is required by the C++ mapping.  In particular,
     *       ownership is maintained by the @c TypeCode.
     */
    char const * name (ACE_ENV_SINGLE_ARG_DECL) const;

    /// The type member count.
    /**
     * This method is valid for the following kinds of @c TypeCodes:
     *
     * @li @c tk_struct
     * @li @c tk_union
     * @li @c tk_enum
     * @li @c tk_value
     * @li @c tk_except
     * @li @c tk_event
     */
    ULong member_count (ACE_ENV_SINGLE_ARG_DECL) const;

    /// The type member name.
    /**
     * This method is valid for the following kinds of @c TypeCodes:
     *
     * @li @c tk_struct
     * @li @c tk_union
     * @li @c tk_enum
     * @li @c tk_value
     * @li @c tk_except
     * @li @c tk_event
     *
     * @note CORBA::TypeCode::member_name() does not follow the usual
     *       parameter passing rules defined by the C++ mapping.  This
     *       behavior is required by the C++ mapping.  In particular,
     *       ownership is maintained by the @c TypeCode.
     */
    char const * member_name (ULong index
                              ACE_ENV_ARG_DECL) const;

    /// The type member @c TypeCode.
    /**
     * This method is valid for the following kinds of @c TypeCodes:
     *
     * @li @c tk_struct
     * @li @c tk_union
     * @li @c tk_value
     * @li @c tk_except
     * @li @c tk_event
     */
    TypeCode_ptr member_type (ULong index
                              ACE_ENV_ARG_DECL) const;

    /// The union member label.
    /**
     * This method is valid for the following kinds of @c TypeCodes:
     *
     * @li @c tk_union
     */
    Any * member_label (ULong index
                        ACE_ENV_ARG_DECL) const;

    /// The type of all non-default union member labels.
    /**
     * This method is valid for the following kinds of @c TypeCodes:
     *
     * @li @c tk_union
     */
    TypeCode_ptr discriminator_type (ACE_ENV_SINGLE_ARG_DECL) const;

    /// The index of the default union member.
    /**
     * This method is valid for the following kinds of @c TypeCodes:
     *
     * @li @c tk_union
     */
    Long default_index (ACE_ENV_SINGLE_ARG_DECL) const;

    /// The length of the type.
    /**
     * This method is valid for the following kinds of @c TypeCodes:
     *
     * @li @c tk_string
     * @li @c tk_wstring
     * @li @c tk_sequence
     * @li @c tk_array
     */
    ULong length (ACE_ENV_SINGLE_ARG_DECL) const;

    /// The underlying content type.
    /**
     * This method is valid for the following kinds of @c TypeCodes:
     *
     * @li @c tk_sequence
     * @li @c tk_array
     * @li @c tk_value_box
     * @li @c tk_alias
     */
    TypeCode_ptr content_type (ACE_ENV_SINGLE_ARG_DECL) const;

    /// The number of significant digits.
    /**
     * This method is valid for the following kinds of @c TypeCodes:
     *
     * @li @c tk_fixed
     */
    UShort fixed_digits (ACE_ENV_SINGLE_ARG_DECL) const;

    /// The scale factor.
    /**
     * This method is valid for the following kinds of @c TypeCodes:
     *
     * @li @c tk_fixed
     */
    UShort fixed_scale (ACE_ENV_SINGLE_ARG_DECL) const;

    /// The @c Visibility of the @c valuetype or @c eventtype member
    /// corresponding to index @a index.
    /**
     * This method is valid for the following kinds of @c TypeCodes:
     *
     * @li @c tk_value
     * @li @c tk_event
     */
    Visibility member_visibility (ULong index
                                  ACE_ENV_ARG_DECL) const;

    /// The @c ValueModifier of the @c valuetype of @c eventtype
    /// represented by this @c TypeCode.
    /**
     * This method is valid for the following kinds of @c TypeCodes:
     *
     * @li @c tk_value
     * @li @c tk_event
     */
    ValueModifier type_modifier (ACE_ENV_SINGLE_ARG_DECL) const;

    /// The @c TypeCode corresponding to the concrete base
    /// @c valuetype or @c eventtype.
    /**
     * This method is valid for the following kinds of @c TypeCodes:
     *
     * @li @c tk_value
     * @li @c tk_event
     *
     * @return @c TypeCode corresponding to the concrete base
     *         @c valuetype or @c eventtype.
     *         @c CORBA::TypeCode::_nil() if no concrete base exists.
     */
    TypeCode_ptr concrete_base_type (ACE_ENV_SINGLE_ARG_DECL) const;
    //@}

    /// Marshal this @c TypeCode into a CDR output stream.
    /**
     * Marshal this @c TypeCode into the @a cdr output CDR stream,
     * excluding the @c TypeCode kind.  Existing @a cdr contents will
     * not be altered.  The marshaled @c TypeCode will be appended to
     * the given @a cdr CDR output stream.
     *
     * @return @c true if marshaling was successful.
     *
     * @note This is a TAO-specific method that is not part of the
     *       standard @c CORBA::TypeCode interface.
     *
     * @note If this method returns @false, the contents of the @a cdr
     *       output CDR stream are undefined.
     */
    virtual bool tao_marshal (TAO_OutputCDR & cdr) const = 0;

    /// Increase the reference count on this @c TypeCode.
    virtual void tao_duplicate (void) = 0;

    /// Decrease the reference count on this object.
    virtual void tao_release (void) = 0;

  protected:

    /// Constructor.
    TypeCode (void);

    /**
     * @name @c TypeCode Template Methods
     *
     * Methods that must be implemented by @c CORBA::TypeCode
     * subclasses if valid for those subclasses.
     *
     * The default implementations of the non-pure virtual methods
     * throw the @c CORBA::TypeCode::BadKind exception since many of
     * these methods are @c TypeCode type-specific.  This reduces code
     * duplication and bloat.
     *
     * The @c TypeCode @c equal(), @c equivalent(), @c kind() and
     * @c get_compact_typecode() methods are valid for all
     * @c TypeCodes which is why their template method "@c _i"
     * counterparts are pure virtual.
     */
    //@{
    virtual Boolean equal_i (TypeCode_ptr tc
                             ACE_ENV_ARG_DECL) const = 0;
    virtual Boolean equivalent_i (TypeCode_ptr tc
                                  ACE_ENV_ARG_DECL) const = 0;
    virtual TCKind kind_i (ACE_ENV_SINGLE_ARG_DECL) const = 0;
    virtual TypeCode_ptr get_compact_typecode_i (
      ACE_ENV_SINGLE_ARG_DECL) const = 0;

    virtual char const * id_i (ACE_ENV_SINGLE_ARG_DECL) const;
    virtual char const * name_i (ACE_ENV_SINGLE_ARG_DECL) const;
    virtual ULong member_count_i (ACE_ENV_SINGLE_ARG_DECL) const;
    virtual char const * member_name_i (ULong index
                                        ACE_ENV_ARG_DECL) const;
    virtual TypeCode_ptr member_type_i (ULong index
                                        ACE_ENV_ARG_DECL) const;
    virtual Any * member_label_i (ULong index
                                  ACE_ENV_ARG_DECL) const;
    virtual TypeCode_ptr discriminator_type_i (
      ACE_ENV_SINGLE_ARG_DECL) const;
    virtual Long default_index_i (ACE_ENV_SINGLE_ARG_DECL) const;
    virtual ULong length_i (ACE_ENV_SINGLE_ARG_DECL) const;
    virtual TypeCode_ptr content_type_i (ACE_ENV_SINGLE_ARG_DECL) const;
    virtual UShort fixed_digits_i (ACE_ENV_SINGLE_ARG_DECL) const;
    virtual UShort fixed_scale_i (ACE_ENV_SINGLE_ARG_DECL) const;
    virtual Visibility member_visibility_i (ULong index
                                            ACE_ENV_ARG_DECL) const;
    virtual ValueModifier type_modifier_i (ACE_ENV_SINGLE_ARG_DECL) const;
    virtual TypeCode_ptr concrete_base_type_i (
      ACE_ENV_SINGLE_ARG_DECL) const;
    //@}

  private:

    // Prevent copying and assignment.
    TypeCode (TypeCode const &);
    void operator= (TypeCode const &);

  };

}  // End namespace CORBA


namespace TAO
{
  extern TAO_Export bool operator<< (TAO_OutputCDR & cdr,
                                     CORBA::TypeCode const * x);

  /// Return the unaliased @c TCKind of the given @c TypeCode.
  CORBA::TCKind unaliased_kind (CORBA::TypeCode_ptr tc
                                ACE_ENV_ARG_DECL);
}


#if defined (__ACE_INLINE__)
# include "tao/TypeCode.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"

#endif /* TAO_TYPECODE_H */
