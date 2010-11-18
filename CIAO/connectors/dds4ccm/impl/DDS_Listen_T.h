/**
 * @author Marcel Smit <msmit@remedy.nl>
 *
 * $Id$
 *
 * Wrapper facade for NDDS.
 */
#ifndef DDS_LISTEN_T_H_
#define DDS_LISTEN_T_H_

#include "dds4ccm/impl/DDS_Subscriber_Base_T.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL
class ACE_Reactor;
ACE_END_VERSIONED_NAMESPACE_DECL

template <typename CCM_TYPE, typename DDS_TYPE>
class DDS_Listen_T
  : public DDS_Subscriber_Base_T<CCM_TYPE, DDS_TYPE>
{
public:
  DDS_Listen_T (void);
  ~DDS_Listen_T (void);

  /**
   * @name DDS_Listen
   * DDS_Listen operations
   */
  //@{
  ::CCM_DDS::CCM_DataListenerControl_ptr get_data_control (void);
  //@}

  void set_component (::CORBA::Object_ptr component);

  void activate (
    typename CCM_TYPE::data_listener_type::_ptr_type listener,
    ::CCM_DDS::PortStatusListener_ptr status,
    ACE_Reactor* reactor);

  void remove (::DDS::Subscriber_ptr subscriber);

private:
  typedef ::CIAO::DDS4CCM::DataReaderListener_T<CCM_TYPE, DDS_TYPE>
    DataReaderListener_type;
  typedef CCM_DDS_DataListenerControl_T< ::CCM_DDS::CCM_DataListenerControl>
    DataListenerControl_type;
  typedef DDS_Subscriber_Base_T<CCM_TYPE, DDS_TYPE>
    DDSSubscriberBase_type;

  /**
   * DDS_Listen
   */
  //@{
  ::CIAO::DDS4CCM::LocalObject_Auto_Ptr_T<DataListenerControl_type> data_control_;
  //@}
};

#include "dds4ccm/impl/DDS_Listen_T.cpp"

#endif /* DDS_LISTEN_T_H_ */
