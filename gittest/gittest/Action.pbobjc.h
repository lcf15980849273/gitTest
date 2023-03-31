// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Action.proto

// This CPP symbol can be defined to use imports that match up to the framework
// imports needed when using CocoaPods.
#if !defined(GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS)
 #define GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS 0
#endif

#if GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS
 #import <Protobuf/GPBProtocolBuffers.h>
#else
 #import "GPBProtocolBuffers.h"
#endif

#if GOOGLE_PROTOBUF_OBJC_VERSION < 30004
#error This file was generated by a newer version of protoc which is incompatible with your Protocol Buffer library sources.
#endif
#if 30004 < GOOGLE_PROTOBUF_OBJC_MIN_SUPPORTED_VERSION
#error This file was generated by an older version of protoc which is incompatible with your Protocol Buffer library sources.
#endif

// @@protoc_insertion_point(imports)

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

CF_EXTERN_C_BEGIN

@class ActionReqPraise;
@class ActionReqSwitchRoom;
@class ActionReqTest;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Enum ActionType

/**
 *
 * 用户行为
 * —— 点赞 - 客户端会缓冲一段时间的点赞处理，批量发送给服务器
 * ———— 点赞返回:
 * —————— [成功] 当有客户端发生点赞行为的时候，服务器会以 [通知] 给直播间里的所有人，进行点赞总数的返回
 * —————— [失败] 会有 error，进行提示
 *
 * —— 切换直播间 - 客户端从 哪个 room 到 哪个 room
 * ———— 成功无提示；失败 error 提示
 **/
typedef GPB_ENUM(ActionType) {
  /**
   * Value used if any message's field encounters a value that is not defined
   * by this enum. The message will also have C functions to get/set the rawValue
   * of the field.
   **/
  ActionType_GPBUnrecognizedEnumeratorValue = kGPBUnrecognizedEnumeratorValue,
  ActionType_ActionTypeNone = 0,

  /** 行为 - 点赞 */
  ActionType_ActionTypePraise = 1,

  /** 行为 - 切换直播间 */
  ActionType_ActionTypeSwitchRoom = 2,

  /** 行为 - 测试 */
  ActionType_ActionTypeTest = 3,
};

GPBEnumDescriptor *ActionType_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL ActionType_IsValidValue(int32_t value);

#pragma mark - ActionRoot

/**
 * Exposes the extension registry for this file.
 *
 * The base class provides:
 * @code
 *   + (GPBExtensionRegistry *)extensionRegistry;
 * @endcode
 * which is a @c GPBExtensionRegistry that includes all the extensions defined by
 * this file and all files that it depends on.
 **/
GPB_FINAL @interface ActionRoot : GPBRootObject
@end

#pragma mark - ActionReq

typedef GPB_ENUM(ActionReq_FieldNumber) {
  ActionReq_FieldNumber_Type = 1,
  ActionReq_FieldNumber_ReqId = 2,
  ActionReq_FieldNumber_ChannelId = 3,
  ActionReq_FieldNumber_Praise = 4,
  ActionReq_FieldNumber_Switch_p = 5,
  ActionReq_FieldNumber_Test = 6,
};

typedef GPB_ENUM(ActionReq_ActionBody_OneOfCase) {
  ActionReq_ActionBody_OneOfCase_GPBUnsetOneOfCase = 0,
  ActionReq_ActionBody_OneOfCase_Praise = 4,
  ActionReq_ActionBody_OneOfCase_Switch_p = 5,
  ActionReq_ActionBody_OneOfCase_Test = 6,
};

/**
 * ———————————————————————————————— 请求 ——————————————————————————————————————————————————————
 **/
GPB_FINAL @interface ActionReq : GPBMessage

/** 类型 */
@property(nonatomic, readwrite) ActionType type;

/** 操作id，方便客户端用于区分 */
@property(nonatomic, readwrite) uint32_t reqId;

/** 传递 channel-id(客户端的id) 方便进行操作 */
@property(nonatomic, readwrite, copy, null_resettable) NSString *channelId;

