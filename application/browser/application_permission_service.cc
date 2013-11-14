// Copyright (c) 2013 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <string>

#include "xwalk/application/browser/application_permission_service.h"
#include "ipc/ipc_sync_channel.h"
#include "ipc/ipc_message_macros.h"
#include "content/public/browser/render_process_host.h"

using xwalk::RuntimeContext;

namespace xwalk {
namespace application {

ApplicationPermissionService::ApplicationPermissionService(RuntimeContext* runtime_context) 
     : runtime_context_(runtime_context) {
    LOG(INFO) << "Xu::permission service create";
}

ApplicationPermissionService::~ApplicationPermissionService() {
}

bool ApplicationPermissionService::OnMessageReceived(const IPC::Message& message) {
    bool handled = true;
    LOG(INFO) << "Xu::enter OnMessageReceived()";
    IPC_BEGIN_MESSAGE_MAP(ApplicationPermissionService, message)
    /*
    IPC_MESSAGE_HANDLER(XWalkExtensionProcessMsg_RegisterExtensions,
                OnRegisterExtensions)
    */
    IPC_MESSAGE_UNHANDLED(handled = false)
    IPC_END_MESSAGE_MAP()
    return handled;
}

void ApplicationPermissionService::OnRenderProcessHostCreated(
        content::RenderProcessHost* host) {
    CHECK(host);
    LOG(INFO) << "Xu::enter OnRenderProcessHostCreated()";
    IPC::ChannelProxy* channel = host->GetChannel();
}

void ApplicationPermissionService::CreateExtensionProcessChannel() {
    LOG(INFO) << "Xu::enter CreateExtensionProcessChannel()";
}

}  // namespace application
}  // namespace xwalk
