/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef BASE_NOTIFICATION_ANS_STANDARD_FRAMEWORKS_ANS_CORE_INCLUDE_ANS_SUBSCRIBER_INTERFACE_H
#define BASE_NOTIFICATION_ANS_STANDARD_FRAMEWORKS_ANS_CORE_INCLUDE_ANS_SUBSCRIBER_INTERFACE_H

#include "iremote_broker.h"

#include "notification.h"
#include "notification_constant.h"
#include "notification_do_not_disturb_date.h"
#include "notification_request.h"
#include "notification_sorting.h"
#include "notification_sorting_map.h"

namespace OHOS {
namespace Notification {
class IAnsSubscriber : public IRemoteBroker {
public:
    IAnsSubscriber() = default;
    virtual ~IAnsSubscriber() override = default;
    DISALLOW_COPY_AND_MOVE(IAnsSubscriber);

    DECLARE_INTERFACE_DESCRIPTOR(u"OHOS.Notification.IAnsSubscriber");

    virtual void OnConnected() = 0;
    virtual void OnDisconnected() = 0;
    virtual void OnConsumed(const sptr<Notification> &notification) = 0;
    virtual void OnConsumed(
        const sptr<Notification> &notification, const sptr<NotificationSortingMap> &notificationMap) = 0;
    virtual void OnCanceled(const sptr<Notification> &notification) = 0;
    virtual void OnCanceled(const sptr<Notification> &notification, const sptr<NotificationSortingMap> &notificationMap,
        int deleteReason) = 0;
    virtual void OnUpdated(const sptr<NotificationSortingMap> &notificationMap) = 0;
    virtual void OnDoNotDisturbDateChange(const sptr<NotificationDoNotDisturbDate> &date) = 0;

protected:
    enum TransactId : uint32_t {
        ON_CONNECTED = FIRST_CALL_TRANSACTION,
        ON_DISCONNECTED,
        ON_CONSUMED,
        ON_CONSUMED_MAP,
        ON_CANCELED,
        ON_CANCELED_MAP,
        ON_UPDATED,
        ON_DND_DATE_CHANGED,
    };
};
}  // namespace Notification
}  // namespace OHOS

#endif  // BASE_NOTIFICATION_ANS_STANDARD_FRAMEWORKS_ANS_CORE_INCLUDE_ANS_SUBSCRIBER_INTERFACE_H
