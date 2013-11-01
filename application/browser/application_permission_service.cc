// Copyright (c) 2013 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <string>

#include "xwalk/application/browser/application_permission_service.h"

using xwalk::RuntimeContext;

namespace xwalk {
namespace application {

ApplicationPermissionService::ApplicationPermissionService(RuntimeContext* runtime_context) 
     : runtime_context_(runtime_context) {
}

ApplicationPermissionService::~ApplicationPermissionService() {
}

}  // namespace application
}  // namespace xwalk
