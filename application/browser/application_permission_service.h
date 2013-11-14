// Copyright (c) 2013 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef XWALK_APPLICATION_BROWSER_APPLICATION_PERMISSION_SERVICE_H_
#define XWALK_APPLICATION_BROWSER_APPLICATION_PERMISSION_SERVICE_H_

#include <string>

#include "base/memory/scoped_ptr.h"
#include "ipc/ipc_listener.h"
#include "ipc/ipc_channel_handle.h"
#include "ipc/ipc_channel_proxy.h"
#include "xwalk/application/common/application.h"
#include "xwalk/runtime/browser/runtime_context.h"

namespace IPC {
class SyncChannel;
}

namespace content {
class RenderProcessHost;
};

namespace xwalk {
class RuntimeContext;
namespace application {
// This will manages application api permission control
class ApplicationPermissionService : public IPC::Listener {
    public:
        explicit ApplicationPermissionService(xwalk::RuntimeContext* runtime_context);
        virtual ~ApplicationPermissionService();
        // To be called when a new RenderProcessHost is created.
        // See XWalkContentBrowserClient::RenderProcessHostCreated().
        void OnRenderProcessHostCreated(content::RenderProcessHost* host);

    private:
        // IPC::Listener implementation.
        virtual bool OnMessageReceived(const IPC::Message& message) OVERRIDE;
        void CreateExtensionProcessChannel();

        xwalk::RuntimeContext* runtime_context_;
        scoped_ptr<IPC::SyncChannel> extension_process_channel_;
        IPC::ChannelProxy::MessageFilter* extension_process_message_filter_;
        IPC::ChannelHandle ep_channel_handle_;

        DISALLOW_COPY_AND_ASSIGN(ApplicationPermissionService);
};
}  // namespace application
}  // namespace xwalk

#endif  // XWALK_APPLICATION_BROWSER_APPLICATION_PERMISSION_SERVICE_H_