/** 内容 */
@property(nonatomic, readonly) ActionReq_ActionBody_OneOfCase actionBodyOneOfCase;

@property(nonatomic, readwrite, strong, null_resettable) ActionReqPraise *praise;

@property(nonatomic, readwrite, strong, null_resettable) ActionReqSwitchRoom *switch_p;

@property(nonatomic, readwrite, strong, null_resettable) ActionReqTest *test;

@end

/**
 * Fetches the raw value of a @c ActionReq's @c type property, even
 * if the value was not defined by the enum at the time the code was generated.
 **/
int32_t ActionReq_Type_RawValue(ActionReq *message);
/**
 * Sets the raw value of an @c ActionReq's @c type property, allowing
 * it to be set to a value that was not defined by the enum at the time the code
 * was generated.
 **/
void SetActionReq_Type_RawValue(ActionReq *message, int32_t value);

/**
 * Clears whatever value was set for the oneof 'actionBody'.
 **/
void ActionReq_ClearActionBodyOneOfCase(ActionReq *message);

#pragma mark - ActionReqPraise

typedef GPB_ENUM(ActionReqPraise_FieldNumber) {
  ActionReqPraise_FieldNumber_Uuid = 1,
  ActionReqPraise_FieldNumber_RoomId = 2,
  ActionReqPraise_FieldNumber_Times = 3,
  ActionReqPraise_FieldNumber_Anonymous = 4,
  ActionReqPraise_FieldNumber_Nickname = 5,
};

GPB_FINAL @interface ActionReqPraise : GPBMessage

/** 用户id (登录 → uid | 未登录 → 用设备uuid [不能带 : ]) */
@property(nonatomic, readwrite, copy, null_resettable) NSString *uuid;

/** 直播间的id → 商户id:直播间unique:场次id */
@property(nonatomic, readwrite, copy, null_resettable) NSString *roomId;

/** 点赞了几次 */
@property(nonatomic, readwrite) uint32_t times;

/** 是否匿名 → 未登录 true | 登录 false */
@property(nonatomic, readwrite) BOOL anonymous;

/** 昵称 */
@property(nonatomic, readwrite, copy, null_resettable) NSString *nickname;

@end

#pragma mark - ActionReqSwitchRoom

typedef GPB_ENUM(ActionReqSwitchRoom_FieldNumber) {
  ActionReqSwitchRoom_FieldNumber_Uuid = 1,
  ActionReqSwitchRoom_FieldNumber_Nickname = 2,
  ActionReqSwitchRoom_FieldNumber_FromRoomId = 3,
  ActionReqSwitchRoom_FieldNumber_ToRoomId = 4,
  ActionReqSwitchRoom_FieldNumber_Announced = 5,
  ActionReqSwitchRoom_FieldNumber_Anonymous = 6,
};

GPB_FINAL @interface ActionReqSwitchRoom : GPBMessage

/** 用户id (登录 → uid | 未登录 → 用设备uuid [不能带 : ]) */
@property(nonatomic, readwrite, copy, null_resettable) NSString *uuid;

/** 昵称 */
@property(nonatomic, readwrite, copy, null_resettable) NSString *nickname;

/** (旧的)直播间的id → 商户id:直播间unique:场次id */
@property(nonatomic, readwrite, copy, null_resettable) NSString *fromRoomId;

/** (新的)直播间的id → 商户id:直播间unique:场次id */
@property(nonatomic, readwrite, copy, null_resettable) NSString *toRoomId;

/** 是否进行公告 */
@property(nonatomic, readwrite) BOOL announced;

/** 是否匿名 → 未登录 true | 登录 false */
@property(nonatomic, readwrite) BOOL anonymous;

@end

#pragma mark - ActionReqTest

typedef GPB_ENUM(ActionReqTest_FieldNumber) {
  ActionReqTest_FieldNumber_Uuid = 1,
};

GPB_FINAL @interface ActionReqTest : GPBMessage

@property(nonatomic, readwrite, copy, null_resettable) NSString *uuid;

@end

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)