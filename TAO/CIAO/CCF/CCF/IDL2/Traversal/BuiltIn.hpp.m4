divert(-1)

# file      : CCF/IDL2/Traversal/BuiltIn.hpp.m4
# author    : Boris Kolpackov <boris@dre.vanderbilt.edu>
# cvs-id    : $Id$

define(`built_in_type', `

      // $1
      //
      //
      struct $1 : Traverser
      {
        typedef
        SyntaxTree::$1Ptr
        NodePtr;

        $1 ()
        {
          map (typeid (SyntaxTree::$1), this);
        }

        virtual bool
        traverse (SyntaxTree::NodePtr const& n)
        {
          traverse (n->dynamic_type<SyntaxTree::$1> ());
	  return true;
        }

        virtual void
        traverse (NodePtr const& n)
        {
          delegate (n);
        }
      };')
divert(0)dnl
dnl
dnl
dnl
// file      : CCF/IDL2/Traversal/BuiltIn.hpp
// author    : Boris Kolpackov <boris@dre.vanderbilt.edu>
// cvs-id    : $Id$

// Note, that this file is automatically generated!
//

#ifndef CCF_IDL2_TRAVERSAL_BUILT_IN_HPP
#define CCF_IDL2_TRAVERSAL_BUILT_IN_HPP

#include "CCF/IDL2/Traversal/Elements.hpp"
#include "CCF/IDL2/SyntaxTree/BuiltIn.hpp"

namespace CCF
{
  namespace IDL2
  {
    namespace Traversal
    {

      // BuiltInTypeDef
      //
      //
      struct BuiltInTypeDef : Traverser
      {
        typedef
        SyntaxTree::BuiltInTypeDefPtr
        NodePtr;

        BuiltInTypeDef ()
        {
          map (typeid (SyntaxTree::BuiltInTypeDef), this);
        }

        virtual bool
        traverse (SyntaxTree::NodePtr const& n)
        {
          traverse (n->dynamic_type<SyntaxTree::BuiltInTypeDef> ());
	  return true;
        }

        virtual void
        traverse (NodePtr const& n)
        {
          delegate (n);
        }
      };
dnl
built_in_type(`Object')
built_in_type(`ValueBase')
built_in_type(`Any')
built_in_type(`Boolean')
built_in_type(`Char')
built_in_type(`Double')
built_in_type(`Float')
built_in_type(`Long')
built_in_type(`LongDouble')
built_in_type(`LongLong')
built_in_type(`Octet')
built_in_type(`Short')
built_in_type(`String')
built_in_type(`UnsignedLong')
built_in_type(`UnsignedLongLong')
built_in_type(`UnsignedShort')
built_in_type(`Void')
built_in_type(`Wchar')
built_in_type(`Wstring')
dnl
    }
  }
}

#endif  // CCF_IDL2_TRAVERSAL_BUILT_IN_HPP
