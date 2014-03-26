// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "xwalk/runtime/browser/renderer_host/pepper/xwalk_browser_pepper_host_factory.h"

#include "build/build_config.h"
/*
#include "chrome/browser/renderer_host/pepper/pepper_broker_message_filter.h"
#include "chrome/browser/renderer_host/pepper/pepper_extensions_common_message_filter.h"
#include "chrome/browser/renderer_host/pepper/pepper_isolated_file_system_message_filter.h"
#include "chrome/browser/renderer_host/pepper/pepper_output_protection_message_filter.h"
#include "chrome/browser/renderer_host/pepper/pepper_platform_verification_message_filter.h"
#include "chrome/browser/renderer_host/pepper/pepper_talk_host.h"
*/
#include "content/public/browser/browser_ppapi_host.h"
#include "ppapi/host/message_filter_host.h"
#include "ppapi/host/ppapi_host.h"
#include "ppapi/host/resource_host.h"
#include "ppapi/proxy/ppapi_messages.h"
#include "ppapi/shared_impl/ppapi_permissions.h"

using ppapi::host::MessageFilterHost;
using ppapi::host::ResourceHost;
using ppapi::host::ResourceMessageFilter;

namespace xwalk {

XWalkBrowserPepperHostFactory::XWalkBrowserPepperHostFactory(
    content::BrowserPpapiHost* host)
    : host_(host) {
}

XWalkBrowserPepperHostFactory::~XWalkBrowserPepperHostFactory() {
}

scoped_ptr<ResourceHost> XWalkBrowserPepperHostFactory::CreateResourceHost(
    ppapi::host::PpapiHost* host,
    const ppapi::proxy::ResourceMessageCallParams& params,
    PP_Instance instance,
    const IPC::Message& message) {
  DCHECK(host == host_->GetPpapiHost());

  // Make sure the plugin is giving us a valid instance for this resource.
  if (!host_->IsValidInstance(instance))
    return scoped_ptr<ResourceHost>();

  /*
  // Dev interfaces.
  if (host_->GetPpapiHost()->permissions().HasPermission(
      ppapi::PERMISSION_DEV)) {
    switch (message.type()) {
      case PpapiHostMsg_ExtensionsCommon_Create::ID: {
        scoped_refptr<ResourceMessageFilter> extensions_common_filter(
            PepperExtensionsCommonMessageFilter::Create(host_, instance));
        if (!extensions_common_filter.get())
          return scoped_ptr<ResourceHost>();
        return scoped_ptr<ResourceHost>(new MessageFilterHost(
            host_->GetPpapiHost(), instance, params.pp_resource(),
            extensions_common_filter));
      }
    }
  }

  // Private interfaces.
  if (host_->GetPpapiHost()->permissions().HasPermission(
          ppapi::PERMISSION_PRIVATE)) {
    switch (message.type()) {
      case PpapiHostMsg_Broker_Create::ID: {
        scoped_refptr<ResourceMessageFilter> broker_filter(
            new PepperBrokerMessageFilter(instance, host_));
        return scoped_ptr<ResourceHost>(new MessageFilterHost(
            host_->GetPpapiHost(), instance, params.pp_resource(),
            broker_filter));
      }
      case PpapiHostMsg_Talk_Create::ID:
        return scoped_ptr<ResourceHost>(new PepperTalkHost(
            host_, instance, params.pp_resource()));
    }
  }

  // Permissions for the following interfaces will be checked at the
  // time of the corresponding instance's methods calls (because
  // permission check can be performed only on the UI
  // thread). Currently these interfaces are available only for
  // whitelisted apps which may not have access to the other private
  // interfaces.
  if (message.type() == PpapiHostMsg_IsolatedFileSystem_Create::ID) {
    PepperIsolatedFileSystemMessageFilter* isolated_fs_filter =
        PepperIsolatedFileSystemMessageFilter::Create(instance, host_);
    if (!isolated_fs_filter)
      return scoped_ptr<ResourceHost>();
    return scoped_ptr<ResourceHost>(new MessageFilterHost(
        host, instance, params.pp_resource(), isolated_fs_filter));
  }
  */

  return scoped_ptr<ResourceHost>();
}

}  // namespace xwalk