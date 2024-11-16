#include "wrapper.hpp"

using namespace geode::prelude;
using namespace Serpent;

CREATE_WRAPPER_FOR(instance->mainClass, MenuLayer_init, bool, ARGS(self), MenuLayer* self)
CREATE_WRAPPER_FOR(instance->mainClass, MenuLayer_onMoreGames, void, ARGS(self, p0), MenuLayer* self, cocos2d::CCObject* p0)
CREATE_WRAPPER_FOR(instance->mainClass, MenuLayer_endGame, void, ARGS(self), MenuLayer* self)
CREATE_WRAPPER_FOR(instance->mainClass, MenuLayer_firstNetworkTest, void, ARGS(self), MenuLayer* self)
CREATE_WRAPPER_FOR(instance->mainClass, MenuLayer_onAchievements, void, ARGS(self, sender), MenuLayer* self, cocos2d::CCObject* sender)
CREATE_WRAPPER_FOR(instance->mainClass, MenuLayer_onCreator, void, ARGS(self, sender), MenuLayer* self, cocos2d::CCObject* sender)
CREATE_WRAPPER_FOR(instance->mainClass, MenuLayer_onDaily, void, ARGS(self, sender), MenuLayer* self, cocos2d::CCObject* sender)
CREATE_WRAPPER_FOR(instance->mainClass, MenuLayer_onGarage, void, ARGS(self, sender), MenuLayer* self, cocos2d::CCObject* sender)
CREATE_WRAPPER_FOR(instance->mainClass, MenuLayer_onMyProfile, void, ARGS(self, sender), MenuLayer* self, cocos2d::CCObject* sender)
CREATE_WRAPPER_FOR(instance->mainClass, MenuLayer_onOptions, void, ARGS(self, sender), MenuLayer* self, cocos2d::CCObject* sender)
CREATE_WRAPPER_FOR(instance->mainClass, MenuLayer_onOptionsInstant, void, ARGS(self), MenuLayer* self)
CREATE_WRAPPER_FOR(instance->mainClass, MenuLayer_onPlay, void, ARGS(self, sender), MenuLayer* self, cocos2d::CCObject* sender)
CREATE_WRAPPER_FOR(instance->mainClass, MenuLayer_onQuit, void, ARGS(self, sender), MenuLayer* self, cocos2d::CCObject* sender)
CREATE_WRAPPER_FOR(instance->mainClass, MenuLayer_onRobTop, void, ARGS(self, sender), MenuLayer* self, cocos2d::CCObject* sender)
CREATE_WRAPPER_FOR(instance->mainClass, MenuLayer_onStats, void, ARGS(self, sender), MenuLayer* self, cocos2d::CCObject* sender)
CREATE_WRAPPER_FOR(instance->mainClass, MenuLayer_openOptions, void, ARGS(self, videoOptions), MenuLayer* self, bool videoOptions)
CREATE_WRAPPER_FOR(instance->mainClass, MenuLayer_showTOS, void, ARGS(self), MenuLayer* self)
CREATE_WRAPPER_FOR(instance->mainClass, MenuLayer_updateUserProfileButton, void, ARGS(self), MenuLayer* self)
CREATE_WRAPPER_FOR(instance->mainClass, MenuLayer_willClose, void, ARGS(self), MenuLayer* self)